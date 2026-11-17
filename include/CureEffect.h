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

    int eSpellType; // src: XBOX_RETAIL_PDB +0x48 (old: m_eSpellType)
    int eArchetypeID; // src: XBOX_RETAIL_PDB +0x4c (old: m_iCureType)
};
