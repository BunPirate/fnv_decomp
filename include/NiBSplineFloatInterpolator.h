#pragma once

#include "NiBSplineInterpolator.h"

// pdb: class NiBSplineFloatInterpolator, size 0x24, bases: NiBSplineInterpolator, 2 members
class NiBSplineFloatInterpolator : public NiBSplineInterpolator
{
  public:
    virtual void LoadBinary(NiStream& kStream);

    float m_fFloatValue;
    unsigned int m_kFloatCPHandle;
};
