#pragma once

#include <cstddef>
#include "hkpCollisionAgent.h"

class hkpCdBody;
class hkpCdPointCollector;
class hkpSimpleClosestContactCollector;
class ShapeSweepParameters;

// pdb: class hkpIterativeLinearCastAgent, size 0xc, bases: hkpCollisionAgent, 0 members
class hkpIterativeLinearCastAgent : public hkpCollisionAgent
{
public:
    static void* __cdecl operator new(std::size_t nbytes);

    virtual void slot3();
    virtual void CastImpl(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                          const void* input, hkpSimpleClosestContactCollector* collector);

    void ProcessEntries_00daf540(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                      const ShapeSweepParameters* input,
                      hkpCdPointCollector* collector,
                      hkpCdPointCollector* startCollector);
};
