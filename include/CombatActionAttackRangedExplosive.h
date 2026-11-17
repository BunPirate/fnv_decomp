#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionAttackRangedExplosive, size 0x2c, bases: CombatAction, 0 members
class CombatActionAttackRangedExplosive : public CombatAction
{
public:
    CombatActionAttackRangedExplosive(COMBAT_ACTION aeType);

    void CombatActionAttackRanged_AddProcedureToController(CombatController* apCombatController, int aiActionValue);
    float GetCost_0097b240(CombatController* apCombatController, int aiActionValue);

    static void __cdecl Execute(int, CombatAction*);
};
