#pragma once

#include "hkVector4.h"
#include "hkMatrix3.h"

typedef float hkReal;

// pdb: structure hkpMassProperties, size 0x50, 4 members
class hkpMassProperties
{
public:
    hkReal m_volume; // src: XBOX_RETAIL_PDB +0x0 (old: m_iBufferSize)
    hkReal m_mass; // src: XBOX_RETAIL_PDB +0x4 (old: m_fViscosityFriction)
    hkVector4 m_centerOfMass; // src: XBOX_RETAIL_PDB +0x10 (old: m_kCenterOfMass1)
    hkMatrix3 m_inertiaTensor; // src: XBOX_RETAIL_PDB +0x20 (old: m_kInertiaTensor)

    hkpMassProperties();
};
