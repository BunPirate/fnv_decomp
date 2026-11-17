#pragma once

#include "NiAVObject.h"

class NiFixedString;
class NiTexture;

// pdb: class SkyShaderProperty, size 0x90 (here 0x74), bases: BSShaderProperty, 8 members
class SkyShaderProperty
{
public:
    unsigned char propertyData[0x70];
    NiPointer<NiTexture> m_spTexture;

    void SetBaseMap(NiTexture*);
    void SetTextureFile(const NiFixedString&);
    void SetTextureFile(int*);
    void SkyShaderProperty_SetBlendValue(float);
    void NiPhysXProp_SetSnapshot(NiTexture*);
    NiTexture* BGSCameraShot_GetImagespaceTarget();
};
