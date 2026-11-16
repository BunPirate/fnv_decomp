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

    NiPointer<NiTexture> spTileTexture;              // +0x60 // src: XBOX_RETAIL_PDB +0x60 (old: m_spTexture)
    NiPointer<NiTexture> spAlphaMap;             // +0x64 // src: XBOX_RETAIL_PDB +0x64 (old: m_spTexture2)
    NiColorA TintColor; // src: XBOX_RETAIL_PDB +0x68 (old: m_kFogTint) (was XBOX_PDB)
                                                  // +0x68
    float fAlpha;                                // +0x78 // src: XBOX_RETAIL_PDB +0x78 (old: m_fAlpha)
    float fTexScrollX[4];                            // +0x7C zeroed // src: XBOX_RETAIL_PDB +0x7c (old: m_afUnk7C)
    int TexClampMode;                                  // +0x8C = 3 // src: XBOX_RETAIL_PDB +0x8c (old: m_iUnk8C)
    bool bNoBlend;                                 // +0x90 // src: XBOX_RETAIL_PDB +0x90 (old: m_bUnk90)
    bool bUseTexScroll;                                 // +0x91 // src: XBOX_RETAIL_PDB +0x91 (old: m_bUnk91)
    bool bUseVertexColors;                                 // +0x92 // src: XBOX_RETAIL_PDB +0x92 (old: m_bUnk92)
    bool bUseTexturingProperty;                                 // +0x93 = constructor argument // src: XBOX_RETAIL_PDB +0x93 (old: m_bUnk93)
    BSStringT<char> TextureFilename;                       // +0x94 // src: XBOX_RETAIL_PDB +0x94 (old: m_kName)
    unsigned int ScissorRect[4];                    // +0x9C not set by the constructor // src: XBOX_RETAIL_PDB +0x9c (old: m_auiUnk9C)
    bool bUseScissor;                                 // +0xAC // src: XBOX_RETAIL_PDB +0xac (old: m_bUnkAC)

    // Array view used by shader constant uploads; the color retains its constructor.
    __declspec(property(get = GetFogTintData)) float* m_afUnk68;
    float* GetFogTintData()
    {
        return &TintColor.r;
    }
};
