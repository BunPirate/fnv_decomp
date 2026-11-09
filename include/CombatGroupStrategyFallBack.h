#pragma once

#include "CombatGroupStrategy.h"

// pdb: class CombatGroupStrategyFallBack, size 0x8, bases: CombatGroupStrategy, 0 members
class CombatGroupStrategyFallBack : public CombatGroupStrategy
{
public:
    bool CanFlank(MarkerStruct* apGroupData, ActorCombatGroup* apGroup) override;
    void __thiscall vf01(ActorCombatGroup* apGroup, MarkerStruct* apGroupData) override;
    bool __thiscall vf02(ActorCombatGroup* apGroup) override;
};
