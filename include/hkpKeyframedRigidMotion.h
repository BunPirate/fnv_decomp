#pragma once

#include "hkpMotion.h"

// pdb: class hkpKeyframedRigidMotion, size 0x120, bases: hkpMotion, 0 members
class hkpKeyframedRigidMotion : public hkpMotion
{
public:
    static const ClassMemberDescriptor Members[];

    hkpKeyframedRigidMotion(FinishingFlag flag);
    hkpKeyframedRigidMotion(const hkVector4& position, const hkQuaternion& rotation) throw();
    virtual ~hkpKeyframedRigidMotion() throw();

    virtual void SetStepPosition(hkReal position, hkReal timestep);
    virtual void vf6c();

protected:
    hkpKeyframedRigidMotion();
};
