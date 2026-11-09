// include/havok/hkpCallbackConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKPCALLBACKCONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPCALLBACKCONSTRAINTMOTOR_H

#include "hkBase.h"
#include "hkpLimitedForceConstraintMotor.h"
#pragma pack(push, 1)
// pdb: class hkpCallbackConstraintMotor, size 0x28, bases: hkpLimitedForceConstraintMotor, 5 members
class hkpCallbackConstraintMotor : public hkpLimitedForceConstraintMotor
{
  public:
    enum CallbackType
    {
        CALLBACK_MOTOR_TYPE_HAVOK_DEMO_SPRING_DAMPER = 0,
        CALLBACK_MOTOR_TYPE_USER_0 = 1,
        CALLBACK_MOTOR_TYPE_USER_1 = 2,
        CALLBACK_MOTOR_TYPE_USER_2 = 3,
        CALLBACK_MOTOR_TYPE_USER_3 = 4
    };
    void* m_callbackFunc;       // +0x14
    hkUint32 m_callbackType;       // +0x18 (CallbackType)
    hkUlong m_userData0;         // +0x1C
    hkUlong m_userData1;             // +0x20
    hkUlong m_userData2;  // +0x24
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCallbackConstraintMotor[(sizeof(hkpCallbackConstraintMotor) == 0x28) ? 1 : -1];
#endif
