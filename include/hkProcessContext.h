#pragma once

#include "InplaceArray6.h"

// RTTI: hkProcessContext has no base classes (Havok 7.1 Common/Visualize/hkProcessContext.h).
// pdb: class hkProcessContext, size 0x50, 3 members
class hkProcessContext
{
public:
    int m_owner; // src: XBOX_RETAIL_PDB +0x4 (old: m_04)
    InplaceArray6 m_monitorStreamBegins; // src: XBOX_RETAIL_PDB +0x8 (old: m_08)
    InplaceArray6 m_monitorStreamEnds; // src: XBOX_RETAIL_PDB +0x2c (old: m_2c)

    hkProcessContext() : m_owner(0)
    {}
    virtual ~hkProcessContext() throw();

    virtual void p04();
    virtual void p08();
};
