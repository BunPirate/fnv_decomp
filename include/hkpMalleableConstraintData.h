#pragma once

#include "hkpConstraintData.h"
#include "hkpBridgeAtoms.h"

// pdb: class hkpMalleableConstraintData, size 0x20, bases: hkpConstraintData, 3 members
class hkpMalleableConstraintData : public hkpConstraintData
{
public:
    hkpMalleableConstraintData(hkpConstraintData* ref) throw();
    virtual ~hkpMalleableConstraintData() throw();

    hkpConstraintData* m_constraintData; // src: XBOX_RETAIL_PDB +0xc (old: m_pConstraintData)
    hkpBridgeAtoms m_atoms; // src: XBOX_RETAIL_PDB +0x10 (old: m_kBridgeAtoms)
    float m_strength; // src: XBOX_RETAIL_PDB +0x1c (old: m_fSpringStrength)
};
