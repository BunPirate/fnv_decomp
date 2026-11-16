// gamebryo2.2/corelibs/nianimation/nibsplinecomptransforminterpolator.cpp (11 functions)
#include "NiRefObject_inline.h"

#include "../../../../include/StrArr.h"
#include "../../../../include/NiBSplineCompTransformInterpolator.h"
#include "../../../../include/NiBSplineData.h"
#include "../../../../include/NiBSplineInterpolator.h"
#include "../../../../include/NiBSplineTransformInterpolator.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiQuaternion.h"
// NiStream.h currently supplies BSStreamHeader itself; BSStreamHeader.h duplicates that definition.
#include "../../../../include/NiStream.h"
#include "NiMemObject.h"
#include <string.h>

inline NiQuatTransform& NiQuatTransform::operator=(const NiQuatTransform& rhs)
{
    memcpy(this, &rhs, sizeof(*this));
    return *this;
}

inline NiQuaternion& NiQuaternion::operator=(const NiQuaternion& rhs)
{
    memcpy(this, &rhs, sizeof(*this));
    return *this;
}

inline void NiBinaryStream::ReadComp(void* value, unsigned int size, unsigned int componentSize)
{
    unsigned int uiComponentSize = componentSize;
    m_uiAbsoluteCurrentPos += m_pfnRead(this, value, size, &uiComponentSize, 1);
}

extern double _DAT_010241b0;

// NiBSplineInterpolator's copy helper is not declared by the shared header.
struct SplineBaseOperations
{
    void NiBSplineInterpolator_CopyMembers(NiBSplineInterpolator*, CloningProcess&);
    void NiBSplineInterpolator_ctor(int, int);
};

// @fnv 0x00a51140
// pdb: NiBSplineCompTransformInterpolator::LoadBinary | NiBSplineCompTransformInterpolator.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiBSplineCompTransformInterpolator::LoadBinary(NiStream& kStream)
{
    NiBSplineTransformInterpolator::LoadBinary(kStream);

    kStream.m_pkIstr->ReadComp(m_afCompScalars, 0x18, 4);
}

// Copies the spline transform interpolator's translation, rotation and scale control-point handles and an extra field into destination.
// @fnv 0x00a4fec0
// pdb: NiPointer<NiBSplineData>::operator= | NiBSplineTransformInterpolator.obj | debug, object-file run extension, low
// pdb params: pObject
__declspec(noinline) void NiBSplineCompTransformInterpolator::CopyMemberData(NiBSplineCompTransformInterpolator* destination,
                                                        CloningProcess& cloningProcess)
{
    reinterpret_cast<SplineBaseOperations*>(this)->NiBSplineInterpolator_CopyMembers(destination, cloningProcess);
    destination->m_kTransformValue = m_kTransformValue;
    destination->m_kTransCPHandle = m_kTransCPHandle;
    destination->m_kRotCPHandle = m_kRotCPHandle;
    destination->m_kScaleCPHandle = m_kScaleCPHandle;
}

// @fnv 0x00a50f60
// pdb: NiBSplineCompTransformInterpolator::Update | NiBSplineCompTransformInterpolator.obj | retail, upstream name already matches, high
// pdb params: fTime, pkInterpTarget, kValue
// pdb locals: fNormTime, afValues
bool NiBSplineCompTransformInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    if (m_fLastTime == fTime)
    {
        NiQuatTransform* transformValue = &m_kTransformValue;
        kValue = *transformValue;
        if (transformValue->m_fScale == _DAT_010241b0 && transformValue->qy == _DAT_010241b0 &&
            transformValue->m_kTranslate == _DAT_010241b0)
            return false;
        return true;
    }

    float normalizedTime = (fTime - m_fStartTime) / (m_fEndTime - m_fStartTime);
    float decodedValue[4];
    NiPoint3 translation;
    if (m_kTransCPHandle != 0xffff)
    {
        m_spData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue, 3,
                                                          m_spBasisData.m_pObject, m_kTransCPHandle,
                                                          m_afCompScalars[0], m_afCompScalars[1]);
        translation.x = decodedValue[0];
        translation.y = decodedValue[1];
        translation.z = decodedValue[2];
        memcpy(&m_kTransformValue.m_kTranslate, &translation, sizeof(translation));
    }
    if (m_kRotCPHandle != 0xffff)
    {
        m_spData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue, 4,
                                                          m_spBasisData.m_pObject, m_kRotCPHandle,
                                                          m_afCompScalars[2], m_afCompScalars[3]);
        NiQuaternion& rotation = *reinterpret_cast<NiQuaternion*>(&m_kTransformValue.m_kRotate);
        rotation = *reinterpret_cast<NiQuaternion*>(decodedValue);
        rotation.FastNormalize();
    }
    if (m_kScaleCPHandle != 0xffff)
    {
        m_spData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue, 1,
                                                          m_spBasisData.m_pObject, m_kScaleCPHandle,
                                                          m_afCompScalars[4], m_afCompScalars[5]);
        m_kTransformValue.m_fScale = decodedValue[0];
    }

    NiQuatTransform* transformValue = &m_kTransformValue;
    kValue = *transformValue;
    if (transformValue->m_fScale == _DAT_010241b0 && transformValue->qy == _DAT_010241b0 &&
        transformValue->m_kTranslate == _DAT_010241b0)
        return false;
    m_fLastTime = fTime;
    return true;
}

void __fastcall FUN_00a57f80(void* pThis);

// Calls the spline base destructor, then frees pThis when flags has bit 0 set.
// @fnv 0x00a50e50
void* __fastcall FUN_00a50e50(void* pThis, int, unsigned int flags)
{
    FUN_00a57f80(pThis);
    if (flags & 1)
    {
        NiMemObject::operator delete(pThis, 0x60);
    }
    return pThis;
}

extern int NiBSplineCompTransformInterpolator_ms_RTTI; // src: XBOX_RETAIL_PDB 0x011f4004 (old: g_011f4004)

// @fnv 0x00a50e40
// src: COMMUNITY 0x00a50e40
int* __cdecl NiBSplineCompTransformInterpolator_GetRTTI()
{
    return &NiBSplineCompTransformInterpolator_ms_RTTI;
}

struct SplineTransformOperations
{
    bool IsEqual(NiObject*);
    void SaveBinary(NiStream&);
    NiBSplineTransformInterpolator* NiBSplineTransformInterpolator_ctor(int, int, int, int, int);
};
// @fnv 0x00a50e00
// pdb: NiBSplineFloatInterpolator::`scalar deleting destructor' | NiBSplineFloatInterpolator.obj | debug, object-file run extension, low
bool __fastcall IsEqualCompTransform(NiBSplineCompTransformInterpolator* self, int, NiObject* pkObject)
{
    NiBSplineCompTransformInterpolator* pkDest;
    unsigned int ui;
    if (!reinterpret_cast<SplineTransformOperations*>(self)->IsEqual(pkObject))
        return false;
    pkDest = (NiBSplineCompTransformInterpolator*)pkObject;
    for (ui = 0; ui < 6; ui++)
    {
        if (self->m_afCompScalars[ui] != pkDest->m_afCompScalars[ui])
            return false;
    }
    return true;
}

extern int NiBSplineCompTransformInterpolator_ms_RTTI; // src: XBOX_RETAIL_PDB 0x011f4004 (old: g_011f4004)
char* _FUN_00a7d330(const char*);
struct Holder
{
    void LoadBSplineTransform(StrArr*);
    void AppendString(StrArr*);
};
// @fnv 0x00a511c0
// pdb: NiBSplineCompTransformInterpolator::GetViewerStrings | NiBSplineCompTransformInterpolator.obj | retail, object-file run extension, low
// pdb params: pkStrings
void Holder::AppendString(StrArr* pkStrings)
{
    LoadBSplineTransform(pkStrings);
    char* s = _FUN_00a7d330((const char*)NiBSplineCompTransformInterpolator_ms_RTTI);
    unsigned int uiSize = pkStrings->m_usSize;
    unsigned int uiCapacity = pkStrings->m_usMaxSize;
    if (uiSize >= uiCapacity)
    {
        unsigned int grow = pkStrings->m_usGrowBy;
        pkStrings->SetSize(uiSize + grow);
    }
    pkStrings->SetAt(uiSize, s);
}

// @fnv 0x00a51180
// pdb: NiBSplineCompTransformInterpolator::SaveBinary | NiBSplineCompTransformInterpolator.obj | retail, object-file run extension, low
// pdb params: kStream
void __fastcall SaveCompTransform(NiBSplineCompTransformInterpolator* self, int, NiStream& stream)
{
    reinterpret_cast<SplineTransformOperations*>(self)->SaveBinary(stream);
    NiBinaryStream* __restrict output = stream.m_pkOstr;
    unsigned int size = 4;
    output->m_uiAbsoluteCurrentPos += output->m_pfnWrite(output, self->m_afCompScalars, 0x18, &size, 1);
}

extern int DAT_011a8400;
extern int DAT_011a8404;
extern int DAT_011a8408;
extern int DAT_011f3704;
extern int DAT_011f3708;
extern int DAT_011f370c;
extern int DAT_011f3710;
extern float DAT_01096b8c;
extern int DAT_0109957c;

// The shared classes do not declare the parameterized constructors. Keep the
// original thiscall entry point here, operating on their checked layouts.
// @fnv 0x00a4fff0
// src: XBOX_RETAIL_PDB 0x00a4fff0
// pdb: NiBSplineTransformInterpolator::NiBSplineTransformInterpolator | NiBSplineTransformInterpolator.obj | retail, call graph, high
// pdb params: pkData, kTransCPHandle, kRotCPHandle, kScaleCPHandle, pkBasisData
NiBSplineTransformInterpolator* SplineTransformOperations::NiBSplineTransformInterpolator_ctor(int pkData, int kTransCPHandle, int kRotCPHandle,
                                                                    int kScaleCPHandle, int pkBasisData)
{
    NiBSplineTransformInterpolator* self = reinterpret_cast<NiBSplineTransformInterpolator*>(this);
    reinterpret_cast<SplineBaseOperations*>(self)->NiBSplineInterpolator_ctor(pkData, pkBasisData);
    *reinterpret_cast<int*>(self) = (int)&DAT_0109957c;
    reinterpret_cast<int&>(self->m_kTransformValue.m_kTranslate) = DAT_011a8400;
    reinterpret_cast<int&>(self->m_kTransformValue.y) = DAT_011a8404;
    reinterpret_cast<int&>(self->m_kTransformValue.z) = DAT_011a8408;
    reinterpret_cast<int&>(self->m_kTransformValue.m_kRotate) = DAT_011f3704;
    reinterpret_cast<int&>(self->m_kTransformValue.qy) = DAT_011f3708;
    reinterpret_cast<int&>(self->m_kTransformValue.qz) = DAT_011f370c;
    reinterpret_cast<int&>(self->m_kTransformValue.qw) = DAT_011f3710;
    self->m_kTransformValue.m_fScale = DAT_01096b8c;
    self->m_kTransCPHandle = kTransCPHandle;
    self->m_kRotCPHandle = kRotCPHandle;
    self->m_kScaleCPHandle = kScaleCPHandle;
    return self;
}

static const float NI_INFINITY = 3.402823466e+38f;
extern int DAT_0109991c;

__forceinline NiBSplineCompTransformInterpolator* NewCompTransform()
{
    NiBSplineCompTransformInterpolator* result =
        static_cast<NiBSplineCompTransformInterpolator*>(NiObject::operator new(sizeof(NiBSplineCompTransformInterpolator)));
    if (result)
    {
        reinterpret_cast<SplineTransformOperations*>(result)->NiBSplineTransformInterpolator_ctor(0, 0xffff, 0xffff, 0xffff, 0);
        // Keep vtable installation before the range stores, as in the original constructor.
        *reinterpret_cast<volatile int*>(result) = (int)&DAT_0109991c;
        volatile float* ranges = result->m_afCompScalars;
        ranges[0] = NI_INFINITY;
        ranges[1] = NI_INFINITY;
        ranges[2] = NI_INFINITY;
        ranges[3] = NI_INFINITY;
        ranges[4] = NI_INFINITY;
        ranges[5] = NI_INFINITY;
        return result;
    }
    return 0;
}

// @fnv 0x00a50f00
// pdb: NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator | NiBSplineCompTransformInterpolator.obj | debug, object-file run extension, low
// pdb params: kPoseValue
// pdb locals: ui
NiBSplineTransformInterpolator* __cdecl CreateEvaluator()
{
    return NewCompTransform();
}

// @fnv 0x00a50e70
// pdb: NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator | NiBSplineCompTransformInterpolator.obj | debug, object-file run extension, low
// pdb params: pkData, kTransCPHandle, kRotCPHandle, kScaleCPHandle, pkBasisData
// pdb locals: ui
NiBSplineCompTransformInterpolator* __fastcall CloneCompTransform(NiBSplineCompTransformInterpolator* self, int,
                                                                CloningProcess& cloning)
{
    NiBSplineCompTransformInterpolator* destination = NewCompTransform();
    self->CopyMemberData(destination, cloning);
    destination->m_afCompScalars[0] = self->m_afCompScalars[0];
    destination->m_afCompScalars[1] = self->m_afCompScalars[1];
    destination->m_afCompScalars[2] = self->m_afCompScalars[2];
    destination->m_afCompScalars[3] = self->m_afCompScalars[3];
    destination->m_afCompScalars[4] = self->m_afCompScalars[4];
    destination->m_afCompScalars[5] = self->m_afCompScalars[5];
    return destination;
}
