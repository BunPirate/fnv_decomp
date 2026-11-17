#pragma once

#include "bhkShape.h"

// pdb: class bhkBvTreeShape, size 0x14, bases: bhkShape, 0 members
class bhkBvTreeShape : public bhkShape
{
public:
    bhkBvTreeShape();

    const char* const* GetArg1Ptr();

};
