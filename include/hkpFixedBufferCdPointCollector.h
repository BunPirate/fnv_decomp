#pragma once

#include "hkpCdPointCollector.h"
class RootContactPoint;

// pdb: class hkpFixedBufferCdPointCollector, size 0x18, bases: hkpCdPointCollector, 4 members
class hkpFixedBufferCdPointCollector : public hkpCdPointCollector
{
public:
    hkpFixedBufferCdPointCollector(RootContactPoint* buffer, int capacity);
    virtual ~hkpFixedBufferCdPointCollector();
    virtual void AddCdPoint(const ContactPointPair& point);

    RootContactPoint* m_pointsArrayBase; // src: XBOX_RETAIL_PDB +0x8 (old: m_pPointBuffer)
    RootContactPoint* m_nextFreePoint; // src: XBOX_RETAIL_PDB +0xc (old: m_pPointBufferEnd)
    int m_capacity; // src: XBOX_RETAIL_PDB +0x10 (old: m_pRayCursor)
    int m_numPoints; // src: XBOX_RETAIL_PDB +0x14 (old: m_iPointCount)
};
