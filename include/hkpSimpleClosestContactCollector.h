#pragma once

#include "hkpCdPointCollector.h"
#include "Contact228.h"

// pdb: class hkpSimpleClosestContactCollector, size 0x30, bases: hkpCdPointCollector, 2 members
class hkpSimpleClosestContactCollector : public hkpCdPointCollector
{
public:
    hkpSimpleClosestContactCollector();
    virtual ~hkpSimpleClosestContactCollector();
    virtual void AddCdPoint(const ContactPointPair& point);
    virtual void reset();

    void addContactPoint(const Contact228& point);
    void Reset();

    unsigned char m_hasHit;
    Contact228 m_hitPoint;
};
