#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalFallBack, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalFallBack : public CombatGoal
{
public:
    CombatGoalFallBack(CombatGoal::COMBAT_GOAL eType);
};
