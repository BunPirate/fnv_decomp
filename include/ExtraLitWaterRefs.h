#pragma once

#include "BSExtraData.h"
#include "LitWaterRefList.h"

class BSExtraDataEx;
class TESForm;

// pdb: class ExtraLitWaterRefs, size 0x14, bases: BSExtraData, 1 members
class ExtraLitWaterRefs : public BSExtraData
{
public:
    virtual ~ExtraLitWaterRefs();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraLitWaterRefs();
    void Copy(BSExtraDataEx* apSource);
    void InitItem_00434050(TESForm* apOwner);
    bool Compare_00434e30(BSExtraData* apCompare);
    void* FUN_00411d90(unsigned int flags);
    void FUN_00434dc0();

    LitWaterRefList kRefs;
};
