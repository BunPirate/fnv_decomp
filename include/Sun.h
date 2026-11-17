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

    NiPointer<NiAVObject> spSunBaseNode; // src: XBOX_RETAIL_PDB +0x8 (old: m_pFirstSceneObject)
    NiPointer<NiAVObject> spSunGlareNode; // src: XBOX_RETAIL_PDB +0xc (old: m_pSecondSceneObject)
    NiPointer<NiAVObject> spSunBase; // src: XBOX_RETAIL_PDB +0x10 (old: m_pThirdSceneObject)
    NiPointer<NiAVObject> spSunGlare; // src: XBOX_RETAIL_PDB +0x14 (old: m_pFourthSceneObject)
    void* pSunGlarePick; // src: XBOX_RETAIL_PDB +0x18 (old: m_pSunGlarePick)
    NiPointer<NiAVObject> spLight; // src: XBOX_RETAIL_PDB +0x1c (old: m_pMenuLight)
    float fGlareScale; // src: XBOX_RETAIL_PDB +0x20 (old: m_fSunGlareIntensity)
    bool bDoOcclusionTests;
    NiPointer<NiAVObject> spSunAccumulator; // src: XBOX_RETAIL_PDB +0x28 (old: m_pSunShaderAccumulator)
};
