#pragma once

#include "BSExtraData.h"

// pdb: class ExtraEnableStateChildren, size 0x14 (here 0x10), bases: BSExtraData, 1 members
class ExtraEnableStateChildren : public BSExtraData
{
public:
    struct ChildrenList
    {
        ~ChildrenList();
        void RemoveAll();
    };

    virtual ~ExtraEnableStateChildren();

    void* FUN_00433410(unsigned int flags);
    void FUN_00433440();

    ChildrenList list;
};
