#pragma once

#include "BSExtraData.h"

// pdb: class ExtraHasNoRumors, size 0x10, bases: BSExtraData, 1 members
class ExtraHasNoRumors : public BSExtraData
{
public:
    char bNoRumors; // src: XBOX_RETAIL_PDB +0xc (old: value)
};
