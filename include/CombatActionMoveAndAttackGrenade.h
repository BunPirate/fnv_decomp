#pragma once

#include "CombatActionAttackGrenade.h"

struct CombatController;

// pdb: class CombatActionMoveAndAttackGrenade, size 0x2c, bases: CombatActionAttackGrenade, 0 members
class CombatActionMoveAndAttackGrenade : public CombatActionAttackGrenade
{
public:
    CombatActionMoveAndAttackGrenade(COMBAT_ACTION aeType);

    void Execute_0097c620(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097c6b0(CombatController* apCombatController, int aiActionValue);
};
