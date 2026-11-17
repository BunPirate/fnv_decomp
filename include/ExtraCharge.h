#pragma once

#include "BSExtraData.h"

// pdb: class ExtraCharge, size 0x10, bases: BSExtraData, 1 members
class ExtraCharge : public BSExtraData
{
public:
    bool Compare(BSExtraData* extra) override;

    float m_fCharge;
};
