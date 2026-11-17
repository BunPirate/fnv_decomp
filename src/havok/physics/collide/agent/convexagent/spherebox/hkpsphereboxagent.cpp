#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpSymmetricAgentFlipCollector.h"

extern void __cdecl hkpSphereBoxAgent_staticGetPenetrations(int a, int b, int input, int d);
// @fnv 0x00d3c590
void __stdcall ForwardToD3C440(int a, int b, int c, int d)
{
    hkpSphereBoxAgent_staticGetPenetrations(a, b, c, d);
}

struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
    void AppendRecordAndRegisterAgents(Conversion*, int, int);
};
void hkpSphereBoxAgent_createBoxSphereAgent();
void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_staticGetPenetrations();
void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_staticGetClosestPoints();
void Object_UpdateFields_00d3ac80();
void CreateD3C380Obj();
void hkpSphereBoxAgent_staticGetPenetrations();
void hkpSphereBoxAgent_staticGetClosestPoints();
void Object_ProcessEntries_00daf8e0();
// Fills a Conversion with function pointers and flags and registers it twice with the registry, once for 4->1 and once for 1->4.
// @fnv 0x00d3cef0
// src: HAVOK_LIB 0x00d3cef0
// pdb: hkpSphereBoxAgent::registerAgent | hkpSphereBoxAgent.obj | retail, upstream name already matches, high
// pdb params: dispatcher
// pdb locals: af
void __cdecl hkpSphereBoxAgent_registerAgent(Registry* dispatcher)
{
    Conversion conversion;
    conversion.convert = hkpSphereBoxAgent_createBoxSphereAgent;
    conversion.create = hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_staticGetPenetrations;
    conversion.copy = hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_staticGetClosestPoints;
    conversion.destroy = Object_UpdateFields_00d3ac80;
    conversion.enabled = true;
    conversion.supported = false;
    dispatcher->AppendRecordAndRegisterAgents(&conversion, 4, 1);
    conversion.convert = CreateD3C380Obj;
    conversion.create = hkpSphereBoxAgent_staticGetPenetrations;
    conversion.copy = hkpSphereBoxAgent_staticGetClosestPoints;
    conversion.destroy = Object_ProcessEntries_00daf8e0;
    conversion.enabled = false;
    conversion.supported = false;
    dispatcher->AppendRecordAndRegisterAgents(&conversion, 1, 4);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
extern void __cdecl hkpSphereBoxAgent_staticGetClosestPoints(void*, void*, int, void*);
// Builds a hkpSymmetricAgentFlipCollector from DAT_0104da48 and arg4, then calls FUN_00d3cc00 with arg2, arg1, arg3 and the collector.
// @fnv 0x00d3d040
// src: XBOX_RETAIL_PDB 0x00d3d040
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetClosestPoints | hkpSphereBoxAgent.obj | retail, object-file gap fill, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void __cdecl hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_staticGetClosestPoints(void* bodyA, void* bodyB, int input, int collector)
{
    // The original initializes stack storage directly, without collector lifetime calls.
    void* storage[sizeof(hkpSymmetricAgentFlipCollector) / sizeof(void*)];
    hkpSymmetricAgentFlipCollector& local = *(hkpSymmetricAgentFlipCollector*)storage;
    *(void**)&local = &DAT_010ce7fc;
    local.m_earlyOutDistance = DAT_0104da48;
    local.m_collector = (void*)collector;
    hkpSphereBoxAgent_staticGetClosestPoints(bodyB, bodyA, input, &local);
}

struct S_00d3c3c0_Holder
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int idx, int arg);
};
struct S_00d3c3c0_Obj
{
    virtual void v00(int flag);
    int unk04;
    S_00d3c3c0_Holder* unk08;
    unsigned short unk0c;
    void hkpSphereBoxAgent_cleanup(int constraintOwner);
};
// If unk0c is not 0xffff, calls v14 on unk08 with unk0c and arg, then calls v00 with 1.
// @fnv 0x00d3c3c0
// src: HAVOK_SRC 0x00d3c3c0
// pdb: hkpSphereBoxAgent::cleanup | hkpSphereBoxAgent.obj | retail, upstream name already matches, high
// pdb params: constraintOwner
void S_00d3c3c0_Obj::hkpSphereBoxAgent_cleanup(int constraintOwner)
{
    int idx = unk0c;
    if ((unsigned short)idx != 0xffff)
        unk08->v14(idx, constraintOwner);
    v00(1);
}

struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct SmallRecord
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};

extern char DAT_010cf018[];

hkMemoryRouter* hkMemoryRouter_getInstance();

// @fnv 0x00d3c400
// src: XBOX_PDB 0x00d3c400
// pdb: hkpSphereBoxAgent::createBoxSphereAgent | hkpSphereBoxAgent.obj | retail, upstream name already matches, high
// pdb params: bodyA, bodyB, input, mgr
void __cdecl hkpSphereBoxAgent_createBoxSphereAgent(int bodyA, int bodyB, int input, int mgr)
{
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    ObjAllocator* allocator = (ObjAllocator*)pAllocHolder->m_heap;
    SmallRecord* pRecord = (SmallRecord*)allocator->Alloc(0x10);
    pRecord->m_w04 = 0x10;
    pRecord->m_w06 = 1;
    pRecord->m_i08 = mgr;
    pRecord->m_w0C = 0xffff;
    pRecord->m_vptr = DAT_010cf018;
}

class D3CF80CollectorBase
{
  public:
    D3CF80CollectorBase() : m_bHit(false)
    {}
    virtual void AddCdPoint(const void* pkEvent) = 0;

    bool m_bHit;
};

class D3CF80Collector : public D3CF80CollectorBase
{
  public:
    D3CF80Collector(int iFilter) : m_iFilter(iFilter)
    {}
    virtual void AddCdPoint(const void* pkEvent);

    int m_iFilter;
};

class D3CF80Agent
{
  public:
    void ForwardToD3C440(void* pkA, void* pkB, void* pkInput, D3CF80Collector* pkCollector);
    void CollectFilteredEvents(void* bodyA, void* bodyB, void* input, int collector);
};

// @fnv 0x00d3cf80
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::getPenetrations | hkpSphereBoxAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void D3CF80Agent::CollectFilteredEvents(void* bodyA, void* bodyB, void* input, int collector)
{
    D3CF80Collector kCollector(collector);
    ForwardToD3C440(bodyB, bodyA, input, &kCollector);
}

extern void __cdecl hkpSphereBoxAgent_staticGetPenetrations(int a, int b, int input, int d);
extern char DAT_010ce81c[];

struct FlipCollectorLocal
{
    void* unk00;
    unsigned char unk04;
    int unk08;
};

// Builds a FlipCollectorLocal from DAT_010ce81c and a4, then calls FUN_00d3c440 with a2, a1, a3 and the local's address.
// @fnv 0x00d3cfc0
// src: XBOX_RETAIL_PDB 0x00d3cfc0
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::staticGetPenetrations | hkpSphereBoxAgent.obj | retail, object-file gap fill, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void __cdecl hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_staticGetPenetrations(int bodyA, int bodyB, int input, int collector)
{
    FlipCollectorLocal local;
    local.unk08 = collector;
    local.unk04 = 0;
    local.unk00 = DAT_010ce81c;
    hkpSphereBoxAgent_staticGetPenetrations(bodyB, bodyA, input, (int)&local);
}

extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void hkpSphereBoxAgent_getClosestPoints(void*, void*, unsigned int, hkpSymmetricAgentFlipCollector*);
    void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};
// Builds a hkpSymmetricAgentFlipCollector from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first, third and the collector to FUN_00d3c910.
// @fnv 0x00d3d000
// src: XBOX_PDB 0x00d3d000
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::getClosestPoints | hkpSphereBoxAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void CpuObject::hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_getClosestPoints(void* bodyA, void* bodyB, unsigned int input, unsigned int collector)
{
    void* storage[sizeof(hkpSymmetricAgentFlipCollector) / sizeof(void*)];
    hkpSymmetricAgentFlipCollector& callData = *(hkpSymmetricAgentFlipCollector*)storage;
    callData.m_collector = (void*)collector;
    callData.m_earlyOutDistance = DAT_0104da48;
    *(void**)&callData = &DAT_010ce7fc;
    hkpSphereBoxAgent_getClosestPoints(bodyB, bodyA, input, &callData);
}

typedef ::__m128 LocalM128;
extern "C"
{
using ::_mm_shuffle_ps;
using ::_mm_mul_ps;
using ::_mm_add_ps;
using ::_mm_xor_ps;
}

extern LocalM128 DAT_010c4c00;

struct SimplexVertex
{
    LocalM128 m_kPointA;
    LocalM128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    LocalM128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void hkpSphereBoxAgent_processCollision(int bodyA, int bodyB, int input, Simplex* result);
};

struct Agent : AgentBase
{
    void hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_processCollision(int bodyA, int bodyB, int input, Simplex* result);
};

// @fnv 0x00d3d080
// src: XBOX_PDB 0x00d3d080
// pdb: hkpSymmetricAgentLinearCast<hkpSphereBoxAgent>::processCollision | hkpSphereBoxAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, result
void Agent::hkpSymmetricAgentLinearCast_hkpSphereBoxAgent_processCollision(int bodyA, int bodyB, int input, Simplex* result)
{
    SimplexVertex* v = result->m_kRayEnd;
    float oldDistance = result->m_fClosestPointDistanceSquared;
    AgentBase::hkpSphereBoxAgent_processCollision(bodyB, bodyA, input, result);
    for (; v < result->m_kRayEnd; v++)
    {
        const LocalM128* pb = &v->m_kPointB;
        LocalM128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != result->m_fClosestPointDistanceSquared)
    {
        LocalM128* n = &result->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = result->m_dims.m_ucLowNibble;
            result->m_dims.m_ucLowNibble = result->m_dims.m_ucHighNibble;
            result->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = result->m_ucDimensionA;
            result->m_ucDimensionA = result->m_ucDimensionB;
            result->m_ucDimensionB = t;
        }
        int last = result->m_ucDimensionA + result->m_ucDimensionB - 1;
        unsigned short t0 = result->m_ids[0];
        result->m_ids[0] = result->m_ids[last];
        result->m_ids[last] = t0;
        if ((result->m_ucDimensionA & result->m_ucDimensionB) == 2)
        {
            unsigned short t1 = result->m_ids[1];
            result->m_ids[1] = result->m_ids[2];
            result->m_ids[2] = t1;
        }
    }
}
