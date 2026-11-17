#pragma once

#include "BSExtraData.h"

// pdb: class ExtraModdingItem, size 0x10, bases: BSExtraData, 1 members
class ExtraModdingItem : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* extra);

    bool __thiscall IsDifferentFrom(BSExtraData* extra);

    unsigned char unk0C;
    unsigned char unk0D[3];
};
