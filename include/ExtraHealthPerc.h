#pragma once

#include "BSExtraData.h"

// pdb: class ExtraHealthPerc, size 0x10, bases: BSExtraData, 1 members
class ExtraHealthPerc : public BSExtraData
{
public:
    ExtraHealthPerc();
    bool Compare(BSExtraData* extra) override;
    bool Compare_00431db0(BSExtraData* extra);

    float m_fHealthPercentage;
};
