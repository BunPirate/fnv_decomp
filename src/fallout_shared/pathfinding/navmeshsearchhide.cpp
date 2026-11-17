
// src/fallout_shared/pathfinding/navmeshsearchhide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshsearchhide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/NiPoint3.h"
#include "../../../include/NavMesh.h"
#include "../../../include/NavMeshTriangle.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingAvoidNodeArray.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESObjectDOOR.h"
#include "../../../include/NavMeshSearch.h"
#include "../../../include/NavMeshSearchHide.h"

void* _Deallocate(void*);

// Calls FUN_006a9d60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x006a9d30
// pdb: NavMeshSearchHide::`scalar deleting destructor' | NavMeshSearchHide.obj | retail, vtable slot, high
void* NavMeshSearchHide::DestroyIfFlagged(unsigned int flags)
{
    NavMeshSearchHide_dtor();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void __cdecl BSClamp_float(float* pfValue, float fMin, float fScaledValue);

struct A9F60Entry
{
    int unk00;
    float m_fScore;
    NavMesh* m_pMesh;
    unsigned short m_usNode;
    unsigned short unk0E;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

// @fnv 0x006a9f60
// src: XBOX_DEBUG_PDB 0x006a9f60
// pdb: NavMeshSearchHide::SetNodeData | NavMeshSearchHide.obj | debug, call graph, high
// pdb params: apNode, apNavMesh, aiTriangle
// pdb locals: avoidVector, fcost, center
void NavMeshSearchHide::SetNodeData(SearchNode* apNode, NavMesh* apNavMesh, unsigned short aiTriangle)
{
    reinterpret_cast<A9F60Entry*>(apNode)->m_pMesh = apNavMesh;
    reinterpret_cast<A9F60Entry*>(apNode)->m_usNode = aiTriangle;
    NiPoint3 kPos4 = apNavMesh->FUN_00558220(aiTriangle);
    reinterpret_cast<A9F60Entry*>(apNode)->m_fVectorY = kPos4.x;
    reinterpret_cast<A9F60Entry*>(apNode)->m_fVectorZ = kPos4.y;
    reinterpret_cast<A9F60Entry*>(apNode)->m_fScalarPart = kPos4.z;
    NiPoint3 kDiff = kPos4 - AvoidNodeCenter;
    float fScore6 = fDistanceUpperBound - kDiff.Length();
    BSClamp_float(&fScore6, 0.0f, fDistanceUpperBound);
    reinterpret_cast<A9F60Entry*>(apNode)->m_fScore = fScore6;
}

struct NavMeshTriRef
{
    NavMesh* m_pMesh;
    unsigned short m_usTri;
    NiPoint3 FastNavMeshTriLocation_GetLocation();
};

struct NavSearchNodeInfo
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
    int FUN_0045cd60();
};

struct NavSearchNode
{
    char pad00[0x1c];
    NavMesh* m_pMesh;
    unsigned short m_usTri;
    int m_iSide;
};

struct NavSearchNodeList
{
    void FUN_007cb2e0(NavSearchNode** ppNode);
};

struct FloatSetting
{
    float* Setting_Float_00403e20();
};
extern FloatSetting g_setting_011d6ef0;

extern "C" TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int auiFormId);

struct DoorCheck
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    DoorCheck(TESForm* pkForm);
    ~DoorCheck();
    bool FUN_00502450(void* apActorLockData, TESForm* apDoorRef, bool* abOutMustPick);
};

float __cdecl BSMAX_00404010(float fA, float fB);

// @fnv 0x006aa000
// pdb: NavMeshSearchHide::GetNodeConnections | NavMeshSearchHide.obj | retail, vtable slot, high
// pdb params: apNode, apRetNodes
// pdb locals: aCurrentLocation, i, potherMesh, iotherEdge, usotherTri, fpositionalPenalty, fdoorMultiplier, fdistToThreat, pextra, toThreat, fcost, pnode, ftoThreatLength, nodeCenter, fnodescore, fdirectionalPenalty, nodeToNode, fnodeToNodeLength, doorID, pdoor, doorLock, bmustPick, lockData
bool NavMeshSearchHide::ExpandNeighbors(NavSearchNodeInfo* apNode, NavSearchNodeList* apRetNodes)
{
    NiPoint3 kPosX = apNode->FUN_0045cd60() ? apNode->m_kRef.FastNavMeshTriLocation_GetLocation() : reinterpret_cast<PathingRequest*>(m_pActor)->GetOffsetC().FUN_005c3420();
    for (int i9 = 0; i9 < 3; i9++)
    {
        NavMesh* pMesh5;
        unsigned short usTriZ;
        int iUnkZ;
        if (apNode->m_kRef.m_pMesh->FindAdjacentEdge(apNode->m_kRef.m_usTri, i9, &pMesh5, &usTriZ, &iUnkZ))
        {
            int* pEdgeWork = reinterpret_cast<int*>(apNode->m_kRef.m_pMesh->GetEdgeExtraInfo(apNode->m_kRef.m_usTri, i9));
            if (pEdgeWork && *pEdgeWork == 1)
                continue;
            float fMultY = 1.0f;
            if (pMesh5->FUN_005582f0(usTriZ)->FUN_00691140(0x1000))
            {
                if (reinterpret_cast<PathingRequest*>(m_pActor)->FUN_0073cb80())
                    continue;
                else
                {
                    unsigned int uiFormIDOut = *pMesh5->FUN_00699af0(usTriZ);
                    TESForm* pForm2 = TESForm_GetFormByNumericID(uiFormIDOut);
                    if (pForm2)
                    {
                        DoorCheck kCheck_2(pForm2);
                        void* pSource_2 = reinterpret_cast<PathingRequest*>(unk2058)->GetActorLockData();
                        bool bResultZ;
                        if (!kCheck_2.FUN_00502450(pSource_2, pForm2, &bResultZ))
                            continue;
                        if (static_cast<TESObjectDOOR*>(static_cast<TESObjectREFR*>(pForm2)->GetObjectReference())->IsTeleportDoor())
                            fMultY = 100.0f;
                    }
                }
            }
            if (reinterpret_cast<PathingRequest*>(m_pActor)->GetFloatAtOffset68() > *g_setting_011d6ef0.Setting_Float_00403e20() &&
                pMesh5->FUN_005582f0(usTriZ)->FUN_00691140(0x10))
                continue;
            NiPoint3 kCenterTmp = pMesh5->FUN_00558220(usTriZ);
            NiPoint3 kDeltaW = kCenterTmp.SubtractIntoVector(kPosX);
            float fCost_ = kDeltaW.NiPoint3_XYLength() * fMultY + apNode->m_fCost;
            float fExtraZ = 0.0f;
            if (reinterpret_cast<const PathingRequest*>(m_pActor)->GetString())
                fExtraZ = reinterpret_cast<const PathingRequest*>(m_pActor)->GetString()->GetAvoidanceAtPoint(kCenterTmp);
            float fDist6 = kCenterTmp.SubtractIntoVector(ThreatLocation).NiPoint3_XYLength();
            float fNearOut = 1.0f - fDist6 / 512.0;
            fExtraZ += BSMAX_00404010(fNearOut, 0.0f);
            NiPoint3 kToTargetWork = ThreatLocation.SubtractIntoVector(kPosX);
            float fDot_2 = kToTargetWork.DotProduct(kDeltaW);
            float fLenA_2 = kToTargetWork.FUN_00457990();
            float fLenBY = kDeltaW.FUN_00457990();
            if (fLenA_2 == 0.0 || fLenBY == 0.0)
                fDot_2 = 0.0f;
            else
                fDot_2 = fDot_2 / (fLenA_2 * fLenBY);
            fExtraZ += BSMAX_00404010(fDot_2, 0.0f);
            fCost_ = (1.0f + fExtraZ) * fCost_;
            NavSearchNode* pNode;
            switch (FUN_006a7e00(GetKeyForNode_006a94f0(reinterpret_cast<NavMeshStandIn*>(pMesh5), usTriZ, fCost_, &pNode)))
            {
            case 0:
                SetNodeData(reinterpret_cast<SearchNode*>(pNode), pMesh5, usTriZ);
            case 1:
                pNode->m_pMesh = apNode->m_kRef.m_pMesh;
                pNode->m_usTri = apNode->m_kRef.m_usTri;
                pNode->m_iSide = i9;
                apRetNodes->FUN_007cb2e0(&pNode);
                break;
            }
        }
    }
    return true;
}

// PathingRequestHide accessors missing from its shared header: 0x00984230 returns this+0xB0; 0x00885BD0 reads +0xD8.
struct HideRequestTargetAccess
{
    PathingLocation* hkpAabbPhantom_getAabb();
    float FUN_00885bd0();
};

struct InfoF
{
    NavMesh* m_pMesh;
    unsigned short m_usTri;
    unsigned short unk06;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    NiPoint3* FastNavMeshTriLocation_GetLocation(NiPoint3* pOut);
};

struct ParamX
{
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
};

extern NiPoint3 DAT_011f426c;

// @fnv 0x006a9d80
// src: XBOX_DEBUG_PDB 0x006a9d80
// pdb: NavMeshSearchHide::BuildNodePath | NavMeshSearchHide.obj | debug, call graph, high
// pdb params: apRequest, aStartNode, apReturnNodeArray, apReturnLinkArray
// pdb locals: startPoint, startNode, avoidVector, fcost, center
int NavMeshSearchHide::BuildNodePath(ActorX* apRequest, TriRef20* aStartNode, ParamX* apReturnNodeArray, int apReturnLinkArray)
{
    unk2058 = reinterpret_cast<int>(apRequest);
    m_pActor = apRequest;
    StartNode = *aStartNode;

    NiPoint3 kActorPos5 = reinterpret_cast<PathingRequest*>(apRequest)->GetOffsetC().FUN_005c3420();
    AvoidNodeCenter = DAT_011f426c;
    fDistanceUpperBound = 0.0f;
    if (reinterpret_cast<const PathingRequest*>(m_pActor)->GetString())
    {
        fDistanceUpperBound = reinterpret_cast<const PathingRequest*>(m_pActor)->GetString()->GetAvoidCost(kActorPos5, AvoidNodeCenter);
    }

    InfoF kInfo3;
    kInfo3.m_pMesh = reinterpret_cast<NavMesh*>(aStartNode->m_pMesh);
    kInfo3.m_usTri = aStartNode->m_usTri;
    NiPoint3 kTmp_2 = kInfo3.m_pMesh->FUN_00558220(kInfo3.m_usTri);
    kInfo3.m_fVectorY = kTmp_2.x;
    kInfo3.m_fVectorZ = kTmp_2.y;
    kInfo3.m_fScalarPart = kTmp_2.z;

    // This output buffer is populated by FUN_006a6eb0 without default construction.
    float kTriPt2[3];
    NiPoint3 kDiff = kInfo3.FastNavMeshTriLocation_GetLocation(reinterpret_cast<NiPoint3*>(kTriPt2))->SubtractIntoVector(AvoidNodeCenter);
    float fVal6 = fDistanceUpperBound - kDiff.FUN_00457990();
    BSClamp_float(&fVal6, 0.0f, fDistanceUpperBound);

    FUN_006a7c90(GetKeyForNode_006a94f0(reinterpret_cast<MeshX*>(kInfo3.m_pMesh), kInfo3.m_usTri), &kInfo3, fVal6);

    ThreatLocation = reinterpret_cast<HideRequestTargetAccess*>(m_pActor)->hkpAabbPhantom_getAabb()->FUN_005c3420();

    FUN_006a7d60(apReturnNodeArray, apReturnLinkArray, 1);
    return !apReturnNodeArray->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
}

extern const double DAT_01012060;

bool __cdecl NavMeshMath_Get2DBaryCentricCoord(const NiPoint3& aV0, const NiPoint3& aV1, const NiPoint3& aV2, const NiPoint3& aLoc,
                          NiPoint3* aCoord);

struct NavInfo6aa4
{
    bool HasFlags();
    void GetTripleShorts(unsigned short* pusA, unsigned short* pusB, unsigned short* pusC);
    unsigned short NavMeshTriangle_GetEdgeCover(unsigned short aiEdge);
};

struct NavList6aa4
{
    NavMesh* m_pkMesh;
    NavInfo6aa4* NavMeshSearchNode_GetTriangle();
};

struct NavData6aa4
{
    float m_fCost;
    int unk04;
    NavMeshTriRef m_kRef;
    NavList6aa4* FUN_00413f40();
};

// @fnv 0x006aa470
// src: XBOX_PDB 0x006aa470
// pdb: NavMeshSearchHide::IsGoalNode | NavMeshSearchHide.obj | retail, upstream name already matches, high
// pdb params: apNode
// pdb locals: v0, barycentricCoords, flength, fscore, parentNodeData, v2, bproperSide, nodeCenter, v1, pmesh, ptriangle
bool NavMeshSearchHide::IsGoalNode(NavData6aa4* apNode)
{
    NavList6aa4* pkList = apNode->FUN_00413f40();
    NavInfo6aa4* pkInfo7 = pkList->NavMeshSearchNode_GetTriangle();
    if (!pkInfo7->HasFlags())
        return false;

    NiPoint3 kPos = apNode->m_kRef.FastNavMeshTriLocation_GetLocation();
    float aFLength = ThreatLocation.SubtractIntoVector(kPos).NiPoint3_XYLength();
    if (aFLength < reinterpret_cast<HideRequestTargetAccess*>(m_pkActor)->FUN_00885bd0())
        return false;

    NavMesh* pkMesh6 = pkList->m_pkMesh;
    unsigned short usA5, usB, usC;
    pkInfo7->GetTripleShorts(&usA5, &usB, &usC);
    // FUN_006815c0 initializes this point storage.
    float kOut3[3];
    reinterpret_cast<NiPoint3*>(kOut3)->FUN_006815c0();
    bool bFound8 = false;
    NavMeshMath_Get2DBaryCentricCoord(pkMesh6->GetVertex_0068f0a0(usA5), pkMesh6->GetVertex_0068f0a0(usB), pkMesh6->GetVertex_0068f0a0(usC), ThreatLocation,
                 reinterpret_cast<NiPoint3*>(kOut3));
    if (kOut3[0] < DAT_01012060 && pkInfo7->NavMeshTriangle_GetEdgeCover(1) > 0)
        bFound8 = true;
    else if (kOut3[2] < DAT_01012060 && pkInfo7->NavMeshTriangle_GetEdgeCover(0) > 0)
        bFound8 = true;
    if (!bFound8)
        return false;

    float fDist_2 = 0.0f;
    if (reinterpret_cast<const PathingRequest*>(m_pkActor)->GetString())
        fDist_2 = reinterpret_cast<const PathingRequest*>(m_pkActor)->GetString()->GetAvoidanceAtPoint(kPos);
    return fDist_2 <= DAT_01012060;
}

extern int DAT_0106b7dc;

// @fnv 0x006a9d60
// src: XBOX_DEBUG_PDB 0x006a9d60
// pdb: NavMeshSearchHide::~NavMeshSearchHide | NavMeshSearchHide.obj | debug, call graph, high
void NavMeshSearchHide::NavMeshSearchHide_dtor()
{
    *reinterpret_cast<void**>(this) = &DAT_0106b7dc;
    NavMeshSearch::FUN_006a6b00();
}
