#pragma once

#include "hkpConstraintData.h"
#include "hkpBridgeAtoms.h"

// pdb: class hkpMalleableConstraintData, size 0x20, bases: hkpConstraintData, 3 members
class hkpMalleableConstraintData : public hkpConstraintData
{
public:
    hkpMalleableConstraintData(hkpConstraintData* ref) throw();
    virtual ~hkpMalleableConstraintData() throw();

    hkpConstraintData* m_constraintData;
    hkpBridgeAtoms m_atoms;
    float m_strength;
};
