#pragma once

#include "CombatGroupStrategy.h"

// pdb: class CombatGroupStrategyAmbush, size 0x8, bases: CombatGroupStrategy, 0 members
class CombatGroupStrategyAmbush : public CombatGroupStrategy
{
public:
    virtual bool CanFlank(MarkerStruct* apGroup, ActorCombatGroup* apGroupData) override;
    virtual void __thiscall vf01(ActorCombatGroup* apGroup, MarkerStruct* apGroupData) override;
    virtual bool __thiscall vf02(ActorCombatGroup* apGroup) override;
};
