// gamebryo2.2/corelibs/nianimation/niquattransform.cpp: NiQuatTransform, QXform, QXformViewer, QXform2 (8 functions)

// Preserve the existing point declarations used by this generated unit.
#pragma include_alias("NiPoint3.h", "../../../../include/NiPoint3.h")
#include "PointStorage.h"
#include "../../../../include/NiMatrix3.h"


#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiColor.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiColorA.h"

// NiQuaternion copied as plain data: the original copies the four floats inline, while the shared class declares an
// out-of-line operator=.
struct NiQuaternionValue
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
};
extern const float kInvalidTransformValue;

__forceinline void NiBinaryStream::ReadScalar(void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, data, bytes, &size, 1);
}

// Reads translation, rotation and scale from the stream; for older versions reads validity bytes and sets invalid components to kInvalidTransformValue.
// @fnv 0x00a38bb0
// pdb: NiQuatTransform::LoadBinary | NiQuatTransform.obj | retail, upstream name already matches, high
// pdb params: kStream
// pdb locals: bValid
void NiQuatTransform::LoadBinary(NiStream& kStream)
{
    reinterpret_cast<NiColor&>(m_kTranslate).LoadBinary(kStream);
    reinterpret_cast<NiColorA&>(m_kRotate).LoadBinary(kStream);
    kStream.m_pkIstr->ReadScalar(&m_fScale, 4);
    if (kStream.m_uiNifFileVersion < 0x0A01006E)
    {
        unsigned char valid;
        kStream.m_pkIstr->ReadScalar(&valid, 1);
        if (!valid)
            m_kTranslate = kInvalidTransformValue;
        kStream.m_pkIstr->ReadScalar(&valid, 1);
        if (!valid)
            qy = kInvalidTransformValue;
        kStream.m_pkIstr->ReadScalar(&valid, 1);
        if (!valid)
            m_fScale = kInvalidTransformValue;
    }
}

struct Inner_00a6db50
{
    void __thiscall Set(float, float, float, float);
};
struct Outer_00a2bdb0
{
    int _0;
    Inner_00a6db50 _4;
    Outer_00a2bdb0* __thiscall ClearInnerVector();
};
// Calls the inner object's method with four zero floats and returns this.
// @fnv 0x00a2bdb0
// src: GUESS 0x00a2bdb0 (confidence: medium)
// pdb: NiTCBRotKey::NiTCBRotKey | NiTCBRotKey.obj | debug, object-file run extension, low
Outer_00a2bdb0* __thiscall Outer_00a2bdb0::ClearInnerVector()
{
    _4.Set(0.0f, 0.0f, 0.0f, 0.0f);
    return this;
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
struct QQuatOps
{
    NiQuaternion MultiplyQuaternion(const NiQuaternion& q) const;
    void FUN_00a38560();
};
struct QXform
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    QXform() : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(kInvalidTransformValue)
    {}
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e38;
    }
    bool IsRotateValid() const
    {
        return m_kRotate.m_fX != -3.4028234663852886e38;
    }
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e38;
    }
    void MakeScaleInvalid()
    {
        m_fScale = kInvalidTransformValue;
    }
    void MakeRotateInvalid()
    {
        m_kRotate.m_fX = kInvalidTransformValue;
    }
    void MakeTranslateInvalid()
    {
        m_kTranslate.x = kInvalidTransformValue;
    }
    QXform ProcessAndReturnValue_00a38a00(const QXform& kTransform) const;
};
// @fnv 0x00a38a00
// src: GUESS 0x00a38a00 (confidence: low)
// pdb: NiQuatTransform::operator* | NiQuatTransform.obj | retail, object-file gap fill, high
// pdb params: kTransform
// pdb locals: kDest, fScale, kTempRot
QXform QXform::ProcessAndReturnValue_00a38a00(const QXform& kTransform) const
{
    QXform kResult;
    if (IsScaleValid() && kTransform.IsScaleValid())
        kResult.m_fScale = kTransform.m_fScale * m_fScale;
    else
        kResult.MakeScaleInvalid();
    if (IsRotateValid() && kTransform.IsRotateValid())
    {
        NiQuaternion kRotate = ((const QQuatOps*)&m_kRotate)->MultiplyQuaternion(kTransform.m_kRotate);
        ((QQuatOps*)&kRotate)->FUN_00a38560();
        *(NiQuaternionValue*)&kResult.m_kRotate = *(NiQuaternionValue*)&kRotate;
    }
    else
        kResult.MakeRotateInvalid();
    if (IsTranslateValid() && kTransform.IsTranslateValid())
    {
        NiPoint3 kTranslate;
        kTranslate.x = kTransform.m_kTranslate.x + m_kTranslate.x;
        kTranslate.y = kTransform.m_kTranslate.y + m_kTranslate.y;
        kTranslate.z = kTransform.m_kTranslate.z + m_kTranslate.z;
        kResult.m_kTranslate = kTranslate;
    }
    else
        kResult.MakeTranslateInvalid();
    return kResult;
}

char* GetViewerStringName(const char* pcName);
char* GetViewerStringFloat(const char* pcName, float fValue);

struct ViewerPoint3 : NiPoint3
{
    char* FormatToBuffer(const char* pPrefix) const;
};
struct ViewerQuaternion : NiQuaternion
{
    char* GetViewerString(const char* pcName) const;
};

struct ViewerStrings
{
    virtual ~ViewerStrings();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pcElement);
    unsigned int Add(char*& pcElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
};

struct QXformViewer : QXform
{
    void NiQuatTransform_GetViewerStrings(ViewerStrings* pkStrings);
};

// Appends the class name and, when valid, the translate, rotate and scale members to the viewer string list.
// @fnv 0x00a38cb0
// src: XBOX_PDB 0x00a38cb0
// pdb: NiQuatTransform::GetViewerStrings | NiQuatTransform.obj | retail, string-set bridge, high
// pdb params: pkStrings
void QXformViewer::NiQuatTransform_GetViewerStrings(ViewerStrings* pkStrings)
{
    char* pcString = GetViewerStringName("NiQuatTransform");
    pkStrings->Add(pcString);
    if (IsTranslateValid())
    {
        char* pcString = static_cast<ViewerPoint3&>(m_kTranslate).FormatToBuffer("m_kTranslate");
        pkStrings->Add(pcString);
    }
    if (IsRotateValid())
    {
        char* pcString = static_cast<ViewerQuaternion&>(m_kRotate).GetViewerString("m_kRotate");
        pkStrings->Add(pcString);
    }
    if (IsScaleValid())
    {
        char* pcString = GetViewerStringFloat("m_fScale", m_fScale);
        pkStrings->Add(pcString);
    }
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;

struct QMat3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 MulPoint(const NiPoint3& p) const;
};
extern const QMat3 kQMat3Identity;


// Hands the scaled point back as plain point storage.
inline PointStorage ScalePoint(float f, const NiPoint3& p)
{
    PointStorage r;
    r.x = f * p.x;
    r.y = f * p.y;
    r.z = f * p.z;
    return r;
}

struct QQuatRot
{
    void ToRotationMatrix(QMat3& m) const;
};

struct QXform2
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    QXform2() : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(kInvalidTransformValue)
    {}
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e38;
    }
    bool IsRotateValid() const
    {
        return m_kRotate.m_fX != -3.4028234663852886e38;
    }
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e38;
    }
    QXform2 NiQuatTransform_HierApply(const QXform2& kTransform) const;
};

// @fnv 0x00a38830
// src: COMMUNITY 0x00a38830
// pdb: NiQuatTransform::HierApply | NiQuatTransform.obj | retail, upstream name already matches, high
// pdb params: kTransform
// pdb locals: kDest, fScale, kRotate, kTempRot
QXform2 QXform2::NiQuatTransform_HierApply(const QXform2& kTransform) const
{
    QXform2 kRes;
    float fScale = 1.0f;
    if (IsScaleValid() && kTransform.IsScaleValid())
    {
        float fNew = m_fScale * kTransform.m_fScale;
        kRes.m_fScale = fNew;
        fScale = fNew;
    }
    else
    {
        kRes.m_fScale = kInvalidTransformValue;
    }
    QMat3 kRot = kQMat3Identity;
    if (IsRotateValid() && kTransform.IsRotateValid())
    {
        NiQuaternion kQ = ((const QQuatOps*)&m_kRotate)->MultiplyQuaternion(kTransform.m_kRotate);
        ((QQuatOps*)&kQ)->FUN_00a38560();
        *(NiQuaternionValue*)&kRes.m_kRotate = *(NiQuaternionValue*)&kQ;
        ((const QQuatRot*)&m_kRotate)->ToRotationMatrix(kRot);
    }
    else
    {
        kRes.m_kRotate.m_fX = kInvalidTransformValue;
    }
    if (IsTranslateValid() && kTransform.IsTranslateValid())
    {
        PointStorage kS = ScalePoint(fScale, kRot.MulPoint(kTransform.m_kTranslate));
        NiPoint3 kSum;
        kSum.x = m_kTranslate.x + kS.x;
        kSum.y = m_kTranslate.y + kS.y;
        kSum.z = m_kTranslate.z + kS.z;
        kRes.m_kTranslate = kSum;
    }
    else
    {
        kRes.m_kTranslate.x = kInvalidTransformValue;
    }
    return kRes;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* p, unsigned int n, unsigned int* sizes,
                                                unsigned int count)
{
    unsigned int written = m_pfnWrite(this, p, n, sizes, count);
    m_uiAbsoluteCurrentPos += written;
    return written;
}

template <class T>
inline void SaveBinaryValues(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& kStream, const T& value)
{
    SaveBinaryValues(*kStream.m_pkOstr, &value);
}

// The former DataA38 is a 32-byte transform: its calls bind to NiColor::SaveBinary (0x00a69780)
// for translation and NiQuaternion::SaveBinary (0x00a6e4a0) for rotation, followed by scale.
// @fnv 0x00a38b60
// pdb: NiQuatTransform::SaveBinary | NiQuatTransform.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiQuatTransform::SaveBinary(NiStream* kStream)
{
    reinterpret_cast<NiColor&>(m_kTranslate).SaveBinary(*kStream);
    reinterpret_cast<NiQuaternion&>(m_kRotate).SaveBinary(kStream);
    SaveBinaryValue(*kStream, m_fScale);
}

// local form of NiQuaternion: 0x00a2bcf0 needs POD result construction; the shared default ctor changes bytes.
struct QQ
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    void Set(float w, float x, float y, float z);
    QQ MultiplyQuaternion(const QQ& q) const;
};
// Multiplies this quaternion by q using the Hamilton product and returns the resulting quaternion.
// @fnv 0x00a2bcf0
// src: GUESS 0x00a2bcf0 (confidence: medium)
// pdb: NiQuaternion::operator* | NiTCBRotKey.obj | retail, call graph, high
// pdb params: c
QQ QQ::MultiplyQuaternion(const QQ& aQuat) const
{
    QQ r;
    r.Set(m_fVectorX * aQuat.m_fVectorX - m_fVectorY * aQuat.m_fVectorY - m_fVectorZ * aQuat.m_fVectorZ -
              m_fScalarPart * aQuat.m_fScalarPart,
          m_fVectorX * aQuat.m_fVectorY + m_fVectorY * aQuat.m_fVectorX + m_fVectorZ * aQuat.m_fScalarPart -
              m_fScalarPart * aQuat.m_fVectorZ,
          m_fVectorX * aQuat.m_fVectorZ + m_fVectorZ * aQuat.m_fVectorX + m_fScalarPart * aQuat.m_fVectorY -
              m_fVectorY * aQuat.m_fScalarPart,
          m_fVectorX * aQuat.m_fScalarPart + m_fScalarPart * aQuat.m_fVectorX + m_fVectorY * aQuat.m_fVectorZ -
              m_fVectorZ * aQuat.m_fVectorY);
    return r;
}

#include <string.h>
// local form of NiQuaternion: 0x00a386a0 needs inline memcpy assignment; the shared out-of-line operator= changes bytes.
struct LocalQuaternionConjugateValue
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    LocalQuaternionConjugateValue& operator=(const LocalQuaternionConjugateValue& q)
    {
        memcpy(this, &q, sizeof(q));
        return *this;
    }
};
LocalQuaternionConjugateValue NiQuaternionConjugate(const LocalQuaternionConjugateValue& kQuat);
struct QuatPoint
{
    float x, y, z;
    QuatPoint()
    {}
    QuatPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    QuatPoint operator-() const
    {
        return QuatPoint(-x, -y, -z);
    }
    QuatPoint operator*(float fScale) const
    {
        QuatPoint kR;
        kR.x = x * fScale;
        kR.y = y * fScale;
        kR.z = z * fScale;
        return kR;
    }
};
// NiMatrix3::operator*(const NiPoint3&) const, inlined here over this unit's QuatPoint.
struct NiMatrix3_QuatPointView : public NiMatrix3
{
    QuatPoint operator*(const QuatPoint& kPt) const
    {
        QuatPoint kR;
        kR.x = m_pEntry[0][0] * kPt.x + m_pEntry[0][1] * kPt.y + m_pEntry[0][2] * kPt.z;
        kR.y = m_pEntry[1][0] * kPt.x + m_pEntry[1][1] * kPt.y + m_pEntry[1][2] * kPt.z;
        kR.z = m_pEntry[2][0] * kPt.x + m_pEntry[2][1] * kPt.y + m_pEntry[2][2] * kPt.z;
        return kR;
    }
};
struct QuatRotate
{
    void NiQuaternion_ToRotation(NiMatrix3& kRot) const;
};
extern char DAT_011a9448;
static const double DAT_010241b0 = -3.4028234663852886e+38;
static const float DAT_01096b8c = -3.402823466e+38f;
struct FUN_00a386a0_shell : NiQuatTransform
{
    void Inverse(NiQuatTransform& kDest);
};

// Computes the inverse transform into kDest by inverting scale, conjugating and rotating the quaternion, and transforming the translation.
// @fnv 0x00a386a0
// pdb: NiMatrix3::Inverse | GlobalFunc.obj | retail, upstream name already matches, medium
// pdb note: debug build links it to NiQuatTransform::HierInvert
// pdb locals: inv
void FUN_00a386a0_shell::Inverse(NiQuatTransform& kDest)
{
    float fInvScale = 1.0f;
    if (m_fScale == DAT_010241b0)
    {
        kDest.m_fScale = DAT_01096b8c;
    }
    else
    {
        kDest.m_fScale = 1.0f / m_fScale;
        fInvScale = kDest.m_fScale;
    }
    NiMatrix3 kRot = *(NiMatrix3*)&DAT_011a9448;
    if (qy == DAT_010241b0)
    {
        kDest.qy = DAT_01096b8c;
    }
    else
    {
        *(LocalQuaternionConjugateValue*)&kDest.m_kRotate =
            NiQuaternionConjugate(*(LocalQuaternionConjugateValue*)&m_kRotate);
        ((QuatRotate*)&kDest.m_kRotate)->NiQuaternion_ToRotation(kRot);
    }
    if (m_kTranslate == DAT_010241b0)
    {
        kDest.m_kTranslate = DAT_01096b8c;
    }
    else
    {
        *(QuatPoint*)&kDest.m_kTranslate = ((const NiMatrix3_QuatPointView&)kRot * -*(QuatPoint*)&m_kTranslate) * fInvScale;
    }
}
