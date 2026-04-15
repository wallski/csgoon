#include "Esp.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Utils.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../../ext/imgui/imgui.h"
#include <algorithm>

// Returns a health-based color: green (100hp) -> yellow (50hp) -> red (0hp)
static ImU32 HealthColor(int hp)
{
    float t = std::clamp(hp / 100.f, 0.f, 1.f);
    float r, g;
    if (t >= 0.5f) {
        // 100->50hp : green to yellow
        float f = (t - 0.5f) * 2.f;
        r = 1.f - f;
        g = 1.f;
    } else {
        // 50->0hp : yellow to red
        float f = t * 2.f;
        r = 1.f;
        g = f;
    }
    return IM_COL32(
        static_cast<int>(r * 255),
        static_cast<int>(g * 255),
        0, 255
    );
}

void ESP::Render()
{
    if (!Globals::esp_enabled)
        return;

    ImDrawList* dl = ImGui::GetBackgroundDrawList();
    const float sw = ImGui::GetIO().DisplaySize.x;
    const float sh = ImGui::GetIO().DisplaySize.y;

    const auto& entities  = EntityManager::Get().GetEntities();
    C_CSPlayerPawn* localPawn = EntityManager::Get().GetLocalPawn();
    if (!localPawn)
        return;

    for (const auto& ent : entities)
    {
        C_CSPlayerPawn* pawn = ent.pawn;
        if (!pawn || !pawn->IsAlive())
            continue;

        bool isEnemy = ent.isEnemy;

        if (isEnemy  && !Globals::esp_enemy_enabled) continue;
        if (!isEnemy && !Globals::esp_team_enabled)  continue;

        ImU32 boxCol, skelCol, fillCol;
        bool  renderBox, renderCornerBox, renderFill, renderHealth, renderSkeleton;
        float boxThick;

        if (isEnemy) {
            boxCol  = ImGui::ColorConvertFloat4ToU32(ImVec4(Globals::esp_box_color[0],      Globals::esp_box_color[1],      Globals::esp_box_color[2],      Globals::esp_box_color[3]));
            skelCol = ImGui::ColorConvertFloat4ToU32(ImVec4(Globals::esp_skeleton_color[0], Globals::esp_skeleton_color[1], Globals::esp_skeleton_color[2], Globals::esp_skeleton_color[3]));
            fillCol = ImGui::ColorConvertFloat4ToU32(ImVec4(Globals::esp_box_fill_color[0], Globals::esp_box_fill_color[1], Globals::esp_box_fill_color[2], Globals::esp_box_fill_color[3]));

            renderBox       = Globals::esp_box;
            renderCornerBox = Globals::esp_corner_box;
            renderFill      = Globals::esp_box_fill;
            renderHealth    = Globals::esp_health;
            renderSkeleton  = Globals::esp_skeleton;
            boxThick        = Globals::esp_box_thickness;
        }
        else {
            boxCol  = ImGui::ColorConvertFloat4ToU32(ImVec4(Globals::esp_team_box_color[0],      Globals::esp_team_box_color[1],      Globals::esp_team_box_color[2],      Globals::esp_team_box_color[3]));
            skelCol = ImGui::ColorConvertFloat4ToU32(ImVec4(Globals::esp_team_skeleton_color[0], Globals::esp_team_skeleton_color[1], Globals::esp_team_skeleton_color[2], Globals::esp_team_skeleton_color[3]));
            fillCol = ImGui::ColorConvertFloat4ToU32(ImVec4(Globals::esp_team_box_fill_color[0], Globals::esp_team_box_fill_color[1], Globals::esp_team_box_fill_color[2], Globals::esp_team_box_fill_color[3]));

            renderBox       = Globals::esp_team_box;
            renderCornerBox = Globals::esp_team_corner_box;
            renderFill      = Globals::esp_team_box_fill;
            renderHealth    = Globals::esp_team_health;
            renderSkeleton  = Globals::esp_team_skeleton;
            boxThick        = Globals::esp_box_team_thickness;
        }

        Vector feet = pawn->m_vOldOrigin();
        Vector head = Utils::GetBonePos(pawn, BoneID::Head);
        if (head.IsZero())
            continue;

        head.z += 8.2f;

        Vector sFeet, sHead;
        if (!Utils::WorldToScreen(feet, sFeet, (float*)Globals::ViewMatrix, sw, sh) ||
            !Utils::WorldToScreen(head, sHead, (float*)Globals::ViewMatrix, sw, sh))
            continue;

        float h = sFeet.y - sHead.y;
        if (h < 5.f)
            continue;

        float w = h * 0.5f;
        float x = sHead.x - w * 0.5f;
        float y = sHead.y;

        if (renderFill)
            dl->AddRectFilled({ x, y }, { x + w, y + h }, fillCol);

        if (renderBox)
        {
            dl->AddRect({ x, y }, { x + w, y + h }, boxCol, 0.f, 0, boxThick);
            dl->AddRect({ x - 1, y - 1 }, { x + w + 1, y + h + 1 }, IM_COL32(0, 0, 0, 220));
        }

        if (renderCornerBox)
        {
            float cl = w * 0.25f;
            dl->AddLine({ x,     y     }, { x + cl,     y     }, boxCol, boxThick);
            dl->AddLine({ x,     y     }, { x,          y + cl }, boxCol, boxThick);
            dl->AddLine({ x + w, y     }, { x + w - cl, y     }, boxCol, boxThick);
            dl->AddLine({ x + w, y     }, { x + w,      y + cl }, boxCol, boxThick);
            dl->AddLine({ x,     y + h }, { x + cl,     y + h }, boxCol, boxThick);
            dl->AddLine({ x,     y + h }, { x,          y + h - cl }, boxCol, boxThick);
            dl->AddLine({ x + w, y + h }, { x + w - cl, y + h }, boxCol, boxThick);
            dl->AddLine({ x + w, y + h }, { x + w,      y + h - cl }, boxCol, boxThick);
        }

        if (renderHealth)
        {
            int   hp     = pawn->m_iHealth();
            float hpFrac = std::clamp(hp / 100.f, 0.f, 1.f);
            float hpH    = h * hpFrac;

            // Background bar
            dl->AddRectFilled({ x - 6, y - 1 }, { x - 2, y + h + 1 }, IM_COL32(0, 0, 0, 150));
            // Gradient health fill
            dl->AddRectFilled({ x - 5, y + h - hpH }, { x - 3, y + h }, HealthColor(hp));
        }

        if (renderSkeleton)
        {
            const float thick = Globals::esp_skeleton_thickness;

            for (const auto& conn : Bones::connections)
            {
                Vector b1 = Utils::GetBonePos(pawn, conn.bone1);
                Vector b2 = Utils::GetBonePos(pawn, conn.bone2);
                if (b1.IsZero() || b2.IsZero())
                    continue;

                Vector sb1, sb2;
                if (Utils::WorldToScreen(b1, sb1, (float*)Globals::ViewMatrix, sw, sh) &&
                    Utils::WorldToScreen(b2, sb2, (float*)Globals::ViewMatrix, sw, sh))
                {
                    dl->AddLine({ sb1.x, sb1.y }, { sb2.x, sb2.y }, skelCol, thick);
                }
            }
        }
    }
}
