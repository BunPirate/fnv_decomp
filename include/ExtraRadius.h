#pragma once

#include "BSExtraData.h"

// pdb: class ExtraRadius, size 0x10, bases: BSExtraData, 1 members
class ExtraRadius : public BSExtraData
{
public:
    bool Compare(BSExtraData* extra) override;
    bool Compare_00436bd0(BSExtraData* extra);

    ExtraRadius();

    float fRadius;
};
