#pragma once

#include "CombatAction.h"

// pdb: class CombatActionActivateCombatItem, size 0x2c, bases: CombatAction, 0 members
class CombatActionActivateCombatItem : public CombatAction
{
public:
    CombatActionActivateCombatItem(COMBAT_ACTION type);
    void Execute_0097cf10(CombatController* apCombatController, int aiActionValue);
};
