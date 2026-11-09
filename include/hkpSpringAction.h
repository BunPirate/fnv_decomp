#pragma once

#include "hkpBinaryAction.h"
#include "hkVector4.h"
#include "hkBool.h"

typedef float hkReal;

// pdb: class hkpSpringAction, size 0x60, bases: hkpBinaryAction, 8 members
class hkpSpringAction : public hkpBinaryAction
{
public:
    hkVector4 m_lastForce;
    hkVector4 m_positionAinA;
    hkVector4 m_positionBinB;
    hkReal m_restLength;
    hkReal m_strength;
    hkReal m_damping;
    hkBool m_onCompression;
    hkBool m_onExtension;
    char pad5E[0x2];
};
