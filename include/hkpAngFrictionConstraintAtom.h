#pragma once

#include "hkpConstraintAtom.h"

// pdb: structure hkpAngFrictionConstraintAtom, size 0xc, bases: hkpConstraintAtom, 4 members
class hkpAngFrictionConstraintAtom : public hkpConstraintAtom
{
public:
    unsigned char m_isEnabled; // src: XBOX_RETAIL_PDB +0x2 (old: m_bLimitEnabled)
    unsigned char m_firstFrictionAxis; // src: XBOX_RETAIL_PDB +0x3 (old: m_ucFirstFrictionAxis)
    unsigned char m_numFrictionAxes; // src: XBOX_RETAIL_PDB +0x4 (old: m_ucNumFrictionAxes)
    char pad5[0x3];
    float m_maxFrictionTorque; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMaxFrictionTorque)
};
