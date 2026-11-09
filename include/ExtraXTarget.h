#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraXTarget, size 0x10, bases: BSExtraData, 1 members
class ExtraXTarget : public BSExtraData
{
public:
    virtual ~ExtraXTarget();
    virtual bool Compare(BSExtraData*);

    ExtraXTarget();

    TESObjectREFR* pTarget;
};
