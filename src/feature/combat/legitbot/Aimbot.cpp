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

    // Respect configured keybind (default LMB)
    bool keyDown = (GetAsyncKeyState(Globals::legit_key) & 0x8000) != 0;
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

        *reinterpret_cast<Vector*>(reinterpret_cast<uintptr_t>(local) + Offsets::QAngle::v_angle) = finalAngle;
        *reinterpret_cast<Vector*>(Globals::ClientBase + Offsets::v_angle::dwViewAngles) = finalAngle;
    }
}
