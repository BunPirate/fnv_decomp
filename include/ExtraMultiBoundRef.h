#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraMultiBoundRef, size 0x10, bases: BSExtraData, 1 members
class ExtraMultiBoundRef : public BSExtraData
{
public:
    ExtraMultiBoundRef();

    bool Compare(BSExtraData* apCompare) override;
    bool Compare_00435540(BSExtraData* apCompare);

    TESObjectREFR* m_pReference;
};
