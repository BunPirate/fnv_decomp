#pragma once

#include "ActiveEffect.h"
#include "NiPointLight.h"

// pdb: class LightEffect, size 0x4c, bases: ActiveEffect, 1 members
class LightEffect : public ActiveEffect
{
public:
    LightEffect(void* apCaster, void* apSpell, void* apEffect);

    virtual ~LightEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual void FinishLoadGameTES(Actor* apActor);
    virtual void Revert(Actor* apActor);
    virtual void Revert(BGSLoadFormBuffer* apBuffer);
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
    virtual void CopyData(ActiveEffect* apDestination);
    virtual void Start();
    virtual void Finish();

    float GetFloatAtOffset1C();
    void AttachLight();
    void FUN_0080f030(Actor* apActor);
    void DetachLight();

    NiPointer<NiPointLight> spPointLight; // src: XBOX_RETAIL_PDB +0x48 (old: m_spLight)
};
