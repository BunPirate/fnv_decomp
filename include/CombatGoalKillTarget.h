#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalKillTarget, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalKillTarget : public CombatGoal
{
public:
    CombatGoalKillTarget(CombatGoal::COMBAT_GOAL eType);
};
