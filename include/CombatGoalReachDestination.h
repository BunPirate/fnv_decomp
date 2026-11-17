#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalReachDestination, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalReachDestination : public CombatGoal
{
public:
    CombatGoalReachDestination(CombatGoal::COMBAT_GOAL eType);
};
