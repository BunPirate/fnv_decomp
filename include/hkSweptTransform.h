#pragma once

#include "hkVector4.h"
#include "hkQuaternion.h"
class hkTransform;

struct ClassMemberDescriptor;

typedef float hkReal;
typedef float hkTime;

// pdb: class hkSweptTransform, size 0x50, 5 members
class hkSweptTransform
{
public:
    static const ClassMemberDescriptor Members[];

    __forceinline void _approxTransformAt(hkTime time, hkTransform& transformOut) const;
    hkReal getInterpolationValue(hkTime t) const;
    hkTime getBaseTime() const;
    __forceinline hkReal getInvDeltaTime() const;

    hkVector4 m_centerOfMass0;
    hkVector4 m_vCenterOfMass1;
    hkQuaternion m_rotation0;
    hkQuaternion m_rotation1;
    hkVector4 m_centerOfMassLocal;
};
