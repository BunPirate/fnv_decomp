#pragma once

#include "AStarSearch.h"
#include "BSSimpleArray.h"
#include "NavMeshEdgeData.h"
#include "NavMeshPOVSearch.h"
#include "NiPoint3.h"

class PathSmootherPOVNode;
class Key6AE;
class PathSmootherPOVLink;
class PathSmootherPOVAvoidanceNode;
class PathSmootherPOVPoint;
class NavMesh;
class NavMeshEdgePoint;
class NavMeshEdgeSegment;
class NavMeshInfo;
class NavMeshTriangleReference;
class NavMeshTriangleEdgeReference;
class PathingRequest;
class PathingSolution;
class SineCosine;
class Sphere;
class CircularArc;

template <class N, class L> class AStarNode;
typedef AStarNode<PathSmootherPOVAvoidanceNode, NavMeshEdgeSegment> POVNode;

// pdb: class PathSmootherPOVSearch, size 0x2110, bases: AStarSearch<PathSmootherPOVNode, 18 members
class PathSmootherPOVSearch : public AStarSearch<PathSmootherPOVNode, PathSmootherPOVLink>
{
public:
    void* DestroyPathSmootherPOVSearch(unsigned int);
    void CreateStartPoint();
    void CreateGoalPoint();
    void CollectAvoidSpheres();
    void* ComputePathNodes();
    void CopyNodeListToArrays(void*, BSSimpleArray<PathSmootherPOVAvoidanceNode, 1024>*,
                              BSSimpleArray<NavMeshEdgeSegment, 1024>*);
    void AddEntry(const Key6AE*, const NavMeshEdgeData&);

    PathSmootherPOVSearch();
    virtual ~PathSmootherPOVSearch();
    virtual bool CollectConnections(const POVNode*, BSSimpleArray<POVNode*, 1024>*);
    virtual bool HasReachedGoal(const POVNode*);

    class NavMeshEdgeRecord
    {
    public:
        NavMesh* m_pLocationNavMesh;
        unsigned short m_usVertexId;
        NavMeshEdgeData Edge;
        unsigned int m_uiReferenceIndex;
        unsigned int m_uiListIndex;
        unsigned int m_uiTrailingValue;
    };

    PathingRequest* pRequest;
    PathingSolution* pSolution; // src: XBOX_RETAIL_PDB +0x205c (old: m_pOutputSolution)
    NiPoint3 m_kPathStartPosition;
    NiPoint3 GoalLocation; // src: XBOX_RETAIL_PDB +0x206c (old: m_kGoalPosition)
    bool bUnderWaterPath; // src: XBOX_RETAIL_PDB +0x2078 (old: m_bUnderwaterPath)
    const BSSimpleArray<NavMeshTriangleReference, 1024>* Triangles;
    const BSSimpleArray<NavMeshTriangleEdgeReference, 1024>* Edges;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kPrimaryPathPoints;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kSecondaryPathPoints;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> m_kRequestPathPoints;
    BSSimpleArray<PathSmootherPOVPoint*, 1024> allPOVs; // src: XBOX_RETAIL_PDB +0x20b4 (old: m_kPathPoints)
    PathSmootherPOVPoint* pStartPov; // src: XBOX_RETAIL_PDB +0x20c4 (old: m_pStartPoint)
    PathSmootherPOVPoint* pGoalPov; // src: XBOX_RETAIL_PDB +0x20c8 (old: m_pGoalPoint)
    BSSimpleArray<PathSmootherPOVAvoidanceNode, 1024> Nodes;
    BSSimpleArray<NavMeshEdgeSegment, 1024> Links;
    BSSimpleArray<NavMeshEdgeRecord, 1024> m_kPrimaryEdgeRecords;
    BSSimpleArray<NavMeshEdgeRecord, 1024> m_kSecondaryEdgeRecords;
    BSSimpleArray<const NavMeshInfo*, 1024>* pDetailedPathInfos; // src: XBOX_RETAIL_PDB +0x210c (old: m_pNavMeshInfos)

    bool CheckSegmentAgainstNavMesh(const NavMeshEdgePoint&, const NiPoint3&, NavMeshEdgePoint&, float&);
    bool SmoothPath(PathingRequest*, const BSSimpleArray<NavMeshTriangleReference, 1024>&,
                       const BSSimpleArray<NavMeshTriangleEdgeReference, 1024>&,
                       const NiPoint3&, const NiPoint3&, PathingSolution*,
                       BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*,
                       BSSimpleArray<const NavMeshInfo*, 1024>*);
    void AddAvoidanceNodes();
    void AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_AddStartNode(unsigned int, const PathSmootherPOVAvoidanceNode&, float);
    bool AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_Search(BSSimpleArray<PathSmootherPOVAvoidanceNode, 1024>*,
                      BSSimpleArray<NavMeshEdgeSegment, 1024>*, bool);
    void BuildPOVLinks();
    bool TryAddLastNode();
    void InsertPOVPoint(BSSimpleArray<NavMeshEdgeRecord, 1024>*, unsigned int, bool);
    void BuildFallbackPath();
    bool AddIntersectingPOVsAsBadNodes(BSSimpleArray<NavMeshTriangleEdgeReference, 1024>*);
    void CollectUniqueNavMeshes();
    void BuildSmoothedPath();
    void AddPathPoints(bool);
    void AddNavMeshEdgeRecord(NavMesh*, unsigned short, const NiPoint3&, const NiPoint3&);
    NiPoint3 RotatePoint90(const SineCosine&, ANGLE_DIRECTION);
    bool FindPathToPoint(const POVNode*, PathSmootherPOVPoint*, BSSimpleArray<POVNode*, 1024>*);
    bool CheckSegmentAgainstAvoidNodes(PathSmootherPOVPoint*, PathSmootherPOVPoint*,
                           const NiPoint3&, const NiPoint3&, float*);
    bool CheckArcAgainstNavMesh(const NavMeshEdgePoint&, Sphere&, CircularArc, NavMeshEdgePoint*);
    bool DoubleCheckArcAgainstNavMesh(const NavMeshEdgePoint&, Sphere&, CircularArc);
    bool TripleCheckSegmentAgainstNavMesh(const NavMeshEdgePoint&, const NiPoint3&, NavMeshEdgePoint*, bool, bool, float&);
    unsigned int GetKeyForNode(PathSmootherPOVPoint*, ANGLE_DIRECTION);
    int AStarSearch_PathSmootherPOVNode_PathSmootherPOVLink_GetOrCreateAStarNode(unsigned int, float, POVNode*&);
    void SetPOVSearchNode(POVNode*, PathSmootherPOVPoint*, ANGLE_DIRECTION);
};
