#pragma once

#include "BSExtraData.h"
#include "MagicTarget.h"
#include "NiPoint3.h"

class FollowerSwimBreadcrumb;

// pdb: class ExtraFollowerSwimBreadcrumbs, size 0x28, bases: BSExtraData, 4 members
class ExtraFollowerSwimBreadcrumbs : public BSExtraData
{
public:
    virtual ~ExtraFollowerSwimBreadcrumbs();

    void __thiscall FUN_00437d10();
    void* __thiscall FUN_00437ce0(unsigned int flags);

    int eLeaderState; // src: XBOX_RETAIL_PDB +0xc (old: iCount)
    NiPoint3 LeaderLocation; // src: XBOX_RETAIL_PDB +0x10 (old: kLastPos)
    int LeaderNavMeshID; // src: XBOX_RETAIL_PDB +0x1c (old: iLastCell)
    BSSimpleList<FollowerSwimBreadcrumb*> CrumbList; // src: XBOX_RETAIL_PDB +0x20 (old: kBreadcrumbs)
};
