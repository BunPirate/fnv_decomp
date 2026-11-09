#pragma once

#include "hkpBinaryAction.h"
#include "hkQuaternion.h"

typedef float hkReal;

// pdb: class hkpAngularDashpotAction, size 0x40, bases: hkpBinaryAction, 3 members
class hkpAngularDashpotAction : public hkpBinaryAction
{
public:
    hkQuaternion m_rotation;
    hkReal m_strength;
    hkReal m_damping;
    char pad38[0x8];
};
