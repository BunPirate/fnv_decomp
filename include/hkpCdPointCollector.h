#pragma once

#include <cstddef>

struct ContactPointPair;

// pdb: class hkpCdPointCollector, size 0x8, 1 members
class hkpCdPointCollector
{
public:
    hkpCdPointCollector();
    virtual ~hkpCdPointCollector() throw();
    virtual void AddCdPoint(const ContactPointPair& point) = 0;
    virtual void reset();

    float getEarlyOutDistance() const;
    static void* __cdecl operator new(std::size_t nbytes);

    float m_earlyOutDistance; // src: XBOX_RETAIL_PDB +0x4 (old: m_fEarlyOutDistance)
};
