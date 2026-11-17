#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalAmbush, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalAmbush : public CombatGoal
{
public:
    CombatGoalAmbush(CombatGoal::COMBAT_GOAL eType);
};
