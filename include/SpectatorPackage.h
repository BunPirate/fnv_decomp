#pragma once

#include "TESPackage.h"

// pdb: class SpectatorPackage, size 0xb4 (here 0x80), bases: TESPackage, 8 members
class SpectatorPackage : public TESPackage
{
public:
    int IsComplete(const SpectatorPackage& other);
    void __thiscall ProcessEntries_009f8420(Actor& aActor);
};
