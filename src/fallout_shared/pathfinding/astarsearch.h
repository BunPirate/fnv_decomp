#ifndef FNV_ASTARSEARCH_H
#define FNV_ASTARSEARCH_H

#include "astarsearch_decls.h"

// @fnv 0x00b00a00
// pdb: BSTaskletManager::QInstance | BSTaskletManager_Xenon.obj | retail, call graph, high
inline BSWin32TaskletManager& GetTaskletManager()
{
    static BSWin32TaskletManager s_TaskletManager(6);
    return s_TaskletManager;
}

// @fnv 0x006a7e00
// pdb: AStarSearch<NavMeshSearchNode,NavMeshSearchLink>::GetOrCreateAStarNode | NavMeshSearch.obj | debug, call graph, high
// pdb params: aiKey, afCost, aRetNode
// pdb locals: pBuckHead, pcurrent, pprev
CREATE_ASTARNODE_RESULT AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::CreateOrUpdateNode(
    unsigned int aiKey, float afCost, AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>*& aRetNode)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>** ppBucket =
        &m_kNodeHashTable.m_ppNodes[m_kNodeHashTable.AStarNodeMap_GetBucketIndex(aiKey)];
    if (*ppBucket)
    {
        if ((*ppBucket)->iKey == aiKey)
        {
            if ((*ppBucket)->m_fPathingCostCur > afCost)
            {
                aRetNode = *ppBucket;
                AStarBucketQueue.UnlinkNode(aRetNode);
                aRetNode->m_fPathingCostCur = afCost;
                return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
            }
            else
                return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
        }
        else
        {
            AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pPrev = *ppBucket;
            AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pCur;
            pCur = (*ppBucket)->m_pNextHashNode;
            while (pCur)
            {
                if (pCur->iKey == aiKey)
                {
                    if (pCur->m_fPathingCostCur > afCost)
                    {
                        aRetNode = pCur;
                        AStarBucketQueue.UnlinkNode(aRetNode);
                        aRetNode->m_fPathingCostCur = afCost;
                        return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
                    }
                    else
                        return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
                }
                pPrev = pCur;
                pCur = pCur->m_pNextHashNode;
            }
        }
    }
    aRetNode = m_kNodeAllocator.CreateNode();
    aRetNode->iKey = aiKey;
    aRetNode->m_fPathingCostCur = afCost;
    aRetNode->m_pNextHashNode = *ppBucket;
    *ppBucket = aRetNode;
    return CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE;
}

// @fnv 0x006b8fe0
// pdb: AStarSearch<CombatPlanNode *,CombatPlanLink *>::GetOrCreateAStarNode | CombatPlanner.obj | retail, call graph (shared callers), low
// pdb note: debug build links it to AStarSearch<NavMeshInfo const *,TESObjectREFR *>::GetOrCreateAStarNode
// pdb params: aiKey, afCost, aRetNode
// pdb locals: pBuckHead, pcurrent, pprev
CREATE_ASTARNODE_RESULT AStarSearch<AStarNodeData*, AStarNodeLink*>::CreateOrUpdateNode(
    unsigned int uiKey, float m_fPathingCostCur, AStarNode<AStarNodeData*, AStarNodeLink*>*& pNodeOut)
{
    AStarNode<AStarNodeData*, AStarNodeLink*>** ppBucket =
        &m_kNodeHashTable.m_ppNodes[m_kNodeHashTable.AStarNodeMap_GetBucketIndex(uiKey)];
    if (*ppBucket)
    {
        if ((*ppBucket)->iKey == uiKey)
        {
            if ((*ppBucket)->m_fPathingCostCur > m_fPathingCostCur)
            {
                pNodeOut = *ppBucket;
                AStarBucketQueue.UnlinkFromNeighbors(pNodeOut);
                pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
            }
            else
                return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
        }
        else
        {
            AStarNode<AStarNodeData*, AStarNodeLink*>* pPrev = *ppBucket;
            AStarNode<AStarNodeData*, AStarNodeLink*>* pCur;
            pCur = (*ppBucket)->m_pNextHashNode;
            while (pCur)
            {
                if (pCur->iKey == uiKey)
                {
                    if (pCur->m_fPathingCostCur > m_fPathingCostCur)
                    {
                        pNodeOut = pCur;
                        AStarBucketQueue.UnlinkFromNeighbors(pNodeOut);
                        pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
                        return CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA;
                    }
                    else
                        return CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER;
                }
                pPrev = pCur;
                pCur = pCur->m_pNextHashNode;
            }
        }
    }
    pNodeOut = m_kNodeAllocator.AStarNodeHeap_CombatPlanNode_CombatPlanLink_AllocateNode();
    pNodeOut->iKey = uiKey;
    pNodeOut->m_fPathingCostCur = m_fPathingCostCur;
    pNodeOut->m_pNextHashNode = *ppBucket;
    *ppBucket = pNodeOut;
    return CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE;
}

// @fnv 0x006a7c90
// pdb: AStarSearch<NavMeshSearchNode,NavMeshSearchLink>::AddStartNode | NavMeshSearch.obj | debug, call graph, high
// pdb params: aiKey, aNodeData, afHeuristic
// pdb locals: pastarNode
AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::FindOrCreateSearchNode(
    unsigned int aiKey, const NavMeshTriangleReference& aNodeData, float afHeuristic)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode;
    switch (((NavMeshSearch*)this)->CreateOrUpdateNode(aiKey, 0.0f, pNode))
    {
    case CREATE_ASTARNODE_RESULT_ASTAR_CREATED_NEW_NODE:
        pNode->m_fCost = afHeuristic;
        pNode->ObjectResolver = aNodeData;
        AStarBucketQueue.InsertSortedNode(pNode);
        m_pLastCreatedNode = pNode;
        return pNode;
    case CREATE_ASTARNODE_RESULT_ASTAR_MUST_SET_LINKDATA:
        return pNode;
    case CREATE_ASTARNODE_RESULT_ASTAR_OLD_COST_IS_BETTER:
        return 0;
    default:
        return 0;
    }
}

// @fnv 0x006a8010
// pdb: AStarSearch<NavMeshSearchNode,NavMeshSearchLink>::BuildNodePath | NavMeshSearch.obj | debug, call graph, medium
// pdb locals: iloopCount, ConnectedNodes, ptempLastSearchedNode, i, pconnectedNode
AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::ComputePath()
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pCurNode;
    AStarConnectionArray<NavMeshTriangleReference, NavMeshTriangleEdgeReference> ConnectionArray;
    unsigned int uiCounter;
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* i;
    unsigned int pSavedLastNode;
    i = m_pCurrentNode;
    m_pCurrentNode = AStarBucketQueue.Pop();
    if (m_pCurrentNode == NULL)
        return NULL;
    m_pFirstNode = m_pCurrentNode;
    uiCounter = 0;
    while (m_pCurrentNode)
    {
        if (HasReachedGoal(m_pCurrentNode))
        {
            m_pFirstNode = m_pCurrentNode;
            return m_pCurrentNode;
        }
        ConnectionArray.Clear(0);
        CollectConnections(m_pCurrentNode, &ConnectionArray);
        for (pSavedLastNode = 0; pSavedLastNode < ConnectionArray.GetSize(); pSavedLastNode++)
        {
            pCurNode = ConnectionArray[pSavedLastNode];
            AStarBucketQueue.UnlinkNode(pCurNode);
            if (m_pCurrentNode->m_pParentNode == pCurNode)
                return NULL;
            pCurNode->m_pParentNode = m_pCurrentNode;
            AStarBucketQueue.InsertSortedNode(pCurNode);
            if (pCurNode->GetFitness() < m_pFirstNode->GetFitness())
                m_pFirstNode = pCurNode;
        }
        if (m_bUseBestNode)
        {
            if (++uiCounter == 50)
            {
                uiCounter = 0;
                BSSleep(0);
            }
        }
        i = m_pCurrentNode;
        m_pCurrentNode = AStarBucketQueue.Pop();
    }
    m_pCurrentNode = i;
    return NULL;
}

// @fnv 0x006a7d60
// pdb: AStarSearch<NavMeshSearchNode,NavMeshSearchLink>::Search | NavMeshSearch.obj | debug, call graph, high
// pdb params: apReturnArray, apReturnLinkArray, abReturnBestPathIfFailed
// pdb locals: pbestNode, psolutionNode, bretValue
bool AStarSearch<NavMeshTriangleReference, NavMeshTriangleEdgeReference>::Search(unsigned int apReturnArray, unsigned int apReturnLinkArray, bool abReturnBestPathIfFailed)
{
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pNode;
    bool bSuccess;
    AStarNode<NavMeshTriangleReference, NavMeshTriangleEdgeReference>* pOutNode;
    m_bUseBestNode = GetTaskletManager().IsTaskletThread(gm_GetCurrentThreadId());
    pNode = ComputePath();
    if (pNode)
    {
        bSuccess = true;
        pOutNode = pNode;
    }
    else if (abReturnBestPathIfFailed)
    {
        bSuccess = false;
        pOutNode = m_pFirstNode;
    }
    else
    {
        bSuccess = false;
        pOutNode = NULL;
    }
    if (pOutNode)
        AStarSearch_NavMeshSearchNode_NavMeshSearchLink_GetPathToNode(pOutNode, apReturnArray, apReturnLinkArray);
    return bSuccess;
}

#endif
