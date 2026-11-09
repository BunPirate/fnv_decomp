// bscore/abstractheap.cpp: AbstractHeap and heap diagnostics (19 functions)

#include "../../include/AbstractHeap.h"
#include "abstractheap_decls.h"
#include "../../include/IMemoryManagerFile.h"
#include "../../include/MemoryManager.h"

// Helpers absent from the shared API; inherit the shared layout without copying it.
struct AbstractHeapDiagnostics : AbstractHeap
{
    int CountLinkedNodes(int node);
    AbstractHeap* DestroyIfFlagged(unsigned int flags);
    void CheckFreeBlock(HeapFreeBlock* block);
    void AbstractHeap_OutputBlockFailure(unsigned int desired_size, HeapFreeList* list);
};

__forceinline void AddHeapFreeBlock(HeapFreeList* list, HeapFreeBlock* block)
{
    if (list->pTail)
    {
        HeapFreeBlock* tail = list->pTail;
        block->m_pNextFree = tail;
        HeapFreeBlock* previous = tail->m_pPrevFree;
        block->m_pPrevFree = previous;
        if (previous)
            previous->m_pNextFree = block;
        tail->m_pPrevFree = block;
        list->pTail = block;
    }
    else
    {
        list->pHead = block;
        list->pTail = block;
    }
}

// @fnv 0x00aa9bd0
// pdb: AbstractHeap::TryAndDefragment | AbstractHeap.obj | debug, object-file gap fill, medium
// pdb params: apNewFree
// pdb locals: pcur, pprev
void AbstractHeap::InsertFreeBlock(HeapFreeBlock* freeBlock)
{
    HeapFreeBlock* block = freeBlock;
    if (block)
    {
        for (;;)
        {
            HeapFreeBlock* previous = (HeapFreeBlock*)block->GetPrevious();
            if (previous && previous->IsFree())
            {
                CoalesceFreeBlocks(previous, block);
                block = previous;
            }
            else
            {
                break;
            }
        }
    }
    if (block)
    {
        while (block != pBlockTail && block->GetNext()->IsFree())
        {
            CoalesceFreeBlocks(block, (HeapFreeBlock*)block->GetNext());
        }
    }
    RebuildFreeLists();
}

// @fnv 0x00aa8f50
// pdb: AbstractHeap::BaseAllocate | AbstractHeap.obj | retail, upstream name already matches, high
// pdb params: aSize
// pdb locals: plist, curaSize, pmem, isub, isubID, pfreeCur, isizeDiff, pnewFree, bdecommitted, newSize, bres, msg, totalSize, pnext, itotalMem, itotalSize, pblock
void* AbstractHeap::BaseAllocate(unsigned int aSize)
{
    fnv_EnterCriticalSection(&CriticalSectionO);
    if (aSize <= 8)
        aSize = 8;
    else
        aSize = (aSize + iDefaultAlignment - 1) & ~(iDefaultAlignment - 1);
    unsigned int uiBlockSize;
    void* pMemory = 0;
    HeapFreeList* pSizeClassFreeList = GetFreeList(aSize);
    if (!pSizeClassFreeList->pTail && pSizeClassFreeList != &LargeFreeList)
    {
        pSizeClassFreeList += MinFreeBlockSize / iDefaultAlignment;
        if (pSizeClassFreeList > pLastSmallList)
        {
            pSizeClassFreeList = &LargeFreeList;
        }
        else
        {
            int iSubBucketIndex = 0;
            int iFirstBucket = GetSubBucket(aSize + MinFreeBlockSize);
            for (iSubBucketIndex = iFirstBucket; iSubBucketIndex < 16 && !pSizeClassFreeList->pTail; ++iSubBucketIndex)
            {
                if (pSubBuckets[iSubBucketIndex].iCount)
                {
                    if (pSubBuckets[iSubBucketIndex].pFirst > pSizeClassFreeList)
                        pSizeClassFreeList = pSubBuckets[iSubBucketIndex].pFirst;
                    while (!pSizeClassFreeList->pTail && !IsLastInSubBucket(iSubBucketIndex, pSizeClassFreeList))
                        ++pSizeClassFreeList;
                }
            }
            if (iSubBucketIndex == 16)
                pSizeClassFreeList = &LargeFreeList;
        }
    }
    if (pSizeClassFreeList->pTail)
    {
        HeapFreeBlock* pBlock = pSizeClassFreeList->pHead;
        while (pBlock)
        {
            uiBlockSize = pBlock->GetSize();
            int iExtra = uiBlockSize - aSize;
            if (iExtra == 0 || iExtra >= (int)MinFreeBlockSize)
            {
                HeapFreeBlock* pNewBlock = 0;
                bool bDecommitted = pBlock->IsDecommitted();
                RemoveBlockFromFreeList_00aa9e50(pSizeClassFreeList, pBlock);
                if (iExtra)
                {
                    if (bDecommitted)
                    {
                        unsigned int iCommitSize = aSize + 24;
                        bool bCommitted = VirtualAlloc(pBlock, iCommitSize, 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            AddBlockToFreeList(pBlock);
                            fnv_LeaveCriticalSection(&CriticalSectionO);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                        char szMessage[256];
                        sprintf_s(szMessage, 256, "Committing Entire Free Block: %08X, %08X\r\n", pBlock, iCommitSize);
                        if (AbstractHeapHasLog())
                        {
                            AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                        }
                    }
                    pNewBlock = (HeapFreeBlock*)((char*)pBlock + aSize + sizeof(MemoryBlockHeader));
                    unsigned int iRemainingSize = uiBlockSize - (aSize + sizeof(MemoryBlockHeader));
                    pNewBlock->m_pNextFree = 0;
                    pNewBlock->m_pPrevFree = 0;
                    pNewBlock->SetFlags(iRemainingSize, 0);
                    pNewBlock->SetPrevious(pBlock);
                    if (pBlock == pBlockTail)
                        pBlockTail = pNewBlock;
                    else
                    {
                        MemoryBlockHeader* pNext = pBlock->GetNext();
                        pNext->SetPrevious(pNewBlock);
                    }
                    ++iNumBlocks;
                    AddBlockToFreeList(pNewBlock);
                    InsertFreeBlock(pNewBlock);
                }
                else
                {
                    if (bDecommitted)
                    {
                        bool bCommitted = VirtualAlloc(pBlock, aSize + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                        if (!bCommitted)
                        {
                            AddBlockToFreeList(pBlock);
                            fnv_LeaveCriticalSection(&CriticalSectionO);
                            return 0;
                        }
                        pBlock->SetDecommitted(false);
                        char szMessage[256];
                        sprintf_s(szMessage, 256, "Committing perfectly matched Free Block: %08X, %08X\r\n", pBlock,
                                  aSize + sizeof(MemoryBlockHeader));
                        if (AbstractHeapHasLog())
                        {
                            AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                        }
                    }
                }
                pBlock->SetSize(aSize);
                pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
                iBlockMemAllocated += pBlock->GetTotalSize();
                break;
            }
            pBlock = pBlock->m_pPrevFree;
        }
    }
    if (!pMemory)
    {
        unsigned int uiBlockAllocationSizeItem = aSize + sizeof(MemoryBlockHeader);
        unsigned int iNeededSize = iMemAllocated + uiBlockAllocationSizeItem;
        if (iPageSize && iNeededSize > iCurrentSize && iNeededSize <= MemHeapSize)
            iCurrentSize += CreateMorePages(pMemHeap, iCurrentSize, uiBlockAllocationSizeItem);
        if (iNeededSize <= iCurrentSize)
        {
            MemoryBlockHeader* pBlock = (MemoryBlockHeader*)(pMemHeap + iMemAllocated);
            if (iPageSize)
            {
                bool bCommitted = VirtualAlloc(pBlock, aSize + sizeof(MemoryBlockHeader), 4096, 4) != 0;
                if (!bCommitted)
                {
                    fnv_LeaveCriticalSection(&CriticalSectionO);
                    return 0;
                }
                char szMessage[256];
                sprintf_s(szMessage, 256, "Committing memory on end of heap: %08X, %08X\r\n", pBlock,
                          aSize + sizeof(MemoryBlockHeader));
                if (AbstractHeapHasLog())
                {
                    AbstractHeapLogger::Get()->vfn_14(2, szMessage, 0, 0, 0);
                }
            }
            pBlock->SetFlags(aSize, 0);
            PushBlock(pBlock);
            iMemAllocated += uiBlockAllocationSizeItem;
            if (iMemAllocated > iMemAllocatedHigh)
                iMemAllocatedHigh = iMemAllocated;
            pMemory = (char*)pBlock + sizeof(MemoryBlockHeader);
            iBlockMemAllocated += uiBlockAllocationSizeItem;
        }
    }
    fnv_LeaveCriticalSection(&CriticalSectionO);
    return pMemory;
}

// @fnv 0x00aa9a70
// pdb: AbstractHeap::CleanEnd | AbstractHeap.obj | debug, object-file gap fill, medium
// pdb locals: pcur, ifreeSize
void AbstractHeap::RebuildFreeLists()
{
    MemoryBlockHeader* block = pBlockTail;
    while (block && block->IsFree() && block->GetNext() == (MemoryBlockHeader*)(pMemHeap + iMemAllocated))
    {
        RemoveBlockFromFreeList((HeapFreeBlock*)block);
        iMemAllocated -= block->GetTotalSize();
        --iNumBlocks;
        if (pBlockHead == pBlockTail)
        {
            pBlockTail = 0;
            pBlockHead = 0;
            break;
        }
        else
        {
            pBlockTail = block->GetPrevious();
        }
        block = pBlockTail;
    }
    if (iPageSize)
    {
        unsigned int unused = iCurrentSize - iMemAllocated;
        if (iCurrentSize - unused < iInitialSize)
            unused = iCurrentSize - iInitialSize;
        if (unused >= iPageSize)
            iCurrentSize -= CleanExtraPages(pMemHeap, iCurrentSize, unused);
    }
}

// @fnv 0x00aa9970
// pdb: AbstractHeap::MergeFreeBlocks | AbstractHeap.obj | debug, object-file gap fill, medium
// pdb params: apFree1, apFree2
void AbstractHeap::CoalesceFreeBlocks(HeapFreeBlock* pFirstBlock, HeapFreeBlock* pSecondBlock)
{
    RemoveBlockFromFreeList(pFirstBlock);
    RemoveBlockFromFreeList(pSecondBlock);
    if (pSecondBlock->IsDecommitted())
        pFirstBlock->SetDecommitted(true);
    pFirstBlock->SetSize(pFirstBlock->GetSize() + pSecondBlock->GetTotalSize());
    if (pSecondBlock == pBlockTail)
        pBlockTail = pFirstBlock;
    else
        pSecondBlock->GetNext()->SetPrevious(pFirstBlock);
    --iNumBlocks;
    AddBlockToFreeList(pFirstBlock);
}

// @fnv 0x00aa98f0
// pdb: AbstractHeap::BaseFree | AbstractHeap.obj | retail, upstream name already matches, high
// pdb params: apPointer
// pdb locals: pcur
void AbstractHeap::BaseFree(void* apPointer)
{
    if (!apPointer)
        return;
    fnv_EnterCriticalSection(&CriticalSectionO);
    HeapFreeBlock* block = (HeapFreeBlock*)((char*)apPointer - sizeof(MemoryBlockHeader));
    iBlockMemAllocated -= block->GetTotalSize();
    AddBlockToFreeList(block);
    InsertFreeBlock(block);
    fnv_LeaveCriticalSection(&CriticalSectionO);
}

// Removes the given block from the free list corresponding to its size by calling FUN_00aa9e50.
// @fnv 0x00aaa660
inline void AbstractHeap::RemoveBlockFromFreeList(HeapFreeBlock* block)
{
    RemoveBlockFromFreeList_00aa9e50(GetFreeList(block->GetSize()), block);
}

// Clears the block's fields, marks it free, adds it to the free list for its size, and updates the free-block and sub-bucket counters.
// @fnv 0x00aa9d30
// src: COMMUNITY 0x00aa9d30
// pdb: AbstractHeap::AddBlockToFreeList | AbstractHeap.obj | debug, upstream name already matches, high
// pdb params: apBlock
// pdb locals: plist
void AbstractHeap::AddBlockToFreeList(HeapFreeBlock* apBlock)
{
    apBlock->m_pPrevFree = 0;
    apBlock->m_pNextFree = 0;
    apBlock->SetFree(true);
    HeapFreeList* list = GetFreeList(apBlock->GetSize());
    AddHeapFreeBlock(list, apBlock);
    ++iNumFreeBlocks;
    IncrementSubBucket(apBlock->GetSize());
}
// @fnv 0x00aa9e50
// src: XBOX_PDB 0x00aa9e50
// pdb: AbstractHeap::RemoveBlockFromFreeList | AbstractHeap.obj | debug, object-file gap fill, medium
// pdb params: apList, apBlock
// pdb locals: pnext, pprev
void AbstractHeap::RemoveBlockFromFreeList_00aa9e50(HeapFreeList* apFreeList, HeapFreeBlock* block)
{
    HeapFreeBlock* pPrev = block->m_pPrevFree;
    HeapFreeBlock* pNext = block->m_pNextFree;
    block->RemoveFromFreeList();
    block->SetFree(false);
    if (block == apFreeList->pHead)
        apFreeList->pHead = pPrev;
    if (block == apFreeList->pTail)
        apFreeList->pTail = pNext;
    DecrementSubBucket(block->GetSize());
    --iNumFreeBlocks;
}
// Unlinks this node from the free list by patching its neighbours' free-list links, then clears the previous and next free pointers.
// @fnv 0x00aaa5e0
// pdb: AbstractHeap::GetSubBucketIndex | AbstractHeap.obj | debug, object-file run extension, low
// pdb params: aiBucketSize
inline void HeapFreeBlock::RemoveFromFreeList()
{
    if (m_pNextFree)
        m_pNextFree->SetPrevFree(m_pPrevFree);
    if (m_pPrevFree)
        m_pPrevFree->SetNextFree(m_pNextFree);
    m_pPrevFree = 0;
    m_pNextFree = 0;
}
// Computes the sub-bucket index for size and, if valid, increments that bucket's iCount.
// @fnv 0x00aa9ef0
// pdb: AbstractHeap::IncrementSubBucket | AbstractHeap.obj | debug, upstream name already matches, high
// pdb params: aiBucketSize
// pdb locals: id
void AbstractHeap::IncrementSubBucket(int aiBucketSize)
{
    int bucket = GetSubBucket(aiBucketSize);
    if (bucket != -1)
        ++pSubBuckets[bucket].iCount;
}
// Looks up the sub-bucket for size and decrements its iCount if a bucket was found.
// @fnv 0x00aa9f50
// pdb: AbstractHeap::DecrementSubBucket | AbstractHeap.obj | debug, upstream name already matches, high
// pdb params: aiBucketSize
// pdb locals: id
void AbstractHeap::DecrementSubBucket(int aiBucketSize)
{
    int bucket = GetSubBucket(aiBucketSize);
    if (bucket != -1)
        --pSubBuckets[bucket].iCount;
}
// Links block into the heap's block list, setting its previous pointer and updating the head/tail and count.
// @fnv 0x00aa9ca0
// pdb: AbstractHeap::AddBlockToList | AbstractHeap.obj | debug, object-file gap fill, medium
// pdb params: apNewBlock
void AbstractHeap::PushBlock(MemoryBlockHeader* block)
{
    if (pBlockTail)
    {
        block->SetPrevious(pBlockTail);
        pBlockTail = block;
    }
    else
    {
        pBlockHead = block;
        pBlockTail = pBlockHead;
    }
    ++iNumBlocks;
}

// Returns -1 if arg is null, otherwise counts nodes by following the pointer at offset 0x4C until it is null.
// @fnv 0x00aaa560
// pdb: AbstractHeap::GetLogIndex | AbstractHeap.obj | debug, object-file run extension, low
// pdb params: apLogItem
// pdb locals: iindex
int AbstractHeapDiagnostics::CountLinkedNodes(int pNode)
{
    if (!pNode)
        return -1;
    int count = 0;
    while (*(int*)(pNode + 0x4C))
    {
        ++count;
        pNode = *(int*)(pNode + 0x4C);
    }
    return count;
}

extern MemoryManager g_memoryManager;
// Calls the heap destructor, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00aaa5b0
// pdb: AbstractHeap::`scalar deleting destructor' | AbstractHeap.obj | debug, object-file run extension, low
AbstractHeap* AbstractHeapDiagnostics::DestroyIfFlagged(unsigned int flags)
{
    AbstractHeap::~AbstractHeap();
    if (flags & 1)
    {
        g_memoryManager.Deallocate(this);
    }
    return this;
}

struct _RTL_CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
// @fnv 0x00aa9fb0
// pdb: AbstractHeap::CheckHeapIntegrity | AbstractHeap.obj | retail, upstream name already matches, high
// pdb locals: pcur, pfreeCur, isub, i
void AbstractHeap::CheckHeapIntegrity()
{
    HeapFreeBlock* pblock;
    MemoryBlockHeader* pfreeCur;
    int i2;
    int isub;
    EnterCriticalSection((_RTL_CRITICAL_SECTION*)CriticalSectionO);
    pblock = 0;
    for (isub = 0; isub < 16; isub++)
    {
        if (pSubBuckets[isub].iCount)
        {
            pblock = pSubBuckets[isub].pFirst->pHead;
            while (pblock)
            {
                ((AbstractHeapDiagnostics*)this)->CheckFreeBlock(pblock);
                pblock = pblock->m_pPrevFree;
            }
        }
    }
    for (i2 = 0; i2 < 0x400; i2++)
    {
        pblock = pSmallFreeList[i2].pHead;
        while (pblock)
        {
            ((AbstractHeapDiagnostics*)this)->CheckFreeBlock(pblock);
            pblock = pblock->m_pPrevFree;
        }
    }
    pblock = LargeFreeList.pHead;
    while (pblock)
    {
        ((AbstractHeapDiagnostics*)this)->CheckFreeBlock(pblock);
        pblock = pblock->m_pPrevFree;
    }
    pfreeCur = pBlockTail;
    while (pfreeCur)
    {
        pfreeCur = pfreeCur->m_pPreviousBlock;
    }
    LeaveCriticalSection((_RTL_CRITICAL_SECTION*)CriticalSectionO);
}

// pdb: structure _MEMORYSTATUS, size 0x20, 8 members
struct _MEMORYSTATUS
{
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
};
extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(_MEMORYSTATUS*);

// If heap logging is enabled, logs the block size, then counts free blocks in list and reports count, largest, total and available physical memory.
// @fnv 0x00aa9760
// src: XBOX_DEBUG_PDB 0x00aa9760
// pdb: AbstractHeap::OutputBlockFailure | AbstractHeap.obj | debug, unique string literal, high
// pdb params: desired_size, list
// pdb locals: m, avail, memoryStatus, num, largest, block, size
void AbstractHeapDiagnostics::AbstractHeap_OutputBlockFailure(unsigned int desired_size, HeapFreeList* list)
{
    if (AbstractHeapHasLog())
    {
        unsigned int numBlocks4 = 0;
        unsigned int largest = 0;
        unsigned int total = 0;
        _MEMORYSTATUS status3;
        char buffer[256];
        sprintf_s(buffer, 256, "AbstractHeap: Checking list for block size %u\n", desired_size);
        AbstractHeapLogger::Get()->vfn_14(2, buffer, 0, 0, 0);
        if (list)
        {
            MemoryBlockHeader* block = list->pHead;
            while (block)
            {
                numBlocks4++;
                unsigned int size = block->GetSize();
                total += size;
                if (size > largest)
                    largest = size;
                block = block->GetNext();
            }
        }
        GlobalMemoryStatus(&status3);
        sprintf_s(
            buffer, 256,
            "\tNumber of blocks free: %u\n\tLargest free block: %u\n\tTotal space in free blocks: %u\n\tAvailable global memory: %u\n",
            numBlocks4, largest, total, status3.dwAvailPhys);
        AbstractHeapLogger::Get()->vfn_14(2, buffer, 0, 0, 0);
    }
}

struct BucketInfo
{
    unsigned int iSize;
    int iCount;
};

// Writes the bucket count and, for each bucket size, the number of free blocks to the given file, returning the total bytes written.
// @fnv 0x00aaa310
// pdb: AbstractHeap::OutputBucketInfo | AbstractHeap.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: iwritten, inumBuckets, bucket, icnt, plist, pcur
int AbstractHeap::OutputBucketInfo(IMemoryManagerFile* apFile)
{
    if (!apFile)
        return 0;
    fnv_EnterCriticalSection(CriticalSectionO);
    BucketInfo bucketInfo;
    int numBuckets;
    int total;
    int i4;
    HeapFreeBlock* block;
    {
        HeapFreeList* list;
        total = 0;
        numBuckets = 0x401;
        total += apFile->Write(&numBuckets, 4);
        for (i4 = 0; i4 < numBuckets; i4++)
        {
            bucketInfo.iSize = (i4 + 1) * iDefaultAlignment;
            bucketInfo.iCount = 0;
            list = GetFreeList(bucketInfo.iSize);
            block = list->pHead;
            while (block)
            {
                bucketInfo.iCount++;
                block = block->m_pPrevFree;
            }
            total += apFile->Write(&bucketInfo, 8);
        }
    }
    fnv_LeaveCriticalSection(CriticalSectionO);
    return total;
}

struct HeapBlockInfo
{
    int iType;
    unsigned int iSize;
    int bFree;
    int unk0C;
    int unk10;
    int iOwner;
};

// Writes the heap block count and, when full is set, each block's size, free flag and owner to the file, returning bytes written.
// @fnv 0x00aaa430
// pdb: AbstractHeap::OutputBlockInfo | AbstractHeap.obj | retail, upstream name already matches, high
// pdb params: apFile, abOutputWalk
// pdb locals: iwritten, stats, i, pblock, zero
int AbstractHeap::OutputBlockInfo(IMemoryManagerFile* apFile, bool abOutputWalk)
{
    if (!apFile)
        return 0;
    fnv_EnterCriticalSection(CriticalSectionO);
    int total2 = 0;
    if (abOutputWalk)
    {
        total2 += apFile->Write(&iNumBlocks, 4);
        int i;
        HeapBlockInfo info2;
        info2.iType = 8;
        MemoryBlockHeader* block7 = pBlockHead;
        for (i = 0; i < iNumBlocks; block7 = block7->GetNext(), i++)
        {
            info2.iSize = block7->GetSize();
            info2.bFree = block7->IsFree() != 0;
            info2.iOwner = -1;
            total2 += apFile->Write(&info2, sizeof(info2));
        }
    }
    else
    {
        int zero4 = 0;
        total2 += apFile->Write(&zero4, 4);
    }
    fnv_LeaveCriticalSection(CriticalSectionO);
    return total2;
}

class MemoryHeapStats
{
  public:
    const char* pName;
    unsigned int iMemHeapSize;
    unsigned int iCurrentSize;
    int iMemAllocated;
    unsigned int iNumBlocks;
    unsigned int iNumFreeBlocks;
    int iFreeSize;
    int iUsedSize;
    int iMinFreeBlock;
    int iMaxFreeBlock;
    unsigned int iHeapStructSize;
    unsigned int iFreeListBytes;
    int iBlockTableBytes;
    int iUnusedBytes;
    unsigned int m_uiTrailingStatsValue;
};

// @fnv 0x00aaa0e0
// pdb: AbstractHeap::GetHeapStats | AbstractHeap.obj | retail, upstream name already matches, high
// pdb params: apStats, abFullBlockInfo
// pdb locals: iblockDebugOverhead, pcur, iheapBlockSize, itotalBlockDebugOverhead, isize
void AbstractHeap::GetHeapStats(MemoryHeapStats* apStats, bool abFullBlockInfo)
{
    fnv_EnterCriticalSection(&this->CriticalSectionO);
    apStats->pName = this->pName;
    apStats->iMemHeapSize = this->MemHeapSize;
    apStats->iCurrentSize = this->iCurrentSize;
    apStats->iMemAllocated = this->iMemAllocated;
    apStats->iNumBlocks = this->iNumBlocks;
    apStats->iNumFreeBlocks = this->iNumFreeBlocks;
    int iZero4 = 0;
    int iBlockBytes2 = apStats->iNumBlocks * iZero4;
    int iHeaderSize3 = sizeof(MemoryBlockHeader) - iZero4;
    apStats->iHeapStructSize = sizeof(AbstractHeap);
    apStats->iFreeListBytes = 0x2000;
    apStats->iFreeListBytes += 0x80;
    apStats->iBlockTableBytes = this->iNumBlocks * iHeaderSize3;
    apStats->iUnusedBytes = iBlockBytes2;
    MemoryBlockHeader* aBlock = this->pBlockHead;
    apStats->iFreeSize = this->iMemAllocated - this->iBlockMemAllocated;
    apStats->iUsedSize = this->iBlockMemAllocated;
    apStats->iMinFreeBlock = 0xfffffff;
    apStats->iMaxFreeBlock = 0;
    if (abFullBlockInfo)
    {
        apStats->iFreeSize = 0;
        apStats->iUsedSize = 0;
        while (aBlock)
        {
            if (aBlock->IsFree())
            {
                int freeSize = aBlock->GetSize();
                apStats->iFreeSize += freeSize + iHeaderSize3;
                if (freeSize < apStats->iMinFreeBlock)
                    apStats->iMinFreeBlock = freeSize;
                if (freeSize > apStats->iMaxFreeBlock)
                    apStats->iMaxFreeBlock = freeSize;
            }
            else
            {
                int usedSize_ = aBlock->GetSize();
                apStats->iUsedSize += usedSize_ + iHeaderSize3;
            }
            aBlock = (aBlock == this->pBlockTail) ? 0 : aBlock->GetNext();
        }
        if (apStats->iNumFreeBlocks == 0)
            apStats->iMinFreeBlock = 0;
    }
    apStats->m_uiTrailingStatsValue = apStats->iMemHeapSize - apStats->iMemAllocated + apStats->iFreeSize;
    fnv_LeaveCriticalSection(&this->CriticalSectionO);
}
