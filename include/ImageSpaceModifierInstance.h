#pragma once

#include "NiObject.h"
#include "NiAVObject.h"

class ImageSpaceModifierInstanceForm;

// pdb: class ImageSpaceModifierInstance, size 0x1c, bases: NiObject, 5 members
class ImageSpaceModifierInstance : public NiObject
{
  public:
    ImageSpaceModifierInstance(float, float, NiAVObject*);
    virtual ~ImageSpaceModifierInstance();

    // Slots 0 through 34 are inherited from NiObject.
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual ImageSpaceModifierInstanceForm* GetInstanceForm();
    virtual void vf38(char* apBuffer);

    static float GetTime();
    bool IsFlagSet();
    void __thiscall PlayerCharacter_StopVatsImageSpace();

    bool bIsWeather; // src: XBOX_RETAIL_PDB +0x8 (old: m_bHasBeenApplied)
    unsigned char layoutPadding9[3];
    float fStrength; // src: XBOX_RETAIL_PDB +0xc (old: fWaterLevelItem)
    NiPointer<NiAVObject> spTarget; // src: XBOX_RETAIL_PDB +0x10 (old: m_spTargetObject)
    float fStartTime; // src: XBOX_RETAIL_PDB +0x14 (old: m_fStartTime)
    unsigned int iFlags;
};
