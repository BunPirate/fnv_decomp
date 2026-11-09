#pragma once

#include "BSExtraData.h"

// pdb: class ExtraCount, size 0x10, bases: BSExtraData, 1 members
class ExtraCount : public BSExtraData
{
public:
    short iCount;
    unsigned char layoutPaddingE[2];

    virtual ~ExtraCount();

    ExtraCount();
    ExtraCount(short aCount);
    bool Compare_00431c50(BSExtraData* compare);
};
