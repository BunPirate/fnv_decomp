#pragma once

class ContactArray;
class hkpWorld;

// pdb: class hkpPhysicsContextWorldListener, size 0x4, 0 members
class hkpPhysicsContextWorldListener
{
public:
    virtual ~hkpPhysicsContextWorldListener() throw();
    virtual void WorldAddedCallback(hkpWorld* world);
    virtual void WorldRemovedCallback(hkpWorld* world);

    void UpdateFields_00de2980(void*) throw();
};
