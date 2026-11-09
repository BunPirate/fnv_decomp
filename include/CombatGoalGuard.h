#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalGuard, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalGuard : public CombatGoal
{
public:
    CombatGoalGuard(CombatGoal::COMBAT_GOAL eType);
};
