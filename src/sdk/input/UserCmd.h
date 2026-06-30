#pragma once

#include <cstdint>
#include "../utils/Vector.h"

enum EInputHistoryBits : std::uint32_t
{
    INPUT_HISTORY_BITS_VIEWANGLES = 0x1U,
};

enum EBaseCmdBits : std::uint32_t
{
    BASE_BITS_VIEWANGLES = 0x4U,
};

class CBasePB
{
public:
    char          pad0[0x8]{};
    std::uint32_t nHasBits{};
    std::uint64_t nCachedBits{};

    void SetBits(std::uint64_t nBits)
    {
        nCachedBits |= nBits;
    }
};

static_assert(sizeof(CBasePB) == 0x18);

class CMsgQAngle : public CBasePB
{
public:
    Vector angValue{};
};

static_assert(sizeof(CMsgQAngle) == 0x28);

class CCSGOInputHistoryEntryPB : public CBasePB
{
public:
    CMsgQAngle* pViewAngles{};
    char        pad1[0x58]{};
};

static_assert(sizeof(CCSGOInputHistoryEntryPB) == 0x78);

template <typename T>
struct RepeatedPtrField_t
{
    struct Rep_t
    {
        int nAllocatedSize{};
        char pad[4]{};
        T*   tElements[256]{};
    };

    void*  pArena{};
    int    nCurrentSize{};
    int    nTotalSize{};
    Rep_t* pRep{};
};

struct CInButtonStatePB : CBasePB
{
    std::uint64_t nValue{};
    std::uint64_t nValueChanged{};
    std::uint64_t nValueScroll{};
};

static_assert(sizeof(CInButtonStatePB) == 0x30);

class CBaseUserCmdPB : public CBasePB
{
public:
    RepeatedPtrField_t<void> subtickMovesField{};
    void*                    strMoveCrc{};
    CInButtonStatePB*        pInButtonState{};
    CMsgQAngle*              pViewAngles{};
    char                     pad0[0x38]{};
};

static_assert(sizeof(CBaseUserCmdPB) == 0x80);

class CCSGOUserCmdPB
{
public:
    std::uint32_t nHasBits{};
    std::uint32_t pad0{}; // alignment to 8
    std::uint64_t nCachedSize{};
    RepeatedPtrField_t<CCSGOInputHistoryEntryPB> inputHistoryField{};
    CBaseUserCmdPB* pBaseCmd{};
    char            pad1[0x10]{}; // was 0x18, now 0x10
};
static_assert(sizeof(CCSGOUserCmdPB) == 0x40);

struct CInButtonState
{
    char          pad0[0x8]{};
    std::uint64_t nValue{};
    std::uint64_t nValueChanged{};
    std::uint64_t nValueScroll{};
};

static_assert(sizeof(CInButtonState) == 0x20);

class CUserCmd
{
public:
    char            pad0[0x18]{};
    CCSGOUserCmdPB  csgoUserCmd{};
    CInButtonState  nButtons{};
    char            pad1[0x20]{};

    void SetSubTickAngle(const Vector& angView)
    {
        auto* rep = csgoUserCmd.inputHistoryField.pRep;
        if (!rep)
            return;

        for (int i = 0; i < rep->nAllocatedSize && i < csgoUserCmd.inputHistoryField.nCurrentSize; ++i)
        {
            CCSGOInputHistoryEntryPB* entry = rep->tElements[i];
            if (!entry || !entry->pViewAngles)
                continue;

            entry->pViewAngles->angValue = angView;
            entry->SetBits(INPUT_HISTORY_BITS_VIEWANGLES);
        }
    }

    void SetBaseViewAngle(const Vector& angView)
    {
        CBaseUserCmdPB* base = csgoUserCmd.pBaseCmd;
        if (!base || !base->pViewAngles)
            return;

        base->pViewAngles->angValue = angView;
        base->SetBits(BASE_BITS_VIEWANGLES);
    }

    void SetSilentViewAngle(const Vector& angView)
    {
        SetSubTickAngle(angView);
        SetBaseViewAngle(angView);
    }
};

static_assert(sizeof(CUserCmd) == 0x98);
