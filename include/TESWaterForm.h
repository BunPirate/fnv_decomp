#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESAttackDamageForm.h"
#include "NiAVObject.h"
#include "NiColorA.h"
#include "TESTexture.h"
#include "WaterShaderSettings.h"

class BSRenderedTexture;
class NiTexture;
class NiSourceTexture;
class TESSound;
class SpellItem;
class BGSPlaceableWater;
class BGSSaveFormBuffer;

// pdb: class TESWaterForm, size 0x194, bases: TESForm, TESFullName, TESAttackDamageForm, 29 members
struct TESWaterForm : public TESForm, public TESFullName, public TESAttackDamageForm
{
public:
    TESWaterForm();
    virtual ~TESWaterForm();
    TESWaterForm& operator=(const TESWaterForm&);

    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile*);
    virtual void SaveForm();
    virtual void SaveGameLegacy(unsigned int changedFlags);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    bool Load(TESFile*);
    void SetSpellItem(SpellItem*);
    unsigned int HasTexture();
    const char* GetTexturePath() const;
    void SetTexture(NiSourceTexture* apTexture);
    int __thiscall _FNV_GetFormType();
    WaterShaderSettings* GetShaderSettings();
    WaterShaderSettings* Sky_GetStarsColor();
    bool HasFlag1();
    bool IsDangerous();
    void __thiscall TESWaterForm_SetRemappedWaterForm(int);
    void SetSpellItem_0057f890(SpellItem*);
    unsigned int GetMember();
    const char* GetMaterialName();
    void SetMaterialName(const char*);
    unsigned int GetNoiseTextureNameLength();
    const char* GetNoiseTextureName() const;
    void SetNP(void*);
    void GetNoiseTexture(NiPointer<NiTexture>&);
    float GetOpacity_00580100();
    BGSPlaceableWater* GetPlaceableAutoWater();
    BGSPlaceableWater* GetPlaceableLODWater();
    void SaveWaterForm();
    void Copy_0057fde0(TESForm*);
    bool Compare_0057ff10(TESForm*);
    void SaveGame_005806e0(BGSSaveFormBuffer*);
    void LoadGame_00580730(BGSLoadFormBuffer*);
    void Revert_005807a0(BGSLoadFormBuffer*);

    bool bNeedUpdate; // src: XBOX_RETAIL_PDB +0x2c (old: m_bNeedsUpdate)
    unsigned char layoutPadding2D[3];
    NiPointer<BSRenderedTexture> spNoiseNormalMap; // src: XBOX_RETAIL_PDB +0x30 (old: m_pRenderedTexture)
    NiColorA fTexScroll0; // src: XBOX_RETAIL_PDB +0x34 (old: m_kTextureScrollLayer0)
    NiColorA fTexScroll1; // src: XBOX_RETAIL_PDB +0x44 (old: m_kTextureScrollLayer1)
    NiColorA fTexScroll2; // src: XBOX_RETAIL_PDB +0x54 (old: m_kTextureScrollLayer2)
    TESTexture NoiseTexture; // src: XBOX_RETAIL_PDB +0x64 (old: m_kNoiseMapTexture)
    unsigned char cAlpha; // src: XBOX_RETAIL_PDB +0x70 (old: m_ucOpacity)
    unsigned char cFlags;
    unsigned char layoutPadding72[2];
    BSStringT<char> cMaterialID; // src: XBOX_RETAIL_PDB +0x74 (old: m_kMaterialId)
    TESSound* pWaterSound; // src: XBOX_RETAIL_PDB +0x7c (old: m_pWaterSound)
    TESWaterForm* pRemappedWaterForm; // src: XBOX_RETAIL_PDB +0x80 (old: m_pWaterForm)
    WaterShaderSettings Data;
    TESWaterForm* pWaterWeatherControl[3]; // src: XBOX_RETAIL_PDB +0x148 (old: m_apWaterForms)
    int iCurrentTextureSelect01; // src: XBOX_RETAIL_PDB +0x154 (old: m_iCurrentTextureSelection1)
    int iCurrentTextureSelect02; // src: XBOX_RETAIL_PDB +0x158 (old: m_iCurrentTextureSelection2)
    unsigned int fFrequencyX; // src: XBOX_RETAIL_PDB +0x15c (old: m_uiNoiseFrequencyX)
    unsigned int fFrequencyY; // src: XBOX_RETAIL_PDB +0x160 (old: m_uiNoiseFrequencyY)
    int iOctaves; // src: XBOX_RETAIL_PDB +0x164 (old: m_iNoiseOctaveCount)
    float fAmplitude; // src: XBOX_RETAIL_PDB +0x168 (old: m_fNoiseAmplitude)
    float fLacunarity; // src: XBOX_RETAIL_PDB +0x16c (old: m_fNoiseLacunarity)
    float fBias; // src: XBOX_RETAIL_PDB +0x170 (old: fSideOffset)
    float fGain; // src: XBOX_RETAIL_PDB +0x174 (old: m_fDistanceScale)
    SpellItem* pSpellItem; // src: XBOX_RETAIL_PDB +0x178 (old: m_pWaterSpell)
    NiPointer<NiTexture> spNoiseTexture; // src: XBOX_RETAIL_PDB +0x17c (old: m_kNoiseTextureData)
    BGSPlaceableWater* pPlaceableAutoWater; // src: XBOX_RETAIL_PDB +0x180 (old: m_pPlaceableAutoWater)
    BGSPlaceableWater* pPlaceableLODWater; // src: XBOX_RETAIL_PDB +0x184 (old: m_pPlaceableWater)
    int iRadiationDamage; // src: XBOX_RETAIL_PDB +0x188 (old: m_iRadiationMagnitude)
    int iHealthRestoration; // src: XBOX_RETAIL_PDB +0x18c (old: m_iHealthMagnitude)
    bool bResetNoiseTexture; // src: XBOX_RETAIL_PDB +0x190 (old: m_bResetNoiseTextures)
    unsigned char layoutPadding191[3];
};
