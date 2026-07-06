#pragma once
#include "../sdk/utils/Vector.h"

namespace InputHook {
    void Setup();
    void Destroy();


    void SetViewAngles(const Vector& angles);
    bool HasViewAngles();
    void ClearViewAngles();


    void SetRageAngles(const Vector& angles, bool silent);
    bool HasRageAngles();
    Vector GetRageAngles();
    bool IsSilent();


    void SetLockAngles(const Vector& angles);
    bool HasLockAngles();

    inline Vector g_aimAngles      = { 0, 0, 0 };
    inline bool   g_hasAimAngles   = false;

    inline Vector g_rageAngles     = { 0, 0, 0 };
    inline bool   g_hasRageAngles  = false;
    inline bool   g_rageSilent     = false;

    inline Vector g_lockAngles     = { 0, 0, 0 };
    inline bool   g_hasLockAngles  = false;
}
