#pragma once

#include "BSExtraData.h"
#include "GO.h"

class NiRenderedTexture;

// pdb: structure _D3DLOCKED_RECT, size 0x8 (here 0x4), 2 members
struct _D3DLOCKED_RECT
{
    int dummy;
};

// pdb: class ExtraCellCanopyShadowMask, size 0x1c, bases: BSExtraData, 3 members
class ExtraCellCanopyShadowMask : public BSExtraData
{
public:
    int eState;
    GO spMask; // src: XBOX_RETAIL_PDB +0x10 (old: mGO)
    _D3DLOCKED_RECT Rect; // src: XBOX_RETAIL_PDB +0x14 (old: rect)
    int layoutPadding;

    ExtraCellCanopyShadowMask(int aeState, NiRenderedTexture* apTex);
};
