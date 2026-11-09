#pragma once

#include "bhkConvexShape.h"

// pdb: class bhkConvexListShape, size 0x14, bases: bhkConvexShape, 0 members
class bhkConvexListShape : public bhkConvexShape
{
public:
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();

    static NiObject* __cdecl CreateObject();
};
