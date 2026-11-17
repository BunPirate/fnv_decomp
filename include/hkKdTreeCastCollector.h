#pragma once

#include "hkBool.h"

typedef unsigned long hkPrimitiveId;
typedef float hkReal;

// pdb: class hkKdTreeCastCollector, size 0x4, 0 members
class hkKdTreeCastCollector
{
public:
    virtual ~hkKdTreeCastCollector();
    virtual hkBool ReportHit(hkPrimitiveId primId) = 0;
    virtual hkBool DidHit() = 0;
    virtual hkReal GetHitFraction() = 0;
};
