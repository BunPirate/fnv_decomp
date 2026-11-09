// fallout/magic/concussioneffect.cpp: ConcussionEffect (7 functions)

#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorMover.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/ConcussionEffect.h"
#include "../../../include/ImageSpaceModifierInstanceForm.h"
#include "../../../include/MagicProjectile.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESImageSpaceModifier.h"
#include "concussioneffect_decls.h"
#include "../../../include/TESForm.h"

const char kConcussionFXCrippleHead[] = "FXCrippleHead";

// @fnv 0x0080bd60
// pdb: ConcussionEffect::CheckTarget | ConcussionEffect.obj | retail, vtable slot, high
// pdb params: apTarget
// pdb locals: pactor
bool ConcussionEffect::IsEffectValid(MagicTarget* apTarget)
{
    Actor* actor = apTarget ? apTarget->GetOwnerActor() : 0;
    if (actor)
    {
        if (!actor->HasHealth(false) && !actor->GetIsDying())
            return true;
    }
    return false;
}

// @fnv 0x0080bdd0
// pdb: ConcussionEffect::Update | ConcussionEffect.obj | retail, upstream name already matches, high
// pdb params: afSecondsElapsed
// pdb locals: ptarget
void ConcussionEffect::Update(float afSecondsElapsed)
{
    ((MagicProjectile*)this)->Process(afSecondsElapsed);
    fTimer += afSecondsElapsed;
    Actor* actor = GetTarget() ? GetTarget()->GetOwnerActor() : 0;
    if (actor)
        CheckApplyConcussion(actor);
}

// @fnv 0x0080bcb0
// pdb: ConcussionEffect::Copy | ConcussionEffect.obj | retail, upstream name already matches, high
// pdb locals: presult
ActiveEffect* ConcussionEffect::Copy()
{
    ConcussionEffect* copy = new ConcussionEffect(m_pEffectInstance, pSpell, pEffect);
    copy->fTimer = fTimer;
    CopyData(copy);
    return copy;
}

// @fnv 0x0080be40
// src: XBOX_RETAIL_PDB 0x0080be40
// pdb: ConcussionEffect::CheckApplyConcussion | ConcussionEffect.obj | retail, string-set bridge, high
// pdb params: apTarget
void ConcussionEffect::CheckApplyConcussion(Actor* apTarget)
{
    if (fTimer > DAT_011d1ba4.Float()->f)
    {
        fTimer = 0.0f;
        if (apTarget->Actor_GetPerceptionCondition() == 0.0)
        {
            if (!apTarget->GetActorValue(static_cast<ActorValue::Index>(0x48)))
            {
                DAT_011dbe50 = true;
                if (apTarget->IsPlayerRef() && !g_thePlayer->IsSleepingOrResting())
                {
                    ImageSpaceModifierInstanceForm::Trigger(TESImageSpaceModifier::GetConcussionModifier(),
                                                            DAT_011cf834.Float()->f, 0);
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID(kConcussionFXCrippleHead, 0x101).Play(false);
                }
                apTarget->GetProcess()->StartIdleAnimation(apTarget, 0, static_cast<ANIM_IDLE_PLAY_TYPE>(2), true, false, true);
                DAT_011dbe50 = false;
            }
        }
    }
}

// @fnv 0x0080bc70
// pdb: ConcussionEffect::ConcussionEffect | ConcussionEffect.obj | debug, upstream name already matches, high
// pdb params: apCaster, apSpell, apEffect
ConcussionEffect::ConcussionEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect)
    : ActiveEffect(apCaster, apSpell, apEffect)
{
    fTimer = 0.0f;
}

TESForm* __cdecl GetFormByID(unsigned int);
extern unsigned char DAT_0118abb1;
extern TESImageSpaceModifier* DAT_011c9704;

// @fnv 0x0080bfa0
TESImageSpaceModifier* TESImageSpaceModifier::GetConcussionModifier()
{
    if (!DAT_0118abb1)
        return 0;
    if (!DAT_011c9704)
        DAT_011c9704 = dynamic_cast<TESImageSpaceModifier*>(GetFormByID(0x164));
    return DAT_011c9704;
}

struct FUN_0052d240_shell
{
    void FUN_00483710();
    void BGSStaticCollection_ClearData();
};
// @fnv 0x0052d240
// src: COMMUNITY 0x0052d240
// pdb: BGSStaticCollection::ClearData | BGSStaticCollection.obj | debug, upstream name already matches, high
void FUN_0052d240_shell::BGSStaticCollection_ClearData()
{
    FUN_00483710();
}
