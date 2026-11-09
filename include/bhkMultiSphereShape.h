#pragma once

#include "bhkSphereRepShape.h"

// pdb: class bhkMultiSphereShape, size 0x14, bases: bhkSphereRepShape, 0 members
class bhkMultiSphereShape : public bhkSphereRepShape
{
public:
    static NiObject* __cdecl CreateObject();
    unsigned int GetInstanceSize();
};
