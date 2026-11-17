#pragma once

#include "hkpContactListener.h"

// The destructor is user-declared: 0x006234d0 stores the bhkContactListener vftable (0x0104dd5c)
// before calling ~hkpContactListener.
// pdb: class bhkContactListener, size 0x4, bases: hkpContactListener, 0 members
class bhkContactListener : public hkpContactListener
{
public:
    virtual ~bhkContactListener();
};
