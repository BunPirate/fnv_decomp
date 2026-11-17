#pragma once

#include <cstddef>
#include "hkpUnaryAction.h"
#include "hkaAnimation.h"
#include "hkBool.h"
#include "hkContactPoint.h"
#include "hkQuaternion.h"
#include "hkpVehicleFrictionStatus.h"
#include "hkpVehicleWheelCollide.h"

class hkpRigidBody;
class hkpVehicleData;
class hkpVehicleDriverInput;
class hkpVehicleSteering;
class hkpVehicleEngine;
class hkpVehicleTransmission;
class hkpVehicleBrake;
class hkpVehicleSuspension;
class hkpVehicleAerodynamics;
class hkpTyremarksInfo;
class hkpVehicleVelocityDamper;
class hkpVehicleDriverInputStatus;
class hkpVehicleInstanceWheelInfo;
struct WGround;

// pdb: class hkpVehicleInstance, size 0xd4, bases: hkpUnaryAction, 25 members
class hkpVehicleInstance : public hkpUnaryAction
{
public:
    static void* __cdecl operator new(std::size_t nbytes);

    struct WheelInfo
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
        enum { MAX_NUM_SHAPE_KEYS = 8 };

        hkContactPoint m_contactPoint; // src: XBOX_RETAIL_PDB +0x0 (old: m_vContactPoint)
        hkReal m_contactFriction; // src: XBOX_RETAIL_PDB +0x20 (old: m_fSuspensionLength)
        hkpRigidBody* m_contactBody; // src: XBOX_RETAIL_PDB +0x24 (old: m_pUserData)
        unsigned int m_contactShapeKey; // src: XBOX_RETAIL_PDB +0x28 (old: m_contactShapeKey0)
        unsigned int m_contactShapeKey1;
        unsigned int m_contactShapeKey2;
        unsigned int m_contactShapeKey3;
        unsigned int m_contactShapeKey4;
        unsigned int m_contactShapeKey5;
        unsigned int m_contactShapeKey6;
        unsigned int m_contactShapeKey7;
        hkVector4 m_hardPointWs; // src: XBOX_RETAIL_PDB +0x50 (old: m_vContactPointVelocity)
        hkVector4 m_rayEndPointWs; // src: XBOX_RETAIL_PDB +0x60 (old: m_vContactNormal)
        hkReal m_currentSuspensionLength; // src: XBOX_RETAIL_PDB +0x70 (old: m_fContactFriction)
        hkVector4 m_suspensionDirectionWs; // src: XBOX_RETAIL_PDB +0x80 (old: m_vHardPointWs)
        hkVector4 m_spinAxisChassisSpace; // src: XBOX_RETAIL_PDB +0x90 (old: m_vRayEndPointWs)
        hkVector4 m_spinAxisWs; // src: XBOX_RETAIL_PDB +0xa0 (old: m_vSuspensionDirectionWs)
        hkQuaternion m_steeringOrientationChassisSpace; // src: XBOX_RETAIL_PDB +0xb0 (old: m_qSteeringOrientation)
        hkReal m_spinVelocity; // src: XBOX_RETAIL_PDB +0xc0 (old: m_fValueAtOffsetC0)
        hkReal m_spinAngle; // src: XBOX_RETAIL_PDB +0xc4 (old: m_fSpinAngle)
        hkReal m_skidEnergyDensity; // src: XBOX_RETAIL_PDB +0xc8 (old: m_fSkidEnergyDensity)
        hkReal m_sideForce; // src: XBOX_RETAIL_PDB +0xcc (old: m_fSideForce)
        hkReal m_forwardSlipVelocity; // src: XBOX_RETAIL_PDB +0xd0 (old: m_fSuspensionForce)
        hkReal m_sideSlipVelocity; // src: XBOX_RETAIL_PDB +0xd4 (old: m_fForwardForce)

        void init();
    };

    static const unsigned char s_maxNumLocalWheels = 16;

    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();

    void UpdateVehicle(hkReal deltaTime, const hkpVehicleWheelCollide::WheelCollideResult* cdInfo);
    hkpRigidBody* getChassis() const;
    void ProcessEntries_00e38310(float deltaTime, const int* groundBody, const WGround* ground);

    hkpVehicleData* m_data;
    hkpVehicleDriverInput* m_driverInput; // src: XBOX_RETAIL_PDB +0x20 (old: m_pDriverInput)
    hkpVehicleSteering* m_steering; // src: XBOX_RETAIL_PDB +0x24 (old: m_pSteering)
    hkpVehicleEngine* m_engine; // src: XBOX_RETAIL_PDB +0x28 (old: m_pVehicleEngine)
    hkpVehicleTransmission* m_transmission; // src: XBOX_RETAIL_PDB +0x2c (old: m_pTransmission)
    hkpVehicleBrake* m_brake; // src: XBOX_RETAIL_PDB +0x30 (old: m_pBrake)
    hkpVehicleSuspension* m_suspension; // src: XBOX_RETAIL_PDB +0x34 (old: m_pSuspension)
    hkpVehicleAerodynamics* m_aerodynamics; // src: XBOX_RETAIL_PDB +0x38 (old: m_pAerodynamics)
    hkpVehicleWheelCollide* m_wheelCollide; // src: XBOX_RETAIL_PDB +0x3c (old: m_pWheelCollide)
    hkpTyremarksInfo* m_tyreMarks; // src: XBOX_RETAIL_PDB +0x40 (old: m_pTyremarksInfo)
    hkpVehicleVelocityDamper* m_velocityDamper; // src: XBOX_RETAIL_PDB +0x44 (old: m_pVelocityDamper)
    hkArray<hkpVehicleInstanceWheelInfo> m_wheelsInfo; // src: XBOX_RETAIL_PDB +0x48 (old: m_kWheelInfoArray)
    hkpVehicleFrictionStatus m_frictionStatus; // src: XBOX_RETAIL_PDB +0x54 (old: m_kFrictionStatus)
    hkpVehicleDriverInputStatus* m_deviceStatus; // src: XBOX_RETAIL_PDB +0x9c (old: m_pDriverInputStatus)
    hkArray<hkBool> m_isFixed; // src: XBOX_RETAIL_PDB +0xa0 (old: m_kSecondRealArray)
    hkReal m_wheelsTimeSinceMaxPedalInput; // src: XBOX_RETAIL_PDB +0xac (old: m_fBrakeState)
    hkBool m_tryingToReverse; // src: XBOX_RETAIL_PDB +0xb0 (old: m_bIsReversing)
    char padB1[3];
    hkReal m_torque; // src: XBOX_RETAIL_PDB +0xb4 (old: m_fFirstValueBeforeSteeringAngle)
    hkReal m_rpm; // src: XBOX_RETAIL_PDB +0xb8 (old: m_fSecondValueBeforeSteeringAngle)
    hkReal m_mainSteeringAngle; // src: XBOX_RETAIL_PDB +0xbc (old: m_fMainSteeringAngle)
    hkArray<hkReal> m_wheelsSteeringAngle; // src: XBOX_RETAIL_PDB +0xc0 (old: m_kWheelSteeringAngles)
    hkBool m_isReversing; // src: XBOX_RETAIL_PDB +0xcc (old: m_iGearCount)
    signed char m_currentGear; // src: XBOX_RETAIL_PDB +0xcd (old: m_iGearCapacity)
    hkBool m_delayed; // src: XBOX_RETAIL_PDB +0xce (old: m_bGearShiftActive)
    char padCF[1];
    hkReal m_clutchDelayCountdown; // src: XBOX_RETAIL_PDB +0xd0 (old: m_fGearShiftTime)
};
