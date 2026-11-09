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
    hkArray<void*> m_grabbedBodies;
    hkInt32 m_maxNumObjectsPicked;
    hkReal m_maxMassOfObjectPicked;
    hkReal m_maxDistOfObjectPicked;
    hkReal m_impulseAppliedWhenObjectNotPicked;
    hkReal m_throwVelocity;
    hkVector4 m_capturedObjectPosition;
    hkVector4 m_capturedObjectsOffset;

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
