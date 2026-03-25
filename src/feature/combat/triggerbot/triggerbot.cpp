#include "Triggerbot.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/utils/Utils.h"
#include <chrono>




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
    if (!local)
        return;

    static auto lastShot = std::chrono::steady_clock::now();
    static bool wasAiming = false;

    int entIndex = local->m_iIDEntIndex();

    if (entIndex <= 0) {
        wasAiming = false;
        return;
    }

    C_CSPlayerPawn* target = EntityManager::Get().GetPawnFromHandle(entIndex);

    if (!target || !target->IsAlive() || target->m_iTeamNum() == local->m_iTeamNum()) {
        wasAiming = false;
        return;
    }

    auto now = std::chrono::steady_clock::now();

    if (!wasAiming) {
        lastShot = now;
        wasAiming = true;
    }

    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShot).count();

    if (elapsed >= Globals::trigger_delay) {
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        lastShot = now;
        wasAiming = false;
    }
}