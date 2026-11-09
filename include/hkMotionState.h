#pragma once

#include "hkTransform.h"
#include "hkSweptTransform.h"
#include "hkVector4.h"
#include "QuantizedFloat8.h"

struct ClassMemberDescriptor;
typedef unsigned char hkUint8;

// pdb: class hkMotionState, size 0xb0, 9 members
class hkMotionState
{
public:
    hkTransform m_transform;
    hkSweptTransform m_kSweptTransform;
    hkVector4 m_deltaAngle;
    hkReal m_objectRadius;
    hkReal m_linearDamping;
    hkReal m_angularDamping;
    QuantizedFloat8 m_maxLinearVelocity;
    QuantizedFloat8 m_maxAngularVelocity;
    hkUint8 m_deactivationClass;
    char padAF[1];

    hkMotionState();
    hkMotionState(const hkMotionState& o);
    hkTransform& getTransform();
    const hkTransform& getTransform() const;
    hkSweptTransform& getSweptTransform();
    const hkSweptTransform& getSweptTransform() const;

    static const ClassMemberDescriptor Members[];
};
