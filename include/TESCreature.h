#pragma once

#include "TESActorBase.h"
#include "TESAttackDamageForm.h"
#include "TESModelList.h"
#include "TypedData.h"
#include "BaseProcess.h"

class CreatureSounds;
class BGSBodyPartData;
class BGSImpactDataSet;
class BGSListForm;
class TESCombatStyle;
class SoundOps;
enum BGSImpactDataSet__IMPACT_MATERIAL_TYPE;

// pdb: class TESCreature, size 0x160, bases: TESActorBase, TESAttackDamageForm, TESModelList, 15 members
class TESCreature : public TESActorBase, public TESAttackDamageForm, public TESModelList
{
public:
    TESCreature();
    virtual ~TESCreature();
    TESCreature& operator=(const TESCreature& other);

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* apFile);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* form);
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void SaveGameLegacy(unsigned int aiFlags);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void LoadGameLegacy(unsigned int changedFlags, unsigned int currentFlags);
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual BGSBodyPartData* GetBodyPartData() const;
    virtual void SetBodyPartData(BGSBodyPartData* bodyPartData);
    virtual TESCombatStyle* GetCombatStyle() const;
    virtual void SetCombatStyle(TESCombatStyle* style);
    virtual void SetActorValueF(ActorValue::Index index, float value);
    virtual void SetActorValueI(ActorValue::Index index, int value);
    virtual void ModActorValueF(ActorValue::Index index, float value);
    virtual void ModActorValueI(ActorValue::Index index, int value);
    virtual void CopyFromTemplateForm(TESActorBase* apForceTemplate);

    void ResetFormData();
    CreatureSounds* GetCreatureSounds();
    CreatureSounds* CreateCreatureSounds();
    TESCreature* GetSoundCreature();
    void SetSoundCreature(TESCreature* apCreature);
    BGSImpactDataSet* GetImpactDataSet();
    void SetImpactDataSet(BGSImpactDataSet* impactDataSet);
    BGSListForm* GetField158();
    unsigned char GetCombatSkill();
    void SetByteAt12D(unsigned char value);
    void SetCreatureType(unsigned char value);
    signed char GetCreatureType() const;
    signed char GetCreatureType();
    void SetBoltGrowWidth(float value);
    void SetBoltSmallWidth(float value);
    const void* GetOffset12C();
    void InitWornForm(Actor* actor, bool weapon, bool armor, bool update);
    NiNode* Create3DModel(TESObjectREFR* apRef);
    void UpdateModel3D(TESObjectREFR* reference, bool weapon, bool armor, bool update);

    bool Compare_005f9b90(TESForm* apCompare);
    bool TESForm_CompareAllComponents(TESCreature* apCompare);
    unsigned char ShadowSceneNode_GetDisableLightUpdate();
    float TESObjectWEAP_GetShotsPerSecond();
    float TESEffectShader_GetAddOnScaleStart();
    float GetFootWeight();
    SOUND_LEVEL BGSSaveLoadFile_GetFilePosition();
    void TESBoundObject_CopyBoundData(TESCreature* other);
    unsigned char FUN_0059f3a0();
    void SetTypeAtOffset12C(unsigned char value);
    void FUN_005f8bd0(BGSListForm* list);
    void FUN_00507780(float value);
    SoundOps* PickCreatureSound(int type);
    void* Return_0();
    bool IsHumanoidCreature() const;
    void FUN_005f9e00(Actor* actor, bool weapon, bool armor, bool update);

    union
    {
        TESCreature* m_pCreature;
        CreatureSounds* m_pCreatureSounds;
    };
    union
    {
        TypedData Data;
        struct
        {
            unsigned char dataPadding;
            unsigned char m_ucField00;
            unsigned char m_ucField01;
            unsigned char m_ucField02;
        };
    };
    unsigned char cHandReach; // src: XBOX_RETAIL_PDB +0x130 (old: m_ucCreatureType)
    unsigned char layoutPadding131[3];
    float fTurnSpeed; // src: XBOX_RETAIL_PDB +0x134 (old: m_fFirstCreatureStat)
    float fFootWeight; // src: XBOX_RETAIL_PDB +0x138 (old: m_fSecondCreatureStat)
    float fBaseScale; // src: XBOX_RETAIL_PDB +0x13c (old: m_fThirdCreatureStatCur)
    TESCombatStyle* pCombatStyle; // src: XBOX_RETAIL_PDB +0x140 (old: m_pCombatStyle)
    BGSBodyPartData* pBodyPartData; // src: XBOX_RETAIL_PDB +0x144 (old: m_pBodyPartDataCur)
    BGSImpactDataSet__IMPACT_MATERIAL_TYPE eBloodImpactMaterial; // src: XBOX_RETAIL_PDB +0x148 (old: m_eImpactMaterial)
    BGSImpactDataSet* pImpactDataSet; // src: XBOX_RETAIL_PDB +0x14c (old: m_pImpactDataSet)
    bool bEmbeddedWeaponChecked; // src: XBOX_RETAIL_PDB +0x150 (old: m_bHasImpactDataSet)
    unsigned char layoutPadding151[3];
    SOUND_LEVEL eSoundLevel; // src: XBOX_RETAIL_PDB +0x154 (old: m_eSoundLevel)
    BGSListForm* pWeaponList; // src: XBOX_RETAIL_PDB +0x158 (old: m_pCreatureListForm)
    char cCanUseHandToHand; // src: XBOX_RETAIL_PDB +0x15c (old: m_cCreatureDataFlag)
    unsigned char layoutPadding15D[3];
};
