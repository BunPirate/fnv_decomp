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

    DynamicMap<NiVBDynamicSet> m_kSets;
    DynamicMap<NiVBChip> m_kChips;
    // src: XBOX_PDB (NiTPrimitiveArray<NiVBDynamicSet *> / <NiVBChip *>); ctor 0x00e957b0.
    NiTPrimitiveArray<NiVBDynamicSet*> m_kMultiStreamSets;
    NiTPrimitiveArray<NiVBChip*> m_kMultiStreamChips;
    unsigned int m_uiNextIndex;
};
