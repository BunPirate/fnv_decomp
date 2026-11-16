#pragma once

#include "NiTMap.h"

class BGSReconstructCellSubBlocksMap;

// pdb: class BGSReconstructCellBlocksMap, size 0x18, bases: NiTMap<unsigned int, 2 members
class BGSReconstructCellBlocksMap : public NiTMap<unsigned int, BGSReconstructCellSubBlocksMap*>
{
public:
    int pPersistentCell; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    bool bExteriors; // src: XBOX_RETAIL_PDB +0x14 (old: unk14)

    BGSReconstructCellBlocksMap(bool abExteriors);
    ~BGSReconstructCellBlocksMap();
    void* ScalarDeletingDestructor(unsigned int flags);

    void FUN_00841a60();
    void* FUN_00841a30(unsigned int flags);
};
