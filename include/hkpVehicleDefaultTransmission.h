#pragma once

#include "hkpVehicleTransmission.h"
#include "hkaAnimation.h"

struct Vehicle;

// pdb: class hkpVehicleDefaultTransmission, size 0x34, bases: hkpVehicleTransmission, 7 members
class hkpVehicleDefaultTransmission : public hkpVehicleTransmission
{
public:
    float calcTransmissionRPM(const Vehicle* vehicle, const void* transmissionOut);
    virtual void vf03();
    virtual void vf04();
    virtual float vf05(const Vehicle* vehicle, const void* input);
    virtual void vf06();
    virtual void vf07();
    virtual hkReal getTransmissionRatio(const Vehicle* vehicle, const void* input) const;

    hkReal m_downshiftRPM;
    hkReal m_upshiftRPM;
    hkReal m_primaryTransmissionRatio;
    hkReal m_clutchDelayTime;
    hkReal m_reverseGearRatio;
    hkArray<hkReal> m_gearsRatio;
    hkArray<hkReal> m_wheelsTorqueRatio;
};
