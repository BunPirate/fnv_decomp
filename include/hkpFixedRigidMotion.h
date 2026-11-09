#pragma once

#include "hkpKeyframedRigidMotion.h"

// pdb: class hkpFixedRigidMotion, size 0x120, bases: hkpKeyframedRigidMotion, 0 members
class hkpFixedRigidMotion : public hkpKeyframedRigidMotion
{
public:
    hkpFixedRigidMotion(const hkVector4* position, const hkQuaternion* rotation) throw();

    virtual void SetTranslationalVelocity(const hkVector4& kVel);
    virtual void SetRotationalVelocity(const hkVector4& kVel);
    virtual void SetStepPosition(hkReal position, hkReal timestep);
    virtual void hkpFixedRigidMotion_getPositionAndVelocities(int* motion);

    void FUN_00c86420(int deactivationClass) throw();
};
