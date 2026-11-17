#pragma once

#include "NiExtraData.h"

// pdb: class NiFloatExtraData, size 0x10, bases: NiExtraData, 1 members
class NiFloatExtraData : public NiExtraData
{
  public:
    void* Destroy(unsigned int flags);

    float m_fValue;
};
