// src/havok/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/aerodynamics/default/hkpvehicledefaultaerodynamics.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpVehicleDefaultAerodynamics.h"
#include <math.h>

extern double DAT_01011588;

// These Havok base constructors are inline in the original constructor at 0x00e44310.

// @fnv 0x00e442e0
float hkpVehicleDefaultAerodynamics::calcLiftForce(float speed) throw()
{
    return m_airDensity * DAT_01011588 * m_liftCoefficient * m_frontalArea * speed * speed;
}

// @fnv 0x00e44310
hkpVehicleDefaultAerodynamics::hkpVehicleDefaultAerodynamics() throw()
{
    m_airDensity = 0.0f;
    m_frontalArea = 0.0f;
    m_dragCoefficient = 0.0f;
    m_liftCoefficient = 0.0f;
    m_extraGravityws.m_vComponents = _mm_setzero_ps();
}

// @fnv 0x00e44340
float hkpVehicleDefaultAerodynamics::calcDragForce(float speed) throw()
{
    float fAbs = (float)fabs((double)speed);
    return speed * (fAbs * (m_airDensity * -0.5 * m_dragCoefficient * m_frontalArea));
}
