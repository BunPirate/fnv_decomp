#pragma once

#include "Tile.h"
#include "NiAVObject.h"

class NiTexture;
class TileShaderProperty;

// pdb: class TileImage, size 0x48, bases: Tile, 4 members
class TileImage : public Tile
{
  public:
    TileImage();
    virtual ~TileImage();
    virtual void Init(Tile* apParent, const char* apName, Tile* apReplacedTile);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float arg0, float arg1);
    virtual Tile* SetTraitValue(int aiTrait, float afValue, const char* axString);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);

    const char* GetImageTag();
    void UpdateTileImage();
    void SetSourceTexture(NiAVObject* apTexture);
    void SetSourceTexture(NiTexture* apTexture);

    NiNode* GetNiNode();
    using Tile::FUN_00a011b0;
    float FUN_00a011b0(unsigned int trait, int value);
    void Tile_FinalPostParse(unsigned int aiTrait, float afValue);

    static void ReadFloatAttribute(const char* name, float& value, float defaultValue, char* buffer);
    static void ReadTextureAttribute(const char* name, float& value, NiPointer<NiTexture>& texture,
                                     float defaultValue, NiPointer<NiTexture> defaultTexture);

    float fScale;
    NiPointer<NiTexture> spTexture;
    NiPointer<TileShaderProperty> spTSP; // src: XBOX_RETAIL_PDB +0x40 (old: m_spShaderProperty)
    bool bIsScissor; // src: XBOX_RETAIL_PDB +0x44 (old: m_bTextureLoaded)
    unsigned char unk45[3];
};
