
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiVBBlock.h"
#include "../../../../include/NiVBSet.h"

void __stdcall InsertSortedNode(NiVBBlock*);

// The shared NiVBSet header lacks the list head, threshold, InsertSortedNode,
// RemoveFirstNodeAtLeast and FUN_00e94580 used by the local set views below.

// @fnv 0x00e94490
// src: COMMUNITY 0x00e94490
// pdb: NiVBSet::FreeChip | NiVBSet.obj | retail, upstream name already matches, high
// pdb params: uiBlockIndex, uiChipIndex
// pdb locals: uiPreFreeSpace, pkVBBlock
void NiVBSet::FreeChip(unsigned int uiBlockIndex, unsigned int uiChipIndex)
{
    unsigned int uiPreFreeSpace;
    NiVBBlock* pkVBBlock;
    pkVBBlock = m_kBlockArray.m_pData[uiBlockIndex];
    if (!pkVBBlock)
        return;
    uiPreFreeSpace = pkVBBlock->m_uiValue24;
    pkVBBlock->FreeVBBlock(uiChipIndex);
    if (uiPreFreeSpace == pkVBBlock->m_uiValue24)
        return;
    RemoveNode(pkVBBlock);
    if (pkVBBlock->m_uiValue28 == pkVBBlock->m_uiSize)
    {
        m_kBlockArray.FUN_00a93c50(uiBlockIndex);
        NiVBSet_FreeBlock(pkVBBlock);
    }
    else
    {
        InsertSortedNode(pkVBBlock);
    }
}

// InsertSortedNode: insert a block into a key-sorted doubly linked list owned by this set.
// Head pointer lives at +0x2c; each node has key at +0x24, next at +0x3c, prev at +0x40.

struct FUN_00e94220_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    NiVBBlock* m_pFirstNode;

    void InsertSortedNode(NiVBBlock* node);
};

// Inserts a block into the doubly linked list ordered by m_24, updating head, next and back pointers.
// @fnv 0x00e94220
// pdb: NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned int,NiVBSet *>::~NiTMapBase<NiTPointerAllocator<unsigned int>,unsigned int,NiVBSet *> | NiStaticGeometryGroup.obj | debug, object-file run extension, low
void FUN_00e94220_cls::InsertSortedNode(NiVBBlock* node)
{
    if (m_pFirstNode != 0)
    {
        NiVBBlock* prev = 0;
        NiVBBlock* cur = m_pFirstNode;
        unsigned int key = node->m_24;
        do
        {
            if (cur->m_24 > key)
            {
                goto found;
            }
            prev = cur;
            cur = reinterpret_cast<NiVBBlock*>(cur->m_pkNextBlock);
        } while (cur != 0);
        prev->m_pkNextBlock = reinterpret_cast<unsigned int>(node);
        node->m_pkPrevBlock = reinterpret_cast<unsigned int>(prev);
        node->m_pkNextBlock = 0;
        return;
    found:
        if (prev != 0)
        {
            prev->m_pkNextBlock = reinterpret_cast<unsigned int>(node);
        }
        cur->m_pkPrevBlock = reinterpret_cast<unsigned int>(node);
        node->m_pkNextBlock = reinterpret_cast<unsigned int>(cur);
        node->m_pkPrevBlock = reinterpret_cast<unsigned int>(prev);
        if (cur != m_pFirstNode)
        {
            return;
        }
        m_pFirstNode = node;
    }
    else
    {
        m_pFirstNode = node;
        node->m_pkNextBlock = 0;
        m_pFirstNode->m_pkPrevBlock = 0;
    }
}

extern unsigned int DAT_011c0cdc;
extern int DAT_010f0f8c;
void* __cdecl Object_DispatchCommandFour(unsigned int);
__forceinline NiVBBlock* InitializeVBBlock(NiVBBlock* block)
{
    block->m_apkChips.unk34 = 0;
    block->m_apkChips.unk3A = 1;
    block->m_apkChips.m_36 = 0;
    block->m_apkChips.m_38 = 0;
    block->m_apkChips.m_30 = 0;
    block->m_apkChips.unk00 = &DAT_010f0f8c;
    block->ClearAllData();
    return block;
}
extern NiVBBlock* DAT_0126fa30;
// Allocates DAT_011c0cdc NiVBBlock objects, initializes each, and links them into a doubly linked list headed by DAT_0126fa30.
// @fnv 0x00e944f0
void __cdecl AllocateVBBlocks()
{
    for (unsigned int i = 0; i < DAT_011c0cdc; ++i)
    {
        NiVBBlock* pRawBlock = static_cast<NiVBBlock*>(Object_DispatchCommandFour(sizeof(NiVBBlock)));
        NiVBBlock* p = pRawBlock ? InitializeVBBlock(pRawBlock) : 0;
        NiVBBlock* previous = reinterpret_cast<NiVBBlock*>(p->m_pkNextBlock);
        NiVBBlock* next = reinterpret_cast<NiVBBlock*>(p->m_pkPrevBlock);
        if (previous)
            previous->m_pkPrevBlock = reinterpret_cast<unsigned int>(next);
        if (next)
            next->m_pkNextBlock = reinterpret_cast<unsigned int>(previous);
        if (DAT_0126fa30)
            DAT_0126fa30->m_pkPrevBlock = reinterpret_cast<unsigned int>(p);
        p->m_pkNextBlock = reinterpret_cast<unsigned int>(DAT_0126fa30);
        p->m_pkPrevBlock = 0;
        DAT_0126fa30 = p;
    }
}

struct VBSet
{
    char _00[0x30];
    unsigned int m_uiThreshold;
    NiVBBlock* RemoveFirstNodeAtLeast(unsigned int uiSize);
    NiVBBlock* NiVBSet_CreateBlock(unsigned int uiSize);
    void InsertSortedNode(NiVBBlock* pkBlock);
    void* NiVBSet_AllocateChip(unsigned int uiSize, bool bForceNewBlock);
};

// @fnv 0x00e94650
// src: COMMUNITY 0x00e94650
// pdb: NiVBSet::AllocateChip | NiVBSet.obj | retail, upstream name already matches, high
// pdb params: uiSize, bForceNewBlock
// pdb locals: pkVBChip, pkVBBlock
void* VBSet::NiVBSet_AllocateChip(unsigned int uiSize, bool bForceNewBlock)
{
    void* pvChip = 0;
    NiVBBlock* pkBlock = 0;
    if (!bForceNewBlock)
        pkBlock = RemoveFirstNodeAtLeast(uiSize);
    if (!pkBlock)
        pkBlock = NiVBSet_CreateBlock(uiSize);
    if (pkBlock)
    {
        pvChip = pkBlock->NiVBBlock_AllocateChip(uiSize);
        if (pkBlock->m_uiValue24 > m_uiThreshold)
            InsertSortedNode(pkBlock);
    }
    return pvChip;
}

struct VBLayout;
struct VBArray
{
    unsigned int m_uiCount;
    VBLayout** m_pData;
    void FUN_00ba3aa0(unsigned int, VBLayout**);
};
// Chip layout used by the block's chip array and the chip free list.
struct VBLayout
{
    void* m_pBuffer;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiSize;
    unsigned int unk10;
    unsigned int m_uiValueBeforeCount;
    VBLayout* m_pkNext;
    VBLayout* m_pkPrev;
};
extern VBLayout* g_pkFreeList;
// @fnv 0x00e98500
// pdb: NiVBBlock::DeleteChips | NiVBBlock.obj | retail, object-file run extension, low
// pdb locals: pkVBChip, pkNext
unsigned int __fastcall FreeVBBlock(NiVBBlock* object, void*, unsigned int index)
{
    NiVBBlock* pLayout = object;
    unsigned int result = 0;
    VBLayout* block = reinterpret_cast<VBLayout**>(pLayout->m_apkChips.m_30)[index];
    if (block)
    {
        result = block->m_uiValueBeforeCount;
        if (pLayout->m_uiValue20 - result == block->m_uiSize)
        {
            pLayout->m_uiValue20 = 0;
            if (index > 0)
            {
                VBLayout** ppCursor = reinterpret_cast<VBLayout**>(pLayout->m_apkChips.m_30);
                unsigned int remain = index;
                do
                {
                    VBLayout* current = *ppCursor;
                    if (current)
                    {
                        unsigned int end = current->m_uiValueBeforeCount + current->m_uiSize;
                        if (end > pLayout->m_uiValue20)
                            pLayout->m_uiValue20 = end;
                    }
                    ++ppCursor;
                } while (--remain);
            }
        }
        pLayout->m_uiValue24 = pLayout->m_uiSize - pLayout->m_uiValue20;
        pLayout->m_uiValue28 += result;
        VBLayout* removed = 0;
        reinterpret_cast<VBArray*>(&pLayout->m_apkChips)->FUN_00ba3aa0(index, &removed);
        block->m_pkPrev = 0;
        block->m_pkNext = g_pkFreeList;
        if (g_pkFreeList)
            g_pkFreeList->m_pkPrev = block;
        g_pkFreeList = block;
    }
    return result;
}

struct HashNode
{
    HashNode* next;
    unsigned int key;
    unsigned int value;
};
struct HashTableBase
{
    virtual void Reserved0() = 0;
    virtual unsigned int BucketIndex(unsigned int key) = 0;
    virtual bool EqualKey(unsigned int key, unsigned int existingKey) = 0;
    virtual void Initialize(HashNode* entry, unsigned int key, unsigned int value) = 0;
    virtual void Reserved4() = 0;
    virtual HashNode* AllocateNode() = 0;

    unsigned int tableSize;
    HashNode** buckets;
    unsigned int elementCount;
    void InsertOrUpdate(unsigned int key, unsigned int value);
};
// Looks up key in the bucket chain, updates the value if found, otherwise allocates, initializes and prepends a new node and increments elementCount.
// @fnv 0x00b57ea0
// pdb: NiTMapBase<NiTPointerAllocator<unsigned int>,NiNode *,unsigned int>::SetAt | NiBSBoneLODController.obj | debug, call graph, medium
// pdb params: key, val
// pdb locals: pkItem, uiIndex, uiDepth
void HashTableBase::InsertOrUpdate(unsigned int key, unsigned int value)
{
    unsigned int bucketIndex = BucketIndex(key);
    HashNode* node = buckets[bucketIndex];
    while (node)
    {
        if (EqualKey(key, node->key))
        {
            node->value = value;
            return;
        }
        node = node->next;
    }
    HashNode* newNode = AllocateNode();
    Initialize(newNode, key, value);
    newNode->next = buckets[bucketIndex];
    buckets[bucketIndex] = newNode;
    ++elementCount;
}

struct VBArr
{
    unsigned int NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(NiVBBlock** ppBlock);
};

struct VBDev;
typedef int(__stdcall* VBDev_fn)(VBDev* pSelf, unsigned int uiSize, unsigned int uiA, unsigned int uiB,
                                 unsigned int uiC, unsigned int* puiOut, unsigned int uiZero);
struct VBDev
{
    VBDev_fn* m_pVtbl;
};

struct VBSetX
{
    unsigned int m_u00;
    unsigned int m_u04;
    unsigned int m_u08;
    unsigned int m_u0C;
    VBDev* m_pDev;
    unsigned int m_u14;
    unsigned int m_u18;
    VBArr m_kArr;
    NiVBBlock* NiVBSet_CreateBlock(unsigned int uiSize);
};

__forceinline NiVBBlock* PopBlock()
{
    if (!DAT_0126fa30)
        AllocateVBBlocks();
    NiVBBlock* block = DAT_0126fa30;
    DAT_0126fa30 = reinterpret_cast<NiVBBlock*>(DAT_0126fa30->m_pkNextBlock);
    if (DAT_0126fa30)
        DAT_0126fa30->m_pkPrevBlock = 0;
    block->m_pkNextBlock = 0;
    block->m_pkPrevBlock = 0;
    return block;
}

// Allocates a NiVBBlock of at least uiSize bytes via the device, fills its fields, and inserts it into the VBArr.
// @fnv 0x00e94580
// src: COMMUNITY 0x00e94580
// pdb: NiVBSet::CreateBlock | NiVBSet.obj | retail, upstream name already matches, high
// pdb params: uiSize
// pdb locals: pkVB, d3dRet, pkVBBlock, uiVBSize, uiIndex
NiVBBlock* VBSetX::NiVBSet_CreateBlock(unsigned int uiSize)
{
    unsigned int uiAllocSize = uiSize;
    if ((m_u08 & 0x10000000) == 0)
    {
        if (uiAllocSize <= m_u0C)
            uiAllocSize = m_u0C;
    }
    uiSize = 0;
    if (m_pDev->m_pVtbl[26](m_pDev, uiAllocSize, m_u14, m_u04, m_u18, &uiSize, 0) < 0)
        return 0;

    NiVBBlock* p = PopBlock();
    p->m_00 = reinterpret_cast<unsigned int>(this);
    p->m_pkVB = uiSize;
    p->m_uiSize = uiAllocSize;
    p->m_24 = uiAllocSize;
    p->m_28 = uiAllocSize;
    p->m_uiFVF = m_u04;
    p->m_uiFlags = m_u08;
    p->m_1c = m_u18;
    NiVBBlock* pBlock = p;
    NiVBBlock* __restrict usageBlock = p;
    usageBlock->m_uiUsage = m_u14;
    p->m_uiIndex = m_kArr.NiTArray_void_cdecl_NiStream_NiObject_NiTMallocInterface_void_cdecl_NiStream_NiObject_AddFirstEmpty(&pBlock);
    return p;
}

extern "C" void __cdecl _NiFree_00aa10f0(void*);
struct VBReleaseInterface
{
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTArray.h"
// Gamebryo NiTArray.inl / NiTCollection.h bodies the original inlines (FUN_00aa10f0 = NiFree)
template <class T> inline void NiTMallocInterface<T>::Deallocate(T* pArray)
{
    _NiFree_00aa10f0(pArray);
}
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::~NiTArray()
{
    TAlloc::Deallocate(m_pBase);
}
template <class T, class TAlloc> inline T NiTArray<T, TAlloc>::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex >= m_usSize)
        return T(0);
    T item = m_pBase[uiIndex];
    m_pBase[uiIndex] = T(0);
    if (item)
        --m_usESize;
    if (uiIndex == (unsigned short)(m_usSize - 1))
        --m_usSize;
    return item;
}
typedef NiTArray<NiVBBlock*, NiTMallocInterface<NiVBBlock*> > CleanupBlockArray;

struct VBSetCleanup
{
    unsigned int index;
    unsigned int format;
    unsigned int flags;
    unsigned int blockSize;
    VBReleaseInterface* buffer;
    unsigned int usage;
    unsigned int pool;
    CleanupBlockArray blocks;
    void NiVBSet_dtor();
};

// Releases each block's VB interface, links non-null blocks into a list, releases the buffer, and destroys the array.
// @fnv 0x00e943c0
// src: XBOX_RETAIL_PDB 0x00e943c0
// pdb: NiVBSet::~NiVBSet | NiVBSet.obj | retail, object-file gap fill, high
// pdb locals: i, pkBlock
void VBSetCleanup::NiVBSet_dtor()
{
    for (unsigned int i = 0; i < blocks.m_usSize; ++i)
    {
        NiVBBlock* block = blocks.RemoveAt(i);
        if (block)
        {
            if (block->m_pkVB)
            {
                reinterpret_cast<VBReleaseInterface*>(block->m_pkVB)->Release();
                block->m_pkVB = 0;
            }
            block->ClearAllData();
            NiVBBlock* previous = reinterpret_cast<NiVBBlock*>(block->m_pkNextBlock);
            NiVBBlock* next = reinterpret_cast<NiVBBlock*>(block->m_pkPrevBlock);
            if (previous)
                previous->m_pkPrevBlock = reinterpret_cast<unsigned int>(next);
            if (next)
                next->m_pkNextBlock = reinterpret_cast<unsigned int>(previous);
            NiVBBlock* head = DAT_0126fa30;
            if (head)
            {
                head->m_pkPrevBlock = reinterpret_cast<unsigned int>(block);
                head = DAT_0126fa30;
            }
            block->m_pkNextBlock = reinterpret_cast<unsigned int>(head);
            block->m_pkPrevBlock = 0;
            DAT_0126fa30 = block;
        }
    }
    if (buffer)
        buffer->Release();
    buffer = 0;
    blocks.CleanupBlockArray::~CleanupBlockArray();
}
