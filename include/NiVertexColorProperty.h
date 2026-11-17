#pragma once

#include "NiProperty.h"

#pragma pack(push, 2)
// pdb: class NiVertexColorProperty, size 0x1c (here 0x1a), bases: NiProperty, 1 members
class NiVertexColorProperty : public NiProperty
{
  public:
    NiVertexColorProperty() throw();

    bool IsVertexColorPropertyEqual(NiObject*);

    unsigned short m_uiObjectFlags;
};
#pragma pack(pop)
