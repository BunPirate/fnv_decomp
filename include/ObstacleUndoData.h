#pragma once

#include "NiRefObject.h"

// pdb: class ObstacleUndoData, size 0x70 (here 0x8), bases: NiRefObject, 11 members
class ObstacleUndoData : public NiRefObject
{
public:
    virtual ~ObstacleUndoData();
    void* Destroy(unsigned int flags);
};
