// fallout/ai/highprocess.h: definitions for shared HighProcess declarations
#ifndef FNV_LUNA_HIGH_PROCESS_H
#define FNV_LUNA_HIGH_PROCESS_H

#include "../../../include/BaseProcess.h"
#include "../../../include/HighProcess.h"
#include "highprocess_packet_decls.h"

// @fnv 0x008d9090
float HighProcess::GetProcessBlendAmount() const
{
    return fAwarePlayerTimer;
}

// @fnv 0x004727d0
unsigned int HighProcess::GetPostAnimationAction() const
{
    return ePostAnimActon;
}

// @fnv 0x0051f510
MobileObject* HighProcess::GetMobileObject() const
{
    return pDialogTarget;
}

// @fnv 0x008d94b0
float HighProcess::GetProcessBlendWeight() const
{
    return fLightLevel;
}

// @fnv 0x008d9530
bool HighProcess::IsDetectionEnabled() const
{
    return bDialoguewithPlayer;
}

// @fnv 0x006214b0
TESIdleForm* HighProcess::GetSelectedIdleForm() const
{
    return pIdleToPlay;
}

// @fnv 0x008d9610
BaseProcess::FadeState HighProcess::GetCurrentFadeState() const
{
    return (BaseProcess::FadeState)eFadeState;
}

// @fnv 0x008d96b0
void HighProcess::ClearPostAnimActions()
{
    ePostAnimActon = BaseProcess::POSTANIM_ACTION_NONE;
}

// @fnv 0x008d9300
NiObjectNET* HighProcess::GetMuzzleFlash() const
{
    return (NiObjectNET*)pCurrentMuzzleFlash;
}

// @fnv 0x008d94f0
float HighProcess::GetLightLevel(void)
{
    return fLightLevelTimer;
}

// @fnv 0x008d94d0
void HighProcess::SetLightLevel(float value)
{
    fLightLevel = value;
}

// @fnv 0x008d9510
void HighProcess::SetFloatProperty(float value)
{
    fLightLevelTimer = value;
}

// @fnv 0x008d95b0
float HighProcess::GetCurrentAlpha() const
{
    return fDetectionModifierTimer;
}

// @fnv 0x008d9010
float HighProcess::GetRadiationRate() const
{
    return fIdleTimer;
}

// @fnv 0x008d9030
void HighProcess::SetRadiationRate(float value)
{
    fIdleTimer = value;
}

// @fnv 0x008d91e0
bool HighProcess::IsProcessStateActive() const
{
    return bCurrentlyReanimating;
}

// @fnv 0x008d97a0
float HighProcess::GetControllerPhase() const
{
    return fHighestRadiation > fRadiationDelta ? fHighestRadiation : fRadiationDelta;
}

// @fnv 0x008d90e0
void HighProcess::UpdateActorLighting(float value)
{
    fBreathTimer = value;
}

// @fnv 0x008d8da0
bool HighProcess::IsAsleep() const
{
    return bIsDoingSayTo;
}

// @fnv 0x008d93f0
double HighProcess::GetDetectionStrength(void)
{
    return fDetectionTimer;
}

// @fnv 0x008d9650
bool HighProcess::IsCurrentlyDetected() const
{
    return bNeedTalkPlayer;
}

// @fnv 0x008d8f10
bool HighProcess::IsDetecting() const
{
    return bGreetingFlag;
}

// @fnv 0x008d9050
bool HighProcess::HasAssignedAnimation() const
{
    return bContinuingPackageforPC;
}

// @fnv 0x008d9180
bool HighProcess::IsMovementStopped(void)
{
    return bStop;
}

// @fnv 0x008d9740
float HighProcess::GetDetectionProgress() const
{
    return fHeadTrackTargetTimer;
}

// @fnv 0x008d9760
void HighProcess::SetDetectionLevel(float value)
{
    fHeadTrackTargetTimer = value;
}

// @fnv 0x008d8de0
DIALOGUE_EMOTION HighProcess::GetCurrentDialogueEmotion() const
{
    return eLastSpeakingEmotion;
}

// @fnv 0x008d9720
bool HighProcess::GetPlantedExplosive() const
{
    return bPlantedExplosive;
}

// @fnv 0x008d9100
float HighProcess::UpdateProcessTiming() const
{
    return fBreathTimer;
}

// @fnv 0x008d9390
DetectionEvent* HighProcess::FindDetectionEventForActor(Actor* index)
{
    return pActorsGeneratedDetectionEvent;
}

// @fnv 0x008d8ff0
void HighProcess::SetEssentialFlag(bool value)
{
    bWeaponAlertDrawn = value;
}

// @fnv 0x008d9070
void HighProcess::SetAnimationEnabled(bool value)
{
    bContinuingPackageforPC = value;
}

// @fnv 0x008d9320
float HighProcess::GetFirstProcessFloat() const
{
    return fCheckToTalkTimer;
}

// @fnv 0x008d9690
void HighProcess::SetCurrentDialogueItem(DialogueItem* value)
{
    pSubtitleVoice = value;
}

// @fnv 0x008d9410
void HighProcess::SetIdleForm(TESIdleForm* value)
{
    pIdleToPlay = value;
}

// @fnv 0x008d91a0
void HighProcess::ResetMovementState(void)
{
    bStop = BaseProcess::POSTANIM_ACTION_NONE;
}

// @fnv 0x008d9160
void HighProcess::SetSubtitleActive(bool value)
{
    bActivateAnim = value;
}

// @fnv 0x008d9550
void HighProcess::SetActorProcessEnabled(bool value)
{
    bDialoguewithPlayer = value;
}

// @fnv 0x008d9240
LipSyncAnimation* HighProcess::GetLipSync() const
{
    return pLipSynicAnim;
}

// @fnv 0x008d92a0
bool HighProcess::IsActorTalking() const
{
    return bLipFileFailed;
}

// @fnv 0x008d9220
void HighProcess::SetDialogueState(bool value)
{
    bWaitingForLipFile = value;
}

// @fnv 0x008d8e00
void HighProcess::SetDialogueEmotion(DIALOGUE_EMOTION value)
{
    eLastSpeakingEmotion = value;
}

// @fnv 0x008d9260
void HighProcess::AssignLipSyncAnimation(LipSyncAnimation* value)
{
    pLipSynicAnim = value;
}

// @fnv 0x008d8f70
void HighProcess::SetLipSyncValue(float value)
{
    fSoundDelay = value;
}

// @fnv 0x008d9280
void HighProcess::SetTalkingState(bool value)
{
    bLipFileFailed = value;
}

// @fnv 0x008d8fb0
void HighProcess::UpdateActorProcess(float value)
{
    fGreetingTimer = value;
}

// @fnv 0x008d9830
TESObjectREFR* HighProcess::GetRelatedReference() const
{
    return pLastTarget;
}

// @fnv 0x008d8e20
TESObjectREFR* HighProcess::GetPreviousReference() const
{
    return pGreetActor;
}

// @fnv 0x008d9430
bool HighProcess::HasCombatStarted()
{
    return bFinishingCombatPackage;
}

// @fnv 0x008d9810
bool HighProcess::IsCombatTargetValid() const
{
    return bForceRotate;
}

// @fnv 0x008d8e40
void HighProcess::SetActorTargetReference(TESObjectREFR* value)
{
    pGreetActor = value;
}

// @fnv 0x008d92c0
bool HighProcess::CanFireWeapon(void)
{
    return bLipQuequed;
}

// @fnv 0x008d9670
DialogueItem* HighProcess::GetCurrentDialogueItem() const
{
    return pSubtitleVoice;
}

// @fnv 0x008d8dc0
void HighProcess::SetCombatEnabled(bool value)
{
    bIsDoingSayTo = value;
}

// @fnv 0x008d8f30
void HighProcess::SetCombatAlerted(bool value)
{
    bGreetingFlag = value;
}

// @fnv 0x008d9570
void HighProcess::StopAllActorSounds()
{
    fDetectionModifierTimer = *originalRuntimeFloatSetting244.Float();
}

// @fnv 0x008d8e60
BSSoundHandle HighProcess::GetActorSoundHandle(unsigned int index)
{
    return SoundHandle[index];
}

// @fnv 0x008d8ea0
void HighProcess::SetActorSoundHandle(unsigned int index, BSSoundHandle handle)
{
    SoundHandle[index] = handle;
}

#endif
