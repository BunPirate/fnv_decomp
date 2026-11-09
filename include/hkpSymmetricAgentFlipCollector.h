#pragma once

#include "hkpCdPointCollector.h"

// pdb: class hkpSymmetricAgentFlipCollector, size 0xc, bases: hkpCdPointCollector, 1 members
class hkpSymmetricAgentFlipCollector : public hkpCdPointCollector
{
public:
    virtual ~hkpSymmetricAgentFlipCollector();
    virtual void AddCdPoint(const ContactPointPair& point);

    void dispose();
    void collect(float value);
    void process(void* value);
    void unk00();

    void* m_collector;
};
