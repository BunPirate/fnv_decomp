#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "TESEnchantableForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "TESHealthForm.h"
#include "TESAttackDamageForm.h"
#include "BGSAmmoForm.h"
#include "BGSClipRoundsForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSRepairItemList.h"
#include "BGSEquipType.h"
#include "BGSPreloadable.h"
#include "BGSMessageIcon.h"
#include "BGSBipedModelList.h"
#include "BGSPickupPutdownSounds.h"
#include "TESModel.h"
#include "WeaponProperties.h"
#include "WeaponCriticalData.h"
#include "WeaponVATSData.h"

class Actor;
class BGSImpactDataSet;
class BGSProjectile;
class PlayerCharacter;
class QueuedFile;
class SpellItem;
class TESAmmo;
class TESEffectShader;
class TESObjectIMOD;
class TESObjectSTAT;
class TESSound;

class TESObjectWEAP : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESAttackDamageForm,
                      public BGSAmmoForm,
                      public BGSClipRoundsForm,
                      public BGSDestructibleObjectForm,
                      public BGSRepairItemList,
                      public BGSEquipType,
                      public BGSPreloadable,
                      public BGSMessageIcon,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
public:
    enum SOUND_LEVEL;

    TESObjectWEAP();
    virtual ~TESObjectWEAP();
    virtual void ClearData();
    virtual void InitItem();

    void ResetFormData();
    bool Load(TESFile* apFile);
    // TESForm vtable slot 8 (vftable 0x102c51c slot 8 = 0x51f630)
    bool LoadForm(TESFile* apFile);
    void QueueResourceLoad(int priority, QueuedFile* file, bool flag);
    unsigned short GetShortAtOffset1C0();
    float GetField14C();
    float GetField150Float();
    float GetField154();
    bool IsRangedWeapon();
    bool GetIsAutomaticWeapon();
    unsigned int FUN_0051f5f0(); // 0x0051f5f0
    bool GetBurstShot();
    int GetClipRounds(bool bModValue);
    TESAmmo* GetCurrentAmmo(Actor* apWeaponHolder);
    BGSProjectile* GetProjectileData(Actor* apWeaponHolder);
    float GetProjectileData();
    unsigned char GetDamageForActor(bool bUseModValue, bool bIgnoreAmmo, Actor* apWeaponHolder);
    void SetModItem(unsigned int slot, TESObjectIMOD* item);
    void SetModItem(unsigned char slot, TESObjectIMOD* item);
    int GetWeaponType() const;
    int GetWeaponType();
    int GetCombatWeaponType();
    int TESObjectWEAP_GetCombatWeaponType();
    int GetReloadAnim(bool modded);
    int GetFlaggedValue(unsigned char bModValue);
    int GetField19C();
    bool GetHideBackpack();
    bool GetHasScope();
    bool GetHasModScope();
    TESModel* GetWeaponModel();
    TESModel* GetModTESModel(unsigned char mods, bool flag);
    TESSound* GetField238();
    TESSound* GetField23C();
    void Fire(TESObjectREFR* apSource);
    bool IsRanged();
    bool IsMelee();
    int GetModdedValue(bool flag);
    unsigned char GetAmmoPerShot();
    bool IsPlayable();
    void SetByteAtOffsetF4(int value);
    int GetUnk15C();
    ActorValue__Index GetResistance();
    float GetModdedWeaponValue(WEAPON_MOD_EFFECT effect, unsigned char value);
    float GetModdedWeaponValue(WEAPON_MOD_EFFECT effect, unsigned char value) const;
    SpellItem* GetField1CC();
    SpellItem* GetVATSSpecialEffect();
    TESEffectShader* GetScopeEffect();
    void SetEffectShader(TESEffectShader* shader);
    void SetNPCsUseAmmo(bool value);
    void SetModObject(unsigned char slot, TESObjectSTAT* object);
    TESSound* GetAttackSound(bool modded);
    void SetAttackSound(TESSound* sound);
    void SetDistantAttackSound(TESSound* sound);
    void SetModAttackSound(TESSound* sound);
    TESSound* GetModDistantAttackSound();
    void SetAttackFailSound(TESSound* sound);
    void SetMeleeBlockSound(TESSound* sound);
    void SetIdleSound(TESSound* sound);
    void SetEquipSound(TESSound* sound);
    void SetUnequipSound(TESSound* sound);
    void Set1stPersonObject(TESObjectSTAT* object);
    void SetAttackSound2(TESSound* sound);
    void SetModAttackSound2(TESSound* sound);
    void SetModDistantAttackSound2(TESSound* sound);
    void SetImpactDataSet(BGSImpactDataSet* dataSet);
    float GetWeightForForm(bool modded);

    int FUN_00446390();
    TESBoundObject* TESObjectWEAP_GetCurrentAmmo(PlayerCharacter* apWeaponHolder);
    void* TESObjectWEAP_GetCurrentAmmo(int apWeaponHolder);
    int FUN_0051e2a0(unsigned char value);
    float GetAttackSpeed(bool modded);
    float GetAmmoRegenRate(bool modded);
    float GetAmmoRegenRate(int value);
    int FUN_00525b20(int bUseModValue, int bIgnoreAmmo, int apWeaponHolder);
    TESModel* TESCasino_GetData();
    bool FUN_004c94d0();
    bool IsTwoHandedWeapon();
    bool TESObjectWEAP_IsThrownWeapon();
    bool FUN_004ad030();
    bool TESObjectWEAP_IsEmbeddedWeapon();
    void TESCreature_SetMaterialType(BGSProjectile* projectile);
    void UpdateState_0051f4f0(SpellItem* effect);
    void TESObjectWEAP_SetVATSEffect(SpellItem* effect);
    void TESObjectWEAP_SetNumProjectiles(unsigned char value);
    void TESObjectWEAP_SetAttackLoop(TESSound* sound);

    WeaponProperties data;
    WeaponCriticalData criticalData; // src: XBOX_RETAIL_PDB +0x1c0 (old: m_kCriticalData)
    TESModel ShellCasingModel; // src: XBOX_RETAIL_PDB +0x1d0 (old: m_kModel)
    TESModel ScopeModel; // src: XBOX_RETAIL_PDB +0x1e8 (old: m_kModel1stPerson)
    TESModel WorldModel; // src: XBOX_RETAIL_PDB +0x200 (old: m_kModel3rdPerson)
    TESEffectShader* pScopeEffect; // src: XBOX_RETAIL_PDB +0x218 (old: m_pWeaponEffectShader)
    TESSound* pAttackSound; // src: XBOX_RETAIL_PDB +0x21c (old: m_pWeaponSound1)
    TESSound* pAttackSound2; // src: XBOX_RETAIL_PDB +0x220 (old: m_pWeaponSound2)
    TESSound* pAttackSound2D; // src: XBOX_RETAIL_PDB +0x224 (old: m_pWeaponSound3)
    TESSound* pAttackLoop; // src: XBOX_RETAIL_PDB +0x228 (old: m_pWeaponSound4)
    TESSound* pAttackFailSound; // src: XBOX_RETAIL_PDB +0x22c (old: m_pWeaponSound5)
    TESSound* pMeleeBlockSound; // src: XBOX_RETAIL_PDB +0x230 (old: m_pWeaponSound6)
    TESSound* pIdleSound; // src: XBOX_RETAIL_PDB +0x234 (old: m_pWeaponSound7)
    TESSound* pEquipSound; // src: XBOX_RETAIL_PDB +0x238 (old: m_pWeaponSound8)
    TESSound* pUnEquipSound; // src: XBOX_RETAIL_PDB +0x23c (old: m_pWeaponUnequipSound)
    TESSound* pModSilencedSound; // src: XBOX_RETAIL_PDB +0x240 (old: m_pWeaponEquipSound)
    TESSound* pModSilencedSound2; // src: XBOX_RETAIL_PDB +0x244 (old: m_pWeaponPickupSound)
    TESSound* pModSilencedSound2D; // src: XBOX_RETAIL_PDB +0x248 (old: m_pWeaponDropSound)
    BGSImpactDataSet* pImpactDataSet; // src: XBOX_RETAIL_PDB +0x24c (old: m_pImpactDataSet)
    TESObjectSTAT* p1stPersonObject;
    TESObjectSTAT* p1stPersonMod1Object;
    TESObjectSTAT* p1stPersonMod2Object;
    TESObjectSTAT* p1stPersonMod3Object;
    TESObjectSTAT* p1stPersonMod12Object;
    TESObjectSTAT* p1stPersonMod23Object;
    TESObjectSTAT* p1stPersonMod13Object;
    TESObjectSTAT* p1stPersonMod123Object;
    TESModelTextureSwap WorldModelMod1; // src: XBOX_RETAIL_PDB +0x270 (old: m_kWeaponModTextureSwap1)
    TESModelTextureSwap WorldModelMod2; // src: XBOX_RETAIL_PDB +0x290 (old: m_kWeaponModTextureSwap2)
    TESModelTextureSwap WorldModelMod3; // src: XBOX_RETAIL_PDB +0x2b0 (old: m_kWeaponModTextureSwap3)
    TESModelTextureSwap WorldModelMod12; // src: XBOX_RETAIL_PDB +0x2d0 (old: m_kWeaponModTextureSwap4)
    TESModelTextureSwap WorldModelMod13; // src: XBOX_RETAIL_PDB +0x2f0 (old: m_kWeaponModTextureSwap5)
    TESModelTextureSwap WorldModelMod23; // src: XBOX_RETAIL_PDB +0x310 (old: m_kWeaponModTextureSwap6)
    TESModelTextureSwap WorldModelMod123; // src: XBOX_RETAIL_PDB +0x330 (old: m_kWeaponModTextureSwap7)
    TESObjectIMOD* pModObjectOne; // src: XBOX_RETAIL_PDB +0x350 (old: m_pWeaponMod1)
    TESObjectIMOD* pModObjectTwo; // src: XBOX_RETAIL_PDB +0x354 (old: m_pWeaponMod2)
    TESObjectIMOD* pModObjectThree; // src: XBOX_RETAIL_PDB +0x358 (old: m_pWeaponMod3)
    BSStringT<char> EmbeddedWeaponNode; // src: XBOX_RETAIL_PDB +0x35c (old: m_kEmbeddedWeaponNodeName)
    SOUND_LEVEL eSoundLevel; // src: XBOX_RETAIL_PDB +0x364 (old: m_eSoundLevel)
    BSStringT<char> VATSAttackName;
    WeaponVATSData specialVATSData; // src: XBOX_RETAIL_PDB +0x370 (old: m_kVATSData)
    bool bIsLoopingReload; // src: XBOX_RETAIL_PDB +0x384 (old: m_bHasReloadAnimation)
    unsigned char layoutPadding385[3];
};
