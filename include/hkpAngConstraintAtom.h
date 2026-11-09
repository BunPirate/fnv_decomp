#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;

// pdb: structure hkpAngConstraintAtom, size 0x4, bases: hkpConstraintAtom, 2 members
class hkpAngConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_firstConstrainedAxis;
    hkUint8 m_numConstrainedAxes;
};
