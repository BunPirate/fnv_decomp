#pragma once

#include "BSExtraData.h"

namespace extra_save
{
class SForm;
}

// pdb: class ExtraHeadingTarget, size 0x10, bases: BSExtraData, 1 members
class ExtraHeadingTarget : public BSExtraData
{
public:
    virtual ~ExtraHeadingTarget();

    void __thiscall FUN_00435ef0();
    void* __thiscall FUN_0042c960(unsigned int flags);

    extra_save::SForm* pheadingtarget;
};
