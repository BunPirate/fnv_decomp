#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalStayInCombatArea, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalStayInCombatArea : public CombatGoal
{
public:
    CombatGoalStayInCombatArea(CombatGoal::COMBAT_GOAL eType);
};
