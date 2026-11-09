#pragma once

#include "BSExtraData.h"

// pdb: class ExtraCellImageSpace, size 0x10, bases: BSExtraData, 1 members
class ExtraCellImageSpace : public BSExtraData
{
public:
    virtual ~ExtraCellImageSpace();
    bool Compare(BSExtraData* apCompare) override;

    ExtraCellImageSpace(void* apImageSpace);

    bool IsDifferentFrom(BSExtraData* extra);

    void* pImageSpace;
};
