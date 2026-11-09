
#include "../../../../include/BSBlendTreadTransfInterpolator.h"
#include "../../../../include/NiBlendInterpolator.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/BSTreadTransfInterpolator.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuaternion.h"
// @fnv 0x00a432d0
bool BSBlendTreadTransfInterpolator::UpdateTransform(float time, NiObjectNET* target, NiQuatTransform& arValue)
{
    bool result = false;
    if (m_ucInterpCount == 1)
        result = UpdateSingleInterpolator(time, target, arValue);
    else if (m_ucInterpCount > 0)
    {
        NormalizeWeights();
        result = UpdateAccumulatedTransform(time, target, arValue);
    }
    m_fLastTime = time;
    return result;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 BSBlendTreadTransfInterpolator_ms_RTTI;

// @fnv 0x00a42fe0
// src: COMMUNITY 0x00a42fe0
GlobalObjectO2_00a7b610* __cdecl BSBlendTreadTransfInterpolator_GetRTTI()
{
    return &BSBlendTreadTransfInterpolator_ms_RTTI;
}

extern int DAT_01097904;
NiBlendInterpolator* __fastcall NiBlendInterpolator_NiBlendInterpolator(NiBlendInterpolator*);
// @fnv 0x00a42ff0
NiObject* BSBlendTreadTransfInterpolator::MakeClone(CloningProcess& kCloning)
{
    BSBlendTreadTransfInterpolator* pkObject;
    pkObject = (BSBlendTreadTransfInterpolator*)BSFadeNode::operator new(0x34);
    if (pkObject)
    {
        NiBlendInterpolator_NiBlendInterpolator(pkObject);
        pkObject->fCurrLerp = 0.0f;
        *(void**)pkObject = (void*)&DAT_01097904;
    }
    else
    {
        pkObject = 0;
    }
    CopyMembers(pkObject, &kCloning);
    pkObject->fCurrLerp = fCurrLerp;
    return pkObject;
}

// @fnv 0x00a39100
// src: COMMUNITY 0x00a39100
// pdb: NiBlendAccumTransformInterpolator::InterpolatorIsCorrectType | NiBlendAccumTransformInterpolator.obj | debug, upstream name already matches, high
// pdb params: pkInterpolator
bool __stdcall NiBlendAccumTransformInterpolator_InterpolatorIsCorrectType(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->IsTransformValueSupported();
}

namespace fnv_00a43160 {
extern const NiPoint3 DAT_011a8400;
extern const NiQuaternion DAT_011f3704;
extern const float DAT_01096b8c;
extern const float DAT_0109696c;
extern const double DAT_01012070;
extern const float DAT_01015f5c;

} // namespace fnv_00a43160

// Keep the original bitwise quaternion copies independent of operator= in the headers.
static __forceinline void CopyTreadQuaternion(NiQuaternion& destination, const NiQuaternion& source)
{
    unsigned int* out = reinterpret_cast<unsigned int*>(&destination);
    const unsigned int* in = reinterpret_cast<const unsigned int*>(&source);
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
    out[3] = in[3];
}

__forceinline NiQuatTransform::NiQuatTransform()
{
    reinterpret_cast<NiPoint3&>(m_kTranslate) = fnv_00a43160::DAT_011a8400;
    CopyTreadQuaternion(reinterpret_cast<NiQuaternion&>(m_kRotate), fnv_00a43160::DAT_011f3704);
    m_fScale = fnv_00a43160::DAT_01096b8c;
}

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* interpolator;
    float weight;
    float normalizedWeight;
    int priority;
    float easeSpinner;
    float time;
};
// @fnv 0x00a43160
bool BSBlendTreadTransfInterpolator::UpdateAccumulatedTransform(float time, NiObjectNET* object, NiQuatTransform& arResult)
{
    using namespace fnv_00a43160;
    float total = 0.0f;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pkInterpArray[i];
        if (item.interpolator && item.normalizedWeight > 0.0f)
        {
            float sampleTime = time;
            if (item.normalizedWeight != 0.0f)
            {
                if (m_uFlags & 1)
                    sampleTime = item.time;
                if (sampleTime != DAT_0109696c)
                {
                    NiQuatTransform transform;
                    if (item.interpolator->UpdateTransform(sampleTime, object, transform))
                    {
                        total += static_cast<BSTreadTransfInterpolator*>(item.interpolator)->fDiffLerp * item.normalizedWeight;
                    }
                }
            }
        }
    }
    float& combined = fCurrLerp;
    combined += total;
    if (combined > 1.0f)
        fCurrLerp = combined - DAT_01012070;
    else if (combined < 0.0f)
        fCurrLerp = combined + DAT_01012070;
    float* __restrict pfOut = (float*)&arResult;
    pfOut[7] = pfOut[4] = pfOut[0] = DAT_01015f5c;
    return true;
}

void __cdecl NiBlendInterpolator_RegisterStreamables();
// @fnv 0x00a40a00
// src: XBOX_PDB 0x00a40a00
// pdb: BSBlendTreadTransfInterpolator::RegisterStreamables | BSBlendTreadTransfInterpolator.obj | debug, upstream name already matches, high
// pdb params: arStream
// pdb locals: bret
void __cdecl BSBlendTreadTransfInterpolator_RegisterStreamables()
{
    NiBlendInterpolator_RegisterStreamables();
}

void __cdecl NiBlendInterpolator_SaveBinary();
// @fnv 0x00a40a10
// src: XBOX_PDB 0x00a40a10
// pdb: BSBlendTreadTransfInterpolator::SaveBinary | BSBlendTreadTransfInterpolator.obj | debug, upstream name already matches, high
// pdb params: arStream
void __cdecl BSBlendTreadTransfInterpolator_SaveBinary()
{
    NiBlendInterpolator_SaveBinary();
}

void __cdecl NiBlendInterpolator_LoadBinary();

// @fnv 0x00a42fc0
// src: XBOX_PDB 0x00a42fc0
// pdb: BSBlendTreadTransfInterpolator::LoadBinary | BSBlendTreadTransfInterpolator.obj | debug, upstream name already matches, high
// pdb params: arStream
void __cdecl BSBlendTreadTransfInterpolator_LoadBinary()
{
    NiBlendInterpolator_LoadBinary();
}

void __cdecl NiBlendInterpolator_IsEqual();

// @fnv 0x00a42fd0
// src: XBOX_PDB 0x00a42fd0
// pdb: BSBlendTreadTransfInterpolator::IsEqual | BSBlendTreadTransfInterpolator.obj | debug, upstream name already matches, high
// pdb params: apObject
// pdb locals: bret
void __cdecl BSBlendTreadTransfInterpolator_IsEqual()
{
    NiBlendInterpolator_IsEqual();
}

extern float DAT_0109696c;
// Parameterless quaternion member call: the quaternion address is passed in ECX.
void __fastcall FUN_00a38560(NiQuaternion* quaternion);
// @fnv 0x00a43040
bool BSBlendTreadTransfInterpolator::UpdateSingleInterpolator(float afTime, NiObjectNET* target, NiQuatTransform& arTransform)
{
    if (m_uFlags & 1)
        afTime = m_fSingleTime;
    if (afTime == DAT_0109696c)
    {
        arTransform.m_kTranslate = -3.4028234663852886e38f;
        arTransform.qy = -3.4028234663852886e38f;
        arTransform.m_fScale = -3.4028234663852886e38f;
        return false;
    }
    if (m_pkSingleInterpolator->UpdateTransform(afTime, target, arTransform))
    {
        fCurrLerp += static_cast<BSTreadTransfInterpolator*>(m_pkSingleInterpolator)->fDiffLerp;
        if (fCurrLerp > 1.0f)
            fCurrLerp = fCurrLerp - 1.0;
        else if (fCurrLerp < 0.0f)
            fCurrLerp = fCurrLerp + 1.0;
        if (arTransform.qy != -3.4028234663852886e38)
        {
            NiQuaternion qRotation = reinterpret_cast<NiQuaternion&>(arTransform.m_kRotate);
            FUN_00a38560(&qRotation);
            CopyTreadQuaternion(reinterpret_cast<NiQuaternion&>(arTransform.m_kRotate), qRotation);
        }
        return true;
    }
    arTransform.m_kTranslate = -3.4028234663852886e38f;
    arTransform.qy = -3.4028234663852886e38f;
    arTransform.m_fScale = -3.4028234663852886e38f;
    return false;
}

static volatile float BlendTimeValue = -3.402823466e+38f;
extern int DAT_0109697c;

// The shared class has no default constructor; initialize its declared fields here.
void __fastcall InitializeInterpolator(NiInterpolator* interpolator);

// @fnv 0x00a36890
// src: GAMEBRYO_LIB 0x00a36890
// pdb: NiBlendPoint3Interpolator::NiBlendPoint3Interpolator | NiBlendPoint3Interpolator.obj | retail, call graph, low
// pdb note: debug build links it to NiTransformController::`scalar deleting destructor'
// pdb params: bManagerControlled, fWeightThreshold, ucArraySize
NiBlendInterpolator* __fastcall NiBlendInterpolator_NiBlendInterpolator(NiBlendInterpolator* interpolator)
{
    InitializeInterpolator(interpolator);
    *reinterpret_cast<void**>(interpolator) = &DAT_0109697c;
    interpolator->m_uFlags = 0;
    interpolator->m_ucArraySize = 0;
    interpolator->m_ucInterpCount = 0;
    interpolator->m_ucSingleIdx = 0xff;
    interpolator->m_cHighPriority = -128;
    interpolator->m_cNextHighPriority = -128;
    interpolator->m_pkInterpArray = 0;
    interpolator->m_pkSingleInterpolator = 0;
    interpolator->m_fWeightThreshold = 0.0f;
    interpolator->m_fSingleTime = BlendTimeValue;
    interpolator->m_fHighSumOfWeights = BlendTimeValue;
    interpolator->m_fNextHighSumOfWeights = BlendTimeValue;
    interpolator->m_fHighEaseSpinner = BlendTimeValue;
    return interpolator;
}
