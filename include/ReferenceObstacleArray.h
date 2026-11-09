#pragma once

#include "NiRefObject.h"

// pdb: class ReferenceObstacleArray, size 0x1c (here 0xc), bases: NiRefObject, 2 members
class ReferenceObstacleArray : public NiRefObject
{
public:
    virtual ~ReferenceObstacleArray();
    void* DestroyIfFlagged(unsigned int flags);

    unsigned int formID;
};
