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

    int eLeaderState;
    NiPoint3 LeaderLocation;
    int LeaderNavMeshID;
    BSSimpleList<FollowerSwimBreadcrumb*> CrumbList;
};
