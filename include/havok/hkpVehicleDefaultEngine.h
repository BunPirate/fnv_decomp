// include/havok/hkpVehicleDefaultEngine.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTENGINE_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTENGINE_H

#include "hkBase.h"
#include "hkpVehicleEngine.h"
#pragma pack(push, 1)
// pdb: class hkpVehicleDefaultEngine, size 0x30, bases: hkpVehicleEngine, 10 members
class hkpVehicleDefaultEngine : public hkpVehicleEngine
{
  public:
    hkReal m_minRPM;                    // +0x8
    hkReal m_optRPM;                    // +0xC
    hkReal m_maxRPM;                    // +0x10
    hkReal m_maxTorque;                 // +0x14
    hkReal m_torqueFactorAtMinRPM;      // +0x18
    hkReal m_torqueFactorAtMaxRPM;      // +0x1C
    hkReal m_resistanceFactorAtMinRPM;  // +0x20
    hkReal m_resistanceFactorAtOptRPM;  // +0x24
    hkReal m_resistanceFactorAtMaxRPM;  // +0x28
    hkReal m_clutchSlipRPM;             // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleDefaultEngine[(sizeof(hkpVehicleDefaultEngine) == 0x30) ? 1 : -1];
#endif
