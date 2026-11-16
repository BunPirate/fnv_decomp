#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "BGSImpactData__IMPACT_DATA_DATA.h"

class BGSTextureSet;
class TESSound;



#include "DecalData.h"

// pdb: class BGSImpactData, size 0x78, bases: TESForm, TESModel, 5 members
class BGSImpactData : public TESForm, public TESModel
{
public:
    BGSImpactData__IMPACT_DATA_DATA Data;
    BGSTextureSet* pDecalTextureSet; // src: XBOX_RETAIL_PDB +0x48 (old: m_pDecalTextureSet)
    TESSound* pSound1; // src: XBOX_RETAIL_PDB +0x4c (old: m_pPrimaryImpactSound)
    TESSound* pSound2; // src: XBOX_RETAIL_PDB +0x50 (old: m_pSecondaryImpactSound)
    DecalData DData; // src: XBOX_RETAIL_PDB +0x54 (old: ImpactDecalInfo)

    BGSImpactData();
    virtual ~BGSImpactData();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* apFile);
    virtual void SaveForm(void);
    virtual void InitItem(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void ResetFormData();
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short asSize);
    void SetDecalTextureSet(BGSTextureSet* textureSet);
    void SetSound1(TESSound* sound);
    void SetSound2(TESSound* sound);
    void CopyDecalDataFromTextureSet();
    bool Load(TESFile* apFile);
    BGSTextureSet* GetDecalTextureSet() const;

    void Copy_0058dd10(int apCopy);
    bool IsDifferentFrom(TESForm* apCompare);
    bool IsFlagSet();
    void Save_0058e450();
    void CopyDecalData();
    int GetGlobalValue();
};
