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
    GO spMask;
    _D3DLOCKED_RECT Rect;
    int layoutPadding;

    ExtraCellCanopyShadowMask(int aeState, NiRenderedTexture* apTex);
};
