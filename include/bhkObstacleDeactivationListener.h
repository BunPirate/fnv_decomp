#pragma once

#include "hkpEntityActivationListener.h"

class hkpEntity;

// RTTI vftable 0x0106c3b4: implicit destructor (deleting form 0x006c00d0, destructor 0x006c0170,
// which stores no vftable), entityDeactivatedCallback 0x006c0190, entityActivatedCallback 0x006c01d0.
// pdb: class bhkObstacleDeactivationListener, size 0x4, bases: hkpEntityActivationListener, 0 members
class bhkObstacleDeactivationListener : public hkpEntityActivationListener
{
public:
    virtual void entityDeactivatedCallback(hkpEntity*);
    virtual void entityActivatedCallback(hkpEntity*);
};
