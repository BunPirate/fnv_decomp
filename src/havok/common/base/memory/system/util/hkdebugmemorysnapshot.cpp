
// src/havok/common/base/memory/system/util/hkdebugmemorysnapshot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/util/hkdebugmemorysnapshot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryAllocator.h"

// The router returned by 0x00c85750 exposes the debug allocator at offset 0x14.

class DebugAllocatorRouter
{
public:
    int unk00;
    int unk04;
    int unk08;
    union
    {
        int unk0C;
        int unk0c;
    };
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }

    hkMemoryAllocator& debug();
};

inline hkMemoryAllocator& DebugAllocatorRouter::debug()
{
    // The debug allocator follows the stream allocator in the router layout.
    return **reinterpret_cast<hkMemoryAllocator**>(
        reinterpret_cast<char*>(&m_pStreamAllocator) + sizeof(m_pStreamAllocator));
}

typedef unsigned int hkSnapshotAddress;

// Snapshot metadata is 72 bytes (size, sixteen trace addresses, count); hkEntry is 12 bytes.
struct SnapshotAllocationInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
};

// Both snapshot call sites use this 12-byte layout; no shared snapshot header exists yet.
// pdb: class hkDebugMemorySnapshot, size 0xc, 3 members
class hkDebugMemorySnapshot
{
public:
    hkSnapshotAddress* m_pointers; // src: XBOX_RETAIL_PDB +0x0 (old: m_pAddressList)
    SnapshotAllocationInfo* m_info;
    int m_numPointers; // src: XBOX_RETAIL_PDB +0x8 (old: m_iElementCount)

    void FreeBuffers();
    void Sort();
    void subtract_00dd7090(hkDebugMemorySnapshot& other);
};
// @fnv 0x00dd7090
// src: HAVOK_LIB 0x00dd7090
void hkDebugMemorySnapshot::subtract_00dd7090(hkDebugMemorySnapshot& other)
{
    Sort();
    other.Sort();
    hkSnapshotAddress* a = m_pointers;
    hkSnapshotAddress* aEnd = a + m_numPointers;
    hkSnapshotAddress* b = other.m_pointers;
    hkSnapshotAddress* pBlockBEnd = b + other.m_numPointers;
    while (a < aEnd && b < pBlockBEnd)
    {
        if (*a == *b)
        {
            *a = 0;
            ++a;
            ++b;
        }
        else if (*a < *b)
            ++a;
        else
            ++b;
    }
}

namespace hkRouterDD6E {
extern "C" DebugAllocatorRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

template <typename T> inline void hkDeallocateChunkDD6E(T* p, int n)
{
    hkRouterDD6E::hkMemoryRouter_getInstance().debug().blockFree(p, n * sizeof(T));
}

// Deallocates the two arrays when the first pointer is set, then nulls both pointers and the count.
// @fnv 0x00dd6ec0
void hkDebugMemorySnapshot::FreeBuffers()
{
    if (m_pointers)
    {
        hkDeallocateChunkDD6E(m_pointers, m_numPointers);
        hkDeallocateChunkDD6E(m_info, m_numPointers);
    }
    m_pointers = 0;
    m_info = 0;
    m_numPointers = 0;
}

DebugAllocatorRouter* __cdecl hkMemoryRouter_getInstance();

template <typename T> inline T* hkAllocateDebug(int n)
{
    return (T*)hkMemoryRouter_getInstance()->debug().blockAlloc(n * sizeof(T));
}

template <typename T> inline void hkDeallocateDebug(T* p, int n)
{
    hkMemoryRouter_getInstance()->debug().blockFree(p, n * sizeof(T));
}

bool __cdecl LessThan(const hkSnapshotAddress* a, const hkSnapshotAddress* b);
void __cdecl hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(const hkSnapshotAddress** p, int lo, int hi,
                          bool(__cdecl* cmp)(const hkSnapshotAddress*, const hkSnapshotAddress*));

inline void hkQuickSortQ(const hkSnapshotAddress** p, int size,
                         bool(__cdecl* cmp)(const hkSnapshotAddress*, const hkSnapshotAddress*))
{
    if (size > 1)
    {
        hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(p, 0, size - 1, cmp);
    }
}

// @fnv 0x00dd6f20
void hkDebugMemorySnapshot::Sort()
{
    if (m_numPointers > 1)
    {
        const hkSnapshotAddress** sorted = hkAllocateDebug<const hkSnapshotAddress*>(m_numPointers);
        for (int i = 0; i < m_numPointers; i++)
        {
            sorted[i] = &m_pointers[i];
        }
        hkQuickSortQ(sorted, m_numPointers, LessThan);

        hkSnapshotAddress* pointers = hkAllocateDebug<hkSnapshotAddress>(m_numPointers);
        SnapshotAllocationInfo* info = hkAllocateDebug<SnapshotAllocationInfo>(m_numPointers);
        for (int i = 0; i < m_numPointers; i++)
        {
            pointers[i] = *sorted[i];
            info[i] = m_info[sorted[i] - m_pointers];
        }

        hkDeallocateDebug(sorted, m_numPointers);
        hkDeallocateDebug(m_pointers, m_numPointers);
        hkDeallocateDebug(m_info, m_numPointers);
        m_pointers = pointers;
        m_info = info;
    }
}
