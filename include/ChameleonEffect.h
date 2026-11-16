#pragma once

#include "ValueModifierEffect.h"

// pdb: class ChameleonEffect, size 0x4c, bases: ValueModifierEffect, 0 members
class ChameleonEffect : public ValueModifierEffect
{
public:
    ChameleonEffect(void* apCaster, void* apSpell, void* apEffect);

    virtual ~ChameleonEffect();
    virtual ActiveEffect* Copy();
    virtual void FinishLoadGameTES(Actor* actor);
    virtual void Revert(Actor* apActor);
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
    virtual void Start();
    virtual void Finish();

    void Revert_0080b1b0(Actor* apActor);
    void Revert_0080b310(BGSLoadFormBuffer* apLoadGameBuffer);
    void FinishInitLoadGame_0080b0c0(Actor* apActor);
    void FinishLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void Finish_0080aef0();
    void UpdateChameleonEffect();
    ChameleonEffect* Clone();
    void CopyTo(ChameleonEffect* pkCopy);
};
