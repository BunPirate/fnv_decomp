// Shared Havok layouts. Only construction declarations absent from the shared
// headers remain local.
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMatrix3.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpMaxSizeMotion.h"
#include "../../../../../include/hkMotionState.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkUFloat8.h"

// These value types are initialized by the surrounding SIMD code.
inline hkAabb::hkAabb() {}

extern float DAT_01016248;
inline float lowerPair(float left, float right)
{
    return left < right ? left : right;
}
inline float lowerPairReversed(float left, float right)
{
    return left > right ? right : left;
}

#include <xmmintrin.h>
#include <math.h>
#include "../../../../../include/hkpFixedRigidMotion.h"
extern "C" int DAT_01268370;
extern "C" double __cdecl sqrt(double);
static inline float CA8Sqrtf(float x)
{
    return ((float)sqrt((double)x));
}
static inline float CA8Sqrt(float r)
{
    return CA8Sqrtf(r);
}
static inline float CA8Max2(float a, float b)
{
    return (a > b) ? a : b;
}

struct hkpRigidBodyCinfo;

// Shared data layout; these construction entry points are not declared by
// hkpRigidBody.h or hkpEntity.h yet.
struct RigidBodyConstruction : hkpRigidBody
{
    void FUN_00c9cce0(const hkpShape* shape) throw();
    void hkpRigidBody_updateCachedShapeInfo(const hkpShape* shape, hkVector4* extentOut) throw();
    void hkpRigidBody_enableDeactivation(bool enabled) throw();
    void hkpRigidBody_setAngularVelocity(const hkVector4& newVel) throw();
    RigidBodyConstruction* hkpRigidBody_ctor(const hkpRigidBodyCinfo& info);
};

// @fnv 0x00ca8150
// src: XBOX_PDB 0x00ca8150
// pdb: hkpRigidBody::updateCachedShapeInfo | hkpRigidBody.obj | retail, upstream name already matches, high
// pdb params: shape, extentOut
// pdb locals: aabb, assertBuf, ostr
void RigidBodyConstruction::hkpRigidBody_updateCachedShapeInfo(const hkpShape* shape, hkVector4* extentOut) throw()
{
    hkAabb pair;
    shape->CalculateAabb(reinterpret_cast<const hkTransform&>(DAT_01268370), 0.0f, pair);
    __m128 a = *(const __m128*)&pair.m_kMinimumCorner;
    __m128 b = *(const __m128*)&pair.m_kMaximumCorner;
    _mm_store_ps(&extentOut->x, _mm_sub_ps(b, a));

    hkVector4& p = pair.m_kMinimumCorner;
    unsigned int* target = reinterpret_cast<unsigned int*>(&p);
    const unsigned int* source = reinterpret_cast<const unsigned int*>(&m_motion.m_kMotionState.m_kSweptTransform.m_centerOfMassLocal);
    target[0] = source[0];
    target[1] = source[1];
    target[2] = source[2];
    target[3] = source[3];
    __m128 pv = _mm_load_ps(&p.x);
    __m128 d0 = _mm_sub_ps(b, pv);
    __m128 d1 = _mm_sub_ps(a, pv);
    __m128 x0 = _mm_mul_ps(d0, d0);
    float db;
    _mm_store_ss(&db, _mm_add_ss(_mm_shuffle_ps(x0, x0, 0xaa), _mm_add_ss(_mm_shuffle_ps(x0, x0, 0x55), x0)));
    __m128 x1 = _mm_mul_ps(d1, d1);
    float da;
    _mm_store_ss(&da, _mm_add_ss(_mm_shuffle_ps(x1, x1, 0xaa), _mm_add_ss(_mm_shuffle_ps(x1, x1, 0x55), x1)));

    m_motion.m_kMotionState.m_objectRadius = CA8Sqrt(CA8Max2(db, da));
}

// Only the initialization methods missing from the shared headers live here.
struct RigidMotionInitialization : hkpMaxSizeMotion
{
    void FUN_00c86420(int) throw();
};
inline void* operator new(std::size_t, void* memory) throw()
{
    return memory;
}
// pdb: class hkpRigidBodyCinfo, size 0xc0, 28 members
struct hkpRigidBodyCinfo
{
    unsigned int m_collisionFilterInfo; // src: XBOX_RETAIL_PDB +0x0 (old: collisionFilterInfo)
    const hkpShape* m_shape; // src: XBOX_RETAIL_PDB +0x4 (old: shape)
    hkReferencedObject* m_localFrame; // src: XBOX_RETAIL_PDB +0x8 (old: localFrame)
    unsigned char m_collisionResponse, unk0d; // src: XBOX_RETAIL_PDB +0xc (old: response)
    unsigned short m_contactPointCallbackDelay; // src: XBOX_RETAIL_PDB +0xe (old: responseCount)
    hkVector4 m_position; // src: XBOX_RETAIL_PDB +0x10 (old: position)
    hkQuaternion m_rotation; // src: XBOX_RETAIL_PDB +0x20 (old: rotation)
    hkVector4 m_linearVelocity, m_angularVelocity; // src: XBOX_RETAIL_PDB m_angularVelocity +0x40 (old: angularVelocity); m_linearVelocity +0x30 (old: linearVelocity)
    hkMatrix3 m_inertiaTensor; // src: XBOX_RETAIL_PDB +0x50 (old: inertia)
    hkVector4 m_centerOfMass; // src: XBOX_RETAIL_PDB +0x80 (old: centerOfMass)
    float m_mass, m_linearDamping, m_angularDamping; // src: XBOX_RETAIL_PDB m_angularDamping +0x98 (old: angularDamping); m_linearDamping +0x94 (old: linearDamping); m_mass +0x90 (old: mass)
    unsigned short m_gravityFactor, solverDeactivation; // src: XBOX_RETAIL_PDB +0x9c (old: unk9c)
    float m_friction, m_restitution, m_maxLinearVelocity, m_maxAngularVelocity, m_allowedPenetrationDepth; // src: XBOX_RETAIL_PDB m_friction +0xa0 (old: friction); m_maxAngularVelocity +0xac (old: maxAngular); m_maxLinearVelocity +0xa8 (old: maxLinear); m_allowedPenetrationDepth +0xb0 (old: penetrationDepth); m_restitution +0xa4 (old: restitution)
    signed char m_motionType; // src: XBOX_RETAIL_PDB +0xb4 (old: motionType)
    unsigned char m_enableDeactivation; // src: XBOX_RETAIL_PDB +0xb5 (old: enableDeactivation)
    signed char m_solverDeactivation, m_qualityType; // src: XBOX_RETAIL_PDB m_solverDeactivation +0xb6 (old: deactivationClass); m_qualityType +0xb7 (old: quality)
    unsigned char m_autoRemoveLevel, m_responseModifierFlags; // src: XBOX_RETAIL_PDB m_autoRemoveLevel +0xb8 (old: removalLevel); m_responseModifierFlags +0xb9 (old: responseModifier)
    signed char m_numShapeKeysInContactPointProperties; // src: XBOX_RETAIL_PDB +0xba (old: shapeKeys)
    unsigned char m_forceCollideOntoPpu; // src: XBOX_RETAIL_PDB +0xbb (old: forceCollide)
};

unsigned char __cdecl GetSubtreeDepth(const hkpShape* shape) throw();
extern float DAT_0104da48;

extern hkError* DAT_01268360;

static __declspec(noinline) void ComputeScaledMinimum(hkpCollidable* coll, const hkVector4& he)
{
    float lo = lowerPair(he.x, lowerPair(he.y, he.z));
    float hi = he.x > he.y ? he.x : he.y;
    if (he.z > hi)
        hi = he.z;
    coll->m_allowedPenetrationDepth = lowerPairReversed(hi * DAT_01016248, lo);
    coll->m_boundingVolumeData.m_pChildShapeKeys = coll->m_boundingVolumeData.m_pChildShapeAabbs;
}

extern void* DAT_010c7888;
// @fnv 0x00ca8c90
// src: XBOX_RETAIL_PDB 0x00ca8c90
// pdb: hkpRigidBody::hkpRigidBody | hkpRigidBody.obj | retail, string-set bridge, high
// pdb params: flag
RigidBodyConstruction* RigidBodyConstruction::hkpRigidBody_ctor(const hkpRigidBodyCinfo& info)
{
    FUN_00c9cce0(info.m_shape);
    *(void**)this = &DAT_010c7888;
    *reinterpret_cast<unsigned char*>(&m_material.m_responseType) = info.m_collisionResponse;
    m_contactPointCallbackDelay = info.m_contactPointCallbackDelay;
    m_kCollidable.m_broadPhaseHandle.m_collisionFilterInfo = info.m_collisionFilterInfo;
    hkReferencedObject* frame = info.m_localFrame;
    if (frame)
    {
        frame->addReference();
        if (m_localFrame)
            reinterpret_cast<hkReferencedObject*>(m_localFrame)->removeReference();
        m_localFrame = reinterpret_cast<hkLocalFrame*>(frame);
        frame->addReference();
    }
    if (info.m_motionType == 5)
    {
        hkpFixedRigidMotion* fixed = ::new (&m_motion) hkpFixedRigidMotion(&info.m_position, &info.m_rotation);
        reinterpret_cast<hkUFloat8*>(&fixed->m_kMotionState.m_maxLinearVelocity)->FindFloatTableIndex(&info.m_maxLinearVelocity);
        reinterpret_cast<hkUFloat8*>(&fixed->m_kMotionState.m_maxAngularVelocity)->FindFloatTableIndex(&info.m_maxAngularVelocity);
        fixed->FUN_00c86420(1);
        m_kCollidable.m_pMotionState = &m_motion.m_kMotionState.m_transform;
        if (info.m_allowedPenetrationDepth <= 0.0f)
            m_kCollidable.m_allowedPenetrationDepth = DAT_0104da48;
        else
            m_kCollidable.m_allowedPenetrationDepth = info.m_allowedPenetrationDepth;
    }
    else
    {
        hkpRigidBody::createDynamicRigidMotion(
            static_cast<hkpMotion::MotionType>(info.m_motionType), info.m_position, info.m_rotation,
            info.m_mass, info.m_inertiaTensor, info.m_centerOfMass, info.m_maxLinearVelocity, info.m_maxAngularVelocity, &m_motion);
        static_cast<RigidMotionInitialization&>(m_motion).FUN_00c86420(info.m_solverDeactivation);
        OnTrigger(info.m_linearVelocity);
        hkpRigidBody_setAngularVelocity(info.m_angularVelocity);
        m_kCollidable.m_pMotionState = &m_motion.m_kMotionState.m_transform;
        m_kCollidable.m_allowedPenetrationDepth = info.m_allowedPenetrationDepth;
    }
    hkpRigidBody_enableDeactivation(info.m_enableDeactivation != 0);
    m_motion.m_kMotionState.m_linearDamping = info.m_linearDamping;
    m_motion.m_kMotionState.m_angularDamping = info.m_angularDamping;
    if (m_kCollidable.m_pCollisionShape)
    {
        hkVector4 halfExtents;
        hkpRigidBody_updateCachedShapeInfo(m_kCollidable.m_pCollisionShape, &halfExtents);
        if (m_kCollidable.m_allowedPenetrationDepth <= 0.0f)
            ComputeScaledMinimum(&m_kCollidable, halfExtents);
    }
    if (info.m_qualityType != -1)
        m_kCollidable.m_broadPhaseHandle.m_objectQualityType = info.m_qualityType;
    else if (*reinterpret_cast<const unsigned char*>(&m_motion.m_type) == 5)
        m_kCollidable.m_broadPhaseHandle.m_objectQualityType = 0;
    else
        m_kCollidable.m_broadPhaseHandle.m_objectQualityType = (info.m_motionType == 4) ? 1 : 2;
    m_autoRemoveLevel = info.m_autoRemoveLevel;
    if (info.m_forceCollideOntoPpu)
        m_kCollidable.m_forceCollideOntoPpu |= 1;
    m_material.m_friction = info.m_friction;
    m_material.m_restitution = info.m_restitution;
    m_motion.m_gravityFactor.m_value = info.solverDeactivation;
    if (info.m_numShapeKeysInContactPointProperties >= 0)
    {
        m_numShapeKeysInContactPointProperties = info.m_numShapeKeysInContactPointProperties;
        if (m_numShapeKeysInContactPointProperties > 0 && m_numShapeKeysInContactPointProperties < GetSubtreeDepth(info.m_shape))
        {
            char buffer[512];
            __declspec(align(16)) char streamStorage[(sizeof(hkOstream) + 15) & ~15];
            ::new (streamStorage) hkOstream(buffer, 512);
            hkOstream& stream = *reinterpret_cast<hkOstream*>(streamStorage);
            stream.ProcessAndReturnValue_00cc01c0(
                "Shape key storage insufficient to store all possible branches. This may cause truncation of the shape key information.");
            DAT_01268360->message(1, 0x458a1bb2, buffer, ".\\Entity\\hkpRigidBody.cpp", 329);
            stream.FUN_00cc00e0();
        }
    }
    else
        m_numShapeKeysInContactPointProperties = GetSubtreeDepth(info.m_shape);
    m_responseModifierFlags = info.m_responseModifierFlags;
    return this;
}
