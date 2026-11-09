#pragma once

#include "CombatAction.h"

struct CombatController;

// pdb: class CombatActionIgnoreBlockedTarget, size 0x2c, bases: CombatAction, 0 members
class CombatActionIgnoreBlockedTarget : public CombatAction
{
public:
    CombatActionIgnoreBlockedTarget(COMBAT_ACTION aeType);

    virtual void vfn_0();

    void Execute_0097ccf0(CombatController* apCombatController, int aiActionValue);
};
