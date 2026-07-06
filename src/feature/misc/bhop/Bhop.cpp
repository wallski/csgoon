#include "Bhop.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"
#include <Windows.h>

void BunnyHop::Run() {
    if (!Globals::misc_bhop)
        return;

    // Only run when space is held
    if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
        return;

    if (!Globals::ClientBase)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local)
        return;

    // Read ground flag (m_fFlags bit 0 = FL_ONGROUND)
    uint32_t flags = 0;
    Memory::SafeRead(reinterpret_cast<uintptr_t>(local) + Offsets::uint32::m_fFlags, flags);
    bool onGround = (flags & (1 << 0)) != 0;

    // buttons::jump is a CInButton struct in client.dll.
    // Writing 65  → button pressed  (jump ON)
    // Writing 256 → button released (jump OFF)
    // Toggle rapidly: press on the exact frame we land, release in the air.
    uintptr_t jumpAddr = Globals::ClientBase + Offsets::buttons::jump;

    if (onGround)
        Memory::SafeWrite<int>(jumpAddr, 65);
    else
        Memory::SafeWrite<int>(jumpAddr, 256);
}