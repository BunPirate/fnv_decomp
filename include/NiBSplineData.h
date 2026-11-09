#pragma once

#include "NiObject.h"

class NiBSplineBasisData;

// pdb: class NiBSplineData, size 0x18, bases: NiObject, 4 members
class NiBSplineData : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& kStream);

    void ReadGroup(NiStream& stream);
    void CalculateSplineValue(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float);

    float* m_pafControlPoints;
    short* m_pasCompactControlPoints;
    unsigned int m_uiControlPointCount;
    unsigned int m_uiCompactControlPointCount;
};
