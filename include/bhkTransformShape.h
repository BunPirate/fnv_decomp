#pragma once

#include "bhkShape.h"

// pdb: class bhkTransformShape, size 0x14, bases: bhkShape, 0 members
class bhkTransformShape : public bhkShape
{
public:
    static NiObject* __cdecl CreateObject();
    void* __thiscall Destroy(unsigned int);
};
