#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraEnableStateParent, size 0x14, bases: BSExtraData, 2 members
class ExtraEnableStateParent : public BSExtraData
{
public:
    ExtraEnableStateParent();

    bool Compare(BSExtraData* apCompare) override;
    bool Compare_00433340(BSExtraData* apCompare);

    TESObjectREFR* pParent;
    unsigned char cFlags;
    unsigned char unk11[3];
};
