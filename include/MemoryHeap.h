#pragma once

#include "AbstractHeap.h"

// pdb: class MemoryHeap, size 0x20f8 (here 0x20f4), bases: AbstractHeap, 2 members
class MemoryHeap : public AbstractHeap
{
public:
    virtual ~MemoryHeap();
    virtual const char* GetName();
    virtual void* Allocate(unsigned int aSize, unsigned int alignment);
    virtual void Deallocate(void* apPointer, unsigned int alignment);
    virtual bool ContainsBlockImpl(const void* pointer);
    virtual void CheckHeapIntegrity();
    virtual void GetHeapStats(MemoryHeapStats* stats, bool full);
    virtual int OutputBucketInfo(IMemoryManagerFile* file);
    virtual int OutputBlockInfo(IMemoryManagerFile* file, bool full);
    virtual unsigned int Size(const void* apPointer, unsigned int alignment);
    virtual void vf10();
    virtual void vf11();
    virtual void* AllocateHeapMemory(unsigned int size, unsigned int alignment);
    virtual void FreeHeapMemory(void* pointer);
    virtual unsigned int CreateMorePages(void* pointer, unsigned int size, unsigned int alignment);
    virtual unsigned int CleanExtraPages(void* pointer, unsigned int size, unsigned int alignment);
    virtual void DecommitPages(HeapFreeBlock* block);
    virtual void CommitPages(HeapFreeBlock* block, unsigned int size);

    bool bSupportsSwapping;
    bool bDeletingHeap;
    unsigned char _pad20F2[2];

    unsigned int CommitRange(void* base, unsigned int offset, unsigned int size);
};
