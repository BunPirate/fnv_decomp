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
    hkVector4 m_axis; // src: XBOX_RETAIL_PDB +0x20 (old: m_kAxisEndPoints)
    hkReal m_spinRate; // src: XBOX_RETAIL_PDB +0x30 (old: m_fSpinRate)
    hkReal m_gain; // src: XBOX_RETAIL_PDB +0x34 (old: m_fGain)
    hkBool m_active; // src: XBOX_RETAIL_PDB +0x38 (old: m_bSlotEnabled)
    char pad39[0x7];
};
