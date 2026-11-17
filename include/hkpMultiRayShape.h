#pragma once

#include <cstddef>
#include "hkpShape.h"
#include "hkaAnimation.h"
#include "hkVector4.h"

// pdb: class hkpMultiRayShape, size 0x20, bases: hkpShape, 2 members
class hkpMultiRayShape : public hkpShape
{
public:
    static const ClassMemberDescriptor Members[];

    struct Ray
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        class CommandArgument;
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;

        hkVector4 m_start; // src: XBOX_RETAIL_PDB +0x0 (old: m_kRayStart)
        hkVector4 m_end; // src: XBOX_RETAIL_PDB +0x10 (old: m_kRayEnd)
    };

    hkpMultiRayShape(const Ray* Rays, int nRays, hkReal rayPenetrationDistance = 0.0f);
    hkpMultiRayShape(FinishingFlag flag);

    const hkArray<Ray>& getRays() const { return m_rays; }
    hkReal getRayPenetrationDistance() const { return m_rayPenetrationDistance; }

    hkArray<Ray> m_rays; // src: XBOX_RETAIL_PDB +0x10 (old: m_kRays)
    hkReal m_rayPenetrationDistance; // src: XBOX_RETAIL_PDB +0x1c (old: m_fRayRadius)
};
