#pragma once

#include "BSExtraData.h"
#include "TwoIntRecord.h"

// pdb: class ExtraNavMeshPortal, size 0x14, bases: BSExtraData, 1 members
class ExtraNavMeshPortal : public BSExtraData
{
public:
    ExtraNavMeshPortal(TwoIntRecord);

    TwoIntRecord Portal;
};
