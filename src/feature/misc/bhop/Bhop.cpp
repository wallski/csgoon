#include "Bhop.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"

void BunnyHop::Run() {
    if (!Globals::misc_bhop)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !Memory::IsValidPtr(reinterpret_cast<uintptr_t>(local)))
        return;

    uint32_t flags = 0;
    if (!Memory::SafeRead(
            reinterpret_cast<uintptr_t>(local) + Offsets::uint32::m_fFlags,
            flags))
        return;

    bool onGround = (flags & (1 << 0)) != 0;

    // Read movement services pointer safely
    uintptr_t movServices = 0;
    if (!Memory::SafeRead(
            reinterpret_cast<uintptr_t>(local) + Offsets::CPlayer_MovementServices::m_pMovementServices,
            movServices)
        || !Memory::IsValidPtr(movServices))
        return;

    // Read current button state, set the jump bit when airborne, write back
    uintptr_t buttonsAddr = movServices + Offsets::CInButtonState::m_nButtons;
    uint64_t buttons = 0;
    if (!Memory::SafeRead(buttonsAddr, buttons))
        return;

    if (!onGround)
        buttons |= (1ULL << 1);  // FL_JUMP

    Memory::SafeWrite(buttonsAddr, buttons);
}