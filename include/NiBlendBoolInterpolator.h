#pragma once

#include "NiBlendInterpolator.h"

class NiBoolInterpolator;

// pdb: class NiBlendBoolInterpolator, size 0x34, bases: NiBlendInterpolator, 1 members
class NiBlendBoolInterpolator : public NiBlendInterpolator
{
public:
    NiBlendBoolInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);

    virtual void LoadBinary(NiStream& kStream);
    virtual bool UpdateBool(float time, NiObjectNET* target, bool& value);

    bool Update(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);
    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, bool& bValue);
    bool BlendValues(float time, NiObjectNET* target, bool& value);
    unsigned char FindHighestWeightIndex();
    NiBoolInterpolator* GetValueForIndex(unsigned char index);

    unsigned char m_bBoolValue;
    unsigned char layoutPadding31[3];
};
