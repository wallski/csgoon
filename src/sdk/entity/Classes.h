#pragma once
#include <cstdint>
#include "../memory/Offsets.h"
#include "../utils/Vector.h"

#define SCHEMA(type, name, offset) \
    type name() const { \
        return *reinterpret_cast<const type*>(reinterpret_cast<uintptr_t>(this) + offset); \
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
    SCHEMA(Vector, m_aimPunchAngle, Offsets::QAngle::m_aimPunchAngle);
    SCHEMA(uintptr_t, m_pObserverServices, Offsets::CPlayer_ObserverServices::m_pObserverServices);
    SCHEMA(int, m_iIDEntIndex, Offsets::CEntityIndex::m_iIDEntIndex);
    SCHEMA(Vector, m_angEyeAngles, Offsets::QAngle::m_angEyeAngles);

};

class C_CSPlayerController : public C_BaseEntity
{
public:
    SCHEMA(uint32_t, m_hPlayerPawn, Offsets::CHandle::m_hPlayerPawn);
    SCHEMA(const char*, m_iszPlayerName, Offsets::chars::m_iszPlayerName);
    SCHEMA(bool, m_bPawnIsAlive, Offsets::bools::m_bPawnIsAlive);
};