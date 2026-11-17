#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraOriginalReference, size 0x10, bases: BSExtraData, 1 members
class ExtraOriginalReference : public BSExtraData
{
public:
    virtual ~ExtraOriginalReference();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraOriginalReference(TESObjectREFR* apReference);

    bool Compare_004319d0(BSExtraData* apCompare);

    TESObjectREFR* m_pWorldReferenceInfo;
};
