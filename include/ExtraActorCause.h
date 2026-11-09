#pragma once

#include "BSExtraData.h"
#include "NiAVObject.h"

class ActorCause;

// pdb: class ExtraActorCause, size 0x10, bases: BSExtraData, 1 members
class ExtraActorCause : public BSExtraData
{
public:
    virtual ~ExtraActorCause();

    ExtraActorCause();
    void FUN_0042cb30();
    void SetActorCause(int apCause);
    void* FUN_0042cb00(unsigned int flags);

    NiPointer<ActorCause> spActorCause;
};
