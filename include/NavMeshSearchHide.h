#pragma once

#include "NavMeshSearch.h"
#include "NiPoint3.h"

class ActorX;
class Range6aa4;
class MeshX;
class InfoF;
class ParamX;
class NavMeshStandIn;
class NavSearchNode;
class NavSearchNodeInfo;
class NavSearchNodeList;
class NavData6aa4;

struct TriRef20
{
    MeshX* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    NiPoint3 m_kPt;
};

// pdb: class NavMeshSearchHide, size 0x20d8, bases: NavMeshSearch, 5 members
class NavMeshSearchHide : public NavMeshSearch
{
public:
    virtual ~NavMeshSearchHide();
    virtual bool CollectConnections(const SearchNode*, BSSimpleArray<SearchNode*, 1024>*);
    virtual bool HasReachedGoal(const SearchNode*);

    void NavMeshSearchHide_dtor();
    void* DestroyIfFlagged(unsigned int flags);

    void SetNodeData(SearchNode* apNode, NavMesh* apNavMesh, unsigned short aiTriangle);
    void InitEntry(NavSearchNode* pNode, NavMeshStandIn* pMesh, unsigned short usTri);
    bool ExpandNeighbors(NavSearchNodeInfo* apNode, NavSearchNodeList* apRetNodes);
    int BuildNodePath(ActorX* apRequest, TriRef20* aStartNode, ParamX* apReturnNodeArray, int apReturnLinkArray);
    bool IsGoalNode(NavData6aa4* apNode);

    int GetKeyForNode_006a94f0(NavMeshStandIn* pMesh, unsigned short usTri,
                     float m_fPathingCostCur, NavSearchNode** ppNode);
    int GetKeyForNode_006a94f0(MeshX* pMesh, unsigned short usTri);
    int FUN_006a7e00(int aiKey);
    void FUN_006a7c90(int aiKey, InfoF* aNodeData, float afHeuristic);
    void FUN_006a7d60(ParamX* apReturnArray, int apReturnLinkArray, int abReturnBestPathIfFailed);

    union
    {
        ActorX* m_pActor;
        Range6aa4* m_pkActor;
    };
    TriRef20 StartNode;
    NiPoint3 AvoidNodeCenter;
    float fDistanceUpperBound;
    NiPoint3 ThreatLocation;
};
