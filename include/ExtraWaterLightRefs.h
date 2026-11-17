#pragma once

#include "BSExtraData.h"
#include "LitWaterRefList.h"

class BSExtraDataEx;

// pdb: class ExtraWaterLightRefs, size 0x14, bases: BSExtraData, 1 members
class ExtraWaterLightRefs : public BSExtraData
{
public:
    virtual ~ExtraWaterLightRefs();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraWaterLightRefs();
    bool Compare_004349c0(BSExtraData* apCompare);
    void Copy(BSExtraDataEx* apSource);

    LitWaterRefList kRefs;
};
