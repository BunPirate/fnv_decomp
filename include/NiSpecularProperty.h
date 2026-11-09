#pragma once

#include "NiProperty.h"

// pdb: class NiSpecularProperty, size 0x1c, bases: NiProperty, 1 members
class NiSpecularProperty : public NiProperty
{
  public:
    NiSpecularProperty() throw();

    virtual NiObject* MakeClone(CloningProcess& cloning);

    unsigned short m_uFlags;
};
