#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraLinkedRef, size 0x10, bases: BSExtraData, 1 members
class ExtraLinkedRef : public BSExtraData
{
public:
    virtual ~ExtraLinkedRef();
    virtual bool Compare(BSExtraData* apCompare);

    bool __thiscall Compare_00433670(BSExtraData* apCompare);

    TESObjectREFR* m_pLinkedReference;
};
