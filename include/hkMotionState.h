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
    hkTransform m_transform; // src: XBOX_RETAIL_PDB +0x0 (old: m_kMotionTransform)
    hkSweptTransform m_kSweptTransform;
    hkVector4 m_deltaAngle; // src: XBOX_RETAIL_PDB +0x90 (old: m_kDeltaAngle)
    hkReal m_objectRadius; // src: XBOX_RETAIL_PDB +0xa0 (old: m_fObjectRadius)
    hkReal m_linearDamping; // src: XBOX_RETAIL_PDB +0xa4 (old: m_fLinearDamping)
    hkReal m_angularDamping; // src: XBOX_RETAIL_PDB +0xa8 (old: m_fAngularDamping)
    QuantizedFloat8 m_maxLinearVelocity; // src: XBOX_RETAIL_PDB +0xac (old: m_fSurfaceFriction)
    QuantizedFloat8 m_maxAngularVelocity; // src: XBOX_RETAIL_PDB +0xad (old: m_fRestitution)
    hkUint8 m_deactivationClass; // src: XBOX_RETAIL_PDB +0xae (old: m_uiDeactivationClass)
    char padAF[1];

    hkMotionState();
    hkMotionState(const hkMotionState& o);
    hkTransform& getTransform();
    const hkTransform& getTransform() const;
    hkSweptTransform& getSweptTransform();
    const hkSweptTransform& getSweptTransform() const;

    static const ClassMemberDescriptor Members[];
};
