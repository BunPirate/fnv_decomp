#pragma once

#include "NiProperty.h"
#include "NiColor.h"

// pdb: class NiFogProperty, size 0x2c, bases: NiProperty, 3 members
class NiFogProperty : public NiProperty
{
  public:
    NiFogProperty();
    virtual ~NiFogProperty();

    void SetColor(const NiColor& color);

    unsigned short m_uFlags; // src: XBOX_RETAIL_PDB +0x18 (old: m_uiObjectFlags)
    float m_fDepth; // src: XBOX_RETAIL_PDB +0x1c (old: m_fFogDepth)
    NiColor m_kColor; // src: XBOX_RETAIL_PDB +0x20 (old: m_kFogTint)
};
