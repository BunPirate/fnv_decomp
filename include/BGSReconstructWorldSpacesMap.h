#pragma once

#include "NiTMap.h"

class BGSReconstructCellBlocksMap;

// pdb: class BGSReconstructWorldSpacesMap, size 0x10, bases: NiTMap<unsigned int, 0 members
class BGSReconstructWorldSpacesMap : public NiTMap<unsigned int, BGSReconstructCellBlocksMap*>
{
public:
    BGSReconstructWorldSpacesMap();
    virtual ~BGSReconstructWorldSpacesMap();
    void* ScalarDeletingDestructor(unsigned int flags);
    void FUN_00841f00();
    void* FUN_00841ed0(unsigned int flags);
};
