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

    hkPadSpu<WorldRayCastOutput*> m_rayCastOutputBase; // src: XBOX_RETAIL_PDB +0x8 (old: m_pRayHitBuffer)
    hkPadSpu<WorldRayCastOutput*> m_nextFreeOutput; // src: XBOX_RETAIL_PDB +0xc (old: m_pHitBufferEnd)
    hkPadSpu<int> m_capacity; // src: XBOX_RETAIL_PDB +0x10 (old: m_pRayCursor)
    hkPadSpu<int> m_numOutputs; // src: XBOX_RETAIL_PDB +0x14 (old: m_iHitCount)
    hkPadSpu<const hkpCollidable*> m_collidableOnPpu; // src: XBOX_RETAIL_PDB +0x18 (old: m_pCollidable)
};
