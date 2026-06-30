#include "InputHook.h"
#include "../sdk/input/UserCmd.h"
#include "../sdk/memory/PatternScan.h"
#include "../feature/combat/ragebot/ragebot.h"
#include "../../ext/minhook/MinHook.h"
#include <Windows.h>

using CreateMoveFn = bool(__fastcall*)(void*, int, CUserCmd*);
inline CreateMoveFn oCreateMove = nullptr;

bool __fastcall hkCreateMove(void* pInput, int nSlot, CUserCmd* cmd)
{
    const bool result = oCreateMove(pInput, nSlot, cmd);

    if (!cmd || !Memory::IsValidPtr(reinterpret_cast<uintptr_t>(cmd)))
        return result;

    RageAimbot::OnCreateMove(cmd);

    if (InputHook::g_hasAimAngles) {
        InputHook::ApplySilentViewAngle(cmd, InputHook::g_aimAngles);
        InputHook::g_hasAimAngles = false;
    }

    return result;
}

void InputHook::ApplySilentViewAngle(CUserCmd* cmd, const Vector& angles)
{
    if (!cmd)
        return;

    cmd->SetSilentViewAngle(angles);
}

void InputHook::Setup()
{
    uintptr_t createMove = Memory::PatternScan("client.dll",
        "48 8B C4 4C 89 40 ? 48 89 48 ? 55 53 56 57 48 8D A8");

    if (!createMove) {
        createMove = Memory::PatternScan("client.dll",
            "40 53 48 83 EC ? 48 8B D9 48 8B 89 ? ? ? ? 48 85 C9 74 ?");
    }

    if (!createMove) {
        createMove = Memory::PatternScan("client.dll",
            "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 01 48 8B F9 FF 50 ?");
    }

    if (createMove) {
        MH_CreateHook(reinterpret_cast<void*>(createMove),
            reinterpret_cast<void*>(&hkCreateMove),
            reinterpret_cast<void**>(&oCreateMove));
        MH_EnableHook(reinterpret_cast<void*>(createMove));
    }
}

void InputHook::Destroy()
{
    if (oCreateMove)
        MH_DisableHook(reinterpret_cast<void*>(oCreateMove));
}

void InputHook::SetViewAngles(const Vector& angles)
{
    g_aimAngles = angles;
    g_hasAimAngles = true;
}

bool InputHook::HasViewAngles()
{
    return g_hasAimAngles;
}

void InputHook::ClearViewAngles()
{
    g_hasAimAngles = false;
}
