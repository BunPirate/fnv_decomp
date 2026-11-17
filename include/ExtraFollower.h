#pragma once

#include "BSExtraData.h"

class Actor;
template <class T> class BSSimpleList;

// pdb: class ExtraFollower, size 0x10, bases: BSExtraData, 1 members
class ExtraFollower : public BSExtraData
{
public:
    ExtraFollower();
    virtual ~ExtraFollower();

    void __thiscall FUN_00430ea0();
    void* __thiscall FUN_00430e70(unsigned int flags);

    BSSimpleList<Actor*>* list;
};
