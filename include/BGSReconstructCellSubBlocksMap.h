#pragma once

#include "NiTMap.h"

class BGSReconstructCellsMap;

// pdb: class BGSReconstructCellSubBlocksMap, size 0x10, bases: NiTMap<unsigned int, 0 members
class BGSReconstructCellSubBlocksMap : public NiTMap<unsigned int, BGSReconstructCellsMap*>
{
public:
    BGSReconstructCellSubBlocksMap();
    virtual ~BGSReconstructCellSubBlocksMap();
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);
    bool HasCellWithFlag(unsigned int);
};
