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

    NiColorA kColor1;
    NiColorA kColor2;
    NiColorA kColor3;
    float fFadeInPct;
    float fFadeOutPct;
    float fColor1EndPct;
    float fColor2StartPct;
    float fColor2EndPct;
    float fColor3StartPct;
};
