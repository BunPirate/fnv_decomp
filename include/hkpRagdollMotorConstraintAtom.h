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
    hkBool m_isEnabled;
    char pad3[0x1];
    hkInt16 m_initializedOffset;
    hkInt16 m_previousTargetAnglesOffset;
    char pad8[0x8];
    hkMatrix3 m_target_bRca;
    hkpConstraintMotor* m_motors[3];
    char pad4C[0x4];
};
