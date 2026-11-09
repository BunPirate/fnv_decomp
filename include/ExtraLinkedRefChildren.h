#pragma once

#include "BSExtraData.h"

// pdb: class ExtraLinkedRefChildren, size 0x14 (here 0x10), bases: BSExtraData, 1 members
class ExtraLinkedRefChildren : public BSExtraData
{
public:
    struct ListX
    {
        ~ListX();
        void RemoveAll();
    };

    virtual ~ExtraLinkedRefChildren();

    void FUN_004335d0();
    void* __thiscall FUN_004335a0(unsigned int flags);

    ListX items;
};
