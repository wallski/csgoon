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

// ── Safe pointer helpers ───────────────────────────────────────────────────────
// Read a pointer-sized value and return 0 on any fault or bad address.
static uintptr_t ReadPtr(uintptr_t addr)
{
    uintptr_t val = 0;
    Memory::SafeRead(addr, val);
    return val;
}

// ── EntityManager::Update ─────────────────────────────────────────────────────
// Called once per Present frame.  ALL memory reads go through SafeRead so a
// stale / freed pointer during a round transition or map load simply skips that
// entity instead of crashing.
void EntityManager::Update()
{
    // Lazily resolve entity list address from cached base
    if (!entityListAddress && Globals::ClientBase)
        entityListAddress = Globals::ClientBase + Offsets::client_dll::dwEntityList;

    if (!entityListAddress)
        return;

    // Level-1 dereference: entityListAddress → actual list object pointer
    uintptr_t listPtr = ReadPtr(entityListAddress);
    if (!listPtr)
        return;

    // ── Local pawn ────────────────────────────────────────────────────────────
    C_CSPlayerPawn* currentLocalPawn = nullptr;
    if (Globals::ClientBase)
    {
        uintptr_t localPawnAddr = ReadPtr(Globals::ClientBase + Offsets::client_dll::dwLocalPlayerPawn);
        if (Memory::IsValidPtr(localPawnAddr))
            currentLocalPawn = reinterpret_cast<C_CSPlayerPawn*>(localPawnAddr);
    }

    // ── Entity walk ───────────────────────────────────────────────────────────
    std::vector<Entity_t> temp;
    temp.reserve(64);

    for (int i = 1; i < 64; ++i)
    {
        // Chunk pointer table: listPtr+16, entries spaced 8 bytes apart
        uintptr_t listEntry = ReadPtr(listPtr + 8 * ((i & 0x7FFF) >> 9) + 16);
        if (!listEntry)
            continue;

        // Controller slot within chunk
        uintptr_t controllerPtr = ReadPtr(listEntry + 112 * (i & 0x1FF));
        if (!controllerPtr || !Memory::IsValidPtr(controllerPtr))
            continue;

        auto controller = reinterpret_cast<C_CSPlayerController*>(controllerPtr);

        // Read pawn handle via SafeRead to avoid faulting on a freed controller
        uint32_t pawnHandle = 0;
        if (!Memory::SafeRead(controllerPtr + Offsets::CHandle::m_hPlayerPawn, pawnHandle))
            continue;

        if (!pawnHandle || pawnHandle == static_cast<uint32_t>(-1))
            continue;

        // Resolve pawn through entity list
        uintptr_t pawnListEntry = ReadPtr(listPtr + 8 * ((pawnHandle & 0x7FFF) >> 9) + 16);
        if (!pawnListEntry)
            continue;

        uintptr_t pawnPtr = ReadPtr(pawnListEntry + 112 * (pawnHandle & 0x1FF));
        if (!pawnPtr || !Memory::IsValidPtr(pawnPtr))
            continue;

        auto pawn = reinterpret_cast<C_CSPlayerPawn*>(pawnPtr);

        // Skip self, dead pawns.  SafeRead the health so a freed pawn doesn't crash.
        if (pawn == currentLocalPawn)
            continue;

        int health = 0;
        if (!Memory::SafeRead(pawnPtr + Offsets::int32::m_iHealth, health) || health <= 0)
            continue;

        // Read team number safely
        int pawnTeam  = 0;
        int localTeam = 0;
        Memory::SafeRead(pawnPtr + Offsets::uint8::m_iTeamNum, pawnTeam);

        Entity_t ent{};
        ent.controller = controller;
        ent.pawn       = pawn;
        ent.index      = i;

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
            ent.isEnemy = true; // assume enemy when we have no local pawn
        }

        temp.push_back(ent);
    }

    {
        std::unique_lock lock(mutex);
        entities.swap(temp);
        localPawn = currentLocalPawn;
    }
}

// ── GetPawnFromHandle ──────────────────────────────────────────────────────────
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
