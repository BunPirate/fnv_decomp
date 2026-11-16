#pragma once

#include "ValueModifierEffect.h"
#include "NiAVObject.h"

// pdb: class AbsorbEffect, size 0x5c, bases: ValueModifierEffect, 4 members
class AbsorbEffect : public ValueModifierEffect
{
public:
    virtual ~AbsorbEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float afSecondsElapsed);
    virtual void FinishLoadGameTES(Actor* actor);
    virtual bool CanApply(MagicCaster* apCaster);
    virtual void CopyData(ActiveEffect* other);
    virtual void Start();
    virtual void Finish();

    NiPointer<NiAVObject> spBoltNode; // src: XBOX_RETAIL_PDB +0x4c (old: spBolt)
    NiPointer<NiAVObject> spSource; // src: XBOX_RETAIL_PDB +0x50 (old: spNode50)
    NiPointer<NiAVObject> spTarget; // src: XBOX_RETAIL_PDB +0x54 (old: spNode54)
    NiPointer<NiAVObject> spBoltProperty; // src: XBOX_RETAIL_PDB +0x58 (old: m_spTargetObject)

    AbsorbEffect(MagicCaster* caster, MagicItem* apSpell, EffectItem* effect);
    void __thiscall Start3D();
    void __thiscall FinishInitLoadGame(Actor* apActor);
    void CopyData_0082a650(ActiveEffect* apDestination);
    void FUN_00802e20();
    void* __thiscall Destroy(unsigned int flags);
    void Update3D_00803b70(float value);
};
