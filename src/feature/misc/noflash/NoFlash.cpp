#include "NoFlash.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"


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

    Memory::SafeWrite(base + Offsets::float32::m_flFlashMaxAlpha,     0.f);
    Memory::SafeWrite(base + Offsets::float32::m_flFlashOverlayAlpha, 0.f);
    Memory::SafeWrite(base + Offsets::float32::m_flFlashBangTime,     0.f);
}
