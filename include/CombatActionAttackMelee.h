#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackMelee, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackMelee : public CombatAction
{
public:
    CombatActionAttackMelee(COMBAT_ACTION aeType);

    void AddProcedureToController(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b4a0(CombatController* apCombatController, int aiActionValue);
};
