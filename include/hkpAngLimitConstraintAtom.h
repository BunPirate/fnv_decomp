#pragma once

#include "hkpConstraintAtom.h"

// pdb: structure hkpAngLimitConstraintAtom, size 0x10, bases: hkpConstraintAtom, 5 members
class hkpAngLimitConstraintAtom : public hkpConstraintAtom
{
public:
    hkpAngLimitConstraintAtom(FinishingFlag f);
    hkpAngLimitConstraintAtom() : hkpConstraintAtom(FinishingFlag()) {}

    unsigned char m_isEnabled;
    unsigned char m_limitAxis;
    float m_minAngle;
    float m_maxAngle;
    float m_angularLimitsTauFactor;
};
