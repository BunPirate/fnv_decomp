#pragma once

#include "hkpKeyframedRigidMotion.h"

// pdb: class hkpMaxSizeMotion, size 0x120, bases: hkpKeyframedRigidMotion, 0 members
class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
public:
    static const ClassMemberDescriptor Members[];

private:
    void operator=(const hkpMaxSizeMotion& other);
};
