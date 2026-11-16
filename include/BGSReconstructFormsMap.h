#pragma once

#include "NiTMap.h"

class ReconstructFormData;

// pdb: class BGSReconstructFormsMap, size 0x14, bases: NiTMap<unsigned int, 1 members
class BGSReconstructFormsMap : public NiTMap<unsigned int, ReconstructFormData>
{
public:
    int iFlags; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)

    BGSReconstructFormsMap();
    virtual ~BGSReconstructFormsMap();
    void FUN_008411f0();
    void* FUN_008411c0(unsigned int flags);
};
