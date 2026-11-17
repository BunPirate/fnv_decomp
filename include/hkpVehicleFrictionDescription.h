#pragma once

#include <cstddef>

struct ClassMemberDescriptor;
class hkClass;

// pdb: structure hkpVehicleFrictionDescription, size 0xd0, 3 members
class hkpVehicleFrictionDescription
{
public:
    struct AxisDescription
    {
        class CommandArgument;
        struct DefaultStruct;

        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        float m_frictionCircleYtab[16]; // src: XBOX_RETAIL_PDB +0x0 (old: m_afFrictionCurveSamples)
        float m_xStep; // src: XBOX_RETAIL_PDB +0x40 (old: m_fAxisFrictionTuning1)
        float m_xStart; // src: XBOX_RETAIL_PDB +0x44 (old: m_fAxisFrictionTuning2)
        float m_wheelSurfaceInertia; // src: XBOX_RETAIL_PDB +0x48 (old: m_fAxisFrictionTuning3)
        float m_wheelSurfaceInertiaInv; // src: XBOX_RETAIL_PDB +0x4c (old: m_fAxisFrictionTuning4)
        float m_wheelChassisMassRatio; // src: XBOX_RETAIL_PDB +0x50 (old: m_fAxisFrictionTuning5)
        float m_wheelRadius; // src: XBOX_RETAIL_PDB +0x54 (old: m_fAxisFrictionTuning6)
        float m_wheelRadiusInv; // src: XBOX_RETAIL_PDB +0x58 (old: m_fAxisFrictionTuning7)
        float m_wheelDownForceFactor; // src: XBOX_RETAIL_PDB +0x5c (old: m_fAxisFrictionTuning8)
        float m_wheelDownForceSumFactor; // src: XBOX_RETAIL_PDB +0x60 (old: m_fAxisFrictionTuning9)
    };

    float m_wheelDistance; // src: XBOX_RETAIL_PDB +0x0 (old: m_fFrictionEqualizer)
    float m_chassisMassInv; // src: XBOX_RETAIL_PDB +0x4 (old: m_fMaxVelocityForPositionalFriction)
    AxisDescription m_axleDescr[2]; // src: XBOX_RETAIL_PDB +0x8 (old: m_kAxisDescriptions)
};
