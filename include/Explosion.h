#pragma once

#include "MobileObject.h"
#include "MagicTarget.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

class ActorCause;
class Cell;
class Proj;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiLight;
class NonActorMagicCaster;
class TESObjectWEAP;
class bhkSimpleShapePhantom;

// pdb: class Explosion, size 0x104, bases: MobileObject, 26 members
class Explosion : public MobileObject
{
public:
    struct ExplosionParameters;

    Explosion();
    virtual ~Explosion();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual void Update(float delta);
    virtual void Initialize();

    float fAge; // src: XBOX_RETAIL_PDB +0x88 (old: m_fFirstFloatValue)
    float fLifetime; // src: XBOX_RETAIL_PDB +0x8c (old: f3DLifetime)
    float fBuildTime; // src: XBOX_RETAIL_PDB +0x90 (old: fInnerRadius)
    float fRadius; // src: XBOX_RETAIL_PDB +0x94 (old: fOuterRadius)
    float fImageSpaceRadius; // src: XBOX_RETAIL_PDB +0x98 (old: ExplosionRuntimeData)
    float fWeaponCondition; // src: XBOX_RETAIL_PDB +0x9c (old: m_fFourthRecordValue)
    NiPointer<bhkSimpleShapePhantom> spPhantom; // src: XBOX_RETAIL_PDB +0xa0 (old: m_pExplosionPhantom)
    BSSimpleList<ExplosionParameters*> TargetList; // src: XBOX_RETAIL_PDB +0xa4 (old: kTargets)
    BSSoundHandle Sound1[2]; // src: XBOX_RETAIL_PDB +0xac (old: kSoundHandles)
    NiPointer<NiLight> spLight; // src: XBOX_RETAIL_PDB +0xc4 (old: m_pMenuLight)
    TESObjectREFR* pOwner; // src: XBOX_RETAIL_PDB +0xc8 (old: pOwnerRef)
    TESObjectREFR* pExplodedRef; // src: XBOX_RETAIL_PDB +0xcc (old: ReferenceSoundCauseData)
    NiPointer<ActorCause> spActorCause; // src: XBOX_RETAIL_PDB +0xd0 (old: m_pActorCause)
    bool bDecalsPlaced; // src: XBOX_RETAIL_PDB +0xd4 (old: ReferenceCauseInfo)
    bool bTargetsFound; // src: XBOX_RETAIL_PDB +0xd5 (old: m_bFlagD5)
    bool bTargetsProcessed; // src: XBOX_RETAIL_PDB +0xd6 (old: m_bFlagD6)
    bool bForcesApplied; // src: XBOX_RETAIL_PDB +0xd7 (old: m_bFlagD7)
    bool bIgnoreImageSpaceSwap; // src: XBOX_RETAIL_PDB +0xd8 (old: MagicWeaponState)
    bool bUnderWater; // src: XBOX_RETAIL_PDB +0xd9 (old: bUnderwater)
    NonActorMagicCaster* pCaster; // src: XBOX_RETAIL_PDB +0xdc (old: m_pEffectInstance)
    TESObjectWEAP* pWeaponSource; // src: XBOX_RETAIL_PDB +0xe0 (old: m_pFiringWeapon)
    int iFrameCount; // src: XBOX_RETAIL_PDB +0xe4 (old: m_iValueE4)
    NiPoint3 ClosestPoint; // src: XBOX_RETAIL_PDB +0xe8 (old: kClosestPoint)
    NiPoint3 ClosestPointNormal; // src: XBOX_RETAIL_PDB +0xf4 (old: kClosestPointNormal)
    float fCalculatedDamage; // src: XBOX_RETAIL_PDB +0x100 (old: m_fClosestPointScalar)

    float GetEffectiveValue();
    int* FindEntryResultByCategory(int category);

    bool IsDistant();
    float Explosion_GetRadius();
    Proj* FUN_004181e0();
    NiPoint3* FUN_00430830();
    Cell* FUN_008d6f30();
    float BGSProjectile_GetMuzzleFlashDuration();
    void bhkCharacterControllerCinfo_SetAcrobatics(float a);

    void ApplyBlastEffects();
    void* Destroy(unsigned int flags);

    void WriteToSaveBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadGame_009b22c0(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame_009b25b0(void* apLoadGameBuffer);
    void FinishLoadGame_009b2770(BGSLoadFormBuffer* apLoadGameBuffer);
    void RevertBGS_009b2790(BGSLoadFormBuffer* apLoadGameBuffer);

    void ProcessMovement(float afDelta);
    void Update3D(int iUnused);
    void UpdateExplosion();
    void UpdateCastSound();
    void Explosion_TestExplosionUnderWater();
    void Init3D();
    void Explosion_AttachDistant();
    void Explosion_UpdateRadiation();
    unsigned int QUserData();
    void StartSounds();
    unsigned char GetByteAtOffsetD9();
    void SetActorCause_009ac170(ActorCause* apActorCause);
};
