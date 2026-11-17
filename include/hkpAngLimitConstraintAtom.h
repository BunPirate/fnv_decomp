#pragma once

#include "hkpConstraintAtom.h"

// pdb: structure hkpAngLimitConstraintAtom, size 0x10, bases: hkpConstraintAtom, 5 members
class hkpAngLimitConstraintAtom : public hkpConstraintAtom
{
public:
    hkpAngLimitConstraintAtom(FinishingFlag f);
    hkpAngLimitConstraintAtom() : hkpConstraintAtom(FinishingFlag()) {}

    unsigned char m_isEnabled; // src: XBOX_RETAIL_PDB +0x2 (old: m_bLimitEnabled)
    unsigned char m_limitAxis; // src: XBOX_RETAIL_PDB +0x3 (old: m_ucLimitAxis)
    float m_minAngle; // src: XBOX_RETAIL_PDB +0x4 (old: m_fMinAngle)
    float m_maxAngle; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMaxAngle)
    float m_angularLimitsTauFactor; // src: XBOX_RETAIL_PDB +0xc (old: m_fAngularLimitsTauFactor)
};
