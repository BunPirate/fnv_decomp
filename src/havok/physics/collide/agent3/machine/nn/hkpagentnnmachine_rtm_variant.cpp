// Keep this unit's compiler intrinsic representation: the SDK's additional byte
// arrays in __m128 introduce /GS cookies that the original RTM functions lack.
// Exe 0x00cfe370 _FUN_00cfe370: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
extern "C"
{
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, LocalM128);
    void _mm_prefetch(const char*, int);
}

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkMotionState.h"

#include <new>
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpAgent3Input.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpAgentNnTrack.h"
#include "../../../../../../../include/hkpAgentNnEntry.h"

// The approved headers do not yet define the process agent input, machine
// entries, or process input/output.
// Keep one real-name definition of each required record below until they do.
__forceinline hkpCdBody::hkpCdBody() {}
__forceinline hkpCdBody::hkpCdBody(const hkpCdBody* parent, const hkTransform* t)
{
    m_parent = parent;
    m_motion = t;
}
__forceinline const hkMotionState* hkpCdBody::GetMotionState() const
{
    return reinterpret_cast<const hkMotionState*>(m_motion);
}
__forceinline const hkpShape* hkpCdBody::getShape() const { return m_shape; }
__forceinline unsigned int hkpCdBody::getShapeKey() const { return m_shapeKey; }
__forceinline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key)
{
    m_shape = shape;
    m_shapeKey = key;
}
__forceinline hkAgent3::CleanupFunc hkpCollisionDispatcher::getAgent3CleanupFunc(int type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction3;
}
__forceinline hkAgent3::ProcessFunc hkpCollisionDispatcher::getAgent3ProcessFunc(int type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction8;
}
__forceinline hkAgent3::SepNormalFunc hkpCollisionDispatcher::getAgent3SepNormalFunc(int type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction7;
}

// hkMemoryRouter is include/'s shared hkMemoryRouter (allocator at +0x10).

// These unit-local inline bodies retain the Havok operations used by the RTM code.
__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x) {}
__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& x)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), x.m_vComponents);
}
__forceinline void hkVector4::setMul4(float r, const hkVector4& v1)
{
    setMul4(hkSimdReal(r), v1);
}
__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
    LocalM128 linear = _mm_load_ps(reinterpret_cast<const float*>(&m_vComponents));
    LocalM128 sep = _mm_load_ps(reinterpret_cast<const float*>(&a));
    LocalM128 x2 = _mm_mul_ps(sep, linear);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2);
    LocalM128 zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), _mm_shuffle_ps(linear, linear, 255));
    return _mm_add_ps(xySum, zwSum);
}
__forceinline float& hkVector4::operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
__forceinline const float& hkVector4::operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
__forceinline LocalM128& hkVector4::getQuad() { return m_vComponents; }
__forceinline const LocalM128& hkVector4::getQuad() const { return m_vComponents; }
__forceinline hkTransform::hkTransform() {}
__forceinline const hkTransform& hkMotionState::getTransform() const { return m_transform; }
__forceinline const hkSweptTransform& hkMotionState::getSweptTransform() const { return m_kSweptTransform; }
__forceinline float hkSweptTransform::getInvDeltaTime() const { return m_vCenterOfMass1(3); }

// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef float hkReal;
typedef unsigned char hkUchar;
typedef LocalM128 hkQuadReal;

void __cdecl hkSweptTransformUtil_lerp2(const hkSweptTransform& st, hkReal t, hkTransform& out);

struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpAgentNnEntry;
class hkpConstraintOwner;
extern float DAT_0104da48;
struct TrackContact
{
    hkVector4 position, normal;
    int id, unk24, unk28, unk2c;
};
struct TrackProperties
{
    float appliedImpulse, internalSolver;
    int material, internalData;
    unsigned int extendedData[7];
    int unk2c;
    TrackProperties() : appliedImpulse(0.0f), internalSolver(0.0f)
    {}
};
struct TrackToi
{
    hkVector4 position, normal;
    hkPadSpu<float> time;
    float separationVelocity;
    int unk28, unk2c;
    int cache0, cache1, cache2, cache3;
    TrackProperties properties;
    TrackToi() : time(DAT_0104da48)
    {}
};
// pdb: structure hkpProcessCollisionOutput, size 0x3090, bases: hkpProcessCollisionData, 1 members
struct hkpProcessCollisionOutput
{
    hkPadSpu<TrackContact*> m_pAlignedPairData;
    hkPadSpu<hkpConstraintOwner*> m_pConstraintOwner;
    int unk08, unk0c;
    TrackContact m_akContactPoints[256];
    TrackToi m_fTimeOfImpact;
    hkPadSpu<void*> m_potentialContacts; // src: XBOX_RETAIL_PDB +0x3080 (old: m_akContactRecords)
    int unk3074, unk3078, unk307c;
    hkpProcessCollisionOutput(hkpConstraintOwner* owner)
    {
        m_pConstraintOwner = owner;
    }
    __forceinline void reset()
    {
        m_pAlignedPairData = &m_akContactPoints[0];
        m_fTimeOfImpact.time = DAT_0104da48;
        m_potentialContacts = 0;
    }
    __forceinline bool isEmpty() const
    {
        return (TrackContact*)m_pAlignedPairData == &m_akContactPoints[0];
    }
};



// The shared agent does not yet declare ProcessAgent. Dispatch its existing
// virtual slot without duplicating the class definition.
typedef void (__thiscall* ProcessCollisionAgentFunc)(hkpCollisionAgent*,
    const hkpCdBody&, const hkpCdBody&, const hkpProcessCollisionInput&,
    hkpProcessCollisionOutput&);

// pdb: structure hkpAgent3ProcessInput, size 0x80, bases: hkpAgent3Input, 2 members
struct hkpAgent3ProcessInput : public hkpAgent3Input
{
    hkPadSpu<hkReal> m_distAtT1; // src: XBOX_RETAIL_PDB +0x60 (old: m_fSubtypeValue)
    hkVector4 m_linearTimInfo; // src: XBOX_RETAIL_PDB +0x70 (old: m_vSubtypePosition)
};

typedef void*(__cdecl* hkAgent3CleanupFunc)(hkpAgentNnEntry* entry, void* agentData, hkpContactMgr* mgr,
                                                hkpConstraintOwner& owner);
typedef void(__cdecl* hkAgent3SepNormalFunc)(const hkpAgent3Input& input, hkpAgentNnEntry* entry,
                                                 void* agentData, hkVector4& sepNormalOut);
typedef void*(__cdecl* hkAgent3ProcessFunc)(const hkpAgent3ProcessInput& input, hkpAgentNnEntry* entry,
                                                void* agentData, hkVector4* separatingNormalOut,
                                                hkpProcessCollisionOutput& result);

#include "../../../../../../../include/hkStepInfo.h"


// pdb: structure hkpProcessCollisionInput, size 0x80 (here 0x70), bases: hkpCollisionInput, 7 members
struct hkpProcessCollisionInput
{
    hkPadSpu<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    hkPadSpu<int> m_collisionQuality;
    hkPadSpu<hkReal> m_fScalar;
    int unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    hkStepInfo m_pStepInfo;
    hkPadSpu<hkpCollisionQualityInfo*> m_pCollisionQualityInfo;

    inline hkReal getTolerance() const
    {
        return m_fScalar;
    }
};


// pdb: structure hkpAgentNnMachinePaddedEntry, size 0x20, bases: hkpAgentNnEntry, 1 members
struct hkpAgentNnMachinePaddedEntry : public hkpAgentNnEntry
{
    int m_padOutTo16BytesAlignment; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiRollingFrictionData)
    int m_padding3;
};

// pdb: structure hkpAgentNnMachineTimEntry, size 0x30, bases: hkpAgentNnEntry, 2 members
struct hkpAgentNnMachineTimEntry : public hkpAgentNnEntry
{
    hkReal m_timeOfSeparatingNormal; // src: XBOX_RETAIL_PDB +0x18 (old: m_fFloatValue)
    int unk1c;
    hkVector4 m_separatingNormal; // src: XBOX_RETAIL_PDB +0x20 (old: m_vSeparatingNormal)
};

// pdb: structure hkAgentNnMachineBodyTemp, size 0xa0, 4 members
struct hkAgentNnMachineBodyTemp
{
    hkpCdBody m_bodyA; // src: XBOX_RETAIL_PDB +0x0 (old: m_pBodyA)
    hkpCdBody m_bodyB; // src: XBOX_RETAIL_PDB +0x10 (old: m_pBodyB)
    hkTransform m_transA; // src: XBOX_RETAIL_PDB +0x20 (old: m_kTransformA)
    hkTransform m_transB; // src: XBOX_RETAIL_PDB +0x60 (old: m_kTransformB)
};

void* __cdecl hkAgentMachine_processTransformedShapes(void* cdBody, void* newCdBodies, void* newMotionStates, unsigned int numSlots, void* cdBodyHasTransformFlag);

enum
{
    STREAM_CALL_CFE3 = 2,
    STREAM_CALL_WITH_TIM_CFE3 = 4,
    STREAM_CALL_AGENT_CFE3 = 6,
    TRANSFORM_FLAG_CFE3 = 8,
    STREAM_CALL_WITH_TRANSFORM_CFE3 = 10,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFE3 = 12,
    STREAM_CALL_AGENT_WITH_TRANSFORM_CFE3 = 14
};

static __forceinline void calcTimInfoCFE3(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                          hkVector4& timOut)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();

    hkVector4 diff0;
    diff0.setSub4(st0.m_centerOfMass0, st0.m_vCenterOfMass1);
    hkVector4 diff1;
    diff1.setSub4(st1.m_vCenterOfMass1, st1.m_centerOfMass0);

    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();

    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.m_deltaAngle(3) * ms0.m_objectRadius + f1 * ms1.m_deltaAngle(3) * ms1.m_objectRadius;
}

static __forceinline void initInputAtTimeCFE3(hkpAgent3Input& in, hkAgentNnMachineBodyTemp& bodyTemp,
                                              hkpAgent3Input& out)
{
    hkSweptTransformUtil_lerp2(in.m_bodyA->GetMotionState()->getSweptTransform(), in.m_input->m_pStepInfo.m_startTime,
                 bodyTemp.m_transA);
    hkSweptTransformUtil_lerp2(in.m_bodyB->GetMotionState()->getSweptTransform(), in.m_input->m_pStepInfo.m_startTime,
                 bodyTemp.m_transB);

    out.m_bodyA = &bodyTemp.m_bodyA;
    out.m_bodyB = &bodyTemp.m_bodyB;
    out.m_contactMgr = in.m_contactMgr;
    out.m_input = in.m_input;

    bodyTemp.m_bodyA.SetCollisionShapeAndKey(in.m_bodyA->getShape(), in.m_bodyA->getShapeKey());
    bodyTemp.m_bodyB.SetCollisionShapeAndKey(in.m_bodyB->getShape(), in.m_bodyB->getShapeKey());
    ::new (&bodyTemp.m_bodyA) hkpCdBody(in.m_bodyA, &bodyTemp.m_transA);
    ::new (&bodyTemp.m_bodyB) hkpCdBody(in.m_bodyB, &bodyTemp.m_transB);

    out.m_aTb.hkTransform_setMulInverseMul(bodyTemp.m_transA, bodyTemp.m_transB);
}

extern "C"
{
// @fnv 0x00cfe370
// src: XBOX_PDB 0x00cfe370
// pdb: hkAgentNnMachine_InlineProcessAgent | hkpAgentNnMachine.obj | retail, upstream name already matches, high
// pdb params: entry, input, numTim, output, mgr
// pdb locals: transformForTransformedShapeB, cdBodyForTransformedShapeA, transformForTransformedShapeA, cdBodyForTransformedShapeB, dummyCdBodyHasTransformFlag, in3, assertBuf, ostr, prevInput, prevTemp
    static __declspec(noinline) void __cdecl hkAgentNnMachine_InlineProcessAgent(hkpAgentNnEntry* entry,
                                                          const hkpProcessCollisionInput& input, int& numTim,
                                                          hkpProcessCollisionOutput& output, hkpContactMgr* mgr)
    {
        const hkpCdBody* cdBodyA = entry->getCollidableA();
        const hkpCdBody* cdBodyB = entry->getCollidableB();

        // Raw SIMD storage keeps these uninitialized arrays free of added /GS checks.
        LocalM128 motionStatesAStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];

        hkMotionState* motionStatesA = reinterpret_cast<hkMotionState*>(motionStatesAStorage);
        LocalM128 motionStatesBStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
        hkMotionState* motionStatesB = reinterpret_cast<hkMotionState*>(motionStatesBStorage);
        hkpCdBody cdBodiesA[4];
        hkpCdBody cdBodiesB[4];

        int command = entry->m_ucAgentType;
    commandSwitch:
        switch (command)
        {
        case STREAM_CALL_WITH_TRANSFORM_CFE3:
        case STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFE3:
        case STREAM_CALL_AGENT_WITH_TRANSFORM_CFE3: {
            hkUchar dummy;
            cdBodyA = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)cdBodyA, cdBodiesA, motionStatesA, 4, &dummy);
            cdBodyB = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)cdBodyB, cdBodiesB, motionStatesB, 4, &dummy);
            command = hkUchar(command) & hkUchar(~TRANSFORM_FLAG_CFE3);
            goto commandSwitch;
        }

        case STREAM_CALL_AGENT_CFE3: {
            hkpCollisionAgent* agent =
                *reinterpret_cast<hkpCollisionAgent**>(static_cast<hkpAgentNnMachinePaddedEntry*>(entry) + 1);
            (*reinterpret_cast<ProcessCollisionAgentFunc**>(agent))[6](agent, *cdBodyA, *cdBodyB, input, output);
            break;
        }

        case STREAM_CALL_CFE3: {
            hkpAgentNnMachinePaddedEntry* e = static_cast<hkpAgentNnMachinePaddedEntry*>(entry);
            hkpAgent3ProcessInput in3;
            in3.m_bodyA = cdBodyA;
            in3.m_bodyB = cdBodyB;
            in3.m_contactMgr = entry->m_contactMgr;
            in3.m_input = &input;

            const hkMotionState* msA = in3.m_bodyA->GetMotionState();
            const hkMotionState* msB = in3.m_bodyB->GetMotionState();
            calcTimInfoCFE3(*msA, *msB, in3.m_input->m_pStepInfo.m_deltaTime, in3.m_linearTimInfo);
            in3.m_aTb.hkTransform_setMulInverseMul(msA->getTransform(), msB->getTransform());

            void* agentData = e + 1;
            (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(in3, entry, agentData, 0,
                                                                                       output);
            break;
        }

        case STREAM_CALL_WITH_TIM_CFE3: {
            hkpAgentNnMachineTimEntry* e = static_cast<hkpAgentNnMachineTimEntry*>(entry);
            hkpAgent3ProcessInput in3;
            in3.m_bodyA = cdBodyA;
            in3.m_bodyB = cdBodyB;
            in3.m_contactMgr = entry->m_contactMgr;
            in3.m_input = &input;

            const hkMotionState* msA = in3.m_bodyA->GetMotionState();
            const hkMotionState* msB = in3.m_bodyB->GetMotionState();
            calcTimInfoCFE3(*msA, *msB, in3.m_input->m_pStepInfo.m_deltaTime, in3.m_linearTimInfo);

            void* agentData = e + 1;
            hkReal dist;
            if (e->m_timeOfSeparatingNormal != input.m_pStepInfo.m_startTime)
            {
                if (!input.m_pCollisionQualityInfo->m_useContinuousPhysics)
                {
                    e->m_timeOfSeparatingNormal = input.m_pStepInfo.m_endTime;
                    dist = -3.40282e+38f;
                    e->m_separatingNormal.setZero4();
                    e->m_separatingNormal(3) = dist;
                    goto PROCESS_AT_T1;
                }
                hkAgentNnMachineBodyTemp bodyTemp;
                hkpAgent3Input in3b;
                initInputAtTimeCFE3(in3, bodyTemp, in3b);
                (reinterpret_cast<hkAgent3SepNormalFunc>(input.m_pCollisionDispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)))(in3b, entry, agentData,
                                                                                             e->m_separatingNormal);
            }

            hkVector4& vSeparatingNormal = e->m_separatingNormal;
            const hkReal worst = in3.m_linearTimInfo.dot4xyz1(vSeparatingNormal);
            e->m_timeOfSeparatingNormal = input.m_pStepInfo.m_endTime;
            dist = vSeparatingNormal(3) - worst;
            if (dist >= input.getTolerance())
            {
                e->m_separatingNormal(3) = dist;
                if (entry->m_usNumContactPoints)
                {
                    (reinterpret_cast<hkAgent3CleanupFunc>(input.m_pCollisionDispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)))(
                        entry, agentData, in3.m_contactMgr, *output.m_pConstraintOwner);
                }
                numTim++;
                break;
            }
        PROCESS_AT_T1:
            in3.m_distAtT1 = dist;
            in3.m_aTb.hkTransform_setMulInverseMul(msA->getTransform(), msB->getTransform());
            (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(in3, entry, agentData,
                                                                                       &e->m_separatingNormal, output);
            break;
        }

        default:
            break;
        }
    }
}
void hkAgentNnMachine_ProcessAgentCFE3(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& input,
                                       hkpProcessCollisionOutput& output, hkpContactMgr* mgr)
{
    int numTim = 0;
    hkAgentNnMachine_InlineProcessAgent(entry, input, numTim, output, mgr);
}

extern "C"
{

    void _ReadBarrier();
    void _ReadWriteBarrier();
    void _WriteBarrier();
    void _ReadWriteBarrier();

}

// pdb: structure hkpAgentNnSector, size 0x200, 1 members
struct hkpAgentNnSector
{
    unsigned char m_data[512]; // src: XBOX_RETAIL_PDB +0x0 (old: data)
    hkpAgentNnEntry* getBegin()
    {
        return reinterpret_cast<hkpAgentNnEntry*>(&m_data[0]);
    }
    hkpAgentNnEntry* GetStreamEnd()
    {
        return reinterpret_cast<hkpAgentNnEntry*>(&m_data[512]);
    }
};
struct TrackMonitor
{
    char* start;
    char* end;
    char* capacity;
    char* limit;
};
extern unsigned int DAT_0126835c;
extern unsigned int DAT_01269200;
__declspec(selectany) extern const float DAT_0104e148 = -3.40282e+38f;
extern const char DAT_010cc9d0[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
struct PreviousBodies
{
    hkpCdBody a, b;
    hkTransform ta, tb;
};
static __forceinline void fillPrevious(const hkpAgent3Input& current, PreviousBodies& b, hkpAgent3Input& previous)
{
    hkSweptTransformUtil_lerp2(current.m_bodyA->GetMotionState()->getSweptTransform(),
                 current.m_input->m_pStepInfo.m_startTime, b.ta);
    hkSweptTransformUtil_lerp2(current.m_bodyB->GetMotionState()->getSweptTransform(),
                 current.m_input->m_pStepInfo.m_startTime, b.tb);
    previous.m_bodyA = &b.a;
    previous.m_bodyB = &b.b;
    previous.m_contactMgr = current.m_contactMgr;
    previous.m_input = current.m_input;
    b.a.SetCollisionShapeAndKey(current.m_bodyA->getShape(), current.m_bodyA->getShapeKey());
    b.b.SetCollisionShapeAndKey(current.m_bodyB->getShape(), current.m_bodyB->getShapeKey());
    ::new (&b.a) hkpCdBody(current.m_bodyA, &b.ta);
    ::new (&b.b) hkpCdBody(current.m_bodyB, &b.tb);
    previous.m_aTb.hkTransform_setMulInverseMul(b.ta, b.tb);
}
static __forceinline void motionDelta(const hkMotionState& a, const hkMotionState& b, hkReal dt,
                                      hkVector4& out)
{
    hkVector4 da, db;
    da.setSub4(a.getSweptTransform().m_centerOfMass0, a.getSweptTransform().m_vCenterOfMass1);
    db.setSub4(b.getSweptTransform().m_vCenterOfMass1, b.getSweptTransform().m_centerOfMass0);
    hkReal fa = dt * a.getSweptTransform().getInvDeltaTime();
    hkReal fb = dt * b.getSweptTransform().getInvDeltaTime();
    out.setMul4(fa, da);
    out.addMul4(fb, db);
    out(3) = fa * a.m_deltaAngle(3) * a.m_objectRadius + fb * b.m_deltaAngle(3) * b.m_objectRadius;
}
static __forceinline void processEntry(hkpAgentNnEntry* e, const hkpProcessCollisionInput& context, int& skipped,
                                       hkpProcessCollisionOutput& out)
{
    const hkpCdBody* a = e->getCollidableA();
    const hkpCdBody* b = e->getCollidableB();
    // Raw SIMD storage keeps these uninitialized arrays free of added /GS checks.
    LocalM128 maStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* ma = reinterpret_cast<hkMotionState*>(maStorage);
    LocalM128 mbStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* mb = reinterpret_cast<hkMotionState*>(mbStorage);
    hkpCdBody ba[4], bb[4];
    int cmd = e->m_ucAgentType;
again:
    switch (cmd)
    {
    case 10:
    case 12:
    case 14: {
        hkPadSpu<hkUchar> transformed;
        a = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)a, ba, ma, 4, &transformed);
        b = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)b, bb, mb, 4, &transformed);
        cmd = hkUchar(cmd) & hkUchar(~8);
        goto again;
    }
    case 6: {
        hkpCollisionAgent* agent =
            *reinterpret_cast<hkpCollisionAgent**>(static_cast<hkpAgentNnMachinePaddedEntry*>(e) + 1);
        (*reinterpret_cast<ProcessCollisionAgentFunc**>(agent))[6](agent, *a, *b, context, out);
        break;
    }
    case 2: {
        hkpAgent3ProcessInput query;
        query.m_bodyA = a;
        query.m_bodyB = b;
        query.m_contactMgr = e->m_contactMgr;
        query.m_input = &context;
        const hkMotionState* am = query.m_bodyA->GetMotionState();
        const hkMotionState* bm = query.m_bodyB->GetMotionState();
        motionDelta(*am, *bm, query.m_input->m_pStepInfo.m_deltaTime, query.m_linearTimInfo);
        query.m_aTb.hkTransform_setMulInverseMul(am->getTransform(), bm->getTransform());
        (reinterpret_cast<hkAgent3ProcessFunc>(context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)))(
            query, e, static_cast<hkpAgentNnMachinePaddedEntry*>(e) + 1, 0, out);
        break;
    }
    case 4: {
        hkpAgentNnMachineTimEntry* timed = static_cast<hkpAgentNnMachineTimEntry*>(e);
        hkpAgent3ProcessInput query;
        query.m_bodyA = a;
        query.m_bodyB = b;
        query.m_contactMgr = e->m_contactMgr;
        query.m_input = &context;
        const hkMotionState* am = query.m_bodyA->GetMotionState();
        const hkMotionState* bm = query.m_bodyB->GetMotionState();
        motionDelta(*am, *bm, query.m_input->m_pStepInfo.m_deltaTime, query.m_linearTimInfo);
        void* data = timed + 1;
        hkReal distance;
        if (timed->m_timeOfSeparatingNormal != context.m_pStepInfo.m_startTime)
        {
            if (!context.m_pCollisionQualityInfo->m_useContinuousPhysics)
            {
                timed->m_timeOfSeparatingNormal = context.m_pStepInfo.m_endTime;
                distance = -3.40282e+38f;
                timed->m_separatingNormal.setZero4();
                timed->m_separatingNormal(3) = distance;
                goto collide;
            }
            PreviousBodies bodies;
            hkpAgent3Input previous;
            fillPrevious(query, bodies, previous);
            (reinterpret_cast<hkAgent3SepNormalFunc>(context.m_pCollisionDispatcher->getAgent3SepNormalFunc(e->m_ucNnTrackType)))(previous, e, data,
                                                                                       timed->m_separatingNormal);
        }
        {
            hkVector4& normal = timed->m_separatingNormal;
            LocalM128 velocity = _mm_load_ps(&query.m_linearTimInfo(0));
            LocalM128 product = _mm_mul_ps(normal.getQuad(), velocity);
            LocalM128 z = _mm_shuffle_ps(product, product, 170);
            LocalM128 w = _mm_shuffle_ps(velocity, velocity, 255);
            LocalM128 y = _mm_shuffle_ps(product, product, 85);
            LocalM128 zw = _mm_add_ss(z, w);
            LocalM128 xy = _mm_add_ss(y, product);
            LocalM128 total = _mm_add_ps(zw, xy);
            hkReal movement;
            _mm_store_ss(&movement, total);
            timed->m_timeOfSeparatingNormal = context.m_pStepInfo.m_endTime;
            distance = normal(3) - movement;
            if (distance >= context.getTolerance())
            {
                timed->m_separatingNormal(3) = distance;
                if (e->m_usNumContactPoints)
                    (reinterpret_cast<hkAgent3CleanupFunc>(context.m_pCollisionDispatcher->getAgent3CleanupFunc(e->m_ucNnTrackType)))(
                        e, data, query.m_contactMgr, *out.m_pConstraintOwner);
                ++skipped;
                break;
            }
        }
    collide:
        query.m_distAtT1 = distance;
        query.m_aTb.hkTransform_setMulInverseMul(am->getTransform(), bm->getTransform());
        (reinterpret_cast<hkAgent3ProcessFunc>(context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)))(query, e, data,
                                                                                 &timed->m_separatingNormal, out);
        break;
    }
    }
}
// @fnv 0x00cff3c0
// src: GUESS 0x00cff3c0 (confidence: low)
// pdb: hkAgentNnMachine_ProcessTrack | hkpAgentNnMachine.obj | retail, object-file run extension, low
// pdb params: owner, agentTrack, input
// pdb locals: processOutput, numTim, HKLOOP_sectorIndex, HKLOOP_endEntry
void __cdecl hkpConstraintOwner_ProcessEntries_00cff3c0(hkpConstraintOwner* owner, hkpAgentNnTrack& track, const hkpProcessCollisionInput& context)
{
    int skipped = 0;
    hkpProcessCollisionOutput result(owner);
    for (int index = 0; index < track.m_sectors.GetLogicalSize();)
    {
        hkpAgentNnSector* sector = track.m_sectors[index];
        hkpAgentNnEntry* entry = sector->getBegin();
        ++index;
        hkpAgentNnEntry* end = (index == track.m_sectors.GetLogicalSize())
                                      ? (hkpAgentNnEntry*)((char*)entry + track.m_bytesUsedInLastSector)
                                      : sector->GetStreamEnd();
        for (; entry < end; entry = (hkpAgentNnEntry*)((char*)entry + entry->m_iElementCount))
        {
            hkpCdBody* a = entry->getCollidableA();
            hkpCdBody* b = entry->getCollidableB();
            result.reset();
            _mm_prefetch((const char*)entry + 128, 0);
            _mm_prefetch((const char*)entry->m_contactMgr, 0);
            processEntry(entry, context, skipped, result);
            if (DAT_01269200 == 1)
                return;
            if (!result.isEmpty())
                entry->m_contactMgr->processContact(*a, *b, context, result);
        }
    }
    TrackMonitor& stream = *(TrackMonitor*)TlsGetValue(DAT_0126835c);
    char* cur = stream.end;
    if (cur < stream.limit)
    {
        *(const char**)cur = DAT_010cc9d0;
        *(float*)(cur + 4) = float(skipped);
        stream.end = cur + 8;
    }
}

namespace ProcessAgentCFEDD0 {

typedef ::LocalM128 hkQuadReal;

static __forceinline void timedEstimateProcessAgentCFEDD0(const hkMotionState& a,
                                                          const hkMotionState& b, float dt,
                                                          hkVector4& out, float& sb)
{
    hkVector4 da, db;
    da.setSub4(a.m_kSweptTransform.m_centerOfMass0, a.m_kSweptTransform.m_vCenterOfMass1);
    db.setSub4(b.m_kSweptTransform.m_vCenterOfMass1, b.m_kSweptTransform.m_centerOfMass0);
    float sa = dt * a.m_kSweptTransform.getInvDeltaTime();
    sb = dt * b.m_kSweptTransform.getInvDeltaTime();
    out.setMul4(sa, da);
    out.addMul4(sb, db);
    out(3) = sa * a.m_deltaAngle(3) * a.m_objectRadius + sb * b.m_deltaAngle(3) * b.m_objectRadius;
}
static __forceinline void motionEstimateProcessAgentCFEDD0(const hkMotionState& a,
                                                           const hkMotionState& b, float dt,
                                                           hkVector4& out)
{
    hkVector4 da, db;
    da.setSub4(a.m_kSweptTransform.m_centerOfMass0, a.m_kSweptTransform.m_vCenterOfMass1);
    db.setSub4(b.m_kSweptTransform.m_vCenterOfMass1, b.m_kSweptTransform.m_centerOfMass0);
    float sa = dt * a.m_kSweptTransform.getInvDeltaTime();
    float sb = dt * b.m_kSweptTransform.getInvDeltaTime();
    out.setMul4(sa, da);
    out.addMul4(sb, db);
    out(3) = sa * a.m_deltaAngle(3) * a.m_objectRadius + sb * b.m_deltaAngle(3) * b.m_objectRadius;
}
static __forceinline void previousInputProcessAgentCFEDD0(hkpAgent3Input& current,
                                                          hkAgentNnMachineBodyTemp& state,
                                                          hkpAgent3Input& previous)
{
    ::hkSweptTransformUtil_lerp2(current.m_bodyA->GetMotionState()->getSweptTransform(),
                 current.m_input->m_pStepInfo.m_startTime, state.m_transA);
    ::hkSweptTransformUtil_lerp2(current.m_bodyB->GetMotionState()->getSweptTransform(),
                 current.m_input->m_pStepInfo.m_startTime, state.m_transB);
    previous.m_bodyA = &state.m_bodyA;
    previous.m_bodyB = &state.m_bodyB;
    previous.m_contactMgr = current.m_contactMgr;
    previous.m_input = current.m_input;
    state.m_bodyA.SetCollisionShapeAndKey(current.m_bodyA->getShape(), current.m_bodyA->getShapeKey());
    state.m_bodyB.SetCollisionShapeAndKey(current.m_bodyB->getShape(), current.m_bodyB->getShapeKey());
    ::new (&state.m_bodyA) hkpCdBody(current.m_bodyA, &state.m_transA);
    ::new (&state.m_bodyB) hkpCdBody(current.m_bodyB, &state.m_transB);
    previous.m_aTb.hkTransform_setMulInverseMul(state.m_transA, state.m_transB);
}
extern float DAT_0104e148;
// @fnv 0x00cfedd0
// src: XBOX_PDB 0x00cfedd0
// pdb: hkAgentNnMachine_ProcessAgent | hkpAgentNnMachine.obj | retail, upstream name already matches, high
// pdb params: entry, input, output, mgr
extern "C" void __cdecl hkAgentNnMachine_ProcessAgent(hkpAgentNnEntry* entry,
                                     const hkpProcessCollisionInput& input,
                                     hkpProcessCollisionOutput& output)
{
    const hkpCdBody* a = entry->getCollidableA();
    const hkpCdBody* b = entry->getCollidableB();
    // Raw SIMD storage keeps these uninitialized arrays free of added /GS checks.
    LocalM128 motionsAStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* motionsA = reinterpret_cast<hkMotionState*>(motionsAStorage);
    LocalM128 motionsBStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* motionsB = reinterpret_cast<hkMotionState*>(motionsBStorage);
    hkpCdBody bodiesA[4], bodiesB[4];
    int command = entry->m_ucAgentType;
again:
    switch (command)
    {
    case 10:
    case 12:
    case 14: {
        hkUchar transformed;
        a = (const hkpCdBody*)::hkAgentMachine_processTransformedShapes((void*)a, bodiesA, motionsA, 4,
                                                                                 &transformed);
        b = (const hkpCdBody*)::hkAgentMachine_processTransformedShapes((void*)b, bodiesB, motionsB, 4,
                                                                                 &transformed);
        command = (hkUchar)command & 0xf7;
        goto again;
    }
    case 6: {
        hkpAgentNnMachinePaddedEntry* padded = (hkpAgentNnMachinePaddedEntry*)entry;
        hkpCollisionAgent* agent = *(hkpCollisionAgent**)(padded + 1);
        (*reinterpret_cast<ProcessCollisionAgentFunc**>(agent))[6](agent, *a, *b, input, output);
        break;
    }
    case 2: {
        hkpAgent3ProcessInput process;
        process.m_bodyA = a;
        process.m_bodyB = b;
        process.m_contactMgr = entry->m_contactMgr;
        process.m_input = &input;
        const hkMotionState* ma = process.m_bodyA->GetMotionState();
        const hkMotionState* mb = process.m_bodyB->GetMotionState();
        motionEstimateProcessAgentCFEDD0(*ma, *mb, process.m_input->m_pStepInfo.m_deltaTime,
                                         process.m_linearTimInfo);
        process.m_aTb.hkTransform_setMulInverseMul(ma->getTransform(), mb->getTransform());
        void* data = (hkpAgentNnMachinePaddedEntry*)entry + 1;
        (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(process, entry, data, 0, output);
        break;
    }
    case 4: {
        hkpAgentNnMachineTimEntry* timed = (hkpAgentNnMachineTimEntry*)entry;
        hkpAgent3ProcessInput process;
        process.m_bodyA = a;
        process.m_bodyB = b;
        process.m_contactMgr = entry->m_contactMgr;
        process.m_input = &input;
        const hkMotionState* ma = process.m_bodyA->GetMotionState();
        const hkMotionState* mb = process.m_bodyB->GetMotionState();
        float distance;
        timedEstimateProcessAgentCFEDD0(*ma, *mb, process.m_input->m_pStepInfo.m_deltaTime,
                                        process.m_linearTimInfo, distance);
        void* data = timed + 1;
        if (timed->m_timeOfSeparatingNormal != input.m_pStepInfo.m_startTime)
        {
            if (!input.m_pCollisionQualityInfo->m_useContinuousPhysics)
            {
                timed->m_timeOfSeparatingNormal = input.m_pStepInfo.m_endTime;
                distance = -3.40282e+38f;
                timed->m_separatingNormal.setZero4();
                timed->m_separatingNormal(3) = distance;
                goto processAtEnd;
            }
            hkAgentNnMachineBodyTemp state;
            hkpAgent3Input previous;
            previousInputProcessAgentCFEDD0(process, state, previous);
            (reinterpret_cast<hkAgent3SepNormalFunc>(input.m_pCollisionDispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)))(previous, entry, data,
                                                                                         timed->m_separatingNormal);
        }
        {
            hkVector4& plane = timed->m_separatingNormal;
            float projected = process.m_linearTimInfo.dot4xyz1(plane);
            timed->m_timeOfSeparatingNormal = input.m_pStepInfo.m_endTime;
            distance = plane(3) - projected;
            if (distance >= input.getTolerance())
            {
                timed->m_separatingNormal(3) = distance;
                if (entry->m_usNumContactPoints)
                    (reinterpret_cast<hkAgent3CleanupFunc>(input.m_pCollisionDispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)))(
                        entry, data, process.m_contactMgr, *output.m_pConstraintOwner);
                break;
            }
        }
    processAtEnd:
        process.m_distAtT1 = distance;
        process.m_aTb.hkTransform_setMulInverseMul(ma->getTransform(), mb->getTransform());
        (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(process, entry, data,
                                                                                   &timed->m_separatingNormal, output);
        break;
    }
    default:
        break;
    }
}

}
