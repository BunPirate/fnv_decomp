#pragma once

#include "NiProperty.h"

// pdb: class NiMaterialProperty, size 0x4c, bases: NiProperty, 9 members
class NiMaterialProperty : public NiProperty
{
  public:
    NiMaterialProperty();
    virtual void LoadBinary(NiStream& stream);

    int m_iIndex; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)
    int m_spec; // src: XBOX_RETAIL_PDB +0x1c (old: unk1c)
    int unk20;
    int unk24;
    int m_emit; // src: XBOX_RETAIL_PDB +0x28 (old: unk28)
    int unk2c;
    int unk30;
    int m_external_emit; // src: XBOX_RETAIL_PDB +0x34 (old: unk34)
    int m_fShine; // src: XBOX_RETAIL_PDB +0x38 (old: unk38)
    int m_fAlpha; // src: XBOX_RETAIL_PDB +0x3c (old: unk3c)
    int m_fEmitMult; // src: XBOX_RETAIL_PDB +0x40 (old: unk40)
    int m_uiRevID; // src: XBOX_RETAIL_PDB +0x44 (old: unk44)
    int m_pvRendererData; // src: XBOX_RETAIL_PDB +0x48 (old: unk48)
};
