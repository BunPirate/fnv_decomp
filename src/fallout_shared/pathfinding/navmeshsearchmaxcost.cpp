#include "../../../include/NavMeshSearchMaxCost.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/PathBuilderDetailedPathInfos.h"
// In-class bodies of the former Point stand-in.
__forceinline NiPoint3::NiPoint3(float px, float py, float pz) : x(px), y(py), z(pz)
{}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/DoorAccessData.h"

// src/fallout_shared/pathfinding/navmeshsearchmaxcost.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchmaxcost.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* __cdecl _Deallocate(void*);
extern void* const NavMeshSearchMaxCost_vftable[];

// Destroys the search, frees this when flags has bit 1 set, and returns this.
// @fnv 0x006ab450
// pdb: NavMeshSearchMaxCost::`scalar deleting destructor' | NavMeshSearchMaxCost.obj | retail, vtable slot, high
void* NavMeshSearchMaxCost::Destroy(unsigned int flags)
{
    NavMeshSearchMaxCost_dtor();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x006abb90
int __thiscall NavMeshSearchMaxCost::GetField2048()
{
    return unk2048;
}

// @fnv 0x006abb60
// src: XBOX_PDB 0x006abb60
// pdb: NavMeshSearchMaxCost::IsGoalNode | NavMeshSearchMaxCost.obj | debug, vtable slot, medium
// pdb params: apNode
bool __thiscall NavMeshSearchMaxCost::IsGoalNode_006abb60(const SearchNode* apNode)
{
    if (!hasGoal)
        return false;
    else
        return NavMeshSearch::HasReachedGoal(apNode);
}

// pdb: structure ScrapHeapBuffer, size 0x8 (here 0x1), 2 members
struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
};
extern unsigned int DAT_010a2720;
struct FUN_006abcb0_shell
{
    char _pad[16];
    ScrapHeapBuffer* heap;
    void* __thiscall BSScrapArray_NavMeshSearchNode_1024_Allocate(unsigned int);
};
// Allocates n blocks of 0x14 bytes from the heap and returns the pointer.
// @fnv 0x006abcb0
// src: COMMUNITY 0x006abcb0
// pdb: BSScrapArray<NavMeshSearchNode,1024>::_Allocate | NavMeshSearchMaxCost.obj | debug, vtable slot, medium
// pdb params: aiSizeInItem
// pdb locals: pnewBuffer
void* __thiscall FUN_006abcb0_shell::BSScrapArray_NavMeshSearchNode_1024_Allocate(unsigned int auiCount)
{
    void* tmp;
    tmp = heap->Allocate(auiCount * 0x14, DAT_010a2720);
    return tmp;
}

namespace fnv_006abce0 {
struct ScrapHeapBuffer
{
    void* __thiscall Allocate(unsigned int, unsigned int);
    void __thiscall Deallocate(void*);
};
// Exe 0x006abce0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct NavmeshsearchmaxcostOffset08View
{
    unsigned int __thiscall GetFlags();
};
extern unsigned int DAT_010a2720;
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_006abce0_shell
{
    char _pad[0x10];
    ScrapHeapBuffer* heap;
    void* __thiscall BSScrapArray_NavMeshSearchNode_1024_Reallocate(void*, unsigned int);
};
// Allocates count*0x14 bytes, copies GetFlags()*0x14 bytes from src into it, frees src, and returns the new buffer.
// @fnv 0x006abce0
// src: COMMUNITY 0x006abce0
// pdb: BSScrapArray<NavMeshSearchNode,1024>::_Reallocate | NavMeshSearchMaxCost.obj | retail, vtable slot, high
// pdb params: apBuffer, aiNewSizeInItem
// pdb locals: pnewBuffer
void* __thiscall FUN_006abce0_shell::BSScrapArray_NavMeshSearchNode_1024_Reallocate(void* apBuffer, unsigned int aiNewSizeInItem)
{
    void* dst = heap->Allocate(aiNewSizeInItem * 0x14, DAT_010a2720);
    __memcpy(dst, apBuffer, ((NavmeshsearchmaxcostOffset08View*)this)->GetFlags() * 0x14);
    heap->Deallocate(apBuffer);
    return dst;
}
}  // namespace fnv_006abce0

extern int DAT_0106b8c8;

struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
};

struct FUN_006abdc0_shell
{
    int* p;
    void __thiscall ResetVirtualTableAndClear_006abdc0();
};

// @fnv 0x006abdc0
// src: GUESS 0x006abdc0 (confidence: medium)
// pdb: BSSimpleArray<NavMeshSearchLink,1024>::~BSSimpleArray<NavMeshSearchLink,1024> | NavMeshSearchMaxCost.obj | debug, call graph (shared callers), medium
void __thiscall FUN_006abdc0_shell::ResetVirtualTableAndClear_006abdc0()
{
    p = &DAT_0106b8c8;
    ((GlobalObject_00869f00*)this)->Clear(true);
}

namespace fnv_006abde0 {
struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
};
struct FUN_006abdc0
{
    virtual ~FUN_006abdc0();
};
struct FUN_006abde0 : FUN_006abdc0
{
    virtual ~FUN_006abde0();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006abde0
// pdb: BSScrapArray<NavMeshSearchLink,1024>::~BSScrapArray<NavMeshSearchLink,1024> | NavMeshSearchMaxCost.obj | retail, call graph, medium
FUN_006abde0::~FUN_006abde0()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_006abde0

namespace fnv_006abc30 {
struct GlobalObject_00869f00
{
    void __thiscall Clear(bool);
};
extern void* DAT_0106b8a0;

struct FUN_006abc30_shell
{
    void __thiscall SetVtableAndProcessState_006abc30();
};

// @fnv 0x006abc30
// src: GUESS 0x006abc30 (confidence: low)
void __thiscall FUN_006abc30_shell::SetVtableAndProcessState_006abc30()
{
    *(void**)this = &DAT_0106b8a0;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_006abc30

struct FUN_006abc30_Class
{
    virtual ~FUN_006abc30_Class();
};
struct FUN_006abc50 : FUN_006abc30_Class
{
    ~FUN_006abc50();
};
// @fnv 0x006abc50
// pdb: BSScrapArray<NavMeshSearchNode,1024>::~BSScrapArray<NavMeshSearchNode,1024> | NavMeshSearchMaxCost.obj | retail, call graph, medium
FUN_006abc50::~FUN_006abc50()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct FUN_006abf60
{
    virtual ~FUN_006abf60();
    FUN_006abf60();
    int unk04;
    int unk08;
    int unk0c;
};
struct FUN_00aa42e0_shell
{
    void* __thiscall FUN_00aa42e0();
};
FUN_00aa42e0_shell* __cdecl MemoryManager_Instance();
struct FUN_006abbb0 : FUN_006abf60
{
    void* unk10;
    FUN_006abbb0();
    virtual ~FUN_006abbb0();
    void __thiscall BSSimpleArray_WeaponData_1024_InitialSetup(int, int);
};
// Initializes unk10 from FUN_00401020()->FUN_00aa42e0() and calls FUN_009a3d00(0, 0).
// @fnv 0x006abbb0
// pdb: BSScrapArray<NavMeshSearchNode,1024>::BSScrapArray<NavMeshSearchNode,1024> | NavMeshSearchMaxCost.obj | debug, call graph, medium
FUN_006abbb0::FUN_006abbb0()
{
    unk10 = MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_WeaponData_1024_InitialSetup(0, 0);
}

namespace fnv_006abd40 {
void* __cdecl MemoryManager_Instance();

struct NavMeshSearchHeapObj
{
    void* FUN_00aa42e0();
};

struct NavMeshSearchGraphBase
{
    NavMeshSearchGraphBase();
    virtual void unk00();
    ~NavMeshSearchGraphBase();
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_006abd40 : NavMeshSearchGraphBase
{
    void* m_10;

    FUN_006abd40();
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(unsigned int a, unsigned int b);
};

// @fnv 0x006abd40
// pdb: BSScrapArray<NavMeshSearchLink,1024>::BSScrapArray<NavMeshSearchLink,1024> | NavMeshSearchMaxCost.obj | debug, call graph, high
FUN_006abd40::FUN_006abd40()
{
    m_10 = ((NavMeshSearchHeapObj*)MemoryManager_Instance())->FUN_00aa42e0();
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(0, 0);
}
}  // namespace fnv_006abd40

struct NavMeshSearchLocation
{
    NavMesh* m_pLocationNavMesh;
    unsigned short m_usTriangleID;
    NiPoint3 kPosition;
    NiPoint3* FastNavMeshTriLocation_GetLocation(NiPoint3* apResult);
    NiPoint3 FastNavMeshTriLocation_GetLocation();
};
// @fnv 0x006ab4a0
// pdb: NavMeshSearchMaxCost::BuildNodePath | NavMeshSearchMaxCost.obj | debug, object-file gap fill, medium
// pdb params: apRequest, aStartNode, aOptimalLocation, apReturnNodeArray, apReturnLinkArray
// pdb locals: bresult, spgoalMesh, usgoalTri, center
bool NavMeshSearchMaxCost::StartSearch(int aiSearchType, NavMeshSearchLocation* apStart, PathingLocation* apGoal,
                                     PathBuilderDetailedPathInfos* apInfos, PathBuilderDetailedPathInfos* apAltInfos)
{
    (*(NavMeshSearchLocation*)&StartNode) = *apStart;
    unk2058 = aiSearchType;
    apInfos->Clear(false);
    apAltInfos->Clear(false);
    AStarSearch_NavMeshSearchNode_NavMeshSearchLink_ClearSearchData();
    if (!apGoal->PathingLocation_QUnused() && apGoal->FUN_006dd6f0(false))
    {
        NavMeshPtr spGoalNavMesh;
        unsigned short m_usTriangleID;
        if (apGoal->FUN_006dd640(&spGoalNavMesh, &m_usTriangleID))
        {
            (*(NavMeshSearchLocation*)&GoalNode).m_pLocationNavMesh = spGoalNavMesh;
            (*(NavMeshSearchLocation*)&GoalNode).m_usTriangleID = m_usTriangleID;
            float kGoalPos[3];
            (*(NavMeshSearchLocation*)&GoalNode).m_pLocationNavMesh->FUN_00558220((NiPoint3*)kGoalPos, (*(NavMeshSearchLocation*)&GoalNode).m_usTriangleID);
            (*(NavMeshSearchLocation*)&GoalNode).kPosition.x = kGoalPos[0];
            (*(NavMeshSearchLocation*)&GoalNode).kPosition.y = kGoalPos[1];
            (*(NavMeshSearchLocation*)&GoalNode).kPosition.z = kGoalPos[2];
            bHasGoal = true;
        }
    }
    {
        float kStartPos[3];
        float kTmpGoalPos[3];
        FUN_006a7c90(GetKeyForNode_006a94f0(apStart->m_pLocationNavMesh, apStart->m_usTriangleID), apStart,
                     (*(*(NavMeshSearchLocation*)&StartNode).FastNavMeshTriLocation_GetLocation((NiPoint3*)kStartPos) - *(*(NavMeshSearchLocation*)&GoalNode).FastNavMeshTriLocation_GetLocation((NiPoint3*)kTmpGoalPos)).Length());
    }
    bool bFoundPath = FUN_006a7d60(apInfos, apAltInfos, false);
    return bFoundPath;
}

struct Mesh
{
    NiPoint3 Center(unsigned short);
};
struct Location
{
    Mesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    float x, y, z;
    NiPoint3 Center();
};
struct OpenSet
{
    int a, b, c, d, e;
    OpenSet();
    ~OpenSet();
};
struct ClosedSet
{
    int a, b, c, d, e;
    ClosedSet();
    ~ClosedSet();
};
struct Node
{
    int a, b;
    Location location;
};
// Sets start and goal locations from mesh centers, runs the search, and returns the fallback point or result center.
// @fnv 0x006ab670
// pdb: NavMeshSearchMaxCost::FindClosestPoint | NavMeshSearchMaxCost.obj | debug, object-file gap fill, medium
// pdb params: aStartLocation, aStartNode, aGoalLocation, aGoalNode, afMaxDist
// pdb locals: nodes, links, center
NiPoint3 NavMeshSearchMaxCost::FindPath(int unused, Location* initial, NiPoint3* fallback, Location* target, float cost)
{
    (*(Location*)&StartNode).mesh = initial->mesh;
    (*(Location*)&StartNode).triangle = initial->triangle;
    NiPoint3 center = (*(Location*)&StartNode).mesh->Center((*(Location*)&StartNode).triangle);
    (*(Location*)&StartNode).x = center.x;
    (*(Location*)&StartNode).y = center.y;
    (*(Location*)&StartNode).z = center.z;
    Add(Index((*(Location*)&StartNode).mesh, (*(Location*)&StartNode).triangle), &(*(Location*)&StartNode), ((*(Location*)&StartNode).Center() - (*(Location*)&GoalNode).Center()).Length());
    if (target->mesh || target->triangle != 0xffff)
    {
        hasGoal = true;
        (*(Location*)&GoalNode).mesh = target->mesh;
        (*(Location*)&GoalNode).triangle = target->triangle;
        center = (*(Location*)&GoalNode).mesh->Center((*(Location*)&GoalNode).triangle);
        (*(Location*)&GoalNode).x = center.x;
        (*(Location*)&GoalNode).y = center.y;
        (*(Location*)&GoalNode).z = center.z;
    }
    else
    {
        hasGoal = false;
    }
    fMaxDist = cost;
    OpenSet open;
    ClosedSet closed_2;
    if (Run(&open, &closed_2, 0))
        return *fallback;
    else
        return Result()->location.Center();
}

namespace fnv_006ab8e0 {
struct EdgeExtraInfo
{
    int type;
};
// NavMeshTriangleView: unit-local view (declares only what 0x006ab8e0 calls), not the shared NavMeshTriangle; renamed so no local type keeps the shared name
struct NavMeshTriangleView
{
    bool FUN_00691140(unsigned int);
};
}  // namespace fnv_006ab8e0

// NavMeshAStarNode: unit-local stand-in for the A* search node (AStarNode<NavMeshSearchNode,NavMeshSearchLink>; src: XBOX_PDB), not a NavMeshTriangleReference: 0x006ab8e0 ExpandNeighborNodes reads cost at +0 and the location at +8, writes the parent fields at +0x1c..+0x24
struct NavMeshAStarNode
{
    float cost;
    unsigned int unk04;
    NavMeshSearchLocation location;
    NavMesh* parentMesh;
    unsigned short parentTriangle;
    unsigned short unk22;
    int parentEdge;
};
namespace fnv_006ab8e0 {
struct DoorBase
{
    bool FUN_00518000();
};
struct Door
{
    DoorBase* BGSSaveFormBuffer_GetForm();
};
Door* __cdecl TESForm_GetFormByNumericID(unsigned int);
}  // namespace fnv_006ab8e0

struct NodeOutput
{
    unsigned int FUN_007cb2e0(NavMeshTriangleReference*&);
};

// @fnv 0x006ab8e0
// pdb: NavMeshSearchMaxCost::GetNodeConnections | NavMeshSearchMaxCost.obj | retail, vtable slot, high
// pdb params: apNode, apRetNodes
// pdb locals: i, potherMesh, iotherEdge, usotherTri, pextra, fcost, pnode, nodeCenter, doorID, pdoor, doorLock, bmustPick, lockData
bool NavMeshSearchMaxCost::ExpandNeighborNodes(NavMeshTriangleReference* apNode, NodeOutput* apRetNodes)
{
    using namespace fnv_006ab8e0;
    for (int i = 0; i < 3; ++i)
    {
        NavMesh* mesh;
        unsigned short triangle;
        int linked;
        if (reinterpret_cast<NavMeshAStarNode*>(apNode)->location.m_pLocationNavMesh->FindAdjacentEdge(reinterpret_cast<NavMeshAStarNode*>(apNode)->location.m_usTriangleID, i, &mesh, &triangle, &linked))
        {
            fnv_006ab8e0::EdgeExtraInfo* edge = (fnv_006ab8e0::EdgeExtraInfo*)reinterpret_cast<NavMeshAStarNode*>(apNode)->location.m_pLocationNavMesh->GetEdgeExtraInfo(reinterpret_cast<NavMeshAStarNode*>(apNode)->location.m_usTriangleID, i);
            if (edge && edge->type == 1)
                continue;
            NiPoint3 center = mesh->FUN_00558220(triangle);
            float cost = (center - reinterpret_cast<NavMeshAStarNode*>(apNode)->location.FastNavMeshTriLocation_GetLocation()).NiPoint3_XYLength() + reinterpret_cast<NavMeshAStarNode*>(apNode)->cost;
            if (cost > fMaxDist)
                continue;
            if (((fnv_006ab8e0::NavMeshTriangleView*)mesh->FUN_005582f0(triangle))->FUN_00691140(0x1000))
            {
                if (((PathingRequest*)unk2058)->FUN_0073cb80())
                {
                    continue;
                }
                else
                {
                    unsigned int door = *mesh->FUN_00699af0(triangle);
                    Door* doorId = TESForm_GetFormByNumericID(door);
                    if (doorId)
                    {
                        const PathingActorData* actor;
                        bool unlocked;
                        {
                            DoorAccessData lock(reinterpret_cast<TESObjectREFR*>(doorId));
                            actor = ((PathingRequest*)unk2058)->GetActorLockData();
                            if (!lock.CanUnlockDoor(actor, reinterpret_cast<TESObjectREFR*>(doorId), unlocked))
                                continue;
                            if (doorId->BGSSaveFormBuffer_GetForm()->FUN_00518000())
                                continue;
                        }
                    }
                }
            }
            NavMeshTriangleReference* nodeA;
            switch (FUN_006a7e00(GetKeyForNode_006a94f0(mesh, triangle), cost, &nodeA))
            {
            case 0:
                SetNodeData(nodeA, mesh, triangle);
            case 1:
                reinterpret_cast<NavMeshAStarNode*>(nodeA)->parentMesh = reinterpret_cast<NavMeshAStarNode*>(apNode)->location.m_pLocationNavMesh;
                reinterpret_cast<NavMeshAStarNode*>(nodeA)->parentTriangle = reinterpret_cast<NavMeshAStarNode*>(apNode)->location.m_usTriangleID;
                reinterpret_cast<NavMeshAStarNode*>(nodeA)->parentEdge = i;
                apRetNodes->FUN_007cb2e0(nodeA);
                break;
            }
        }
    }
    return true;
}
// This cleanup entry calls FUN_006a6b00 rather than the shared base destructor.

// @fnv 0x006ab480
// src: XBOX_DEBUG_PDB 0x006ab480
// pdb: NavMeshSearchMaxCost::~NavMeshSearchMaxCost | NavMeshSearchMaxCost.obj | debug, call graph (shared callers), high
void NavMeshSearchMaxCost::NavMeshSearchMaxCost_dtor()
{
    *(void* const**)this = NavMeshSearchMaxCost_vftable;
    FUN_006a6b00();
}
