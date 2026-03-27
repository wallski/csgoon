#include "Configs.h"
#include "../../../sdk/utils/Globals.h"
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <Windows.h>

namespace fs = std::filesystem;

void Configs::Create(const std::string& name) {
    std::ofstream file(configDir + name + ".cfg");
    file.close();
}

void Configs::Save(const std::string& name) {
    std::ofstream file(configDir + name + ".cfg");
    if (!file.is_open())
        return;

    // esp
    //file << "esp_name=" << Globals::esp_name << "\n";
    file << "esp_corner_box=" << Globals::esp_corner_box << "\n";
    file << "esp_enabled=" << Globals::esp_enabled << "\n";
    file << "esp_box=" << Globals::esp_box << "\n";
    file << "esp_box_color_r=" << Globals::esp_box_color[0] << "\n";
    file << "esp_box_color_g=" << Globals::esp_box_color[1] << "\n";
    file << "esp_box_color_b=" << Globals::esp_box_color[2] << "\n";
    file << "esp_box_color_a=" << Globals::esp_box_color[3] << "\n";
    file << "esp_box_thickness=" << Globals::esp_box_thickness << "\n";
    file << "esp_skeleton=" << Globals::esp_skeleton << "\n";
    file << "esp_skeleton_color_r=" << Globals::esp_skeleton_color[0] << "\n";
    file << "esp_skeleton_color_g=" << Globals::esp_skeleton_color[1] << "\n";
    file << "esp_skeleton_color_b=" << Globals::esp_skeleton_color[2] << "\n";
    file << "esp_skeleton_color_a=" << Globals::esp_skeleton_color[3] << "\n";
    file << "esp_skeleton_thickness=" << Globals::esp_skeleton_thickness << "\n";
    file << "esp_name_color_r=" << Globals::esp_name_color[0] << "\n";
    file << "esp_name_color_g=" << Globals::esp_name_color[1] << "\n";
    file << "esp_name_color_b=" << Globals::esp_name_color[2] << "\n";
    file << "esp_name_color_a=" << Globals::esp_name_color[3] << "\n";
    file << "esp_health=" << Globals::esp_health << "\n";
    file << "esp_box_fill=" << Globals::esp_box_fill << "\n";
    file << "esp_box_fill_color_r=" << Globals::esp_box_fill_color[0] << "\n";
    file << "esp_box_fill_color_g=" << Globals::esp_box_fill_color[1] << "\n";
    file << "esp_box_fill_color_b=" << Globals::esp_box_fill_color[2] << "\n";
    file << "esp_box_fill_color_a=" << Globals::esp_box_fill_color[3] << "\n";
    file << "esp_autoload_enabled=" << Globals::autoload_enabled << "\n";
    file << "esp_team_box_color_r=" << Globals::esp_team_box_color[0] << "\n";
    file << "esp_team_box_color_g=" << Globals::esp_team_box_color[1] << "\n";
    file << "esp_team_box_color_b=" << Globals::esp_team_box_color[2] << "\n";
    file << "esp_team_box_color_a=" << Globals::esp_team_box_color[3] << "\n";
    file << "esp_team_skeleton_color_r=" << Globals::esp_team_skeleton_color[0] << "\n";
    file << "esp_team_skeleton_color_g=" << Globals::esp_team_skeleton_color[1] << "\n";
    file << "esp_team_skeleton_color_b=" << Globals::esp_team_skeleton_color[2] << "\n";
    file << "esp_team_skeleton_color_a=" << Globals::esp_team_skeleton_color[3] << "\n";
    file << "esp_team_box_fill_color_r=" << Globals::esp_team_box_fill_color[0] << "\n";
    file << "esp_team_box_fill_color_g=" << Globals::esp_team_box_fill_color[1] << "\n";
    file << "esp_team_box_fill_color_b=" << Globals::esp_team_box_fill_color[2] << "\n";
    file << "esp_team_box_fill_color_a=" << Globals::esp_team_box_fill_color[3] << "\n";
    file << "esp_team_box=" << Globals::esp_team_box << "\n";
    file << "esp_team_corner_box=" << Globals::esp_team_corner_box << "\n";
    file << "esp_team_box_fill=" << Globals::esp_team_box_fill << "\n";
    file << "esp_team_skeleton=" << Globals::esp_team_skeleton << "\n";
    file << "esp_box_team_thickness=" << Globals::esp_box_team_thickness << "\n";
    file << "esp_team_ct_color_r=" << Globals::esp_team_ct_color[0] << "\n";
    file << "esp_team_ct_color_g=" << Globals::esp_team_ct_color[1] << "\n";
    file << "esp_team_ct_color_b=" << Globals::esp_team_ct_color[2] << "\n";
    file << "esp_team_ct_color_a=" << Globals::esp_team_ct_color[3] << "\n";
    file << "esp_team_t_color_r=" << Globals::esp_team_t_color[0] << "\n";
    file << "esp_team_t_color_g=" << Globals::esp_team_t_color[1] << "\n";
    file << "esp_team_t_color_b=" << Globals::esp_team_t_color[2] << "\n";
    file << "esp_team_t_color_a=" << Globals::esp_team_t_color[3] << "\n";
    file << "esp_team_health=" << Globals::esp_team_health << "\n";
    file << "esp_team_enabled=" << Globals::esp_team_enabled << "\n";
    file << "esp_enemy_enabled=" << Globals::esp_enemy_enabled << "\n";


    // aimbot
    file << "aim_enabled=" << Globals::aim_enabled << "\n";
    file << "aim_silent=" << Globals::aim_silent << "\n";
    file << "aim_autoshoot=" << Globals::aim_autoshoot << "\n";
    file << "aim_fov=" << Globals::aim_fov << "\n";
    file << "aim_smooth=" << Globals::aim_smooth << "\n";
    file << "aim_head=" << Globals::aim_head << "\n";
    file << "aim_body=" << Globals::aim_body << "\n";
    file << "rage_fov=" << Globals::rage_fov << "\n";
    file << "aim_team_check=" << Globals::aim_team_check << "\n";
    file << "aim_head=" << Globals::aim_head << "\n";
    file << "aim_body=" << Globals::aim_body << "\n";

    // misc
    file << "misc_bhop=" << Globals::misc_bhop << "\n";
    file << "misc_autostrafe=" << Globals::misc_autostrafe << "\n";
    file << "misc_radar=" << Globals::misc_radar << "\n";
    file << "misc_noflash=" << Globals::misc_noflash << "\n";
    file << "misc_fovchanger=" << Globals::misc_fovchanger << "\n";
    file << "misc_fov=" << Globals::misc_fov << "\n";

    // ragebot
    file << "rage_enabled=" << Globals::rage_enabled << "\n";
    file << "rage_silent=" << Globals::rage_silent << "\n";
    file << "rage_autoshoot=" << Globals::rage_autoshoot << "\n";
    file << "rage_multipoint=" << Globals::rage_multipoint << "\n";
    file << "rage_hitchance=" << Globals::rage_hitchance << "\n";
    file << "rage_mindmg=" << Globals::rage_mindmg << "\n";
    file << "rage_fov=" << Globals::rage_fov << "\n";
    file << "rage_key=" << Globals::rage_key << "\n";


    // legitbot
    file << "legit_enabled=" << Globals::legit_enabled << "\n";
    file << "legit_lock=" << Globals::legit_lock << "\n";
    file << "legit_rcs=" << Globals::legit_rcs << "\n";
    file << "legit_smooth=" << Globals::legit_smooth << "\n";
    file << "legit_fov=" << Globals::legit_fov << "\n";

    // triggerbot
    file << "trigger_enabled=" << Globals::trigger_enabled << "\n";
    file << "trigger_delay=" << Globals::trigger_delay << "\n";
    file << "trigger_keybind_toggle=" << Globals::trigger_keybind_toggle << "\n";
    file << "trigger_key=" << Globals::trigger_key << "\n";
    file << "trigger_keybind_enabled=" << Globals::trigger_keybind_enabled << "\n";

    // smoke
    file << "trigger_smoke_check=" << Globals::trigger_smoke_check << "\n";

    file.close();
}

void Configs::Load(const std::string& name) {
    std::ifstream file(configDir + name + ".cfg");
    if (!file.is_open())
        return;

    std::string line;
    while (std::getline(file, line)) {
        auto sep = line.find('=');
        if (sep == std::string::npos)
            continue;

        std::string key = line.substr(0, sep);
        std::string val = line.substr(sep + 1);

        try {
            // esp
            //else if (key == "esp_name")              Globals::esp_name = val == "1";

            if (key == "esp_enabled")          Globals::esp_enabled = val == "1";
            else if (key == "esp_corner_box") Globals::esp_corner_box = val == "1";
            else if (key == "esp_box")               Globals::esp_box = val == "1";
            else if (key == "esp_box_color_r")       Globals::esp_box_color[0] = std::stof(val);
            else if (key == "esp_box_color_g")       Globals::esp_box_color[1] = std::stof(val);
            else if (key == "esp_box_color_b")       Globals::esp_box_color[2] = std::stof(val);
            else if (key == "esp_box_color_a")       Globals::esp_box_color[3] = std::stof(val);
            else if (key == "esp_box_thickness")     Globals::esp_box_thickness = std::stof(val);
            else if (key == "esp_team_box")        Globals::esp_team_box = val == "1";
            else if (key == "esp_team_corner_box") Globals::esp_team_corner_box = val == "1";
            else if (key == "esp_team_box_fill")   Globals::esp_team_box_fill = val == "1";
            else if (key == "esp_team_skeleton")   Globals::esp_team_skeleton = val == "1";
            else if (key == "esp_skeleton")          Globals::esp_skeleton = val == "1";
            else if (key == "esp_skeleton_color_r")  Globals::esp_skeleton_color[0] = std::stof(val);
            else if (key == "esp_skeleton_color_g")  Globals::esp_skeleton_color[1] = std::stof(val);
            else if (key == "esp_skeleton_color_b")  Globals::esp_skeleton_color[2] = std::stof(val);
            else if (key == "esp_skeleton_color_a")  Globals::esp_skeleton_color[3] = std::stof(val);
            else if (key == "esp_skeleton_thickness")Globals::esp_skeleton_thickness = std::stof(val);
            else if (key == "esp_name_color_r")      Globals::esp_name_color[0] = std::stof(val);
            else if (key == "esp_name_color_g")      Globals::esp_name_color[1] = std::stof(val);
            else if (key == "esp_name_color_b")      Globals::esp_name_color[2] = std::stof(val);
            else if (key == "esp_name_color_a")      Globals::esp_name_color[3] = std::stof(val);
            else if (key == "esp_health")            Globals::esp_health = val == "1";
            else if (key == "esp_box_fill")          Globals::esp_box_fill = val == "1";
            else if (key == "esp_autoload_enabled")  Globals::autoload_enabled = val == "1";
            else if (key == "esp_team_box_color_r")      Globals::esp_team_box_color[0] = std::stof(val);
            else if (key == "esp_team_box_color_g")      Globals::esp_team_box_color[1] = std::stof(val);
            else if (key == "esp_team_box_color_b")      Globals::esp_team_box_color[2] = std::stof(val);
            else if (key == "esp_team_box_color_a")      Globals::esp_team_box_color[3] = std::stof(val);
            else if (key == "esp_team_skeleton_color_r") Globals::esp_team_skeleton_color[0] = std::stof(val);
            else if (key == "esp_team_skeleton_color_g") Globals::esp_team_skeleton_color[1] = std::stof(val);
            else if (key == "esp_team_skeleton_color_b") Globals::esp_team_skeleton_color[2] = std::stof(val);
            else if (key == "esp_team_skeleton_color_a") Globals::esp_team_skeleton_color[3] = std::stof(val);
            else if (key == "esp_team_box_fill_color_r") Globals::esp_team_box_fill_color[0] = std::stof(val);
            else if (key == "esp_team_box_fill_color_g") Globals::esp_team_box_fill_color[1] = std::stof(val);
            else if (key == "esp_team_box_fill_color_b") Globals::esp_team_box_fill_color[2] = std::stof(val);
            else if (key == "esp_team_box_fill_color_a") Globals::esp_team_box_fill_color[3] = std::stof(val);
            else if (key == "esp_box_fill_color_r")    Globals::esp_box_fill_color[0] = std::stof(val);
            else if (key == "esp_box_fill_color_g")    Globals::esp_box_fill_color[1] = std::stof(val);
            else if (key == "esp_box_fill_color_b")    Globals::esp_box_fill_color[2] = std::stof(val);
            else if (key == "esp_box_fill_color_a")    Globals::esp_box_fill_color[3] = std::stof(val);
            else if (key == "esp_box_team_thickness")  Globals::esp_box_team_thickness = std::stof(val);
            else if (key == "esp_team_ct_color_r")     Globals::esp_team_ct_color[0] = std::stof(val);
            else if (key == "esp_team_ct_color_g")     Globals::esp_team_ct_color[1] = std::stof(val);
            else if (key == "esp_team_ct_color_b")     Globals::esp_team_ct_color[2] = std::stof(val);
            else if (key == "esp_team_ct_color_a")     Globals::esp_team_ct_color[3] = std::stof(val);
            else if (key == "esp_team_t_color_r")      Globals::esp_team_t_color[0] = std::stof(val);
            else if (key == "esp_team_t_color_g")      Globals::esp_team_t_color[1] = std::stof(val);
            else if (key == "esp_team_t_color_b")      Globals::esp_team_t_color[2] = std::stof(val);
            else if (key == "esp_team_t_color_a")      Globals::esp_team_t_color[3] = std::stof(val);
            else if (key == "esp_team_health")         Globals::esp_team_health = val == "1";
            else if (key == "esp_team_enabled")         Globals::esp_team_enabled = val == "1";
            else if (key == "esp_enemy_enabled")    Globals::esp_enemy_enabled = val == "1";

            // aimbot
            else if (key == "aim_enabled")           Globals::aim_enabled = val == "1";
            else if (key == "aim_silent")            Globals::aim_silent = val == "1";
            else if (key == "aim_autoshoot")         Globals::aim_autoshoot = val == "1";
            else if (key == "aim_fov")               Globals::aim_fov = std::stof(val);
            else if (key == "aim_smooth")            Globals::aim_smooth = std::stof(val);
            else if (key == "aim_head")              Globals::aim_head = val == "1";
            else if (key == "aim_body")              Globals::aim_body = val == "1";
            else if (key == "rage_fov")        Globals::rage_fov = std::stof(val);
            else if (key == "aim_team_check")  Globals::aim_team_check = val == "1";
            else if (key == "aim_head")        Globals::aim_head = val == "1";
            else if (key == "aim_body")        Globals::aim_body = val == "1";

            // misc
            else if (key == "misc_bhop")             Globals::misc_bhop = val == "1";
            else if (key == "misc_autostrafe")       Globals::misc_autostrafe = val == "1";
            else if (key == "misc_radar")            Globals::misc_radar = val == "1";
            else if (key == "misc_noflash")          Globals::misc_noflash = val == "1";
            else if (key == "misc_fovchanger")       Globals::misc_fovchanger = val == "1";
            else if (key == "misc_fov")              Globals::misc_fov = std::stof(val);

            // ragebot
            else if (key == "rage_enabled")          Globals::rage_enabled = val == "1";
            else if (key == "rage_silent")           Globals::rage_silent = val == "1";
            else if (key == "rage_autoshoot")        Globals::rage_autoshoot = val == "1";
            else if (key == "rage_multipoint")       Globals::rage_multipoint = val == "1";
            else if (key == "rage_hitchance")        Globals::rage_hitchance = std::stof(val);
            else if (key == "rage_mindmg")           Globals::rage_mindmg = std::stof(val);
            else if (key == "rage_key")              Globals::rage_key = std::stoi(val);
            else if (key == "rage_fov")             Globals::rage_fov = std::stof(val);

            // legitbot
            else if (key == "legit_enabled")         Globals::legit_enabled = val == "1";
            else if (key == "legit_lock")            Globals::legit_lock = val == "1";
            else if (key == "legit_rcs")             Globals::legit_rcs = val == "1";
            else if (key == "legit_smooth")          Globals::legit_smooth = std::stof(val);
            else if (key == "legit_fov")             Globals::legit_fov = std::stof(val);

            // triggerbot
            else if (key == "trigger_enabled")       Globals::trigger_enabled = val == "1";
            else if (key == "trigger_delay")         Globals::trigger_delay = std::stoi(val);
            else if (key == "trigger_keybind_toggle")Globals::trigger_keybind_toggle = val == "1";
            else if (key == "trigger_key")           Globals::trigger_key = std::stoi(val);
            else if (key == "trigger_keybind_enabled")Globals::trigger_keybind_enabled = val == "1";

            // smoke
            else if (key == "trigger_smoke_check") Globals::trigger_smoke_check = val == "1";
        }
        catch (...) {

        }
    }

    file.close();
}

void Configs::Delete(const std::string& name) {
    fs::remove(configDir + name + ".cfg");
}

void Configs::Reset() {
    // ESP
    //Globals::esp_name = false;
    Globals::rage_fov = 5.0f;
    Globals::aim_team_check = true;
    Globals::aim_head = true;
    Globals::aim_body = false;
    Globals::esp_enemy_enabled = false;
    Globals::esp_team_health = false;
    Globals::esp_team_enabled = false;
    Globals::esp_team_box_color[0] = 0.f;
    Globals::esp_team_box = false;
    Globals::esp_team_corner_box = false;
    Globals::esp_team_box_fill = false;
    Globals::esp_team_skeleton = false;
    Globals::esp_team_box_color[1] = 0.5f;
    Globals::esp_team_box_color[2] = 1.f;
    Globals::esp_team_box_color[3] = 1.f;
    Globals::esp_team_skeleton_color[0] = 0.f;
    Globals::esp_team_skeleton_color[1] = 0.5f;
    Globals::esp_team_skeleton_color[2] = 1.f;
    Globals::esp_team_skeleton_color[3] = 0.9f;
    Globals::esp_team_box_fill_color[0] = 0.f;
    Globals::esp_team_box_fill_color[1] = 0.5f;
    Globals::esp_team_box_fill_color[2] = 1.f;
    Globals::esp_team_box_fill_color[3] = 0.2f;
    Globals::esp_box_team_thickness = 1.5f;
    Globals::esp_team_ct_color[0] = 0.31f; Globals::esp_team_ct_color[1] = 0.55f;
    Globals::esp_team_ct_color[2] = 1.f;   Globals::esp_team_ct_color[3] = 1.f;
    Globals::esp_team_t_color[0] = 1.f;   Globals::esp_team_t_color[1] = 0.65f;
    Globals::esp_team_t_color[2] = 0.20f; Globals::esp_team_t_color[3] = 1.f;

    Globals::esp_enabled = false;
    Globals::esp_corner_box = false;
    Globals::esp_box = false;
    Globals::esp_box_color[0] = 1.f;
    Globals::esp_box_color[1] = 0.f;
    Globals::esp_box_color[2] = 0.f;
    Globals::esp_box_color[3] = 1.f;
    Globals::esp_box_thickness = 1.5f;
    Globals::esp_skeleton = false;
    Globals::esp_skeleton_color[0] = 1.f;
    Globals::esp_skeleton_color[1] = 1.f;
    Globals::esp_skeleton_color[2] = 1.f;
    Globals::esp_skeleton_color[3] = 0.9f;
    Globals::esp_skeleton_thickness = 1.8f;
    Globals::esp_name_color[0] = 1.f;
    Globals::esp_name_color[1] = 1.f;
    Globals::esp_name_color[2] = 1.f;
    Globals::esp_name_color[3] = 1.f;
    Globals::esp_health = false;
    Globals::esp_box_fill = false;
    Globals::esp_box_fill = false;
    Globals::esp_box_fill_color[0] = 1.f;
    Globals::esp_box_fill_color[1] = 0.f;
    Globals::esp_box_fill_color[2] = 0.f;
    Globals::esp_box_fill_color[3] = 0.2f;
    Globals::autoload_enabled = false;

    // Aimbot
    Globals::aim_enabled = false;
    Globals::aim_silent = false;
    Globals::aim_autoshoot = false;
    Globals::aim_fov = 5.0f;
    Globals::aim_smooth = 5.0f;
    Globals::aim_head = true;
    Globals::aim_body = false;

    // Misc
    Globals::misc_bhop = false;
    Globals::misc_autostrafe = false;
    Globals::misc_radar = false;
    Globals::misc_noflash = false;
    Globals::misc_fovchanger = false;
    Globals::misc_fov = 90.0f;

    // Ragebot
    Globals::rage_enabled = false;
    Globals::rage_silent = false;
    Globals::rage_autoshoot = false;
    Globals::rage_multipoint = false;
    Globals::rage_hitchance = 80.0f;
    Globals::rage_mindmg = 20.0f;
    Globals::rage_fov = 5.0f;
    Globals::rage_key = 0;

    // Legitbot
    Globals::legit_enabled = false;
    Globals::legit_lock = false;
    Globals::legit_rcs = false;
    Globals::legit_smooth = 5.0f;
    Globals::legit_fov = 5.0f;

    // Triggerbot
    Globals::trigger_enabled = false;
    Globals::trigger_delay = 0;
    Globals::trigger_keybind_toggle = false;
    Globals::trigger_key = 0;
    Globals::trigger_keybind_enabled = false;

    // Smoke
    Globals::trigger_smoke_check = false;
}

void Configs::AutoLoad() {
    if (autoLoadConfig.empty() || autoLoadConfig == "none")
        return;

    Load(autoLoadConfig);
}

std::vector<std::string> Configs::GetConfigs() {
    std::vector<std::string> configs;

    if (configDir.empty() || !fs::exists(configDir))
        return configs;

    for (const auto& entry : fs::directory_iterator(configDir)) {
        if (entry.path().extension() == ".cfg") {
            configs.push_back(entry.path().stem().string());
        }
    }

    return configs;
}

void Configs::Init(HMODULE hModule) {
    char path[MAX_PATH];
    GetModuleFileNameA(hModule, path, MAX_PATH);

    std::string fullPath(path);
    configDir = fullPath.substr(0, fullPath.find_last_of("\\/")) + "\\configs\\";

    fs::create_directories(configDir);

    // load autoload setting
    std::ifstream f(configDir + "autoload.txt");
    if (f.is_open()) {
        std::getline(f, autoLoadConfig);
        f.close();
    }

    AutoLoad();
}