// gamebryo2.2/corelibs/nianimation/niblendpoint3interpolator.cpp: NiBlendPoint3Interpolator, BlendPointShell (13 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBlendPoint3Interpolator.h"
#include "../../../../include/StrArr.h"

extern const float DAT_0109696c;
extern const NiPoint3 DAT_011a9424;

// @fnv 0x00a55b90
// src: XBOX_RETAIL_PDB 0x00a55b90
// pdb: NiBlendPoint3Interpolator::StoreSingleValue | NiBlendPoint3Interpolator.obj | retail, object-file gap fill, high
// pdb params: fTime, pkInterpTarget, kValue
bool NiBlendPoint3Interpolator::StoreSingleValue(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue)
{
    if (m_uFlags & 1)
        fTime = m_fSingleTime;

    if (fTime == DAT_0109696c)
        return false;

    if (m_pkSingleInterpolator->UpdatePoint3(fTime, pkInterpTarget, m_kPoint3Value))
    {
        kValue = m_kPoint3Value;
        return true;
    }

    m_kPoint3Value = DAT_011a9424;
    kValue = m_kPoint3Value;
    return false;
}

// Updates the interpolator: delegates to single or multi-interpolation update based on m_ucInterpCount, stores fTime in m_fLastTime, and returns success.
// @fnv 0x00a55e00
// pdb: NiBlendPoint3Interpolator::Update | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb params: fTime, pkInterpTarget, kValue
// pdb locals: bReturnValue
bool NiBlendPoint3Interpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue)
{
    bool bSuccess = false;
    if (m_ucInterpCount == 1)
        bSuccess = StoreSingleValue(fTime, pkInterpTarget, kValue);
    else if (m_ucInterpCount > 0)
    {
        NormalizeWeights();
        bSuccess = UpdateSingleInterpolator(fTime, pkInterpTarget, kValue);
    }
    m_fLastTime = fTime;
    return bSuccess;
}

struct GlobalObjectO2_00a7b610
{
    int x;
};
extern GlobalObjectO2_00a7b610 g_011f406c;
// @fnv 0x00a55af0
// src: COMMUNITY 0x00a55af0
GlobalObjectO2_00a7b610* __cdecl NiBlendPoint3Interpolator_GetRTTI()
{
    return &g_011f406c;
}

struct FUN_00a55ec0_shell : public NiBlendPoint3Interpolator
{
    bool NiBlendPoint3Interpolator_IsEqual(NiObject*);
};

struct FUN_00a36fd0_tgt
{
    bool NiBlendInterpolator_IsEqual(NiObject*);
};
struct Call_439090_tgt
{
    bool _Call_439090(const void*);
};

// Calls FUN_00a36fd0 on pkObject; if that succeeds, calls _Call_439090 on pkObject+0x30 and returns its negation.
// @fnv 0x00a55ec0
// src: XBOX_PDB 0x00a55ec0
// pdb: NiBlendPoint3Interpolator::IsEqual | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb params: pkObject
// pdb locals: pkDest
bool FUN_00a55ec0_shell::NiBlendPoint3Interpolator_IsEqual(NiObject* pkObject)
{
    bool r = ((FUN_00a36fd0_tgt*)this)->NiBlendInterpolator_IsEqual(pkObject);
    if (!r)
        return r;
    r = ((Call_439090_tgt*)((char*)this + 0x30))->_Call_439090((char*)pkObject + 0x30);
    r = !r;
    return r;
}

namespace fnv_00a55ef0 {
struct FUN_00a55ef0_shell : public NiBlendPoint3Interpolator
{
    void AppendPoint3Value(void*);
};

struct GlobalObjectO2_00a7b610
{
    void* p;
};
extern GlobalObjectO2_00a7b610 g_011f406c;
char* NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610);
struct ViewerBase
{
    void NiBlendInterpolator_GetViewerStrings(void*);
};
struct ViewerPoint3
{
    char* GetViewerString_00a59af0(const char*);
};
// @fnv 0x00a55ef0
// pdb: NiBlendPoint3Interpolator::GetViewerStrings | NiBlendPoint3Interpolator.obj | retail, string-set bridge, high
// pdb params: pkStrings
void FUN_00a55ef0_shell::AppendPoint3Value(void* pkStrings)
{
    ((ViewerBase*)this)->NiBlendInterpolator_GetViewerStrings(pkStrings);
    StrArr* arr = (StrArr*)pkStrings;
    char* pElement = NiViewerStrings_NiGetViewerString_Title(g_011f406c);
    unsigned int i = arr->m_usSize;
    if (i >= arr->m_usMaxSize)
        arr->SetSize(arr->m_usGrowBy + i);
    arr->SetAt(i, pElement);
    pElement = ((ViewerPoint3*)((char*)this + 0x30))->GetViewerString_00a59af0("m_kPoint3Value");
    i = arr->m_usSize;
    if (i >= arr->m_usMaxSize)
        arr->SetSize(arr->m_usGrowBy + i);
    arr->SetAt(i, pElement);
}
}  // namespace fnv_00a55ef0

// Calls the virtual function at vtable offset 0xb0 on p and returns its bool result.
// @fnv 0x00a55a60
// src: XBOX_PDB 0x00a55a60
// pdb: NiBlendPoint3Interpolator::InterpolatorIsCorrectType | NiBlendPoint3Interpolator.obj | debug, upstream name already matches, high
// pdb params: pkInterpolator
bool __stdcall NiBlendPoint3Interpolator_InterpolatorIsCorrectType(NiBlendPoint3Interpolator* p)
{
    return reinterpret_cast<bool(__thiscall*)(NiObject*)>(*reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const unsigned char*>(*reinterpret_cast<const unsigned int*>(p)) + 0xb0))(p);
}

void __fastcall NiBlendInterpolator_NiBlendInterpolator(void*);
extern int DAT_0109a49c;
extern int _DAT_011a9424;
extern int _DAT_011a9428;
extern int _DAT_011a942c;
// @fnv 0x00a55a80
// src: EXE 0x00a55a80
// pdb: NiBlendPoint3Interpolator::CreateObject | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb locals: pkObject
void* NiBlendPoint3Interpolator_CreateObject()
{
    void* p = BSFadeNode::operator new(64);
    if (p)
    {
        NiBlendInterpolator_NiBlendInterpolator(p);
        *(void**)p = (void*)&DAT_0109a49c;
        *(int*)((char*)p + 0x30) = _DAT_011a9424;
        *(int*)((char*)p + 0x34) = _DAT_011a9428;
        *(int*)((char*)p + 0x38) = _DAT_011a942c;
        *(unsigned char*)((char*)p + 0x3c) = 0;
        return p;
    }
    return 0;
}

struct FUN_00a37ec0_tgt
{
    void NiBlendInterpolator_SaveBinary(NiStream&);
};
struct NiColorSaveHelper
{
    void SaveBinary(NiStream&);
};
struct FUN_00a37ec0_shell : public NiBlendPoint3Interpolator
{
    void NiBlendPoint3Interpolator_SaveBinary(NiStream& kStream);
};
// @fnv 0x00a55ad0
// src: XBOX_PDB 0x00a55ad0
// pdb: NiBlendPoint3Interpolator::SaveBinary | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb params: kStream
void FUN_00a37ec0_shell::NiBlendPoint3Interpolator_SaveBinary(NiStream& kStream)
{
    ((FUN_00a37ec0_tgt*)this)->NiBlendInterpolator_SaveBinary(kStream);
    ((NiColorSaveHelper*)((char*)this + 0x30))->SaveBinary(kStream);
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl _delete(void*, unsigned int);
struct Cls_00a55b00
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls DestroyInterpolatorArray on this, frees this with _delete when bit 0 of f is set, and returns this.
// @fnv 0x00a55b00
void* Cls_00a55b00::DestroyIfFlagged(unsigned int auiFlags)
{
    DestroyInterpolatorArray(this);
    if (auiFlags & 1)
        _delete(this, 0x40);
    return this;
}

struct CloningProcess;
struct CloneOwner
{
    void NiBlendInterpolator_CopyMembers(void*, void*);
};
struct FUN_00a55b20_shell : public NiBlendPoint3Interpolator
{
    void* NiBlendPoint3Interpolator_CreateClone(CloningProcess*);
};
// Allocates a NiBlendPoint3Interpolator, initialises it, copies the point3 fields and flag from this, and returns the clone.
// @fnv 0x00a55b20
// src: XBOX_PDB 0x00a55b20
// pdb: NiBlendPoint3Interpolator::CreateClone | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb params: kCloning
// pdb locals: pkObject
void* FUN_00a55b20_shell::NiBlendPoint3Interpolator_CreateClone(CloningProcess* kCloning)
{
    NiBlendPoint3Interpolator* pkObject = static_cast<NiBlendPoint3Interpolator*>(BSFadeNode::operator new(0x40));
    if (pkObject)
    {
        NiBlendInterpolator_NiBlendInterpolator(pkObject);
        *reinterpret_cast<void**>(pkObject) = &DAT_0109a49c;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x30) = _DAT_011a9424;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x34) = _DAT_011a9428;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x38) = _DAT_011a942c;
        *reinterpret_cast<char*>(reinterpret_cast<char*>(pkObject) + 0x3c) = 0;
    }
    else
    {
        pkObject = 0;
    }
    reinterpret_cast<CloneOwner*>(this)->NiBlendInterpolator_CopyMembers(pkObject, kCloning);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x30) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x30);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x34) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x34);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(pkObject) + 0x38) =
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x38);
    *reinterpret_cast<char*>(reinterpret_cast<char*>(pkObject) + 0x3c) =
        *reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x3c);
    return pkObject;
}

extern int DAT_0109a49c;

struct FUN_00a370b0_tgt
{
    void Init(void* a, float f, void* c);
};

struct FUN_00a55a10
{
    int m_vptr;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    NiPoint3 m_kPoint3Value;
    bool m_bValueValid;

    FUN_00a55a10(void* a, float f, void* c);
};

// @fnv 0x00a55a10
FUN_00a55a10::FUN_00a55a10(void* apArg, float f, void* c)
{
    ((FUN_00a370b0_tgt*)this)->Init(apArg, f, c);
    m_vptr = reinterpret_cast<int>(&DAT_0109a49c);
    m_kPoint3Value = DAT_011a9424;
    m_bValueValid = false;
}

struct FUN_00a37980_tgt
{
    void NiBlendInterpolator_LoadBinary(NiObjectNET* kStream);
};
struct FUN_00a59be0_tgt
{
    void FUN_00a59be0(NiObjectNET* p);
};
struct FUN_00a55e60_cls : public NiBlendPoint3Interpolator
{
    void NiBlendPoint3Interpolator_LoadBinary(NiObjectNET* kStream);
};
// @fnv 0x00a55e60
// src: GAMEBRYO_LIB 0x00a55e60
// pdb: NiBlendPoint3Interpolator::LoadBinary | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb params: kStream
void FUN_00a55e60_cls::NiBlendPoint3Interpolator_LoadBinary(NiObjectNET* kStream)
{
    ((FUN_00a37980_tgt*)this)->NiBlendInterpolator_LoadBinary(kStream);
    NiPoint3* pt = &m_kPoint3Value;
    ((FUN_00a59be0_tgt*)pt)->FUN_00a59be0(kStream);
    if (pt->x != DAT_011a9424.x || pt->y != DAT_011a9424.y || pt->z != DAT_011a9424.z)
    {
        m_bValidValue = true;
    }
}

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_iValueAt14;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
extern const NiPoint3 DAT_011f426c;
struct BlendPointShell : NiBlendPoint3Interpolator
{
    static NiPoint3& Add(NiPoint3& a, const NiPoint3& b)
    {
        a.x = b.x + a.x;
        float* pa = &a.x;
        pa[1] += b.y;
        pa[2] += b.z;
        return a;
    }
    bool GetTime(unsigned char index, float& time)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pkInterpArray[index];
        if (!item.m_spControllerInterpolator || item.m_fNormalizedWeight == 0.0f)
            return false;
        if (m_uFlags & 1)
            time = item.m_fLastEvaluationTime;
        return time != DAT_0109696c;
    }
    bool NiBlendPoint3Interpolator_BlendValues(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue);
};
// Blends successful controller values using normalized weights, adjusts for skipped weights, and writes the result to value.
// @fnv 0x00a55c30
// src: XBOX_PDB 0x00a55c30
// pdb: NiBlendPoint3Interpolator::BlendValues | NiBlendPoint3Interpolator.obj | retail, upstream name already matches, high
// pdb params: fTime, pkInterpTarget, kValue
// pdb locals: fTotalNormalizedWeight, uc, pkInterpolator, fUpdateTime, bSuccess
bool BlendPointShell::NiBlendPoint3Interpolator_BlendValues(float fTime, NiObjectNET* pkInterpTarget, NiPoint3& kValue)
{
    float weight = 1.0f;
    m_bValidValue = false;
    m_kPoint3Value = DAT_011f426c;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiBlendInterpolator__InterpArrayItem& item = m_pkInterpArray[i];
        if (item.m_spControllerInterpolator && item.m_fNormalizedWeight > 0.0f)
        {
            float updateTime = fTime;
            if (!GetTime(i, updateTime))
            {
                weight -= item.m_fNormalizedWeight;
                continue;
            }
            NiPoint3 tempPoint;
            if (item.m_spControllerInterpolator->UpdatePoint3(updateTime, pkInterpTarget, tempPoint))
            {
                float w = m_pkInterpArray[i].m_fNormalizedWeight;
                NiPoint3 scaledPoint;
                scaledPoint.x = tempPoint.x * w;
                scaledPoint.y = tempPoint.y * w;
                scaledPoint.z = tempPoint.z * w;
                Add(m_kPoint3Value, scaledPoint);
                m_bValidValue = true;
            }
            else
                weight -= m_pkInterpArray[i].m_fNormalizedWeight;
        }
    }
    if (!m_bValidValue)
    {
        m_kPoint3Value = DAT_011a9424;
        kValue = m_kPoint3Value;
        return false;
    }
    float inverseWeight = 1.0f / weight;
    m_kPoint3Value *= inverseWeight;
    kValue = m_kPoint3Value;
    return true;
}
