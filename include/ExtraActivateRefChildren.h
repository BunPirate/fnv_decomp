#pragma once

#include "BSExtraData.h"
#include "SL.h"

// pdb: class ExtraActivateRefChildren, size 0x18, bases: BSExtraData, 2 members
class ExtraActivateRefChildren : public BSExtraData
{
public:
    virtual ~ExtraActivateRefChildren();

    ExtraActivateRefChildren();

    void __thiscall FUN_00433830();
    void* __thiscall FUN_00433800(unsigned int flags);

    SL ChildList; // src: XBOX_RETAIL_PDB +0xc (old: m)
    float f;
};
