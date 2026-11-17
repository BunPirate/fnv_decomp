#pragma once

#include "NiBSplineFloatInterpolator.h"

// pdb: class NiBSplineCompFloatInterpolator, size 0x2c, bases: NiBSplineFloatInterpolator, 1 members
class NiBSplineCompFloatInterpolator : public NiBSplineFloatInterpolator
{
  public:
    virtual void LoadBinary(NiStream&);

    float m_afCompScalars[2]; // src: XBOX_RETAIL_PDB +0x24 (old: m_afOffsetAndHalfRange)
};
