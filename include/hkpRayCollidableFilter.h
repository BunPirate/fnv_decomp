#pragma once

#include "hkBool.h"

class WorldRayCastInput;
class hkpCollidable;
struct ClassMemberDescriptor;

// pdb: class hkpRayCollidableFilter, size 0x4, 0 members
class hkpRayCollidableFilter
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkpRayCollidableFilter();
    virtual hkBool IsCollisionEnabled(const WorldRayCastInput& input, const hkpCollidable& collidable) const = 0;
};
