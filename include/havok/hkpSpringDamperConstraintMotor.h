// include/havok/hkpSpringDamperConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPSPRINGDAMPERCONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPSPRINGDAMPERCONSTRAINTMOTOR_H

#include "hkBase.h"
#include "hkpLimitedForceConstraintMotor.h"
#pragma pack(push, 1)
// pdb: class hkpSpringDamperConstraintMotor, size 0x1c, bases: hkpLimitedForceConstraintMotor, 2 members
class hkpSpringDamperConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    hkReal m_springConstant;  // +0x14
    hkReal m_springDamping;   // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSpringDamperConstraintMotor[(sizeof(hkpSpringDamperConstraintMotor) == 0x1C) ? 1 : -1];
#endif
