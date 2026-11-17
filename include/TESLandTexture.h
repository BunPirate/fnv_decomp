#pragma once

#include "TESForm.h"
#include "TextureParameterBlock.h"
#include "MagicTarget.h"

class BGSTextureSet;
class BSAudio;
class TESGrass;

// pdb: class TESLandTexture, size 0x28, bases: TESForm, 4 members
class TESLandTexture : public TESForm
{
public:
    BGSTextureSet* pTextureSet; // src: XBOX_RETAIL_PDB +0x18 (old: m_pTextureSet)
    TextureParameterBlock HavokData; // src: XBOX_RETAIL_PDB +0x1c (old: LandTextureParameters)
    unsigned char cSpecularExponent; // src: XBOX_RETAIL_PDB +0x1f (old: m_ucTextureTiling)
    BSSimpleList<TESGrass*> TextureGrassList; // src: XBOX_RETAIL_PDB +0x20 (old: m_kGrassList)

    TESLandTexture();
    virtual ~TESLandTexture();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* apCopy);
    virtual bool Compare(TESForm* apCompare);

    void* Delete(unsigned int flags);
    BGSTextureSet* GetTextureSet();
    void ResetFormData();
    bool Load(TESFile* apFile);
    BSSimpleList<TESGrass*>* GetGrassList();
    void AddLandRef(int aePriority, void* apParent);
    void v0();
    void v00();
    static BSAudio* GetSoundSystem();
};
