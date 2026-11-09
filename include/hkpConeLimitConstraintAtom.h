#pragma once

#include "hkpConstraintAtom.h"

typedef unsigned char hkUint8;
typedef float hkReal;

// pdb: structure hkpConeLimitConstraintAtom, size 0x14, bases: hkpConstraintAtom, 8 members
class hkpConeLimitConstraintAtom : public hkpConstraintAtom
{
public:
    enum MeasurementMode
    {
        ZERO_WHEN_VECTORS_ALIGNED = 0,
        ZERO_WHEN_VECTORS_PERPENDICULAR = 1
    };

    hkUint8 m_isEnabled;
    hkUint8 m_twistAxisInA;
    hkUint8 m_refAxisInB;
    hkUint8 m_angleMeasurementMode;
    hkUint8 m_memOffsetToAngleOffset;
    char pad7[0x1];
    hkReal m_minAngle;
    hkReal m_maxAngle;
    hkReal m_angularLimitsTauFactor;
};
