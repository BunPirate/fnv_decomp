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

    BSSimpleList<TESObjectREFR*> DeadDetectList; // 0x0C8
    BSSimpleList<TESObjectREFR*> RefListChairBed; // 0x0D0
    float fPursueTimer; // 0x0D8
    float fEquippedWeight; // 0x0DC
    bool bDoneOnce; // 0x0E0
    bool bAimingTarget; // 0x0E1
    bool bNeedReparentWeapon; // 0x0E2
    bool bDrawn; // 0x0E3
    ActorPackageContext RunOncePackage; // 0x0E4
    NiPoint3 lastSeenPostion; // 0x0FC
    PACKAGE_OBJECT_TYPE eUseItem; // 0x108
    TESIdleForm* pLastIdlePlayed; // 0x10C
    bool bPickPackIdle; // 0x110
    unsigned char layoutPadding111[3]; // 0x111
    InventoryStackRecord* pWeapon; // 0x114
    InventoryStackRecord* pAmmo; // 0x118
    NiPointer<QueuedFile> spWeaponPreload; // 0x11C
    NiPointer<ActorSupportClass> spReserveProjectileClones; // 0x120
    bool bWeaponGrenade; // 0x124
    bool bWeaponMine; // 0x125
    bool bWeaponThrown; // 0x126
    bool bHeavyArmorWorn; // 0x127
    bool bPowerArmorWorn; // 0x128
    bool bPowerArmorHelmet; // 0x129
    bool bHasBackPackWorn; // 0x12A
    unsigned char layoutPadding12B[1]; // 0x12B
    NiNode* pWeaponBone; // 0x12C
    NiAVObject* pFireNode; // 0x130
    bool bWantWeaponDrawn; // 0x134
    bool bWeaponDrawn; // 0x135
    unsigned char layoutPadding136[2]; // 0x136
    NiPointer<bhkCharacterController> spCharController; // 0x138
    char cKnockState; // 0x13C
    unsigned char cSitSleepState; // 0x13D
    unsigned char layoutPadding13E[2]; // 0x13E
    TESObjectREFR* m_pFurnitureReference; // 0x140
    unsigned char cCurrentFurnitureIndex; // 0x144
    unsigned char layoutPadding145[3]; // 0x145
    FurnitureMark FurnitureMarker; // 0x148
    Actor* pCommandingActor; // 0x158
    TESObjectWEAP* pLastBoundWeapon; // 0x15C
    MagicItem* pCurrentSpell; // 0x160
    MagicItem* pCurrentPackageSpell; // 0x164
    bool bCheckMagicNode; // 0x168
    unsigned char layoutPadding169[3]; // 0x169
    TESEffectShader* pCurrentWeaponEffect; // 0x16C
    float fAlphaMult; // 0x170
    float fScriptRefractPower; // 0x174
    BSFaceGenAnimationData* m_pFaceAnimationData; // 0x178
    bool bRefreshMagicShaderEffects; // 0x17C
    bool bRefreshMagicShaderEffectBody; // 0x17D
    bool bRefreshMagicShaderEffectWeapon; // 0x17E
    bool bRefreshMagicShaderEffectLoading; // 0x17F
    bool bRefreshFlareFlags; // 0x180
    unsigned char layoutPadding181[3]; // 0x181
    unsigned int uiFlareFlags; // 0x184
    bool bPickPocketed; // 0x188
    bool bDoneClothesChange; // 0x189
    bool bDetectLifeDetected; // 0x18A
    bool bSummonedCreature; // 0x18B
    unsigned char cUpdate3DModel; // 0x18C
    bool bForceNextUpdate; // 0x18D
    unsigned char layoutPadding18E[2]; // 0x18E
    int iPackageIdleNumber; // 0x190
    TESIdleForm* pCurrentIdle; // 0x194
    float fPackageIdleTimer; // 0x198
    bool bPlayedBeginIdles; // 0x19C
    bool bPlayedEndIdles; // 0x19D
    unsigned char layoutPadding19E[2]; // 0x19E
    LipSyncAnimation* pCreatureLipsynchAnim; // 0x1A0
    unsigned int iCreatureLipsynchStartTime; // 0x1A4
    int iReservationSlot; // 0x1A8
    BSSimpleList<ArrowProjectile*>* pAttachedArrowList; // 0x1AC
    BSSimpleList<MiddleHighProcess__DeferredHideLimb*> DeferredHideLimbList; // 0x1B0
    BSSimpleList<ActiveEffect*>* pActiveEffectList; // 0x1B8
    MagicTarget* pDesiredTarget; // 0x1BC
    Animation* pAnimation; // 0x1C0
    BSAnimGroupSequence* pAimSequence[3]; // 0x1C4
    float fAimLooking; // 0x1D0
    float fAutomaticShotDelay; // 0x1D4
    unsigned char cShotsToFire; // 0x1D8
    bool bSustainedFire; // 0x1D9
    bool bBeenAttacked; // 0x1DA
    unsigned char layoutPadding1DB[1]; // 0x1DB
    NiNode* pDamageRootNode[15]; // 0x1DC
    NiAVObject* pHeadNode; // 0x218
    NiAVObject* pTorsoNode; // 0x21C
    NiPointer<BSShaderPPLightingProperty> pLightingProperty; // 0x220
    BSBound* pBSBound; // 0x224
    bool bIronSights; // 0x228
    unsigned char layoutPadding229[1]; // 0x229
    short iAnimActionSuccess; // 0x22A
    unsigned int iMovementAnimations; // 0x22C
    BSSimpleList<PaddedFloatRecord*>* pListItemstoEquipUnequip; // 0x230
    float fRadiationDelta; // 0x234
    float fRadiationMagicDelta; // 0x238
    float fRadiationWaterDelta; // 0x23C
    BooleanFloatQuery* pLastHitData; // 0x240
    int iWeaponConditionStage; // 0x244
    BSFaceGenNiNode* pFaceNode; // 0x248
    BSFaceGenNiNode* pFaceNodeSkinned; // 0x24C
    NiAVObject* pAnimFace; // 0x250
    BooleanFloatQuery* pLastAttackHitData; // 0x254
    unsigned int nFurnitureListTimer; // 0x258

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
