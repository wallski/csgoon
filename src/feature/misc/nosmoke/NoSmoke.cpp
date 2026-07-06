#include "NoSmoke.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"



struct Vec3 { float x, y, z; };

void NoSmoke::Run()
{
    if (!Globals::misc_nosmoke)
        return;

    uintptr_t client = Globals::ClientBase;
    if (!Memory::IsValidPtr(client))
        return;


    uintptr_t listPtr = 0;
    if (!Memory::SafeRead(client + Offsets::client_dll::dwEntityList, listPtr) || !listPtr)
        return;


    int highest = 0;
    if (!Memory::SafeRead(listPtr + Offsets::client_dll::dwGameEntitySystem_highestEntityIndex, highest))
        return;
    if (highest <= 0 || highest > 32768)
        return;

    for (int i = 0; i < highest; ++i)
    {

        uintptr_t chunk = 0;
        if (!Memory::SafeRead(listPtr + 8 * ((i & 0x7FFF) >> 9) + 16, chunk) || !chunk)
            continue;

        uintptr_t entity = 0;
        if (!Memory::SafeRead(chunk + 112 * (i & 0x1FF), entity) || !entity)
            continue;

        if (!Memory::IsValidPtr(entity))
            continue;

        bool didSmoke = false;
        if (!Memory::SafeRead(entity + Offsets::bools::m_bDidSmokeEffect, didSmoke) || !didSmoke)
            continue;


        const Vec3 black{ 0.f, 0.f, 0.f };
        Memory::SafeWrite(entity + Offsets::Vector::m_vSmokeColor, black);
    }
}
