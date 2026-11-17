#pragma once

#include "hkpBinaryAction.h"
#include "hkQuaternion.h"

typedef float hkReal;

// pdb: class hkpAngularDashpotAction, size 0x40, bases: hkpBinaryAction, 3 members
class hkpAngularDashpotAction : public hkpBinaryAction
{
public:
    hkQuaternion m_rotation;
    hkReal m_strength; // src: XBOX_RETAIL_PDB +0x30 (old: m_fSpringStrength)
    hkReal m_damping; // src: XBOX_RETAIL_PDB +0x34 (old: m_fMotorDamping)
    char pad38[0x8];
};
