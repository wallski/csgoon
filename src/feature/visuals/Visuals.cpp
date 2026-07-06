#include "Visuals.h"
#include "esp/Esp.h"
#include "enemycounter/EnemyCounter.h"
#include "../../sdk/utils/Globals.h"
#include "../../../ext/imgui/imgui.h"
#include <cmath>

void Visuals::Render()
{
    ESP::Render();
	EnemyCounter::Render();


    if (Globals::misc_fov_circle)
    {
        ImDrawList* dl = ImGui::GetBackgroundDrawList();
        const float sw = ImGui::GetIO().DisplaySize.x;
        const float sh = ImGui::GetIO().DisplaySize.y;
        const float cx = sw * 0.5f;
        const float cy = sh * 0.5f;


        float fov = 0.f;
        if (Globals::legit_enabled)
            fov = Globals::legit_fov;
        else if (Globals::rage_enabled)
            fov = Globals::rage_fov;

        if (fov > 0.f)
        {
            float aspect     = (sh > 0.f) ? (sw / sh) : (16.f / 9.f);
            float base_hfov  = 90.0f;
    
            float vFov_rad   = 2.0f * atanf(tanf(base_hfov * 0.5f * 3.14159265f / 180.0f) * (3.0f / 4.0f));
            float hFov_deg   = 2.0f * atanf(tanf(vFov_rad * 0.5f) * aspect) * 180.0f / 3.14159265f;

  
            float pxPerDeg   = sw / hFov_deg;
            float radius     = pxPerDeg * fov;

            ImU32 col = ImGui::ColorConvertFloat4ToU32(ImVec4(
                Globals::misc_fov_circle_color[0],
                Globals::misc_fov_circle_color[1],
                Globals::misc_fov_circle_color[2],
                Globals::misc_fov_circle_color[3]
            ));
            dl->AddCircle({ cx, cy }, radius, col, 64, 1.0f);
        }
    }
}