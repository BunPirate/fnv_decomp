#pragma once

#include "hkpBinaryAction.h"
#include "hkArray.h"
#include "hkStepInfo.h"
#include "hkVector4.h"

typedef float hkReal;

// pdb: class hkpDashpotAction, size 0x60, bases: hkpBinaryAction, 4 members
class hkpDashpotAction : public hkpBinaryAction
{
public:
    __declspec(noinline) hkpDashpotAction* hkpDashpotAction_ctor(int entityA, int entityB, int userData);
    hkpAction* clone_00d4d9d0(const hkArray<hkpEntity*>& newEntities, const hkArray<hkpEntity*>& newPhantoms);
    void applyAction_00d4da60(hkPadSpu<const hkStepInfo*> stepInfo);

    hkVector4 m_point[2]; // src: XBOX_RETAIL_PDB +0x20 (old: m_kPoint)
    hkReal m_strength; // src: XBOX_RETAIL_PDB +0x40 (old: m_fSpringStrength)
    hkReal m_damping; // src: XBOX_RETAIL_PDB +0x44 (old: m_fMotorDamping)
    char pad48[0x8];
    hkVector4 m_impulse; // src: XBOX_RETAIL_PDB +0x50 (old: m_fContactImpulse)
};
