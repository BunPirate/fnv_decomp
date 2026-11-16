#pragma once

#include "ValueModifierEffect.h"

// pdb: class CalmEffect, size 0x4c, bases: ValueModifierEffect, 0 members
class CalmEffect : public ValueModifierEffect
{
public:
    CalmEffect(void*, void*, void*);

    virtual ActiveEffect* Copy();
    virtual void Update(float afSecondsElapsed);
    virtual bool IsEffectValid(MagicTarget* target);
    virtual void Start();
    virtual void Finish();

    CalmEffect* Copy_0080a930();
    bool CheckTarget_0080a9e0(MagicCaster* apTarget);
    void Start_0080aa90();
    void Update_0080ab10(float afSecondsElapsed);
    void Finish_0080abf0();
    bool __thiscall AbsorbEffect_CheckDeletedCaster(MagicCaster*);
    bool __thiscall ClearCasterIfMatch(MagicCaster*);
};
