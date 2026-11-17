#pragma once

#include "bhkConvexShape.h"

// pdb: class bhkTriangleShape, size 0x14, bases: bhkConvexShape, 0 members
class bhkTriangleShape : public bhkConvexShape
{
public:
    static NiObject* __cdecl CreateObject();
};
