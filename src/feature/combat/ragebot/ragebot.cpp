#include "ragebot.h"
#include "../Combat.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/utils/Vector.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/input/UserCmd.h"
#include "../../../core/InputHook.h"
#include <Windows.h>

static bool GetRageTargetAngle(C_CSPlayerPawn* local, Vector& outAngle)
{
    if (!local || !local->IsAlive())
        return false;

    Vector eyePos = local->m_vOldOrigin() + local->m_vecViewOffset();

    C_CSPlayerPawn* target = Combat::FindTarget(
        local, eyePos, outAngle,
        Globals::rage_fov,
        Globals::aim_team_check
    );
    if (!target)
        return false;

    if (local->m_iShotsFired() > 1) {
        outAngle = outAngle - (local->m_aimPunchAngle() * 2.0f);
        Utils::NormalizeAngles(outAngle);
    }

    return true;
}

void RageAimbot::Run()
{
    if (!Globals::rage_enabled || Globals::rage_silent)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;

    Vector targetAngle{};
    if (!GetRageTargetAngle(local, targetAngle))
        return;

    if (Globals::rage_lock && Globals::rage_key != 0 && (GetAsyncKeyState(Globals::rage_key) & 0x8000)) {
        uintptr_t localPtr = reinterpret_cast<uintptr_t>(local);
        Memory::SafeWrite(localPtr + Offsets::QAngle::v_angle, targetAngle);
        if (Globals::ClientBase)
            Memory::SafeWrite(Globals::ClientBase + Offsets::client_dll::dwViewAngles, targetAngle);
    }
}

void RageAimbot::OnCreateMove(CUserCmd* cmd)
{
    if (!Globals::rage_enabled || !Globals::rage_silent || !cmd)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;

    Vector targetAngle{};
    if (!GetRageTargetAngle(local, targetAngle))
        return;

    InputHook::ApplySilentViewAngle(cmd, targetAngle);
}
