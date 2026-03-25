#pragma once
#include <cstdint>
#include <Windows.h>


namespace Globals
{
    // ESP
     //inline bool esp_name = true;
    inline bool esp_enabled = false;
    inline bool esp_box = false;
    inline bool esp_corner_box = false;
    inline float esp_box_color[4] = { 1.f, 0.f, 0.f, 1.f };
    inline float esp_box_thickness = 1.5f;
    inline bool esp_skeleton = false;
    inline float esp_skeleton_color[4] = { 1.f, 1.f, 1.f, 0.9f };
    inline float esp_skeleton_thickness = 1.8f;
    inline float esp_name_color[4] = { 1.f, 1.f, 1.f, 1.f };
    inline bool esp_health = true;
    inline bool esp_enemy_only = false;
    inline bool esp_box_fill = false;
    inline float esp_box_fill_color[4] = { 1.f, 0.f, 0.f, 0.2f };   

    // Aimbot
    inline bool aim_enabled = false;
    inline bool aim_silent = false;
    inline bool aim_autoshoot = false;
    inline float aim_fov = 5.0f;
    inline float aim_smooth = 5.0f;
    inline bool aim_head = true;
    inline bool aim_body = false;

    // Misc
    inline bool misc_bhop = false;
    inline bool misc_autostrafe = false;
    inline bool misc_radar = false;
    inline bool misc_noflash = false;
    inline bool misc_fovchanger = false;
    inline float misc_fov = 90.0f;

    // Engine
    inline float ViewMatrix[16] = { 0.f };
    inline int ScreenWidth = 0;
    inline int ScreenHeight = 0;

    // ragebot
    inline bool rage_enabled = false;
    inline bool rage_silent = false;
    inline bool rage_autoshoot = false;
    inline bool rage_multipoint = false;
    inline float rage_hitchance = 80.0f;
    inline float rage_mindmg = 20.0f;

    // legitbot
    inline bool legit_enabled = false;
    inline bool legit_lock = false;
    inline bool legit_rcs = false;
    inline float legit_smooth = 5.0f;
    inline float legit_fov = 5.0f;

    // triggerbot
    inline bool trigger_enabled = false;
    inline int trigger_delay = 0;
    inline bool trigger_keybind_toggle = false;
    inline int trigger_key = 0;
    inline bool trigger_key_active = false;
    inline bool trigger_keybind_enabled = false;

    // configs
    inline bool autoload_enabled = false;
}