#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"
#include "hkaAnimation.h"

typedef unsigned int hkUint32;

// pdb: class hkpMouseSpringAction, size 0x60, bases: hkpUnaryAction, 8 members
class hkpMouseSpringAction : public hkpUnaryAction
{
public:
    void ApplySpringForce(void*);

    char pad1C[0x4];
    hkVector4 m_positionInRbLocal;
    hkVector4 m_mousePositionInWorld;
    hkReal m_springDamping;
    hkReal m_springElasticity;
    hkReal m_maxRelativeForce;
    hkReal m_objectDamping;
    hkUint32 m_shapeKey;
    hkArray<char> m_applyCallbacks;
};
