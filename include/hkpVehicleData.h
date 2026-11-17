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

        hkReal m_radius; // src: XBOX_RETAIL_PDB +0x0 (old: m_fSphereRadius)
        hkReal m_mass; // src: XBOX_RETAIL_PDB +0x4 (old: m_fViscosityFriction)
        hkReal m_width; // src: XBOX_RETAIL_PDB +0x8 (old: m_fMaxFriction)
        hkReal m_friction; // src: XBOX_RETAIL_PDB +0xc (old: m_fSlipAngle)
        hkReal m_viscosityFriction; // src: XBOX_RETAIL_PDB +0x10 (old: m_fSlipVelocity)
        hkReal m_maxFriction; // src: XBOX_RETAIL_PDB +0x14 (old: m_fMaxContactBodyAcceleration)
        hkReal m_slipAngle; // src: XBOX_RETAIL_PDB +0x18 (old: m_fForceFeedbackMultiplier)
        hkReal m_forceFeedbackMultiplier; // src: XBOX_RETAIL_PDB +0x1c (old: m_fMaxFrictionForce)
        hkReal m_maxContactBodyAcceleration; // src: XBOX_RETAIL_PDB +0x20 (old: m_fFrictionEqualizer)
        hkInt8 m_axle; // src: XBOX_RETAIL_PDB +0x24 (old: m_iAxle)
    };

    static void* __cdecl operator new(std::size_t nbytes);
    hkpVehicleData(FinishingFlag f);

    virtual void vf03();

    char pad8[0x8];
    hkVector4 m_gravity; // src: XBOX_RETAIL_PDB +0x10 (old: m_kGravity)
    hkInt8 m_numWheels; // src: XBOX_RETAIL_PDB +0x20 (old: m_iWheelCount)
    char pad21[0xF];
    hkRotation m_chassisOrientation; // src: XBOX_RETAIL_PDB +0x30 (old: m_kChassisOrientation)
    hkReal m_torqueRollFactor; // src: XBOX_RETAIL_PDB +0x60 (old: m_fChassisMass)
    hkReal m_torquePitchFactor; // src: XBOX_RETAIL_PDB +0x64 (old: m_fTorqueMax)
    hkReal m_torqueYawFactor; // src: XBOX_RETAIL_PDB +0x68 (old: m_fTorqueMin)
    hkReal m_extraTorqueFactor; // src: XBOX_RETAIL_PDB +0x6c (old: m_fTorqueFactor)
    hkReal m_maxVelocityForPositionalFriction; // src: XBOX_RETAIL_PDB +0x70 (old: m_fTorquePitchFactor)
    hkReal m_chassisUnitInertiaYaw; // src: XBOX_RETAIL_PDB +0x74 (old: m_fTorqueRollFactor)
    hkReal m_chassisUnitInertiaRoll; // src: XBOX_RETAIL_PDB +0x78 (old: m_fTorqueYawFactor)
    hkReal m_chassisUnitInertiaPitch; // src: XBOX_RETAIL_PDB +0x7c (old: m_fExtraTorqueFactor)
    hkReal m_frictionEqualizer; // src: XBOX_RETAIL_PDB +0x80 (old: m_fChassisUnitInertiaRoll)
    hkReal m_normalClippingAngleCos; // src: XBOX_RETAIL_PDB +0x84 (old: m_fChassisUnitInertiaPitch)
    hkReal m_maxFrictionSolverMassRatio; // src: XBOX_RETAIL_PDB +0x88 (old: m_fChassisUnitInertiaYaw)
    hkArray<WheelComponentParams> m_wheelParams; // src: XBOX_RETAIL_PDB +0x8c (old: m_kWheelParams)
    hkArray<hkInt8> m_numWheelsPerAxle; // src: XBOX_RETAIL_PDB +0x98 (old: m_kNumWheelsPerAxle)
    hkpVehicleFrictionDescription m_frictionDescription; // src: XBOX_RETAIL_PDB +0xa4 (old: m_kFrictionDescription)
    char pad174[0xC];
    hkVector4 m_chassisFrictionInertiaInvDiag; // src: XBOX_RETAIL_PDB +0x180 (old: m_vChassisUnitInertiaAndMassInv)
    hkBool m_alreadyInitialised; // src: XBOX_RETAIL_PDB +0x190 (old: m_bWheelsUseChassisForGround)
    char pad191[0xF];
};
