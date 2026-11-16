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

    hkUint8 m_isEnabled; // src: XBOX_RETAIL_PDB +0x2 (old: m_bLimitEnabled)
    hkUint8 m_twistAxisInA; // src: XBOX_RETAIL_PDB +0x3 (old: m_ucMemOffsetToAngleOffset)
    hkUint8 m_refAxisInB; // src: XBOX_RETAIL_PDB +0x4 (old: m_ucMemOffsetToOldAngleOffset)
    hkUint8 m_angleMeasurementMode; // src: XBOX_RETAIL_PDB +0x5 (old: m_ucMemOffsetToFirstConstrainedDof)
    hkUint8 m_memOffsetToAngleOffset; // src: XBOX_RETAIL_PDB +0x6 (old: m_ucAngleMeasurementMode)
    char pad7[0x1];
    hkReal m_minAngle; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMinAngle)
    hkReal m_maxAngle; // src: XBOX_RETAIL_PDB +0xc (old: m_fMaxAngle)
    hkReal m_angularLimitsTauFactor; // src: XBOX_RETAIL_PDB +0x10 (old: m_fAngularLimitsTauFactor)
};
