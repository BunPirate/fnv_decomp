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
    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void Unk_21(BGSLoadFormBuffer* arg);
    virtual void Update(float delta);
    virtual void Initialize();

    float fAge;
    float fLifetime;
    float fBuildTime;
    float fRadius;
    float fImageSpaceRadius;
    float fWeaponCondition;
    NiPointer<bhkSimpleShapePhantom> spPhantom;
    BSSimpleList<ExplosionParameters*> TargetList;
    BSSoundHandle Sound1[2];
    NiPointer<NiLight> spLight;
    TESObjectREFR* pOwner;
    TESObjectREFR* pExplodedRef;
    NiPointer<ActorCause> spActorCause;
    bool bDecalsPlaced;
    bool bTargetsFound;
    bool bTargetsProcessed;
    bool bForcesApplied;
    bool bIgnoreImageSpaceSwap;
    bool bUnderWater;
    NonActorMagicCaster* pCaster;
    TESObjectWEAP* pWeaponSource;
    int iFrameCount;
    NiPoint3 ClosestPoint;
    NiPoint3 ClosestPointNormal;
    float fCalculatedDamage;

    float GetEffectiveValue();
    int* FindEntryResultByCategory(int category);

    bool Explosion_IsDistant();
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
