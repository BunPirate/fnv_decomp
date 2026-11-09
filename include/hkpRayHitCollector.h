#pragma once

#include "hkpCdBody.h"

struct RayCastHitResult;

// pdb: class hkpRayHitCollector, size 0x8, 1 members
class hkpRayHitCollector
{
public:
    hkpRayHitCollector();

    virtual void CollectRayHit(const hkpCdBody& cdBody, const RayCastHitResult& hitInfo) = 0;
    virtual void vf01();

    void reset();

    float m_earlyOutHitFraction;
};
