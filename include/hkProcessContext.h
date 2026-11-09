#pragma once

#include "InplaceArray6.h"

// RTTI: hkProcessContext has no base classes (Havok 7.1 Common/Visualize/hkProcessContext.h).
// pdb: class hkProcessContext, size 0x50, 3 members
class hkProcessContext
{
public:
    int m_owner;
    InplaceArray6 m_monitorStreamBegins;
    InplaceArray6 m_monitorStreamEnds;

    hkProcessContext() : m_owner(0)
    {}
    virtual ~hkProcessContext() throw();

    virtual void p04();
    virtual void p08();
};
