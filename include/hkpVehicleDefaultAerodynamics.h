#pragma once

#include "hkpVehicleAerodynamics.h"
#include "hkVector4.h"

class hkpVehicleInstanceE443;
struct AerodynamicsDragOutputE443;

typedef float hkReal;

// pdb: class hkpVehicleDefaultAerodynamics, size 0x30, bases: hkpVehicleAerodynamics, 5 members
class hkpVehicleDefaultAerodynamics : public hkpVehicleAerodynamics
{
public:
    hkpVehicleDefaultAerodynamics() throw();

    virtual void vf03(const float deltaTime,
                      const hkpVehicleInstanceE443* pkVehicle,
                      AerodynamicsDragOutputE443& dragInfoOut) throw();
    virtual float calcDragForce(float m_fGain) throw();
    virtual float calcLiftForce(float m_fGain) throw();

    hkReal m_airDensity;
    hkReal m_frontalArea;
    hkReal m_dragCoefficient;
    hkReal m_liftCoefficient;
    char pad18[0x8];
    hkVector4 m_extraGravityws;
};
