#pragma once

#include "hkpFirstPersonGun.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

class hkTransform;
class hkpRigidBody;
class hkpWorld;
class GGRigidBody;
class GGTransform;
class GGWorld;
class GunTransform;
class GunArg3;

// pdb: class hkpGravityGun, size 0x60, bases: hkpFirstPersonGun, 8 members
class hkpGravityGun : public hkpFirstPersonGun
{
public:
    hkArray<void*> m_grabbedBodies; // src: XBOX_RETAIL_PDB +0x20 (old: m_kPickedBodies)
    hkInt32 m_maxNumObjectsPicked; // src: XBOX_RETAIL_PDB +0x2c (old: m_iMaxPickedBodies)
    hkReal m_maxMassOfObjectPicked; // src: XBOX_RETAIL_PDB +0x30 (old: m_fMaxPickMass)
    hkReal m_maxDistOfObjectPicked; // src: XBOX_RETAIL_PDB +0x34 (old: m_fMaxPickDistance)
    hkReal m_impulseAppliedWhenObjectNotPicked; // src: XBOX_RETAIL_PDB +0x38 (old: m_fPickAngle)
    hkReal m_throwVelocity; // src: XBOX_RETAIL_PDB +0x3c (old: m_fHoldDistance)
    hkVector4 m_capturedObjectPosition; // src: XBOX_RETAIL_PDB +0x40 (old: m_kGrabPosition)
    hkVector4 m_capturedObjectsOffset; // src: XBOX_RETAIL_PDB +0x50 (old: m_kTargetPosition)

    hkpGravityGun() throw();
    hkpGravityGun(FinishingFlag);
    hkpGravityGun* DestroyAndFree(unsigned int) throw();

    hkpRigidBody* hkpGravityGun_dropObject(int);
    hkpRigidBody* FindVisibleRigidBodyToGrab(int, int, int);
    GGRigidBody* FindVisibleRigidBodyToGrab(const GGTransform&, const GGRigidBody*, const GGWorld*);
    bool isGrabbed(const GGRigidBody*) const;
    void gravityGunPush(int viewTransform, int characterBody, int world);
    void gravityGunPush(GunTransform*, GunArg3*, hkpWorld*);
    void DropPickedObjectIfPresent(int, int, int);
    void DropPickedObjectIfPresent(GunTransform*, GunArg3*, hkpWorld*);
    void RemoveAllReferences(int);
    __declspec(noinline) void gravityGunStep(float timeStep, const hkTransform& viewTransform, hkpRigidBody* characterBody);
    void gravityGunStep(hkReal, GunTransform*, GunArg3*);
    void takeObject(hkpRigidBody*);
    void gravityGunPull(hkTransform*, hkpRigidBody*, hkpWorld*);
    void gravityGunPull(GunTransform*, GunArg3*, hkpWorld*);
    void stepGun(hkReal, hkpWorld*, GunArg3*, GunTransform*, bool, bool);
};
