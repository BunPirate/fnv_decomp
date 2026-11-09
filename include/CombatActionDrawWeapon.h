#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionDrawWeapon, size 0x2c, bases: CombatAction, 0 members
class CombatActionDrawWeapon : public CombatAction
{
public:
    CombatActionDrawWeapon(COMBAT_ACTION aeType);

    void AddProcedureToController_0097c790(CombatController* apCombatController, int aiActionValue);
    void GetDebugText_0097c990(char* apDebugText, unsigned int aiMaxLength, int aiActionValue);
};
