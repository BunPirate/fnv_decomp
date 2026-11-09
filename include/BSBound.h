#pragma once

#include "NiExtraData.h"

// pdb: class BSBound, size 0x24 (here 0xc), bases: NiExtraData, 2 members
class BSBound : public NiExtraData
{
public:
    bool FUN_00a7b290(int);
    int RegisterStreamables_00c54e90(int arStream);
    void LinkObject_00c54e70(NiStream& stream);
};
