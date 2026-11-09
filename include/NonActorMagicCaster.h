#pragma once

#include "BSExtraData.h"
#include "MagicCaster.h"

// pdb: class NonActorMagicCaster, size 0x24 (here 0x18), bases: BSExtraData, MagicCaster, 3 members
class NonActorMagicCaster : public BSExtraData, public MagicCaster
{
public:
    void SetSelectedMagicItem(MagicItem* spell);
};
