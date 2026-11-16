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
    unsigned int iInfoFlags; // src: XBOX_RETAIL_PDB +0x10 (old: m_uiNavMeshInfoCount)
    BSSimpleArray<const NavMeshInfo*, 1024> BestInfoPath; // src: XBOX_RETAIL_PDB +0x14 (old: NavMeshInfoPointerArray)
    BSSimpleArray<TESObjectREFR*, 1024> BestInfoPathDoors; // src: XBOX_RETAIL_PDB +0x24 (old: TESObjectReferenceArray)
    PathingPath BestTeleportPath; // src: XBOX_RETAIL_PDB +0x34 (old: NavMeshReferenceCollection)

    PathingInfo();
    ~PathingInfo();
};
