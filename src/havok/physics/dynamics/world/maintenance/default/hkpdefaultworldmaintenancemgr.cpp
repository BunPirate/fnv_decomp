
// src/havok/physics/dynamics/world/maintenance/default/hkpdefaultworldmaintenancemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/maintenance/default/hkpdefaultworldmaintenancemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpWorld.h"
#include "../../../../../../../include/hkStepInfo.h"

struct S_00d0b250_RefObj
{
    virtual ~S_00d0b250_RefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00d0b250_RefObj() : m_sReferenceCount(1)
    {}
};

// pdb: class hkpDefaultWorldMaintenanceMgr, size 0x10, bases: hkpWorldMaintenanceMgr, 2 members
struct hkpDefaultWorldMaintenanceMgr : S_00d0b250_RefObj // src: EXE 0x010cd34c (vtable; old: FUN_00d0b250)
{
    float m_minAllowedTimeValue; // src: XBOX_RETAIL_PDB +0x8 (old: m_kPointA)
    float m_maxAllowedTimeValue; // src: XBOX_RETAIL_PDB +0xc (old: m_kPointB)
    hkpDefaultWorldMaintenanceMgr();
    virtual ~hkpDefaultWorldMaintenanceMgr();
};

// Initializes the object's two float members to 33.0 and 63.0 and sets the base reference count to 1.
// @fnv 0x00d0b250
hkpDefaultWorldMaintenanceMgr::hkpDefaultWorldMaintenanceMgr() : m_minAllowedTimeValue(33.0f), m_maxAllowedTimeValue(63.0f)
{}

struct S_00d0b230_Dst
{
    int unk00, unk04, unk08, unk0C, unk10;
    float unk14;
    float unk18;
};

struct S_00d0b230_Arg
{
    int unk00, unk04;
    S_00d0b230_Dst* unk08;
};

struct FUN_00d0b230_class
{
    int unk00, unk04;
    float unk08;
    void SetDstFields(S_00d0b230_Arg* a);
};

// @fnv 0x00d0b230
void FUN_00d0b230_class::SetDstFields(S_00d0b230_Arg* a)
{
    S_00d0b230_Dst* pDst = a->unk08;
    pDst->unk14 = unk08;
    pDst->unk18 = unk08;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
#include "../../../../../../../include/hkpSimulation.h"
#include "../../../../../../../include/hkpSimulationIsland.h"
extern DWORD DAT_0126835c;
extern const char str_010cd380[];
extern const char str_010cd378[];
extern const char str_010cd36c[];
extern const char str_01076f38[];
extern void __cdecl hkpWorldOperationUtil_splitSimulationIslands(void*);
struct TraceBuffer
{
    int unk00;
    unsigned char* current;
    int unk08;
    unsigned char* end;
};
struct TraceEntry16
{
    volatile unsigned int type;
    volatile unsigned int timestamp;
    unsigned int unk08;
    volatile unsigned int detail;
};
struct TraceEntry12
{
    volatile unsigned int type;
    volatile unsigned int timestamp;
    unsigned int unk08;
};
struct FUN_00d0b280_cls
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    void hkpDefaultWorldMaintenanceMgr_performMaintenance(float* world, float* stepInfo);
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(float* first, float* second);
};
// Writes trace entries, calls FUN_00cb6f30(first), and if *second >= unk0c calls FUN_00d0b3e0(first, second) between further trace entries.
// @fnv 0x00d0b280
// src: HAVOK_LIB 0x00d0b280
// pdb: hkpDefaultWorldMaintenanceMgr::performMaintenance | hkpDefaultWorldMaintenanceMgr.obj | retail, string-set bridge, high
// pdb params: world, stepInfo
void FUN_00d0b280_cls::hkpDefaultWorldMaintenanceMgr_performMaintenance(float* world, float* stepInfo)
{
    TraceBuffer* buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    unsigned char* current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry16* entry = (volatile TraceEntry16*)current;
        entry->type = (unsigned int)str_010cd380;
        entry->detail = (unsigned int)str_010cd378;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 16;
        buffer->current = current;
    }
    hkpWorldOperationUtil_splitSimulationIslands(world);
    if (*stepInfo >= unk0c)
    {
        buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
        current = buffer->current;
        if (current < buffer->end)
        {
            volatile TraceEntry12* entry = (volatile TraceEntry12*)current;
            entry->type = (unsigned int)str_010cd36c;
            _ReadWriteBarrier();
            volatile unsigned int timestamp = (unsigned int)__rdtsc();
            entry->timestamp = timestamp;
            current += 12;
            buffer->current = current;
        }
        hkpDefaultWorldMaintenanceMgr_resetWorldTime(world, stepInfo);
    }
    buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry12* entry = (volatile TraceEntry12*)current;
        entry->type = (unsigned int)str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 12;
        buffer->current = current;
    }
}

extern DWORD DAT_0126835c;
extern const char str_010cd380[];
extern const char str_010cd36c[];
extern const char str_01076f38[];

struct FUN_00d0b350_cls
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(float* first, float* second);
    void TraceConditionalCall(float* world, float* stepInfo);
};
// Writes a trace entry, calls FUN_00d0b3e0(first, second) if *second >= unk0c, then writes a closing trace entry.
// @fnv 0x00d0b350
// pdb: hkpDefaultWorldMaintenanceMgr::performMaintenanceNoSplit | hkpDefaultWorldMaintenanceMgr.obj | retail, string-set bridge, high
// pdb params: world, stepInfo
void FUN_00d0b350_cls::TraceConditionalCall(float* world, float* stepInfo)
{
    TraceBuffer* buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    unsigned char* current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry16* entry = (volatile TraceEntry16*)current;
        entry->type = (unsigned int)str_010cd380;
        entry->detail = (unsigned int)str_010cd36c;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 16;
        buffer->current = current;
    }
    if (*stepInfo >= unk0c)
        hkpDefaultWorldMaintenanceMgr_resetWorldTime(world, stepInfo);
    buffer = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    current = buffer->current;
    if (current < buffer->end)
    {
        volatile TraceEntry12* entry = (volatile TraceEntry12*)current;
        entry->type = (unsigned int)str_01076f38;
        _ReadWriteBarrier();
        volatile unsigned int timestamp = (unsigned int)__rdtsc();
        entry->timestamp = timestamp;
        current += 12;
        buffer->current = current;
    }
}

struct CollisionAgentContext
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
    int unk48;
    int unk4C;
    hkStepInfo m_pStepInfo;
};

// The shared world header leaves the step info at 0x1D0 in its padding.
static __forceinline hkStepInfo& WorldStepInfo(hkpWorld* world)
{
    return *reinterpret_cast<hkStepInfo*>(world->pad1C8 + 8);
}

void __cdecl hkpWorldAgentUtil_warpTime(hkpSimulationIsland* island, float oldTime, float newTime, CollisionAgentContext* collisionInput);

struct TimeRebaser
{
    int unk00;
    int unk04;
    float m_newTime;
    void hkpDefaultWorldMaintenanceMgr_resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo);
};

// @fnv 0x00d0b3e0
// src: HAVOK_LIB 0x00d0b3e0
// pdb: hkpDefaultWorldMaintenanceMgr::resetWorldTime | hkpDefaultWorldMaintenanceMgr.obj | retail, upstream name already matches, high
// pdb params: world, stepInfo
void TimeRebaser::hkpDefaultWorldMaintenanceMgr_resetWorldTime(hkpWorld* world, hkStepInfo& stepInfo)
{
    float deltaTime = stepInfo.m_endTime - stepInfo.m_startTime;
    hkStepInfo& si = WorldStepInfo(world);
    const TimeRebaser* owner = this;
    si.m_startTime = owner->m_newTime;
    si.m_endTime = owner->m_newTime + deltaTime;
    si.m_deltaTime = deltaTime;
    si.m_invDeltaTime = 1.0f / si.m_deltaTime;

    float shift = WorldStepInfo(world).m_startTime - stepInfo.m_startTime;
    hkpSimulation* pSimulation = world->m_simulation;
    pSimulation->m_currentTime += shift;
    pSimulation->m_currentPsiTime = WorldStepInfo(world).m_startTime;
    if (pSimulation->m_simulateUntilTime != -1.0f)
    {
        world->m_simulation->m_simulateUntilTime = (float)(world->m_simulation->m_simulateUntilTime + shift);
    }

    for (int iIsland = 0; iIsland < world->m_activeSimulationIslands.m_iElementCount; iIsland++)
    {
        hkpSimulationIsland* island = static_cast<hkpSimulationIsland*>(world->m_activeSimulationIslands.m_data[iIsland]);
        for (int iActor = 0; iActor < island->m_iActorEntryCount; iActor++)
        {
            island->m_kActorEntries[iActor]->m_motion.m_kMotionState.m_kSweptTransform.m_centerOfMass0.w += shift;
        }
        hkpWorldAgentUtil_warpTime(island, stepInfo.m_endTime, WorldStepInfo(world).m_endTime, static_cast<CollisionAgentContext*>(world->m_collisionInput));
    }

    world->m_simulation->shiftTime(shift);
    stepInfo = WorldStepInfo(world);
    static_cast<CollisionAgentContext*>(world->m_collisionInput)->m_pStepInfo = WorldStepInfo(world);
}
