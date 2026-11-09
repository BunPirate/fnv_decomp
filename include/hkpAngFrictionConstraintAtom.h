#pragma once

#include "hkpConstraintAtom.h"

// pdb: structure hkpAngFrictionConstraintAtom, size 0xc, bases: hkpConstraintAtom, 4 members
class hkpAngFrictionConstraintAtom : public hkpConstraintAtom
{
public:
    unsigned char m_isEnabled;
    unsigned char m_firstFrictionAxis;
    unsigned char m_numFrictionAxes;
    char pad5[0x3];
    float m_maxFrictionTorque;
};
