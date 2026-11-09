#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBoolInterpController.h"
#include "../../../../include/NiBoolData.h"
#include "../../../../include/NiBoolInterpolator.h"
#include "../../../../include/NiBoolTimelineInterpolator.h"
#include "../../../../include/NiKeyBasedInterpolator.h"
#include "../../../../include/StrArr.h"

// src/gamebryo2.2/corelibs/nianimation/nibooltimelineinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibooltimelineinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* NiBoolTimelineInterpolator_ms_RTTI;

// @fnv 0x00a52d70
// src: COMMUNITY 0x00a52d70
void* __cdecl NiBoolTimelineInterpolator_GetRTTI()
{
    return &NiBoolTimelineInterpolator_ms_RTTI;
}

extern int DAT_01099fb4;


// Allocates a 0x20-byte NiBoolInterpolator, initialises its vtable, clears the field at offset 0x18 and the byte at 0x1c, and returns it (or null).
// @fnv 0x00a52fe0
NiBoolInterpolator* __cdecl CreateBoolInterpolator()
{
    NiBoolInterpolator* p = static_cast<NiBoolInterpolator*>(BSFadeNode::operator new(0x20));
    if (p)
    {
        p->NiBoolInterpolator_ctor(0);
        *reinterpret_cast<void**>(p) = reinterpret_cast<void*>(&DAT_01099fb4);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x18) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p) + 0x1c) = 0;
        return p;
    }
    return 0;
}

inline NiBoolTimelineInterpolator::NiBoolTimelineInterpolator() throw() : NiBoolInterpolator(static_cast<void*>(0))
{
    m_uiPreviousIdx = 0;
    m_bPreviousValue = false;
}


void __cdecl UpdateState_00a3ca30();
void __cdecl _delete(void*, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// Decrements the reference count of m_ptr and calls DeleteThis when it reaches zero, then calls FUN_00a3ca30 and frees this if flag bit 0 is set.
// @fnv 0x00a52f30
// pdb: NiBoolTimelineInterpolator::`scalar deleting destructor' | NiBoolTimelineInterpolator.obj | retail, object-file run extension, low
void* NiBoolTimelineInterpolator::ReleaseRef(unsigned int auiFlags)
{
    NiBoolData* p = m_spBoolData.m_pObject;
    if (p)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
    }
    typedef void (__thiscall* DestroyBase)(NiBoolInterpolator*);
    reinterpret_cast<DestroyBase>(&UpdateState_00a3ca30)(this);
    if (auiFlags & 1)
        _delete(this, 0x20);
    return this;
}

void __cdecl FUN_00a536d0();
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330(g_011f4044) to pkStrings, growing it via SetSize when full, after calling FUN_00a536d0.
// @fnv 0x00a53020
void NiBoolTimelineInterpolator::AppendString(StrArr* pkStrings)
{
    typedef void (__thiscall* AppendBaseStrings)(NiBoolInterpolator*, StrArr*);
    reinterpret_cast<AppendBaseStrings>(&FUN_00a536d0)(this, pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)NiBoolTimelineInterpolator_ms_RTTI);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pszStr);
}

extern unsigned int DAT_0109a0b4;
extern unsigned char DAT_0109a914;
// Allocates a 0x18-byte NiKeyBasedInterpolator, constructs it, sets its vtable and fields, and returns the pointer or 0.
// @fnv 0x00a53500
// src: XBOX_RETAIL_PDB 0x00a53500
// pdb: NiBoolInterpolator::CreateObject | NiBoolInterpolator.obj | retail, object-file gap fill, high
// pdb locals: pkObject
void* NiBoolInterpolator_CreateObject()
{
    void* p = BSFadeNode::operator new(0x18);
    if (p)
    {
        static_cast<NiKeyBasedInterpolator*>(p)->NiKeyBasedInterpolator::NiKeyBasedInterpolator();
        *(unsigned int*)p = (unsigned int)&DAT_0109a0b4;
        *(unsigned char*)((char*)p + 0xc) = DAT_0109a914;
        *(unsigned int*)((char*)p + 0x10) = 0;
        *(unsigned int*)((char*)p + 0x14) = 0;
        return p;
    }
    return 0;
}

// Constructs the object, links it to the given NiBoolData stream, zeroes two fields and sets the vtable.
// @fnv 0x00a52f00
// pdb: NiBoolTimelineInterpolator::NiBoolTimelineInterpolator | NiBoolTimelineInterpolator.obj | retail, upstream name already matches, high
// pdb params: pkBoolData
NiBoolTimelineInterpolator::NiBoolTimelineInterpolator(NiBoolData* pkBoolData)
    : NiBoolInterpolator(pkBoolData)
{
    m_uiPreviousIdx = 0;
    m_bPreviousValue = 0;
    *(int**)this = &DAT_01099fb4;
}

struct BoolKey
{
    float time;
    unsigned char opposite;
};
unsigned char __cdecl NiBoolKey_GenInterp(float, BoolKey*, unsigned int, unsigned int, unsigned int&, unsigned char);
// Evaluates the boolean key timeline at time, updating index, cached and m_bBoolValue, and returns whether a value is available via out.
// @fnv 0x00a52d80
// pdb: NiBoolTimelineInterpolator::Update | NiBoolTimelineInterpolator.obj | retail, object-file run extension, low
// pdb params: fTime, pkInterpTarget, bValue
// pdb locals: uiNumKeys, pkKeys, ucSize, eType, bInterpValue, bBoolValue, uiCurrentIdx, bValueToFind, ui
bool NiBoolTimelineInterpolator::EvaluateBoolAtTime(float time, void*, bool& out)
{
    unsigned char& cached = reinterpret_cast<unsigned char&>(NiBoolInterpolator::m_bBoolValue);
    if (m_fLastTime == time)
    {
        if (cached == DAT_0109a914)
        {
            out = false;
            return false;
        }
        out = cached != 0;
        return true;
    }
    if (m_spBoolData.m_pObject)
    {
        unsigned int type = m_spBoolData.m_pObject->m_eType;
        unsigned char stride = m_spBoolData.m_pObject->m_ucKeySize;
        BoolKey* keys = reinterpret_cast<BoolKey*>(m_spBoolData.m_pObject->m_pkKeys);
        unsigned int count = m_spBoolData.m_pObject->m_uiNumKeys;
        if (count > 0)
        {
            m_uiPreviousIdx = m_uiLastIdx;
            unsigned char opposite = NiBoolKey_GenInterp(time, keys, type, count, m_uiLastIdx, stride);
            unsigned int current = m_uiLastIdx;
            unsigned char result = opposite;
            unsigned char value;
            if (opposite == reinterpret_cast<unsigned char&>(m_bPreviousValue))
            {
                value = !opposite;
                if (m_uiPreviousIdx != current && m_uiPreviousIdx + 1 > current)
                {
                    for (unsigned int uiIndex = m_uiPreviousIdx + 1; uiIndex < count; uiIndex++)
                    {
                        if (((BoolKey*)((char*)keys + stride * uiIndex))->opposite == value)
                        {
                            goto changed;
                        }
                    }
                    if (opposite != value)
                    {
                        for (unsigned int uiIndex2 = 0; uiIndex2 < current; uiIndex2++)
                        {
                            if (((BoolKey*)((char*)keys + stride * uiIndex2))->opposite == value)
                            {
                                goto changed;
                            }
                        }
                    }
                }
                else
                {
                    for (unsigned int uiIndex3 = m_uiPreviousIdx + 1; uiIndex3 < current && uiIndex3 < count; uiIndex3++)
                    {
                        if (((BoolKey*)((char*)keys + stride * uiIndex3))->opposite == value)
                        {
                            goto changed;
                        }
                    }
                }
            }
            goto ready;
        changed:
            result = value;
        ready:
            cached = result != 0;
            reinterpret_cast<unsigned char&>(m_bPreviousValue) = opposite;
        }
    }
    if (cached == DAT_0109a914)
    {
        out = false;
        return false;
    }
    out = cached != 0;
    m_fLastTime = time;
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plAddend);

inline void IncBoolDataRefCount(NiBoolData* data)
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&data->m_uiRefCount));
}

inline void DecBoolDataRefCount(NiBoolData* data)
{
    if (InterlockedDecrement(reinterpret_cast<volatile long*>(&data->m_uiRefCount)) == 0)
        data->DeleteThis();
}

inline NiPointer<NiBoolData>& NiPointer<NiBoolData>::operator=(const NiPointer& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            DecBoolDataRefCount(m_pObject);
        m_pObject = other.m_pObject;
        if (m_pObject)
            IncBoolDataRefCount(m_pObject);
    }
    return *this;
}

// @fnv 0x00a53480
// src: XBOX_RETAIL_PDB 0x00a53480
// pdb: NiBoolInterpolator::CopyMembers | NiBoolInterpolator.obj | retail, object-file gap fill, high
// pdb params: pkDest, kCloning
void NiBoolInterpolator::CopyMembers(NiBoolInterpolator* pkDest, CloningProcess& kCloning)
{
    NiObject::CopyMemberData(pkDest, kCloning);
    pkDest->m_bBoolValue = m_bBoolValue;
    pkDest->m_spBoolData = m_spBoolData;
    pkDest->m_uiLastIdx = m_uiLastIdx;
}

void __cdecl j_j_j_nullsub_3();
// @fnv 0x00a514d0
// src: COMMUNITY 0x00a514d0
void __cdecl j_j_j_j_nullsub_3()
{
    j_j_j_nullsub_3();
}

void __cdecl SaveToStream();

// @fnv 0x00a52d00
// src: XBOX_PDB 0x00a52d00
// pdb: NiBoolTimelineInterpolator::SaveBinary | NiBoolTimelineInterpolator.obj | debug, upstream name already matches, high
// pdb params: kStream
void __cdecl NiBoolTimelineInterpolator_SaveBinary()
{
    SaveToStream();
}

extern void FUN_00a53600();

// @fnv 0x00a52ce0
// src: XBOX_PDB 0x00a52ce0
// pdb: NiBoolTimelineInterpolator::LoadBinary | NiBoolTimelineInterpolator.obj | debug, upstream name already matches, high
// pdb params: kStream
void NiBoolTimelineInterpolator_LoadBinary()
{
    FUN_00a53600();
}

extern void RegisterStreamables_00a3c5b0();

// @fnv 0x00a52cf0
// src: XBOX_PDB 0x00a52cf0
// pdb: NiBoolTimelineInterpolator::RegisterStreamables | NiBoolTimelineInterpolator.obj | debug, upstream name already matches, high
// pdb params: kStream
void NiBoolTimelineInterpolator_RegisterStreamables()
{
    RegisterStreamables_00a3c5b0();
}

bool __cdecl FUN_00a53220();
// @fnv 0x00a52d10
// src: XBOX_PDB 0x00a52d10
bool NiBoolTimelineInterpolator::IsEqual_00a52d10()
{
    typedef bool (__thiscall* IsEqualBase)(NiBoolInterpolator*);
    return reinterpret_cast<IsEqualBase>(&FUN_00a53220)(this);
}

// Allocates a timeline interpolator and copies its base state into the clone.
// @fnv 0x00a52f80
// src: XBOX_PDB 0x00a52f80
// pdb: NiBoolTimelineInterpolator::CreateClone | NiBoolTimelineInterpolator.obj | retail, object-file run extension, low
// pdb params: kCloning
// pdb locals: pkObject
NiBoolTimelineInterpolator* NiBoolTimelineInterpolator::CreateClone_00a52f80(CloningProcess& cloning)
{
    NiBoolTimelineInterpolator* p = new NiBoolTimelineInterpolator;
    NiBoolInterpolator::CopyMembers(p, cloning);
    return p;
}
