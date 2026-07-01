#include "ragebot.h"
#include "../Combat.h"
#include "../triggerbot/Triggerbot.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/utils/Vector.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/memory/PatternScan.h"
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
        Globals::aim_team_check
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
        Memory::SafeWrite(localPtr + Offsets::QAngle::v_angle, targetAngle);
        if (Globals::ClientBase)
            Memory::SafeWrite(Globals::ClientBase + Offsets::client_dll::dwViewAngles, targetAngle);
    }

    if (Globals::rage_autoshoot) {
        static auto lastShot = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShot).count() >= 30) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            lastShot = now;
        }
    }
}
