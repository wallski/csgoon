#include "ragebot.h"
#include "../triggerbot/Triggerbot.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/utils/Vector.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../core/InputHook.h"
#include <Windows.h>
#include <cmath>

// Finds closest enemy to crosshair
C_CSPlayerPawn* FindTarget(C_CSPlayerPawn* local, const Vector& eyePos, Vector& outAngle) {
    Vector currentAngle = local->m_angEyeAngles();
    C_CSPlayerPawn* bestTarget = nullptr;
    float bestFov = Globals::rage_fov;

    for (const auto& ent : EntityManager::Get().GetEntities()) {
        if (!ent.isEnemy || !ent.pawn || !ent.pawn->IsAlive())
            continue;

        Vector headPos = Utils::GetBonePos(ent.pawn, BoneID::Head);
        if (headPos.IsZero())
            continue;

        Vector angleToTarget = Utils::CalcAngle(eyePos, headPos);
        Utils::NormalizeAngles(angleToTarget);

        float fov = Utils::GetFoV(currentAngle, angleToTarget);
        if (fov < bestFov) {
            bestFov = fov;
            bestTarget = ent.pawn;
            outAngle = angleToTarget;
        }
    }
    return bestTarget;
}

void RageAimbot::Run() {
    if (!Globals::rage_enabled)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;

    // Prepare aim angles - hook applies them to CUserCmd
    Vector eyePos = local->m_vOldOrigin() + local->m_vecViewOffset();
    Vector targetAngle;

    C_CSPlayerPawn* target = FindTarget(local, eyePos, targetAngle);
    if (!target)
        return;

    // RCS
    if (local->m_iShotsFired() > 1) {
        targetAngle = targetAngle - (local->m_aimPunchAngle() * 2.0f);
        Utils::NormalizeAngles(targetAngle);
    }

    // Silent aim: hook modifies CUserCmd->viewangles only
    // Your screen stays looking original direction
    if (Globals::rage_silent) {
        InputHook::SetRageAngles(targetAngle, true);
    }
    // Non-silent: direct angle write (aimlock) only when rage_lock is enabled and holding rage key
    else if (Globals::rage_lock && Globals::rage_key != 0 && (GetAsyncKeyState(Globals::rage_key) & 0x8000)) {
        uintptr_t localPtr = reinterpret_cast<uintptr_t>(local);
        uintptr_t client = Memory::GetModuleBase("client.dll");

        *reinterpret_cast<Vector*>(localPtr + Offsets::QAngle::v_angle) = targetAngle;
        *reinterpret_cast<Vector*>(client + Offsets::v_angle::dwViewAngles) = targetAngle;
    }
}