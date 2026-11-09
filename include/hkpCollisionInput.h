#pragma once

#include <stddef.h>
#include "hkPadSpu.h"
#include "hkVector4_S.h"

class hkpCollisionDispatcher;
class hkpCollisionFilter;
class hkpConvexListFilter;

// pdb: structure hkpCollisionInput, size 0x50, 7 members
class hkpCollisionInput
{
public:
    hkpCollisionInput(const hkpCollisionInput& other);

    float getTolerance() const { return m_tolerance; }

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher;
    hkPadSpu<int> m_weldClosestPoints;
    hkPadSpu<float> m_tolerance;
    hkPadSpu<const hkpCollisionFilter*> m_filter;
    hkPadSpu<const hkpConvexListFilter*> m_convexListFilter;
    unsigned int m_createPredictiveAgents;
    unsigned int unk18;
    unsigned int unk1C;

    struct AabbBoundsAndScale
    {
        static void* __cdecl operator new(size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(size_t n, void* p);
        static void* __cdecl operator new[](size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        class CommandArgument;

        hkVector4_S m_kAabbMin;
        hkVector4_S m_kAabbMaximum;
        hkVector4_S m_kAabbScale;
    };

    AabbBoundsAndScale m_aabb32Info;
};
