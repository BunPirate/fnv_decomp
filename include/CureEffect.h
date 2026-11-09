#pragma once

#include "ActiveEffect.h"

// pdb: class CureEffect, size 0x50, bases: ActiveEffect, 2 members
class CureEffect : public ActiveEffect
{
public:
    virtual ~CureEffect();
    virtual ActiveEffect* Copy();
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();

    int eSpellType;
    int eArchetypeID;
};
