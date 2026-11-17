#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionSearch, size 0x2c, bases: CombatAction, 0 members
class CombatActionSearch : public CombatAction
{
public:
    CombatActionSearch(COMBAT_ACTION aeType);

    void Execute_0097caf0(CombatController* apCombatController, int aiActionValue);
};
