#pragma once

#include "BSExtraData.h"

// pdb: class ExtraScale, size 0x10, bases: BSExtraData, 1 members
class ExtraScale : public BSExtraData
{
public:
    bool Compare(BSExtraData* apCompare) override;

    float fScale;
};
