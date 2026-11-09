#pragma once

#include "bhkHeightFieldShape.h"

// pdb: class bhkPlaneShape, size 0x14, bases: bhkHeightFieldShape, 0 members
class bhkPlaneShape : public bhkHeightFieldShape
{
public:
    static NiObject* __cdecl CreateObject();
};
