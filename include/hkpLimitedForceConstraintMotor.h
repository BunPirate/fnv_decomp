#pragma once

#include "hkpConstraintMotor.h"

typedef float hkReal;

// pdb: class hkpLimitedForceConstraintMotor, size 0x14, bases: hkpConstraintMotor, 2 members
class hkpLimitedForceConstraintMotor : public hkpConstraintMotor
{
public:
    __forceinline hkpLimitedForceConstraintMotor(const hkpLimitedForceConstraintMotor& o) throw()
        : hkpConstraintMotor(o), m_minForce(o.m_minForce), m_maxForce(o.m_maxForce)
    {}

    hkReal m_minForce; // src: XBOX_RETAIL_PDB +0xc (old: m_fMinForce)
    hkReal m_maxForce; // src: XBOX_RETAIL_PDB +0x10 (old: m_fMaxForce)
};
