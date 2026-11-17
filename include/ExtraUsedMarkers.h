#pragma once

#include "BSExtraData.h"

// pdb: class ExtraUsedMarkers, size 0x10, bases: BSExtraData, 1 members
class ExtraUsedMarkers : public BSExtraData
{
public:
    virtual ~ExtraUsedMarkers();

    ExtraUsedMarkers();
    void SetUsedMarker(unsigned int aMarker, bool aUsed);
    bool IsUsedMarker(unsigned int aMarker);

    unsigned int m_uiUsedMarkerFlags;
};
