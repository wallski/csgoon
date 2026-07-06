#include "Triggerbot.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"
#include "../../../sdk/utils/Utils.h"
#include <chrono>


static bool IsActiveWeaponSniper(C_CSPlayerPawn* local) {
    if (!local) return false;
    uintptr_t weaponServices = 0;
    if (!Memory::SafeRead(reinterpret_cast<uintptr_t>(local) + Offsets::CPlayer_WeaponServices::m_pWeaponServices, weaponServices) || !weaponServices)
        return false;

    uint32_t activeWeaponHandle = 0;
    if (!Memory::SafeRead(weaponServices + 0x60, activeWeaponHandle) || !activeWeaponHandle) // m_hActiveWeapon
        return false;

    C_CSPlayerPawn* weaponEntity = EntityManager::Get().GetPawnFromHandle(activeWeaponHandle);
    if (!weaponEntity)
        return false;

    uint16_t itemDef = 0;
    if (!Memory::SafeRead(reinterpret_cast<uintptr_t>(weaponEntity) + 0x1BA, itemDef)) // m_iItemDefinitionIndex
        return false;

    // 9 = AWP, 11 = G3SG1, 38 = SCAR-20, 40 = SSG 08
    return (itemDef == 9 || itemDef == 11 || itemDef == 38 || itemDef == 40);
}

void Triggerbot::Run() {
    if (!Globals::trigger_enabled)
        return;

    if (Globals::trigger_keybind_enabled) {
        if (Globals::trigger_key == 0)
            return;

        if (Globals::trigger_keybind_toggle) {
            static bool lastKeyState = false;
            bool keyDown = (GetAsyncKeyState(Globals::trigger_key) & 0x8000) != 0;
            if (keyDown && !lastKeyState)
                Globals::trigger_key_active = !Globals::trigger_key_active;
            lastKeyState = keyDown;

            if (!Globals::trigger_key_active)
                return;
        }
        else {
            if (!(GetAsyncKeyState(Globals::trigger_key) & 0x8000))
                return;
        }
    }

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !Memory::IsValidPtr(reinterpret_cast<uintptr_t>(local)))
        return;

    static auto lastShot = std::chrono::steady_clock::now();
    static bool wasAiming = false;

    // Read the entity index the local player is currently looking at
    int entIndex = 0;
    if (!Memory::SafeRead(
            reinterpret_cast<uintptr_t>(local) + Offsets::CEntityIndex::m_iIDEntIndex,
            entIndex)
        || entIndex <= 0)
    {
        wasAiming = false;
        return;
    }

    C_CSPlayerPawn* target = EntityManager::Get().GetPawnFromHandle(entIndex);
    if (!target || !Memory::IsValidPtr(reinterpret_cast<uintptr_t>(target)))
    {
        wasAiming = false;
        return;
    }

    // Safe-read health and team to avoid crashing on freed pawn
    int targetHealth = 0;
    Memory::SafeRead(reinterpret_cast<uintptr_t>(target) + Offsets::int32::m_iHealth, targetHealth);
    if (targetHealth <= 0)
    {
        wasAiming = false;
        return;
    }

    int targetTeam = 0, localTeam = 0;
    Memory::SafeRead(reinterpret_cast<uintptr_t>(target) + Offsets::uint8::m_iTeamNum, targetTeam);
    Memory::SafeRead(reinterpret_cast<uintptr_t>(local)  + Offsets::uint8::m_iTeamNum, localTeam);
    if (Globals::aim_team_check && targetTeam == localTeam)
    {
        wasAiming = false;
        return;
    }

    auto now = std::chrono::steady_clock::now();

    if (!wasAiming) {
        lastShot = now;
        wasAiming = true;
    }
    
    if (Globals::trigger_smoke_check) {
        Vector localOrigin{}, viewOffset{}, targetOrigin{};
        uintptr_t localBase  = reinterpret_cast<uintptr_t>(local);
        uintptr_t targetBase = reinterpret_cast<uintptr_t>(target);
        Memory::SafeRead(localBase  + Offsets::Vector::m_vOldOrigin,                        localOrigin);
        Memory::SafeRead(localBase  + Offsets::CNetworkViewOffsetVector::m_vecViewOffset,   viewOffset);
        Memory::SafeRead(targetBase + Offsets::Vector::m_vOldOrigin,                        targetOrigin);
        Vector eyePos = localOrigin + viewOffset;
        if (Utils::IsInSmoke(eyePos, targetOrigin))
            return;
    }

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShot).count();

    if (elapsed >= Globals::trigger_delay) {
        // Recoil check — for non-snipers (rifles, pistols, SMGs), only fire if recoil has settled
        if (!IsActiveWeaponSniper(local)) {
            Vector punch = local->m_aimPunchAngle();
            float punchLen = std::sqrt(punch.x * punch.x + punch.y * punch.y);
            if (punchLen > 0.2f)
                return;
        }

        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        lastShot = now;
        wasAiming = false;
    }
}