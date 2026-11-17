#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackHandToHand, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackHandToHand : public CombatAction
{
public:
    CombatActionAttackHandToHand(COMBAT_ACTION aeType);

    float GetCost_0097b5a0(CombatController* apCombatController, int aiActionValue);
};
