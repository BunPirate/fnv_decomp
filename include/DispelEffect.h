#pragma once

#include "ActiveEffect.h"

// pdb: class DispelEffect, size 0x48, bases: ActiveEffect, 0 members
class DispelEffect : public ActiveEffect
{
public:
    DispelEffect(MagicCaster*, MagicItem*, EffectItem*);

    virtual ActiveEffect* Copy() override;
    virtual void CopyData(ActiveEffect* apDestination) override;
    virtual bool IsEffectValid(MagicTarget* apTarget) override;
    virtual void Start() override;
};
