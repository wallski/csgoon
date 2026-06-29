#include "NoSmoke.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"

// ── How NoSmoke works ────────────────────────────────────────────────────────
// CS2 smoke grenades are entities with class CSmokeGrenadeProjectile.
// Once detonated they set m_bDidSmokeEffect = true and store the world
// position of the smoke cloud in m_vSmokeDetonationPos.
//
// The visual volumetric smoke is driven by m_vSmokeColor (an RGB Vector3
// that controls the render colour of the volume).  Setting it to black
// {0,0,0} effectively makes the smoke invisible while the collision /
// line-of-sight occlusion is left intact on the server side (i.e. other
// players still think you're in smoke — this is purely a client visual).
//
// We walk the FULL entity list each frame (up to highestEntityIndex) rather
// than the player sub-list, because smoke grenades are world entities, not
// player controllers.
//
// Performance note: this loop is cheap — it's just pointer chasing, no
// expensive math.  highestEntityIndex caps it to however many live entities
// there actually are rather than always iterating 64 slots.
// ─────────────────────────────────────────────────────────────────────────────

// A tiny Vector3 struct so we can write three floats without pulling in the
// full Vector.h dependency chain here.
struct Vec3 { float x, y, z; };

void NoSmoke::Run()
{
    if (!Globals::misc_nosmoke)
        return;

    uintptr_t client = Globals::ClientBase;
    if (!client)
        return;

    // Level-1 pointer: the entity list object
    uintptr_t listPtr = *reinterpret_cast<uintptr_t*>(client + Offsets::client_dll::dwEntityList);
    if (!listPtr)
        return;

    // How many entity slots are actually populated this frame
    // This value lives directly on the GameEntitySystem object, not per-entity
    int highest = *reinterpret_cast<int*>(listPtr + Offsets::client_dll::dwGameEntitySystem_highestEntityIndex);
    if (highest <= 0 || highest > 32768)
        return;

    for (int i = 0; i < highest; ++i)
    {
        // ── Entity list indirection (same pattern as EntityManager) ───────
        // The list is a two-level array.
        //   Chunk index  = (i & 0x7FFF) >> 9        (which 512-slot chunk)
        //   Slot in chunk = i & 0x1FF                (slot within that chunk)
        //   Chunk pointer table starts at listPtr+16, spaced 8 bytes apart
        uintptr_t chunk = *reinterpret_cast<uintptr_t*>(listPtr + 8 * ((i & 0x7FFF) >> 9) + 16);
        if (!chunk)
            continue;

        uintptr_t entity = *reinterpret_cast<uintptr_t*>(chunk + 112 * (i & 0x1FF));
        if (!entity)
            continue;

        // Only process entities that have detonated as smokes
        bool didSmoke = *reinterpret_cast<bool*>(entity + Offsets::bools::m_bDidSmokeEffect);
        if (!didSmoke)
            continue;

        // Set smoke render colour to black → invisible volumetric
        // m_vSmokeColor is a Vector (3 floats, 12 bytes) on the grenade entity
        Vec3& smokeColor = *reinterpret_cast<Vec3*>(entity + Offsets::Vector::m_vSmokeColor);
        smokeColor.x = 0.f;
        smokeColor.y = 0.f;
        smokeColor.z = 0.f;
    }
}
