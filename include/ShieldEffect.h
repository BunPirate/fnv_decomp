#pragma once

#include "ValueModifierEffect.h"

// pdb: class ShieldEffect, size 0x50, bases: ValueModifierEffect, 1 members
class ShieldEffect : public ValueModifierEffect
{
public:
    virtual ActiveEffect* Copy() override;
    virtual void Update(float afSecondsElapsed) override;
    virtual unsigned short GetSaveSize(Actor* actor) override;
    virtual void SaveGame(Actor* apActor) override;
    virtual void LoadGame(Actor* apActor) override;
    virtual void CopyData(ActiveEffect* other) override;
    virtual void Start() override;
    virtual void Finish() override;

    unsigned int eAdditionalActorValue;

    ShieldEffect(void*, void*, void*);
    void ApplyActorValueModifier(Actor* actor, float magnitude);
};
