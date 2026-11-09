#pragma once

#include "BSExtraData.h"

class RegionList;

// pdb: class ExtraRegionList, size 0x10, bases: BSExtraData, 1 members
class ExtraRegionList : public BSExtraData
{
public:
    ExtraRegionList(RegionList* value);

    RegionList* pList;
};
