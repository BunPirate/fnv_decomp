#pragma once

#include <cstddef>
#include "hkpRayHitCollector.h"
#include "hkMonitorStream.h"

struct WorldRayCastOutput;
class hkpCollidable;

// pdb: class hkpFixedBufferRayHitCollector, size 0x1c, bases: hkpRayHitCollector, 5 members
class hkpFixedBufferRayHitCollector : public hkpRayHitCollector
{
public:
    hkpFixedBufferRayHitCollector(WorldRayCastOutput* buffer, int capacity);
    hkpFixedBufferRayHitCollector(int buffer, int capacity);

    static void* __cdecl operator new(std::size_t nbytes);
    static void __cdecl addRayHitImplementation(
        const hkpCdBody& cdBody,
        const RayCastHitResult& hitInfo,
        hkpFixedBufferRayHitCollector* collector);

    virtual void CollectRayHit(const hkpCdBody& cdBody, const RayCastHitResult& hitInfo);

    hkPadSpu<WorldRayCastOutput*> m_rayCastOutputBase;
    hkPadSpu<WorldRayCastOutput*> m_nextFreeOutput;
    hkPadSpu<int> m_capacity;
    hkPadSpu<int> m_numOutputs;
    hkPadSpu<const hkpCollidable*> m_collidableOnPpu;
};
