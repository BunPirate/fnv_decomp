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
    BGSTextureSet* pTextureSet;
    TextureParameterBlock HavokData;
    unsigned char cSpecularExponent;
    BSSimpleList<TESGrass*> TextureGrassList;

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
