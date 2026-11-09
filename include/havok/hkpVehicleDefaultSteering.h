// include/havok/hkpVehicleDefaultSteering.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTSTEERING_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTSTEERING_H

#include "hkBase.h"
#include "hkpVehicleSteering.h"
#pragma pack(push, 1)
// pdb: class hkpVehicleDefaultSteering, size 0x1c, bases: hkpVehicleSteering, 3 members
class hkpVehicleDefaultSteering : public hkpVehicleSteering
{
  public:
    hkReal m_maxSteeringAngle;           // +0x8
    hkReal m_maxSpeedFullSteeringAngle;  // +0xC
    hkArray<hkBool> m_doesWheelSteer;    // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultSteering[(sizeof(hkpVehicleDefaultSteering) == 0x1C) ? 1 : -1];
#endif
