#pragma once

#include "hkpConstraintAtom.h"
#include "hkRotation.h"

// pdb: structure hkpSetLocalRotationsConstraintAtom, size 0x70, bases: hkpConstraintAtom, 2 members
class hkpSetLocalRotationsConstraintAtom : public hkpConstraintAtom
{
public:
    hkpSetLocalRotationsConstraintAtom();
    hkpSetLocalRotationsConstraintAtom(FinishingFlag f);

    char pad2[0xE];
    hkRotation m_rotationA; // src: XBOX_RETAIL_PDB +0x10 (old: m_kRotationA)
    hkRotation m_rotationB; // src: XBOX_RETAIL_PDB +0x40 (old: m_kRotationB)
};
