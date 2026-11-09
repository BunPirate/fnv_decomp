#pragma once

#include "NiExtraData.h"

#pragma pack(push, 1)
// pdb: class NiBooleanExtraData, size 0x10 (here 0xd), bases: NiExtraData, 1 members
class NiBooleanExtraData : public NiExtraData
{
  public:
    virtual ~NiBooleanExtraData();

    bool IsEqualTo(NiObject* pObject);

    bool m_bValue;
};
#pragma pack(pop)
