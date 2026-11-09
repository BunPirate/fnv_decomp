#pragma once

#include "BSExtraData.h"

class MapMarkerData;

// pdb: class ExtraMapMarker, size 0x10, bases: BSExtraData, 1 members
class ExtraMapMarker : public BSExtraData
{
public:
    ExtraMapMarker(MapMarkerData* pMapMarkerData);

    virtual ~ExtraMapMarker();
    virtual bool Compare(BSExtraData*);

    void __local_vftable_ctor_closure();

    MapMarkerData* data;
};
