#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class BSMultiBoundNode;

// pdb: class ExtraMultiBound, size 0x10, bases: BSExtraData, 1 members
class ExtraMultiBound : public BSExtraData
{
public:
    NiPointer<BSMultiBoundNode> spBound;
};
