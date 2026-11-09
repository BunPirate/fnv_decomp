#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackRangedFromCover, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackRangedFromCover : public CombatAction
{
public:
    CombatActionAttackRangedFromCover(COMBAT_ACTION aeType);

    void Execute_0097af70(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b070(CombatController* apCombatController, int aiActionValue);
};
