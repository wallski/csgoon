#include "Aimbot.h"
#include "../Combat.h"
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

void Aimbot::Run() {
    if (!Globals::legit_enabled)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;


    bool keyDown = (GetAsyncKeyState(Globals::legit_key) & 0x8000) != 0;
    

    static Vector oldPunch{};
    if (Globals::legit_rcs && local->m_iShotsFired() > 1) {
        Vector punch = local->m_aimPunchAngle() * 2.0f;
        if (!Globals::legit_lock || !keyDown) {
            Vector currentAngle{};
            uintptr_t localPtr = reinterpret_cast<uintptr_t>(local);
            if (Memory::SafeRead(localPtr + Offsets::QAngle::v_angle, currentAngle)) {
                Vector finalAngle = currentAngle + oldPunch - punch;
                Utils::NormalizeAngles(finalAngle);
                
                Memory::SafeWrite(localPtr + Offsets::QAngle::v_angle, finalAngle);
                if (Globals::ClientBase)
                    Memory::SafeWrite(Globals::ClientBase + Offsets::client_dll::dwViewAngles, finalAngle);
            }
        }
        oldPunch = punch;
    } else {
        oldPunch = {};
    }

    if (!keyDown)
        return;

    Vector eyePos = local->m_vOldOrigin() + local->m_vecViewOffset();
    Vector targetAngle;

    C_CSPlayerPawn* target = Combat::FindTarget(
        local, eyePos, targetAngle,
        Globals::legit_fov,
        Globals::aim_team_check
    );
    if (!target)
        return;

    if (Globals::legit_lock) {
        if (Globals::legit_rcs && local->m_iShotsFired() > 1) {
            targetAngle = targetAngle - (local->m_aimPunchAngle() * 2.0f);
            Utils::NormalizeAngles(targetAngle);
        }


        uintptr_t localPtr = reinterpret_cast<uintptr_t>(local);
        Memory::SafeWrite(localPtr + Offsets::QAngle::v_angle, targetAngle);
        if (Globals::ClientBase)
            Memory::SafeWrite(Globals::ClientBase + Offsets::client_dll::dwViewAngles, targetAngle);
    }
}
