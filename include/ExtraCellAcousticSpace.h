#pragma once

#include "BSExtraData.h"

struct BGSAcousticSpace;

// pdb: class ExtraCellAcousticSpace, size 0x10, bases: BSExtraData, 1 members
class ExtraCellAcousticSpace : public BSExtraData
{
public:
    ExtraCellAcousticSpace(BGSAcousticSpace*);
    bool Compare(BSExtraData* apCompare) override;
    bool FUN_0040f000(BSExtraData* apCompare);

    BGSAcousticSpace* pSpace;
};
