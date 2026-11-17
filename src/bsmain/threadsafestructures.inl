
#include "threadsafestructures_ThreadSafeStructuresMatch.h"

template<>
// @fnv 0x0044B350
// pdb: LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueue<NiPointer<QueuedReference> > | ModelLoader.obj | debug, call graph, medium
// pdb params: aiMaxThreads, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueue(unsigned int maxThreads, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 253);
    iCount = 0;
    pHead = new LockFreeQueueEntry;
    pTail = pHead;
    m_uiDeleteBatchSize = deleteBatchSize;
    m_ppDeletedNodeBuffers = new LockFreeQueueEntry*[maxThreads * 2];
    pMenuInterfaceManager = new Manager(maxThreads);
}

template<>
// @fnv 0x006C6450
// pdb: LockFreeQueue<bhkRigidBody *>::LockFreeQueue<bhkRigidBody *> | NavMeshObstacleManager.obj | debug, object-file run extension, low
// pdb params: aiMaxThreads, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeQueue<bhkRigidBody*>::LockFreeQueue(unsigned int maxThreads, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 253);
    iCount = 0;
    pHead = new LockFreeQueueEntry;
    pTail = pHead;
    m_uiDeleteBatchSize = deleteBatchSize;
    m_ppDeletedNodeBuffers = new LockFreeQueueEntry*[maxThreads * 2];
    pMenuInterfaceManager = new Manager(maxThreads);
}

template<>
// @fnv 0x005289E0
// pdb: LockFreeMap<unsigned int,NiPointer<ExteriorCellLoaderTask> >::LockFreeMap<unsigned int,NiPointer<ExteriorCellLoaderTask> > | ExteriorCellLoader.obj | debug, object-file run extension, low
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeMap<unsigned int, NiPointer<ExteriorCellLoaderTask> >::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 912);
    uiCount = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}

template<>
// @fnv 0x0044F070
void LockFreeMap<unsigned int, NiPointer<ExteriorCellLoaderTask> >::DeletedNodeScanner::ScanForDeletedNodes()
{
    AutoMemContext kContext(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 866);
    unsigned int numReferences = pOwner->GetMaxThreads() * 3;
    ThreadSafeHashTableNode** referencedNodes = new ThreadSafeHashTableNode*[numReferences];
    memcpy(referencedNodes, pOwner->m_ppDeletedNodeBuffers, numReferences * sizeof(ThreadSafeHashTableNode*));
    ThreadSafeHashTableNode* deleteHead = 0;
    unsigned int deleteCount = 0;
    while (m_pDeletedNodeHead != 0)
    {
        ThreadSafeHashTableNode* pNode = m_pDeletedNodeHead;
        m_pDeletedNodeHead = m_pDeletedNodeHead->GetNextDelete();
        {
            bool bReferenced = false;
            for (unsigned int index = 0; index < numReferences; ++index)
            {
                if (pNode == referencedNodes[index])
                {
                    bReferenced = true;
                    break;
                }
            }
            if (bReferenced)
            {
                pNode->SetNextDelete(deleteHead);
                deleteHead = pNode;
                ++deleteCount;
            }
            else
            {
                pNode->SetNextDelete(0);
                pOwner->DeleteNode(pNode);
            }
        }
    }
    delete[] referencedNodes;
    m_pDeletedNodeHead = deleteHead;
    m_uiDeleteCount = deleteCount;
}

template<>
// @fnv 0x006C73B0
// pdb: ThreadSpecificInterfaceManager<LockFreeMap<MobileObject *,NiPointer<LipTask> >::LockFreeMapInterface>::ThreadSpecificInterfaceManager<LockFreeMap<MobileObject *,NiPointer<LipTask> >::LockFreeMapInterface> | LipSyncBackgroundManager.obj | retail, call graph (shared callers), low
// pdb note: debug build links it to ThreadSpecificInterfaceManager<LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueInterface>::ThreadSpecificInterfaceManager<LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueInterface>
// pdb params: aiMaxThreads
// pdb locals: tempMemContext
ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>::ThreadInterfaceManager(unsigned int maxThreads)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 20);
    uiThreadCount = 0;
    uiMaxThreads = maxThreads;
    m_pThreadInterfaceEntries = new ThreadInterfaceEntry[uiMaxThreads];
    uiTLSIndex = _TlsAlloc();
}

template<>
// @fnv 0x0044B750
// pdb: LockFreeMap<TESObjectREFR *,NiPointer<QueuedReference> >::LockFreeMap<TESObjectREFR *,NiPointer<QueuedReference> > | ModelLoader.obj | retail, call graph, medium
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeMap<TESObjectREFR*, NiPointer<QueuedReference> >::LockFreeMap(unsigned int aiMaxThreads, unsigned int aiNumBuckets, unsigned int aiDeleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 912);
    uiCount = 0;
    uiNumBuckets = aiNumBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[aiMaxThreads * 3];
    uiDeleteBatchSize = aiDeleteBatchSize;
    pManager = new Manager(aiMaxThreads);
}

template<>
// @fnv 0x0044BA10
// pdb: LockFreeMap<AnimIdle *,NiPointer<QueuedAnimIdle> >::LockFreeMap<AnimIdle *,NiPointer<QueuedAnimIdle> > | ModelLoader.obj | retail, call graph, high
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeMap<AnimIdle*, NiPointer<QueuedAnimIdle> >::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 912);
    uiCount = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}

template<>
// @fnv 0x0044BBE0
// pdb: LockFreeMap<Animation *,NiPointer<QueuedReplacementKFList> >::LockFreeMap<Animation *,NiPointer<QueuedReplacementKFList> > | ModelLoader.obj | retail, call graph, medium
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeMap<Animation*, NiPointer<QueuedReplacementKFList> >::LockFreeMap(unsigned int aiMaxThreads, unsigned int aiNumBuckets, unsigned int aiDeleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 912);
    uiCount = 0;
    uiNumBuckets = aiNumBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[aiMaxThreads * 3];
    uiDeleteBatchSize = aiDeleteBatchSize;
    pManager = new Manager(aiMaxThreads);
}

template<>
// @fnv 0x0044BE80
// pdb: LockFreeMap<TESObjectREFR *,NiPointer<QueuedHelmet> >::LockFreeMap<TESObjectREFR *,NiPointer<QueuedHelmet> > | ModelLoader.obj | retail, call graph, high
// pdb params: aiMaxThreads, aiNumBuckets, aiDeleteBatchSize
// pdb locals: tempMemContext
LockFreeMap<TESObjectREFR*, NiPointer<QueuedHelmet> >::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 912);
    uiCount = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}

template<>
// @fnv 0x0044C040
LockFreeMap<const char*, Model*>::LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD, true,
        kThreadSafeStructuresSourceFile, 912);
    uiCount = 0;
    uiNumBuckets = numBuckets;
    m_pBuckets = new ThreadSafePointer<ThreadSafeHashTableNode>[uiNumBuckets];
    m_ppDeletedNodeBuffers = new ThreadSafeHashTableNode*[maxThreads * 3];
    uiDeleteBatchSize = deleteBatchSize;
    pManager = new Manager(maxThreads);
}
