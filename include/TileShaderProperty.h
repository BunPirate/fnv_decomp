#pragma once

#include "BSShaderProperty.h"
#include "BSStringT.h"
#include "NiColorA.h"
#include "NiAVObject.h"

class NiTexture;

// Tile shader property: 0x60-byte base and 0x50-byte tile state.
// pdb: class TileShaderProperty, size 0xb0, bases: BSShaderProperty, 16 members
class TileShaderProperty : public BSShaderProperty
{
  public:
    TileShaderProperty(bool abUseTexturingProperty);                // 0x00bb7c30
    virtual ~TileShaderProperty();

    void CopyMembers(TileShaderProperty* pDest, int arCloneData);
    TileShaderProperty* CreateClone(int arCloneData);
    void LoadBinary_00bb7b60(NiStream* kStream);
    void SaveBinary_00bb7be0(NiStream* kStream);

    void SetTextureImage(NiTexture* texture);      // 0x00bb7a10 replaces m_spTexture (+0x60)
    void SetTileTexture(NiTexture* texture);         // 0x00bb7a10 (same function)
    void SetAlpha(float alpha);                    // 0x00821600 stores +0x78
    void EffectSetting_SetAreaSound(int value);                  // 0x008cc6d0 stores +0x8C
    NiTexture* BGSCameraShot_GetLocationNode();                     // 0x009c8640 returns m_spTexture
    void FUN_007700d0(bool value);                 // 0x007700d0 stores +0x91

    NiPointer<NiTexture> spTileTexture;              // +0x60
    NiPointer<NiTexture> spAlphaMap;             // +0x64
    NiColorA TintColor;                           // src: XBOX_PDB
                                                  // +0x68
    float fAlpha;                                // +0x78
    float fTexScrollX[4];                            // +0x7C zeroed
    int TexClampMode;                                  // +0x8C = 3
    bool bNoBlend;                                 // +0x90
    bool bUseTexScroll;                                 // +0x91
    bool bUseVertexColors;                                 // +0x92
    bool bUseTexturingProperty;                                 // +0x93 = constructor argument
    BSStringT<char> TextureFilename;                       // +0x94
    unsigned int ScissorRect[4];                    // +0x9C not set by the constructor
    bool bUseScissor;                                 // +0xAC

    // Array view used by shader constant uploads; the color retains its constructor.
    __declspec(property(get = GetFogTintData)) float* m_afUnk68;
    float* GetFogTintData()
    {
        return &TintColor.r;
    }
};
