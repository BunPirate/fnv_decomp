#pragma once

#include "BSExtraData.h"

class TESObjectCELL;

// pdb: class ExtraPersistentCell, size 0x10, bases: BSExtraData, 1 members
class ExtraPersistentCell : public BSExtraData
{
public:
    virtual ~ExtraPersistentCell();

    ExtraPersistentCell(TESObjectCELL* aCell);

    TESObjectCELL* cell;
};
