// fallout_shared/pathfinding/teleportdoorsearch.cpp: TeleportDoorSearch, DoorSearchInit (6 functions)

#include "teleportdoorsearch_decls.h"
// @fnv 0x006f3b00
// pdb: TeleportDoorSearch::IsGoalNode | TeleportDoorSearch.obj | retail, vtable slot, high
// pdb params: apNode
// pdb locals: pworlddata, pworld
bool TeleportDoorSearch::HasReachedGoal(const AStarNode<ParentSpaceNode, TeleportLink>* apNode)
{
    if (Restrictions == 3)
    {
        TESWorldSpace* w = apNode->world;
        PointerPairData* data = w ? w->GetWorldSpaceData() : 0;
        return apNode->exterior && data && data->a && data->b;
    }
    else
    {
        if (apNode->exterior != GoalNode)
            return false;
        if (apNode->cell != cell)
            return false;
        if (apNode->world != world)
            return false;
        return true;
    }
}
// @fnv 0x006f36d0
// pdb: TeleportDoorSearch::GetNodeConnections | TeleportDoorSearch.obj | retail, vtable slot, high
// pdb params: apNode, apRetNodes
// pdb locals: i, ikey, fdistToDoor, doorLock, ptelCell, bcanOpenLock, doorLocInThisSpace, bmustPick, fcost, pnode, pdoor, fdoorAdditionalCost
bool TeleportDoorSearch::CollectConnections(const AStarNode<ParentSpaceNode, TeleportLink>* apNode,
                                            BSSimpleArray<AStarNode<ParentSpaceNode, TeleportLink>*, 1024>* apRetNodes)
{
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&DoorList)->Clear(false);
    if (apNode->exterior)
        apNode->world->BuildTeleportDoorList(DoorList);
    else
        apNode->cell->AppendCellReferences(DoorList);
    if (DoorLockDisposition == 1 || DoorLockDisposition == 3 || pLockData)
    {
        // Local names and declaration order preserve MSVC9 stack-slot allocation.
        // a03 index, a06 lock penalty, a00 door, a08 result node.
        // a04 position, a02 locked, a01 cost, a07 destination cell, a05 unlock result.
        // b01 destination space, b02 lock, b00 distance.
        float a06;
        TESObjectREFR* a00;
        AStarNode<ParentSpaceNode, TeleportLink>* a08;
        // Reserve the position without calling NiPoint3's nontrivial default constructor.
        float a04[sizeof(NiPoint3) / sizeof(float)];
        bool a02;
        float a01;
        TESObjectCELL* a07;
        bool a05;
        unsigned int a03;
        for (a03 = 0; a03 < reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&DoorList)->GetSize(); ++a03)
        {
            a00 = reinterpret_cast<TESObjectREFR*>(reinterpret_cast<NiFormArray*>(&DoorList)->FUN_00877a30(a03));
            if (a00->GetDisabled())
                continue;
            void* b01 =
                reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320()
                    ? reinterpret_cast<void*>(reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320())
                    : reinterpret_cast<void*>(a00->GetExtraRadioData()->DoorTeleportData_GetTeleportCell());
            switch (Restrictions)
            {
            case 2:
                if (reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320())
                    continue;
                break;
            case 1:
                if (reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320() &&
                    reinterpret_cast<TESWorldSpace*>(
                        reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320()) != startWorld)
                    continue;
                break;
            }
            DoorAccessData b02(a00);
            a05 = b02.CanUnlockDoor(pLockData, a00, a02);
            a06 = 0.0f;
            if (!a05 || a02)
            {
                switch (DoorLockDisposition)
                {
                case 1:
                case 3:
                    break;
                case 2:
                    a06 = 409600.0f;
                    break;
                case 0:
                    continue;
                }
            }
            if (reinterpret_cast<TESObjectDOOR*>(a00->GetObjectReference())->IsTeleportDoor() && DoorLockDisposition != 3)
                a06 = 409600.0f;
            reinterpret_cast<NiPoint3&>(a04) = *static_cast<const TESObjectREFR*>(a00)->GetPos();
            float b00;
            if (reinterpret_cast<ActorMover*>(const_cast<AStarNode<ParentSpaceNode, TeleportLink>*>(apNode))
                    ->GetCurrentMoveModeType())
                b00 = static_cast<const NiPoint3&>(apNode->pos - reinterpret_cast<const NiPoint3&>(a04)).Length();
            else
                b00 = static_cast<const NiPoint3&>(StartLocation.FUN_005c3420() - reinterpret_cast<const NiPoint3&>(a04)).Length();
            if (fMaxDist != 0.0 && apNode->cost + b00 > fMaxDist)
                continue;
            a01 = apNode->cost + b00 + a06;
            a07 = a00->GetExtraRadioData()->DoorTeleportData_GetTeleportCell();
            switch (InsertOrUpdateNode(b01, a01, a08))
            {
            case 0:
                if (reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320())
                {
                    a08->exterior = true;
                    a08->cell = 0;
                    a08->world = reinterpret_cast<TESWorldSpace*>(
                        reinterpret_cast<ExtraLock*>(a00->GetExtraRadioData())->FUN_0043a320());
                }
                else
                {
                    a08->exterior = false;
                    a08->world = 0;
                    a08->cell = a00->GetExtraRadioData()->DoorTeleportData_GetTeleportCell();
                }
                a08->fitness = 1.0f;
            case 1:
                a08->door = a00;
                a08->pos = *reinterpret_cast<NiPoint3*>(
                    reinterpret_cast<QuestDialogueInfo*>(a00->GetExtraRadioData())->GetInfoArray());
                reinterpret_cast<BSSimpleArray<TESIdleForm*, 1024>*>(apRetNodes)->Add(reinterpret_cast<TESIdleForm*&>(a08));
            }
        }
    }
    return true;
}

// @fnv 0x006f3460
// pdb: TeleportDoorSearch::~TeleportDoorSearch | TeleportDoorSearch.obj | retail, upstream name already matches, high
TeleportDoorSearch::~TeleportDoorSearch()
{
}

struct FUN_00996840_shell
{
    unsigned int AStarNodeMap_GetBucketIndex(unsigned int);
};
struct AStarNodeTD
{
    float m_fPathingCostCur;
    char pad[0x2c];
    unsigned int uiKey;
    AStarNodeTD* pNext;
};
struct FUN_006f4340_shell
{
    AStarNodeTD* ProcessAndReturnValue_006f4340();
};
struct FUN_006f4430_shell
{
    void UnlinkFromList(AStarNodeTD*);
};

// @fnv 0x006f3e30
// pdb: AStarSearch<ParentSpaceNode,TeleportLink>::GetOrCreateAStarNode | TeleportDoorSearch.obj | debug, call graph, high
// pdb params: aiKey, afCost, aRetNode
// pdb locals: pBuckHead, pcurrent, pprev
int TeleportDoorSearch::InsertOrUpdateNode(void* aiKey, float afCost, AStarNode<ParentSpaceNode, TeleportLink>*& aRetNode)
{
    AStarNodeTD** pBucketHead = (AStarNodeTD**)((char*)this + 0x14) + reinterpret_cast<FUN_00996840_shell*>(reinterpret_cast<char*>(this) + 0x14)->AStarNodeMap_GetBucketIndex(reinterpret_cast<unsigned int>(aiKey));
    if (*pBucketHead)
    {
        if ((*pBucketHead)->uiKey == reinterpret_cast<unsigned int>(aiKey))
        {
            if ((*pBucketHead)->m_fPathingCostCur > afCost)
            {
                reinterpret_cast<AStarNodeTD*&>(aRetNode) = *pBucketHead;
                reinterpret_cast<FUN_006f4430_shell*>(reinterpret_cast<char*>(this) + 0x1ff4)->UnlinkFromList(reinterpret_cast<AStarNodeTD*&>(aRetNode));
                (reinterpret_cast<AStarNodeTD*&>(aRetNode))->m_fPathingCostCur = afCost;
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            AStarNodeTD* pcurrent;
            AStarNodeTD* pprev;
            pprev = *pBucketHead;
            pcurrent = (*pBucketHead)->pNext;
            while (pcurrent)
            {
                if (pcurrent->uiKey == reinterpret_cast<unsigned int>(aiKey))
                {
                    if (pcurrent->m_fPathingCostCur > afCost)
                    {
                        reinterpret_cast<AStarNodeTD*&>(aRetNode) = pcurrent;
                        reinterpret_cast<FUN_006f4430_shell*>(reinterpret_cast<char*>(this) + 0x1ff4)->UnlinkFromList(reinterpret_cast<AStarNodeTD*&>(aRetNode));
                        (reinterpret_cast<AStarNodeTD*&>(aRetNode))->m_fPathingCostCur = afCost;
                        return 1;
                    }
                    else
                    {
                        return 2;
                    }
                }
                pprev = pcurrent;
                pcurrent = pcurrent->pNext;
            }
        }
    }
    reinterpret_cast<AStarNodeTD*&>(aRetNode) = reinterpret_cast<FUN_006f4340_shell*>(reinterpret_cast<char*>(this) + 4)->ProcessAndReturnValue_006f4340();
    (reinterpret_cast<AStarNodeTD*&>(aRetNode))->uiKey = reinterpret_cast<unsigned int>(aiKey);
    (reinterpret_cast<AStarNodeTD*&>(aRetNode))->m_fPathingCostCur = afCost;
    (reinterpret_cast<AStarNodeTD*&>(aRetNode))->pNext = *pBucketHead;
    *pBucketHead = reinterpret_cast<AStarNodeTD*&>(aRetNode);
    return 0;
}

struct SearchState
{
    bool exterior;
    void* world;
    void* cell;
};
struct ResultSub
{
    int unk00, unk04, unk08, unk0c;
};
struct SearchResult
{
    int unk00, unk04, unk08, unk0c;
    ResultSub sub;
    NiPoint3 start, finish;
};
// Local extension for methods not yet declared by the shared search class.
struct DoorSearchInit : TeleportDoorSearch
{
    void AStarSearch_ParentSpaceNode_TeleportLink_AddStartNode(void*, SearchState*, float);
    bool FindPath(SearchResult*, ResultSub*, bool);
    bool TeleportDoorSearch_BuildNodePath(PathingLocation*, PathingLocation*, SearchResult*, int, float, void*, int);
};
// @fnv 0x006f34e0
// src: XBOX_RETAIL_PDB 0x006f34e0
// pdb: TeleportDoorSearch::BuildNodePath | TeleportDoorSearch.obj | retail, call graph, high
// pdb params: aStartLocation, aGoalLocation, apRetPath, aRestrictions, afMaxDist, apLockData, aDisposition
// pdb locals: istartKey
bool DoorSearchInit::TeleportDoorSearch_BuildNodePath(PathingLocation* aStartLocation, PathingLocation* aGoalLocation, SearchResult* apRetPath, int aRestrictions,
                                    float afMaxDist, void* apLockData, int aDisposition)
{
    StartLocation = *aStartLocation;
    void* a;
    if (aStartLocation->FUN_00441110())
    {
        reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->world = aStartLocation->FUN_00441110();
        reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->exterior = true;
        reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->cell = 0;
        a = reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->world;
    }
    else if (aStartLocation->FUN_006dd4f0())
    {
        reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->cell = aStartLocation->FUN_006dd4f0();
        reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->exterior = false;
        reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->world = 0;
        a = reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->cell;
    }
    else
        return false;
    Restrictions = aRestrictions;
    if (reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058)->world && aRestrictions == 2)
        return false;
    fMaxDist = afMaxDist;
    DoorLockDisposition = aDisposition;
    if (Restrictions != 3)
    {
        if (aGoalLocation->FUN_00441110())
        {
            world = aGoalLocation->FUN_00441110();
            GoalNode = true;
            cell = 0;
        }
        else if (aGoalLocation->FUN_006dd4f0())
        {
            cell = aGoalLocation->FUN_006dd4f0();
            GoalNode = false;
            world = 0;
        }
    }
    pLockData = static_cast<const PathingActorData*>(apLockData);
    apRetPath->start = aStartLocation->FUN_005c3420();
    apRetPath->finish = aGoalLocation->FUN_005c3420();
    AStarSearch_ParentSpaceNode_TeleportLink_AddStartNode(a, reinterpret_cast<SearchState*>(reinterpret_cast<char*>(this) + 0x2058), 1.0f);
    if (!FindPath(apRetPath, &apRetPath->sub, true))
        return false;
    return true;
}
