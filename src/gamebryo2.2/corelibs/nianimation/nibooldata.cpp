// gamebryo2.2/corelibs/nianimation/nibooldata.cpp: NiBoolData (7 functions)
#include "NiRefObject_inline.h"

#include "nibooldata_decls.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00a53a50
// pdb: NiBoolData::LoadBinary | NiBoolData.obj | retail, upstream name already matches, high
// pdb params: kStream
// pdb locals: uiNumKeys, eBoolType, pfnCreateFunc, pkBoolKeys, pfnFillDerivedFunc
void NiBoolData::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    NiAnimationKey::KeyType type = NiAnimationKey::STEPKEY;
    unsigned int numKeys;
    ReadBinaryValue(kStream, numKeys);
    if (numKeys > 0)
    {
        if (kStream.m_uiNifFileVersion >= 0x0a010068)
            ReadBinaryValue(kStream, type);
        m_ucKeySize = BooleanKey::GetKeySize(type);
        BooleanKey* keys = static_cast<BooleanKey*>(BooleanKey::GetLoadFunction(type)(kStream, numKeys));
        BooleanKey::GetFillDerivedFunction(type)(keys, numKeys, m_ucKeySize);
        SetColorKeys(keys, numKeys, type);
    }
}

// Replaces the stored key array: frees the old keys, then stores the new keys, count, key type and key size, or clears them when keys is null or numKeys is zero.
// @fnv 0x00a538b0
// pdb: NiBoolData::~NiBoolData | NiBoolData.obj | retail, object-file run extension, low
void NiBoolData::SetColorKeys(BooleanKey* keys, unsigned int numKeys, NiAnimationKey::KeyType eKeyType)
{
    if (m_pkKeys)
        BooleanKey::GetDeleteFunction(m_eType)(m_pkKeys);
    if (keys && numKeys)
    {
        m_ucKeySize = BooleanKey::GetKeySize(eKeyType);
        m_pkKeys = keys;
        m_uiNumKeys = numKeys;
        m_eType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pkKeys = 0;
        m_eType = NiAnimationKey::NOINTERP;
        m_ucKeySize = 0;
    }
}

void __cdecl NiAnimationKey_GuaranteeKeyAtStartAndEnd(unsigned int, unsigned int, void*&, unsigned int&, float, float);
// These entry points use ECX for the shared object and retain the original stack arguments.
// The shared class does not yet declare these NiBoolData operations.
// @fnv 0x00a537a0
void __fastcall GuaranteeBoolKeys(NiBoolData* data, void*, float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = data->m_pkKeys;
    NiAnimationKey_GuaranteeKeyAtStartAndEnd(5, data->m_eType, pkKeys, data->m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    data->m_pkKeys = static_cast<BooleanKey*>(pkKeys);
}

struct GlobalObjectO2_00a7b610
{
    void* pObject;
};

extern GlobalObjectO2_00a7b610 NiBoolData_ms_RTTI; // src: XBOX_RETAIL_PDB 0x011f4054 (old: g_011f4054)

void __stdcall AppendCameraPathEntries(StrArr*);
void* __cdecl _FUN_00a7d330(void*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);

// @fnv 0x00a53ba0
// pdb: NiBoolData::GetViewerStrings | NiBoolData.obj | retail, object-file run extension, low
// pdb params: pStrings
void __fastcall GetBoolViewerStrings(NiBoolData* data, void*, StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);

    char* pString = static_cast<char*>(_FUN_00a7d330(NiBoolData_ms_RTTI.pObject));
    unsigned int uiIndex = apViewerStrings->m_usSize;
    unsigned int uiCapacity = apViewerStrings->m_usMaxSize;

    if (uiIndex >= uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + uiIndex);

    apViewerStrings->SetAt(uiIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumKeys", data->m_uiNumKeys);
    uiIndex = apViewerStrings->m_usSize;
    uiCapacity = apViewerStrings->m_usMaxSize;

    if (uiIndex >= uiCapacity)
        apViewerStrings->SetSize(apViewerStrings->m_usGrowBy + uiIndex);

    apViewerStrings->SetAt(uiIndex, pString);
}

typedef bool(__cdecl* FUN_00a53830_elemcmp)(void* a, void* b);
extern FUN_00a53830_elemcmp DAT_011f3b58[];

// Compares the base object, key count, type and stride, then compares each key with the type-specific function.
// @fnv 0x00a53830
// pdb: NiBoolData::IsEqual | NiBoolData.obj | retail, object-file run extension, low
// pdb params: pkObject
// pdb locals: pkData, pfnEqualFunc, ui
bool __fastcall EqualsBoolData(NiBoolData* data, void*, NiBoolData* other)
{
    if (!data->IsSameAs(other))
    {
        return false;
    }
    if (data->m_uiNumKeys != other->m_uiNumKeys)
    {
        return false;
    }
    if (data->m_eType != other->m_eType)
    {
        return false;
    }
    if (data->m_ucKeySize != other->m_ucKeySize)
    {
        return false;
    }
    FUN_00a53830_elemcmp pElemCmp = DAT_011f3b58[data->m_eType];
    for (unsigned int uiIndex = 0; uiIndex < data->m_uiNumKeys; ++uiIndex)
    {
        unsigned int off = (unsigned int)data->m_ucKeySize * uiIndex;
        unsigned char* pOtherData = reinterpret_cast<unsigned char*>(other->m_pkKeys) + off;
        unsigned char* pThisData = reinterpret_cast<unsigned char*>(data->m_pkKeys) + off;
        if (!pElemCmp(pThisData, pOtherData))
        {
            return false;
        }
    }
    return true;
}

typedef void(__cdecl* NiBoolSaveKeysFunction)(NiStream&, BooleanKey*, unsigned int);
extern "C" NiBoolSaveKeysFunction DAT_011f3ac8[NiAnimationKey::NUMKEYTYPES];
template <class T> inline void BinaryWriteValue(NiBinaryStream* output, const T& value)
{
    unsigned int size = sizeof(T);
    output->m_uiAbsoluteCurrentPos += output->m_pfnWrite(output, &value, size, &size, 1);
}
template <class T> inline void WriteValue(NiStream& stream, const T& value)
{
    BinaryWriteValue(stream.m_pkOstr, value);
}
// @fnv 0x00a53b20
// pdb: NiBoolData::SaveBinary | NiBoolData.obj | retail, object-file run extension, low
// pdb params: kStream
// pdb locals: pfnSaveFunc
void __fastcall SaveBoolData(NiBoolData* data, void*, NiStream& stream)
{
    data->NiObject::SaveBinary(stream);
    WriteValue(stream, data->m_uiNumKeys);
    if (data->m_uiNumKeys > 0)
    {
        WriteValue(stream, data->m_eType);
        DAT_011f3ac8[data->m_eType](stream, data->m_pkKeys, data->m_uiNumKeys);
    }
}

void __cdecl NiAnimationKey_CopySequence(unsigned int eContent, NiAnimationKey::KeyType eType, BooleanKey* pkOrigKeys,
                          unsigned int uiOrigNumKeys, float fStartTime, float fEndTime, BooleanKey** pkNewKeys,
                          unsigned int* uiNewNumKeys);

// Clones this NiBoolData, processes its keys with the requested time range when present, and assigns the result to output.
// @fnv 0x00a53910
// pdb: NiBoolData::ReplaceAnim | NiBoolData.obj | retail, object-file run extension, low
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void __fastcall CloneBoolDataForTimeRange(NiBoolData* data, void*, float startTime, float endTime, NiPointer<NiBoolData>& output)
{
    NiBoolData* original = 0;
    data->ResolveObjectPointer(reinterpret_cast<NiPointer<NiObject>&>(original));

    NiBoolData* copy = original;
    if (copy != 0)
        copy->IncRefCount();

    if (data->m_uiNumKeys > 0)
    {
        BooleanKey* keys = 0;
        unsigned int count = 0;
        NiAnimationKey_CopySequence(5, data->m_eType, data->m_pkKeys, data->m_uiNumKeys, startTime, endTime, &keys, &count);
        copy->SetColorKeys(keys, count, data->m_eType);
    }

    NiBoolData* previous = output.m_pObject;
    if (previous != copy)
    {
        if (previous != 0)
            previous->DecRefCount();

        output.m_pObject = copy;
        if (copy != 0)
            copy->IncRefCount();
    }
    if (copy != 0)
        copy->DecRefCount();
    if (original != 0)
        original->DecRefCount();
}
