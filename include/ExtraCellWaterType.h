#pragma once

#include "BSExtraData.h"
#include "TESWaterForm.h"

// pdb: class ExtraCellWaterType, size 0x10, bases: BSExtraData, 1 members
class ExtraCellWaterType : public BSExtraData
{
public:
    ExtraCellWaterType();

    TESWaterForm* pWater;
};
