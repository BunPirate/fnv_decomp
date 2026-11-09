#pragma once

#include "BSExtraData.h"

namespace extra_save
{
class SForm;
}

// pdb: class ExtraItemDropper, size 0x10, bases: BSExtraData, 1 members
class ExtraItemDropper : public BSExtraData
{
public:
    extra_save::SForm* pDropper;
};
