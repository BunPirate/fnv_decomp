#pragma once

#include "NiSingleInterpController.h"
#include "NiFixedString.h"
#include "NiExtraData.h"

// pdb: class NiExtraDataController, size 0x40, bases: NiSingleInterpController, 2 members
class NiExtraDataController : public NiSingleInterpController
{
public:
    virtual bool IsEqual(NiObject* object) const;

    void PostLinkObject_00a57400(NiStream& kStream);

    NiFixedString m_kExtraDataName;
    NiPointer<NiExtraData> m_spExtraData;
};
