#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "../../ext/imgui/imgui.h"
#include "../../ext/imgui/imgui_internal.h"
#include "../sdk/utils/Globals.h"
#include "../feature/misc/configs/Configs.h"
#include <Windows.h>
#include <stdio.h>
#include <fstream>

namespace Style {
    // backgrounds
    constexpr ImU32 bg = IM_COL32(8, 7, 14, 255);
    constexpr ImU32 bg_panel = IM_COL32(13, 11, 22, 255);
    constexpr ImU32 bg_card = IM_COL32(18, 15, 32, 255);
    constexpr ImU32 bg_hover = IM_COL32(28, 22, 50, 255);
    constexpr ImU32 bg_active = IM_COL32(38, 28, 68, 255);

    // accent
    constexpr ImU32 accent = IM_COL32(138, 43, 226, 255);
    constexpr ImU32 accent_bright = IM_COL32(180, 90, 255, 255);
    constexpr ImU32 accent_dim = IM_COL32(90, 28, 150, 160);
    constexpr ImU32 accent_line = IM_COL32(138, 43, 226, 60);

    // text
    constexpr ImU32 text = IM_COL32(235, 228, 255, 255);
    constexpr ImU32 text_muted = IM_COL32(110, 95, 155, 255);
    constexpr ImU32 text_dim = IM_COL32(60, 50, 90, 255);

    // borders
    constexpr ImU32 border = IM_COL32(45, 35, 75, 255);
    constexpr ImU32 border_bright = IM_COL32(90, 60, 150, 255);
}

static int g_tab = 0;
static const char* tabs[] = { "ragebot", "legitbot", "visuals", "misc", "configs" };



static void toggle(const char* label, bool* v) {
    ImGuiWindow* w = ImGui::GetCurrentWindow();
    if (w->SkipItems) return;

    ImGuiContext& g = *GImGui;
    ImGuiID id = w->GetID(label);
    float h = 18.f;
    float tw = 32.f;

    ImVec2 pos = w->DC.CursorPos;
    ImRect bb(pos, ImVec2(pos.x + tw, pos.y + h));

    ImGui::ItemSize(ImVec2(tw + 8 + g.FontSize + 8, h));
    if (!ImGui::ItemAdd(bb, id)) return;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held);
    if (pressed) *v = !*v;

    // track background
    ImU32 col_track = *v
        ? Style::accent
        : (hovered ? Style::bg_hover : Style::bg_card);

    // subtle glow when on
    if (*v)
        w->DrawList->AddRectFilled(
            ImVec2(pos.x - 2, pos.y - 2),
            ImVec2(pos.x + tw + 2, pos.y + h + 2),
            Style::accent_dim, h * 0.5f + 2
        );

    w->DrawList->AddRectFilled(pos, ImVec2(pos.x + tw, pos.y + h), col_track, h * 0.5f);
    w->DrawList->AddRect(pos, ImVec2(pos.x + tw, pos.y + h),
        *v ? Style::accent_bright : Style::border, h * 0.5f, 0, 1.f);

    float pad = 2.f;
    float r = (h - pad * 2) * 0.5f;
    float cx = *v ? (pos.x + tw - h * 0.5f) : (pos.x + h * 0.5f);
    w->DrawList->AddCircleFilled(ImVec2(cx, pos.y + h * 0.5f), r,
        IM_COL32(255, 255, 255, *v ? 255 : 180));

    ImGui::SameLine(0.f, 10.f);
    ImGui::TextColored(*v ? ImColor(Style::text) : ImColor(Style::text_muted), "%s", label);
}

static void color_btn(float col[4], const char* id) {
    ImGuiWindow* w = ImGui::GetCurrentWindow();
    if (w->SkipItems) return;

    ImGuiID iid = w->GetID(id);
    ImVec2 pos = w->DC.CursorPos;
    float sz = 18.f;

    ImRect bb(pos, ImVec2(pos.x + sz, pos.y + sz));
    ImGui::ItemSize(bb);
    if (!ImGui::ItemAdd(bb, iid)) return;

    bool hovered, held;
    bool pressed = ImGui::ButtonBehavior(bb, iid, &hovered, &held);
    char popupId[32];
    snprintf(popupId, sizeof(popupId), "cp_%s", id);
    if (pressed) ImGui::OpenPopup(popupId);

    ImU32 c = ImGui::ColorConvertFloat4ToU32(ImVec4(col[0], col[1], col[2], 1));

    // outer glow on hover
    if (hovered)
        w->DrawList->AddRectFilled(
            ImVec2(pos.x - 2, pos.y - 2),
            ImVec2(pos.x + sz + 2, pos.y + sz + 2),
            Style::accent_dim, 5
        );

    w->DrawList->AddRectFilled(pos, ImVec2(pos.x + sz, pos.y + sz), c, 4);
    w->DrawList->AddRect(pos, ImVec2(pos.x + sz, pos.y + sz),
        hovered ? Style::accent_bright : Style::border, 4, 0, hovered ? 1.5f : 1.f);

    if (ImGui::BeginPopup(popupId)) {
        ImGui::ColorPicker4("##p", col,
            ImGuiColorEditFlags_NoInputs |
            ImGuiColorEditFlags_NoSidePreview |
            ImGuiColorEditFlags_AlphaBar);
        ImGui::EndPopup();
    }
}

static void slider(const char* label, float* v, float mn, float mx) {
    ImGui::PushItemWidth(140);
    ImGui::SliderFloat(label, v, mn, mx, "%.1f");
    ImGui::PopItemWidth();
}

static void section(const char* label) {
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 p = ImGui::GetCursorScreenPos();
    float w = ImGui::GetContentRegionAvail().x;

    dl->AddLine(ImVec2(p.x, p.y + 6), ImVec2(p.x + w * 0.3f, p.y + 6), Style::accent_line, 1.f);
    dl->AddLine(ImVec2(p.x + w * 0.7f, p.y + 6), ImVec2(p.x + w, p.y + 6), Style::accent_line, 1.f);

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + w * 0.3f + 6);
    ImGui::TextColored(ImColor(Style::text_muted), "%s", label);
    ImGui::Spacing();
}

static void feature(const char* label, bool* en, float* col = nullptr, float* thick = nullptr) {
    ImGui::PushID(label);

    toggle(label, en);

    if (col && *en) {
        float ww = ImGui::GetWindowWidth();
        ImGui::SameLine(ww - 24);
        color_btn(col, "c");
    }

    if (thick && *en) {
        ImGui::Indent(46);
        slider("##t", thick, 0.5f, 5.0f);
        ImGui::Unindent(46);
    }

    ImGui::PopID();
}

void Menu::Render() {
    if (!IsOpen) return;

    ImGuiStyle& s = ImGui::GetStyle();
    s.WindowRounding = 10;
    s.FrameRounding = 6;
    s.GrabRounding = 4;
    s.PopupRounding = 6;
    s.WindowPadding = ImVec2(0, 0);
    s.FramePadding = ImVec2(8, 5);
    s.ItemSpacing = ImVec2(0, 10);
    s.ItemInnerSpacing = ImVec2(6, 4);
    s.ScrollbarSize = 6;

    ImVec4* c = s.Colors;
    c[ImGuiCol_WindowBg] = ImColor(Style::bg);
    c[ImGuiCol_Text] = ImColor(Style::text);
    c[ImGuiCol_TextDisabled] = ImColor(Style::text_muted);
    c[ImGuiCol_Border] = ImColor(Style::border);
    c[ImGuiCol_Separator] = ImColor(Style::border);
    c[ImGuiCol_FrameBg] = ImColor(Style::bg_card);
    c[ImGuiCol_FrameBgHovered] = ImColor(Style::bg_hover);
    c[ImGuiCol_FrameBgActive] = ImColor(Style::accent_dim);
    c[ImGuiCol_Button] = ImColor(Style::bg_card);
    c[ImGuiCol_ButtonHovered] = ImColor(Style::bg_hover);
    c[ImGuiCol_ButtonActive] = ImColor(Style::accent);
    c[ImGuiCol_SliderGrab] = ImColor(Style::accent);
    c[ImGuiCol_SliderGrabActive] = ImColor(Style::accent_bright);
    c[ImGuiCol_CheckMark] = ImColor(Style::accent_bright);
    c[ImGuiCol_PopupBg] = ImColor(Style::bg_panel);
    c[ImGuiCol_ScrollbarBg] = ImColor(0, 0, 0, 0);
    c[ImGuiCol_ScrollbarGrab] = ImColor(Style::accent_dim);

    ImGui::SetNextWindowSize(ImVec2(580, 420), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImVec2(250, 150), ImGuiCond_Once);

    ImGui::Begin("##csgoon", nullptr,
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoTitleBar);

    ImVec2 wp = ImGui::GetWindowPos();
    ImVec2 ws = ImGui::GetWindowSize();
    ImDrawList* dl = ImGui::GetWindowDrawList();

    float sidebar = 120.f;

    // outer border glow
    dl->AddRect(
        ImVec2(wp.x - 1, wp.y - 1),
        ImVec2(wp.x + ws.x + 1, wp.y + ws.y + 1),
        Style::accent_dim, 11, 0, 1.5f
    );

    // sidebar 
    dl->AddRectFilled(
        ImVec2(wp.x, wp.y),
        ImVec2(wp.x + sidebar, wp.y + ws.y),
        Style::bg_panel, 10, ImDrawFlags_RoundCornersLeft
    );

    // sidebar right border - gradient feel with two lines
    dl->AddLine(
        ImVec2(wp.x + sidebar, wp.y + 10),
        ImVec2(wp.x + sidebar, wp.y + ws.y - 10),
        Style::border, 1.f
    );
    dl->AddLine(
        ImVec2(wp.x + sidebar + 1, wp.y + 10),
        ImVec2(wp.x + sidebar + 1, wp.y + ws.y - 10),
        Style::accent_line, 1.f
    );

    // logo / title 
    ImGui::SetCursorPos(ImVec2(14, 16));

    // accent bar left of title
    ImVec2 ts = ImGui::GetCursorScreenPos();
    dl->AddRectFilled(
        ImVec2(ts.x - 4, ts.y),
        ImVec2(ts.x - 1, ts.y + 16),
        Style::accent_bright, 1
    );

    ImGui::TextColored(ImColor(Style::accent_bright), "csgoon");
    ImGui::SetCursorPos(ImVec2(14, 32));
    ImGui::TextColored(ImColor(Style::text_dim), "v1.0");

    // tabs 
    ImGui::SetCursorPosY(58);

    for (int i = 0; i < 5; i++) {
        ImGui::PushID(i);
        ImGui::SetCursorPosX(10);

        ImVec2 sp = ImGui::GetCursorScreenPos();
        bool active = g_tab == i;

        if (active) {
            dl->AddRectFilled(
                ImVec2(sp.x - 2, sp.y - 3),
                ImVec2(sp.x + sidebar - 18, sp.y + 26),
                Style::bg_active, 6
            );
            dl->AddRectFilled(
                ImVec2(sp.x - 2, sp.y - 3),
                ImVec2(sp.x + 2, sp.y + 26),
                Style::accent, 2
            );
            dl->AddRectFilled(
                ImVec2(sp.x + sidebar - 20, sp.y - 3),
                ImVec2(sp.x + sidebar - 18, sp.y + 26),
                Style::accent_dim, 2
            );
        }

        ImGui::PushStyleColor(ImGuiCol_Text,
            active ? Style::accent_bright : Style::text_muted);
        ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(0, 0, 0, 0));

        if (ImGui::Button(tabs[i], ImVec2(sidebar - 20, 22)))
            g_tab = i;

        ImGui::PopStyleColor(4);
        ImGui::PopID();
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 4);
    }

    // content 
    ImGui::SetCursorPos(ImVec2(sidebar + 16, 12));
    ImGui::BeginChild("content", ImVec2(ws.x - sidebar - 28, ws.y - 24), false,
        ImGuiWindowFlags_NoScrollbar);

    if (g_tab == 0) {
        ImGui::PushID("tab_rage");
        section("ragebot");
        feature("enable", &Globals::rage_enabled);
        feature("silent aim", &Globals::rage_silent);
        feature("auto shoot", &Globals::rage_autoshoot);
        feature("multipoint", &Globals::rage_multipoint);
        ImGui::Spacing();
        slider("hitchance", &Globals::rage_hitchance, 0, 100);
        slider("min damage", &Globals::rage_mindmg, 1, 100);
        ImGui::PopID();
    }
    else if (g_tab == 1) {
        ImGui::PushID("tab_legit");
        section("legitbot");
        feature("enable", &Globals::legit_enabled);
        feature("aim lock", &Globals::legit_lock);
        feature("rcs", &Globals::legit_rcs);
        ImGui::Spacing();
        slider("smooth", &Globals::legit_smooth, 1, 20);
        slider("fov", &Globals::legit_fov, 1, 15);

        ImGui::Spacing();
        ImGui::PushID("tab_trigger");
        section("triggerbot");
        feature("enable", &Globals::trigger_enabled);
        if (Globals::trigger_enabled) {
            ImGui::Indent(12);
            ImGui::SliderInt("delay (ms)", &Globals::trigger_delay, 0, 100);
            feature("use keybind", &Globals::trigger_keybind_enabled);
            if (Globals::trigger_keybind_enabled) {
                feature("toggle mode", &Globals::trigger_keybind_toggle);
                static bool waitingForKey = false;
                if (waitingForKey) {
                    ImGui::Button("press any key...", ImVec2(150, 0));
                    for (int i = 0; i < 256; i++) {
                        if (i == VK_LBUTTON || i == VK_ESCAPE) continue;
                        if (GetAsyncKeyState(i) & 0x8000) {
                            Globals::trigger_key = i;
                            waitingForKey = false;
                            break;
                        }
                    }
                }
                else {
                    if (ImGui::Button("bind key", ImVec2(90, 0)))
                        waitingForKey = true;
                    ImGui::SameLine(0, 6);
                    if (ImGui::Button("clear", ImVec2(46, 0)))
                        Globals::trigger_key = 0;
                    ImGui::SameLine(0, 8);
                    ImGui::TextColored(ImColor(Style::text_muted),
                        "vk: 0x%02X", Globals::trigger_key);
                }
            }
            ImGui::Unindent(12);
        }
        ImGui::PopID();
        ImGui::PopID();
    }
    else if (g_tab == 2) {
        ImGui::PushID("tab_visuals");

        float totalW = ImGui::GetContentRegionAvail().x;
        float leftW = totalW * 0.52f;
        float rightW = totalW - leftW - 8.f;

        // feature toggles 
        ImGui::BeginChild("vis_left", ImVec2(leftW, 0), false, ImGuiWindowFlags_NoScrollbar);
        section("visuals");
        feature("enable", &Globals::esp_enabled);
        feature("corner box", &Globals::esp_corner_box, Globals::esp_box_color, &Globals::esp_box_thickness);
        if (Globals::esp_corner_box) Globals::esp_box = false;
        feature("box", &Globals::esp_box, Globals::esp_box_color, &Globals::esp_box_thickness);
        if (Globals::esp_box) Globals::esp_corner_box = false;
        feature("box fill", &Globals::esp_box_fill, Globals::esp_box_fill_color);
        feature("skeleton", &Globals::esp_skeleton, Globals::esp_skeleton_color, &Globals::esp_skeleton_thickness);
        feature("health", &Globals::esp_health);
        feature("enemy only", &Globals::esp_enemy_only);
        ImGui::EndChild();

        ImGui::SameLine(0, 8.f);

        // preview 
        ImGui::BeginChild("vis_right", ImVec2(rightW, 0), false, ImGuiWindowFlags_NoScrollbar);

        ImDrawList* pdl = ImGui::GetWindowDrawList();
        ImVec2      pPos = ImGui::GetCursorScreenPos();

        float pW = rightW - 4.f;
        float pH = 200.f;
        float pX = pPos.x;
        float pY = pPos.y + 16.f;

        // label
        ImGui::SetCursorScreenPos(ImVec2(pX + pW * 0.5f - 22.f, pPos.y));
        ImGui::TextColored(ImColor(Style::text_dim), "preview");
        ImGui::Dummy(ImVec2(pW, pH));

        // background
        pdl->AddRectFilled(ImVec2(pX, pY), ImVec2(pX + pW, pY + pH), Style::bg_card, 6);
        pdl->AddRect(ImVec2(pX, pY), ImVec2(pX + pW, pY + pH), Style::border, 6, 0, 1.f);

        // figure layout
        float cx = pX + pW * 0.5f;
        float fw = pW * 0.38f;
        float fTop = pY + pH * 0.06f;
        float fBot = pY + pH * 0.94f;
        float fH = fBot - fTop;

        ImVec2 head = { cx,             fTop + fH * 0.06f };
        ImVec2 neck = { cx,             fTop + fH * 0.14f };
        ImVec2 chest = { cx,             fTop + fH * 0.30f };
        ImVec2 pelvis = { cx,             fTop + fH * 0.46f };
        ImVec2 lsho = { cx - fw * 0.40f,  fTop + fH * 0.20f };
        ImVec2 lelbow = { cx - fw * 0.52f,  fTop + fH * 0.34f };
        ImVec2 lhand = { cx - fw * 0.50f,  fTop + fH * 0.46f };
        ImVec2 rsho = { cx + fw * 0.40f,  fTop + fH * 0.20f };
        ImVec2 relbow = { cx + fw * 0.52f,  fTop + fH * 0.34f };
        ImVec2 rhand = { cx + fw * 0.50f,  fTop + fH * 0.46f };
        ImVec2 lhip = { cx - fw * 0.22f,  fTop + fH * 0.46f };
        ImVec2 lknee = { cx - fw * 0.28f,  fTop + fH * 0.68f };
        ImVec2 lfoot = { cx - fw * 0.26f,  fTop + fH * 0.90f };
        ImVec2 rhip = { cx + fw * 0.22f,  fTop + fH * 0.46f };
        ImVec2 rknee = { cx + fw * 0.28f,  fTop + fH * 0.68f };
        ImVec2 rfoot = { cx + fw * 0.26f,  fTop + fH * 0.90f };

        // box bounds
        float bx = cx - fw * 0.55f;
        float by = head.y - fH * 0.06f;
        float bw = fw * 1.1f;
        float bh = lfoot.y - by + fH * 0.02f;

        ImU32 boxCol = ImGui::ColorConvertFloat4ToU32(ImVec4(
            Globals::esp_box_color[0], Globals::esp_box_color[1],
            Globals::esp_box_color[2], Globals::esp_box_color[3]));

        // fill
        if (Globals::esp_box_fill)
            pdl->AddRectFilled(ImVec2(bx, by), ImVec2(bx + bw, by + bh),
                ImGui::ColorConvertFloat4ToU32(ImVec4(
                    Globals::esp_box_fill_color[0], Globals::esp_box_fill_color[1],
                    Globals::esp_box_fill_color[2], Globals::esp_box_fill_color[3])));

        // full box
        if (Globals::esp_box)
            pdl->AddRect(ImVec2(bx, by), ImVec2(bx + bw, by + bh), boxCol, 0, 0, Globals::esp_box_thickness);

        // corner box
        if (Globals::esp_corner_box) {
            float cl = bw * 0.25f;
            float th = Globals::esp_box_thickness;
            pdl->AddLine({ bx,      by }, { bx + cl,    by }, boxCol, th);
            pdl->AddLine({ bx,      by }, { bx,       by + cl }, boxCol, th);
            pdl->AddLine({ bx + bw,   by }, { bx + bw - cl, by }, boxCol, th);
            pdl->AddLine({ bx + bw,   by }, { bx + bw,    by + cl }, boxCol, th);
            pdl->AddLine({ bx,      by + bh }, { bx + cl,    by + bh }, boxCol, th);
            pdl->AddLine({ bx,      by + bh }, { bx,       by + bh - cl }, boxCol, th);
            pdl->AddLine({ bx + bw,   by + bh }, { bx + bw - cl, by + bh }, boxCol, th);
            pdl->AddLine({ bx + bw,   by + bh }, { bx + bw,    by + bh - cl }, boxCol, th);
        }

        // health bar
        if (Globals::esp_health) {
            float hbX = bx - 5.f;
            pdl->AddRectFilled(ImVec2(hbX - 2, by - 1), ImVec2(hbX + 2, by + bh + 1), IM_COL32(0, 0, 0, 150));
            pdl->AddRectFilled(ImVec2(hbX - 1, by + bh * 0.30f), ImVec2(hbX + 1, by + bh), IM_COL32(0, 255, 0, 255));
        }

        // skeleton
        if (Globals::esp_skeleton) {
            ImU32 sc = ImGui::ColorConvertFloat4ToU32(ImVec4(
                Globals::esp_skeleton_color[0], Globals::esp_skeleton_color[1],
                Globals::esp_skeleton_color[2], Globals::esp_skeleton_color[3]));
            float st = Globals::esp_skeleton_thickness;

            pdl->AddLine(head, neck, sc, st);
            pdl->AddLine(neck, chest, sc, st);
            pdl->AddLine(chest, pelvis, sc, st);
            pdl->AddLine(chest, lsho, sc, st);
            pdl->AddLine(lsho, lelbow, sc, st);
            pdl->AddLine(lelbow, lhand, sc, st);
            pdl->AddLine(chest, rsho, sc, st);
            pdl->AddLine(rsho, relbow, sc, st);
            pdl->AddLine(relbow, rhand, sc, st);
            pdl->AddLine(pelvis, lhip, sc, st);
            pdl->AddLine(lhip, lknee, sc, st);
            pdl->AddLine(lknee, lfoot, sc, st);
            pdl->AddLine(pelvis, rhip, sc, st);
            pdl->AddLine(rhip, rknee, sc, st);
            pdl->AddLine(rknee, rfoot, sc, st);
        }

        // head circle
        ImU32 headCol = ImGui::ColorConvertFloat4ToU32(ImVec4(
            Globals::esp_skeleton_color[0], Globals::esp_skeleton_color[1],
            Globals::esp_skeleton_color[2], Globals::esp_skeleton_color[3]));
        pdl->AddCircle(head, fH * 0.065f, headCol, 16, Globals::esp_skeleton_thickness);

        ImGui::EndChild();
        ImGui::PopID();
    }
    else if (g_tab == 3) {
        ImGui::PushID("tab_misc");
        section("misc");
        feature("bhop", &Globals::misc_bhop);
        feature("auto strafe", &Globals::misc_autostrafe);
        feature("radar", &Globals::misc_radar);
        feature("no flash", &Globals::misc_noflash);
        ImGui::PopID();
    }
    else if (g_tab == 4) {
        ImGui::PushID("tab_configs");
        section("configs");

        // config name input + create button
        static char newConfigName[64] = "";
        ImGui::InputText("##configname", newConfigName, sizeof(newConfigName));
        ImGui::SameLine(0, 6);
        if (ImGui::Button("create", ImVec2(60, 0))) {
            if (strlen(newConfigName) > 0) {
                Configs::Create(newConfigName);
                memset(newConfigName, 0, sizeof(newConfigName));
            }
        }

        ImGui::Spacing();

        // config list
        static int selectedConfig = -1;
        auto configs = Configs::GetConfigs();

        if (!configs.empty()) {
            // listbox showing all configs
            if (ImGui::BeginListBox("##configs", ImVec2(-1, 80))) {
                for (int i = 0; i < (int)configs.size(); i++) {
                    bool selected = selectedConfig == i;
                    if (ImGui::Selectable(configs[i].c_str(), selected))
                        selectedConfig = i;
                }
                ImGui::EndListBox();
            }

            // action buttons
            if (selectedConfig >= 0 && selectedConfig < (int)configs.size()) {
                if (ImGui::Button("save", ImVec2(60, 0)))
                    Configs::Save(configs[selectedConfig]);
                ImGui::SameLine(0, 6);
                if (ImGui::Button("load", ImVec2(60, 0)))
                    Configs::Load(configs[selectedConfig]);
                ImGui::SameLine(0, 6);
                if (ImGui::Button("delete", ImVec2(60, 0)))
                    Configs::Delete(configs[selectedConfig]);
            }
        }

        ImGui::Spacing();
        section("autoload");
        feature("enable autoload", &Globals::autoload_enabled);
        if (Globals::autoload_enabled && !configs.empty()) {
            // dropdown for autoload selection
            std::string preview = Configs::autoLoadConfig.empty() ? "none" : Configs::autoLoadConfig;
            if (ImGui::BeginCombo("##autoload", preview.c_str())) {
                if (ImGui::Selectable("none", Configs::autoLoadConfig.empty()))
                    Configs::autoLoadConfig = "";
                for (const auto& cfg : configs) {
                    bool sel = Configs::autoLoadConfig == cfg;
                    if (ImGui::Selectable(cfg.c_str(), sel)) {
                        Configs::autoLoadConfig = cfg;
                        // save autoload setting
                        std::ofstream f(Configs::configDir + "autoload.txt");
                        f << Configs::autoLoadConfig;
                        f.close();
                    }
                }
                ImGui::EndCombo();
            }
        }

        ImGui::Spacing();
        if (ImGui::Button("reset all", ImVec2(100, 0)))
            Configs::Reset();

        ImGui::PopID();
    }

    ImGui::EndChild();
    ImGui::End();
}