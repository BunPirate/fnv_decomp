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

        float m_frictionCircleYtab[16];
        float m_xStep;
        float m_xStart;
        float m_wheelSurfaceInertia;
        float m_wheelSurfaceInertiaInv;
        float m_wheelChassisMassRatio;
        float m_wheelRadius;
        float m_wheelRadiusInv;
        float m_wheelDownForceFactor;
        float m_wheelDownForceSumFactor;
    };

    float m_wheelDistance;
    float m_chassisMassInv;
    AxisDescription m_axleDescr[2];
};
