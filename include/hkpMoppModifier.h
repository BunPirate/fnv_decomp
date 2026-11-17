#pragma once

#include "hkBool.h"

// Havok 7.1 hkpMoppModifier: RTTI vftable 0x010e8894, 3 slots (dtor 0x00e00910, two pure virtuals).
// pdb: class hkpMoppModifier, size 0x4, 0 members
class hkpMoppModifier
{
public:
    virtual ~hkpMoppModifier() throw() {}
    virtual hkBool shouldTerminalBeRemoved(unsigned int id, const unsigned int* properties) throw() = 0;
    virtual void addTerminalRemoveInfo(int relativeMoppAddress) throw() = 0;
};
