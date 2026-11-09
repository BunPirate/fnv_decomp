#pragma once

#include "CombatAction.h"

// pdb: class CombatActionUseCombatItem, size 0x2c, bases: CombatAction, 0 members
class CombatActionUseCombatItem : public CombatAction
{
public:
    CombatActionUseCombatItem(COMBAT_ACTION type);
    void Execute_0097d060(CombatController* apCombatController, int aiActionValue);
};
