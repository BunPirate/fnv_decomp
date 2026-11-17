#pragma once

#include "BSTextureSet.h"

// pdb: class BSShaderTextureSet, size 0x40 (here 0x38), bases: BSTextureSet, 1 members
class BSShaderTextureSet : public BSTextureSet
{
  public:
    BSShaderTextureSet();

    virtual void LoadBinary(NiStream& kStream);
    virtual void SaveBinary(NiStream& kStream);
    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);

    const NiRTTI* GetNiRTTI() const;

    char names[48];
};
