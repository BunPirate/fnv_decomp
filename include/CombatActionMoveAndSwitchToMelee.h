#pragma once

#include "CombatActionMove.h"

// pdb: class CombatActionMoveAndSwitchToMelee, size 0x2c, bases: CombatActionMove, 0 members
class CombatActionMoveAndSwitchToMelee : public CombatActionMove
{
public:
    CombatActionMoveAndSwitchToMelee(COMBAT_ACTION aeType);
    void Execute_0097c090(CombatController* apCombatController, int aiActionValue);
};
