#pragma once

#include "hkVector4.h"
#include "hkMatrix3.h"

typedef float hkReal;

// pdb: structure hkpMassProperties, size 0x50, 4 members
class hkpMassProperties
{
public:
    hkReal m_volume;
    hkReal m_mass;
    hkVector4 m_centerOfMass;
    hkMatrix3 m_inertiaTensor;

    hkpMassProperties();
};
