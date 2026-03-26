#include "Bhop.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"

void BunnyHop::Run() {
    if (!Globals::misc_bhop)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local)
        return;

    uint32_t flags = local->m_fFlags();
    bool onGround = flags & (1 << 0);

    uintptr_t movServices = *reinterpret_cast<uintptr_t*>(
        reinterpret_cast<uintptr_t>(local) + Offsets::CPlayer_MovementServices::m_pMovementServices
        );

    if (!movServices)
        return;

    uint64_t* buttons = reinterpret_cast<uint64_t*>(movServices + Offsets::CInButtonState::m_nButtons);

    if (!onGround)
        *buttons |= (1ULL << 1);
}