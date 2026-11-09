#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackRanged, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackRanged : public CombatAction
{
public:
    CombatActionAttackRanged(COMBAT_ACTION aeType);

    float GetCost_0097ae00(CombatController* apCombatController, int aiActionValue);
};
