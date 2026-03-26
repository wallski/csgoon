#include "Aimbot.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/utils/Vector.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/memory/PatternScan.h"
#include "../../../sdk/memory/Offsets.h"
#include <Windows.h>
#include <cmath>
#include <algorithm>

template<typename T>
T Clamp(T val, T min, T max) {
    return (val < min) ? min : (val > max ? max : val);
}

static C_CSPlayerPawn* FindTarget(C_CSPlayerPawn* local, const Vector& eyePos, Vector& outTargetAngle)
{
    Vector currentAngle = local->m_angEyeAngles();
    C_CSPlayerPawn* bestTarget = nullptr;
    float bestFov = Globals::legit_fov;

    for (const auto& ent : EntityManager::Get().GetEntities())
    {
        if (Globals::aim_team_check && !ent.isEnemy)
            continue;
        if (!ent.pawn || !ent.pawn->IsAlive())
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
            outTargetAngle = angleToTarget;
        }
    }
    return bestTarget;
}

void Aimbot::Run() {
    if (!Globals::legit_enabled)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;

    if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000))
        return;

    Vector eyePos = local->m_vOldOrigin() + local->m_vecViewOffset();
    Vector targetAngle;

    C_CSPlayerPawn* target = FindTarget(local, eyePos, targetAngle);
    if (!target)
        return;

    if (Globals::legit_rcs && local->m_iShotsFired() > 1) {
        targetAngle = targetAngle - (local->m_aimPunchAngle() * 2.0f);
        Utils::NormalizeAngles(targetAngle);
    }

    if (Globals::legit_lock) {
        Vector currentAngle = *reinterpret_cast<Vector*>(
            reinterpret_cast<uintptr_t>(local) + Offsets::QAngle::v_angle);

        Vector delta = targetAngle - currentAngle;
        Utils::NormalizeAngles(delta);


        const float MAX_DEG = 8.0f;
        delta.x = Clamp(delta.x, -MAX_DEG, MAX_DEG);
        delta.y = Clamp(delta.y, -MAX_DEG, MAX_DEG);

        float smooth = Clamp(Globals::legit_smooth, 1.0f, 20.0f);
        float factor = 1.0f / smooth;

        Vector finalAngle = currentAngle + delta * factor;
        Utils::NormalizeAngles(finalAngle);

        uintptr_t client = Memory::GetModuleBase("client.dll");
        *reinterpret_cast<Vector*>(reinterpret_cast<uintptr_t>(local) + Offsets::QAngle::v_angle) = finalAngle;
        *reinterpret_cast<Vector*>(client + Offsets::v_angle::dwViewAngles) = finalAngle;
    }
}