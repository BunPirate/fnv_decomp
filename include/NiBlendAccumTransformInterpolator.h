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

    NiQuatTransform m_kAccumulatedTransformValue; // src: XBOX_RETAIL_PDB +0x30 (old: m_kAccumulatedTransform)
    AccumItem* m_pkAccumArray; // src: XBOX_RETAIL_PDB +0x50 (old: m_pAccumulationData)
    bool m_bReset; // src: XBOX_RETAIL_PDB +0x54 (old: m_bHasAccumulation)
};
