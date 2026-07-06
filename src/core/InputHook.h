#pragma once
#include "../sdk/utils/Vector.h"

namespace InputHook {
    void Setup();
    void Destroy();

    // Legit aim - smooth, visible
    void SetViewAngles(const Vector& angles);
    bool HasViewAngles();
    void ClearViewAngles();

    // Rage silent aim - instant, invisible to you
    void SetRageAngles(const Vector& angles, bool silent);
    bool HasRageAngles();
    Vector GetRageAngles();
    bool IsSilent();

    // Rage lock - instant visible snap, applied inside CreateMove for tick-sync
    // This eliminates the render-thread lag that causes sluggish tracking.
    void SetLockAngles(const Vector& angles);
    bool HasLockAngles();

    // Internal
    inline Vector g_aimAngles      = { 0, 0, 0 };
    inline bool   g_hasAimAngles   = false;

    inline Vector g_rageAngles     = { 0, 0, 0 };
    inline bool   g_hasRageAngles  = false;
    inline bool   g_rageSilent     = false;

    inline Vector g_lockAngles     = { 0, 0, 0 };
    inline bool   g_hasLockAngles  = false;
}