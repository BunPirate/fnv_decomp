#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalAvoidThreats, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalAvoidThreats : public CombatGoal
{
public:
    CombatGoalAvoidThreats(CombatGoal::COMBAT_GOAL eType);
};
