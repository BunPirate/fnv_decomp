#pragma once

#include "bhkSerializable.h"

class bhkFilter;
class bhkShape;
class hkSerializableCinfo;

// pdb: class bhkWorldObject, size 0x14, bases: bhkSerializable, 1 members
class bhkWorldObject : public bhkSerializable
{
public:
    bhkWorldObject();
    virtual ~bhkWorldObject();

    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();

    bhkFilter GetFilter();
    bhkShape* bhkWorldObject_GetShape();
    bhkFilter bhkWorldObject_GetCollisionFilter();
    void FUN_00c85790();
    void* FUN_0056d4c0(unsigned int flags);
    void* Bipedanim_GetReferenceFlagsOrZero();
    float bhkRigidBody_GetMass();

    hkSerializableCinfo* pInfo;
    unsigned int iFlags;
};
