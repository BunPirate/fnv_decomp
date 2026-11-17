#pragma once

#include "NavMeshSearch.h"
#include "NiPoint3.h"

class NavMeshSearchLocation;
class PathingLocation;
class PathBuilderDetailedPathInfos;
class Mesh;
class Location;
class OpenSet;
class ClosedSet;
class Node;
class NodeOutput;

// pdb: class NavMeshSearchMaxCost, size 0x20ac, bases: NavMeshSearch, 2 members
class NavMeshSearchMaxCost : public NavMeshSearch
{
public:
    NavMeshSearchMaxCost();
    virtual ~NavMeshSearchMaxCost();
    virtual bool CollectConnections(const SearchNode*, BSSimpleArray<SearchNode*, 1024>*);
    virtual bool HasReachedGoal(const SearchNode*);

    void NavMeshSearchMaxCost_dtor();
    void* __thiscall Destroy(unsigned int flags);
    int GetField2048();
    bool IsGoalNode_006abb60(const SearchNode* apNode);

    bool StartSearch(int aiSearchType, NavMeshSearchLocation* apStart,
                     PathingLocation* apGoal, PathBuilderDetailedPathInfos* apInfos,
                     PathBuilderDetailedPathInfos* apAltInfos);
    void AStarSearch_NavMeshSearchNode_NavMeshSearchLink_ClearSearchData();
    unsigned int GetKeyForNode_006a94f0(NavMesh* apNavMesh, unsigned short ausTriangle);
    void FUN_006a7c90(unsigned int aiKey, NavMeshSearchLocation* aNodeData, float afHeuristic);
    bool FUN_006a7d60(PathBuilderDetailedPathInfos* apReturnArray,
                      PathBuilderDetailedPathInfos* apReturnLinkArray, bool abReturnBestPathIfFailed);

    NiPoint3 FindPath(int unused, Location* initial, NiPoint3* fallback, Location* target, float cost);
    unsigned int Index(Mesh*, unsigned short);
    void Add(unsigned int, Location*, float);
    using NavMeshSearch::Run;
    bool Run(OpenSet*, ClosedSet*, int);
    Node* Result();

    int FUN_006a7e00(unsigned int, float, NavMeshTriangleReference**);
    void SetNodeData(NavMeshTriangleReference*, NavMesh*, unsigned short);
    bool ExpandNeighborNodes(NavMeshTriangleReference* apNode, NodeOutput* apRetNodes);
    void FUN_006a6b00();

    float fMaxDist; // src: XBOX_RETAIL_PDB +0x20a4 (old: maxCost)
    union
    {
        bool hasGoal;
        bool bHasGoal;
        bool flag;
    };
};
