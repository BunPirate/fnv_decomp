#pragma once

#include "NiBlendInterpolator.h"

// pdb: class NiBlendTransformInterpolator, size 0x30, bases: NiBlendInterpolator, 0 members
class NiBlendTransformInterpolator : public NiBlendInterpolator
{
  public:
    NiBlendTransformInterpolator() throw();
    virtual ~NiBlendTransformInterpolator() throw();

    virtual bool UpdateTransform(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);

    bool Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    bool UpdateAccumulatedTransform(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    bool UpdateSingleInterpolator(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
    bool StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);

};
