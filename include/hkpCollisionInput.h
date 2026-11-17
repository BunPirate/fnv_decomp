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

    hkPadSpu<hkpCollisionDispatcher*> m_dispatcher; // src: XBOX_RETAIL_PDB +0x0 (old: m_pCollisionDispatcher)
    hkPadSpu<int> m_weldClosestPoints; // src: XBOX_RETAIL_PDB +0x4 (old: m_collisionQuality)
    hkPadSpu<float> m_tolerance; // src: XBOX_RETAIL_PDB +0x8 (old: m_fScalar)
    hkPadSpu<const hkpCollisionFilter*> m_filter; // src: XBOX_RETAIL_PDB +0xc (old: m_iFilter)
    hkPadSpu<const hkpConvexListFilter*> m_convexListFilter; // src: XBOX_RETAIL_PDB +0x10 (old: m_pConvexListCollisionFilter)
    unsigned int m_createPredictiveAgents; // src: XBOX_RETAIL_PDB +0x14 (old: m_bCreatePredictiveAgents)
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

    AabbBoundsAndScale m_aabb32Info; // src: XBOX_RETAIL_PDB +0x20 (old: m_aiValues)
};
