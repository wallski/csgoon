#pragma once
#include <cstdint>
#include <Windows.h>

namespace Globals
{
    // ── ESP MASTER SWITCHES ──────────────────────────────────────────────────
    inline bool esp_enabled = true;
    inline bool esp_enemy_enabled = true;
    inline bool esp_team_enabled = false;

    // ── ENEMY ESP ─────────────────────────────────────────────────────────────
    inline bool  esp_box = true;
    inline bool  esp_corner_box = false;
    inline bool  esp_box_fill = false;
    inline bool  esp_skeleton = true;
    inline bool  esp_health = true;
    inline bool  esp_name = true;

    inline float esp_box_color[4] = { 1.f, 0.f, 0.f, 1.f };
    inline float esp_box_fill_color[4] = { 1.f, 0.f, 0.f, 0.2f };
    inline float esp_skeleton_color[4] = { 1.f, 1.f, 1.f, 0.9f };
    inline float esp_name_color[4] = { 1.f, 1.f, 1.f, 1.f };
    inline float esp_box_thickness = 1.5f;
    inline float esp_skeleton_thickness = 1.8f;

    // ── TEAM ESP ──────────────────────────────────────────────────────────────
    inline bool  esp_team_box = true;
    inline bool  esp_team_corner_box = false;
    inline bool  esp_team_box_fill = false;
    inline bool  esp_team_skeleton = false;
    inline bool  esp_team_health = true;
    inline bool  esp_team_name = true;

    inline float esp_team_box_color[4] = { 0.f, 0.5f, 1.f, 1.f };
    inline float esp_team_box_fill_color[4] = { 0.f, 0.5f, 1.f, 0.2f };
    inline float esp_team_skeleton_color[4] = { 0.f, 0.5f, 1.f, 0.9f };
    inline float esp_box_team_thickness = 1.5f;

    // ── TEAM COLORS (CT/T specific) ──────────────────────────────────────────
    inline float esp_team_ct_color[4] = { 0.31f, 0.55f, 1.f,  1.f };
    inline float esp_team_t_color[4] = { 1.f,   0.65f, 0.20f, 1.f };

    // ── Aimbot ────────────────────────────────────────────────────────────────
    inline bool  aim_enabled = false;
    inline bool  aim_silent = false;
    inline bool  aim_autoshoot = false;
    inline float aim_fov = 5.0f;
    inline float aim_smooth = 5.0f;
    inline bool  aim_head = true;
    inline bool  aim_body = false;
    inline bool  aim_team_check = true;

    // ── Misc ──────────────────────────────────────────────────────────────────
    inline bool  misc_bhop = false;
    inline bool  misc_autostrafe = false;
    inline bool  misc_radar = false;
    inline bool  misc_noflash = false;
    inline bool  misc_fovchanger = false;
    inline float misc_fov = 90.0f;
    inline bool  g_Unloading = false;

    // ── Engine ────────────────────────────────────────────────────────────────
    inline float ViewMatrix[16] = { 0.f };
    inline int   ScreenWidth = 0;
    inline int   ScreenHeight = 0;

    // ── Ragebot ───────────────────────────────────────────────────────────────
    inline bool  rage_enabled = false;
    inline bool  rage_silent = false;
    inline bool  rage_autoshoot = false;
    inline bool  rage_multipoint = false;
    inline float rage_hitchance = 80.0f;
    inline float rage_mindmg = 20.0f;
    inline float rage_fov = 30.0f;

    // ── Legitbot ──────────────────────────────────────────────────────────────
    inline bool  legit_enabled = false;
    inline bool  legit_lock = false;
    inline bool  legit_rcs = false;
    inline float legit_smooth = 5.0f;
    inline float legit_fov = 5.0f;

    // ── Triggerbot ────────────────────────────────────────────────────────────
    inline bool  trigger_enabled = false;
    inline int   trigger_delay = 0;
    inline bool  trigger_keybind_toggle = false;
    inline int   trigger_key = 0;
    inline bool  trigger_key_active = false;
    inline bool  trigger_keybind_enabled = false;
    inline bool  trigger_smoke_check = false;

    // ── Configs ───────────────────────────────────────────────────────────────
    inline bool autoload_enabled = false;
}