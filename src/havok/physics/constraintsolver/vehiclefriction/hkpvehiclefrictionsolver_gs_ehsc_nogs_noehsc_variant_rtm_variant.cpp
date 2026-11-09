// src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/vehiclefriction/hkpvehiclefrictionsolver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>

struct CurveInput
{
    __m128 points[2];
    __m128 origin, axis, normal, offsetDirection;
    __m128 matrix0, matrix1, matrix2;
    float common, scale0, scale1;
    float radius[2];
    float blend;
};
struct CurveBlock
{
    float samples[16];
    float multiplier, progress, scale, inverseScale, effectiveScale;
    float radius, inverseRadius, weight0, weight1;
};
struct CurveOutput
{
    float separation, common;
    CurveBlock blocks[2];
};

extern "C" double pow(double, double);
extern "C" double fabs(double);
extern "C" const double DAT_010ec9e0;

static __m128 HSum(__m128 m)
{
    __m128 t = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), t);
}

static float Abs(float x)
{
    return (float)fabs(x);
}
static float Power(float x, float y)
{
    return (float)pow(x, y);
}
static float PowerStep(float x)
{
    return (float)pow(x, DAT_010ec9e0);
}

// @fnv 0x00e593f0
// src: XBOX_PDB 0x00e593f0
// pdb: hkVehicleFrictionDescriptionInitValues | hkpVehicleFrictionSolver.obj | retail, upstream name already matches, high
// pdb params: ci, out
// pdb locals: virtInvMass, assertBuf, ostr
void hkVehicleFrictionDescriptionInitValues(CurveInput* ci, CurveOutput* out)
{
    out->common = ci->common;
    out->blocks[0].radius = ci->radius[0];
    out->blocks[1].radius = ci->radius[1];
    out->blocks[0].inverseRadius = 1.0f / ci->radius[0];
    out->blocks[1].inverseRadius = 1.0f / ci->radius[1];
    out->blocks[0].scale = ci->scale0 * out->blocks[0].inverseRadius;
    out->blocks[1].scale = ci->scale1 * out->blocks[1].inverseRadius;
    out->blocks[0].inverseScale = 1.0f / out->blocks[0].scale;
    out->blocks[1].inverseScale = 1.0f / out->blocks[1].scale;

    float d1;
    _mm_store_ss(&d1, HSum(_mm_mul_ps(ci->normal, ci->points[0])));
    float d2;
    _mm_store_ss(&d2, HSum(_mm_mul_ps(ci->points[1], ci->normal)));
    float e = Abs(d1 - d2);
    out->separation = e;
    float r = 1.0f / e;
    out->blocks[0].weight0 = 1.0f - ci->blend;
    double neg = -d2;
    out->blocks[0].weight1 = Abs(neg * r) * ci->blend;
    out->blocks[1].weight0 = 1.0f - ci->blend;
    out->blocks[1].weight1 = Abs(d1 * r) * ci->blend;

    __m128 a30 = ci->axis;
    __m128 a30c9 = _mm_shuffle_ps(a30, a30, 0xc9);
    __m128 a50 = ci->offsetDirection;
    __m128 a20 = ci->origin;
    __m128 a30d2 = _mm_shuffle_ps(a30, a30, 0xd2);

    float T[2];
    int k;
    for (k = 0; k < 2; ++k)
    {

        float s = -ci->radius[k];
        __m128 scalar = _mm_load_ss(&s);
        __m128 u = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), a50), _mm_sub_ps(ci->points[k], a20));
        __m128 uc9 = _mm_shuffle_ps(u, u, 0xc9);
        __m128 ud2 = _mm_shuffle_ps(u, u, 0xd2);
        __m128 X = _mm_sub_ps(_mm_mul_ps(uc9, a30d2), _mm_mul_ps(ud2, a30c9));
        float b4 = out->common;
        __m128 Y = _mm_mul_ps(_mm_shuffle_ps(X, X, 0), ci->matrix0);
        Y = _mm_add_ps(Y, _mm_mul_ps(_mm_shuffle_ps(X, X, 0x55), ci->matrix1));
        Y = _mm_add_ps(Y, _mm_mul_ps(_mm_shuffle_ps(X, X, 0xaa), ci->matrix2));
        float D3;
        _mm_store_ss(&D3, HSum(_mm_mul_ps(Y, X)));
        T[k] = b4 + D3;
    }

    int ebx;
    for (ebx = 0; ebx < 2; ++ebx)
    {
        CurveBlock* bp = &out->blocks[ebx];
        float r1 = T[ebx] * bp->scale;
        bp->effectiveScale = r1;
        float r2 = (float)(r1 * 0.0625);
        bp->progress = r2;
        float r3 = 1.0f / r2;
        double stepValue = PowerStep(r3);
        float r4 = (float)stepValue;
        bp->multiplier = r4;
        float inv1 = 1.0f / r1;
        int cnt;
        for (cnt = 0; cnt < 15; ++cnt)
        {
            float t = 1.0f - r2;
            float v = Power(t, inv1);
            out->blocks[ebx].samples[cnt] = 1.0f - v;
            r2 = r4 * r2;
        }
        out->blocks[ebx].samples[cnt] = 1.0f;
    }
}
