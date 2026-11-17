#pragma once

#include "MiddleLowProcess.h"
#include "ActorPackageContext.h"
#include "NiPoint3.h"
#include "MagicTarget.h"
#include "NiAVObject.h"
#include "FurnitureMark.h"

class ActiveEffect;
class Actor;
class ActorSupportClass;
class Animation;
class ArrowProjectile;
class BGSLoadFormBuffer;
class BipedAnim;
class BooleanFloatQuery;
class BSAnimGroupSequence;
class BSBound;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class DetectionViewData;
class InventoryStackRecord;
class LipSyncAnimation;
class MagicCaster;
class MagicItem;
class MagicTarget;
class MiddleHighProcess__DeferredHideLimb;
class NiNode;
class PaddedFloatRecord;
class QueuedFile;
class SpellItem;
class TargetDoorController;
class TESEffectShader;
class TESIdleForm;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
class ActorCombatGroup;
class bhkCharacterController;

enum KNOCK_STATE_ENUM;
enum RESET_3D_FLAGS;

#pragma pack(push, 4)
// pdb: class MiddleHighProcess, size 0x25c, bases: MiddleLowProcess, 93 members
class MiddleHighProcess : public MiddleLowProcess
{
public:
    virtual void vfn_820(); // slot 520
    virtual void vfn_824(); // slot 521
    virtual void vfn_828(); // slot 522
    virtual void vfn_82c(); // slot 523
    virtual void vfn_830(Actor*); // slot 524 (ProcessAcquire 0x008ebc60 passes the actor)
    virtual void vfn_834(Actor*); // slot 525 (ProcessAcquire 0x008ebc60 passes the actor)
    virtual void vfn_838(Actor*); // slot 526 (ProcessAcquire 0x008ebc60 passes the actor)
    virtual void vfn_83c(Actor*); // slot 527 (parameters: HighProcess::Update 0x008eeec0 calls)
    virtual bool vfn_840(Actor*); // slot 528 (HighProcess 0x008e8600)
    virtual void vfn_844(); // slot 529
    virtual void vfn_848(Actor*, int, int); // slot 530
    virtual void vfn_84c(Actor*, const NiPoint3*, float); // slot 531 (HighProcess 0x008ed420)
    virtual bool vfn_850(Actor*, Actor*); // slot 532 (HighProcess 0x00901a20)
    virtual void vfn_854(); // slot 533
    virtual void vfn_858(); // slot 534
    virtual void vfn_85c(); // slot 535
    virtual void vfn_860(); // slot 536
    virtual void vfn_864(); // slot 537
    virtual void vfn_868(Actor*, Actor*); // slot 538
    virtual void vfn_86c(); // slot 539
    virtual void ProcessAvoidRadiation(Actor*); // slot 506 override, 0x00908f40 (HighProcess::Update calls it directly)
    virtual bool ShouldAttackTarget(Actor*, Actor*, bool, bool, ActorCombatGroup*, bool, bool, bool, bool, bool, bool,
                                    bool, TESPackage*); // slot 207 override, 0x00916880 (HighProcess 0x009001c0 calls it directly)

    BSSimpleList<TESObjectREFR*> DeadDetectList; // 0x0C8 // src: XBOX_RETAIL_PDB +0xc8 (old: m_kReferenceList)
    BSSimpleList<TESObjectREFR*> RefListChairBed; // 0x0D0 // src: XBOX_RETAIL_PDB +0xd0 (old: m_kSecondaryReferenceList)
    float fPursueTimer; // 0x0D8 // src: XBOX_RETAIL_PDB +0xd8 (old: m_kNinthUnshownMember)
    float fEquippedWeight; // 0x0DC // src: XBOX_RETAIL_PDB +0xdc (old: m_kEighthUnshownMember)
    bool bDoneOnce; // 0x0E0 // src: XBOX_RETAIL_PDB +0xe0 (old: m_bPackageStateFlag2)
    bool bAimingTarget; // 0x0E1 // src: XBOX_RETAIL_PDB +0xe1 (old: m_bPackageStateFlag)
    bool bNeedReparentWeapon; // 0x0E2 // src: XBOX_RETAIL_PDB +0xe2 (old: m_bPackageStateFlag3)
    bool bDrawn; // 0x0E3 // src: XBOX_RETAIL_PDB +0xe3 (old: m_bPackageStateFlag4)
    ActorPackageContext RunOncePackage; // 0x0E4 // src: XBOX_RETAIL_PDB +0xe4 (old: PackageReference)
    NiPoint3 lastSeenPostion; // 0x0FC // src: XBOX_RETAIL_PDB +0xfc (old: m_kPackageTargetPosition)
    PACKAGE_OBJECT_TYPE eUseItem; // 0x108 // src: XBOX_RETAIL_PDB +0x108 (old: m_ePackageObjectType)
    TESIdleForm* pLastIdlePlayed; // 0x10C // src: XBOX_RETAIL_PDB +0x10c (old: m_pPackageIdleForm)
    bool bPickPackIdle; // 0x110 // src: XBOX_RETAIL_PDB +0x110 (old: m_kSecondUnshownMember)
    unsigned char layoutPadding111[3]; // 0x111
    InventoryStackRecord* pWeapon; // 0x114
    InventoryStackRecord* pAmmo; // 0x118
    NiPointer<QueuedFile> spWeaponPreload; // 0x11C // src: XBOX_RETAIL_PDB +0x11c (old: m_pQueuedWeaponFile)
    NiPointer<ActorSupportClass> spReserveProjectileClones; // 0x120 // src: XBOX_RETAIL_PDB +0x120 (old: m_pWeaponData)
    bool bWeaponGrenade; // 0x124 // src: XBOX_RETAIL_PDB +0x124 (old: m_bFirstWeaponFlag)
    bool bWeaponMine; // 0x125 // src: XBOX_RETAIL_PDB +0x125 (old: m_bSecondWeaponFlag)
    bool bWeaponThrown; // 0x126 // src: XBOX_RETAIL_PDB +0x126 (old: m_bThirdWeaponFlag)
    bool bHeavyArmorWorn; // 0x127 // src: XBOX_RETAIL_PDB +0x127 (old: m_bFourthWeaponFlag)
    bool bPowerArmorWorn; // 0x128 // src: XBOX_RETAIL_PDB +0x128 (old: m_bFifthWeaponFlag)
    bool bPowerArmorHelmet; // 0x129 // src: XBOX_RETAIL_PDB +0x129 (old: m_bSixthWeaponFlag)
    bool bHasBackPackWorn; // 0x12A // src: XBOX_RETAIL_PDB +0x12a (old: m_bSeventhWeaponFlag)
    unsigned char layoutPadding12B[1]; // 0x12B
    NiNode* pWeaponBone; // 0x12C // src: XBOX_RETAIL_PDB +0x12c (old: m_pActorNode)
    NiAVObject* pFireNode; // 0x130 // src: XBOX_RETAIL_PDB +0x130 (old: m_pActorObject)
    bool bWantWeaponDrawn; // 0x134 // src: XBOX_RETAIL_PDB +0x134 (old: m_bFirstActorFlag)
    bool bWeaponDrawn; // 0x135 // src: XBOX_RETAIL_PDB +0x135 (old: m_bAdditionalActorFlag)
    unsigned char layoutPadding136[2]; // 0x136
    NiPointer<bhkCharacterController> spCharController; // 0x138 // src: XBOX_RETAIL_PDB +0x138 (old: m_pCharacterController)
    char cKnockState; // 0x13C // src: XBOX_RETAIL_PDB +0x13c (old: m_cCharacterControllerState)
    unsigned char cSitSleepState; // 0x13D // src: XBOX_RETAIL_PDB +0x13d (old: m_ucFurnitureInteractionState)
    unsigned char layoutPadding13E[2]; // 0x13E
    TESObjectREFR* m_pFurnitureReference; // 0x140
    unsigned char cCurrentFurnitureIndex; // 0x144 // src: XBOX_RETAIL_PDB +0x144 (old: m_ucFurnitureMarkerIndex)
    unsigned char layoutPadding145[3]; // 0x145
    FurnitureMark FurnitureMarker; // 0x148
    Actor* pCommandingActor; // 0x158 // src: XBOX_RETAIL_PDB +0x158 (old: m_pCombatTarget)
    TESObjectWEAP* pLastBoundWeapon; // 0x15C // src: XBOX_RETAIL_PDB +0x15c (old: m_pEquippedWeapon)
    MagicItem* pCurrentSpell; // 0x160 // src: XBOX_RETAIL_PDB +0x160 (old: m_pFirstMagicItem)
    MagicItem* pCurrentPackageSpell; // 0x164 // src: XBOX_RETAIL_PDB +0x164 (old: m_pSecondMagicItem)
    bool bCheckMagicNode; // 0x168 // src: XBOX_RETAIL_PDB +0x168 (old: m_bWeaponOut)
    unsigned char layoutPadding169[3]; // 0x169
    TESEffectShader* pCurrentWeaponEffect; // 0x16C // src: XBOX_RETAIL_PDB +0x16c (old: m_pEffectShader)
    float fAlphaMult; // 0x170 // src: XBOX_RETAIL_PDB +0x170 (old: m_fFirstEffectShaderValue)
    float fScriptRefractPower; // 0x174 // src: XBOX_RETAIL_PDB +0x174 (old: m_fSecondEffectShaderValue)
    BSFaceGenAnimationData* m_pFaceAnimationData; // 0x178 // src: XBOX_RETAIL_PDB +0x178 (old: m_pFaceGenAnimationData)
    bool bRefreshMagicShaderEffects; // 0x17C // src: XBOX_RETAIL_PDB +0x17c (old: m_bFirstFaceGenFlag)
    bool bRefreshMagicShaderEffectBody; // 0x17D // src: XBOX_RETAIL_PDB +0x17d (old: m_kSixthUnshownMember)
    bool bRefreshMagicShaderEffectWeapon; // 0x17E // src: XBOX_RETAIL_PDB +0x17e (old: m_bThirdFaceGenFlag)
    bool bRefreshMagicShaderEffectLoading; // 0x17F // src: XBOX_RETAIL_PDB +0x17f (old: m_kSeventhUnshownMember)
    bool bRefreshFlareFlags; // 0x180 // src: XBOX_RETAIL_PDB +0x180 (old: m_kFifthUnshownMember)
    unsigned char layoutPadding181[3]; // 0x181
    unsigned int uiFlareFlags; // 0x184 // src: XBOX_RETAIL_PDB +0x184 (old: m_uiAnimationStateFlags)
    bool bPickPocketed; // 0x188 // src: XBOX_RETAIL_PDB +0x188 (old: m_bAiming)
    bool bDoneClothesChange; // 0x189 // src: XBOX_RETAIL_PDB +0x189 (old: m_bAimStateFlag)
    bool bDetectLifeDetected; // 0x18A // src: XBOX_RETAIL_PDB +0x18a (old: m_bCombatStateFlag)
    bool bSummonedCreature; // 0x18B // src: XBOX_RETAIL_PDB +0x18b (old: m_bFourthStateFlag)
    unsigned char cUpdate3DModel; // 0x18C // src: XBOX_RETAIL_PDB +0x18c (old: m_ucProcessState)
    bool bForceNextUpdate; // 0x18D // src: XBOX_RETAIL_PDB +0x18d (old: m_bEquipStateFlag)
    unsigned char layoutPadding18E[2]; // 0x18E
    int iPackageIdleNumber; // 0x190 // src: XBOX_RETAIL_PDB +0x190 (old: m_iIdleState)
    TESIdleForm* pCurrentIdle; // 0x194 // src: XBOX_RETAIL_PDB +0x194 (old: m_pCurrentIdleForm)
    float fPackageIdleTimer; // 0x198 // src: XBOX_RETAIL_PDB +0x198 (old: m_fIdleAnimationTime)
    bool bPlayedBeginIdles; // 0x19C // src: XBOX_RETAIL_PDB +0x19c (old: m_kThirdUnshownMember)
    bool bPlayedEndIdles; // 0x19D // src: XBOX_RETAIL_PDB +0x19d (old: m_kFourthUnshownMember)
    unsigned char layoutPadding19E[2]; // 0x19E
    LipSyncAnimation* pCreatureLipsynchAnim; // 0x1A0 // src: XBOX_RETAIL_PDB +0x1a0 (old: m_pLipSyncAnimation)
    unsigned int iCreatureLipsynchStartTime; // 0x1A4 // src: XBOX_RETAIL_PDB +0x1a4 (old: m_uiLipSyncState)
    int iReservationSlot; // 0x1A8 // src: XBOX_RETAIL_PDB +0x1a8 (old: m_iProjectileCount)
    BSSimpleList<ArrowProjectile*>* pAttachedArrowList; // 0x1AC // src: XBOX_RETAIL_PDB +0x1ac (old: m_pArrowProjectileList)
    BSSimpleList<MiddleHighProcess__DeferredHideLimb*> DeferredHideLimbList; // 0x1B0 // src: XBOX_RETAIL_PDB +0x1b0 (old: m_kDeferredHideLimbList)
    BSSimpleList<ActiveEffect*>* pActiveEffectList; // 0x1B8 // src: XBOX_RETAIL_PDB +0x1b8 (old: m_pActiveEffectList)
    MagicTarget* pDesiredTarget; // 0x1BC // src: XBOX_RETAIL_PDB +0x1bc (old: m_pMagicTarget)
    Animation* pAnimation; // 0x1C0 // src: XBOX_RETAIL_PDB +0x1c0 (old: pCurrentAnimation)
    BSAnimGroupSequence* pAimSequence[3]; // 0x1C4 // src: XBOX_RETAIL_PDB +0x1c4 (old: m_apAnimGroupSequences)
    float fAimLooking; // 0x1D0 // src: XBOX_RETAIL_PDB +0x1d0 (old: m_fAnimationTime)
    float fAutomaticShotDelay; // 0x1D4 // src: XBOX_RETAIL_PDB +0x1d4 (old: m_fAnimationSpeed)
    unsigned char cShotsToFire; // 0x1D8 // src: XBOX_RETAIL_PDB +0x1d8 (old: m_ucAnimationState)
    bool bSustainedFire; // 0x1D9 // src: XBOX_RETAIL_PDB +0x1d9 (old: m_bFirstAnimationFlag)
    bool bBeenAttacked; // 0x1DA // src: XBOX_RETAIL_PDB +0x1da (old: m_bAnimationStateFlag)
    unsigned char layoutPadding1DB[1]; // 0x1DB
    NiNode* pDamageRootNode[15]; // 0x1DC // src: XBOX_RETAIL_PDB +0x1dc (old: m_apBodyPartNodes)
    NiAVObject* pHeadNode; // 0x218 // src: XBOX_RETAIL_PDB +0x218 (old: m_pFirstAttachedObject)
    NiAVObject* pTorsoNode; // 0x21C // src: XBOX_RETAIL_PDB +0x21c (old: m_pSecondAttachedObject)
    NiPointer<BSShaderPPLightingProperty> pLightingProperty; // 0x220 // src: XBOX_RETAIL_PDB +0x220 (old: m_pLightingProperty)
    BSBound* pBSBound; // 0x224 // src: XBOX_RETAIL_PDB +0x224 (old: m_pBound)
    bool bIronSights; // 0x228 // src: XBOX_RETAIL_PDB +0x228 (old: m_kFieldAfterWeaponFlags)
    unsigned char layoutPadding229[1]; // 0x229
    short iAnimActionSuccess; // 0x22A // src: XBOX_RETAIL_PDB +0x22a (old: m_sBoundDataValue)
    unsigned int iMovementAnimations; // 0x22C // src: XBOX_RETAIL_PDB +0x22c (old: m_kEleventhUnshownMember)
    BSSimpleList<PaddedFloatRecord*>* pListItemstoEquipUnequip; // 0x230 // src: XBOX_RETAIL_PDB +0x230 (old: m_pkPaddedFloatRecordList)
    float fRadiationDelta; // 0x234 // src: XBOX_RETAIL_PDB +0x234 (old: m_kTenthUnshownMember)
    float fRadiationMagicDelta; // 0x238 // src: XBOX_RETAIL_PDB +0x238 (old: m_fFirstFaceGenValue)
    float fRadiationWaterDelta; // 0x23C // src: XBOX_RETAIL_PDB +0x23c (old: m_fSecondFaceGenValue)
    BooleanFloatQuery* pLastHitData; // 0x240 // src: XBOX_RETAIL_PDB +0x240 (old: m_pData)
    int iWeaponConditionStage; // 0x244 // src: XBOX_RETAIL_PDB +0x244 (old: m_iFaceGenNodeIndex)
    BSFaceGenNiNode* pFaceNode; // 0x248 // src: XBOX_RETAIL_PDB +0x248 (old: m_pFirstFaceGenNode)
    BSFaceGenNiNode* pFaceNodeSkinned; // 0x24C // src: XBOX_RETAIL_PDB +0x24c (old: m_pSecondFaceGenNode)
    NiAVObject* pAnimFace; // 0x250 // src: XBOX_RETAIL_PDB +0x250 (old: m_pFaceGenObject)
    BooleanFloatQuery* pLastAttackHitData; // 0x254 // src: XBOX_RETAIL_PDB +0x254 (old: m_pAdditionalFaceGenData)
    unsigned int nFurnitureListTimer; // 0x258 // src: XBOX_RETAIL_PDB +0x258 (old: m_uiFaceGenDataFlags)

    MiddleHighProcess();
    virtual ~MiddleHighProcess();
    virtual void ResetCurrentPackage(); // RTTI slot 145
    void SetAnimation(Animation*);
    void RefreshActorPackage(Actor*);
    void ProcessCombat_0091db40(Actor*);
    void BGSTerrainManager_SetNeedsImmediateUpdate(unsigned char);
    bool BSCriticalSection_TryLock();
    void Revert(BGSLoadFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void InitLoadGame(BGSLoadFormBuffer*);
    virtual FurnitureMark* GetFurnitureMarkerData() const; // RTTI slot 309

    virtual bool IsFirstActorFlagSet() const; // RTTI slot 275

    virtual bool IsAdditionalActorFlagSet() const; // RTTI slot 277

    virtual void CastSpellOnCaster(MagicCaster* apCaster, SpellItem* apAbility, bool abLoadCast); // RTTI slot 240
    virtual void CastSpellAtTarget(MagicCaster* apCaster, SpellItem* apDisease, MagicTarget* apTarget, bool abLoadCast); // RTTI slot 241
    virtual void SetPixelLightingProperty(BSShaderPPLightingProperty* apProp); // RTTI slot 319
    virtual NiNode* GetActorRootNode(BipedAnim* apAnim) const; // RTTI slot 100

    virtual void UpdateActorAppearance(bool abUpdateWeaponEffectShader, bool abInitializeActiveHitEffect, bool); // RTTI slot 352
    virtual bool ClearProcessStateFlags() const; // RTTI slot 215
    virtual SIT_SLEEP_STATE GetSitSleepState() const; // RTTI slot 303
    virtual MagicItem* GetSelectedMagicItem() const; // RTTI slot 242
    virtual void SetSelectedMagicItem(MagicItem* apSpell); // RTTI slot 243
    virtual void SetMagicTarget(MagicTarget* apTarget); // RTTI slot 245
    virtual bool UpdateIdleAnimation() const; // RTTI slot 246
    virtual bool ResetAlertState() const; // RTTI slot 106
    bool GetProcessState();
    bool SetProcessStateFlag();
    bool SetActorAlertState();
    virtual void Assign3DObject(NiAVObject* apNode); // RTTI slot 98
    virtual int GetCurrentProcedure() const; // RTTI slot 135
    virtual void SetCurrentProcedure(int aiOffset); // RTTI slot 136
    virtual bhkCharacterController* GetPhysicsCharacterController() const; // RTTI slot 163
    virtual void AssignCharacterController(NiPointer<bhkCharacterController> arController); // RTTI slot 164
    virtual void AddDeferredHideLimb(ObjectToAcquire* apObject); // RTTI slot 78
    virtual void SetFaceAnimationData(ObjectToAcquire* apObject); // RTTI slot 80
    KNOCK_STATE_ENUM StopIdleAnimation();
    virtual bool IsProcessStateInitialized() const; // RTTI slot 351
    virtual void InitializeProcessState(); // RTTI slot 22
    virtual void ResetActorModel(RESET_3D_FLAGS aucFlag); // RTTI slot 282
    virtual void ClearDetectionFlag(); // RTTI slot 284
    virtual BSSimpleList<ArrowProjectile*>* GetArrowProjectiles() const; // RTTI slot 428
    virtual bool IsAlert() const; // RTTI slot 257
    bool IsHoldingWeapon();
    virtual void SetSustainedState(bool abVal); // RTTI slot 440
    virtual void SetIdleAnimationPlayed(bool abVal); // RTTI slot 354
    virtual void SetPlayedState(bool abVal); // RTTI slot 356
    virtual bool WasIdleAnimationPlayed() const; // RTTI slot 357
    virtual LipSyncAnimation* GetLipSyncAnimationData() const; // RTTI slot 466
    virtual float GetAnimationElapsedTime() const; // RTTI slot 471
    virtual void AdvanceMovementTimer(float afVal); // RTTI slot 472
    virtual float GetAnimationRemainingTime() const; // RTTI slot 473
    virtual void SetKnockdownStage(int aiStage); // RTTI slot 483
    virtual void AttachFaceGenerationNode(BSFaceGenNiNode* apNode); // RTTI slot 485
    virtual BSFaceGenNiNode* GetFaceGenHeadNode() const; // RTTI slot 486
    virtual void SetFaceGenHeadNode(BSFaceGenNiNode* apNode); // RTTI slot 487
    virtual NiAVObject* GetAnimationObject() const; // RTTI slot 488
    virtual NiNode* GetActorSceneObject() const; // RTTI slot 438
    virtual NiNode* GetSceneRoot() const; // RTTI slot 97
    void SetCurrentIdle(TESIdleForm*);
    virtual BooleanFloatQuery* RefreshActorRuntimeData() const; // RTTI slot 476
    virtual void SetAnimationNode(NiAVObject* apObject); // RTTI slot 489
    virtual BSFaceGenNiNode* GetFacialAnimationNode() const; // RTTI slot 484
    virtual bool IsActorInCombat() const; // RTTI slot 383
    void SetBoundingBox(BSBound*);
    virtual bool IsAnimationPlaying() const; // RTTI slot 107
    virtual Animation* GetAnimation() const;
 // RTTI slot 110
    virtual void AssignEffectShader(TESEffectShader* apShader); // RTTI slot 350
    virtual void UpdateEffectShader(unsigned int auiTime); // RTTI slot 467
    virtual float GetLightIntensity() const; // RTTI slot 363
    BSBound* GetObjectBounds();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList() const; // RTTI slot 238
    virtual float GetVisibilityAlpha() const; // RTTI slot 273
    virtual ActorValue::Index GetWeaponForm() const; // RTTI slot 333
    virtual void SetRunOncePackageIndex(int aiIndex); // RTTI slot 134
    virtual ObjectToAcquire* GetObjectToAcquire() const; // RTTI slot 79
    void ReadAnimationState(BGSLoadFormBuffer*);
    virtual float GetThirdProcessFloat() const; // RTTI slot 365
    virtual bool BeginIdleAnimation() const; // RTTI slot 422
    virtual InventoryStackRecord* GetActiveWeapon() const; // RTTI slot 82
    virtual InventoryStackRecord* GetCurrentAmmo() const; // RTTI slot 83
    TESPackage* GetInterruptPackage();
    TESPackage* GetStablePackage();
    virtual DetectionViewData* GetDetectionState(Actor* apTarget, DetectionListType aeType) const; // RTTI slot 321
    bool HasMatchingQueuedItem(TESBoundObject*, ExtraDataList*, bool);
    void UpdateShotsPerSecond(bool);
    void SetLastHitData(BooleanFloatQuery*);
    void* GetRightWeaponBone(void*);
};
#pragma pack(pop)
