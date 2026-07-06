#include "Bhop.h"
#include "../../../sdk/entity/EntityManager.h"
#include "../../../sdk/utils/Globals.h"
#include "../../../sdk/memory/Offsets.h"
#include "../../../sdk/memory/PatternScan.h"
#include <Windows.h>

void BunnyHop::Run() {
    if (!Globals::misc_bhop)
        return;


    if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
        return;

    if (!Globals::ClientBase)
        return;

    C_CSPlayerPawn* local = EntityManager::Get().GetLocalPawn();
    if (!local)
        return;


    uint32_t flags = 0;
    Memory::SafeRead(reinterpret_cast<uintptr_t>(local) + Offsets::uint32::m_fFlags, flags);
    bool onGround = (flags & (1 << 0)) != 0;


    uintptr_t jumpAddr = Globals::ClientBase + Offsets::buttons::jump;

    if (onGround)
        Memory::SafeWrite<int>(jumpAddr, 65);
    else
        Memory::SafeWrite<int>(jumpAddr, 256);
}