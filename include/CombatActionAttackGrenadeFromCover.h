#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackGrenadeFromCover, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackGrenadeFromCover : public CombatAction
{
public:
    CombatActionAttackGrenadeFromCover(COMBAT_ACTION aeType);

    void Execute_0097bab0(CombatController* apCombatController, int aiActionValue);
    float CombatActionAttackGrenade_GetCost(CombatController* apCombatController, int aiActionValue);
};
