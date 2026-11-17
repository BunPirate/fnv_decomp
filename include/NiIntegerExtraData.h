#pragma once

#include "NiExtraData.h"

// pdb: class NiIntegerExtraData, size 0x10, bases: NiExtraData, 1 members
class NiIntegerExtraData : public NiExtraData
{
  public:
    virtual void LoadBinary(NiStream& kStream);

    int m_iValue;
};
