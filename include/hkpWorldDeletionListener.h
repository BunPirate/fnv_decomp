#pragma once

class hkpWorld;

// pdb: class hkpWorldDeletionListener, size 0x4, 0 members
class hkpWorldDeletionListener
{
public:
    virtual ~hkpWorldDeletionListener();
    virtual void WorldDeletedCallback(hkpWorld* world) = 0;
    virtual void worldRemoveAllCallback(hkpWorld* world);
};
