#pragma once

#include "BSExtraData.h"

// pdb: class ExtraNorthRotation, size 0x10, bases: BSExtraData, 1 members
class ExtraNorthRotation : public BSExtraData
{
public:
    ExtraNorthRotation();

    float fNorthRot; // src: XBOX_RETAIL_PDB +0xc (old: fNorthRotation)
};
