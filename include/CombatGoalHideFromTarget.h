#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalHideFromTarget, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalHideFromTarget : public CombatGoal
{
public:
    CombatGoalHideFromTarget(CombatGoal::COMBAT_GOAL eType);
};
