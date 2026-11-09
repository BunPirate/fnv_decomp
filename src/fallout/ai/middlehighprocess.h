// Reconstructed source: fallout/ai/middlehighprocess.h
// MiddleHighProcess inline accessors (Doc Speech30 aid segment).
#ifndef FNV_MIDDLEHIGHPROCESS_H
#define FNV_MIDDLEHIGHPROCESS_H

#include "../../../include/FurnitureMark.h"
#include "../../../include/MiddleHighProcess.h"

enum RESET_3D_FLAGS
{
    RESET_3D_FLAGS_RESET_MODEL = 1,
    RESET_3D_FLAGS_RESET_SKIN = 2,
    RESET_3D_FLAGS_RESET_HEAD = 4,
    RESET_3D_FLAGS_RESET_FACE = 8,
    RESET_3D_FLAGS_RESET_SCALE = 16
};

// @fnv 0x008d8120
MagicItem* MiddleHighProcess::GetSelectedMagicItem() const
{
    return pCurrentSpell;
}

// @fnv 0x008d8140
void MiddleHighProcess::SetSelectedMagicItem(MagicItem* apSpell)
{
    pCurrentSpell = apSpell;
}

// @fnv 0x008d8180
void MiddleHighProcess::SetMagicTarget(MagicTarget* apTarget)
{
    pDesiredTarget = apTarget;
}

// @fnv 0x008d81a0
bool MiddleHighProcess::UpdateIdleAnimation() const
{
    return bCheckMagicNode;
}

// @fnv 0x008d8220
bool MiddleHighProcess::ResetAlertState() const
{
    return bWeaponGrenade;
}

// @fnv 0x008d8270
bool MiddleHighProcess::GetProcessState()
{
    return bHeavyArmorWorn;
}

// @fnv 0x008d8290
bool MiddleHighProcess::SetProcessStateFlag()
{
    return bPowerArmorWorn;
}

// @fnv 0x008d82d0
bool MiddleHighProcess::SetActorAlertState()
{
    return bHasBackPackWorn;
}

// @fnv 0x008d82f0
void MiddleHighProcess::Assign3DObject(NiAVObject* apNode)
{
    pFireNode = apNode;
}

// @fnv 0x008d8420
int MiddleHighProcess::GetCurrentProcedure() const
{
    return const_cast<ActorPackageContext&>(RunOncePackage).GetProcedureIndex();
}

// @fnv 0x008d8440
void MiddleHighProcess::SetCurrentProcedure(int aiIndex)
{
    RunOncePackage.AddToProcedureIndex(aiIndex);
}

// @fnv 0x008d8480
bhkCharacterController* MiddleHighProcess::GetPhysicsCharacterController() const
{
    return spCharController;
}

// @fnv 0x008d84a0
void MiddleHighProcess::AssignCharacterController(NiPointer<bhkCharacterController> apController)
{
    spCharController = apController;
}

// @fnv 0x008d8500
void MiddleHighProcess::AddDeferredHideLimb(ObjectToAcquire* apObject)
{
    pAcquireObject = (TargetDoorController*)apObject;
}

// @fnv 0x00407800
void MiddleHighProcess::SetFaceAnimationData(ObjectToAcquire* apObject)
{
    pSavedAcquireObject = (TargetDoorController*)apObject;
}

// @fnv 0x008d8540
KNOCK_STATE_ENUM MiddleHighProcess::StopIdleAnimation()
{
    return (KNOCK_STATE_ENUM)cKnockState;
}

// @fnv 0x008d8600
bool MiddleHighProcess::IsProcessStateInitialized() const
{
    return bRefreshMagicShaderEffects;
}

// @fnv 0x008d8680
void MiddleHighProcess::InitializeProcessState()
{
    m_pFaceAnimationData = 0;
}

// @fnv 0x008d8740
void MiddleHighProcess::ResetActorModel(RESET_3D_FLAGS aeFlags)
{
    cUpdate3DModel |= aeFlags;
}

// @fnv 0x008d87a0
void MiddleHighProcess::ClearDetectionFlag()
{
    cUpdate3DModel = 0;
}

// @fnv 0x008d8800
BSSimpleList<ArrowProjectile*>* MiddleHighProcess::GetArrowProjectiles() const
{
    return pAttachedArrowList;
}

// @fnv 0x008d8840
bool MiddleHighProcess::IsAlert() const
{
    return bIronSights;
}

// @fnv 0x008d8860
bool MiddleHighProcess::IsHoldingWeapon()
{
    return bSustainedFire;
}

// @fnv 0x008d8880
void MiddleHighProcess::SetSustainedState(bool abSustained)
{
    bSustainedFire = abSustained;
}

// @fnv 0x008d88a0
void MiddleHighProcess::SetIdleAnimationPlayed(bool abPlayed)
{
    bPlayedBeginIdles = abPlayed;
}

// @fnv 0x008d88e0
void MiddleHighProcess::SetPlayedState(bool abPlayed)
{
    bPlayedEndIdles = abPlayed;
}

// @fnv 0x008d8900
bool MiddleHighProcess::WasIdleAnimationPlayed() const
{
    return bPlayedEndIdles;
}

// @fnv 0x008d8920
LipSyncAnimation* MiddleHighProcess::GetLipSyncAnimationData() const
{
    return pCreatureLipsynchAnim;
}

// @fnv 0x008d89c0
float MiddleHighProcess::GetAnimationElapsedTime() const
{
    return fRadiationMagicDelta;
}

// @fnv 0x008d89e0
void MiddleHighProcess::AdvanceMovementTimer(float afDelta)
{
    fRadiationWaterDelta = afDelta;
}

// @fnv 0x008d8a00
float MiddleHighProcess::GetAnimationRemainingTime() const
{
    return fRadiationWaterDelta;
}

// @fnv 0x008d8a80
void MiddleHighProcess::SetKnockdownStage(int aiStage)
{
    iWeaponConditionStage = aiStage;
}

// @fnv 0x008d8aa0
void MiddleHighProcess::AttachFaceGenerationNode(BSFaceGenNiNode* apNode)
{
    pFaceNode = apNode;
}

// @fnv 0x008d8ac0
BSFaceGenNiNode* MiddleHighProcess::GetFaceGenHeadNode() const
{
    return pFaceNodeSkinned;
}

// @fnv 0x008d8ae0
void MiddleHighProcess::SetFaceGenHeadNode(BSFaceGenNiNode* apNode)
{
    pFaceNodeSkinned = apNode;
}

// @fnv 0x008d8b00
NiAVObject* MiddleHighProcess::GetAnimationObject() const
{
    return pAnimFace;
}

// @fnv 0x008d8c20
NiNode* MiddleHighProcess::GetActorSceneObject() const
{
    return (NiNode*)pTorsoNode;
}

// @fnv 0x00502430
NiNode* MiddleHighProcess::GetSceneRoot() const
{
    return (NiNode*)pFireNode;
}

// @fnv 0x00505e50
void MiddleHighProcess::SetCurrentIdle(TESIdleForm* apIdle)
{
    pLastIdlePlayed = apIdle;
}

// @fnv 0x00521630
BooleanFloatQuery* MiddleHighProcess::RefreshActorRuntimeData() const
{
    return pLastHitData;
}

// @fnv 0x00521710
void MiddleHighProcess::SetAnimationNode(NiAVObject* apAnims)
{
    pAnimFace = apAnims;
}

// @fnv 0x005224a0
BSFaceGenNiNode* MiddleHighProcess::GetFacialAnimationNode() const
{
    return pFaceNode;
}

// @fnv 0x00566950
bool MiddleHighProcess::IsActorInCombat() const
{
    return bForceNextUpdate;
}

// @fnv 0x005c8a30
void MiddleHighProcess::SetBoundingBox(BSBound* apBound)
{
    pBSBound = apBound;
}

// @fnv 0x005ce8f0
bool MiddleHighProcess::IsAnimationPlaying() const
{
    return bWeaponMine;
}

// @fnv 0x00602150
Animation* MiddleHighProcess::GetAnimation() const
{
    return pAnimation;
}

// @fnv 0x007ac9d0
void MiddleHighProcess::AssignEffectShader(TESEffectShader* apShader)
{
    pCurrentWeaponEffect = apShader;
}

// @fnv 0x0087d7d0
void MiddleHighProcess::UpdateEffectShader(unsigned int auiTime)
{
    iCreatureLipsynchStartTime = auiTime;
}

// @fnv 0x008f7710
float MiddleHighProcess::GetLightIntensity() const
{
    return fAlphaMult;
}

// @fnv 0x009ee020
BSBound* MiddleHighProcess::GetObjectBounds()
{
    return pBSBound;
}

// @fnv 0x008d8310
bool MiddleHighProcess::ClearProcessStateFlags() const
{
    return GetRunOncePackage();
}

// @fnv 0x008d8b20
// pdb: MiddleHighProcess::GetSitSleepState | HighProcess.obj | retail, upstream name already matches, high
SIT_SLEEP_STATE MiddleHighProcess::GetSitSleepState() const
{
    if ((GetPostAnimationAction() & 8) &&
        (cSitSleepState == 4 || cSitSleepState == 9))
        return (SIT_SLEEP_STATE)(cSitSleepState + 1);
    else
        return (SIT_SLEEP_STATE)cSitSleepState;
}

#endif
