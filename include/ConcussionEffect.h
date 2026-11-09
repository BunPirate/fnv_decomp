#pragma once

#include "ActiveEffect.h"

// pdb: class ConcussionEffect, size 0x4c, bases: ActiveEffect, 1 members
class ConcussionEffect : public ActiveEffect
{
public:
    virtual ActiveEffect* Copy();
    virtual void Update(float afSecondsElapsed);
    virtual bool IsEffectValid(MagicTarget* apTarget);

    float fTimer;

    ConcussionEffect(MagicCaster*, MagicItem*, EffectItem*);
    void CheckApplyConcussion(Actor* apTarget);
};
