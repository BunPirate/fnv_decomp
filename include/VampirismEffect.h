#pragma once

#include "ActiveEffect.h"

// pdb: class VampirismEffect, size 0x48, bases: ActiveEffect, 0 members
class VampirismEffect : public ActiveEffect
{
public:
    VampirismEffect(MagicCaster*, MagicItem*, EffectItem*);
    virtual ActiveEffect* Copy() override;
    virtual void InitLoadGame(Actor* apActor) override;
};
