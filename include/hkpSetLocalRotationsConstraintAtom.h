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
    hkRotation m_rotationA;
    hkRotation m_rotationB;
};
