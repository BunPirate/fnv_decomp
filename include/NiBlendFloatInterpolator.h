#pragma once

#include "NiBlendInterpolator.h"

// pdb: class NiBlendFloatInterpolator, size 0x34, bases: NiBlendInterpolator, 1 members
class NiBlendFloatInterpolator : public NiBlendInterpolator
{
public:
    NiBlendFloatInterpolator(bool bManagerControlled, float fWeightThreshold, unsigned char ucArraySize);

    virtual void LoadBinary(NiStream& kStream);
    virtual bool UpdateFloat(float time, NiObjectNET* target, float& value);

    bool Update(float fTime, NiObjectNET* pkInterpTarget, float& fValue);
    bool UpdateAccumulatedTransform(float fTime, NiObjectNET* pkInterpTarget, float& fValue);
    bool UpdateSingleInterpolator(float fTime, NiObjectNET* pkInterpTarget, float& fValue);

    float m_fFloatValue;
};
