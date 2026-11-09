#pragma once

#include "NiExtraData.h"
#include "NiColorA.h"

// pdb: class NiColorExtraData, size 0x1c, bases: NiExtraData, 1 members
class NiColorExtraData : public NiExtraData
{
  public:
    virtual void SaveBinary(NiStream& kStream);

    void SaveBinary_00a893d0(NiStream& kStream);
    void SetColor(NiColorA kColor);

    NiColorA m_kColorA;
};
