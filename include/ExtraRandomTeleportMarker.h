#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraRandomTeleportMarker, size 0x10, bases: BSExtraData, 1 members
class ExtraRandomTeleportMarker : public BSExtraData
{
public:
    virtual bool Compare(BSExtraData* apCompare) override;

    TESObjectREFR* pTeleportMarker;
};
