#pragma once

#include "ValueModifierEffect.h"

class TESObjectREFR;

// pdb: class ParalysisEffect, size 0x4c, bases: ValueModifierEffect, 0 members
class ParalysisEffect : public ValueModifierEffect
{
public:
    ParalysisEffect(void* apCaster, void* apSpell, void* apEffect);

    virtual ActiveEffect* Copy();
    virtual void Update(float afSecondsElapsed);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual void Start();
    virtual void Finish();

    void ApplyEffect();
    void UpdateParalysisEffect(float afSecondsElapsed);
    void Start_008263c0();
    void Finish_008264b0();
    void FinishInitLoadGame_00826550(Actor* apActor);
    void Revert_00826570(TESObjectREFR* apActor);
};
