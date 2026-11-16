#pragma once

#include "TESBoundObject.h"
#include "TESModelTextureSwap.h"
#include "AddonData.h"

class TESFile;
class TESSound;

// pdb: class BGSAddonNode, size 0x60, bases: TESBoundObject, TESModelTextureSwap, 4 members
class BGSAddonNode : public TESBoundObject, public TESModelTextureSwap
{
public:
    typedef ::_AddonNodeFlags _AddonNodeFlags;
    typedef _AddonNodeFlags::Flags AddonNodeFlags;
    typedef ::AddonData AddonData;

    BGSAddonNode();

    virtual void InitItem(void);
    virtual bool LoadForm(TESFile* file);
    bool Load(TESFile* apFile);

    void ResetFormData();
    bool FUN_00448bf0();
    unsigned int GetIndex();
    void SetIndex(unsigned int index);
    unsigned int GetGrass();
    int FUN_0059e300();
    unsigned short GetShortAtOffset58();
    bool IsMasterParticleSystem() const;

    unsigned int iIndex; // src: XBOX_RETAIL_PDB +0x50 (old: uiIndex)
    TESSound* pSound; // src: XBOX_RETAIL_PDB +0x54 (old: SoundAssetTmp)
    AddonData Data; // src: XBOX_RETAIL_PDB +0x58 (old: kData)
    unsigned int iMasterParticleSystemIndex; // src: XBOX_RETAIL_PDB +0x5c (old: uiParticleSystemIndex)
};
