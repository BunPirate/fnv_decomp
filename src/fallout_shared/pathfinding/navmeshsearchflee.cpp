#include "../../../include/DoorAccessData.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/NavMeshSearchFlee.h"
#include "../../../include/NavMeshSearchMaxCost.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/NiPoint3.h"
#include <float.h>
#include "../../../include/NavMeshTriangleReference.h"

// src/fallout_shared/pathfinding/navmeshsearchflee.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchflee.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void _Deallocate(void*);

enum SearchResult
{
    Added,
    Updated,
    Unchanged
};

// Runs the destructor, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006a9290
// pdb: NavMeshSearchFlee::`scalar deleting destructor' | NavMeshSearchFlee.obj | debug, vtable slot, medium
void* NavMeshSearchFlee::DestroyIfFlagged(unsigned int flags)
{
    this->~NavMeshSearchFlee();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Initializes the vtable pointer and clears the fields at offsets 0x20a4 and 0x20a8.
// @fnv 0x006ab410
// pdb: NavMeshSearchMaxCost::NavMeshSearchMaxCost | NavMeshSearchMaxCost.obj | retail, upstream name already matches, high
NavMeshSearchMaxCost::NavMeshSearchMaxCost()
{
    fMaxDist = 0.0f;
    hasGoal = false;
}

class NavMeshTriangleEdgeReference;
template <class N, class L> class AStarNode
{
  public:
    unsigned int unk0, unk4;
    N kNode;
    const N& FUN_00413f40() const;
};
extern double _gModifierZero;

// @fnv 0x006a9a70
// pdb: NavMeshSearchFlee::IsGoalNode | NavMeshSearchFlee.obj | retail, vtable slot, high
// pdb params: apNode
// pdb locals: pdest, fscore, nodeCenter, fsqrLength, spmeshPtr, sgoalTri, thisNode, destinationVec, originDestinationVec
bool NavMeshSearchFlee::IsNodeValid(const AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode)
{
    PathingLocation* pdest = pCurrentRequest->NiAVObject_GetRotate_006a9540();
    float fscore;
    if (bFavorGoingTowardsGoal)
    {
        NavMeshPtr spmeshPtr;
        unsigned short sgoalTri;
        if (pdest->FindNavMeshTriangle(spmeshPtr, sgoalTri))
        {
            const NavMeshTriangleReference* thisNode = &apNode->FUN_00413f40();
            if ((unsigned int)thisNode->m_pLocationNavMesh == static_cast<unsigned int>(spmeshPtr) &&
                thisNode->m_usTriangleIdentifier == sgoalTri)
                return true;
        }
    }
    if (apNode == GetFieldAt2050())
        return false;
    NiPoint3 nodeCenter = apNode->kNode.FastNavMeshTriLocation_GetLocation();
    float fsqrLength = (pCurrentRequest->GetOrigin()->FUN_005c3420() - nodeCenter).GetSquaredXYLength();
    if (fsqrLength < static_cast<const PathingRequest*>(pCurrentRequest)->GetFloatAtOffsetB0() *
                        static_cast<const PathingRequest*>(pCurrentRequest)->GetFloatAtOffsetB0())
        return false;
    if (bFavorGoingTowardsGoal)
    {
        NiPoint3 destinationVec = GoalLocation - nodeCenter;
        NiPoint3 originDestinationVec = pCurrentRequest->GetOrigin()->FUN_005c3420() - GoalLocation;
        if (originDestinationVec.FUN_004a7290() < destinationVec.FUN_004a7290())
            return false;
    }
    fscore = 0.0f;
    if (static_cast<const PathingRequest*>(pCurrentRequest)->GetString())
        fscore = static_cast<const PathingRequest*>(pCurrentRequest)->GetString()->GetAvoidanceAtPoint(nodeCenter);
    return fscore <= _gModifierZero;
}

void BSClamp_float(float&, float, float);

struct FleeNodeLayout
{
    unsigned int unk0;
    float fcost;
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleIdentifier;
    float GetCenterX;
    float m_fCenterY;
    float m_fCenterZ;
};

// Stores the navmesh and triangle on the node, computes the triangle center, and sets the node cost from the flee range minus the distance to the avoid vector.
// @fnv 0x006a9580
// pdb: NavMeshSearchFlee::`scalar deleting destructor' | NavMeshSearchFlee.obj | retail, object-file run extension, low
// pdb note: debug build links it to NavMeshSearchFlee::SetNodeData
// pdb params: this
void NavMeshSearchFlee::SetNodeFleeCost(AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* apNode,
                                     NavMesh* apNavMesh, unsigned short aiTriangle)
{
    reinterpret_cast<FleeNodeLayout*>(apNode)->m_pLocationNavMesh = apNavMesh;
    reinterpret_cast<FleeNodeLayout*>(apNode)->m_usTriangleIdentifier = aiTriangle;

    NiPoint3 center = apNavMesh->GetNavMeshData(aiTriangle);

    reinterpret_cast<FleeNodeLayout*>(apNode)->GetCenterX = center.x;
    reinterpret_cast<FleeNodeLayout*>(apNode)->m_fCenterY = center.y;
    reinterpret_cast<FleeNodeLayout*>(apNode)->m_fCenterZ = center.z;

    NiPoint3 avoidVector = reinterpret_cast<const NiPoint3&>(center) - AvoidNodeCenter;
    float fcost = fDistanceUpperBound - avoidVector.Length();

    BSClamp_float(fcost, 0.0f, fDistanceUpperBound);

    reinterpret_cast<FleeNodeLayout*>(apNode)->fcost = fcost;
}

// NavMeshSearchFlee's destructor.
//
// The compiler-generated destructor of a class with a base class first restores
// the class vtable pointer into the object and then runs the base class
// destructor on the same object.
// @fnv 0x006a92c0
// pdb: NavMeshSearchFlee::~NavMeshSearchFlee | NavMeshSearchFlee.obj | debug, upstream name already matches, high
NavMeshSearchFlee::~NavMeshSearchFlee()
{}

// the start node is the 20-byte triangle reference itself (mesh, triangle, centre): 0x006a92e0 copies 20 bytes
struct FleeStartNode : NavMeshTriangleReference
{
};
struct FleePath
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    const NavMeshTriangleReference* GetLastElement();
};
// The shared avoidance array lacks this vector-output overload.
struct FleeAvoidNodes : PathingAvoidNodeArray
{
    float PathingAvoidNodeArray_ComputeCenter(NiPoint3&, NiPoint3&);
};
extern const NiPoint3 NiPoint3_ZERO;
float BSMIN(float, float);
// @fnv 0x006a92e0
// src: XBOX_DEBUG_PDB 0x006a92e0
// pdb: NavMeshSearchFlee::BuildNodePath | NavMeshSearchFlee.obj | debug, call graph, high
// pdb params: apRequest, aStartNode, apReturnNodeArray, apReturnLinkArray
// pdb locals: startPoint, bresult, pstartNode, endLocation, endNode, fminDistance, vec
bool NavMeshSearchFlee::BuildNodePath(PathingRequest* apRequest, const FleeStartNode* aStartNode, FleePath* apReturnNodeArray,
                                       unsigned int apReturnLinkArray)
{
    pCurrentRequest = apRequest;
    reinterpret_cast<FleeStartNode&>(StartNode) = *aStartNode;
    NiPoint3 a = apRequest->GetOrigin()->FUN_005c3420();
    reinterpret_cast<NiPoint3&>(AvoidNodeCenter) = NiPoint3_ZERO;
    fDistanceUpperBound = static_cast<const PathingRequest*>(apRequest)->GetFloatAtOffsetB0();
    if (static_cast<const PathingRequest*>(pCurrentRequest)->GetString())
        static_cast<FleeAvoidNodes*>(static_cast<const PathingRequest*>(pCurrentRequest)->GetString())->PathingAvoidNodeArray_ComputeCenter(a, AvoidNodeCenter);
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* p =
        FUN_006a7c90(GetKeyForNode_006a94f0(aStartNode->m_pLocationNavMesh, aStartNode->m_usTriangleIdentifier), aStartNode, 0.0f);
    SetNodeFleeCost(p, aStartNode->m_pLocationNavMesh, aStartNode->m_usTriangleIdentifier);
    if (!apRequest->NiAVObject_GetRotate_006a9540()->PathingLocation_QUnused())
    {
        bFavorGoingTowardsGoal = true;
        GoalLocation = pCurrentRequest->NiAVObject_GetRotate_006a9540()->FUN_005c3420();
    }
    bool h = FUN_006a7d60(apReturnNodeArray, apReturnLinkArray, pCurrentRequest->GetByteAtOffset9B());
    if (!h && !apReturnNodeArray->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        const NavMeshTriangleReference* f = apReturnNodeArray->GetLastElement();
        NiPoint3 eb = f->FastNavMeshTriLocation_GetLocation();
        float s = static_cast<const PathingRequest*>(pCurrentRequest)->GetFloatAtOffsetB0() * 0.5;
        s = BSMIN(s, 256.0f);
        NiPoint3 i = a - eb;
        if (i.FUN_004a7290() > s * s)
            h = true;
    }
    return h;
}

extern const NiPoint3 pathingrequestZero;
extern float g_doorCost;
extern double g_positionWeight;
extern double g_destinationWeight;
struct Threshold
{
    float* Float();
};
extern Threshold g_threshold;
float __cdecl BSMAX_00404010(float, float);
// pdb: structure EdgeExtraInfo, size 0xc (here 0x4), 2 members
struct EdgeExtraInfo
{
    int type;
};
struct DoorBase
{
    bool FUN_00518000();
};
struct Door
{
    DoorBase* BGSSaveFormBuffer_GetForm();
};
Door* __cdecl TESForm_GetFormByNumericID(unsigned int);
struct Node
{
    float cost;
    int unk04;
    NavMesh* edgeData;
    unsigned short triangle;
    unsigned short unk0e;
    int unk10, unk14, unk18;
    NavMesh* parentMesh;
    unsigned short parentTriangle;
    unsigned short unk22;
    int parentEdge;
};
struct NodeGeometry
{
    NavMesh* edgeData;
    unsigned short triangle;
    NiPoint3 FastNavMeshTriLocation_GetLocation() const;
};
struct NodeArray
{
    void FUN_007cb2e0(Node*&);
};
// @fnv 0x006a9620
// pdb: NavMeshSearchFlee::GetNodeConnections | NavMeshSearchFlee.obj | retail, vtable slot, high
// pdb params: apNode, apRetNodes
// pdb locals: pavoidNodes, aNodeCenter, avoidDir, pmutableNode, i, potherMesh, iotherEdge, usotherTri, fdoorMultiplier, pextra, toOtherNode, fcost, pnode, nodeCenter, doorID, pdoor, doorLock, bmustPick, lockData, ftowardThreat, unitToOtherNode, fdistToGoal
bool NavMeshSearchFlee::ExpandNode(Node* apNode, NodeArray* apRetNodes)
{
    float position[3];  // Raw storage avoids invoking NiPoint3's default constructor.
    NiPoint3 direction = ((NodeGeometry*)&apNode->edgeData)->FastNavMeshTriLocation_GetLocation();
    PathingAvoidNodeArray* avoid = static_cast<const PathingRequest*>(pCurrentRequest)->GetString();
    reinterpret_cast<NiPoint3&>(position) = *(const NiPoint3*)&pathingrequestZero;
    if (avoid)
    {
        reinterpret_cast<NiPoint3&>(position) = *(NiPoint3*)&AvoidNodeCenter - direction;
        reinterpret_cast<NiPoint3&>(position).Unitize();
    }
    if (!_finite(apNode->cost))
    {
        float& initial = apNode->cost;
        initial = 0.0f;
    }
    for (int edge = 0; edge < 3; ++edge)
    {
        NavMesh* edgeData;
        unsigned short triangle;
        int mesh;
        if (apNode->edgeData->FindAdjacentEdge(apNode->triangle, edge, &edgeData, &triangle, &mesh))
        {
            EdgeExtraInfo* next = apNode->edgeData->GetEdgeExtraInfo(apNode->triangle, edge);
            if (next && next->type == 1)
                continue;
            float delta = 1.0f;
            if (edgeData->FUN_005582f0(triangle)->FUN_00691140(0x1000))
            {
                if (pCurrentRequest->FUN_0073cb80())
                    continue;
                else
                {
                    unsigned int door = *edgeData->FUN_00699af0(triangle);
                    Door* id = TESForm_GetFormByNumericID(door);
                    if (id)
                    {
                        DoorAccessData result(reinterpret_cast<TESObjectREFR*>(id));
                        const PathingActorData* lock = pCurrentRequest->GetActorLockData();
                        bool actor;
                        if (!result.CanUnlockDoor(lock, reinterpret_cast<TESObjectREFR*>(id), actor))
                            continue;
                        if (id->BGSSaveFormBuffer_GetForm()->FUN_00518000())
                            delta = 100.0f;
                    }
                }
            }
            if (static_cast<const PathingRequest*>(pCurrentRequest)->GetFloatAtOffset68() > *g_threshold.Float() &&
                edgeData->FUN_005582f0(triangle)->FUN_00691140(0x10))
                continue;
            Node* neighbour;
            // Adjacent triangle centre and displacement from the current node.
            NiPoint3 multiplier = edgeData->FUN_00558220(triangle);
            NiPoint3 cost = reinterpret_cast<const NiPoint3&>(multiplier) - direction;
            // Accumulated path cost.
            float extra = static_cast<const NiPoint3&>(cost).Length() * delta + apNode->cost;
            if (avoid)
            {
                extra += static_cast<const PathingRequest*>(pCurrentRequest)->GetString()->GetAvoidanceAtPoint(multiplier);
                NiPoint3 penalty = cost;
                penalty.Unitize();
                float travel = BSMAX_00404010(0.0f, penalty.Dot(reinterpret_cast<NiPoint3&>(position)));
                extra += travel * g_positionWeight;
            }
            if (bFavorGoingTowardsGoal)
            {
                float distance = static_cast<const NiPoint3&>(reinterpret_cast<const NiPoint3&>(multiplier) -
                                  reinterpret_cast<const NiPoint3&>(GoalLocation)).Length();
                extra += distance * 10.0;
            }
            switch (FUN_006a7e00(GetKeyForNode_006a94f0(), edgeData, triangle, extra, &neighbour))
            {
            case 0:
                SetNodeFleeCost(reinterpret_cast<SearchNode*>(neighbour), edgeData, triangle);
            case 1:
                neighbour->parentMesh = apNode->edgeData;
                neighbour->parentTriangle = apNode->triangle;
                neighbour->parentEdge = edge;
                apRetNodes->FUN_007cb2e0(neighbour);
                break;
            }
        }
    }
    return true;
}
