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

    RootContactPoint* m_pointsArrayBase;
    RootContactPoint* m_nextFreePoint;
    int m_capacity;
    int m_numPoints;
};
