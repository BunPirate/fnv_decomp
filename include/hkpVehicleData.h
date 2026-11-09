#pragma once

#include <cstddef>
#include "hkReferencedObject.h"
#include "hkaAnimation.h"
#include "hkVector4.h"
#include "hkRotation.h"
#include "hkBool.h"
#include "hkpVehicleFrictionDescription.h"

typedef signed char hkInt8;

// pdb: class hkpVehicleData, size 0x1a0, bases: hkReferencedObject, 19 members
class hkpVehicleData : public hkReferencedObject
{
public:
    struct WheelComponentParams
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* place);
        static void __cdecl operator delete[](void* p, void* place);

        class CommandArgument;
        static const ClassMemberDescriptor Members[];
        static const hkClass& __cdecl staticClass();
        struct DefaultStruct;

        hkReal m_radius;
        hkReal m_mass;
        hkReal m_width;
        hkReal m_friction;
        hkReal m_viscosityFriction;
        hkReal m_maxFriction;
        hkReal m_slipAngle;
        hkReal m_forceFeedbackMultiplier;
        hkReal m_maxContactBodyAcceleration;
        hkInt8 m_axle;
    };

    static void* __cdecl operator new(std::size_t nbytes);
    hkpVehicleData(FinishingFlag f);

    virtual void vf03();

    char pad8[0x8];
    hkVector4 m_gravity;
    hkInt8 m_numWheels;
    char pad21[0xF];
    hkRotation m_chassisOrientation;
    hkReal m_torqueRollFactor;
    hkReal m_torquePitchFactor;
    hkReal m_torqueYawFactor;
    hkReal m_extraTorqueFactor;
    hkReal m_maxVelocityForPositionalFriction;
    hkReal m_chassisUnitInertiaYaw;
    hkReal m_chassisUnitInertiaRoll;
    hkReal m_chassisUnitInertiaPitch;
    hkReal m_frictionEqualizer;
    hkReal m_normalClippingAngleCos;
    hkReal m_maxFrictionSolverMassRatio;
    hkArray<WheelComponentParams> m_wheelParams;
    hkArray<hkInt8> m_numWheelsPerAxle;
    hkpVehicleFrictionDescription m_frictionDescription;
    char pad174[0xC];
    hkVector4 m_chassisFrictionInertiaInvDiag;
    hkBool m_alreadyInitialised;
    char pad191[0xF];
};
