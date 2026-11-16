#pragma once

#include "hkpCdPointCollector.h"
#include "hkContactPoint.h"
#include "hkpRootCdPoint.h"

// pdb: class hkpClosestCdPointCollector, size 0x80, bases: hkpCdPointCollector, 1 members
class hkpClosestCdPointCollector : public hkpCdPointCollector
{
public:
    hkpClosestCdPointCollector();
    virtual ~hkpClosestCdPointCollector();
    virtual void AddCdPoint(const ContactPointPair& point);
    virtual void reset();

    bool DidHit() const;

    int unk08;
    int unk0C;
    hkpRootCdPoint m_hitPoint; // src: XBOX_RETAIL_PDB +0x10 (old: m_kHitPoint)
    hkpRootCdPoint m_unweldedHitPoint;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
