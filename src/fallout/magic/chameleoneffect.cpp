
// src/fallout/magic/chameleoneffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/chameleoneffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/Actor.h"
#include "../../../include/ChameleonEffect.h"
#include "../../../include/TESForm.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/MagicTarget.h"

// Constructs the ValueModifierEffect base and installs the ChameleonEffect vtable.
// @fnv 0x0080acf0
// pdb: ChameleonEffect::ChameleonEffect | ChameleonEffect.obj | debug, upstream name already matches, high
// pdb params: apCaster, apSpell, apEffect
ChameleonEffect::ChameleonEffect(void* apCaster, void* apSpell, void* apEffect) : ValueModifierEffect(apCaster, apSpell, apEffect)
{
}

bool __cdecl BSShaderManager_IsRefractionEnabled();
// @fnv 0x0080b1b0
// src: XBOX_PDB 0x0080b1b0
// pdb: ChameleonEffect::Revert | ChameleonEffect.obj | retail, vtable slot, high
// pdb params: apActor
void ChameleonEffect::Revert_0080b1b0(Actor* apActor)
{
    reinterpret_cast<TESForm*>(this)->TESForm::Revert((unsigned int)apActor);
    if (BSShaderManager_IsRefractionEnabled())
        apActor->Unk_E1(1, 0.0F);
    else
        apActor->UpdateActorPresentation();
}

// @fnv 0x0080b310
// src: XBOX_PDB 0x0080b310
// pdb: ChameleonEffect::Revert | ChameleonEffect.obj | retail, vtable slot, high
// pdb params: apActor
void ChameleonEffect::Revert_0080b310(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Actor* actor = apLoadGameBuffer->GetActor();
    reinterpret_cast<TESForm*>(this)->TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (BSShaderManager_IsRefractionEnabled())
        actor->Unk_E1(1, 0.0f);
    else
        actor->UpdateActorPresentation();
}

// Allocates and constructs a ChameleonEffect from three arguments and returns it.
// @fnv 0x0080b040
// src: COMMUNITY 0x0080b040
ChameleonEffect* __cdecl ChameleonEffect_Create(void* a, void* b, void* c)
{
    return new ChameleonEffect(a, b, c);
}

extern double DAT_01017a40;

float __cdecl BSMAX_00404010(float a, float b);
float __cdecl BSMIN(float a, float b);
float __cdecl MagicSystem_GetChameleonMaxRefraction();
float __cdecl GetOriginalRuntimeFloatSetting9();
float __cdecl LinearInterpolate(float a, float b, float c, float d, float e);

// @fnv 0x0080b0c0
// src: XBOX_PDB 0x0080b0c0
// pdb: ChameleonEffect::FinishInitLoadGame | ChameleonEffect.obj | retail, vtable slot, high
// pdb params: apActor
// pdb locals: fRefractionPower, fChameleon
void ChameleonEffect::FinishInitLoadGame_0080b0c0(Actor* apActor)
{
    ValueModifierEffect::FinishLoadGameTES(apActor);
    if (BSShaderManager_IsRefractionEnabled())
    {
        apActor->SetAlpha(1.0f);
        float h;
        float s;
        h = BSMIN(1.0f, BSMAX_00404010(0.0f, (float)(apActor->GetCurrentActorValue(static_cast<ActorValue::Index>(eWhichActorValue)) / DAT_01017a40)));
        s = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), MagicSystem_GetChameleonMaxRefraction(), 0.0f, 1.0f, 1.0f - h);
        apActor->Unk_E1(1, s);
    }
    else
    {
        apActor->FUN_008c4640();
    }
}

// @fnv 0x0080b200
// src: XBOX_PDB 0x0080b200
// pdb: ChameleonEffect::FinishLoadGame | ChameleonEffect.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
// pdb locals: pactor, fRefractionPower, fChameleon
void ChameleonEffect::FinishLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Actor* actor = apLoadGameBuffer->GetActor();
    ActiveEffect::ApplyLoadBuffer(apLoadGameBuffer);
    if (bActive)
    {
        if (BSShaderManager_IsRefractionEnabled())
        {
            actor->SetAlpha(1.0f);
            float clamped =
                BSMIN(1.0f, BSMAX_00404010(0.0f, (float)(actor->GetCurrentActorValue(static_cast<ActorValue::Index>(eWhichActorValue)) / 100.0)));
            float alpha4 = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), MagicSystem_GetChameleonMaxRefraction(), 0.0f, 1.0f,
                                             (float)(1.0 - clamped));
            actor->Unk_E1(1, alpha4);
        }
        else
        {
            actor->UpdateActorPresentation();
        }
    }
}

extern double DAT_01012060;

// @fnv 0x0080aef0
// src: XBOX_PDB 0x0080aef0
// pdb: ChameleonEffect::Finish | ChameleonEffect.obj | retail, vtable slot, high
// pdb locals: ptargetActor, fchameleonValue, fRefractionPower
void ChameleonEffect::Finish_0080aef0()
{
    Actor* actor;
    float ratio3;
    float interp2;

    ApplyEffect();
    actor = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->FUN_00822b40() : (Actor*)0;
    if (actor != 0)
    {
        if (BSShaderManager_IsRefractionEnabled())
        {
            ratio3 = BSMIN(1.0f, BSMAX_00404010(0.0f, actor->GetCurrentActorValue(static_cast<ActorValue::Index>(eWhichActorValue)) / DAT_01017a40));
            if (ratio3 > DAT_01012060)
            {
                interp2 = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), MagicSystem_GetChameleonMaxRefraction(), 0.0f, 1.0f,
                                            1.0f - ratio3 / DAT_01017a40);
                actor->Unk_E1(1, interp2);
            }
            else
            {
                actor->Unk_E1(1, 0.0f);
                actor->FUN_008c4640();
            }
        }
        else
        {
            actor->FUN_008c4640();
        }
    }
}

// @fnv 0x0080add0
// pdb: ChameleonEffect::Start | ChameleonEffect.obj | retail, vtable slot, high
// pdb locals: ptargetActor, fRefractionPower, fChameleon
void ChameleonEffect::UpdateChameleonEffect()
{
    Actor* q = ActiveEffect::FUN_0059bb30() ? ActiveEffect::FUN_0059bb30()->FUN_00822b40() : 0;
    ValueModifierEffect::Start();
    if (q != 0)
    {
        if (BSShaderManager_IsRefractionEnabled())
        {
            q->SetAlpha(1.0f);
            float r2 = BSMIN(1.0f, BSMAX_00404010(0.0f, q->GetCurrentActorValue(static_cast<ActorValue::Index>(eWhichActorValue)) / DAT_01017a40));
            float r3 = LinearInterpolate(GetOriginalRuntimeFloatSetting9(), MagicSystem_GetChameleonMaxRefraction(), 0.0f, 1.0f, 1.0f - r2);
            q->Unk_E1(1, r3);
        }
        else
        {
            q->FUN_008c4640();
        }
    }
}

// Allocates a ChameleonEffect, copies its state, and returns the new object.
// @fnv 0x0080ad20
// pdb: ChameleonEffect::Copy | ChameleonEffect.obj | retail, vtable slot, high
// pdb locals: presult
ChameleonEffect* ChameleonEffect::Clone()
{
    ChameleonEffect* pkCopy = new ChameleonEffect(m_pEffectInstance, pSpell, pEffect);
    CopyData(pkCopy);
    return pkCopy;
}
