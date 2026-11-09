#pragma once

#include "BSSimpleArray.h"
#include "PathingPath.h"

class PathingInfoEntry;
class NavMeshInfo;
class TESObjectREFR;

// pdb: class PathingInfo, size 0x6c, 5 members
class PathingInfo
{
public:
    BSSimpleArray<PathingInfoEntry, 1024> Items;
    unsigned int iInfoFlags;
    BSSimpleArray<const NavMeshInfo*, 1024> BestInfoPath;
    BSSimpleArray<TESObjectREFR*, 1024> BestInfoPathDoors;
    PathingPath BestTeleportPath;

    PathingInfo();
    ~PathingInfo();
};
