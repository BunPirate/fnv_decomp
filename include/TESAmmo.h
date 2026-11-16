#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "BGSMessageIcon.h"
#include "TESValueForm.h"
#include "BGSClipRoundsForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSPickupPutdownSounds.h"
#include "TESScriptableForm.h"
#include "AmmoCharacteristics.h"
#include "AmmoProjectileData.h"

class TESAmmoEffect;

class TESAmmo : public TESBoundObject,
                public TESFullName,
                public TESModelTextureSwap,
                public TESIcon,
                public BGSMessageIcon,
                public TESValueForm,
                public BGSClipRoundsForm,
                public BGSDestructibleObjectForm,
                public BGSPickupPutdownSounds,
                public TESScriptableForm
{
public:
    TESAmmo();
    virtual ~TESAmmo(); // exe 0x00502880

    void ResetFormData();
    virtual void InitItem();
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x1026064 slot 8 = 0x502cd0)
    bool LoadForm(TESFile* apFile);
    unsigned char GetByteAtOffsetB0();
    unsigned char GetFlag() const;
    const char* FUN_00772820();

    AmmoCharacteristics data;
    AmmoProjectileData NVdata; // src: XBOX_RETAIL_PDB +0xb0 (old: m_kProjectileData)
    BSStringT<char> cDesc; // src: XBOX_RETAIL_PDB +0xc4 (old: m_kPrimaryString)
    BSStringT<char> cAbbrev; // src: XBOX_RETAIL_PDB +0xcc (old: m_kSecondaryString)
    BSSimpleList<TESAmmoEffect*> pAmmoEffectList; // src: XBOX_RETAIL_PDB +0xd4 (old: m_kEffects)
};
