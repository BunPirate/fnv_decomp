#pragma once

#include "TESObjectMISC.h"

// pdb: class TESKey, size 0xac, bases: TESObjectMISC, 0 members
class TESKey : public TESObjectMISC
{
public:
    TESKey();
    virtual ~TESKey();

    void* Destroy(unsigned int flags);
    void FUN_0050a6a0();
};
