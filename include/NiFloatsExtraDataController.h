#pragma once

#include "NiExtraDataController.h"
#include "NiFixedString.h"

// pdb: class NiFloatsExtraDataController, size 0x48, bases: NiExtraDataController, 2 members
class NiFloatsExtraDataController : public NiExtraDataController
{
public:
    virtual bool IsEqual(NiObject* pkObject) const;

    void ApplyInterpolatorValue(NiInterpolator* interpolator, unsigned short index);

    int m_iFloatsExtraDataIndex;
    NiFixedString m_kCtlrID;
};
