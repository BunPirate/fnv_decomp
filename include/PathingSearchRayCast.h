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

    PathingLocation StartLocation;
    PathingLocation GoalLocation;
    PathingRequest* pRequest;
    unsigned int eType;
    NiPoint3 BoundsMin;
    NiPoint3 BoundsMax;
    float fActorRadius;
    void* pCache;
    unsigned int pHavokWorld;
    unsigned int pPickData;
    void* pCollector;
    int iRayCastCount;
    float fMaxDrop;
    float fMaxStep;

    PathingSearchRayCast();
    bool FUN_006c4000();
    bool PathingSearchRayCast_InitRayCasts();
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
