#pragma once

#include "AStarSearch.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class NavMeshSearchNode;
class NavMeshSearchLink;
class NavMeshTriangleReference;
class NavMeshTriangleEdgeReference;
class NavMesh;
class PathingRequest;
class FleeStartNode;
class FleePath;
class Node;
class NodeArray;
enum SearchResult;

typedef AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference> SearchNode;

// pdb: class NavMeshSearchFlee, size 0x2090, bases: AStarSearch<NavMeshSearchNode, 6 members
class NavMeshSearchFlee : public AStarSearch<NavMeshSearchNode, NavMeshSearchLink>
{
public:
    virtual ~NavMeshSearchFlee();
    virtual bool ExpandNode(Node* apNode, NodeArray* apRetNodes);
    virtual bool IsNodeValid(const SearchNode* apNode);

    void* DestroyIfFlagged(unsigned int flags);
    const SearchNode* GetFieldAt2050();
    void SetNodeFleeCost(SearchNode* apNode, NavMesh* apNavMesh, unsigned short aiTriangle);
    unsigned int GetKeyForNode_006a94f0(NavMesh*, unsigned short);
    unsigned int GetKeyForNode_006a94f0();
    SearchNode* FUN_006a7c90(unsigned int, const FleeStartNode*, float);
    bool FUN_006a7d60(FleePath*, unsigned int, bool);
    SearchResult FUN_006a7e00(unsigned int, NavMesh*, unsigned short, float, Node**);
    bool BuildNodePath(PathingRequest* apRequest, const FleeStartNode* aStartNode,
                         FleePath* apReturnNodeArray, unsigned int apReturnLinkArray);

    unsigned int pad0[0x2054 / 4];
    PathingRequest* pCurrentRequest; // src: XBOX_RETAIL_PDB +0x2058 (old: pRequest)
    unsigned int StartNode[5]; // src: XBOX_RETAIL_PDB +0x205c (old: pad205c)
    NiPoint3 AvoidNodeCenter; // src: XBOX_RETAIL_PDB +0x2070 (old: kAvoidVector)
    float fDistanceUpperBound; // src: XBOX_RETAIL_PDB +0x207c (old: fFleeRange)
    bool bFavorGoingTowardsGoal; // src: XBOX_RETAIL_PDB +0x2080 (old: bHasDestination)
    NiPoint3 GoalLocation; // src: XBOX_RETAIL_PDB +0x2084 (old: kDestination)
};
