#pragma once

#include "BSExtraData.h"

// pdb: class ExtraRefractionProperty, size 0x10, bases: BSExtraData, 1 members
class ExtraRefractionProperty : public BSExtraData
{
public:
    float fRefractionPower; // src: XBOX_RETAIL_PDB +0xc (old: fRefraction)
};
