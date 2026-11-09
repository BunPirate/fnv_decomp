#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraMerchantContainer, size 0x10, bases: BSExtraData, 1 members
class ExtraMerchantContainer : public BSExtraData
{
public:
    virtual ~ExtraMerchantContainer();
    virtual bool Compare(BSExtraData*);

    ExtraMerchantContainer();

    TESObjectREFR* pContainer;
};
