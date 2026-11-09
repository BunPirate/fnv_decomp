#pragma once

#include "hkpCdPointCollector.h"
#include "ContactArray289.h"

struct hkBoolStub;

// pdb: class hkpAllCdPointCollector, size 0x3a0, bases: hkpCdPointCollector, 1 members
class hkpAllCdPointCollector : public hkpCdPointCollector
{
public:
    __declspec(nothrow) hkpAllCdPointCollector();
    __declspec(nothrow) virtual ~hkpAllCdPointCollector() throw();

    virtual void AddCdPoint(const ContactPointPair& point);
    virtual void AddCdPoint(const void* point);
    virtual void reset();

    hkBoolStub DidHit() const;
    void sortHits();
    void hkpAllCdPointCollector_sortHits();
    void FUN_006211b0();
    void* FUN_00621140(unsigned int aiFlags);

    ContactArray289 m_hits;
};
