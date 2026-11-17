#pragma once

#include "ImageSpaceModifierInstance.h"
#include "NiAVObject.h"

class TESImageSpaceModifier;

// pdb: class ImageSpaceModifierInstanceForm, size 0x30, bases: ImageSpaceModifierInstance, 5 members
class ImageSpaceModifierInstanceForm : public ImageSpaceModifierInstance
{
  public:
    ImageSpaceModifierInstanceForm();
    virtual ~ImageSpaceModifierInstanceForm();
    ImageSpaceModifierInstanceForm(TESImageSpaceModifier*, float, float, NiAVObject*);
    void* Destroy(unsigned int);

    static void __cdecl Stop(TESImageSpaceModifier*);
    static ImageSpaceModifierInstanceForm* __cdecl Trigger(TESImageSpaceModifier*, float, NiAVObject*);
    static ImageSpaceModifierInstanceForm* TriggerIfNotActive(TESImageSpaceModifier*, float, NiAVObject*);

    TESImageSpaceModifier* GetImageSpaceMod();
    bool IsExpired();
    void Apply();
    void FormatDebugString(char*);
    bool Blend(TESImageSpaceModifier*, float, float, NiAVObject*);
    void SetPad5(float);

    TESImageSpaceModifier* pImageSpaceMod; // src: XBOX_RETAIL_PDB +0x1c (old: m_pPreviousImageSpaceModifier)
    TESImageSpaceModifier* pLastImageSpaceMod; // src: XBOX_RETAIL_PDB +0x20 (old: m_pImageSpaceModifier)
    float fLastStrength; // src: XBOX_RETAIL_PDB +0x24 (old: m_fBlendWeight)
    NiPointer<NiAVObject> spLastTarget; // src: XBOX_RETAIL_PDB +0x28 (old: m_pTargetNode)
    float fTransitionTime; // src: XBOX_RETAIL_PDB +0x2c (old: m_fElapsedTime)
};
