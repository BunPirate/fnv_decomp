#pragma once

#include "NiBSplineInterpolator.h"
#include "NiColor.h"

// pdb: class NiBSplinePoint3Interpolator, size 0x2c, bases: NiBSplineInterpolator, 2 members
class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
{
public:
    virtual void LoadBinary(NiStream& kStream);

    NiColor m_kPoint3Value;
    unsigned int m_kPoint3CPHandle;
};
