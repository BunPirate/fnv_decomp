#pragma once

#include "hkpConstraintAtom.h"

class hkpConstraintData;

// pdb: structure hkpBridgeConstraintAtom, size 0xc, bases: hkpConstraintAtom, 2 members
class hkpBridgeConstraintAtom : public hkpConstraintAtom
{
public:
    hkpBridgeConstraintAtom();
    hkpBridgeConstraintAtom(FinishingFlag flag);
    void hkpBridgeConstraintAtom_init(void* constraintData) throw();

    char pad2[0x2];
    void* m_buildJacobianFunc; // src: XBOX_RETAIL_PDB +0x4 (old: m_pBridge)
    hkpConstraintData* m_constraintData; // src: XBOX_RETAIL_PDB +0x8 (old: m_pConstraintData)
};
