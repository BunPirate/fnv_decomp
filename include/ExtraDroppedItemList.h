#pragma once

#include "BSExtraData.h"

class DroppedItemNode;

// pdb: class ExtraDroppedItemList, size 0x14 (here 0x10), bases: BSExtraData, 1 members
class ExtraDroppedItemList : public BSExtraData
{
public:
    struct ListX
    {
        ListX();
        ~ListX();
        void RemoveAll();

        DroppedItemNode* head;
    };

    ExtraDroppedItemList();
    virtual ~ExtraDroppedItemList();

    void FUN_004359f0();
    void* __thiscall FUN_004359c0(unsigned int flags);

    ListX m_pInventoryEntryData;
};
