#pragma once

#include "SkyObject.h"
#include "NiAVObject.h"

// pdb: class Sun, size 0x2c, bases: SkyObject, 9 members
class Sun : public SkyObject
{
public:
    Sun();
    virtual ~Sun();

    void vfn04();
    void Init(NiNode*);

    NiPointer<NiAVObject> spSunBaseNode;
    NiPointer<NiAVObject> spSunGlareNode;
    NiPointer<NiAVObject> spSunBase;
    NiPointer<NiAVObject> spSunGlare;
    void* pSunGlarePick;
    NiPointer<NiAVObject> spLight;
    float fGlareScale;
    bool bDoOcclusionTests;
    NiPointer<NiAVObject> spSunAccumulator;
};
