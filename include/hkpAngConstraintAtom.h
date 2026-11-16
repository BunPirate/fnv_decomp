#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;

// pdb: structure hkpAngConstraintAtom, size 0x4, bases: hkpConstraintAtom, 2 members
class hkpAngConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_firstConstrainedAxis; // src: XBOX_RETAIL_PDB +0x2 (old: m_ucFirstConstrainedAxis)
    hkUint8 m_numConstrainedAxes; // src: XBOX_RETAIL_PDB +0x3 (old: m_ucNumConstrainedAxes)
};
