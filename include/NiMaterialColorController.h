#pragma once

#include "NiPoint3InterpController.h"

// pdb: class NiMaterialColorController, size 0x3c (here 0xb8), bases: NiPoint3InterpController, 1 members
class NiMaterialColorController : public NiPoint3InterpController
{
public:
    virtual bool IsEqual(NiObject* object) const;

    NiMaterialColorController* Clone(CloningProcess& process);
    const char* GetChannelName();
    NiMaterialColorController* Destroy(int flags);

    unsigned short m_uiObjectFlags;
    unsigned char unk3A[0x7E];
};
