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

    bool bNeedUpdate;
    unsigned char layoutPadding2D[3];
    NiPointer<BSRenderedTexture> spNoiseNormalMap;
    NiColorA fTexScroll0;
    NiColorA fTexScroll1;
    NiColorA fTexScroll2;
    TESTexture NoiseTexture;
    unsigned char cAlpha;
    unsigned char cFlags;
    unsigned char layoutPadding72[2];
    BSStringT<char> cMaterialID;
    TESSound* pWaterSound;
    TESWaterForm* pRemappedWaterForm;
    WaterShaderSettings Data;
    TESWaterForm* pWaterWeatherControl[3];
    int iCurrentTextureSelect01;
    int iCurrentTextureSelect02;
    unsigned int fFrequencyX;
    unsigned int fFrequencyY;
    int iOctaves;
    float fAmplitude;
    float fLacunarity;
    float fBias;
    float fGain;
    SpellItem* pSpellItem;
    NiPointer<NiTexture> spNoiseTexture;
    BGSPlaceableWater* pPlaceableAutoWater;
    BGSPlaceableWater* pPlaceableLODWater;
    int iRadiationDamage;
    int iHealthRestoration;
    bool bResetNoiseTexture;
    unsigned char layoutPadding191[3];
};
