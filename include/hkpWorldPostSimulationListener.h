#pragma once

class hkpWorld;
class hkpEntity;

// pdb: class hkpWorldPostSimulationListener, size 0x4, 0 members
class hkpWorldPostSimulationListener
{
public:
    virtual ~hkpWorldPostSimulationListener() throw();
    virtual void postSimulationCallback(hkpWorld* world) = 0;
    virtual void EntityRemovalCallback(hkpEntity* entity);
};
