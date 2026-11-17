#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionSwitchWeapon, size 0x2c, bases: CombatAction, 0 members
class CombatActionSwitchWeapon : public CombatAction
{
public:
    CombatActionSwitchWeapon(COMBAT_ACTION aeType);
    float GetCost_0097c8e0(CombatController* apCombatController, int aiActionValue);
};
