#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;
typedef float hkReal;

// pdb: structure hkpBallSocketConstraintAtom, size 0x8, bases: hkpConstraintAtom, 3 members
class hkpBallSocketConstraintAtom : public hkpConstraintAtom
{
public:
    hkUint8 m_bodiesToNotify;
    hkUint8 m_stabilizationFactor;
    hkReal m_maxImpulse;
};
