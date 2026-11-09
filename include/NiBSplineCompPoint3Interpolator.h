#pragma once

#include "NiBSplinePoint3Interpolator.h"

// pdb: class NiBSplineCompPoint3Interpolator, size 0x34, bases: NiBSplinePoint3Interpolator, 1 members
class NiBSplineCompPoint3Interpolator : public NiBSplinePoint3Interpolator
{
public:
    virtual void LoadBinary(NiStream& kStream);

    float m_afCompScalars;
    float m_fDecodeScale;
};
