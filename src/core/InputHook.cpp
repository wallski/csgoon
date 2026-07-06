#include "InputHook.h"
#include "../sdk/memory/PatternScan.h"
#include "../../ext/minhook/MinHook.h"
#include "../sdk/utils/Globals.h"
#include "../sdk/memory/Offsets.h"
#include <Windows.h>

using CreateMove_t = void* (__fastcall*)(void*, int, float, bool);
inline CreateMove_t oCreateMove = nullptr;
static uintptr_t g_CreateMoveAddr = 0;

void* __fastcall hkCreateMove(void* thisPtr, int sequenceNumber,
    float inputSampleTime, bool active)
{
    void* cmd = oCreateMove(thisPtr, sequenceNumber, inputSampleTime, active);
    if (!cmd || !Memory::IsValidPtr(cmd)) return cmd;


    uintptr_t cmdAnglesAddr = reinterpret_cast<uintptr_t>(cmd) + 0x10;


    static float spinYaw = 0.0f;
    bool didAim = false;


    if (InputHook::g_hasRageAngles) {
        Memory::SafeWrite(cmdAnglesAddr, InputHook::g_rageAngles);
        InputHook::g_hasRageAngles = false;
        didAim = true;
    }

    else if (InputHook::g_hasLockAngles) {
        Memory::SafeWrite(cmdAnglesAddr, InputHook::g_lockAngles);
        if (Globals::ClientBase)
            Memory::SafeWrite(Globals::ClientBase + Offsets::client_dll::dwViewAngles, InputHook::g_lockAngles);
        InputHook::g_hasLockAngles = false;
        didAim = true;
    }
    else if (InputHook::g_hasAimAngles) {
        Memory::SafeWrite(cmdAnglesAddr, InputHook::g_aimAngles);
        InputHook::g_hasAimAngles = false;
        didAim = true;
    }

    if (!didAim && Globals::rage_enabled && Globals::rage_silent) {

        Vector aaAngles;
        Memory::SafeRead(cmdAnglesAddr, aaAngles);
        
        aaAngles.x = 89.0f;
        spinYaw += 25.0f;
        if (spinYaw > 180.0f) spinYaw -= 360.0f;
        aaAngles.y = spinYaw;
        
        Memory::SafeWrite(cmdAnglesAddr, aaAngles);
    }

    return cmd;
}

void InputHook::Setup() {
    uintptr_t createMove = Memory::PatternScan("client.dll",
        "40 53 48 83 EC ? 48 8B D9 48 8B 89 ? ? ? ? 48 85 C9 74 ?");

    if (!createMove) {
        createMove = Memory::PatternScan("client.dll",
            "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 01 48 8B F9 FF 50 ?");
    }

    if (!createMove) return;

    g_CreateMoveAddr = createMove;

    if (MH_CreateHook((void*)createMove, &hkCreateMove, (void**)&oCreateMove) != MH_OK)
        return;

    MH_EnableHook((void*)createMove);
}

void InputHook::Destroy() {
    if (!g_CreateMoveAddr) return;
    MH_DisableHook((void*)g_CreateMoveAddr);
    MH_RemoveHook((void*)g_CreateMoveAddr);
    g_CreateMoveAddr = 0;
    oCreateMove = nullptr;
}

void InputHook::SetViewAngles(const Vector& angles) {
    g_aimAngles = angles;
    g_hasAimAngles = true;
}

bool InputHook::HasViewAngles() {
    return g_hasAimAngles;
}

void InputHook::ClearViewAngles() {
    g_hasAimAngles = false;
}

void InputHook::SetRageAngles(const Vector& angles, bool silent) {
    g_rageAngles = angles;
    g_hasRageAngles = true;
    g_rageSilent = silent;
}

bool InputHook::HasRageAngles() {
    return g_hasRageAngles;
}

Vector InputHook::GetRageAngles() {
    return g_rageAngles;
}

bool InputHook::IsSilent() {
    return g_rageSilent;
}

void InputHook::SetLockAngles(const Vector& angles) {
    g_lockAngles    = angles;
    g_hasLockAngles = true;
}

bool InputHook::HasLockAngles() {
    return g_hasLockAngles;
}
