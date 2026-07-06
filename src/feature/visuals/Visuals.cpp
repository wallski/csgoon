#include "Visuals.h"
#include "esp/Esp.h"
#include "enemycounter/EnemyCounter.h"
#include "../../sdk/utils/Globals.h"
#include "../../../ext/imgui/imgui.h"

void Visuals::Render()
{
    ESP::Render();
	EnemyCounter::Render();

    // Render FOV Circle if enabled and aimbot is active
    if (Globals::misc_fov_circle)
    {
        ImDrawList* dl = ImGui::GetBackgroundDrawList();
        const float sw = ImGui::GetIO().DisplaySize.x;
        const float sh = ImGui::GetIO().DisplaySize.y;
        const float cx = sw * 0.5f;
        const float cy = sh * 0.5f;

        // Determine the fov limit of the active aimbot
        float fov = 0.f;
        if (Globals::legit_enabled)
            fov = Globals::legit_fov;
        else if (Globals::rage_enabled)
            fov = Globals::rage_fov;

        if (fov > 0.f)
        {
            // Standard Source engine FOV conversion to screen pixels
            // 90 degrees is the default base field of view.
            float radius = (sw / 90.f) * fov;
            dl->AddCircle({ cx, cy }, radius, IM_COL32(255, 255, 255, 120), 64, 1.0f);
        }
    }
}