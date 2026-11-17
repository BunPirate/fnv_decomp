#pragma once

#include "hkReferencedObject.h"

// pdb: class hkResourceBase, size 0x8, bases: hkReferencedObject, 0 members
class hkResourceBase : public hkReferencedObject
{
public:
    enum Type
    {
        TYPE_RESOURCE = 0,
        TYPE_CONTAINER = 1
    };
};
