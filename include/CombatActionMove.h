#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionMove, size 0x2c, bases: CombatAction, 0 members
class CombatActionMove : public CombatAction
{
public:
    CombatActionMove(COMBAT_ACTION aeType);

    bool CheckIdentical(CombatController* apCombatController, int aiActionValue);
    void Execute_0097bca0(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097bcc0(CombatController* apCombatController, int aiActionValue);
};
