#pragma once

#include "BSExtraData.h"

// pdb: class ExtraAnim, size 0x10 (here 0xc), bases: BSExtraData, 1 members
class ExtraAnim : public BSExtraData
{
public:
    virtual ~ExtraAnim();

    ExtraAnim(int aiValue);
};
