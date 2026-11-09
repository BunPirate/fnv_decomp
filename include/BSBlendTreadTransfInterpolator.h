#pragma once

#include "NiBlendInterpolator.h"

// pdb: class BSBlendTreadTransfInterpolator, size 0x34, bases: NiBlendInterpolator, 1 members
class BSBlendTreadTransfInterpolator : public NiBlendInterpolator
{
  public:
    virtual bool UpdateTransform(float, NiObjectNET*, NiQuatTransform&);
    virtual NiObject* MakeClone(CloningProcess&);

    bool Update(float, NiObjectNET*, NiQuatTransform&);
    bool UpdateSingleInterpolator(float, NiObjectNET*, NiQuatTransform&);
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);

    float fCurrLerp;
};
