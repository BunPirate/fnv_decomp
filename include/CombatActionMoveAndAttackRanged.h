#pragma once

#include "CombatActionAttackRanged.h"

struct CombatController;

// pdb: class CombatActionMoveAndAttackRanged, size 0x2c, bases: CombatActionAttackRanged, 0 members
class CombatActionMoveAndAttackRanged : public CombatActionAttackRanged
{
public:
    CombatActionMoveAndAttackRanged(COMBAT_ACTION aeType);

    void AddProcedureToController_0097c280(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097c310(CombatController* apCombatController, int aiActionValue);
};
