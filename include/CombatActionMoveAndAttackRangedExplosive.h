#pragma once

#include "CombatActionAttackRangedExplosive.h"

struct CombatController;
struct CombatWorldStateArray;

// pdb: class CombatActionMoveAndAttackRangedExplosive, size 0x2c, bases: CombatActionAttackRangedExplosive, 0 members
class CombatActionMoveAndAttackRangedExplosive : public CombatActionAttackRangedExplosive
{
public:
    CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION aeType);

    void FUN_0097c470();
    bool CombatActionMove_CanExecute(CombatController* apCombatController, CombatWorldStateArray* apWorldStateArray, int aiActionValue);
    float GetCost_0097c4d0(CombatController* apCombatController, int aiActionValue);
    void CombatActionActivateCombatItem_GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};
