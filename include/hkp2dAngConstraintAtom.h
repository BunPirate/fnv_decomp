#pragma once

#include "hkpConstraintAtom.h"

// pdb: structure hkp2dAngConstraintAtom, size 0x4, bases: hkpConstraintAtom, 1 members
class hkp2dAngConstraintAtom : public hkpConstraintAtom
{
public:
    hkp2dAngConstraintAtom(FinishingFlag f);
    hkp2dAngConstraintAtom() : hkpConstraintAtom(FinishingFlag()) {}

    unsigned char m_freeRotationAxis; // src: XBOX_RETAIL_PDB +0x2 (old: m_ucFreeRotationAxis)
    char unk03;
};
