#pragma once

#include "NiBlendInterpolator.h"
#include "NiQuatTransform.h"

class AccumItem;
class NiObjectNET;

// pdb: class NiBlendAccumTransformInterpolator, size 0x58, bases: NiBlendInterpolator, 3 members
class NiBlendAccumTransformInterpolator : public NiBlendInterpolator
{
public:
    virtual bool vf59(NiQuatTransform* value);

    void ClearAccumulatedTransform();
    void CalculateSingleValue(float fTime, NiObjectNET* pkInterpTarget);
    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);

    NiQuatTransform m_kAccumulatedTransformValue;
    AccumItem* m_pkAccumArray;
    bool m_bReset;
};
