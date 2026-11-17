
// src/havok/common/base/memory/system/hkmemorysystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/hkmemorysystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkThreadMemory.h"

// @fnv 0x00cbc440
// src: COMMUNITY 0x00cbc440
int __stdcall hkMemorySystem_debugTagAddress(int a, int b)
{
    return 1;
}

extern int DAT_01268418;

// @fnv 0x00cbbfc0
// src: XBOX_PDB 0x00cbbfc0
int hkMemorySystem_getInstance()
{
    return DAT_01268418;
}

extern int g_CBBFD0Value;

// @fnv 0x00cbbfd0
// src: GUESS 0x00cbbfd0 (confidence: low)
int __cdecl hkMemorySystem_GetCBBFD0Value()
{
    return g_CBBFD0Value;
}

extern int DAT_010c8efc;

struct FUN_00cbbfe0_This
{
    int unk00;
    void __thiscall SetVirtualTable_00cbbfe0();
};

// @fnv 0x00cbbfe0
// src: GUESS 0x00cbbfe0 (confidence: low)
void FUN_00cbbfe0_This::SetVirtualTable_00cbbfe0()
{
    this->unk00 = reinterpret_cast<int>(&DAT_010c8efc);
}

// FUN_00cbc450 - 10 bytes
//   call 0xcbbfe0
//   mov eax, ecx
//   ret 4
//
// The callee FUN_00cbbfe0 is DEFINED here (stand-in) because MSVC must be able
// to see that it leaves ECX untouched: the original returns `this` in EAX right
// after the call, so `this` has to stay live in ECX across it.  Declaring the
// helper only would make MSVC spill `this` to a callee-saved register.
//
// The stand-in body is behaviourally equivalent to the original callee
// (0x00cbbfe0 = "mov dword ptr [ecx], 0x010c8efc ; ret"): it stores the class
// vtable pointer into the object and returns, never touching ECX.

struct VTable
{
    void* entries[4];
};

extern void FUN_00cbbfe0_dummy();

static const VTable g_vtbl = {
    {(void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy}};

struct MyCls
{
    const VTable* m_vtbl;
    __declspec(noinline) void SetVirtualTable_00cbbfe0();
    MyCls* EvaluateValue_00cbc450(int arg);
};

// src: GUESS 0x00cbbfe0 (confidence: low)
void MyCls::SetVirtualTable_00cbbfe0()
{
    m_vtbl = &g_vtbl;
}

// @fnv 0x00cbc450
// src: GUESS 0x00cbc450 (confidence: low)
MyCls* MyCls::EvaluateValue_00cbc450(int arg)
{
    SetVirtualTable_00cbbfe0();
    return this;
}

// @fnv 0x00cbbff0
// src: COMMUNITY 0x00cbbff0
void __cdecl nullsub_54()
{}

void __cdecl hkOstream_printf(int handle, const char* fmt, ...);
extern const char str_010c9078[];
extern const char str_010c9058[];
extern const char str_010c902c[];
extern const char str_010c900c[];
extern const char str_010c8fe0[];
extern const char str_010c8fc0[];
extern const char str_010c8f94[];
extern const char str_010c8f68[];
extern const char str_010c8f3c[];

template <class T> inline T S00cbc000_max(T a, T b)
{
    return a > b ? a : b;
}
struct S00cbc000_Stats
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

// Formats values derived from S00cbc000_Stats and limit through FUN_00cc0410.
// @fnv 0x00cbc000
// src: HAVOK_LIB 0x00cbc000
// pdb: printDetailedStatistics | hkMemorySystem.obj | retail, upstream name already matches, high
// pdb params: what, ostr, u, softLimit
static __declspec(noinline) void printDetailedStatistics(S00cbc000_Stats* what, unsigned int ostr, int u,
                                              const char* softLimit)
{
    unsigned int total = S00cbc000_max(what->unk00, what->unk04);
    int diff = total - what->unk04 - what->unk0c;
    float fDiff = (float)diff;
    unsigned int sum = what->unk04 + what->unk0c;
    float fRatio = fDiff / (float)sum;
    if (ostr == 0 || ostr == 0x7fffffff)
        ostr = total;
    float fLimit = (float)ostr;
    unsigned int comp = (unsigned int)((1.0f - fRatio) * fLimit);
    unsigned int reserved = total - ostr;
    unsigned int soft = ostr < comp ? ostr : comp;
    float invPct = (float)(100.0 / (float)soft);
    hkOstream_printf(u, str_010c9078, softLimit);
    hkOstream_printf(u, str_010c9058, total);
    if (ostr < total)
    {
        hkOstream_printf(u, str_010c902c, reserved, (double)(((float)reserved * 100.0) / (float)comp));
        hkOstream_printf(u, str_010c900c, ostr);
    }
    hkOstream_printf(u, str_010c8fe0, diff, (double)((fDiff * 100.0) / fLimit));
    hkOstream_printf(u, str_010c8fc0, comp);
    hkOstream_printf(u, str_010c8f94, what->unk04, (double)((float)what->unk04 * invPct));
    hkOstream_printf(u, str_010c8f68, what->unk0c, (double)((float)what->unk0c * invPct));
    hkOstream_printf(u, str_010c8f3c, what->unk08, (double)((float)what->unk08 * invPct));
}

void S00cbc000_Caller(S00cbc000_Stats* s, int handle, unsigned int limit, const char* name)
{
    printDetailedStatistics(s, limit, handle, name);
}

struct hkOstream;
int __cdecl hkOstream_printf(hkOstream* ostr, const char* fmt, ...);

struct SixUnsignedValueRecord
{
    unsigned int m_uiFirstValue;
    unsigned int m_pAllocationMap;
    unsigned int m_uiThirdValue;
    unsigned int m_uiFourthUnsignedValue;
    unsigned int GetFifthValue;
    unsigned int GetSixthValue;
    SixUnsignedValueRecord()
        : m_uiFirstValue(0), m_pAllocationMap(0), m_uiThirdValue(0), m_uiFourthUnsignedValue(0), GetFifthValue(0),
          GetSixthValue(0)
    {}
};

#include "../../../../../../include/hkStackMemory.h"

#include "../../../../../../include/hkArray.h"

struct MemSystemInfo
{
    hkMemoryAllocator* m_pStreamAllocator;
    hkArray<hkThreadMemory*> m_threadMemory;
    hkArray<hkStackMemory*> m_kAllocatorList;
    int m_stackTotal;
    int m_heapSoftLimit;
};

struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkMemoryAllocator* m_pAllocator;
    hkMemoryAllocator* m_pSolverAllocator;
    hkMemoryAllocator& debugAllocator()
    {
        return *m_pAllocator;
    }
    hkMemoryAllocator& solverAllocator()
    {
        return *m_pSolverAllocator;
    }
};
AllocatorHolder* __cdecl hkMemoryRouter_getInstance();

namespace MathUtilities {
template <typename T> inline T max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> inline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

// src: HAVOK_LIB 0x00cbc000
static __declspec(noinline) void printDetailedStatistics(hkOstream* what, const char* ostr, const SixUnsignedValueRecord& u,
                                              unsigned int softLimit)
{
    unsigned int total = MathUtilities::max2(u.m_uiFirstValue, u.m_pAllocationMap);
    int overhead = total - u.m_pAllocationMap - u.m_uiFourthUnsignedValue;
    float fOverhead = (float)overhead;
    float overheadRatio = fOverhead / (float)(u.m_pAllocationMap + u.m_uiFourthUnsignedValue);
    if (softLimit == 0 || softLimit == 0x7fffffff)
        softLimit = total;
    float fLimit = (float)softLimit;
    unsigned int available = (unsigned int)((1.0f - overheadRatio) * fLimit);
    unsigned int reserved = total - softLimit;
    unsigned int avail = MathUtilities::min2(softLimit, available);
    float scale = (float)(100.0 / avail);
    hkOstream_printf(what, "\t%s:\n", ostr);
    hkOstream_printf(what, "            totalSize:   %10i\n", total);
    if (softLimit < total)
    {
        hkOstream_printf(what, "\n            - reserved:  %10i (%4.1f%%)\n", reserved, reserved * 100.0 / available);
        hkOstream_printf(what, "            = softlimit: %10i\n", softLimit);
    }
    hkOstream_printf(what, "            - overhead:  %10i (%4.1f%%)\n", overhead, fOverhead * 100.0 / fLimit);
    hkOstream_printf(what, "            = available: %10i\n", available);
    hkOstream_printf(what, "              used:      %10i (%4.1f%%)\n", u.m_pAllocationMap, u.m_pAllocationMap * scale);
    hkOstream_printf(what, "              free:      %10i (%4.1f%%)\n", u.m_uiFourthUnsignedValue,
                 u.m_uiFourthUnsignedValue * scale);
    hkOstream_printf(what, "              peak:      %10i (%4.1f%%)\n\n", u.m_uiThirdValue, u.m_uiThirdValue * scale);
}

// Writes heap, thread, stack, solver, and debug memory statistics to ostr using info and FUN_00cbc000.
// @fnv 0x00cbc220
// src: HAVOK_LIB 0x00cbc220
// pdb: hkMemorySystem::_printStatistics | hkMemorySystem.obj | retail, string-set bridge, high
// pdb params: ostr, input
// pdb locals: u
void __stdcall hkMemorySystem__printStatistics(hkOstream* ostr, MemSystemInfo* input)
{
    SixUnsignedValueRecord stats;
    input->m_pStreamAllocator->getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(stats));
    unsigned int heapInUse = stats.m_pAllocationMap;
    printDetailedStatistics(ostr, "Heap", stats, input->m_heapSoftLimit);

    hkOstream_printf(ostr, "\tThreadMemory (=CachedHeapMemory)\n");
    int total = 0;
    for (int i = 0; i < input->m_threadMemory.GetLogicalSize(); i++)
    {
        unsigned int iStackSize = input->m_threadMemory[i]->ComputeWeightedSum();
        if (iStackSize > 0)
        {
            hkOstream_printf(ostr, "            Thread %i  size %10i\n", i, iStackSize);
            total += iStackSize;
        }
    }
    hkOstream_printf(ostr, "            = total %i\n\n", total);

    hkOstream_printf(ostr, "\tStackMemory\n");
    int stackTotal = 0;
    for (int iStackIndex = 0; iStackIndex < input->m_kAllocatorList.GetLogicalSize(); iStackIndex++)
    {
        hkStackMemory* pStackTriple = input->m_kAllocatorList[iStackIndex];
        int used;
        int iStackSize = (char*)pStackTriple->m_end.val() - (char*)pStackTriple->m_start.val();
        stackTotal += iStackSize;
        used = iStackSize - (int)((char*)pStackTriple->m_end.val() - (char*)pStackTriple->m_next.val());
        hkOstream_printf(ostr, "            Thread %i  size %10i      used:    %6i (%4.1f%%)\n", iStackIndex, iStackSize,
                     used, used * 100.0 / iStackSize);
    }
    if (input->m_kAllocatorList.GetLogicalSize() == 0)
    {
        stackTotal = input->m_stackTotal;
    }
    hkOstream_printf(ostr, "            = total %i\n\n", stackTotal);

    hkMemoryRouter_getInstance()->solverAllocator().getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(stats));
    hkOstream_printf(ostr, "\t%s:\n", "Solver");
    hkOstream_printf(ostr, "            totalSize:   %10i\n", stats.m_uiFirstValue);
    hkOstream_printf(ostr, "              peak:      %10i (%4.1f%%)\n\n", stats.m_uiThirdValue,
                 (float)stats.m_uiThirdValue * 100.0 / (float)stats.m_uiFirstValue);

    hkMemoryRouter_getInstance()->debugAllocator().getMemoryStatistics(reinterpret_cast<hkMemoryAllocator::MemoryStatistics&>(stats));
    if (heapInUse == stats.m_pAllocationMap)
    {
        hkOstream_printf(ostr, "\tDebugMem: Not used.\n\n");
    }
    else
    {
        printDetailedStatistics(ostr, "DebugMem", stats, 0x7fffffff);
    }
}
