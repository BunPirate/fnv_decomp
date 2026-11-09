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
    static ImageSpaceModifierInstanceForm* ImageSpaceModifierInstanceForm_TriggerIfNotActive(TESImageSpaceModifier*, float, NiAVObject*);

    TESImageSpaceModifier* GetImageSpaceMod();
    bool IsExpired();
    void Apply();
    void FormatDebugString(char*);
    bool Blend(TESImageSpaceModifier*, float, float, NiAVObject*);
    void SetPad5(float);

    TESImageSpaceModifier* pImageSpaceMod;
    TESImageSpaceModifier* pLastImageSpaceMod;
    float fLastStrength;
    NiPointer<NiAVObject> spLastTarget;
    float fTransitionTime;
};
