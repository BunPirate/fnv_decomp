#pragma once

#include "hkReferencedObject.h"
#include "hkMotionState.h"
#include "hkVector4.h"
#include "hkpShape.h"
#include "FinishingFlag.h"

class hkpMaxSizeMotion;
class hkMatrix3;
class hkMotionStateH;
struct ClassMemberDescriptor;

typedef unsigned short hkUint16;
#include "hkHalf.h"   // Havok 7.1 hkHalf (was a short typedef here)

// pdb: class hkpMotion, size 0x120, bases: hkReferencedObject, 12 members
class hkpMotion : public hkReferencedObject
{
public:
    enum MotionType
    {
        MOTION_INVALID = 0,
        MOTION_DYNAMIC = 1,
        MOTION_SPHERE_INERTIA = 2,
        MOTION_BOX_INERTIA = 3,
        MOTION_KEYFRAMED = 4,
        MOTION_FIXED = 5,
        MOTION_THIN_BOX_INERTIA = 6,
        MOTION_CHARACTER = 7,
        MOTION_MAX_ID = 8
    };

    enum
    {
        NUM_INACTIVE_FRAMES_TO_DEACTIVATE = 5
    };

    hkpMotion(FinishingFlag kFlag);
    hkpMotion(const hkVector4& kPosition, const hkQuaternion& kRotation, bool bWantDeactivation) throw();
    virtual ~hkpMotion() throw();

    virtual void SetBodyMass(float fMass);
    virtual void SetMassInv(float fInverseMass);
    virtual void GetInverseScaleMatrix(hkMatrix3& kInertia) const;
    virtual void GetInertiaLocal(hkMatrix3& kInertia) const;
    virtual void SetInertiaLocal(const hkMatrix3& kInertia);
    virtual void SetInertiaInvLocal(const hkMatrix3& kInverseInertia);
    virtual void GetInertiaInvLocal(hkMatrix3& kInverseInertia) const;
    virtual void GetLocalInverseInertia(hkMatrix3& kInverseInertia) const;
    virtual void SetCenterOfMassInLocal(const hkVector4& kCenterOfMass);
    virtual void SetWorldPosition(const hkVector4& kPosition);
    virtual void SetBodyOrientation(const hkQuaternion& kRotation);
    virtual void SetPositionAndRotation(const hkVector4& kPosition, const hkQuaternion& kRotation);
    virtual void SetGeometryTransform(const hkTransform& kTransform);
    virtual void SetTranslationalVelocity(const hkVector4& kVel);
    virtual void SetRotationalVelocity(const hkVector4& kVel);
    virtual void GetProjectedPointVelocity(const hkVector4& kPosition, const hkVector4& kDirection,
                                          float& kVelocity, float& kInverseVirtualMass) const;
    virtual void SetCollisionShape(const hkVector4& kImpulse);
    virtual void ApplyImpulseAtPoint(const hkVector4& kImpulse, const hkVector4& kPoint);
    virtual void ApplyAngularImpulseToBodies(const hkVector4& kImpulse);
    virtual void vf58(float fTimestep, const hkVector4& kForce, const hkVector4& kPoint);
    virtual void vf5c(float fTimestep, const hkVector4& kForce);
    virtual void StepMotion(float deltaTime, const hkVector4& torque);
    virtual void getMotionStateAndVelocitiesAndDeactivationType(hkpMotion* motionOut);

    MotionType getType() const;
    const hkTransform& getTransform() const;
    hkMotionStateH* GetMotionState();
    int getNumInactiveFrames(int iSelect);
    void incrementNumInactiveFramesMt(int iSelect, int iWorldDeactivationNumInactiveFramesSelectFlag);
    void zeroNumInactiveFramesMt(int iSelect, int iWorldDeactivationNumInactiveFramesSelectFlag);
    hkSimdReal getMassInv() const;
    float GetMassValue();
    void SetFlagBits(int iFirst, int iSecond, int iCode);
    void SetFlagBits(unsigned int uFirst, unsigned int uSecond, int iCode);

    static const ClassMemberDescriptor Members[];

    hkEnum<MotionType, hkUint8> m_type;
    hkUint8 m_deactivationIntegrateCounter; // src: XBOX_RETAIL_PDB +0x9 (old: m_ucDeactivationIntegrateCounter)
    hkUint16 m_deactivationNumInactiveFrames[2]; // src: XBOX_RETAIL_PDB +0xa (old: m_ausDeactivationNumInactiveFrames)
    char padE[2];
    hkMotionState m_kMotionState;
    hkVector4 m_inertiaAndMassInv; // src: XBOX_RETAIL_PDB +0xc0 (old: m_kInertiaAndMassInv)
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_deactivationRefPosition[2]; // src: XBOX_RETAIL_PDB +0xf0 (old: m_akDeactivationReferencePositions)
    hkUint32 m_deactivationRefOrientation[2]; // src: XBOX_RETAIL_PDB +0x110 (old: m_auiDeactivationReferenceOrientations)
    hkpMaxSizeMotion* m_savedMotion; // src: XBOX_RETAIL_PDB +0x118 (old: m_pSavedMotion)
    hkUint16 m_savedQualityTypeIndex; // src: XBOX_RETAIL_PDB +0x11c (old: m_savedMotionSize)
    hkHalf m_gravityFactor; // src: XBOX_RETAIL_PDB +0x11e (old: m_fGravityFactor)
};
