
// src/havok/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../../../include/hkArray.h"
#include "../../../../../../../../../../include/hkBool.h"
#include "../../../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../../../include/hkResult.h"
#include "../../../../../../../../../../include/MemoryManager.h"
#include "../../../../../../../../../../include/hkMemoryRouter.h"

extern char g_0126955c_arg0;

// Calls two virtual functions on self: one with a pointer to g_0126955c_arg0, then one with no arguments.
// @fnv 0x00d9fb50
// src: XBOX_PDB 0x00d9fb50
// pdb: hkpDefaultToiResourceMgr::calcContentStatistics | hkpDefaultToiResourceMgr.obj | retail, string-set bridge, high
// pdb params: collector, cls
void __stdcall hkpDefaultToiResourceMgr_calcContentStatistics(void* collector, int cls)
{
    (*(void(__thiscall**)(void*, char*))(*(char**)collector + 0x18))(collector, &g_0126955c_arg0);
    (*(void(__thiscall**)(void*))(*(char**)collector + 0x1c))(collector);
}

struct hkpToiEvent;

// Local until include/hkpToiResources.h exists; the resource buffer is at +0x18.
// pdb: structure hkpToiResources, size 0x20, 8 members
struct hkpToiResources
{
    int m_minPriorityToProcess;
    int m_maxNumEntities;
    int m_maxNumActiveEntities;
    int m_maxNumConstraints;
    int m_numToiSolverIterations;
    int m_numForcedToiFinalSolverIterations;
    char* m_scratchpad;
    int m_scratchpadSize;
};

// Local until include/hkpDefaultToiResourceMgr.h exists; reflected size is 0x10.
// pdb: class hkpDefaultToiResourceMgr, size 0x10, bases: hkpToiResourceMgr, 2 members
class hkpDefaultToiResourceMgr
{
  public:
    hkpDefaultToiResourceMgr();
    virtual ~hkpDefaultToiResourceMgr();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_scratchPadCapacity;
    int m_defaultScratchpadSize;

    void* AllocateMemory(int, int, hkpToiResources*);
    void* FUN_00d9fc70(unsigned char flag);

    hkBool Object_UpdateFields_00d9fb40(const hkpToiEvent& event) throw();
    hkResult AllocateToiResources(const hkpToiEvent& event, const hkArray<hkpToiEvent>& otherEvents,
                                    hkpToiResources& resourcesOut);
};

extern int DAT_010d4310;

// @fnv 0x00d9fb90
hkpDefaultToiResourceMgr::hkpDefaultToiResourceMgr()
{
    m_sReferenceCount = 1;
    *(void**)this = (void*)&DAT_010d4310;
    m_defaultScratchpadSize = 0x20000;
}

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

// Returns the resource buffer through the solver allocator, using the allocated byte count.
// @fnv 0x00d9fc30
// pdb: hkpDefaultToiResourceMgr::endToiAndFreeResources | hkpDefaultToiResourceMgr.obj | retail, vtable slot, high
// pdb params: event, otherEvents, resources
void* hkpDefaultToiResourceMgr::AllocateMemory(int, int, hkpToiResources* resources)
{
    int size = m_scratchPadCapacity;
    char* buffer = resources->m_scratchpad;
    hkMemoryRouter* pRouter = _D1A0E0GetMemoryRouter();
    // The solver allocator occupies the router slot at 0x18.
    MemoryManager* manager = *(MemoryManager**)((char*)pRouter + 0x18);
    typedef void* (__thiscall* ReturnBufferFunction)(MemoryManager*, char*, int);
    return (*(ReturnBufferFunction**)manager)[4](manager, buffer, size);
}

typedef void(__thiscall* FUN_00d9fc70_Callback)(MemoryManager*, void*, unsigned short);

// Destroys the manager, optionally releases its storage, and returns this.
// @fnv 0x00d9fc70
// pdb: hkpDefaultToiResourceMgr::`scalar deleting destructor' | hkpDefaultToiResourceMgr.obj | debug, vtable slot, medium
void* hkpDefaultToiResourceMgr::FUN_00d9fc70(unsigned char flag)
{
    this->hkpDefaultToiResourceMgr::~hkpDefaultToiResourceMgr();

    if (flag & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        MemoryManager* memoryManager = reinterpret_cast<MemoryManager*>(router->m_heap);
        unsigned short size = m_usMemSizeAndFlags;
        FUN_00d9fc70_Callback callback = (*(FUN_00d9fc70_Callback**)memoryManager)[2];

        callback(memoryManager, this, size);
    }

    return this;
}

// @fnv 0x00d9fb70
// src: GUESS 0x00d9fb70 (confidence: high)
// pdb: hkpDefaultToiResourceMgr::resourcesDepleted | hkpDefaultToiResourceMgr.obj | debug, vtable slot, medium
// pdb locals: assertBuf, ostr
int __cdecl hkpDefaultToiResourceMgr_ReturnOne()
{
    return 1;
}

// FUN_00d9fc60
// Returns the address of the global registration object that lives at
// DAT_0126955c.  The startup code fills that object (13 dwords) through a
// constructor call, and this getter hands out its address.
extern int hkpDefaultToiResourceMgrClass;

// @fnv 0x00d9fc60
// src: GUESS 0x00d9fc60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00d9fc60()
{
    return &hkpDefaultToiResourceMgrClass;
}

// @fnv 0x00d9fb80
// src: GUESS 0x00d9fb80 (confidence: high)
int __stdcall Object_ReturnZero_00d9fb80(int arg0)
{
    return 0;
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline hkMemoryAllocator& solverAllocator(hkMemoryRouter& router)
{
    return **(hkMemoryAllocator**)((char*)&router + 0x18);
}

template <class T> inline T* hkMemoryAllocator::_bufAlloc(int& n)
{
    int nb = n * sizeof(T);
    T* p = static_cast<T*>(bufAlloc(nb));
    n = nb / sizeof(T);
    return p;
}

// @fnv 0x00d9fbb0
// pdb: hkpDefaultToiResourceMgr::beginToiAndSetupResources | hkpDefaultToiResourceMgr.obj | retail, vtable slot, high
// pdb params: event, otherEvents, resourcesOut
// pdb locals: assertBuf, ostr
hkResult hkpDefaultToiResourceMgr::AllocateToiResources(const hkpToiEvent& event,
                                                       const hkArray<hkpToiEvent>& otherEvents,
                                                       hkpToiResources& resourcesOut)
{
    if (Object_UpdateFields_00d9fb40(event))
    {
        m_scratchPadCapacity = resourcesOut.m_scratchpadSize = m_defaultScratchpadSize;
        resourcesOut.m_scratchpad = solverAllocator(hkMemoryRouter_getInstance())._bufAlloc<char>(m_scratchPadCapacity);
        resourcesOut.m_maxNumActiveEntities = 1000;
        resourcesOut.m_maxNumConstraints = 1000;
        resourcesOut.m_maxNumEntities = 1000;
        resourcesOut.m_numToiSolverIterations = 3;
        resourcesOut.m_numForcedToiFinalSolverIterations = 4;
        resourcesOut.m_minPriorityToProcess = 3;
        return HK_SUCCESS;
    }
    return HK_FAILURE;
}
