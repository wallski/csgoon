#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "../../ext/imgui/imgui.h"
#include "../../ext/imgui/imgui_internal.h"
#include "../sdk/utils/Globals.h"
#include "../feature/misc/configs/Configs.h"
#include <Windows.h>
#include <stdio.h>
#include <fstream>

// ──────────────────────────────────────────────────────────────────────────────
//  STYLE PALETTE
// ──────────────────────────────────────────────────────────────────────────────
namespace Style {
    constexpr ImU32 bg = IM_COL32(8, 7, 14, 255);
    constexpr ImU32 bg_panel = IM_COL32(13, 11, 22, 255);
    constexpr ImU32 bg_card = IM_COL32(18, 15, 32, 255);
    constexpr ImU32 bg_hover = IM_COL32(28, 22, 50, 255);
    constexpr ImU32 bg_active = IM_COL32(38, 28, 68, 255);

    constexpr ImU32 accent = IM_COL32(138, 43, 226, 255);
    constexpr ImU32 accent_bright = IM_COL32(180, 90, 255, 255);
    constexpr ImU32 accent_dim = IM_COL32(90, 28, 150, 160);
    constexpr ImU32 accent_line = IM_COL32(138, 43, 226, 60);

    constexpr ImU32 text = IM_COL32(235, 228, 255, 255);
    constexpr ImU32 text_muted = IM_COL32(110, 95, 155, 255);
    constexpr ImU32 text_dim = IM_COL32(60, 50, 90, 255);

    constexpr ImU32 border = IM_COL32(45, 35, 75, 255);
    constexpr ImU32 border_bright = IM_COL32(90, 60, 150, 255);
}

static int g_tab = 0;
static int vis_tab = 0; // 0 = enemy, 1 = team
static const char* tabs[] = { "ragebot", "legitbot", "visuals", "misc", "configs" };

// ──────────────────────────────────────────────────────────────────────────────
//  WIDGETS
// ──────────────────────────────────────────────────────────────────────────────

static void toggle(const char* label, bool* v) {
    ImGuiWindow* w = ImGui::GetCurrentWindow();
    if (w->SkipItems) return;

    ImGuiContext& g = *GImGui;
    ImGuiID id = w->GetID(label);
    float h = 18.f, tw = 32.f;

    ImVec2 pos = w->DC.CursorPos;
    ImRect bb(pos, ImVec2(pos.x + tw, pos.y + h));
    ImGui::ItemSize(ImVec2(tw + 8 + g.FontSize + 8, h));
    if (!ImGui::ItemAdd(bb, id)) return;

    bool hov, held;
    bool pressed = ImGui::ButtonBehavior(bb, id, &hov, &held);
    if (pressed) *v = !*v;

    ImU32 col_track = *v ? Style::accent : (hov ? Style::bg_hover : Style::bg_card);
    if (*v)
        w->DrawList->AddRectFilled(
            ImVec2(pos.x - 2, pos.y - 2), ImVec2(pos.x + tw + 2, pos.y + h + 2),
            Style::accent_dim, h * 0.5f + 2);

    w->DrawList->AddRectFilled(pos, ImVec2(pos.x + tw, pos.y + h), col_track, h * 0.5f);
    w->DrawList->AddRect(pos, ImVec2(pos.x + tw, pos.y + h),
        *v ? Style::accent_bright : Style::border, h * 0.5f, 0, 1.f);

    float r = (h - 4.f) * 0.5f;
    float cx = *v ? (pos.x + tw - h * 0.5f) : (pos.x + h * 0.5f);
    w->DrawList->AddCircleFilled({ cx, pos.y + h * 0.5f }, r,
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

    bool hov, held;
    bool pressed = ImGui::ButtonBehavior(bb, iid, &hov, &held);
    char popId[32]; snprintf(popId, sizeof(popId), "cp_%s", id);
    if (pressed) ImGui::OpenPopup(popId);

    ImU32 c = ImGui::ColorConvertFloat4ToU32(ImVec4(col[0], col[1], col[2], 1));
    if (hov)
        w->DrawList->AddRectFilled(
            ImVec2(pos.x - 2, pos.y - 2), ImVec2(pos.x + sz + 2, pos.y + sz + 2),
            Style::accent_dim, 5);
    w->DrawList->AddRectFilled(pos, ImVec2(pos.x + sz, pos.y + sz), c, 4);
    w->DrawList->AddRect(pos, ImVec2(pos.x + sz, pos.y + sz),
        hov ? Style::accent_bright : Style::border, 4, 0, hov ? 1.5f : 1.f);

    if (ImGui::BeginPopup(popId)) {
        ImGui::ColorPicker4("##p", col,
            ImGuiColorEditFlags_NoInputs |
            ImGuiColorEditFlags_NoSidePreview |
            ImGuiColorEditFlags_AlphaBar);
        ImGui::EndPopup();
    }
}

static void slider_f(const char* label, float* v, float mn, float mx, float w = 140.f) {
    ImGui::PushItemWidth(w);
    ImGui::SliderFloat(label, v, mn, mx, "%.1f");
    ImGui::PopItemWidth();
}

static void slider_i(const char* label, int* v, int mn, int mx, float w = 140.f) {
    ImGui::PushItemWidth(w);
    ImGui::SliderInt(label, v, mn, mx);
    ImGui::PopItemWidth();
}

static void section(const char* label) {
    ImDrawList* dl = ImGui::GetWindowDrawList();
    ImVec2 p = ImGui::GetCursorScreenPos();
    float  cw = ImGui::GetContentRegionAvail().x;

    dl->AddLine({ p.x,            p.y + 6 }, { p.x + cw * 0.28f, p.y + 6 }, Style::accent_line, 1.f);
    dl->AddLine({ p.x + cw * 0.72f, p.y + 6 }, { p.x + cw,       p.y + 6 }, Style::accent_line, 1.f);

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + cw * 0.28f + 6);
    ImGui::TextColored(ImColor(Style::text_muted), "%s", label);
    ImGui::Spacing();
}

static void feature(const char* label, bool* en,
    float* col = nullptr, float* thick = nullptr) {
    ImGui::PushID(label);
    toggle(label, en);
    if (col && *en) {
        ImGui::SameLine(ImGui::GetWindowWidth() - 24);
        color_btn(col, "c");
    }
    if (thick && *en) {
        ImGui::Indent(46);
        slider_f("##t", thick, 0.5f, 5.f);
        ImGui::Unindent(46);
    }
    ImGui::PopID();
}

static bool begin_col(const char* id, float totalW, bool right) {
    float half = (totalW - 12.f) * 0.5f;
    if (right) ImGui::SameLine(0, 12.f);
    return ImGui::BeginChild(id, ImVec2(half, 0), false,
        ImGuiWindowFlags_NoScrollbar);
}
static void end_col() { ImGui::EndChild(); }

// ──────────────────────────────────────────────────────────────────────────────
//  PREVIEW FIGURE
//  Extracted into a helper so we can call it twice — once for enemy, once for
//  team — without duplicating the draw code. Just pass in the right globals.
// ──────────────────────────────────────────────────────────────────────────────
static void draw_preview(
    const char* id,
    bool showBox, bool showCorner, float* boxColor, float boxThick,
    bool showFill, float* fillColor,
    bool showSkel, float* skelColor, float skelThick,
    bool showHealth)
{
    ImGui::PushID(id);

    ImDrawList* pdl = ImGui::GetWindowDrawList();
    ImVec2      pPos = ImGui::GetCursorScreenPos();
    float       pW = ImGui::GetContentRegionAvail().x - 4.f;
    float       pH = 240.f;
    float       pX = pPos.x;
    float       pY = pPos.y + 18.f;

    ImGui::SetCursorScreenPos({ pX + pW * 0.5f - 22.f, pPos.y });
    ImGui::TextColored(ImColor(Style::text_dim), "preview");
    ImGui::Dummy({ pW, pH });

    pdl->AddRectFilled({ pX,pY }, { pX + pW,pY + pH }, Style::bg_card, 6);
    pdl->AddRect({ pX,pY }, { pX + pW,pY + pH }, Style::border, 6, 0, 1.f);

    float cx = pX + pW * 0.5f;
    float fw = pW * 0.38f;
    float fTop = pY + pH * 0.06f;
    float fBot = pY + pH * 0.94f;
    float fH = fBot - fTop;

    ImVec2 head = { cx,            fTop + fH * 0.06f };
    ImVec2 neck = { cx,            fTop + fH * 0.14f };
    ImVec2 chest = { cx,            fTop + fH * 0.30f };
    ImVec2 pelvis = { cx,            fTop + fH * 0.46f };
    ImVec2 lsho = { cx - fw * 0.40f, fTop + fH * 0.20f };
    ImVec2 lelbow = { cx - fw * 0.52f, fTop + fH * 0.34f };
    ImVec2 lhand = { cx - fw * 0.50f, fTop + fH * 0.46f };
    ImVec2 rsho = { cx + fw * 0.40f, fTop + fH * 0.20f };
    ImVec2 relbow = { cx + fw * 0.52f, fTop + fH * 0.34f };
    ImVec2 rhand = { cx + fw * 0.50f, fTop + fH * 0.46f };
    ImVec2 lhip = { cx - fw * 0.22f, fTop + fH * 0.46f };
    ImVec2 lknee = { cx - fw * 0.28f, fTop + fH * 0.68f };
    ImVec2 lfoot = { cx - fw * 0.26f, fTop + fH * 0.90f };
    ImVec2 rhip = { cx + fw * 0.22f, fTop + fH * 0.46f };
    ImVec2 rknee = { cx + fw * 0.28f, fTop + fH * 0.68f };
    ImVec2 rfoot = { cx + fw * 0.26f, fTop + fH * 0.90f };

    float bx = cx - fw * 0.55f;
    float by = head.y - fH * 0.06f;
    float bw = fw * 1.1f;
    float bh = lfoot.y - by + fH * 0.02f;

    ImU32 boxCol = ImGui::ColorConvertFloat4ToU32(
        ImVec4(boxColor[0], boxColor[1], boxColor[2], boxColor[3]));

    if (showFill)
        pdl->AddRectFilled({ bx,by }, { bx + bw,by + bh },
            ImGui::ColorConvertFloat4ToU32(
                ImVec4(fillColor[0], fillColor[1], fillColor[2], fillColor[3])));

    if (showBox)
        pdl->AddRect({ bx,by }, { bx + bw,by + bh }, boxCol, 0, 0, boxThick);

    if (showCorner) {
        float cl = bw * 0.25f;
        pdl->AddLine({ bx,      by }, { bx + cl,    by }, boxCol, boxThick);
        pdl->AddLine({ bx,      by }, { bx,       by + cl }, boxCol, boxThick);
        pdl->AddLine({ bx + bw,   by }, { bx + bw - cl, by }, boxCol, boxThick);
        pdl->AddLine({ bx + bw,   by }, { bx + bw,    by + cl }, boxCol, boxThick);
        pdl->AddLine({ bx,    by + bh }, { bx + cl,    by + bh }, boxCol, boxThick);
        pdl->AddLine({ bx,    by + bh }, { bx,       by + bh - cl }, boxCol, boxThick);
        pdl->AddLine({ bx + bw, by + bh }, { bx + bw - cl, by + bh }, boxCol, boxThick);
        pdl->AddLine({ bx + bw, by + bh }, { bx + bw,    by + bh - cl }, boxCol, boxThick);
    }

    if (showHealth) {
        float hbX = bx - 5.f;
        pdl->AddRectFilled({ hbX - 2, by - 1 }, { hbX + 2, by + bh + 1 }, IM_COL32(0, 0, 0, 150));
        pdl->AddRectFilled({ hbX - 1, by + bh * 0.30f }, { hbX + 1, by + bh }, IM_COL32(0, 255, 0, 255));
    }

    if (showSkel) {
        ImU32 sc = ImGui::ColorConvertFloat4ToU32(
            ImVec4(skelColor[0], skelColor[1], skelColor[2], skelColor[3]));
        auto line = [&](ImVec2 a, ImVec2 b) { pdl->AddLine(a, b, sc, skelThick); };
        line(head, neck);   line(neck, chest);   line(chest, pelvis);
        line(chest, lsho);  line(lsho, lelbow);  line(lelbow, lhand);
        line(chest, rsho);  line(rsho, relbow);  line(relbow, rhand);
        line(pelvis, lhip); line(lhip, lknee);   line(lknee, lfoot);
        line(pelvis, rhip); line(rhip, rknee);   line(rknee, rfoot);
    }

    ImU32 headCol = ImGui::ColorConvertFloat4ToU32(
        ImVec4(skelColor[0], skelColor[1], skelColor[2], skelColor[3]));
    pdl->AddCircle(head, fH * 0.065f, headCol, 16, skelThick);

    ImGui::PopID();
}

// ──────────────────────────────────────────────────────────────────────────────
//  MENU::RENDER
// ──────────────────────────────────────────────────────────────────────────────
void Menu::Render() {
    if (!IsOpen) return;

    ImGuiStyle& s = ImGui::GetStyle();
    s.WindowRounding = 10; s.FrameRounding = 6;
    s.GrabRounding = 4; s.PopupRounding = 6;
    s.WindowPadding = { 0,0 };
    s.FramePadding = { 8,5 };
    s.ItemSpacing = { 0,10 };
    s.ItemInnerSpacing = { 6,4 };
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

    ImGui::SetNextWindowSize({ 680, 480 }, ImGuiCond_Once);
    ImGui::SetNextWindowPos({ 250, 150 }, ImGuiCond_Once);
    ImGui::Begin("##csgoon", nullptr,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar);

    ImVec2 wp = ImGui::GetWindowPos();
    ImVec2 ws = ImGui::GetWindowSize();
    ImDrawList* dl = ImGui::GetWindowDrawList();
    const float sidebar = 120.f;

    // outer glow
    dl->AddRect({ wp.x - 1,wp.y - 1 }, { wp.x + ws.x + 1,wp.y + ws.y + 1 },
        Style::accent_dim, 11, 0, 1.5f);

    // sidebar bg + border lines
    dl->AddRectFilled({ wp.x,wp.y }, { wp.x + sidebar,wp.y + ws.y },
        Style::bg_panel, 10, ImDrawFlags_RoundCornersLeft);
    dl->AddLine({ wp.x + sidebar,   wp.y + 10 }, { wp.x + sidebar,   wp.y + ws.y - 10 }, Style::border, 1.f);
    dl->AddLine({ wp.x + sidebar + 1, wp.y + 10 }, { wp.x + sidebar + 1, wp.y + ws.y - 10 }, Style::accent_line, 1.f);

    // logo
    ImGui::SetCursorPos({ 14, 16 });
    ImVec2 ts = ImGui::GetCursorScreenPos();
    dl->AddRectFilled({ ts.x - 4, ts.y }, { ts.x - 1, ts.y + 16 }, Style::accent_bright, 1);
    ImGui::TextColored(ImColor(Style::accent_bright), "csgoon");
    ImGui::SetCursorPos({ 14, 32 });
    ImGui::TextColored(ImColor(Style::text_dim), "v1.0");

    // ── sidebar tabs ──────────────────────────────────────────────────────────
    ImGui::SetCursorPosY(58);
    for (int i = 0; i < 5; i++) {
        ImGui::PushID(i);
        ImGui::SetCursorPosX(10);
        ImVec2 sp = ImGui::GetCursorScreenPos();
        bool   active = (g_tab == i);

        if (active) {
            dl->AddRectFilled({ sp.x - 2,         sp.y - 3 }, { sp.x + sidebar - 18, sp.y + 26 }, Style::bg_active, 6);
            dl->AddRectFilled({ sp.x - 2,         sp.y - 3 }, { sp.x + 2,          sp.y + 26 }, Style::accent, 2);
            dl->AddRectFilled({ sp.x + sidebar - 20,sp.y - 3 }, { sp.x + sidebar - 18, sp.y + 26 }, Style::accent_dim, 2);
        }

        ImGui::PushStyleColor(ImGuiCol_Text, active ? Style::accent_bright : Style::text_muted);
        ImGui::PushStyleColor(ImGuiCol_Button, IM_COL32(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(0, 0, 0, 0));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, IM_COL32(0, 0, 0, 0));
        if (ImGui::Button(tabs[i], { sidebar - 20, 22 })) g_tab = i;
        ImGui::PopStyleColor(4);
        ImGui::PopID();
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 4);
    }

    // ── content area ──────────────────────────────────────────────────────────
    ImGui::SetCursorPos({ sidebar + 16, 12 });
    ImGui::BeginChild("##content", { ws.x - sidebar - 28, ws.y - 24 },
        false, ImGuiWindowFlags_NoScrollbar);
    float cw = ImGui::GetContentRegionAvail().x;

    // ══════════════════════════════════════════════════════════════════════════
    //  TAB 0 — RAGEBOT
    // ══════════════════════════════════════════════════════════════════════════
    if (g_tab == 0) {
        ImGui::PushID("rage");

        if (begin_col("rage_l", cw, false)) {
            section("ragebot");
            feature("enable", &Globals::rage_enabled);
            if (Globals::rage_enabled) Globals::legit_enabled = false;
            feature("silent aim", &Globals::rage_silent);
            feature("team check", &Globals::aim_team_check);
            feature("auto shoot", &Globals::rage_autoshoot);
            feature("multipoint", &Globals::rage_multipoint);
            end_col();
        }
        if (begin_col("rage_r", cw, true)) {
            section("settings");
            ImGui::Spacing();
            ImGui::TextColored(ImColor(Style::text_muted), "hitchance");
            ImGui::Spacing();
            slider_f("##hc", &Globals::rage_hitchance, 0, 100, cw * 0.46f);
            ImGui::Spacing();
            ImGui::TextColored(ImColor(Style::text_muted), "min damage");
            ImGui::Spacing();
            slider_f("##md", &Globals::rage_mindmg, 1, 100, cw * 0.46f);
            ImGui::Spacing();
            ImGui::TextColored(ImColor(Style::text_muted), "fov");
            ImGui::Spacing();
            slider_f("##fv", &Globals::rage_fov, 1, 15, cw * 0.46f);
            end_col();
        }

        ImGui::PopID();
    }

    // ══════════════════════════════════════════════════════════════════════════
    //  TAB 1 — LEGITBOT + TRIGGERBOT
    // ══════════════════════════════════════════════════════════════════════════
    else if (g_tab == 1) {
        ImGui::PushID("legit");

        if (begin_col("legit_l", cw, false)) {
            section("legitbot");
            feature("enable", &Globals::legit_enabled);
            if (Globals::legit_enabled) Globals::rage_enabled = false;
            feature("aim lock", &Globals::legit_lock);
            feature("rcs", &Globals::legit_rcs);
            feature("team check", &Globals::aim_team_check);
            ImGui::Spacing();
            ImGui::TextColored(ImColor(Style::text_muted), "smooth");
            ImGui::Spacing();
            slider_f("##sm", &Globals::legit_smooth, 1, 20, cw * 0.46f);
            ImGui::Spacing();
            ImGui::TextColored(ImColor(Style::text_muted), "fov");
            ImGui::Spacing();
            slider_f("##fv", &Globals::legit_fov, 1, 15, cw * 0.46f);
            end_col();
        }
        if (begin_col("legit_r", cw, true)) {
            section("triggerbot");
            feature("enable", &Globals::trigger_enabled);

            if (Globals::trigger_enabled) {
                ImGui::Spacing();
                ImGui::TextColored(ImColor(Style::text_muted), "delay (ms)");
                ImGui::Spacing();
                slider_i("##td", &Globals::trigger_delay, 0, 200, cw * 0.46f);
                ImGui::Spacing();
                feature("use keybind", &Globals::trigger_keybind_enabled);

                if (Globals::trigger_keybind_enabled) {
                    ImGui::Indent(12);
                    feature("toggle mode", &Globals::trigger_keybind_toggle);
                    ImGui::Spacing();

                    static bool waitingForKey = false;
                    if (waitingForKey) {
                        ImGui::Button("press any key...", { 140, 0 });
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
                        if (ImGui::Button("bind key", { 80, 0 })) waitingForKey = true;
                        ImGui::SameLine(0, 6);
                        if (ImGui::Button("clear", { 46, 0 })) Globals::trigger_key = 0;
                        ImGui::Spacing();
                        ImGui::TextColored(ImColor(Style::text_muted),
                            "vk: 0x%02X", Globals::trigger_key);
                    }
                    ImGui::Unindent(12);
                }
            }
            end_col();
        }

        ImGui::PopID();
    }

    // ══════════════════════════════════════════════════════════════════════════
    //  TAB 2 — VISUALS
    // ══════════════════════════════════════════════════════════════════════════
    else if (g_tab == 2) {
        ImGui::PushID("vis");

        // ── sub-tab bar with ESP master toggle ───────────────────────────────────
        {
            const char* vtabs[] = { "enemy", "team" };

            // Sub-tabs
            for (int i = 0; i < 2; i++) {
                bool active = (vis_tab == i);
                ImGui::PushID(i);
                ImGui::PushStyleColor(ImGuiCol_Button, active ? Style::accent : Style::bg_card);
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, active ? Style::accent : Style::bg_hover);
                ImGui::PushStyleColor(ImGuiCol_Text, active ? Style::accent_bright : Style::text_muted);
                if (ImGui::Button(vtabs[i], { 80, 24 })) vis_tab = i;
                ImGui::PopStyleColor(3);
                ImGui::PopID();
                if (i == 0) ImGui::SameLine(0, 4);
            }

            // ESP master toggle next to tabs
            ImGui::SameLine(0, 12);
            toggle("enabled", &Globals::esp_enabled);
        }

        ImGui::Spacing();
        ImGui::Spacing();

        // ── enemy sub-tab ─────────────────────────────────────────────────────
        if (vis_tab == 0) {
            ImGui::PushID("en");

            if (begin_col("en_l", cw, false)) {
                section("general");
                feature("enemy enabled", &Globals::esp_enemy_enabled);
                feature("health bar", &Globals::esp_health);

                ImGui::Spacing();
                section("box");
                feature("corner box", &Globals::esp_corner_box,
                    Globals::esp_box_color, &Globals::esp_box_thickness);
                if (Globals::esp_corner_box) Globals::esp_box = false;

                feature("box", &Globals::esp_box,
                    Globals::esp_box_color, &Globals::esp_box_thickness);
                if (Globals::esp_box) Globals::esp_corner_box = false;

                feature("box fill", &Globals::esp_box_fill, Globals::esp_box_fill_color);

                ImGui::Spacing();
                section("skeleton");
                feature("skeleton", &Globals::esp_skeleton,
                    Globals::esp_skeleton_color, &Globals::esp_skeleton_thickness);

                end_col();
            }
            if (begin_col("en_r", cw, true)) {
                draw_preview("eprev",
                    Globals::esp_box, Globals::esp_corner_box,
                    Globals::esp_box_color, Globals::esp_box_thickness,
                    Globals::esp_box_fill, Globals::esp_box_fill_color,
                    Globals::esp_skeleton, Globals::esp_skeleton_color,
                    Globals::esp_skeleton_thickness,
                    Globals::esp_health);
                end_col();
            }

            ImGui::PopID();
        }

        // ── team sub-tab ──────────────────────────────────────────────────────
        else {
            ImGui::PushID("tm");

            if (begin_col("tm_l", cw, false)) {
                section("general");
                feature("team enabled", &Globals::esp_team_enabled);
                feature("health bar", &Globals::esp_team_health);

                ImGui::Spacing();
                section("box");
                feature("corner box", &Globals::esp_team_corner_box,
                    Globals::esp_team_box_color, &Globals::esp_box_team_thickness);
                if (Globals::esp_team_corner_box) Globals::esp_team_box = false;

                feature("box", &Globals::esp_team_box,
                    Globals::esp_team_box_color, &Globals::esp_box_team_thickness);
                if (Globals::esp_team_box) Globals::esp_team_corner_box = false;

                feature("box fill", &Globals::esp_team_box_fill,
                    Globals::esp_team_box_fill_color);

                ImGui::Spacing();
                section("skeleton");
                feature("skeleton", &Globals::esp_team_skeleton,
                    Globals::esp_team_skeleton_color, &Globals::esp_skeleton_thickness);

                end_col();
            }
            if (begin_col("tm_r", cw, true)) {
                draw_preview("tprev",
                    Globals::esp_team_box, Globals::esp_team_corner_box,
                    Globals::esp_team_box_color, Globals::esp_box_team_thickness,
                    Globals::esp_team_box_fill, Globals::esp_team_box_fill_color,
                    Globals::esp_team_skeleton, Globals::esp_team_skeleton_color,
                    Globals::esp_skeleton_thickness,
                    Globals::esp_team_health);
                end_col();
            }

            ImGui::PopID();
        }

        ImGui::PopID();
    }

    // ══════════════════════════════════════════════════════════════════════════
    //  TAB 3 — MISC
    // ══════════════════════════════════════════════════════════════════════════
    else if (g_tab == 3) {
        ImGui::PushID("misc");

        if (begin_col("misc_l", cw, false)) {
            section("movement");
            feature("bhop", &Globals::misc_bhop);
            feature("auto strafe", &Globals::misc_autostrafe);
            end_col();
        }
        if (begin_col("misc_r", cw, true)) {
            section("other");
            feature("radar", &Globals::misc_radar);
            feature("no flash", &Globals::misc_noflash);
            end_col();
        }

        ImGui::PopID();
    }

    // ══════════════════════════════════════════════════════════════════════════
    //  TAB 4 — CONFIGS
    // ══════════════════════════════════════════════════════════════════════════
    else if (g_tab == 4) {
        ImGui::PushID("cfg");

        if (begin_col("cfg_l", cw, false)) {
            section("configs");

            static char newName[64] = "";
            ImGui::PushItemWidth(cw * 0.46f - 68);
            ImGui::InputText("##cfgname", newName, sizeof(newName));
            ImGui::PopItemWidth();
            ImGui::SameLine(0, 6);
            if (ImGui::Button("create", { 60, 0 }) && strlen(newName) > 0) {
                Configs::Create(newName);
                memset(newName, 0, sizeof(newName));
            }

            ImGui::Spacing();

            static int sel = -1;
            auto cfgs = Configs::GetConfigs();

            if (!cfgs.empty()) {
                if (ImGui::BeginListBox("##cfglist", { -1, 100 })) {
                    for (int i = 0; i < (int)cfgs.size(); i++) {
                        bool selected = (sel == i);
                        if (ImGui::Selectable(cfgs[i].c_str(), selected)) sel = i;
                    }
                    ImGui::EndListBox();
                }
                if (sel >= 0 && sel < (int)cfgs.size()) {
                    ImGui::Spacing();
                    if (ImGui::Button("save", { 58, 0 })) Configs::Save(cfgs[sel]);
                    ImGui::SameLine(0, 4);
                    if (ImGui::Button("load", { 58, 0 })) Configs::Load(cfgs[sel]);
                    ImGui::SameLine(0, 4);
                    if (ImGui::Button("delete", { 58, 0 })) Configs::Delete(cfgs[sel]);
                }
            }
            end_col();
        }

        if (begin_col("cfg_r", cw, true)) {
            section("autoload");
            feature("enable autoload", &Globals::autoload_enabled);

            if (Globals::autoload_enabled) {
                auto cfgs = Configs::GetConfigs();
                if (!cfgs.empty()) {
                    ImGui::Spacing();
                    std::string preview = Configs::autoLoadConfig.empty()
                        ? "none" : Configs::autoLoadConfig;
                    ImGui::PushItemWidth(-1);
                    if (ImGui::BeginCombo("##al", preview.c_str())) {
                        if (ImGui::Selectable("none", Configs::autoLoadConfig.empty()))
                            Configs::autoLoadConfig = "";
                        for (const auto& cfg : cfgs) {
                            bool s = Configs::autoLoadConfig == cfg;
                            if (ImGui::Selectable(cfg.c_str(), s)) {
                                Configs::autoLoadConfig = cfg;
                                std::ofstream f(Configs::configDir + "autoload.txt");
                                f << Configs::autoLoadConfig;
                            }
                        }
                        ImGui::EndCombo();
                    }
                    ImGui::PopItemWidth();
                }
            }

            ImGui::Spacing();
            ImGui::Spacing();
            section("danger zone");
            ImGui::Spacing();
            if (ImGui::Button("reset all settings", { -1, 0 }))
                Configs::Reset();

            end_col();
        }

        ImGui::PopID();
    }

    ImGui::EndChild();
    ImGui::End();
}