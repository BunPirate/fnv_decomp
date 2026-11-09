#pragma once

#include "NiTMap.h"

class TESObjectREFR;

// pdb: class LoadedReferenceMap, size 0x18, bases: NiTMap<unsigned int, 2 members
class LoadedReferenceMap : public NiTMap<unsigned int, TESObjectREFR*>
{
public:
    unsigned int iCount;
    unsigned int iLastChangedTimeStamp;

    virtual ~LoadedReferenceMap();
    bool AddReference(TESObjectREFR* apRef);
};
