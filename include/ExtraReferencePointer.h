#pragma once

#include "BSExtraData.h"

class TESObjectREFR;

// pdb: class ExtraReferencePointer, size 0x10, bases: BSExtraData, 1 members
class ExtraReferencePointer : public BSExtraData
{
public:
    TESObjectREFR* pRef;
};
