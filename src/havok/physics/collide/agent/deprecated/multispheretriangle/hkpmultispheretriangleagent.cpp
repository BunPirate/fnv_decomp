extern "C" void* const DAT_010ce81c[];

#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/deprecated/multispheretriangle/hkpmultispheretriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe FUN_00d37ed0/FUN_00d38130: CRT byte-array storage adds /GS cookies; preserve the float-only LocalM128 view.
// VC9 requires the __m128 compatibility typedef for the native intrinsic ABI (a renamed tag causes C2719).
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16))
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../../include/hkpMultiSphereShape.h"
#include "../../../../../../../include/hkpMultiSphereTriangleAgent.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpTriangleShape.h"

struct S_00d37e60_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00d37e60_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d37e60_Allocator* m_pStreamAllocator;
    S_00d37e60_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00d37e60_Router* hkMemoryRouter_getInstance();

void hkpCollideTriangleUtil_setupClosestPointTriangleCache(const void* verts, hkpMultiSphereTriangleAgent::TriangleNormal* out) throw();

extern const unsigned hkpMultiSphereTriangleAgent_vtable[];
extern const unsigned hkpSymmetricMultiSphereTriangleAgent_vtable[];

// The shared iterative base has no usable constructor. Initialize the checked
// agent layout directly, including the symmetric wrapper's final vtable.
// @fnv 0x00d37e60
// src: XBOX_RETAIL_PDB 0x00d37e60
// pdb: hkpMultiSphereTriangleAgent::createTriangleMultiSphereAgent | hkpMultiSphereTriangleAgent.obj | retail, object-file gap fill, high
// pdb params: bodyA, bodyB, input, contactMgr
hkpCollisionAgent* hkpMultiSphereTriangleAgent_createTriangleMultiSphereAgent(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                                  void* contactMgr)
{
    hkpMultiSphereTriangleAgent* agent = static_cast<hkpMultiSphereTriangleAgent*>(
        hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(sizeof(hkpMultiSphereTriangleAgent)));
    agent->m_memSizeAndFlags = (unsigned short)sizeof(hkpMultiSphereTriangleAgent);
    if (agent != 0)
    {
        agent->m_referenceCount = 1;
        agent->m_contactMgr = static_cast<hkpContactMgr*>(contactMgr);
        *reinterpret_cast<const unsigned**>(agent) = hkpMultiSphereTriangleAgent_vtable;
        for (int i = 0; i < 8; i++)
            agent->m_contactPointId[i] = 0xffff;
        hkpCollideTriangleUtil_setupClosestPointTriangleCache(static_cast<const hkpTriangleShape*>(bodyA.m_shape)->m_kVertices,
                      &agent->m_closestPointTriangleCache);
        *reinterpret_cast<const unsigned**>(agent) = hkpSymmetricMultiSphereTriangleAgent_vtable;
    }
    return agent;
}

void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations(void*, void*, void*, void*);
struct D38AC0Data
{
    int unk00;
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk08;
};
// @fnv 0x00d38ac0
// src: XBOX_RETAIL_PDB 0x00d38ac0
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::staticGetPenetrations | hkpMultiSphereTriangleAgent.obj | retail, object-file gap fill, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void __cdecl hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_staticGetPenetrations(void* bodyA, void* bodyB, void* input, int collector)
{
    D38AC0Data data;
    data.unk08 = collector;
    data.unk04 = 0;
    data.unk00 = (int)DAT_010ce81c;
    hkpMultiSphereTriangleAgent_staticGetPenetrations(bodyB, bodyA, input, &data);
}

struct CpuCallData
{
    void* descriptor;
    float bound;
    unsigned int value;
};
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject
{
    void FUN_00d38390(void*, void*, unsigned int, CpuCallData*);
    void hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_getClosestPoints(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first and third to FUN_00d38390.
// @fnv 0x00d38e90
// src: XBOX_PDB 0x00d38e90
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::getClosestPoints | hkpMultiSphereTriangleAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void CpuObject::hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_getClosestPoints(void* bodyA, void* bodyB, unsigned int input, unsigned int collector)
{
    CpuCallData data;
    data.value = collector;
    data.bound = DAT_0104da48;
    data.descriptor = &DAT_010ce7fc;
    FUN_00d38390(bodyB, bodyA, input, &data);
}

// Removes each stored contact point, then destroys the agent.
// @fnv 0x00d37e10
// pdb: hkpMultiSphereTriangleAgent::cleanup | hkpMultiSphereTriangleAgent.obj | retail, vtable slot, high
// pdb params: constraintOwner
void hkpMultiSphereTriangleAgent::vf07(int constraintOwner)
{
    unsigned short* p = m_contactPointId;
    int n = 8;
    do
    {
        unsigned short w = *p;
        if (w != 0xffff)
        {
            m_contactMgr->removeContactPointImpl(w, *reinterpret_cast<hkpConstraintOwner*>(constraintOwner));
        }
        ++p;
        --n;
    } while (n != 0);

    if (this != 0)
    {
        delete this;
    }
}

struct CallbackState
{
    const void* type;
    bool completed;
    unsigned context;
};

extern const unsigned vtable_010ce81c[];

struct Operation
{
    void getPenetrations_00d37ed0(unsigned second, unsigned first, unsigned third, CallbackState* callback);
    void hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_getPenetrations(unsigned bodyA, unsigned bodyB, unsigned input, unsigned collector);
};

// Initialises a CallbackState with the given context and vtable, then calls FUN_00d37ed0 with the reordered arguments and the callback.
// @fnv 0x00d38a80
// src: XBOX_PDB 0x00d38a80
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::getPenetrations | hkpMultiSphereTriangleAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void Operation::hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_getPenetrations(unsigned bodyA, unsigned bodyB, unsigned input, unsigned collector)
{
    CallbackState callback;
    callback.context = collector;
    callback.completed = false;
    callback.type = vtable_010ce81c;
    getPenetrations_00d37ed0(bodyB, bodyA, input, &callback);
}

// Stand-in for the 12-byte record the callee receives by pointer.
// Field order/offsets come from the target frame layout:
//   +0 : pointer, +4 : float, +8 : dword
struct FUN_00d38ed0_Local
{
    const char* unk00;
    float unk04;
    int unk08;
};

// Global float loaded with `fld dword ptr [0x104da48]`.
extern float unk_104da48;

// Global object whose address (0x10ce7fc) is stored into the record.
extern char unk_10ce7fc[];

// Callee at 0x00d386c0: __cdecl, four arguments,
// the last one being a pointer to the record built on the stack.
void __cdecl hkpMultiSphereTriangleAgent_staticGetClosestPoints(int unk04, int unk08, int unk0c, FUN_00d38ed0_Local* unk10);

// @fnv 0x00d38ed0
// src: XBOX_RETAIL_PDB 0x00d38ed0
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::staticGetClosestPoints | hkpMultiSphereTriangleAgent.obj | retail, object-file gap fill, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: flip
void __cdecl hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_staticGetClosestPoints(int bodyA, int bodyB, int input, int collector)
{
    FUN_00d38ed0_Local local;

    local.unk04 = unk_104da48;
    local.unk08 = collector;
    local.unk00 = unk_10ce7fc;

    hkpMultiSphereTriangleAgent_staticGetClosestPoints(bodyB, bodyA, input, &local);
}

extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
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
    void hkpMultiSphereTriangleAgent_processCollision(int bodyA, int bodyB, int c, Simplex* result);
};

struct Agent : AgentBase
{
    void hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_processCollision(int bodyA, int bodyB, int input, Simplex* result);
};

// @fnv 0x00d38f10
// src: XBOX_PDB 0x00d38f10
// pdb: hkpSymmetricAgentLinearCast<hkpMultiSphereTriangleAgent>::processCollision | hkpMultiSphereTriangleAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, result
void Agent::hkpSymmetricAgentLinearCast_hkpMultiSphereTriangleAgent_processCollision(int bodyA, int bodyB, int input, Simplex* result)
{
    SimplexVertex* v = result->m_kRayEnd;
    float oldDistance = result->m_fClosestPointDistanceSquared;
    AgentBase::hkpMultiSphereTriangleAgent_processCollision(bodyB, bodyA, input, result);
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

struct hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};
union hkQuadVector
{
    hkVector4f v;
    LocalM128 q;
};

struct hkTransformf
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;
};

__forceinline float hkpTriangleShape::getRadius() const
{
    return m_radius;
}

struct CollisionDistanceInfo
{
    LocalM128 m_kNearestPoint;
    float distance;
    int unk14;
    int unk18;
    int unk1C;
};
void __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* triangle, const hkpMultiSphereTriangleAgent::TriangleNormal& cache,
                          CollisionDistanceInfo& result, void* featureOutput);

static __forceinline LocalM128 SetTransformedPoint(const LocalM128& c0, const LocalM128& c1, const LocalM128& c2, const LocalM128& t,
                                                const LocalM128& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const LocalM128 r0 = _mm_mul_ps(c0, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const LocalM128 r1 = _mm_mul_ps(c1, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(c2, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t));
}

static __forceinline void TransformPointArray(const hkTransformf& t, const hkVector4* vectorsIn, int numVectors,
                                              hkVector4* vectorsOut)
{
    hkQuadVector c0;
    c0.v = t.m_kColumn0;
    hkQuadVector c1;
    c1.v = t.m_kColumn1;
    hkQuadVector c2;
    c2.v = t.m_kColumn2;
    hkQuadVector c3;
    c3.v = t.m_vTranslation;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i].m_vComponents = SetTransformedPoint(c0.q, c1.q, c2.q, c3.q, vectorsIn[i].m_vComponents);
    } while (--i >= 0);
}

// @fnv 0x00d37ed0
// src: HAVOK_SRC 0x00d37ed0
// pdb: hkpMultiSphereTriangleAgent::getPenetrations | hkpMultiSphereTriangleAgent.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: triVertices, worldSpheres, cptr
void hkpMultiSphereTriangleAgent::getPenetrations_00d37ed0(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                                               hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = reinterpret_cast<const hkpMultiSphereShape*>(bodyA.m_shape);
    const hkpTriangleShape* triB = reinterpret_cast<const hkpTriangleShape*>(bodyB.m_shape);

    const hkVector4* localVertices = &triB->m_kVertices[0];
    LocalM128 triVertexStorage[3];
    hkVector4* triVertices = reinterpret_cast<hkVector4*>(triVertexStorage);
    TransformPointArray(*static_cast<const hkTransformf*>(bodyB.m_motion), localVertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = &msA->m_spheres[0];
    LocalM128 worldSphereStorage[8];
    hkVector4* worldSpheres = reinterpret_cast<hkVector4*>(worldSphereStorage);
    const int nsphere = msA->m_numSpheres;
    TransformPointArray(*static_cast<const hkTransformf*>(bodyA.m_motion), localSpheres, nsphere, &worldSpheres[0]);

    for (int i = 0; i < nsphere; ++i)
    {
        float radiusSum = triB->getRadius() + localSpheres[i].m_vComponents.m128_f32[3];
        CollisionDistanceInfo cpr;
        hkpCollideTriangleUtil_closestPointTriangle(worldSpheres[i], &triVertices[0], m_closestPointTriangleCache, cpr, 0);
        if (cpr.distance < radiusSum)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
            break;
        }
    }
}

void __cdecl hkpCollideTriangleUtil_closestPointTriangle(const hkVector4& position, const hkVector4* triangle, const hkpMultiSphereTriangleAgent::TriangleNormal& cache,
                          CollisionDistanceInfo& result, void* featureOutput);
// @fnv 0x00d38130
// src: XBOX_PDB 0x00d38130
// pdb: hkpMultiSphereTriangleAgent::staticGetPenetrations | hkpMultiSphereTriangleAgent.obj | retail, upstream name already matches, high
// pdb params: bodyA, bodyB, input, collector
// pdb locals: triVertices, closestPointTriangleCache, worldSpheres, cptr
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input,
                          hkpCdBodyPairCollector& collector)
{
    const hkpMultiSphereShape* msA = reinterpret_cast<const hkpMultiSphereShape*>(bodyA.m_shape);
    const hkpTriangleShape* triB = reinterpret_cast<const hkpTriangleShape*>(bodyB.m_shape);

    const hkVector4* localVertices = &triB->m_kVertices[0];
    LocalM128 triVertexStorage[3];
    hkVector4* triVertices = reinterpret_cast<hkVector4*>(triVertexStorage);
    TransformPointArray(*static_cast<const hkTransformf*>(bodyB.m_motion), localVertices, 3, &triVertices[0]);

    const hkVector4* localSpheres = &msA->m_spheres[0];
    LocalM128 worldSphereStorage[8];
    hkVector4* worldSpheres = reinterpret_cast<hkVector4*>(worldSphereStorage);
    const int nsphere = msA->m_numSpheres;
    TransformPointArray(*static_cast<const hkTransformf*>(bodyA.m_motion), localSpheres, nsphere, &worldSpheres[0]);

    hkpMultiSphereTriangleAgent::TriangleNormal cache;
    hkpCollideTriangleUtil_setupClosestPointTriangleCache(localVertices, &cache);

    for (int i = 0; i < nsphere; ++i)
    {
        float radiusSum = triB->m_radius + localSpheres[i].m_vComponents.m128_f32[3];
        CollisionDistanceInfo cpr;
        hkpCollideTriangleUtil_closestPointTriangle(worldSpheres[i], &triVertices[0], cache, cpr, 0);
        if (cpr.distance < radiusSum)
        {
            collector.AddCdBodyPair(bodyA, bodyB);
            break;
        }
    }
}
