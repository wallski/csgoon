#include "NoFlash.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"

// ── How NoFlash works ────────────────────────────────────────────────────────
// CS2 stores two key floats on C_CSPlayerPawn that drive the flash screen
// overlay:
//   m_flFlashMaxAlpha    — peak opacity the flash reaches (0–255 range)
//   m_flFlashOverlayAlpha — the current rendered alpha right now
//
// By zeroing both every frame we prevent any visible white-out from ever
// appearing.  We also zero m_flFlashBangTime so the flash is treated as
// expired, which stops the engine from replaying audio DSP filters tied to it.
//
// These are all on the LOCAL PAWN, not on the grenade entity, so we only need
// the local pawn pointer — no entity list walk required.
// ─────────────────────────────────────────────────────────────────────────────

void NoFlash::Run()
{
    if (!Globals::misc_noflash)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local || !local->IsAlive())
        return;

    uintptr_t base = reinterpret_cast<uintptr_t>(local);

    // Peak alpha — if left non-zero the engine will keep trying to ramp up to it
    float& maxAlpha     = *reinterpret_cast<float*>(base + Offsets::float32::m_flFlashMaxAlpha);
    // Current rendered overlay alpha
    float& overlayAlpha = *reinterpret_cast<float*>(base + Offsets::float32::m_flFlashOverlayAlpha);
    // Expiry timestamp — zero it so the engine considers the flash done
    float& bangTime     = *reinterpret_cast<float*>(base + Offsets::float32::m_flFlashBangTime);

    maxAlpha     = 0.f;
    overlayAlpha = 0.f;
    bangTime     = 0.f;
}
