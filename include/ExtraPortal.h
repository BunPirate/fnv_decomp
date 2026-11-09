#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class BSPortalNode;

// pdb: class ExtraPortal, size 0x10, bases: BSExtraData, 1 members
class ExtraPortal : public BSExtraData
{
public:
    NiPointer<BSPortalNode> spPortal;
};
