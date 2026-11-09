#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraAshPileRef, size 0x10, bases: BSExtraData, 1 members
class ExtraAshPileRef : public BSExtraData
{
public:
    ExtraAshPileRef();

    TESObjectREFR* pAshPileRef;
};
