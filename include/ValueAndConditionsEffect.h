#pragma once

#include "ValueModifierEffect.h"

// pdb: class ValueAndConditionsEffect, size 0x50, bases: ValueModifierEffect, 1 members
class ValueAndConditionsEffect : public ValueModifierEffect
{
public:
    ValueAndConditionsEffect(void*, void*, void*);

    virtual ActiveEffect* Copy() override;
    virtual void CopyData(ActiveEffect* apDestination) override;
    virtual void ApplyActorValueModifier(Actor* apActor, float afModifier, ActorValue::Index aeOverrideActorValue) override;

    ActorValue::Index eTargetBodyPart; // src: XBOX_RETAIL_PDB +0x4c (old: m_eModifiedActorValue)

    void LoadGame(void* apActor);
};
