#pragma once

#include "AStarSearch.h"

class NavMeshSearchNode;
class NavMeshSearchLink;
class NavMeshTriangleReference;
class NavMesh;
class NMNode;
class NMNodeArray;

// pdb: class NavMeshSearchClosePoint, size 0x209c (here 0x8), bases: AStarSearch<NavMeshSearchNode, 7 members
class NavMeshSearchClosePoint : public AStarSearch<NavMeshSearchNode, NavMeshSearchLink>
{
public:
    virtual ~NavMeshSearchClosePoint();
    virtual bool AddAdjacentNodes(NMNode* apNode, NMNodeArray* apNodes);
    virtual bool IsNodeWithinSearchCriteria(NavMeshTriangleReference* apNode);

    void SetNodeData(NavMeshTriangleReference* apNode, NavMesh* apNavMesh,
                             unsigned short aiTriangle);

    float fAvoidRadius;
};
