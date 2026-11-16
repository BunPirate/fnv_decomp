#pragma once

__if_not_exists(NiPoint3::x)
{
#include "NiPoint3.h"
}
__if_not_exists(PathingLocation::Location)
{
#include "PathingLocation.h"
}

class PathingRequest;
class PathingSolutionExt;
class RayCastItem;
class RayCastParam;
class SearchItem;
template <class T, unsigned int N> class BSSimpleArrayExt;

// pdb: class PathingSearchRayCast, size 0x94, 14 members
class PathingSearchRayCast
{
public:
    virtual ~PathingSearchRayCast();

    PathingLocation StartLocation; // src: XBOX_RETAIL_PDB +0x4 (old: loc04)
    PathingLocation GoalLocation; // src: XBOX_RETAIL_PDB +0x2c (old: loc2C)
    PathingRequest* pRequest;
    unsigned int eType; // src: XBOX_RETAIL_PDB +0x58 (old: unk58)
    NiPoint3 BoundsMin; // src: XBOX_RETAIL_PDB +0x5c (old: pt5C)
    NiPoint3 BoundsMax; // src: XBOX_RETAIL_PDB +0x68 (old: pt68)
    float fActorRadius; // src: XBOX_RETAIL_PDB +0x74 (old: f74)
    void* pCache; // src: XBOX_RETAIL_PDB +0x78 (old: unk78)
    unsigned int pHavokWorld; // src: XBOX_RETAIL_PDB +0x7c (old: unk7C)
    unsigned int pPickData; // src: XBOX_RETAIL_PDB +0x80 (old: unk80)
    void* pCollector; // src: XBOX_RETAIL_PDB +0x84 (old: unk84)
    int iRayCastCount; // src: XBOX_RETAIL_PDB +0x88 (old: unk88)
    float fMaxDrop; // src: XBOX_RETAIL_PDB +0x8c (old: f8C)
    float fMaxStep; // src: XBOX_RETAIL_PDB +0x90 (old: f90)

    PathingSearchRayCast();
    bool FUN_006c4000();
    bool InitRayCasts();
    bool UpdateAndCheck(const NiPoint3& p1, const NiPoint3& p2);
    bool CheckPathClear(const NiPoint3& p1, const NiPoint3& p2);
    void ComputeBounds(BSSimpleArrayExt<RayCastItem, 1024>& arr);
    void PathingSearchRayCast_CleanUpRayCasts();
    unsigned int BuildPath(RayCastParam* aRequest, PathingSolutionExt* aRetPath);
    void BuildPath(SearchItem*, SearchItem*);
    int FUN_004fd3e0();
    void __thiscall FUN_006e62b0();
    void* __thiscall Destroy(unsigned int flags);
};
