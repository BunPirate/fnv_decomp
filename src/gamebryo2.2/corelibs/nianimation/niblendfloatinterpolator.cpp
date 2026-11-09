// gamebryo2.2/corelibs/nianimation/niblendfloatinterpolator.cpp: float blending (12 functions)

#include "NiRefObject_inline.h"

#include "../../../../include/BSStreamHeader.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiBlendFloatInterpolator.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiStream.h"
#include "niblendfloatinterpolator_types_NiBlendFloatInterpolator.h"

extern float DAT_0109696c;
extern float DAT_0109a918;

// Updates the blend interpolator for the given time and target, delegating to single or multi-interpolator update paths and storing the last time.
// @fnv 0x00a40810
// pdb: NiBlendFloatInterpolator::Update | NiBlendFloatInterpolator.obj | retail, upstream name already matches, high
// pdb params: fTime, pkInterpTarget, fValue
// pdb locals: bReturnValue
bool NiBlendFloatInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, float& fValue)
{
    bool result = false;
    if (m_ucInterpCount == 1)
        result = NiBlendFloatInterpolator::StoreSingleValue(fTime, pkInterpTarget, fValue);
    else if (m_ucInterpCount > 0)
    {
        NiBlendInterpolator::NormalizeWeights();
        result = NiBlendFloatInterpolator::BlendValues(fTime, pkInterpTarget, fValue);
    }
    m_fLastTime = fTime;
    return result;
}

__forceinline void ReadFloat(NiBinaryStream* input, float* value)
{
    unsigned int size = 4;
    input->m_uiAbsoluteCurrentPos += input->m_pfnRead(input, value, 4, &size, 1);
}
// Calls the base NiBlendInterpolator::LoadBinary, then reads a float from the stream into m_fFloatValue.
// @fnv 0x00a40870
// pdb: NiBlendFloatInterpolator::LoadBinary | NiBlendFloatInterpolator.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiBlendFloatInterpolator::LoadBinary(NiStream& kStream)
{
    NiBlendInterpolator::LoadBinary(kStream);
    ReadFloat(kStream.m_pkIstr, &m_fFloatValue);
}

// @fnv 0x00a40640
// src: XBOX_RETAIL_PDB 0x00a40640
// pdb: NiBlendFloatInterpolator::StoreSingleValue | NiBlendFloatInterpolator.obj | retail, object-file run extension, high
// pdb params: fTime, pkInterpTarget, fValue
bool NiBlendFloatInterpolator::StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, float& fValue)
{
    if (m_uFlags & 1)
        fTime = m_fSingleTime;
    if (fTime == DAT_0109696c)
        return false;
    if (m_pkSingleInterpolator->UpdateFloat(fTime, pkInterpTarget, m_fFloatValue))
    {
        fValue = m_fFloatValue;
        return true;
    }
    m_fFloatValue = DAT_0109a918;
    fValue = DAT_0109a918;
    return false;
}

__forceinline bool NiBlendInterpolator::GetBlendUpdateTime(float& time, NiBlendInterpolator__InterpArrayItem& item)
{
    if (!item.m_spControllerInterpolator || item.m_fNormalizedWeight == 0.0f)
        return false;
    if (m_uFlags & 1)
        time = item.m_fLastEvaluationTime;
    return time != DAT_0109696c;
}

// Blends weighted float values from the interpolator array into m_fFloatValue, normalizing by total weight, and writes the result to value.
// @fnv 0x00a406c0
// src: XBOX_RETAIL_PDB 0x00a406c0
// pdb: NiBlendFloatInterpolator::BlendValues | NiBlendFloatInterpolator.obj | retail, object-file run extension, high
// pdb params: fTime, pkInterpTarget, fValue
// pdb locals: bModifiedValue, fTotalNormalizedWeight, uc, pkInterpolator, fUpdateTime, bSuccess
bool NiBlendFloatInterpolator::BlendValues(float fTime, NiObjectNET* pkInterpTarget, float& fValue)
{
    m_fFloatValue = 0.0f;
    bool valid = false;
    float totalWeight = 1.0f;
    float currentValue;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiInterpolator* interpolator = m_pkInterpArray[i].m_spControllerInterpolator;
        if (interpolator && m_pkInterpArray[i].m_fNormalizedWeight > 0.0f)
        {
            NiBlendInterpolator__InterpArrayItem& item = m_pkInterpArray[i];
            float updateTime = fTime;
            if (!GetBlendUpdateTime(updateTime, item))
                totalWeight -= item.m_fNormalizedWeight;
            else if (interpolator->UpdateFloat(updateTime, pkInterpTarget, currentValue))
            {
                valid = true;
                m_fFloatValue += m_pkInterpArray[i].m_fNormalizedWeight * currentValue;
            }
            else
                totalWeight -= m_pkInterpArray[i].m_fNormalizedWeight;
        }
    }
    m_fFloatValue /= totalWeight;
    if (!valid)
    {
        fValue = DAT_0109a918;
        m_fFloatValue = DAT_0109a918;
        return false;
    }
    fValue = m_fFloatValue;
    return true;
}

// Returns whether the source interpolator supports float values.
// @fnv 0x00a40560
bool __fastcall ControlsFloatInterpolator(NiBlendFloatInterpolator*, int, NiInterpolator* interpolator)
{
    return interpolator->IsFloatValueSupported();
}

// Constructs the blend interpolator and initializes its float value.
// @fnv 0x00a40520
// pdb: NiBlendFloatInterpolator::NiBlendFloatInterpolator | NiBlendFloatInterpolator.obj | retail, upstream name already matches, high
// pdb params: bManagerControlled, fWeightThreshold, ucArraySize
NiBlendFloatInterpolator::NiBlendFloatInterpolator(bool bManagerControlled, float fWeightThreshold, unsigned char ucArraySize)
    : NiBlendInterpolator(bManagerControlled, fWeightThreshold, ucArraySize)
{
    m_fFloatValue = DAT_0109a918;
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern const void* vftable_NiBlendFloatInterpolator[];

// @fnv 0x00a40580
void* __cdecl CreateNiBlendFloatInterpolator()
{
    void* pInterpolator = NiObject::operator new(0x34);
    if (pInterpolator)
    {
        NiBlendInterpolator_NiBlendInterpolator(pInterpolator);
        *(void**)pInterpolator = (void*)vftable_NiBlendFloatInterpolator;
        *(float*)((char*)pInterpolator + 0x30) = DAT_0109a918;
        return pInterpolator;
    }
    return 0;
}

// Compares the base interpolator and the float value.
// @fnv 0x00a405b0
bool __fastcall IsFloatValueEqual(NiBlendFloatInterpolator* self, int, NiObject* object)
{
    if (!self->NiBlendInterpolator::IsEqual(object))
        return false;
    NiBlendFloatInterpolator* destination = static_cast<NiBlendFloatInterpolator*>(object);
    if (self->m_fFloatValue != destination->m_fFloatValue)
        return false;
    return true;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3e58;
// @fnv 0x00a405e0
// src: COMMUNITY 0x00a405e0
void* __cdecl NiBlendFloatInterpolator_GetRTTI()
{
    return &g_011f3e58;
}

// @fnv 0x00a408b0
// pdb: NiBlendFloatInterpolator::SaveBinary | NiBlendFloatInterpolator.obj | retail, object-file gap fill, high
// pdb params: kStream
void __fastcall SaveFloatBinary(NiBlendFloatInterpolator* self, int, NiStream* stream)
{
    self->NiBlendInterpolator::SaveBinary(*stream);
    NiBinaryStream* __restrict out = stream->m_pkOstr;
    unsigned int size = 4;
    out->m_uiAbsoluteCurrentPos += out->m_pfnWrite(out, &self->m_fFloatValue, 4, &size, 1);
}

namespace fnv_00a408f0 {
struct M76Arr
{
    void* vtbl;
    void* data;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short pad0c;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* item)
    {
        unsigned int index = m_usESize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, item);
    }
};
struct M76Glob
{
    int pad;
};
extern M76Glob* g_011f3e58;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(M76Glob*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
// Appends the base interpolator strings, type name, and formatted float value.
// @fnv 0x00a408f0
// pdb: NiBlendFloatInterpolator::GetViewerStrings | NiBlendFloatInterpolator.obj | retail, string-set bridge, high
// pdb params: pkStrings
void __fastcall AppendFloatValueStrings(NiBlendFloatInterpolator* self, int, M76Arr* pkStrings)
{
    self->NiBlendInterpolator::AppendInterpolatorStrings(reinterpret_cast<StrArr*>(pkStrings));
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_011f3e58));
    pkStrings->Add(NiGetViewerString_00a7d550("m_fFloatValue", self->m_fFloatValue));
}
}  // namespace fnv_00a408f0

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct CopyMembersArguments
{
    NiBlendFloatInterpolator* destination;
    void* cloningProcess;
};
extern "C" void __fastcall NiBlendInterpolator_CopyMembers(void* pkDest, CopyMembersArguments kCloning);

// Allocates and initializes a clone, then copies the base and float members.
// @fnv 0x00a405f0
// pdb: NiBlendFloatInterpolator::CreateClone | NiBlendFloatInterpolator.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiBlendFloatInterpolator::InterpolatorIsCorrectType
// pdb params: kCloning
// pdb locals: pkObject
NiBlendFloatInterpolator* __fastcall CloneFloatInterpolator(NiBlendFloatInterpolator* self, int, void* pCloningProcess)
{
    NiBlendFloatInterpolator* copy =
        static_cast<NiBlendFloatInterpolator*>(Object_DispatchCommandFour(sizeof(NiBlendFloatInterpolator)));
    if (copy)
    {
        NiBlendInterpolator_NiBlendInterpolator(copy);
        *reinterpret_cast<const void***>(copy) = vftable_NiBlendFloatInterpolator;
        copy->m_fFloatValue = DAT_0109a918;
    }
    else
    {
        copy = 0;
    }
    CopyMembersArguments args = {copy, pCloningProcess};
    NiBlendInterpolator_CopyMembers(self, args);
    copy->m_fFloatValue = self->m_fFloatValue;
    return copy;
}
