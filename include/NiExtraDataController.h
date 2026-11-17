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

    NiFixedString m_kExtraDataName; // src: XBOX_RETAIL_PDB +0x38 (old: m_kDataName)
    NiPointer<NiExtraData> m_spExtraData; // src: XBOX_RETAIL_PDB +0x3c (old: m_pExtraData)
};
