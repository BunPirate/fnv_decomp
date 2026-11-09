#pragma once

#include "hkBool.h"

class hkpCollidable;
struct ClassMemberDescriptor;

// pdb: class hkpCollidableCollidableFilter, size 0x4, 0 members
class hkpCollidableCollidableFilter
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkpCollidableCollidableFilter();
    virtual hkBool IsCollisionEnabled(const hkpCollidable& a, const hkpCollidable& b) const = 0;
    bool* IsCollisionEnabled(bool* r, const hkpCollidable& a, const hkpCollidable& b) const;
};
