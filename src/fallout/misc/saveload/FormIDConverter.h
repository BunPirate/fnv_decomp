// fallout/misc/saveload/FormIDConverter.h: declares FormIDConverter
#ifndef FNV_BGSSAVELOADFORMIDMAP_H
#define FNV_BGSSAVELOADFORMIDMAP_H

#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/TESDataHandler.h"


extern TESDataHandler* g_dataHandler;

// Save/load form-ID remapping table: forward map (formID -> save index),
// reverse map (save index -> formID) and the next index to hand out.
// pdb: class BGSSaveLoadFormIDMap, size 0x24, 3 members
class BGSSaveLoadFormIDMap
{
  public:
    NiTPointerMap<unsigned int, unsigned int> FormIDToIndexMap;  // +0x0
    NiTPointerMap<unsigned int, unsigned int> IndexToFormIDMap;  // +0x10
    unsigned int iCurrentIndex;                                          // +0x20

    BGSSaveLoadFormIDMap(unsigned int iBucketCount);
    ~BGSSaveLoadFormIDMap();
    void Clear();
    unsigned int AddFormID(unsigned int aiFormID);
};

typedef char bgsSaveLoadFormIDMapSizeAssert[(sizeof(BGSSaveLoadFormIDMap) == 36) ? 1 : -1];
typedef char bgsSaveLoadFormIDMapIndexToFormIDMapOffsetAssert
    [((int)&((BGSSaveLoadFormIDMap*)0)->IndexToFormIDMap == 0x10) ? 1 : -1];
typedef char
    bgsSaveLoadFormIDMapICurrentIndexOffsetAssert[((int)&((BGSSaveLoadFormIDMap*)0)->iCurrentIndex == 0x20) ? 1 : -1];
typedef char
    niTPointerMapUnsignedUnsignedSizeAssert[(sizeof(NiTPointerMap<unsigned int, unsigned int>) == 16) ? 1 : -1];

#endif
