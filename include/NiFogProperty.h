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

    unsigned short m_uFlags;
    float m_fDepth;
    NiColor m_kColor;
};
