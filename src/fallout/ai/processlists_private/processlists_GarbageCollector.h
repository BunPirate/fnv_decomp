// Source layout: GarbageCollector. PC corrections are in generate_headers.py.
#ifndef FNV_GARBAGECOLLECTOR_H
#define FNV_GARBAGECOLLECTOR_H

#include "processlists_layout_support.h"
// pdb: class GarbageCollector, size 0x1, 0 members
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* apRef);
    static void Add(BSTempEffect* apEffect);
    static NiTObjectArray<TESObjectREFR*> ms_kReferencesQueuedForRemoval;
    static NiTObjectArray<TESObjectREFR*> ObjectGarbageB;
};
FNV_STATIC_ASSERT(sizeof(GarbageCollector) == 0x1);
#endif
