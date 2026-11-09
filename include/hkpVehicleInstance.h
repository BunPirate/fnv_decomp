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

        hkContactPoint m_contactPoint;
        hkReal m_contactFriction;
        hkpRigidBody* m_contactBody;
        unsigned int m_contactShapeKey;
        unsigned int m_contactShapeKey1;
        unsigned int m_contactShapeKey2;
        unsigned int m_contactShapeKey3;
        unsigned int m_contactShapeKey4;
        unsigned int m_contactShapeKey5;
        unsigned int m_contactShapeKey6;
        unsigned int m_contactShapeKey7;
        hkVector4 m_hardPointWs;
        hkVector4 m_rayEndPointWs;
        hkReal m_currentSuspensionLength;
        hkVector4 m_suspensionDirectionWs;
        hkVector4 m_spinAxisChassisSpace;
        hkVector4 m_spinAxisWs;
        hkQuaternion m_steeringOrientationChassisSpace;
        hkReal m_spinVelocity;
        hkReal m_spinAngle;
        hkReal m_skidEnergyDensity;
        hkReal m_sideForce;
        hkReal m_forwardSlipVelocity;
        hkReal m_sideSlipVelocity;

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
    hkpVehicleDriverInput* m_driverInput;
    hkpVehicleSteering* m_steering;
    hkpVehicleEngine* m_engine;
    hkpVehicleTransmission* m_transmission;
    hkpVehicleBrake* m_brake;
    hkpVehicleSuspension* m_suspension;
    hkpVehicleAerodynamics* m_aerodynamics;
    hkpVehicleWheelCollide* m_wheelCollide;
    hkpTyremarksInfo* m_tyreMarks;
    hkpVehicleVelocityDamper* m_velocityDamper;
    hkArray<hkpVehicleInstanceWheelInfo> m_wheelsInfo;
    hkpVehicleFrictionStatus m_frictionStatus;
    hkpVehicleDriverInputStatus* m_deviceStatus;
    hkArray<hkBool> m_isFixed;
    hkReal m_wheelsTimeSinceMaxPedalInput;
    hkBool m_tryingToReverse;
    char padB1[3];
    hkReal m_torque;
    hkReal m_rpm;
    hkReal m_mainSteeringAngle;
    hkArray<hkReal> m_wheelsSteeringAngle;
    hkBool m_isReversing;
    signed char m_currentGear;
    hkBool m_delayed;
    char padCF[1];
    hkReal m_clutchDelayCountdown;
};
