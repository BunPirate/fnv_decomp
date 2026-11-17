#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;
typedef float hkReal;

// pdb: structure hkpBallSocketConstraintAtom, size 0x8, bases: hkpConstraintAtom, 3 members
class hkpBallSocketConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_bodiesToNotify; // src: XBOX_RETAIL_PDB +0x2 (old: m_ucBodiesToNotify)
    hkUint8 m_stabilizationFactor; // src: XBOX_RETAIL_PDB +0x3 (old: m_solvingMethod)
    hkReal m_maxImpulse; // src: XBOX_RETAIL_PDB +0x4 (old: m_usFlags)
};
