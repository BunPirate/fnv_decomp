typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2

// src/havok/physics/vehicle/steering/default/hkpvehicledefaultsteering.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/steering/default/hkpvehicledefaultsteering.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultSteering.h"

// Exe 0x00e43f70 FUN_00e43f70: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_load_ps(const float* p);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

struct S00e43f70_Vec
{
    LocalM128 q;
    void hkVector4_setRotatedDir(const void* quat, const void* direction);
};

struct S00e43f70_Obj
{
    int unk00;
    int unk04;
    float unk08;
    float unk0c;
    void hkpVehicleDefaultSteering_calcMainSteeringAngle(int deltaTime, char* vehicle, S00e43f70_Obj* filteredInfoOutput, float* steeringOutput);
};

// Stores a scaled product of two floats into a3, scaling it down when the dot product of two vectors exceeds the threshold in unk0c.
// @fnv 0x00e43f70
// src: HAVOK_SRC 0x00e43f70
// pdb: hkpVehicleDefaultSteering::calcMainSteeringAngle | hkpVehicleDefaultSteering.obj | retail, upstream name already matches, high
// pdb params: deltaTime, vehicle, filteredInfoOutput, steeringOutput
// pdb locals: forward_ws
void S00e43f70_Obj::hkpVehicleDefaultSteering_calcMainSteeringAngle(int deltaTime, char* vehicle, S00e43f70_Obj* filteredInfoOutput, float* steeringOutput)
{
    *steeringOutput = filteredInfoOutput->unk08 * unk08;
    S00e43f70_Vec v;
    v.hkVector4_setRotatedDir(*(char**)(vehicle + 0x18) + 0xf0, *(char**)(vehicle + 0x1c) + 0x40);
    LocalM128 w = _mm_load_ps((const float*)(*(char**)(vehicle + 0x18) + 0x1b0));
    LocalM128 p = _mm_mul_ps(w, v.q);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    LocalM128 vDot = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    float dot;
    _mm_store_ss(&dot, vDot);
    if (dot > unk0c)
    {
        dot = unk0c / dot;
        *steeringOutput = *steeringOutput * dot * dot;
    }
}

struct hkOutputE440
{
    float m_uiFilterValue;
    float* m_weights;
};

class hkBaseE440
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10(float t, int a, int b, hkOutputE440* out);
};

class hkMaskedE440 : public hkBaseE440
{
  public:
    int unk04[3];
    char* m_uiMask;
    int m_numMask;

    void hkpVehicleDefaultSteering_calcSteering(float deltaTime, int vehicle, int filteredInfoOutput, hkOutputE440* steeringOutput);
};

// @fnv 0x00e44010
// src: HAVOK_LIB 0x00e44010
// pdb: hkpVehicleDefaultSteering::calcSteering | hkpVehicleDefaultSteering.obj | retail, upstream name already matches, high
// pdb params: deltaTime, vehicle, filteredInfoOutput, steeringOutput
void hkMaskedE440::hkpVehicleDefaultSteering_calcSteering(float deltaTime, int vehicle, int filteredInfoOutput, hkOutputE440* steeringOutput)
{
    vfn_10(deltaTime, vehicle, filteredInfoOutput, steeringOutput);
    for (int i = 0; i < m_numMask; i++)
    {
        if (m_uiMask[i])
            steeringOutput->m_weights[i] = steeringOutput->m_uiFilterValue;
        else
            steeringOutput->m_weights[i] = 0.0f;
    }
}
