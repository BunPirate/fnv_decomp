#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackGrenade, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackGrenade : public CombatAction
{
public:
    CombatActionAttackGrenade(COMBAT_ACTION aeType);

    void Execute_0097b6d0(CombatController* apCombatController, int aiActionValue);
};
