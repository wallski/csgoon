#include "Misc.h"
#include "../combat/Combat.h"
#include "bhop/Bhop.h"
#include "noflash/NoFlash.h"
#include "nosmoke/NoSmoke.h"
#include "../../sdk/entity/EntityManager.h"
#include "../../sdk/utils/Globals.h"
#include "../../sdk/memory/Offsets.h"

void Misc::Render()
{
	// Placeholder for miscellaneous rendering features
}

void Misc::Run() {
	Combat::Run();
	BunnyHop::Run();
	NoFlash::Run();
	NoSmoke::Run();

    // Thirdperson & Radar
    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (local && local->IsAlive()) {
        uintptr_t pObserverServices = local->m_pObserverServices();
        if (pObserverServices) {
            uint8_t currentMode = 0;
            Memory::SafeRead(pObserverServices + Offsets::uint8::m_iObserverMode, currentMode);
            if (Globals::misc_thirdperson) {
                if (currentMode != 1) { // 1 = Chase / Thirdperson
                    Memory::SafeWrite(pObserverServices + Offsets::uint8::m_iObserverMode, (uint8_t)1);
                }
            } else {
                if (currentMode == 1) {
                    Memory::SafeWrite(pObserverServices + Offsets::uint8::m_iObserverMode, (uint8_t)0); // 0 = None / Firstperson
                }
            }
        }
    }

    if (Globals::misc_radar) {
        for (const auto& ent : EntityManager::Get().GetEntities()) {
            if (!ent.pawn || !ent.isEnemy)
                continue;

            uintptr_t entitySpottedState = reinterpret_cast<uintptr_t>(ent.pawn) + 0x1CC8; // m_entitySpottedState
            Memory::SafeWrite(entitySpottedState + 0x8, true); // m_bSpotted
        }
    }
}