#pragma once

#include "../sdk/utils/Vector.h"

class CUserCmd;

namespace InputHook {
    void Setup();
    void Destroy();

    void ApplySilentViewAngle(CUserCmd* cmd, const Vector& angles);

    // Legacy legit path (unused for now)
    void SetViewAngles(const Vector& angles);
    bool HasViewAngles();
    void ClearViewAngles();

    inline Vector g_aimAngles{};
    inline bool   g_hasAimAngles = false;
}
