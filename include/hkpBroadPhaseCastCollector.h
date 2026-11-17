#pragma once

#include "hkpBroadPhaseHandle.h"

// pdb: class hkpBroadPhaseCastCollector, size 0x4, 0 members
class hkpBroadPhaseCastCollector
{
public:
    virtual ~hkpBroadPhaseCastCollector();
    virtual float ReleaseCollector(const hkpBroadPhaseHandle* broadphaseHandle, int castIndex) = 0;
};
