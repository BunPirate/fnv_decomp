#pragma once

#include "BSExtraData.h"

// pdb: class ExtraWeaponModFlags, size 0x10, bases: BSExtraData, 1 members
class ExtraWeaponModFlags : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* extra);

    bool IsModActive(unsigned char acSlot);
    bool Compare_00432140(BSExtraData* extra);

    unsigned char m_ucWeaponModFlags;
    unsigned char unk0D[3];
};
