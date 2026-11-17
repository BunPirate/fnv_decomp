#pragma once

#include "TargetEntry.h"
#include "CombatWorldStateListNode.h"

class ZoneEntry;

// pdb: class TrapTargetEntry, size 0x50 (here 0x10), bases: TargetEntry, 0 members
class TrapTargetEntry : public TargetEntry
{
public:
    virtual void Run_0062c600(ZoneEntry* apTrap);

    unsigned char unk0C[4];
    CombatWorldStateListNode _list;
};
