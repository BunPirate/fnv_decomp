#include "../../../../include/NiHalfSpaceBV.h"
#include "../../../../include/NiBoundingVolume.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/NiSphere.h"
#include "../../../../include/NiPoint3.h"
// LocalVec3: unit-local copy of the former shared stand-in Vec3. Same layout as NiPoint3; this unit defines inline bodies for both NiPoint3 and the stand-in in different forms (constructor/temporary, operand order), so one NiPoint3 cannot carry both.
#include "../../../../include/NiPoint3.h"
class Allocator;
class Elem16;
struct Mat;
struct Matrix4;
class NiPoint3;

struct LocalVec3
{
public:
    union
    {
        float x;
        unsigned int xb;
    };
    union
    {
        float y;
        unsigned int yb;
    };
    union
    {
        float z;
        unsigned int zb;
    };

    LocalVec3();
    // Keep the implicit copy constructor trivial for by-value calls.
    LocalVec3(float x, float y = 0.0f, float z = 0.0f);
    LocalVec3(const float* data);

    __forceinline LocalVec3& operator=(const LocalVec3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    LocalVec3 operator+(const LocalVec3& other) const;
    LocalVec3 operator-(const LocalVec3& other) const;
    NiPoint3 operator-(const NiPoint3& other) const;
    LocalVec3 operator-() const;
    LocalVec3 operator*(float scale) const;
    LocalVec3 operator*(double scale) const;
    LocalVec3& operator+=(const LocalVec3& other);
    LocalVec3& operator*=(float scale);
    LocalVec3& operator/=(float scale);
    bool operator==(const LocalVec3& other) const;
    bool operator!=(const LocalVec3& other) const;
    float& operator[](int index);
    float& operator[](unsigned int index);

    LocalVec3* Self();
    void Set(float x, float y, float z);
    void AssignOutput(const LocalVec3& other);
    LocalVec3 Neg() const;
    LocalVec3 Add(const LocalVec3& other) const;
    LocalVec3 Added(const LocalVec3& other) const;
    LocalVec3& AddTo(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other);
    LocalVec3 AddVector(const LocalVec3& other) const;
    void Subtract(const LocalVec3& other);
    LocalVec3 Scale(float scale) const;
    LocalVec3 ApplyScaled(float scale);
    LocalVec3 ApplyScaled(float scale) const;
    LocalVec3 ScaleSwizzled(float scale);
    LocalVec3 ScaleSwizzled(float scale) const;
    void ScaleByInverse(float scale);
    void Normalize();
    void Unitize();
    LocalVec3 Cross(const LocalVec3& other) const;
    float Dot(const LocalVec3& other) const;
    float DotProduct(const LocalVec3& other);
    float DotProduct(const LocalVec3& other) const;
    float DotProduct(const LocalVec3* other) const;
    float Length() const;
    float LengthSquared() const;
    float GetSquaredXYLength();
    float GetSquaredXYLength() const;
    Elem16& expand(Allocator& allocator);

    void SetComponents(float x, float y, float z);
    bool FUN_00439090(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other);
    bool HasEqualComponents(const LocalVec3* other) const;
    bool HasEqualComponents(const char* other);
    void ScaleComponents(float scale);
    LocalVec3 FUN_00439e90(const LocalVec3& other);
    LocalVec3 FUN_00439e90(const LocalVec3& other) const;
    void SubtractIntoVector();
    LocalVec3 SubtractIntoVector(const LocalVec3& other);
    LocalVec3 SubtractIntoVector(const LocalVec3& other) const;
    LocalVec3 SubtractIntoVector(LocalVec3* other);
    LocalVec3 SubtractIntoVector(const LocalVec3* other);
    void SubtractIntoVector(LocalVec3* output, const LocalVec3* other);
    LocalVec3* SubtractIntoVector(void* output, void* other);
    void FUN_0043d410(float x, int y, int z);
    void FUN_0043d410(float x, unsigned int y, unsigned int z);
    float FUN_00457910();
    float FUN_00457990();
    float FUN_00457990() const;
    void Unitize_004a0c10();
    float FUN_004a7290();
    float FUN_004a7290() const;
    LocalVec3 FUN_004b3800(const LocalVec3& pt) const;
    LocalVec3 ProcessAndReturnValue_0053d280(float divisor);
    float NiPoint3_XYLength();
    float NiPoint3_XYLength() const;
    void ComputeValue_0063c8a0(const LocalVec3* other);
    void ComputeValue_0063c8a0(void* other);
    void FUN_006815c0();
    float CVec3_Distance(LocalVec3* cVec);
    float CVec3_Distance(const LocalVec3& cVec) const;
    LocalVec3 TransformPointByMatrix4(const Mat& cTransform);
    LocalVec3 TransformPointByMatrix4(const Matrix4* cTransform);
    void Normalize_00b12790();
    LocalVec3 Diff_00b13040(void* other);
    LocalVec3 Diff_00b13040(const LocalVec3& other) const;
    float FUN_00b2a180(void* other);
    LocalVec3& AddComponents(void* other);
    void ProcessEntries_00ddc870();
    void FUN_00e0f6e0();
};
inline NiBoundingVolume::NiBoundingVolume() {}

// Preserve the collision routines' inline arithmetic with the shared types.
inline LocalVec3::LocalVec3() {}
inline float LocalVec3::Dot(const LocalVec3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline LocalVec3 LocalVec3::operator-(const LocalVec3& point) const
{
    LocalVec3 result;
    result.x = x - point.x;
    result.y = y - point.y;
    result.z = z - point.z;
    return result;
}
inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kV) const
{
    return NiPoint3(x - kV.x, y - kV.y, z - kV.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kV) const
{
    return NiPoint3(x + kV.x, y + kV.y, z + kV.z);
}
inline NiPoint3 NiPoint3::operator*(float fK) const
{
    return NiPoint3(fK * x, fK * y, fK * z);
}
inline float NiPoint3::operator*(const NiPoint3& kV) const
{
    return x * kV.x + y * kV.y + z * kV.z;
}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
inline NiPoint3& NiPoint3::operator-=(const NiPoint3& kV)
{
    x -= kV.x;
    y -= kV.y;
    z -= kV.z;
    return *this;
}
inline NiPoint3 operator*(float scale, const NiPoint3& point)
{
    return NiPoint3(scale * point.x, scale * point.y, scale * point.z);
}

// Inline geometric views preserve the arithmetic of the collision routines.
template <class Point>
inline const Point& PlaneNormal(const NiPlane& plane)
{
    return *reinterpret_cast<const Point*>(&plane);
}

template <class Point>
inline float PlaneDistance(const NiPlane& plane, const Point& point)
{
    return PlaneNormal<Point>(plane) * point - plane.m_fConstant;
}

template <>
inline float PlaneDistance<LocalVec3>(const NiPlane& plane, const LocalVec3& point)
{
    return PlaneNormal<LocalVec3>(plane).Dot(point) - plane.m_fConstant;
}

// src/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nihalfspacebv.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl SetFromPlane(const NiBoundingVolume* kABV);

// @fnv 0x00e9cc10
// src: GAMEBRYO_LIB 0x00e9cc10
// pdb: NiHalfSpaceBV::Copy | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: kABV
// pdb locals: kHBV
void __cdecl NiHalfSpaceBV_Copy(const NiBoundingVolume* kABV)
{
    SetFromPlane(kABV + 1);
}

// @fnv 0x00e9e670
// src: COMMUNITY 0x00e9e670
int __cdecl NiTexturingProperty_GetType_00e9e670()
{
    return 5;
}

// Saves the bounding volume, sphere and color sub-objects to the stream in sequence.
// @fnv 0x00e9cb80
// src: GAMEBRYO_SRC 0x00e9cb80
void NiHalfSpaceBV::SaveBinary_00e9cb80(NiStream& kStream)
{
    ((NiBoundingVolume*)this)->NiBoundingVolume::SaveBinary(kStream);
    ((NiSphere*)((char*)this + 4))->SaveBinary(kStream);
    ((NiColor*)((char*)this + 0x14))->SaveBinary(kStream);
}

// Compares the type and half-space plane of the two bounding volumes.
// @fnv 0x00e9cc20
// pdb: NiHalfSpaceBV::operator!= | NiHalfSpaceBV.obj | debug, object-file run extension, low
// pdb params: kABV
int NiHalfSpaceBV::MatchesBoundingVolume(const NiBoundingVolume& kABV) const
{
    if (kABV.F3() == 5)
    {
        if (reinterpret_cast<const NiPlane*>(reinterpret_cast<const char*>(&kABV) + 4)
                ->operator==(*reinterpret_cast<const NiPlane*>(reinterpret_cast<const char*>(this) + 4)))
            return 1;
    }
    return 0;
}

extern NiPoint3 DAT_011a9478;
extern NiPoint3 _NiPoint3_ZERO;
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;

// @fnv 0x00e9e700
// src: GAMEBRYO_SRC 0x00e9e700
// pdb: NiHalfSpaceBV::Create | NiHalfSpaceBV.obj | retail, upstream name already matches, high
NiBoundingVolume* NiHalfSpaceBV_Create()
{
    NiHalfSpaceBV* p = (NiHalfSpaceBV*)g_memoryManager.Allocate(32);
    if (p)
        return p->NiHalfSpaceBV_00e9e680(_NiPoint3_ZERO, DAT_011a9478);
    return 0;
}

struct D_00e9e980
{
    char _00[8];
    void** m_pp;
    char _0C[2];
    unsigned short m_cnt;
    char _10[4];
    int m_found;
};
bool __cdecl NiBoundingVolume_TestIntersect(float, void*, void*, void*, void*);
// Scans the pointer array in d up to m_cnt, calls CallConditionFunction on each element, and on success stores the index in m_found and returns true.
// @fnv 0x00e9e980
// src: GAMEBRYO_LIB 0x00e9e980
// pdb: NiUnionBV::UnionOtherTestIntersect | NiUnionBV.obj | retail, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1
// pdb locals: kUnionABV0, i, pkABV
bool __cdecl NiUnionBV_UnionOtherTestIntersect(float fTime, D_00e9e980* kABV0, void* kV0, void* kABV1, void* kV1)
{
    unsigned int i = 0;
    for (; i < kABV0->m_cnt; ++i)
    {
        void* e = kABV0->m_pp[i];
        if (NiBoundingVolume_TestIntersect(fTime, e, kV0, kABV1, kV1))
        {
            kABV0->m_found = (int)i;
            return true;
        }
    }
    return false;
}

// Links the object to the stream, then loads the plane and center point from the stream.
// @fnv 0x00e9cb50
// src: GAMEBRYO_SRC 0x00e9cb50
void NiHalfSpaceBV::LoadBinary_00e9cb50(NiStream& stream)
{
    reinterpret_cast<NiObject*>(this)->NiObject::LinkObject(stream);
    m_kHalfSpacePlane.LoadBinary(stream);
    m_kCenter.LoadBinary(stream);
}

// Copies the plane normal into this half-space and stores the distance divided by the normal's length.
// @fnv 0x00e9cbb0
// pdb: NiHalfSpaceBV::SetPlane | NiHalfSpaceBV.obj | debug, object-file run extension, low
// pdb params: kPlane
// pdb locals: kNormal, fConstant, fLength
void NiHalfSpaceBV::SetFromPlane(const NiPlane* apPlane)
{
    NiPoint3 normalized = *reinterpret_cast<const NiPoint3*>(apPlane);
    const double originalDistance = apPlane->m_fConstant;
    float adjustedDistance = static_cast<float>(originalDistance / reinterpret_cast<NiPoint3*>(&normalized)->FUN_00457910());
    *reinterpret_cast<NiPoint3*>(&m_kHalfSpacePlane) = normalized;
    m_kHalfSpacePlane.m_fConstant = adjustedDistance;
}

struct AffineMatrix
{
    float r00, r01, r02, r10, r11, r12, r20, r21, r22, t0, t1, t2, scale;
};

// @fnv 0x00e9cc60
// pdb: NiHalfSpaceBV::UpdateWorldData | NiHalfSpaceBV.obj | debug, object-file run extension, low
// pdb params: kModelABV, kWorld
// pdb locals: kModelHlfABV, kNormal, fConstant
void NiHalfSpaceBV::TransformPlane(const NiHalfSpaceBV& source, const AffineMatrix& matrix)
{
    NiPoint3 transformedNormal;
    const volatile float& x = source.m_kHalfSpacePlane.m_kNormal;
    const volatile float& m = matrix.r00;
    transformedNormal.x = m * x + matrix.r01 * source.m_kHalfSpacePlane.y + matrix.r02 * source.m_kHalfSpacePlane.z;
    transformedNormal.y = matrix.r10 * source.m_kHalfSpacePlane.m_kNormal + matrix.r11 * source.m_kHalfSpacePlane.y + matrix.r12 * source.m_kHalfSpacePlane.z;
    transformedNormal.z = matrix.r20 * source.m_kHalfSpacePlane.m_kNormal + matrix.r21 * source.m_kHalfSpacePlane.y + matrix.r22 * source.m_kHalfSpacePlane.z;
    const volatile NiPoint3& t = transformedNormal;
    float translation = matrix.t0 * t.x + matrix.t1 * t.y + matrix.t2 * t.z;
    double newDistance = static_cast<volatile float&>(translation);
    newDistance += matrix.scale * source.m_kHalfSpacePlane.m_fConstant;
    float result = (float)newDistance;
    *reinterpret_cast<NiPoint3*>(&m_kHalfSpacePlane) = transformedNormal;
    m_kHalfSpacePlane.m_fConstant = result;
}

struct V3
{
    float x;
    float y;
    float z;
};

struct PB
{
    char _0[0x20];
    V3 u;
    V3 w;
    float r;
};
static float Dot(const V3& l, const V3& r)
{
    return l.x * r.x + l.y * r.y + l.z * r.z;
}
// @fnv 0x00e9cf50
// src: GAMEBRYO_LIB 0x00e9cf50
// pdb: NiHalfSpaceBV::HalfSpaceCapsuleTestIntersect | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1
// pdb locals: kCapsule, fRHS, fSignedDistance0, fNdV, kCapABV, kDeltaV, kHalfABV, fSignedDistance1, kPlane
bool __cdecl NiHalfSpaceBV_HalfSpaceCapsuleTestIntersect(float fTime, NiHalfSpaceBV* kABV0, V3* kV0, PB* kABV1, V3* kV1)
{
    float dist = Dot(kABV1->u, PlaneNormal<V3>(kABV0->m_kHalfSpacePlane));
    dist = dist - kABV0->m_kHalfSpacePlane.m_fConstant;
    float t = -kABV1->r;
    if (dist >= t)
        return true;
    float d2 = Dot(kABV1->w, PlaneNormal<V3>(kABV0->m_kHalfSpacePlane));
    d2 = d2 + dist;
    if (d2 >= t)
        return true;
    V3 v;
    v.x = kV1->x - kV0->x;
    v.y = kV1->y - kV0->y;
    v.z = kV1->z - kV0->z;
    float fDot = PlaneNormal<V3>(kABV0->m_kHalfSpacePlane).x * v.x + PlaneNormal<V3>(kABV0->m_kHalfSpacePlane).y * v.y + PlaneNormal<V3>(kABV0->m_kHalfSpacePlane).z * v.z;
    if (fDot <= 0.0f)
        return false;
    float e = -(fDot * fTime + kABV1->r);
    return e <= dist || d2 >= e;
}

#pragma warning(disable: 4483)
extern void (__cdecl *const __identifier("??_7NiHalfSpaceBV@@6B@")[])();

// The shared initializer names the constructor entry point without introducing
// destructor cleanup that the original constructor does not have.
// @fnv 0x00e9e680
// src: GAMEBRYO_LIB 0x00e9e680
// pdb: NiHalfSpaceBV::NiHalfSpaceBV | NiHalfSpaceBV.obj | retail, call graph (shared callers), high
// pdb params: kABV
NiBoundingVolume* NiHalfSpaceBV::NiHalfSpaceBV_00e9e680(const NiPoint3& kPoint, const NiPoint3& kNormal)
{
    *reinterpret_cast<const void**>(this) = reinterpret_cast<const void*>(__identifier("??_7NiHalfSpaceBV@@6B@"));
    m_kHalfSpacePlane.NiPlane::NiPlane();
    m_kCenter = kPoint;
    NiPlane m_kFogPlane;
    *reinterpret_cast<NiPoint3*>(&m_kFogPlane) = kNormal;
    m_kFogPlane.m_fConstant = kPoint.x * kNormal.x + kPoint.y * kNormal.y + kPoint.z * kNormal.z;
    SetFromPlane(m_kFogPlane);
    return this;
}

// Allocates a half-space, initializes its plane, and copies the plane and center.
// @fnv 0x00e9e730
// src: GAMEBRYO_SRC 0x00e9e730
// pdb: NiHalfSpaceBV::Clone | NiHalfSpaceBV.obj | retail, object-file gap fill, high
// pdb locals: pkClone
NiBoundingVolume* NiHalfSpaceBV::Clone_00e9e730()
{
    NiHalfSpaceBV* clone = static_cast<NiHalfSpaceBV*>(g_memoryManager.Allocate(sizeof(NiHalfSpaceBV)));
    if (clone)
    {
        // Explicit constructor calls are supported by the original MSVC compiler.
        *reinterpret_cast<const void**>(clone) = reinterpret_cast<const void*>(__identifier("??_7NiHalfSpaceBV@@6B@"));
        clone->m_kHalfSpacePlane.NiPlane::NiPlane();
        clone->SetFromPlane(&m_kHalfSpacePlane);
        clone->m_kCenter = this->m_kCenter;
        return clone;
    }
    return 0;
}

extern NiPoint3 DAT_011a9478;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 _NiPoint3_ZERO;

extern P03MM g_memoryManager;

NiBoundingVolume* NiHalfSpaceBV_Create();

// Allocates a half-space from two point constants, then loads it from the stream.
// @fnv 0x00e9e780
// src: XBOX_RETAIL_PDB 0x00e9e780
// pdb: NiHalfSpaceBV::CreateFromStream | NiHalfSpaceBV.obj | retail, object-file gap fill, high
// pdb params: kStream
// pdb locals: pkABV
NiBoundingVolume* __cdecl NiHalfSpaceBV_CreateFromStream(void* kStream)
{
    NiHalfSpaceBV* helper = static_cast<NiHalfSpaceBV*>(g_memoryManager.Allocate(0x20));

    NiBoundingVolume* result;

    if (helper)
        result = helper->NiHalfSpaceBV_00e9e680(DAT_011f426c, DAT_011a9478);
    else
        result = 0;

    result->LoadBinary(*static_cast<NiStream*>(kStream));
    return result;
}

extern "C" size_t __cdecl strlen(const char*);
void* __cdecl NiMalloc(unsigned int uiSize);
int __cdecl FUN_00a305b0(char* pcBuffer, unsigned int uiSize, const char* pcFormat, ...);

class E9E7D0StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, char*& pcValue);

    unsigned int Add(char*& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

// Formats "<pcName> = HALFSPACE_BV" into a newly allocated buffer and appends it to pkStrings.
// @fnv 0x00e9e7d0
// pdb: NiHalfSpaceBV::AddViewerStrings | NiHalfSpaceBV.obj | retail, string-set bridge, high
// pdb params: pcPrefix, pkStrings
// pdb locals: pString, uiLen
void NiHalfSpaceBV::AddViewerStrings(char* pcPrefix, NiTPrimitiveArray<char*>* pkStrings)
{
    unsigned int uiLen = strlen(pcPrefix) + 16;
    char* pcString = static_cast<char*>(NiMalloc(uiLen));
    FUN_00a305b0(pcString, uiLen, "%s = HALFSPACE_BV", pcPrefix);
    reinterpret_cast<E9E7D0StrArray*>(pkStrings)->Add(pcString);
}

// @fnv 0x00e9d070
// src: GAMEBRYO_LIB 0x00e9d070
// pdb: NiHalfSpaceBV::HalfSpaceHalfSpaceTestIntersect | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1
// pdb locals: kHalfABV0, kHalfABV1, kPlane1, kPlane0, fNdV, kDeltaV, fDot
bool __cdecl NiHalfSpaceBV_HalfSpaceHalfSpaceTestIntersect(float fTime, NiHalfSpaceBV* kABV0, NiPoint3* kV0, NiHalfSpaceBV* kABV1, NiPoint3* kV1)
{
    const NiPoint3& na = PlaneNormal<NiPoint3>(kABV0->m_kHalfSpacePlane);
    const NiPoint3& nb = PlaneNormal<NiPoint3>(kABV1->m_kHalfSpacePlane);
    float fDot = nb.y * na.y + na.x * PlaneNormal<NiPoint3>(kABV1->m_kHalfSpacePlane).x + nb.z * na.z;
    if (fDot > (double)-0.999999f)
        return true;
    if (kABV0->m_kHalfSpacePlane.m_fConstant <= -kABV1->m_kHalfSpacePlane.m_fConstant)
        return true;
    NiPoint3 vDelta;
    vDelta.x = kV1->x - kV0->x;
    vDelta.y = kV1->y - kV0->y;
    vDelta.z = kV1->z - kV0->z;
    float fT2 = na.x * vDelta.x + na.y * vDelta.y + na.z * vDelta.z;
    if (fT2 <= 0.0f)
        return false;
    return kABV0->m_kHalfSpacePlane.m_fConstant <= fT2 * fTime - kABV1->m_kHalfSpacePlane.m_fConstant;
}

class SweepPoint
{
  public:
    float x, y, z;

    SweepPoint()
    {}
    SweepPoint(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    SweepPoint operator+(const SweepPoint& pt) const;
    SweepPoint operator-(const SweepPoint& pt) const
    {
        return SweepPoint(x - pt.x, y - pt.y, z - pt.z);
    }
    SweepPoint operator-() const
    {
        return SweepPoint(-x, -y, -z);
    }
    float operator*(const SweepPoint& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
};
SweepPoint operator*(float fScalar, const SweepPoint& pt);

// @fnv 0x00e9e2c0
// src: GAMEBRYO_LIB 0x00e9e2c0
// pdb: NiHalfSpaceBV::HalfSpaceTriFindIntersect | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kVert0, kVert1, kVert2, kV1, fIntrTime, kIntrPt, bCalcNormals, kNormal0, kNormal1
// pdb locals: fSignedDistance2, fRHS, fSignedDistance0, fNdV, kDeltaV, kHalfABV, fSignedDistance1, kPlane
bool __cdecl NiHalfSpaceBV_HalfSpaceTriFindIntersect(float fRadius, const NiHalfSpaceBV& kABV0, const SweepPoint& kV0, const SweepPoint& kVert0,
                          const SweepPoint& kVert1, const SweepPoint& kVert2, const SweepPoint& kV1, float& fIntrTime,
                          SweepPoint& kIntrPt, bool bCalcNormals, SweepPoint& kNormal0, SweepPoint& kNormal1)
{
    const SweepPoint& kN = PlaneNormal<SweepPoint>(kABV0.m_kHalfSpacePlane);
    float fD0 = kN * kVert0 - kABV0.m_kHalfSpacePlane.m_fConstant;
    if (fD0 >= 0.0f)
    {
        fIntrTime = 0.0f;
        kIntrPt = kVert0;
        if (bCalcNormals)
        {
            kNormal1 = PlaneNormal<SweepPoint>(kABV0.m_kHalfSpacePlane);
            kNormal0 = -kNormal1;
        }
        return true;
    }

    float fD1 = kN * kVert1 - kABV0.m_kHalfSpacePlane.m_fConstant;
    if (fD1 >= 0.0f)
    {
        fIntrTime = 0.0f;
        kIntrPt = kVert1;
        if (bCalcNormals)
        {
            kNormal1 = PlaneNormal<SweepPoint>(kABV0.m_kHalfSpacePlane);
            kNormal0 = -kNormal1;
        }
        return true;
    }

    float fD2 = kN * kVert2 - kABV0.m_kHalfSpacePlane.m_fConstant;
    if (fD2 >= 0.0f)
    {
        fIntrTime = 0.0f;
        kIntrPt = kVert2;
        if (bCalcNormals)
        {
            kNormal1 = PlaneNormal<SweepPoint>(kABV0.m_kHalfSpacePlane);
            kNormal0 = -kNormal1;
        }
        return true;
    }

    float fSpeed = (kV1 - kV0) * PlaneNormal<SweepPoint>(kABV0.m_kHalfSpacePlane);
    if (fSpeed <= 0.0f)
        return false;

    float fThreshold = -fRadius * fSpeed;
    if (!(fThreshold <= fD0 || fThreshold <= fD1 || fThreshold <= fD2))
        return false;

    if (fD0 >= fD1)
    {
        if (fD0 >= fD2)
        {
            fIntrTime = -fD0 / fSpeed;
            kIntrPt = kVert0 + fRadius * kV1;
        }
        else
        {
            fIntrTime = -fD2 / fSpeed;
            kIntrPt = kVert2 + fRadius * kV1;
        }
    }
    else
    {
        if (fD1 >= fD2)
        {
            fIntrTime = -fD1 / fSpeed;
            kIntrPt = kVert1 + fRadius * kV1;
        }
        else
        {
            fIntrTime = -fD2 / fSpeed;
            kIntrPt = kVert2 + fRadius * kV1;
        }
    }
    if (bCalcNormals)
    {
        kNormal1 = PlaneNormal<SweepPoint>(kABV0.m_kHalfSpacePlane);
        kNormal0 = -kNormal1;
    }
    return true;
}

// pdb: structure Sphere, size 0x10 (here 0x14), 2 members
struct Sphere
{
    void* vtable;
    float cx, cy, cz, r;
};
// Checks the sphere's signed plane distance against its radius, then tests whether motion over t reaches that threshold.
// @fnv 0x00e9cd10
// src: GAMEBRYO_LIB 0x00e9cd10
// pdb: NiHalfSpaceBV::HalfSpaceSphereTestIntersect | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1
// pdb locals: kSphABV, fSignedDistance, fNdV, kDeltaV, kHalfABV, kPlane
bool __cdecl NiHalfSpaceBV_HalfSpaceSphereTestIntersect(float fTime, NiHalfSpaceBV* kABV0, LocalVec3* kV0, Sphere* kABV1, LocalVec3* kV1)
{
    float dot = kABV1->cy * static_cast<volatile float&>(kABV0->m_kHalfSpacePlane.y) + kABV1->cx * kABV0->m_kHalfSpacePlane.m_kNormal + kABV1->cz * kABV0->m_kHalfSpacePlane.z;
    float distance = dot - kABV0->m_kHalfSpacePlane.m_fConstant;
    float radius = -kABV1->r;
    if (distance >= radius)
        return true;
    LocalVec3 relative;
    relative.x = kV1->x - kV0->x;
    relative.y = kV1->y - kV0->y;
    relative.z = kV1->z - kV0->z;
    float speed = static_cast<volatile float&>(kABV0->m_kHalfSpacePlane.y) * relative.y + relative.x * kABV0->m_kHalfSpacePlane.m_kNormal + kABV0->m_kHalfSpacePlane.z * relative.z;
    if (speed <= 0.0f)
        return false;
    return distance + speed * fTime >= radius;
}

#include <math.h>
namespace fnv_00e9cde0 {
struct OrientedBoxBound
{
    LocalVec3 m_kCenter;
    LocalVec3 m_akAxes[3];
    float m_afExtents[3];
};

struct BoxBV : NiBoundingVolume
{
    OrientedBoxBound m_kBoundsBox;
};

// Tests whether an oriented box overlaps a half-space plane now or within fTime, using projected extents and relative velocity.
// @fnv 0x00e9cde0
// pdb: NiHalfSpaceBV::HalfSpaceBoxTestIntersect | NiHalfSpaceBV.obj | debug, object-file gap fill, medium
// pdb params: fTime, kABV0, kV0, kABV1, kV1
// pdb locals: kBoxABV, kBox, fSignedDistance, fNdV, kDeltaV, kHalfABV, afAxisNormalProjLength, kPlane, fRadius
bool IsIntersectingFogPlane(float fTime, const NiBoundingVolume& kBV0, const LocalVec3& kV0, const NiBoundingVolume& kBV1, const LocalVec3& kV1)
{
    const NiHalfSpaceBV& kHS = (const NiHalfSpaceBV&)kBV0;
    const BoxBV& kBox = (const BoxBV&)kBV1;
    const NiPlane& m_kFogPlane = kHS.m_kHalfSpacePlane;
    const OrientedBoxBound& box = kBox.m_kBoundsBox;

    float afD[3];
    afD[0] = box.m_akAxes[0].Dot(*reinterpret_cast<const LocalVec3*>(&m_kFogPlane)) * box.m_afExtents[0];
    afD[1] = box.m_akAxes[1].Dot(*reinterpret_cast<const LocalVec3*>(&m_kFogPlane)) * box.m_afExtents[1];
    afD[2] = box.m_akAxes[2].Dot(*reinterpret_cast<const LocalVec3*>(&m_kFogPlane)) * box.m_afExtents[2];
    float fRadius = fabsf(afD[0]) + fabsf(afD[1]) + fabsf(afD[2]);

    float fDist = box.m_kCenter.Dot(*reinterpret_cast<const LocalVec3*>(&m_kFogPlane)) - m_kFogPlane.m_fConstant;
    if (fDist >= -fRadius)
        return true;

    LocalVec3 kV = kV1 - kV0;
    float fSpeed = reinterpret_cast<const LocalVec3*>(&m_kFogPlane)->Dot(kV);
    if (fSpeed <= 0.0f)
        return false;

    return fDist + fSpeed * fTime >= -fRadius;
}
}  // namespace fnv_00e9cde0


// Tests the three vertex distances, then compares a scaled dot product with those distances.
// @fnv 0x00e9d150
// src: GAMEBRYO_LIB 0x00e9d150
// pdb: NiHalfSpaceBV::HalfSpaceTriTestIntersect | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kVert0, kVert1, kVert2, kV1
// pdb locals: fSignedDistance2, fRHS, fSignedDistance0, fNdV, kDeltaV, kHalfABV, fSignedDistance1, kPlane
bool __cdecl NiHalfSpaceBV_HalfSpaceTriTestIntersect(float fTime, NiHalfSpaceBV* kABV0, LocalVec3* kV0, LocalVec3* kVert0, LocalVec3* kVert1,
                          LocalVec3* kVert2, LocalVec3* kV1)
{
    const NiPlane& m_kFogPlane = kABV0->m_kHalfSpacePlane;
    float fDist0 = PlaneDistance<LocalVec3>(m_kFogPlane, *kVert0);
    if (fDist0 >= 0.0f)
        return true;
    float fDist1 = PlaneDistance<LocalVec3>(m_kFogPlane, *kVert1);
    if (fDist1 >= 0.0f)
        return true;
    float d2 = PlaneDistance<LocalVec3>(m_kFogPlane, *kVert2);
    if (d2 >= 0.0f)
        return true;
    LocalVec3 vDiff;
    vDiff.x = kV1->x - kV0->x;
    vDiff.y = kV1->y - kV0->y;
    vDiff.z = kV1->z - kV0->z;
    float t = PlaneNormal<LocalVec3>(kABV0->m_kHalfSpacePlane).Dot(vDiff);
    if (t <= 0.0f)
        return false;
    float s = -fTime * t;
    return s <= fDist0 || s <= fDist1 || s <= d2;
}

struct BvPt
{
    float x, y, z;
    BvPt()
    {}
    BvPt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    BvPt operator+(const BvPt& p) const
    {
        return BvPt(x + p.x, y + p.y, z + p.z);
    }
    BvPt operator-(const BvPt& p) const
    {
        return BvPt(x - p.x, y - p.y, z - p.z);
    }
    float VelocityDot(BvPt p) const
    {
        const volatile float& nx = x;
        return nx * p.x + y * p.y + z * p.z;
    }
    float operator*(const BvPt& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    BvPt operator*(float f) const
    {
        return BvPt(x * f, y * f, z * f);
    }
    BvPt operator-() const
    {
        return BvPt(-x, -y, -z);
    }
};

inline BvPt operator*(float f, const BvPt& p)
{
    return BvPt(f * p.x, f * p.y, f * p.z);
}

inline BvPt ScaleNormal(float f, const BvPt& p)
{
    float fScale = f;
    return BvPt(fScale * p.x, fScale * p.y, fScale * p.z);
}

struct SphBV : NiBoundingVolume
{
    NiSphere m_kBoundingSphere;
    const NiSphere& GetSphere() const
    {
        return m_kBoundingSphere;
    }
};

__forceinline bool SweepContact(float fTime, const NiBoundingVolume& kBV0, const BvPt& kV0,
                                const NiBoundingVolume& kBV1, const BvPt& kV1, float& fIntrTime, BvPt& kIntrPt,
                                bool bCalcNormals, BvPt& akNormal0, BvPt& akNormal1)
{
    const NiHalfSpaceBV& kHalfSpaceBV = (const NiHalfSpaceBV&)kBV0;
    const SphBV& kSphereBV = (const SphBV&)kBV1;
    const NiPlane& m_kFogPlane = kHalfSpaceBV.m_kHalfSpacePlane;
    const BvPt& kV = PlaneNormal<BvPt>(m_kFogPlane);
    const NiSphere& kSphere = kSphereBV.m_kBoundingSphere;
    const BvPt& kNormal = *reinterpret_cast<const BvPt*>(&kSphere);

    float fDistance;
    fDistance = kV * kNormal - m_kFogPlane.m_fConstant;
    float fNdV = -kSphere.m_fRadius;

    if (fDistance >= fNdV)
    {
        fIntrTime = 0.0f;
        kIntrPt = kNormal - fDistance * kV;
        if (bCalcNormals)
        {
            akNormal1 = kV;
            akNormal0 = -akNormal1;
        }
        return true;
    }

    BvPt kTargetCenter = kV1 - kV0;
    float fNegRadius;
    fNegRadius = kV.VelocityDot(kTargetCenter);
    if (fNegRadius <= 0.0f)
        return false;

    if (!(fDistance + fTime * fNegRadius >= fNdV))
        return false;

    fIntrTime = -(fDistance + kSphere.m_fRadius) / fNegRadius;

    if (bCalcNormals)
    {
        akNormal1 = kV;
        akNormal0 = -akNormal1;
    }

    kIntrPt = (kNormal + kV1 * fIntrTime) + ScaleNormal(kSphere.m_fRadius, akNormal1);
    return true;
}

// Delegates to SweepContact to compute the intersection time and point between a moving sphere and a half-space plane.
// @fnv 0x00e9d2c0
// src: GAMEBRYO_LIB 0x00e9d2c0
// pdb: NiHalfSpaceBV::HalfSpaceSphereFindIntersect | NiHalfSpaceBV.obj | debug, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1, fIntrTime, kIntrPt, bCalcNormals, kNormal0, kNormal1
// pdb locals: kSphABV, fSignedDistance, fNdV, kDeltaV, kHalfABV, kPlane
bool NiHalfSpaceBV_HalfSpaceSphereFindIntersect(float fTime, const NiBoundingVolume& kABV0, const BvPt& kV0, const NiBoundingVolume& kABV1,
                  const BvPt& kV1, float& fIntrTime, BvPt& kIntrPt, bool bCalcNormals, BvPt& kNormal0, BvPt& kNormal1)
{
    return SweepContact(fTime, kABV0, kV0, kABV1, kV1, fIntrTime, kIntrPt, bCalcNormals, kNormal0, kNormal1);
}

extern "C" void _ReadWriteBarrier();
struct Pt
{
    float x, y, z;
    Pt()
    {}
    Pt(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
    {}
    Pt operator-() const
    {
        return Pt(-x, -y, -z);
    }
    Pt operator+(const Pt& r) const
    {
        return Pt(x + r.x, y + r.y, z + r.z);
    }
    Pt operator-(const Pt& r) const
    {
        return Pt(x - r.x, y - r.y, z - r.z);
    }
    Pt operator*(float s) const
    {
        return Pt(x * s, y * s, z * s);
    }
    float operator*(const Pt& r) const
    {
        return x * r.x + y * r.y + z * r.z;
    }
};

inline float PlaneConstant(const NiHalfSpaceBV* half)
{
    return half->m_kHalfSpacePlane.m_fConstant;
}

inline Pt ScaleNormal(const Pt& p, float f)
{
    return Pt(p.x * f, p.y * f, p.z * f);
}
// Computes a point and time for the two plane inputs, with optional output normals.
// @fnv 0x00e9dfa0
// pdb: NiHalfSpaceBV::HalfSpaceHalfSpaceFindIntersect | NiHalfSpaceBV.obj | debug, object-file gap fill, medium
// pdb params: fTime, kABV0, kV0, kABV1, kV1, fIntrTime, kIntrPt, bCalcNormals, kNormal0, kNormal1
// pdb locals: kHalfABV0, kHalfABV1, kPlane1, kPlane0, fNdV, kDeltaV, fDot, fU1, fU0, fFactor, fDiff
bool __cdecl IntersectPlanes(float fTime, NiHalfSpaceBV* pkABV0, Pt* pkV0, NiHalfSpaceBV* pkABV1, Pt* pkV1, float* pfT, Pt* pkPoint,
                             bool bSide, Pt* pkSide0, Pt* pkSide1)
{
    const Pt& n0 = PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane);
    const Pt& n1 = PlaneNormal<Pt>(pkABV1->m_kHalfSpacePlane);
    double product = n1.x * n0.x;
    _ReadWriteBarrier();
    float fDot = product + n1.y * n0.y + n1.z * n0.z;
    if (fDot > -0.999999f)
    {
        float fInv = 1.0f / (1.0f - fDot * fDot);
        float fC0 = (pkABV0->m_kHalfSpacePlane.m_fConstant - pkABV1->m_kHalfSpacePlane.m_fConstant * fDot) * fInv;
        float fC1 = (pkABV1->m_kHalfSpacePlane.m_fConstant - pkABV0->m_kHalfSpacePlane.m_fConstant * fDot) * fInv;

        *pfT = 0.0f;
        *pkPoint = PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane) * fC0 + PlaneNormal<Pt>(pkABV1->m_kHalfSpacePlane) * fC1;

        if (bSide)
        {
            *pkSide0 = -PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane);
            *pkSide1 = -PlaneNormal<Pt>(pkABV1->m_kHalfSpacePlane);
        }
        return true;
    }

    if (pkABV0->m_kHalfSpacePlane.m_fConstant <= -pkABV1->m_kHalfSpacePlane.m_fConstant)
    {
        *pfT = 0.0f;
        *pkPoint = ScaleNormal(PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane), pkABV0->m_kHalfSpacePlane.m_fConstant - pkABV1->m_kHalfSpacePlane.m_fConstant);

        if (bSide)
        {
            *pkSide1 = PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane);
            *pkSide0 = PlaneNormal<Pt>(pkABV1->m_kHalfSpacePlane);
        }
        return true;
    }

    Pt kDiff = *pkV1 - *pkV0;
    float fDot2 = kDiff * PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane);
    if (!(fDot2 <= 0.0f))
    {
        if (pkABV0->m_kHalfSpacePlane.m_fConstant <= fDot2 * fTime - pkABV1->m_kHalfSpacePlane.m_fConstant)
        {
            float fW = (PlaneConstant(pkABV1) + pkABV0->m_kHalfSpacePlane.m_fConstant) / fDot2;
            *pfT = fW;
            *pkPoint = PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane) * pkABV0->m_kHalfSpacePlane.m_fConstant + *pkV0 * *pfT;

            if (bSide)
            {
                *pkSide1 = PlaneNormal<Pt>(pkABV0->m_kHalfSpacePlane);
                *pkSide0 = PlaneNormal<Pt>(pkABV1->m_kHalfSpacePlane);
            }
            return true;
        }
        return false;
    }
    return false;
}

inline float S9d540_Abs(double f)
{
    return (float)fabs(f);
}

class S9d540_Box
{
  public:
    NiPoint3 m_kCenter;
    NiPoint3 m_akAxes[3];
    float m_afExtents[3];
};
class S9d540_BoxBV
{
  public:
    void* m_vtbl;
    S9d540_Box m_kBoundsBox;
    const S9d540_Box& GetBox() const
    {
        return m_kBoundsBox;
    }
};

// Tests a moving box against a half-space plane and writes a contact time, point, and optional normals.
// @fnv 0x00e9d540
// src: GAMEBRYO_LIB 0x00e9d540
// pdb: NiHalfSpaceBV::HalfSpaceBoxFindIntersect | NiHalfSpaceBV.obj | retail, upstream name already matches, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1, fIntrTime, kIntrPt, bCalcNormals, kNormal0, kNormal1
// pdb locals: kBoxABV, kBox, fSignedDistance, fNdV, kDeltaV, kHalfABV, afAxisNormalProjLength, kPlane, fRadius, i
bool __cdecl NiHalfSpaceBV_HalfSpaceBoxFindIntersect(float fTime, const NiHalfSpaceBV& kABV0, const NiPoint3& kV0, const S9d540_BoxBV& kABV1,
                          const NiPoint3& kV1, float& fIntrTime, NiPoint3& kIntrPt, bool bCalcNormals,
                          NiPoint3& kNormal0, NiPoint3& kNormal1)
{
    const NiPlane& m_kFogPlane = kABV0.m_kHalfSpacePlane;
    const S9d540_Box& kBox = kABV1.GetBox();
    const NiPoint3& kNormal = PlaneNormal<NiPoint3>(m_kFogPlane);

    float afProj[3];
    afProj[0] = (kNormal * kBox.m_akAxes[0]) * kBox.m_afExtents[0];
    afProj[1] = (kNormal * kBox.m_akAxes[1]) * kBox.m_afExtents[1];
    afProj[2] = (PlaneNormal<NiPoint3>(kABV0.m_kHalfSpacePlane) * kBox.m_akAxes[2]) * kBox.m_afExtents[2];
    float fRadius = S9d540_Abs(afProj[0]) + S9d540_Abs(afProj[1]) + S9d540_Abs(afProj[2]);
    float fDistance = PlaneDistance<NiPoint3>(m_kFogPlane, kABV1.m_kBoundsBox.m_kCenter);

    if (fDistance >= -fRadius)
    {
        fIntrTime = 0.0f;
        kIntrPt = kBox.m_kCenter - fDistance * kNormal;
        if (bCalcNormals)
        {
            kNormal1 = kNormal;
            kNormal0 = -kNormal1;
        }
        return true;
    }

    const NiPoint3& kn2 = PlaneNormal<NiPoint3>(m_kFogPlane);
    float fNdV = (kV1 - kV0) * kn2;
    if (fNdV <= 0.0f)
        return false;
    if (fDistance + fTime * fNdV >= -fRadius)
    {
        fIntrTime = -(fDistance + fRadius) / fNdV;
        kIntrPt = kBox.m_kCenter + kV1 * fIntrTime;
        for (int i = 0; i < 3; i++)
        {
            if (S9d540_Abs(afProj[i]) > 0.001f)
            {
                if (afProj[i] > 0.0f)
                    kIntrPt += kBox.m_afExtents[i] * kBox.m_akAxes[i];
                else
                    kIntrPt -= kBox.m_afExtents[i] * kBox.m_akAxes[i];
            }
        }
        if (bCalcNormals)
        {
            kNormal0 = -kNormal;
            kNormal1 = kIntrPt - kBox.m_kCenter;
        }
        return true;
    }
    return false;
}

struct Vec72
{
    float x, y, z;
    Vec72()
    {}
    Vec72(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec72 operator+(const Vec72& b) const
    {
        return Vec72(b.x + x, b.y + y, b.z + z);
    }
    Vec72 operator-(const Vec72& b) const
    {
        return Vec72(x - b.x, y - b.y, z - b.z);
    }
    Vec72 operator-() const
    {
        return Vec72(-x, -y, -z);
    }
    Vec72 operator*(float k) const
    {
        return Vec72(x * k, y * k, z * k);
    }
    float operator*(const Vec72& b) const
    {
        return x * b.x + y * b.y + (z * b.z);
    }
};
Vec72 operator*(float k, const Vec72& v)
{
    return Vec72(k * v.x, k * v.y, k * v.z);
}

inline float NiPlane::Distance(const NiPoint3& kPoint) const
{
    return *reinterpret_cast<const Vec72*>(this) * reinterpret_cast<const Vec72&>(kPoint) - m_fConstant;
}

struct CapsuleData72
{
    Vec72 origin, direction;
    float radius;
    const Vec72& GetOrigin() const
    {
        return origin;
    }
    const Vec72& GetDirection() const
    {
        return direction;
    }
    float GetRadius() const
    {
        return radius;
    }
};
struct Capsule72
{
    void* vtbl;
    Vec72 center, axis;
    float extent;
    CapsuleData72 geometry;
    const CapsuleData72& GetGeometry() const
    {
        return geometry;
    }
};
struct Sphere72
{
    void* vtbl;
    Vec72 center;
    float radius;
    Sphere72(float, const Vec72&);
};
bool NiHalfSpaceBV_HalfSpaceSphereFindIntersect(float, const NiHalfSpaceBV&, const Vec72&, const Sphere72&, const Vec72&, float&, Vec72&, bool, Vec72&,
                  Vec72&);
// Tests a capsule against a moving half-space, using sphere tests when an endpoint is within the capsule radius of the plane.
// @fnv 0x00e9da30
// src: XBOX_RETAIL_PDB 0x00e9da30
// pdb: NiHalfSpaceBV::HalfSpaceCapsuleFindIntersect | NiHalfSpaceBV.obj | retail, object-file run extension, high
// pdb params: fTime, kABV0, kV0, kABV1, kV1, fIntrTime, kIntrPt, bCalcNormals, kNormal0, kNormal1
// pdb locals: kCapsule, fRHS, fSignedDistance0, fNdV, kCapABV, kDeltaV, kHalfABV, fSignedDistance1, kPlane, kSphABV
bool NiHalfSpaceBV_HalfSpaceCapsuleFindIntersect(float fTime, const NiHalfSpaceBV& kABV0, const Vec72& kV0, const Capsule72& kABV1,
                             const Vec72& kV1, float& fIntrTime, Vec72& kIntrPt, bool bCalcNormals,
                             Vec72* __restrict kNormal0, Vec72* kNormal1)
{
    const CapsuleData72& shape = kABV1.geometry;
    const Vec72& origin = shape.origin;
    const NiPlane& plane = kABV0.m_kHalfSpacePlane;
    const Vec72& direction = shape.direction;
    float distance0;
    float distance1;
    distance0 = kABV0.m_kHalfSpacePlane.Distance(reinterpret_cast<const NiPoint3&>(kABV1.GetGeometry().origin));
    Vec72 endpoint;
    endpoint = shape.direction + origin;
    distance1 = plane.Distance(reinterpret_cast<const NiPoint3&>(endpoint));
    if ((distance0 < 0.0f && distance1 > 0.0f) || (distance0 > 0.0f && distance1 < 0.0f))
    {
        fIntrTime = 0.0f;
        float parameter = distance0 / (distance0 - distance1);
        kIntrPt = kABV1.GetGeometry().origin + direction * parameter;
    }
    else if (-shape.radius <= distance0)
    {
        fIntrTime = 0.0f;
        Sphere72 sphere(1.0f, *(Vec72*)&DAT_011f426c);
        sphere.radius = kABV1.geometry.radius;
        if (distance1 >= -shape.radius)
        {
            sphere.center = kABV1.center;
            return NiHalfSpaceBV_HalfSpaceSphereFindIntersect(fTime, kABV0, kV0, sphere, kV1, fIntrTime, kIntrPt, bCalcNormals, *kNormal0,
                                *kNormal1);
        }
        else
        {
            sphere.center = shape.GetOrigin();
            return NiHalfSpaceBV_HalfSpaceSphereFindIntersect(fTime, kABV0, kV0, sphere, kV1, fIntrTime, kIntrPt, bCalcNormals, *kNormal0,
                                *kNormal1);
        }
    }
    else if (distance1 >= -shape.radius)
    {
        fIntrTime = 0.0f;
        Sphere72 sphere(1.0f, *(Vec72*)&DAT_011f426c);
        sphere.radius = kABV1.geometry.radius;
        sphere.center = kABV1.geometry.origin + kABV1.geometry.direction;
        return NiHalfSpaceBV_HalfSpaceSphereFindIntersect(fTime, kABV0, kV0, sphere, kV1, fIntrTime, kIntrPt, bCalcNormals, *kNormal0,
                            *kNormal1);
    }
    else
    {
        Vec72 relativeVelocity;
        relativeVelocity = kV1 - kV0;
        float rate = PlaneNormal<Vec72>(plane) * relativeVelocity;
        if (rate <= 0.0f)
            return false;
        float reach;
        reach = -(rate * fTime + shape.radius);
        if (!(distance0 >= reach || distance1 >= reach))
            return false;
        if (distance1 + 0.000001f < distance0)
        {
            fIntrTime = -(shape.radius + distance0) / rate;
            kIntrPt = origin + fIntrTime * kV1 + PlaneNormal<Vec72>(plane) * shape.radius;
        }
        else if (distance0 + 0.000001f < distance1)
        {
            fIntrTime = -(distance1 + shape.radius) / rate;
            kIntrPt = origin + shape.GetDirection() + fIntrTime * kV1 + PlaneNormal<Vec72>(plane) * shape.radius;
        }
        else
        {
            fIntrTime = -(shape.radius + distance1) / rate;
            kIntrPt = origin + direction * 0.5f + fIntrTime * kV1 + PlaneNormal<Vec72>(kABV0.m_kHalfSpacePlane) * shape.radius;
        }
    }
    if (bCalcNormals)
    {
        *kNormal1 = PlaneNormal<Vec72>(kABV0.m_kHalfSpacePlane);
        *kNormal0 = -*kNormal1;
    }
    return true;
}
