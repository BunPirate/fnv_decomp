#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalActivateCombatItem, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalActivateCombatItem : public CombatGoal
{
public:
    CombatGoalActivateCombatItem(CombatGoal::COMBAT_GOAL eType);
};
