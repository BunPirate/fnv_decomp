#pragma once

#include "ActiveEffect.h"

namespace ActorValue
{
    enum Index;
}

// pdb: class ValueModifierEffect, size 0x4c, bases: ActiveEffect, 1 members
class ValueModifierEffect : public ActiveEffect
{
public:
    virtual ~ValueModifierEffect();
    virtual ActiveEffect* Copy();
    virtual void Finalize();
    virtual void Update(float afSecondsElapsed);
    virtual void FinishLoadGameTES(Actor* actor);
    virtual bool CanFinish();
    virtual void CopyData(ActiveEffect* apDestination);
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();
    virtual void Continue();
    virtual void Finish();
    virtual void SetActorValue(ActorValue::Index value);
    virtual ActorValue::Index GetActorValue();
    virtual void ApplyActorValueModifier(Actor* apActor, float afModifier, ActorValue::Index aeOverrideActorValue);

    ActorValue::Index eWhichActorValue; // src: XBOX_RETAIL_PDB +0x48 (old: m_eActorValue)

    ValueModifierEffect(void*, void*, void*);
    float GetModifiedMagnitude(float afMagnitude);
    void ShowAttributeReductionMessage();
    void ApplyEffect();
    MagicTarget* FUN_0059bb30();
    unsigned short __thiscall FUN_00802d90(Actor* apActor);
    void FUN_00802db0(Actor* apActor);
    void FUN_00802dd0(Actor* apActor);
    void LimbConditionEffect_SaveGame(Actor* apActor);
    void __thiscall ValueModifierEffect_FinishInitLoadGame(Actor* apActor);
};
