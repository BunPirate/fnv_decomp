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

        float m_forward_slip_velocity;
        float m_side_slip_velocity;
        float m_skid_energy_density;
        float m_side_force;
        float m_delayed_forward_impulse;
        float m_sideRhs;
        float m_forwardRhs;
        float m_relativeSideForce;
        float m_relativeForwardForce;

        void init();
    };

    AxisStatus m_axis[2];
};
