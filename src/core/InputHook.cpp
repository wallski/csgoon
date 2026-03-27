#include "InputHook.h"
#include "../sdk/memory/PatternScan.h"
#include "../../ext/minhook/MinHook.h"
#include <Windows.h>

using CreateMove_t = void* (__fastcall*)(void*, int, float, bool);
inline CreateMove_t oCreateMove = nullptr;

void* __fastcall hkCreateMove(void* thisPtr, int sequenceNumber,
    float inputSampleTime, bool active)
{
    void* cmd = oCreateMove(thisPtr, sequenceNumber, inputSampleTime, active);
    if (!cmd) return cmd;

    // CUserCmd viewangles at offset 0x10
    Vector* cmdAngles = reinterpret_cast<Vector*>(
        reinterpret_cast<uintptr_t>(cmd) + 0x10
        );

    // Rage silent aim - modifies cmd only, visual angles unchanged
    if (InputHook::g_hasRageAngles) {
        *cmdAngles = InputHook::g_rageAngles;
        InputHook::g_hasRageAngles = false;
    }
    else if (InputHook::g_hasAimAngles) {
        *cmdAngles = InputHook::g_aimAngles;
        InputHook::g_hasAimAngles = false;
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

    if (createMove) {
        MH_CreateHook((void*)createMove, &hkCreateMove, (void**)&oCreateMove);
        MH_EnableHook((void*)createMove);
    }
}

void InputHook::Destroy() {
    if (oCreateMove)
        MH_DisableHook((void*)oCreateMove);
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