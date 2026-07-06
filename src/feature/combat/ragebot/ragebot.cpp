#include "ragebot.h"
#include "../Combat.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/utils/Vector.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/memory/PatternScan.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../core/InputHook.h"
#include <Windows.h>
#include <cmath>
#include <chrono>

// Returns true if local player has line-of-sight to target (no wall in the way).
// Uses m_iIDEntIndex: the entity index the server says is under the crosshair.
// If it matches the target's pawn entity list index, the target is visible.
static bool IsVisible(C_CSPlayerPawn* local, C_CSPlayerPawn* target) {
    int localIDX = local->m_iIDEntIndex();
    if (localIDX <= 0)
        return false;

    for (const auto& ent : EntityManager::Get().GetEntities()) {
        if (ent.pawn == target)
            return (ent.pawnEntityIdx == localIDX);
    }
    return false;
}

static bool IsActiveWeaponSniper(C_CSPlayerPawn* local) {
    if (!local) return false;
    uintptr_t weaponServices = 0;
    if (!Memory::SafeRead(reinterpret_cast<uintptr_t>(local) + Offsets::CPlayer_WeaponServices::m_pWeaponServices, weaponServices) || !weaponServices)
        return false;

    uint32_t activeWeaponHandle = 0;
    if (!Memory::SafeRead(weaponServices + 0x60, activeWeaponHandle) || !activeWeaponHandle) // m_hActiveWeapon
        return false;

    C_CSPlayerPawn* weaponEntity = EntityManager::Get().GetPawnFromHandle(activeWeaponHandle);
    if (!weaponEntity)
        return false;

    uint16_t itemDef = 0;
    if (!Memory::SafeRead(reinterpret_cast<uintptr_t>(weaponEntity) + 0x1BA, itemDef)) // m_iItemDefinitionIndex
        return false;

    // 9 = AWP, 11 = G3SG1, 38 = SCAR-20, 40 = SSG 08
    return (itemDef == 9 || itemDef == 11 || itemDef == 38 || itemDef == 40);
}

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

    // RCS — compensate punch before writing the angle
    if (local->m_iShotsFired() > 1) {
        targetAngle = targetAngle - (local->m_aimPunchAngle() * 2.0f);
        Utils::NormalizeAngles(targetAngle);
    }

    // ── Silent aim ─────────────────────────────────────────────────────────────
    if (Globals::rage_silent) {
        InputHook::SetRageAngles(targetAngle, true);
    }
    // ── Rage lock — instant direct snap ────────────────────────────────────────
    // Writes directly to v_angle and dwViewAngles every frame.
    // Direct writes are reliable regardless of CreateMove cmd validity.
    else if (Globals::rage_lock) {
        bool keyOk = (Globals::rage_key == 0) || (GetAsyncKeyState(Globals::rage_key) & 0x8000);
        if (keyOk) {
            uintptr_t localPtr = reinterpret_cast<uintptr_t>(local);
            Memory::SafeWrite(localPtr + Offsets::QAngle::v_angle, targetAngle);
            if (Globals::ClientBase)
                Memory::SafeWrite(Globals::ClientBase + Offsets::client_dll::dwViewAngles, targetAngle);
        }
    }

    // ── Auto shoot (timed, unconditional) ──────────────────────────────────────
    if (Globals::rage_autoshoot) {
        static auto lastShot = std::chrono::steady_clock::now();
        auto now = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShot).count() >= 30) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            lastShot = now;
        }
        return;
    }

    // ── Auto Accurate — counter-strafe auto-shot ───────────────────────────────
    // Does NOT lock — only fires when conditions for a guaranteed hit are met:
    //   1. Crosshair is on an enemy (FindTarget confirmed above)
    //   2. Target is visible — no wall between us and them  ← wall check
    //   3. Horizontal speed ≤ 10 u/s (counter-strafe window: velocity near zero)
    //      During full strafe you are at ~250 u/s, so this only triggers for the
    //      brief moment between A→D or D→A when accuracy is at 100%.
    if (!Globals::rage_auto_accurate)
        return;

    // Wall check — don't fire through walls
    if (!IsVisible(local, target))
        return;

    // Recoil check — for non-snipers (rifles, pistols), only fire if recoil has settled
    if (!IsActiveWeaponSniper(local)) {
        Vector punch = local->m_aimPunchAngle();
        float punchLen = std::sqrt(punch.x * punch.x + punch.y * punch.y);
        if (punchLen > 0.15f)
            return;
    }

    // Speed check — only fire at the counter-strafe accuracy window
    Vector vel{};
    Memory::SafeRead(
        reinterpret_cast<uintptr_t>(local) + Offsets::CNetworkVelocityVector::m_vecVelocity,
        vel
    );
    float speed = std::sqrt(vel.x * vel.x + vel.y * vel.y);
    if (speed > 10.0f)
        return;

    // Fire — short cooldown to prevent double-registering the click
    static auto lastAccShot = std::chrono::steady_clock::now();
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastAccShot).count() >= 50) {
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        lastAccShot = now;
    }
}
