#pragma once

#include "NiGeometryGroup.h"
#include "NiTPrimitiveArray.h"

class NiVBDynamicSet;
class NiVBChip;

template <class T> class DynamicMapBase
{
public:
    DynamicMapBase();
    virtual void Slot();

    unsigned int size;
    void* table;
    unsigned int count;
};

template <class T> class DynamicMap : public DynamicMapBase<T>
{
public:
    DynamicMap();
    virtual void Slot();
};





// pdb: class NiDynamicGeometryGroup, size 0x50, bases: NiGeometryGroup, 5 members
class NiDynamicGeometryGroup : public NiGeometryGroup
{
public:
    NiDynamicGeometryGroup();
    virtual void Purge();
    virtual ~NiDynamicGeometryGroup();

    DynamicMap<NiVBDynamicSet> m_kSets; // src: XBOX_RETAIL_PDB +0xc (old: sets)
    DynamicMap<NiVBChip> m_kChips; // src: XBOX_RETAIL_PDB +0x1c (old: chips)
    // src: XBOX_PDB (NiTPrimitiveArray<NiVBDynamicSet *> / <NiVBChip *>); ctor 0x00e957b0.
    NiTPrimitiveArray<NiVBDynamicSet*> m_kMultiStreamSets; // src: XBOX_RETAIL_PDB +0x2c (old: streamSets)
    NiTPrimitiveArray<NiVBChip*> m_kMultiStreamChips; // src: XBOX_RETAIL_PDB +0x3c (old: streamChips)
    unsigned int m_uiNextIndex; // src: XBOX_RETAIL_PDB +0x4c (old: nextIndex)
};
