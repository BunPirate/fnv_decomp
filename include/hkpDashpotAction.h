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

    hkVector4 m_point[2];
    hkReal m_strength;
    hkReal m_damping;
    char pad48[0x8];
    hkVector4 m_impulse;
};
