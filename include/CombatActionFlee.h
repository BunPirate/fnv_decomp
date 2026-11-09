#pragma once

#include "CombatAction.h"

// pdb: class CombatActionFlee, size 0x2c, bases: CombatAction, 0 members
class CombatActionFlee : public CombatAction
{
public:
    CombatActionFlee(COMBAT_ACTION type);
    void Execute_0097cdb0(CombatController* apCombatController, int aiActionValue);
};
