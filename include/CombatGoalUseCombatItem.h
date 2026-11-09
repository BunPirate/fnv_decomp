#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalUseCombatItem, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalUseCombatItem : public CombatGoal
{
public:
    CombatGoalUseCombatItem(CombatGoal::COMBAT_GOAL eType);
};
