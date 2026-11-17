#pragma once

#include "BSExtraData.h"
struct TESCombatStyle;

// pdb: class ExtraCombatStyle, size 0x10, bases: BSExtraData, 1 members
class ExtraCombatStyle : public BSExtraData
{
public:
    bool Compare(BSExtraData* apCompare) override;
    bool Compare_00437300(BSExtraData* apCompare);

    TESCombatStyle* m_pCombatStyle;
};
