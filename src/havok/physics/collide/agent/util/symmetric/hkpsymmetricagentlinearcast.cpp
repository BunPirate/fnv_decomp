
// src/havok/physics/collide/agent/util/symmetric/hkpsymmetricagentlinearcast.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/util/symmetric/hkpsymmetricagentlinearcast.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkVector4.h"

struct FUN_00d2dbe0;
struct Callback
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Run(FUN_00d2dbe0*, int);
};
struct Result
{
    int unk00[4];
    Callback* callback;
};
struct FUN_00d2dbe0
{
    int unk00[3];
    Result* result;
    Result* hkMemoryRouter_getInstance();
    virtual void Virtual0();
    FUN_00d2dbe0(unsigned int flags);
};
// If bit 0 of flags is set, obtains a Result via FUN_00c85750 and invokes its callback's Run with this and 8.
// @fnv 0x00d2dbe0
// pdb: hkpSymmetricAgentFlipCollector::`scalar deleting destructor' | hkpMoppBvTreeStreamAgent.obj | debug, vtable slot, medium
FUN_00d2dbe0::FUN_00d2dbe0(unsigned int flags)
{
    if (flags & 1)
    {
        Result* value = hkMemoryRouter_getInstance();
        value->callback->Run(this, 8);
    }
}

struct Inner
{
    virtual void v00();
    virtual unsigned char Invoke(void* first, void* second);
    unsigned char state;
};
struct Wrapper
{
    virtual void v00();
    unsigned char state;
    Inner* inner;
    unsigned char ForwardAndSyncState(void* bodyA, void* bodyB);
};
// Calls inner->Invoke with the two arguments swapped, then copies inner->state into this wrapper's state and returns it.
// @fnv 0x00da7150
// pdb: hkpSymmetricAgentFlipBodyCollector::addCdBodyPair | hkpSymmetricAgentLinearCast.obj | retail, vtable slot, high
// pdb params: bodyA, bodyB
unsigned char Wrapper::ForwardAndSyncState(void* bodyA, void* bodyB)
{
    inner->Invoke(bodyB, bodyA);
    return state = inner->state;
}

#include <xmmintrin.h>
extern const __m128 DAT_010c4c00;

__forceinline __m128& hkVector4::q()
{
    return m_vComponents;
}

__forceinline const __m128& hkVector4::q() const
{
    return m_vComponents;
}

__forceinline void hkVector4::setBroadcast3(const hkVector4& vector)
{
    __m128 t = _mm_shuffle_ps(vector.m_vComponents, vector.m_vComponents, 0xff);
    m_vComponents = _mm_shuffle_ps(t, t, 0);
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(b.m_vComponents, r.m_vComponents));
}

__forceinline void hkVector4::setNeg3(const hkVector4& vector)
{
    m_vComponents = _mm_xor_ps(vector.m_vComponents, DAT_010c4c00);
}

struct S_00da7070_CdPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    const void* m_pBodyA;
    const void* m_pBodyB;
};
struct S_00da7070_Collector
{
    virtual ~S_00da7070_Collector();
    virtual void AddCdPoint(const S_00da7070_CdPoint& p);
    float m_fEarlyOutDistance;
};
struct S_00da7070 : S_00da7070_Collector
{
    S_00da7070_Collector* m_childCollector;
    void AddFlippedCdPoint(const S_00da7070_CdPoint& point);
};
// Creates a flipped contact point by negating the separating normal, swapping bodies, and projecting the position, then adds it to the child collector.
// @fnv 0x00da7070
// pdb: hkpSymmetricAgentFlipCollector::addCdPoint | hkpSymmetricAgentLinearCast.obj | retail, vtable slot, high
// pdb params: point
// pdb locals: p
void S_00da7070::AddFlippedCdPoint(const S_00da7070_CdPoint& point)
{
    __declspec(align(16)) S_00da7070_CdPoint flipped;
    __m128 d = _mm_shuffle_ps(point.m_vSeparatingNormal.q(), point.m_vSeparatingNormal.q(), 0xff);
    flipped.m_vContactPosition.q() = _mm_add_ps(point.m_vContactPosition.q(), _mm_mul_ps(point.m_vSeparatingNormal.q(), d));
    flipped.m_pBodyA = point.m_pBodyB;
    flipped.m_pBodyB = point.m_pBodyA;
    flipped.m_vSeparatingNormal.q() = _mm_xor_ps(point.m_vSeparatingNormal.q(), DAT_010c4c00);
    m_childCollector->AddCdPoint(flipped);
    m_fEarlyOutDistance = m_childCollector->m_fEarlyOutDistance;
}

namespace fnv_00da70e0 {
struct VecDispatch
{
    virtual void v00();
    virtual void Dispatch(void* packet);
    float m_04;
};
struct VecArg
{
    hkVector4 m_00;
    hkVector4 m_10;
    unsigned int m_20;
    unsigned int m_24;
};
struct VecPacket
{
    hkVector4 m_00;
    hkVector4 m_10;
    unsigned int m_20;
    unsigned int m_24;
    __forceinline VecPacket(unsigned int a, unsigned int b) : m_20(a), m_24(b)
    {}
};
struct VecHolder
{
    unsigned int unk00;
    float m_04;
    unsigned int unk08;
    unsigned int unk0C;
    hkVector4 m_10;
    VecDispatch* m_20;

    void hkpSymmetricAgentFlipCastCollector_addCdPoint(const VecArg& point);
};

// Builds a packet with arg.m_00 + m_10 * arg.m_10's w and arg.m_10 negated, dispatches it via m_20, and copies m_20->m_04 to m_04.
// @fnv 0x00da70e0
// src: XBOX_PDB 0x00da70e0
// pdb: hkpSymmetricAgentFlipCastCollector::addCdPoint | hkpSymmetricAgentLinearCast.obj | retail, upstream name already matches, high
// pdb params: point
// pdb locals: p
void VecHolder::hkpSymmetricAgentFlipCastCollector_addCdPoint(const VecArg& point)
{
    VecPacket p(point.m_24, point.m_20);
    hkVector4 w;
    w.setBroadcast3(point.m_10);
    p.m_00.setAddMul4(point.m_00, m_10, w);
    p.m_10.setNeg3(point.m_10);
    m_20->Dispatch(&p);
    m_04 = m_20->m_04;
}
}  // namespace fnv_00da70e0
