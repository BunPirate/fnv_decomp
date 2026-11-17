#pragma once

class hkpPhantom;

// pdb: class hkpPhantomListener, size 0x4, 0 members
class hkpPhantomListener
{
public:
    virtual ~hkpPhantomListener();
    virtual void PhantomAddedCallback(hkpPhantom*);
    virtual void PhantomRemovedCallback(hkpPhantom*);
    virtual void phantomShapeSetCallback(hkpPhantom*);
    virtual void phantomDeletedCallback(hkpPhantom*);
};
