#pragma once

#include "BSExtraData.h"

class TeleportableReference;

// pdb: class ExtraTeleport, size 0x10, bases: BSExtraData, 1 members
class ExtraTeleport : public BSExtraData
{
public:
    virtual ~ExtraTeleport();
    virtual bool Compare(BSExtraData* extra);

    ExtraTeleport(TeleportableReference*); // 0x00431230
    ExtraTeleport(void*); // 0x00431b80
    ExtraTeleport* __thiscall FUN_00431230(TeleportableReference*);
    ExtraTeleport* __thiscall FUN_00431b80(TeleportableReference*);
    void __local_vftable_ctor_closure();

    TeleportableReference* data;
};
