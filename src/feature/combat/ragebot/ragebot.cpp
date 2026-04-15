#include "ragebot.h"
#include "../Combat.h"
#include "../triggerbot/Triggerbot.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/utils/Vector.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../core/InputHook.h"
#include <Windows.h>
#include <cmath>

void RageAimbot::Run() {
    if (!Globals::rage_enabled)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;

    Vector eyePos = local->m_vOldOrigin() + local->m_vecViewOffset();
    Vector targetAngle;

    C_CSPlayerPawn* target = Combat::FindTarget(
        local, eyePos, targetAngle,
        Globals::rage_fov,
        true  // rage always enemy-only
    );
    if (!target)
        return;

    // RCS
    if (local->m_iShotsFired() > 1) {
        targetAngle = targetAngle - (local->m_aimPunchAngle() * 2.0f);
        Utils::NormalizeAngles(targetAngle);
    }

    // Silent aim: hook modifies CUserCmd->viewangles only
    if (Globals::rage_silent) {
        InputHook::SetRageAngles(targetAngle, true);
    }
    // Non-silent: direct angle write (aimlock) only when rage_lock + key held
    else if (Globals::rage_lock && Globals::rage_key != 0 && (GetAsyncKeyState(Globals::rage_key) & 0x8000)) {
        uintptr_t localPtr = reinterpret_cast<uintptr_t>(local);

        *reinterpret_cast<Vector*>(localPtr + Offsets::QAngle::v_angle) = targetAngle;
        *reinterpret_cast<Vector*>(Globals::ClientBase + Offsets::client_dll::dwViewAngles) = targetAngle;
    }
}
