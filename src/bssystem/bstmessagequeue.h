
#include "bstmessagequeue_decls.h"
template <>
// @fnv 0x00905770
// pdb: BSTCommonLLMessageQueue<ActorPathingMessage>::DoTryPop | HighProcess.obj | retail, vtable slot, high
// pdb params: aMessage
// pdb locals: pElem, bResult
bool BSTCommonLLMessageQueue<QueuedMessage>::RemoveMessage(QueuedMessage& aMessage)
{
    BSTFreeListElem<QueuedMessage>* pElem = pHead;
    bool bResult;
    if (pElem)
    {
        aMessage = reinterpret_cast<QueuedMessage&>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pElem)->GetItem());
        pHead = pElem->pNext;
        pSizeClassFreeList->Elem(pElem);
        bResult = true;
    }
    else
        bResult = false;
    return bResult;
}
template <>
// @fnv 0x009056f0
// pdb: BSTCommonLLMessageQueue<ActorPathingMessage>::DoTryPush | HighProcess.obj | retail, vtable slot, high
// pdb params: aMessage
// pdb locals: pElem, bResult
bool BSTCommonLLMessageQueue<QueuedMessage>::EnqueueMessage(const QueuedMessage& aMessage)
{
    BSTFreeListElem<QueuedMessage>* pElem;
    bool bResult;
    if (pSizeClassFreeList && pSizeClassFreeList->BSTFreeList_Allocate_0(pElem, aMessage))
    {
        if (!pHead)
            m_ppTailLink = &pHead;
        *m_ppTailLink = pElem;
        pElem->pNext = 0;
        m_ppTailLink = &pElem->pNext;
        bResult = true;
    }
    else
        bResult = false;
    return bResult;
}
