#include "EntityManager.h"
#include "../memory/PatternScan.h"
#include "../memory/Offsets.h"
#include "../utils/Globals.h"
#include <chrono>

EntityManager::EntityManager()
{
    entityListAddress = 0;
}

EntityManager& EntityManager::Get()
{
    static EntityManager instance;
    return instance;
}


static uintptr_t ReadPtr(uintptr_t addr)
{
    uintptr_t val = 0;
    Memory::SafeRead(addr, val);
    return val;
}


void EntityManager::Update()
{

    if (!entityListAddress && Globals::ClientBase)
        entityListAddress = Globals::ClientBase + Offsets::client_dll::dwEntityList;

    if (!entityListAddress)
        return;


    uintptr_t listPtr = ReadPtr(entityListAddress);
    if (!listPtr)
        return;


    C_CSPlayerPawn* currentLocalPawn = nullptr;
    if (Globals::ClientBase)
    {
        uintptr_t localPawnAddr = ReadPtr(Globals::ClientBase + Offsets::client_dll::dwLocalPlayerPawn);
        if (Memory::IsValidPtr(localPawnAddr))
            currentLocalPawn = reinterpret_cast<C_CSPlayerPawn*>(localPawnAddr);
    }


    std::vector<Entity_t> temp;
    temp.reserve(64);

    for (int i = 1; i < 64; ++i)
    {

        uintptr_t listEntry = ReadPtr(listPtr + 8 * ((i & 0x7FFF) >> 9) + 16);
        if (!listEntry)
            continue;


        uintptr_t controllerPtr = ReadPtr(listEntry + 112 * (i & 0x1FF));
        if (!controllerPtr || !Memory::IsValidPtr(controllerPtr))
            continue;

        auto controller = reinterpret_cast<C_CSPlayerController*>(controllerPtr);


        uint32_t pawnHandle = 0;
        if (!Memory::SafeRead(controllerPtr + Offsets::CHandle::m_hPlayerPawn, pawnHandle))
            continue;

        if (!pawnHandle || pawnHandle == static_cast<uint32_t>(-1))
            continue;


        uintptr_t pawnListEntry = ReadPtr(listPtr + 8 * ((pawnHandle & 0x7FFF) >> 9) + 16);
        if (!pawnListEntry)
            continue;

        uintptr_t pawnPtr = ReadPtr(pawnListEntry + 112 * (pawnHandle & 0x1FF));
        if (!pawnPtr || !Memory::IsValidPtr(pawnPtr))
            continue;

        auto pawn = reinterpret_cast<C_CSPlayerPawn*>(pawnPtr);


        if (pawn == currentLocalPawn)
            continue;

        int health = 0;
        if (!Memory::SafeRead(pawnPtr + Offsets::int32::m_iHealth, health) || health <= 0)
            continue;


        int pawnTeam  = 0;
        int localTeam = 0;
        Memory::SafeRead(pawnPtr + Offsets::uint8::m_iTeamNum, pawnTeam);

        Entity_t ent{};
        ent.controller    = controller;
        ent.pawn          = pawn;
        ent.index         = i;
        ent.pawnEntityIdx = static_cast<int>(pawnHandle & 0x7FFF);

        if (currentLocalPawn)
        {
            Memory::SafeRead(
                reinterpret_cast<uintptr_t>(currentLocalPawn) + Offsets::uint8::m_iTeamNum,
                localTeam
            );
            ent.isEnemy = (pawnTeam != localTeam);
        }
        else
        {
            ent.isEnemy = true;
        }

        temp.push_back(ent);
    }

    {
        std::unique_lock lock(mutex);
        entities.swap(temp);
        localPawn = currentLocalPawn;
    }
}


C_CSPlayerPawn* EntityManager::GetPawnFromHandle(uint32_t handle)
{
    if (!handle || !entityListAddress)
        return nullptr;

    uintptr_t listPtr = ReadPtr(entityListAddress);
    if (!listPtr)
        return nullptr;

    uintptr_t entry = ReadPtr(listPtr + 8 * ((handle & 0x7FFF) >> 9) + 16);
    if (!entry)
        return nullptr;

    uintptr_t pawnPtr = ReadPtr(entry + 112 * (handle & 0x1FF));
    if (!pawnPtr || !Memory::IsValidPtr(pawnPtr))
        return nullptr;

    return reinterpret_cast<C_CSPlayerPawn*>(pawnPtr);
}

C_CSPlayerPawn* EntityManager::GetLocalPawn()
{
    std::shared_lock lock(mutex);
    return localPawn;
}

const std::vector<Entity_t>& EntityManager::GetEntities()
{
    std::shared_lock lock(mutex);
    return entities;
}
