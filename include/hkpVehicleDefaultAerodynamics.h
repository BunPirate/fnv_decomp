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

    hkReal m_airDensity; // src: XBOX_RETAIL_PDB +0x8 (old: m_fAirDensity)
    hkReal m_frontalArea; // src: XBOX_RETAIL_PDB +0xc (old: m_fFrontalArea)
    hkReal m_dragCoefficient; // src: XBOX_RETAIL_PDB +0x10 (old: m_fDragCoefficient)
    hkReal m_liftCoefficient; // src: XBOX_RETAIL_PDB +0x14 (old: m_fLiftCoefficient)
    char pad18[0x8];
    hkVector4 m_extraGravityws; // src: XBOX_RETAIL_PDB +0x20 (old: m_vExtraGravityWorldSpace)
};
