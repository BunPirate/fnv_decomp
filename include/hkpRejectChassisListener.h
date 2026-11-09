#pragma once

#include "hkReferencedObject.h"
#include "hkpPhantomOverlapListener.h"

// pdb: class hkpRejectChassisListener, size 0x10, bases: hkReferencedObject, hkpPhantomOverlapListener, 1 members
class hkpRejectChassisListener : public hkReferencedObject, public hkpPhantomOverlapListener
{
public:
    virtual ~hkpRejectChassisListener();

    // The hkpPhantomOverlapListener vtable pointer occupies pad8.
    void* m_chassis;
};
