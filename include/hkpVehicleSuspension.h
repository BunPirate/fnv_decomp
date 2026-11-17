#pragma once

#include "hkReferencedObject.h"
#include "hkArray.h"

class hkpVehicleSuspensionSuspensionWheelParameters;

// pdb: class hkpVehicleSuspension, size 0x14, bases: hkReferencedObject, 1 members
class hkpVehicleSuspension : public hkReferencedObject
{
public:
    hkArray<hkpVehicleSuspensionSuspensionWheelParameters> m_wheelParams; // src: XBOX_RETAIL_PDB +0x8 (old: m_kWheelParams)
};
