#pragma once

#include "NiObject.h"

class ScreenReference;

// pdb: class NiScreenPolygon, size 0x1c, bases: NiObject, 5 members
class NiScreenPolygon : public NiObject
{
  public:
    ScreenReference* m_spPropertyState; // src: XBOX_RETAIL_PDB +0x8 (old: unk08)
    ScreenReference* m_usVertices; // src: XBOX_RETAIL_PDB +0xc (old: unk0C)
    ScreenReference* m_pkVertex; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    ScreenReference* m_pkTexture; // src: XBOX_RETAIL_PDB +0x14 (old: unk14)
    ScreenReference* m_pkColor; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)

    NiScreenPolygon(const NiScreenPolygon& other);
    NiScreenPolygon& operator=(const NiScreenPolygon& other);
};
