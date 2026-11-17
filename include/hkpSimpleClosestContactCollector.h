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

    unsigned char m_hasHit; // src: XBOX_RETAIL_PDB +0x8 (old: m_bOk)
    Contact228 m_hitPoint; // src: XBOX_RETAIL_PDB +0x10 (old: contact)
};
