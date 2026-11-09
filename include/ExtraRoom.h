#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class BSRoomNode;

// pdb: class ExtraRoom, size 0x10, bases: BSExtraData, 1 members
class ExtraRoom : public BSExtraData
{
public:
    NiPointer<BSRoomNode> spRoom;
};
