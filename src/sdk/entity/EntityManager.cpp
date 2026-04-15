#include "EntityManager.h"
#include "../memory/PatternScan.h"
#include "../memory/Offsets.h"
#include "../utils/Globals.h"
#include <chrono>
#include <iostream>

EntityManager::EntityManager()
{
    // entityListAddress is resolved from ClientBase once it's cached.
    // If ClientBase isn't set yet (early init), Update() will handle it.
    entityListAddress = 0;
}

EntityManager& EntityManager::Get()
{
    static EntityManager instance;
    return instance;
}


void EntityManager::Update()
{
    // Lazily resolve entity list address from cached base
    if (!entityListAddress && Globals::ClientBase)
        entityListAddress = Globals::ClientBase + Offsets::v_angle::dwEntityList;

    if (!entityListAddress)
        return;

    uintptr_t listPtr = *reinterpret_cast<uintptr_t*>(entityListAddress);
    if (!listPtr)
        return;

    C_CSPlayerPawn* currentLocalPawn = nullptr;

    if (Globals::ClientBase)
    {
        uintptr_t localPawnAddr = *reinterpret_cast<uintptr_t*>(Globals::ClientBase + Offsets::v_angle::dwLocalPlayerPawn);
        currentLocalPawn = reinterpret_cast<C_CSPlayerPawn*>(localPawnAddr);
    }

    std::vector<Entity_t> temp;
    temp.reserve(64);

    for (int i = 1; i < 64; ++i)
    {
        uintptr_t listEntry =
            *reinterpret_cast<uintptr_t*>(listPtr + (8 * ((i & 0x7FFF) >> 9)) + 16);
        if (!listEntry)
            continue;

        uintptr_t controllerPtr =
            *reinterpret_cast<uintptr_t*>(listEntry + 112 * (i & 0x1FF));
        if (!controllerPtr)
            continue;

        auto controller = reinterpret_cast<C_CSPlayerController*>(controllerPtr);
        uint32_t pawnHandle = controller->m_hPlayerPawn();

        if (!pawnHandle || pawnHandle == static_cast<uint32_t>(-1))
            continue;

        uintptr_t pawnListEntry =
            *reinterpret_cast<uintptr_t*>(listPtr + 8 * ((pawnHandle & 0x7FFF) >> 9) + 16);
        if (!pawnListEntry)
            continue;

        uintptr_t pawnPtr =
            *reinterpret_cast<uintptr_t*>(pawnListEntry + 112 * (pawnHandle & 0x1FF));
        if (!pawnPtr)
            continue;

        auto pawn = reinterpret_cast<C_CSPlayerPawn*>(pawnPtr);

        if (!pawn || pawn == currentLocalPawn || !pawn->IsAlive())
            continue;

        Entity_t ent{};
        ent.controller = controller;
        ent.pawn       = pawn;
        ent.index      = i;
        ent.isEnemy    = currentLocalPawn && pawn->m_iTeamNum() != currentLocalPawn->m_iTeamNum();

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

    uintptr_t listPtr = *reinterpret_cast<uintptr_t*>(entityListAddress);
    if (!listPtr)
        return nullptr;

    uintptr_t entry = *reinterpret_cast<uintptr_t*>(
        listPtr + 8 * ((handle & 0x7FFF) >> 9) + 16
        );
    if (!entry)
        return nullptr;

    uintptr_t pawnPtr = *reinterpret_cast<uintptr_t*>(
        entry + 112 * (handle & 0x1FF)
        );
    if (!pawnPtr)
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
