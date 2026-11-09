#pragma once

#include "NiProperty.h"

// pdb: class NiMaterialProperty, size 0x4c, bases: NiProperty, 9 members
class NiMaterialProperty : public NiProperty
{
  public:
    NiMaterialProperty();
    virtual void LoadBinary(NiStream& stream);

    int m_iIndex;
    int m_spec;
    int unk20;
    int unk24;
    int m_emit;
    int unk2c;
    int unk30;
    int m_external_emit;
    int m_fShine;
    int m_fAlpha;
    int m_fEmitMult;
    int m_uiRevID;
    int m_pvRendererData;
};
