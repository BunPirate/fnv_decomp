// gamebryo2.2/corelibs/nimain/niquaternion.cpp: NiQuaternion, NiColorA (15 functions)

#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl cos(double);
extern "C" double __cdecl sin(double);

// Normalizes the quaternion by computing the reciprocal of the square root of the sum of squares and scaling all four components by it.
// @fnv 0x00a38560
// pdb: NiTMapBase<DFALL<NiTMapItem<unsigned int,VertexDist> >,unsigned int,VertexDist>::GetAt | GlobalFunc.obj | retail, object-file run extension, low
// pdb params: key, val
// pdb locals: pkItem, uiIndex
void NiQuaternion::MakeUnitLength()
{
    float fNorm =
        m_fW * m_fW + m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ;
    float fScale = 1.0f / static_cast<float>(sqrt(fNorm));
    m_fW *= fScale;
    m_fX *= fScale;
    m_fY *= fScale;
    m_fZ *= fScale;
}

// Reads four 4-byte values (r, g, b, a) from the stream's binary reader, advancing the stream position by the bytes read.
// @fnv 0x00a69800
// pdb: NiColorA::LoadBinary | NiColor.obj | retail, upstream name already matches, high
// pdb params: stream
void NiColorA::LoadBinary(NiStream& stream)
{
    NiBinaryStream* pkStream = stream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &r, 4, &uiBytesRead, 1);
    }
    pkStream = stream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &g, 4, &uiBytesRead, 1);
    }
    pkStream = stream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &b, 4, &uiBytesRead, 1);
    }
    pkStream = stream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &a, 4, &uiBytesRead, 1);
    }
}

// Spherical interpolation between quaternions a and b by t, using a cosine-based warp, then normalizes the result.
// @fnv 0x00a6e330
// pdb: NiQuaternion::Slerp | NiQuaternion.obj | debug, upstream name already matches, high
// pdb params: t, p, q
// pdb locals: fTPrime, fCos
void NiQuaternion::Slerp(float t, const NiQuaternion& p, const NiQuaternion& q)
{
    float cosine = p.m_fW * q.m_fW + p.m_fX * q.m_fX + p.m_fY * q.m_fY +
                   p.m_fZ * q.m_fZ;
    float warped;
    if (t <= 0.5f)
        warped = CalculateSlerpWeight(t, cosine);
    else
        warped = 1.0f - CalculateSlerpWeight(1.0f - t, cosine);
    float fStart = p.m_fW;
    m_fW = fStart + warped * (q.m_fW - fStart);
    fStart = p.m_fX;
    m_fX = fStart + warped * (q.m_fX - fStart);
    fStart = p.m_fY;
    m_fY = fStart + warped * (q.m_fY - fStart);
    fStart = p.m_fZ;
    m_fZ = fStart + warped * (q.m_fZ - fStart);
    FastNormalize();
}

inline float QuaternionSqrt(float value)
{
    volatile float result = (float)sqrt(value);
    return result;
}
extern const unsigned int DAT_011a9e98[3];
__forceinline NiQuaternion::NiQuaternion()
{}
// Builds the quaternion components from a rotation matrix, using the trace branch or the largest-diagonal branch.
// @fnv 0x00a6df40
// pdb: NiQuaternion::FromRotation | NiQuaternion.obj | retail, call graph, high
// pdb params: rot
// pdb locals: fRoot, fTrace, j, k, quat, i
void NiQuaternion::FromRotationMatrix(const NiMatrix3& rot)
{
    const float (*matrix)[3] = reinterpret_cast<const float (*)[3]>(&rot);
    float root = rot.m_pEntry[0][0] + rot.m_pEntry[1][1] + rot.m_pEntry[2][2];
    if (root > 0.0f)
    {
        root = QuaternionSqrt(root + 1.0f);
        m_fW = root * 0.5;
        root = 0.5 / root;
        m_fX = (matrix[2][1] - matrix[1][2]) * root;
        m_fY = (matrix[0][2] - matrix[2][0]) * root;
        m_fZ = (matrix[1][0] - matrix[0][1]) * root;
    }
    else
    {
        unsigned int uiAxis = 0;
        if (matrix[1][1] > matrix[0][0])
            uiAxis = 1;
        if (matrix[2][2] > matrix[uiAxis][uiAxis])
            uiAxis = 2;
        unsigned int uiNextAxis = DAT_011a9e98[uiAxis];
        unsigned int uiLastAxis = DAT_011a9e98[uiNextAxis];
        root = QuaternionSqrt(matrix[uiAxis][uiAxis] - matrix[uiNextAxis][uiNextAxis] -
                              matrix[uiLastAxis][uiLastAxis] + 1.0f);
        float* apComponents[3] = {&m_fX, &m_fY, &m_fZ};
        *apComponents[uiAxis] = root * 0.5;
        root = 0.5 / root;
        m_fW = (matrix[uiLastAxis][uiNextAxis] - matrix[uiNextAxis][uiLastAxis]) * root;
        *apComponents[uiNextAxis] = (matrix[uiAxis][uiNextAxis] + matrix[uiNextAxis][uiAxis]) * root;
        *apComponents[uiLastAxis] = (matrix[uiAxis][uiLastAxis] + matrix[uiLastAxis][uiAxis]) * root;
    }
}

extern double DAT_0109c9d0;
extern double DAT_0109c9d8;

// @fnv 0x00a6dc30
// src: GAMEBRYO_LIB 0x00a6dc30
float NiQuaternion_CounterWarp(float t, float fCos)
{
    float fFactor = 1.0f - DAT_0109c9d8 * fCos;
    fFactor *= fFactor;
    float fK = DAT_0109c9d0 * fFactor;
    return t * (fK * t * (2.0f * t - 3.0) + 1.0f + fK);
}

// Interpolates p to q and a to b by t, then slerps between those two results by 2*t*(1-t) into self.
// @fnv 0x00a6e430
// src: COMMUNITY 0x00a6e430
// pdb: NiQuaternion::Squad | NiQuaternion.obj | retail, upstream name already matches, high
// pdb params: t, p, a, b, q
// pdb locals: q1, q2
void __fastcall NiQuaternion_Squad(NiQuaternion* self, int edx, float afTime, const NiQuaternion& aStart,
                             const NiQuaternion& aStart2, const NiQuaternion& aEnd2, const NiQuaternion& aEnd)
{
    NiQuaternion q1;
    NiQuaternion q2;
    q1.Slerp(afTime, aStart, aEnd);
    q2.Slerp(afTime, aStart2, aEnd2);
    self->Slerp(2.0f * afTime * (1.0f - afTime), q1, q2);
}

extern unsigned char DAT_011F3FE4;

// @fnv 0x00a4ffe0
// src: COMMUNITY 0x00a4ffe0
unsigned char* __cdecl NiBSplineTransformInterpolator_GetRTTI()
{
    return &DAT_011F3FE4;
}

extern float DAT_011F3FEC;
extern float DAT_011F3FF0;

static inline float isqrt_approx_in_neighborhood(float s)
{
    return DAT_011F3FF0 + DAT_011F3FEC * (s - 0.9590659737586975);
}

// @fnv 0x00a4ff00
// src: XBOX_DEBUG_PDB 0x00a4ff00
// pdb: NiQuaternion::FastNormalize | NiBSplineTransformInterpolator.obj | debug, call graph (shared callers), high
// pdb locals: D, Rsq, quat, Result
void NiQuaternion::FastNormalize()
{
    float s =
        m_fY * m_fY + m_fX * m_fX + m_fZ * m_fZ + m_fW * m_fW;
    float fScale = isqrt_approx_in_neighborhood(s);
    if (s <= 0.9152119755744934)
    {
        fScale *= isqrt_approx_in_neighborhood(fScale * fScale * s);
        if (s <= 0.6521196961402893f)
        {
            fScale *= isqrt_approx_in_neighborhood(fScale * fScale * s);
        }
    }
    m_fX = m_fX * fScale;
    m_fY = fScale * m_fY;
    m_fZ = m_fZ * fScale;
    m_fW = m_fW * fScale;
}

template <class T> inline unsigned int BinaryWriteValue(NiBinaryStream* pkStream, const T& value)
{
    unsigned int uiComponentSize = sizeof(T);
    unsigned int uiBytes = pkStream->m_pfnWrite(pkStream, &value, sizeof(T), &uiComponentSize, 1);
    pkStream->m_uiAbsoluteCurrentPos += uiBytes;
    return uiBytes;
}

template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    NiBinaryStream* pkStream = kStream.m_pkOstr;
    BinaryWriteValue(pkStream, value);
}

// @fnv 0x00a6e4a0
// pdb: NiQuaternion::SaveBinary | NiQuaternion.obj | retail, upstream name already matches, high
// pdb params: stream
void NiQuaternion::SaveBinary(NiStream* stream)
{
    NiStream& kStream = *stream;
    Snap();
    SerializeValue(kStream, m_fW);
    SerializeValue(kStream, m_fX);
    SerializeValue(kStream, m_fY);
    SerializeValue(kStream, m_fZ);
}

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl acos(double);

extern double DAT_0101a6b0;
extern float DAT_0109c9c4;
static const float epsilon = 0.001f;

// Computes the rotation angle from the quaternion's w component and normalizes the xyz vector into an axis, zeroing both when the vector length is below epsilon.
// @fnv 0x00a6de50
// pdb: NiQuaternion::ToAngleAxis | NiQuaternion.obj | debug, object-file run extension, low
// pdb params: angle, axis
// pdb locals: length, invLength
void NiQuaternion::GetAngleAxis(float* angle, NiPoint3* axisPoint)
{
    float* axis = axisPoint->components;
    float fSquaredLength = m_fX * m_fX + m_fY * m_fY + m_fZ * m_fZ;
    volatile float root = (float)sqrt(fSquaredLength);
    float length = root;

    if (length < epsilon)
    {
        *angle = 0;
        axis[0] = 0;
        axis[1] = 0;
        axis[2] = 0;
        return;
    }

    float w = m_fW;
    float fHalfAngle;
    if (w > DAT_0101a6b0)
    {
        if (w < 1.0f)
        {
            volatile float acosRoot = (float)acos(w);
            fHalfAngle = acosRoot;
        }
        else
        {
            fHalfAngle = 0;
        }
    }
    else
    {
        fHalfAngle = DAT_0109c9c4;
    }

    *angle = fHalfAngle + fHalfAngle;
    float invLength = 1.0f / length;
    axis[0] = invLength * m_fX;
    axis[1] = invLength * m_fY;
    axis[2] = invLength * m_fZ;
}

extern "C" double __cdecl fabs(double x);

inline float NiAbsA6E(float fValue)
{
    return (float)fabs(fValue);
}

static const float g_fSnapEpsilonA6E = 1e-08f;

// Sets each quaternion component to zero when its absolute value is at most g_fSnapEpsilonA6E but not already zero.
// @fnv 0x00a6e0f0
// pdb: NiQuaternion::Snap | NiQuaternion.obj | debug, upstream name already matches, high
// pdb locals: epsilon
void NiQuaternion::Snap()
{
    if (NiAbsA6E(m_fX) <= g_fSnapEpsilonA6E && m_fX != 0.0f)
        m_fX = 0.0f;
    if (NiAbsA6E(m_fY) <= g_fSnapEpsilonA6E && m_fY != 0.0f)
        m_fY = 0.0f;
    if (NiAbsA6E(m_fZ) <= g_fSnapEpsilonA6E && m_fZ != 0.0f)
        m_fZ = 0.0f;
    if (NiAbsA6E(m_fW) <= g_fSnapEpsilonA6E && m_fW != 0.0f)
        m_fW = 0.0f;
}

struct Quaternion
{
    float w, x, y, z;
    Quaternion* MultiplyQuaternion(Quaternion* out, const Quaternion* right);
};
Quaternion* __cdecl NiQuaternion_Log(Quaternion* out, const Quaternion* in);
void __cdecl NiQuaternion_Exp(Quaternion* out, const Quaternion* in);
extern const double DAT_0109c9e0;

// Combines two results from FUN_00a6dc90, scales their sum, passes it to FUN_00a88970, then multiplies by current.
// @fnv 0x00a6dd50
// src: COMMUNITY 0x00a6dd50
// pdb: NiQuaternion::Intermediate | NiQuaternion.obj | retail, upstream name already matches, high
// pdb params: q0, q1, q2
// pdb locals: inv, exp
Quaternion* __cdecl NiQuaternion_Intermediate(Quaternion* output, const Quaternion* previous, Quaternion* current,
                                 const Quaternion* next)
{
    Quaternion inverse;
    inverse.w = current->w;
    inverse.x = -current->x;
    inverse.y = -current->y;
    inverse.z = -current->z;

    Quaternion qProductNext;
    Quaternion qLogNext;
    volatile Quaternion* pLogNext = NiQuaternion_Log(&qLogNext, inverse.MultiplyQuaternion(&qProductNext, next));

    Quaternion qProductPrev;
    Quaternion qLogPrev;
    Quaternion* pLogPrev = NiQuaternion_Log(&qLogPrev, inverse.MultiplyQuaternion(&qProductPrev, previous));

    inverse.w = pLogNext->w + pLogPrev->w;
    inverse.x = pLogNext->x + pLogPrev->x;
    inverse.y = pLogNext->y + pLogPrev->y;
    inverse.z = pLogNext->z + pLogPrev->z;

    Quaternion qScaled;
    qScaled.w = (float)(DAT_0109c9e0 * inverse.w);
    qScaled.x = (float)(DAT_0109c9e0 * inverse.x);
    qScaled.y = (float)(DAT_0109c9e0 * inverse.y);
    qScaled.z = (float)(DAT_0109c9e0 * inverse.z);

    Quaternion qExponential;
    NiQuaternion_Exp(&qExponential, &qScaled);
    current->MultiplyQuaternion(output, &qExponential);
    return output;
}

#include <math.h>
extern const float g_fQuatPi;  // 0x0109c9c4

inline float NiACos(float fValue)
{
    if (-1.0 < fValue)
    {
        if (fValue < 1.0f)
            return float(acos(fValue));
        else
            return 0.0f;
    }
    else
    {
        return g_fQuatPi;
    }
}

inline float NiSin(float fRadians)
{
    return sin(fRadians);
}

inline float NiAbs(float fValue)
{
    return float(fabs(fValue));
}

// Sets vector x to zero and scales the other vector components and scalar part by a coefficient derived from arccosine of vector x.
// @fnv 0x00a6dc90
// src: GAMEBRYO_LIB 0x00a6dc90
// pdb: NiQuaternion::Log | NiQuaternion.obj | retail, upstream name already matches, high
// pdb params: q
// pdb locals: angle, coeff, sn
NiQuaternion __cdecl NiQuaternion_Log(const NiQuaternion& q)
{
    // q = cos(A)+sin(A)*(x*i+y*j+z*k), log(q) = A*(x*i+y*j+z*k)
    float fAngleDifference = NiACos(q.m_fW);
    float fSin = NiSin(fAngleDifference);
    float fCoeff;
    if (NiAbs(fSin) < 1e-03f)
        fCoeff = 1.0f;
    else
        fCoeff = fAngleDifference / fSin;

    NiQuaternion kResult;
    kResult.m_fW = 0.0f;
    kResult.m_fX = fCoeff * q.m_fX;
    kResult.m_fY = fCoeff * q.m_fY;
    kResult.m_fZ = fCoeff * q.m_fZ;
    return kResult;
}

// Computes a quaternion from three Euler angles (afXAngle, afYAngle, afZAngle) and stores the result in the vector and scalar parts.
// @fnv 0x00a6e1f0
// pdb: NiQuaternion::FromEulerAnglesXYZ | NiQuaternion.obj | debug, object-file gap fill, medium
// pdb params: afXAngle, afYAngle, afZAngle
// pdb locals: sz, cz, cy, cycz, sysz, cx, sx, sy
void NiQuaternion::SetRotationFromEulerXYZ(float afXAngle, float afYAngle, float afZAngle)
{
    afXAngle = -afXAngle * 0.5;
    float cx = (float)cos(afXAngle);
    afYAngle = afYAngle * 0.5;
    float cy = (float)cos(afYAngle);
    afZAngle = -afZAngle * 0.5;
    float cz = (float)cos(afZAngle);
    float sx = (float)sin(afXAngle);
    float sy = (float)sin(afYAngle);
    float sz = (float)sin(afZAngle);
    float cycz = cy * cz;
    float sysz = sy * sz;
    m_fW = cx * cycz + sx * sysz;
    m_fX = sx * cycz - cx * sysz;
    m_fY = cx * sy * cz + sx * cy * sz;
    m_fZ = cx * cy * sz - sx * sy * cz;
}

#include <string.h>
extern char* __cdecl NiSprintf(char*, unsigned int, const char*, ...);
extern void* __cdecl _NiMalloc(unsigned int);

// Allocates a buffer and writes the prefix and quaternion components using the shown format string.
// @fnv 0x00a6e190
// src: XBOX_RETAIL_PDB 0x00a6e190
// pdb: NiQuaternion::GetViewerString | NiQuaternion.obj | retail, string-set bridge, high
// pdb params: pcPrefix
// pdb locals: pcString, uiLen
char* NiQuaternion::GetViewerString(char* pcPrefix)
{
    unsigned int uiLen = strlen(pcPrefix) + 0x80;
    char* pcString = (char*)_NiMalloc(uiLen);
    NiSprintf(pcString, uiLen, "%s: (w=%g,x=%g,y=%g,z=%g)", pcPrefix, m_fW, m_fX, m_fY, m_fZ);
    return pcString;
}
