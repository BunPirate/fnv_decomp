#pragma once

#include "BSExtraData.h"

class TESForm;

// pdb: class ExtraOwnership, size 0x10, bases: BSExtraData, 1 members
class ExtraOwnership : public BSExtraData
{
public:
    virtual ~ExtraOwnership();
    virtual bool Compare(BSExtraData* extra);

    ExtraOwnership();
    ExtraOwnership(TESForm* owner);
    bool Compare_00431a70(BSExtraData* apCompare);

    void* pOwner;
};
