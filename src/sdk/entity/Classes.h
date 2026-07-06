#pragma once
#include <cstdint>
#include "../memory/Offsets.h"
#include "../utils/Vector.h"
#include "../memory/PatternScan.h"

#define SCHEMA(type, name, offset) \
    type name() const { \
        type val{}; \
        Memory::SafeRead(reinterpret_cast<uintptr_t>(this) + offset, val); \
        return val; \
    }


class CGameSceneNode
{
public:
    SCHEMA(uintptr_t, m_modelState, Offsets::CModelState::m_modelState);
};

class C_Player_ObserverServices {
public:
    SCHEMA(uint32_t, m_hObserverTarget, Offsets::CHandle::m_hObserverTarget);
};

class C_BaseEntity
{
public:
    SCHEMA(uint32_t, m_fFlags, Offsets::uint32::m_fFlags);
    SCHEMA(int, m_iHealth, Offsets::int32::m_iHealth);
    SCHEMA(int, m_iTeamNum, Offsets::uint8::m_iTeamNum);
    SCHEMA(Vector, m_vOldOrigin, Offsets::Vector::m_vOldOrigin);
    SCHEMA(uintptr_t, m_pGameSceneNode, Offsets::CGameSceneNode::m_pGameSceneNode);

    bool IsAlive() const { return m_iHealth() > 0; }
};

class C_CSPlayerPawn : public C_BaseEntity
{
public:
    SCHEMA(Vector, m_vecViewOffset, Offsets::CNetworkViewOffsetVector::m_vecViewOffset);
    SCHEMA(int, m_iShotsFired, Offsets::int32::m_iShotsFired);
    Vector m_aimPunchAngle() const {
        uintptr_t aimPunchServices = 0;
        if (!Memory::SafeRead(reinterpret_cast<uintptr_t>(this) + 0x1490, aimPunchServices) || !aimPunchServices)
            return { 0.f, 0.f, 0.f };

        uintptr_t dataPtr = 0;
        int size = 0;
        if (!Memory::SafeRead(aimPunchServices + 0x88, dataPtr) || !dataPtr)
            return { 0.f, 0.f, 0.f };
        if (!Memory::SafeRead(aimPunchServices + 0x88 + 8, size) || size <= 0 || size > 1000)
            return { 0.f, 0.f, 0.f };

        Vector latestPunch{};
        if (Memory::SafeRead(dataPtr + (size - 1) * sizeof(Vector), latestPunch)) {
            return latestPunch;
        }
        return { 0.f, 0.f, 0.f };
    }
    SCHEMA(uintptr_t, m_pObserverServices, Offsets::CPlayer_ObserverServices::m_pObserverServices);
    SCHEMA(int, m_iIDEntIndex, Offsets::CEntityIndex::m_iIDEntIndex);
    SCHEMA(Vector, m_angEyeAngles, Offsets::QAngle::v_angle);

};

class C_CSPlayerController : public C_BaseEntity
{
public:
    SCHEMA(uint32_t, m_hPlayerPawn, Offsets::CHandle::m_hPlayerPawn);
    SCHEMA(const char*, m_iszPlayerName, Offsets::chars::m_iszPlayerName);
    SCHEMA(bool, m_bPawnIsAlive, Offsets::bools::m_bPawnIsAlive);
};