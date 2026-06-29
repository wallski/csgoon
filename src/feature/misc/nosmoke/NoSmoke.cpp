#include "NoSmoke.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"

// ── How NoSmoke works ────────────────────────────────────────────────────────
// Walks every live entity and blacks out m_vSmokeColor on any detonated smoke
// grenade, making the volumetric cloud visually invisible.
//
// Every dereference uses SafeRead / SafeWrite / IsValidPtr so freed or
// reloading entity slots during round transitions never cause a crash.
// ─────────────────────────────────────────────────────────────────────────────

struct Vec3 { float x, y, z; };

void NoSmoke::Run()
{
    if (!Globals::misc_nosmoke)
        return;

    uintptr_t client = Globals::ClientBase;
    if (!Memory::IsValidPtr(client))
        return;

    // Level-1: entity list object pointer
    uintptr_t listPtr = 0;
    if (!Memory::SafeRead(client + Offsets::client_dll::dwEntityList, listPtr) || !listPtr)
        return;

    // How many entity slots are populated this frame
    int highest = 0;
    if (!Memory::SafeRead(listPtr + Offsets::client_dll::dwGameEntitySystem_highestEntityIndex, highest))
        return;
    if (highest <= 0 || highest > 32768)
        return;

    for (int i = 0; i < highest; ++i)
    {
        // Two-level entity list: chunk table → slot
        uintptr_t chunk = 0;
        if (!Memory::SafeRead(listPtr + 8 * ((i & 0x7FFF) >> 9) + 16, chunk) || !chunk)
            continue;

        uintptr_t entity = 0;
        if (!Memory::SafeRead(chunk + 112 * (i & 0x1FF), entity) || !entity)
            continue;

        if (!Memory::IsValidPtr(entity))
            continue;

        // Only process entities that have finished detonating as a smoke
        bool didSmoke = false;
        if (!Memory::SafeRead(entity + Offsets::bools::m_bDidSmokeEffect, didSmoke) || !didSmoke)
            continue;

        // Black out the render colour — safe write, no crash if entity freed mid-frame
        const Vec3 black{ 0.f, 0.f, 0.f };
        Memory::SafeWrite(entity + Offsets::Vector::m_vSmokeColor, black);
    }
}
