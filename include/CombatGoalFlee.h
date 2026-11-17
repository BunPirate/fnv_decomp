#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalFlee, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalFlee : public CombatGoal
{
public:
    CombatGoalFlee(CombatGoal::COMBAT_GOAL eType);
};
