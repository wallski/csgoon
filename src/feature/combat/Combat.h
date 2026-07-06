#pragma once
#include "../../sdk/entity/Classes.h"
#include "../../sdk/utils/Utils.h"
#include "../../sdk/utils/Globals.h"
#include "../../sdk/entity/EntityManager.h"



namespace Combat
{

    void Run();

    // Shared target-finding logic used by both legitbot and ragebot.
    // Returns the closest enemy to crosshair within fov_limit degrees.
    // outAngle is set to the exact angle toward the chosen bone.
    inline C_CSPlayerPawn* FindTarget(
        C_CSPlayerPawn* local,
        const Vector&   eyePos,
        Vector&         outAngle,
        float           fovLimit,
        bool            teamCheck = true)
    {
        Vector currentAngle = local->m_angEyeAngles();
        C_CSPlayerPawn* bestTarget = nullptr;
        float bestFov = fovLimit;

        for (const auto& ent : EntityManager::Get().GetEntities())
        {
            if (teamCheck && !ent.isEnemy)
                continue;
            if (!ent.pawn || !ent.pawn->IsAlive())
                continue;

            Vector targetPos{};

            // Head target: enemy origin + view offset = their exact eye/head position.
            // Same math as the local player's eye pos. Correct for any pose or crouch.
            if (Globals::aim_head) {
                Vector origin  = ent.pawn->m_vOldOrigin();
                Vector viewOff = ent.pawn->m_vecViewOffset();
                if (!origin.IsZero())
                    targetPos = origin + viewOff;
            }

            // Body fallback: spine bone
            if (targetPos.IsZero() && Globals::aim_body)
                targetPos = Utils::GetBonePos(ent.pawn, BoneID::Spine);

            if (targetPos.IsZero())
                continue;

            Vector angleToTarget = Utils::CalcAngle(eyePos, targetPos);
            Utils::NormalizeAngles(angleToTarget);

            float fov = Utils::GetFoV(currentAngle, angleToTarget);
            if (fov < bestFov) {
                bestFov    = fov;
                bestTarget = ent.pawn;
                outAngle   = angleToTarget;
            }
        }
        return bestTarget;
    }
}
