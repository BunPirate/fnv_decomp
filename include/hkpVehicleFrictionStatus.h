#pragma once

#include <cstddef>

struct ClassMemberDescriptor;
class hkClass;

// pdb: structure hkpVehicleFrictionStatus, size 0x48, 1 members
class hkpVehicleFrictionStatus
{
public:
    struct AxisStatus
    {
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;
        class CommandArgument;

        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        float m_forward_slip_velocity; // src: XBOX_RETAIL_PDB +0x0 (old: m_fAxisStatusMetric1)
        float m_side_slip_velocity; // src: XBOX_RETAIL_PDB +0x4 (old: m_fAxisStatusMetric2)
        float m_skid_energy_density; // src: XBOX_RETAIL_PDB +0x8 (old: m_fAxisStatusMetric3)
        float m_side_force; // src: XBOX_RETAIL_PDB +0xc (old: m_fAxisStatusMetric4)
        float m_delayed_forward_impulse; // src: XBOX_RETAIL_PDB +0x10 (old: m_fAxisStatusMetric5)
        float m_sideRhs; // src: XBOX_RETAIL_PDB +0x14 (old: m_fAxisStatusMetric6)
        float m_forwardRhs; // src: XBOX_RETAIL_PDB +0x18 (old: m_fAxisStatusMetric7)
        float m_relativeSideForce; // src: XBOX_RETAIL_PDB +0x1c (old: m_fAxisStatusMetric8)
        float m_relativeForwardForce; // src: XBOX_RETAIL_PDB +0x20 (old: m_fAxisStatusMetric9)

        void init();
    };

    AxisStatus m_axis[2]; // src: XBOX_RETAIL_PDB +0x0 (old: m_kAxisEndPoints)
};
