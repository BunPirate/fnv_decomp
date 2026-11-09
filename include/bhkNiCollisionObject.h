#pragma once

#include "NiCollisionObject.h"

// pdb: class bhkNiCollisionObject, size 0x14 (here 0xc), bases: NiCollisionObject, 2 members
class bhkNiCollisionObject : public NiCollisionObject
{
  public:
    virtual ~bhkNiCollisionObject();

    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
};
