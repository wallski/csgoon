#pragma once
#include <cstdint>

namespace Offsets
{
    // -> offsets.h on a2x dumper
    constexpr std::ptrdiff_t dwEntityList = 0x24AF268;
    constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x2069B50;
    constexpr std::ptrdiff_t dwViewMatrix = 0x230FF20;

    
	// -> client.dll.hpp on a2x dumper -> C_BaseEntity 
    constexpr std::ptrdiff_t m_iHealth = 0x354;
    constexpr std::ptrdiff_t m_iTeamNum = 0x3F3;
    constexpr std::ptrdiff_t m_vOldOrigin = 0x1588;
    constexpr std::ptrdiff_t m_pGameSceneNode = 0x338;

	// -> CbaseModelEntity
    constexpr std::ptrdiff_t m_vecViewOffset = 0xD58;

	// -> C_CSPlayerPawn
    constexpr std::ptrdiff_t m_iShotsFired = 0x270C;
    constexpr std::ptrdiff_t m_aimPunchAngle = 0x16CC;
    constexpr std::ptrdiff_t m_iIDEntIndex = 0x3EAC;

	// -> C_CSPlayerController
    constexpr std::ptrdiff_t m_iszPlayerName = 0x6F8;
    constexpr std::ptrdiff_t m_hPlayerPawn = 0x90C;
    constexpr std::ptrdiff_t m_bPawnIsAlive = 0x914;

	// -> CBodyComponentSkeletonInstance
    constexpr std::ptrdiff_t m_modelState = 0x160;

	// -> CObserverServices
    constexpr std::ptrdiff_t m_pObserverServices = 0x13F0;
    constexpr std::ptrdiff_t m_hObserverTarget = 0x4C;
	constexpr std::ptrdiff_t m_iObserverMode = 0x48;

    // -> AA
    constexpr std::ptrdiff_t attack = 0x20628F0;
    constexpr std::ptrdiff_t m_pMovementServices = 0x1418;
    constexpr std::ptrdiff_t m_nButtons = 0x50;

    // -> namespace C_BaseEntity
    constexpr std::ptrdiff_t m_fFlags = 0x400;

    // -> namespace cs2_dumper -> namespace buttons
    constexpr std::ptrdiff_t jump = 0x2062E00;
}
