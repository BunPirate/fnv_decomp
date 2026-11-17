#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalFindTarget, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalFindTarget : public CombatGoal
{
public:
    CombatGoalFindTarget(CombatGoal::COMBAT_GOAL eType);
};
