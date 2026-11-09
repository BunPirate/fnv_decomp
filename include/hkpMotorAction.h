#pragma once

#include "hkpUnaryAction.h"
#include "hkVector4.h"
#include "hkBool.h"

typedef float hkReal;

// pdb: class hkpMotorAction, size 0x40, bases: hkpUnaryAction, 4 members
class hkpMotorAction : public hkpUnaryAction
{
public:
    char pad1C[0x4];
    hkVector4 m_axis;
    hkReal m_spinRate;
    hkReal m_gain;
    hkBool m_active;
    char pad39[0x7];
};
