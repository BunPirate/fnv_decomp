#pragma once

#include "BSExtraData.h"

class TESGlobal;

// pdb: class ExtraGlobal, size 0x10, bases: BSExtraData, 1 members
class ExtraGlobal : public BSExtraData
{
public:
    virtual ~ExtraGlobal();
    virtual bool Compare(BSExtraData* extra);

    ExtraGlobal(TESGlobal* aGlobal);

    union
    {
        TESGlobal* pGlobalForm;
        TESGlobal* global;
    };
};
