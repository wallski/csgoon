#pragma once
#include <string>
#include <vector>
#include <Windows.h>

namespace Configs {
    void Init(HMODULE hModule);
    void Create(const std::string& name);
    void Save(const std::string& name);
    void Load(const std::string& name);
    void Delete(const std::string& name);
    void Reset();
    void AutoLoad();
    std::vector<std::string> GetConfigs();

    inline std::string configDir = "";
    inline std::string autoLoadConfig = "";
}