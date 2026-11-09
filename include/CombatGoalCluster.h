#pragma once

#include "CombatGoal.h"

// pdb: class CombatGoalCluster, size 0x1c, bases: CombatGoal, 0 members
class CombatGoalCluster : public CombatGoal
{
public:
    CombatGoalCluster(CombatGoal::COMBAT_GOAL eType);
};
