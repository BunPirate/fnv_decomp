#pragma once

#include "BSExtraData.h"

class EntryData;
class InventoryChanges;
class TESForm;

// pdb: class ExtraContainerChanges, size 0x10, bases: BSExtraData, 1 members
class ExtraContainerChanges : public BSExtraData
{
public:
    virtual ~ExtraContainerChanges();

    ExtraContainerChanges(InventoryChanges* changes);
    EntryData* InventoryChanges_GetInventoryItem(TESForm*, int);

    InventoryChanges* pChanges;
};
