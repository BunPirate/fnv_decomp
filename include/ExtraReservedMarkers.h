#pragma once

#include "BSExtraData.h"

// pdb: class ExtraReservedMarkers, size 0x10, bases: BSExtraData, 1 members
class ExtraReservedMarkers : public BSExtraData
{
public:
    virtual ~ExtraReservedMarkers();

    ExtraReservedMarkers();
    void SetUsedMarker(unsigned int, bool);

    unsigned int m_uiReservedMarkers;
};
