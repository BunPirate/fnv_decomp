
// src/havok/physics/dynamics/world/simulation/multithreaded/hkpdynamicsjobqueueutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/multithreaded/hkpdynamicsjobqueueutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d96530_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct S_00d96530_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d96530_Allocator* m_pStreamAllocator;
    S_00d96530_Allocator* heap()
    {
        return m_pStreamAllocator;
    }
};

S_00d96530_Router* hkMemoryRouter_getInstance();

struct S_00d96530_RelArray
{
    int m_offset;
    int m_iElementCount;
    int m_pRayCursor;
    S_00d96530_RelArray(void* data, int capacity)
    {
        m_offset = (char*)data - (char*)this;
        m_iElementCount = 0;
        m_pRayCursor = capacity;
    }
};

struct S_00d96530_Block
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d96530_RelArray m_ppData;
    void* operator new(size_t, void* p)
    {
        return p;
    }
    void operator delete(void*, void*)
    {}
    S_00d96530_Block(int capacity) : m_ppData((char*)this + 0x20, capacity)
    {}
};

struct S_00d96530_Header
{
    int m_iBlockCount;
    int m_maxBlocks;
    int m_iDofCount;
    S_00d96530_Block* m_kBlocks[1];
};

// @fnv 0x00d96530
// src: XBOX_RETAIL_PDB 0x00d96530
// pdb: hkpAgentSectorHeader::allocate | hkpDynamicsJobQueueUtils.obj | retail, call graph, high
// pdb params: numTasks, numAgentNnEntriesPerTask
S_00d96530_Header* hkpAgentSectorHeader_allocate(int numTasks, int numAgentNnEntriesPerTask)
{
    S_00d96530_Header* pHeader =
        (S_00d96530_Header*)hkMemoryRouter_getInstance()->heap()->AllocateMemoryBlock((short)numTasks * 4 + 0xc);
    int iBlockBytes = numAgentNnEntriesPerTask << 4;
    pHeader->m_maxBlocks = numTasks;
    pHeader->m_iBlockCount = numTasks;
    pHeader->m_iDofCount = iBlockBytes + 0x20;
    S_00d96530_Block** blocks = pHeader->m_kBlocks;
    for (int i = 0; i < numTasks; i++)
    {
        void* p = hkMemoryRouter_getInstance()->heap()->AllocateMemoryBlock(iBlockBytes + 0x20);
        blocks[i] = (S_00d96530_Block*)p;
        new (p) S_00d96530_Block(iBlockBytes);
    }
    return pHeader;
}

struct S_Holder
{
    virtual void* v0();
    virtual void* v1();
    virtual void v2(const void* a, int b);
};
struct S_Tls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Holder* unk10;
    S_Holder& holder()
    {
        return *unk10;
    }
};
inline void S_Call(const void* a, int b)
{
    ((S_Tls*)hkMemoryRouter_getInstance())->holder().v2(a, b);
}
struct S_Item;
struct S_C
{
    int count;
    int unk04;
    int unk08;
    S_Item* arr[8];
    void hkpAgentSectorHeader_deallocate();
};
// Calls S_Call on each of the count items in arr with unk08, then calls S_Call on this with count*4+0xc.
// @fnv 0x00d965b0
// src: HAVOK_LIB 0x00d965b0
// pdb: hkpAgentSectorHeader::deallocate | hkpDynamicsJobQueueUtils.obj | retail, upstream name already matches, high
void S_C::hkpAgentSectorHeader_deallocate()
{
    S_Item* const* p = arr;
    for (int i = 0; i < count; i++)
        S_Call(p[i], unk08);
    S_Call(this, (short)count * 4 + 0xc);
}
