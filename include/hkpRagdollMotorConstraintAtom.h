#pragma once

#include "hkpConstraintAtom.h"
#include "hkBool.h"
#include "hkMatrix3.h"

class hkpConstraintMotor;

typedef short hkInt16;

// pdb: structure hkpRagdollMotorConstraintAtom, size 0x50, bases: hkpConstraintAtom, 5 members
class hkpRagdollMotorConstraintAtom : public hkpConstraintAtom
{
public:
    hkBool m_isEnabled; // src: XBOX_RETAIL_PDB +0x2 (old: m_bLimitEnabled)
    char pad3[0x1];
    hkInt16 m_initializedOffset; // src: XBOX_RETAIL_PDB +0x4 (old: m_iInitializedOffset)
    hkInt16 m_previousTargetAnglesOffset; // src: XBOX_RETAIL_PDB +0x6 (old: m_iPreviousTargetAnglesOffset)
    char pad8[0x8];
    hkMatrix3 m_target_bRca; // src: XBOX_RETAIL_PDB +0x10 (old: m_kMotorAxes)
    hkpConstraintMotor* m_motors[3]; // src: XBOX_RETAIL_PDB +0x40 (old: m_ppMotors)
    char pad4C[0x4];
};
