#pragma once

#include "hkpParametricCurve.h"
#include "hkBool.h"
#include "hkVector4.h"
#include "hkArray.h"
#include "hkaAnimation.h"

// pdb: class hkpLinearParametricCurve, size 0x40, bases: hkpParametricCurve, 5 members
class hkpLinearParametricCurve : public hkpParametricCurve
{
public:
    __declspec(noinline) hkpLinearParametricCurve() throw();
    virtual ~hkpLinearParametricCurve() throw();

    virtual void vf11();
    virtual void vf12();
    virtual void vf13();

    hkReal m_smoothingFactor; // src: XBOX_RETAIL_PDB +0x8 (old: m_fSmoothingValue)
    hkBool m_closedLoop; // src: XBOX_RETAIL_PDB +0xc (old: m_bClosedLoop)
    char padD[0x3];
    hkVector4 m_dirNotParallelToTangentAlongWholePath; // src: XBOX_RETAIL_PDB +0x10 (old: m_kVector4)
    hkArray<hkVector4> m_points; // src: XBOX_RETAIL_PDB +0x20 (old: m_kPoints)
    hkArray<hkReal> m_distance; // src: XBOX_RETAIL_PDB +0x2c (old: m_fClosestPointDistanceSquared)
    char pad38[0x8];
};
