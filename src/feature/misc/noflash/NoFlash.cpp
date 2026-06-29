#include "NoFlash.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"

// ── How NoFlash works ────────────────────────────────────────────────────────
// CS2 stores floats on C_CSPlayerPawn that drive the flash screen overlay:
//   m_flFlashMaxAlpha     — peak opacity the flash can reach (0-255)
//   m_flFlashOverlayAlpha — current rendered alpha this frame
//   m_flFlashBangTime     — expiry timestamp; zero = engine treats flash as done
//
// SafeWrite is used for every write so if the pawn pointer becomes stale
// between frames (round transition, map load) the write simply fails silently
// instead of crashing.
// ─────────────────────────────────────────────────────────────────────────────

void NoFlash::Run()
{
    if (!Globals::misc_noflash)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local)
        return;

    uintptr_t base = reinterpret_cast<uintptr_t>(local);
    if (!Memory::IsValidPtr(base))
        return;

    // Use SafeWrite — if the pawn was freed this frame the write is a no-op
    Memory::SafeWrite(base + Offsets::float32::m_flFlashMaxAlpha,     0.f);
    Memory::SafeWrite(base + Offsets::float32::m_flFlashOverlayAlpha, 0.f);
    Memory::SafeWrite(base + Offsets::float32::m_flFlashBangTime,     0.f);
}
