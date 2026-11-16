#pragma once

#include "NiPSysModifier.h"
#include "NiColorA.h"

class ViewerStrings;

// pdb: class BSPSysSimpleColorModifier, size 0x60, bases: NiPSysModifier, 9 members
class BSPSysSimpleColorModifier : public NiPSysModifier
{
public:
    virtual void LinkObject(NiStream& stream);
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    void LinkObject_00c60910(NiStream& stream);
    void GetViewerStrings_00c60b20(ViewerStrings* pkStrings);

    NiColorA kColor1; // src: XBOX_RETAIL_PDB +0x18 (old: color1)
    NiColorA kColor2; // src: XBOX_RETAIL_PDB +0x28 (old: color2)
    NiColorA kColor3; // src: XBOX_RETAIL_PDB +0x38 (old: color3)
    float fFadeInPct; // src: XBOX_RETAIL_PDB +0x48 (old: fadeIn)
    float fFadeOutPct; // src: XBOX_RETAIL_PDB +0x4c (old: fadeOut)
    float fColor1EndPct; // src: XBOX_RETAIL_PDB +0x50 (old: color1End)
    float fColor2StartPct; // src: XBOX_RETAIL_PDB +0x54 (old: color2Start)
    float fColor2EndPct; // src: XBOX_RETAIL_PDB +0x58 (old: color2End)
    float fColor3StartPct; // src: XBOX_RETAIL_PDB +0x5c (old: color3Start)
};
