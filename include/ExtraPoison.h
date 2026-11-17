#pragma once

#include "BSExtraData.h"

class AlchemyItem;

// pdb: class ExtraPoison, size 0x10, bases: BSExtraData, 1 members
class ExtraPoison : public BSExtraData
{
public:
    bool IsDifferent(BSExtraData* apCompare);

    AlchemyItem* poison;
};
