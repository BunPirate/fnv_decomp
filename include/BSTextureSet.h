#pragma once

#include "NiObject.h"
#include "BSShaderProperty.h"

class NiTexture;
template <class T> class NiPointer;

// pdb: class BSTextureSet, size 0x8, bases: NiObject, 0 members
class BSTextureSet : public NiObject
{
  public:
    BSTextureSet();

    virtual void LoadBinary(NiStream& stream) = 0;
    virtual void SaveBinary(NiStream& stream) = 0;

    virtual void GetTexture(BSShaderProperty::TextureTypeEnum textureType, NiPointer<NiTexture>& texture);
    virtual const char* GetTexture(BSShaderProperty::TextureTypeEnum textureType);
    virtual void SetTexture(BSShaderProperty::TextureTypeEnum textureType, const char* textureName);
};
