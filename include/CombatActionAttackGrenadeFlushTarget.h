#pragma once

#include "CombatAction.h"

class CombatController;
struct CombatWorldStateArray;

// pdb: class CombatActionAttackGrenadeFlushTarget, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackGrenadeFlushTarget : public CombatAction
{
public:
    CombatActionAttackGrenadeFlushTarget(COMBAT_ACTION aeType);

    bool CanExecute_0097b840(CombatController* apCombatController, CombatWorldStateArray* apWorldStateArray, int aiActionValue);
    void Execute_0097b880(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b980(CombatController* apCombatController, int aiActionValue);
};
