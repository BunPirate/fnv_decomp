// gamebryo2.2/corelibs/nianimation/nifloatdata.cpp: NiFloatData (10 functions)

#include "../../../../include/NiFloatData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiStream.h"
#include "nifloatdata_decls.h"
#include "../../../../include/StrArr.h"

// @fnv 0x00a3cdc0
// src: XBOX_RETAIL_PDB 0x00a3cdc0
// pdb: NiFloatData::ReplaceAnim | NiFloatData.obj | retail, call graph (shared callers), high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void NiFloatData::ReplaceAnim(TimedAnimationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType)
{
    if (m_pkKeys)
        DAT_011f38a0[m_eType](m_pkKeys);
    if (pkKeys && uiNumKeys && eType)
    {
        m_ucKeySize = DAT_011f3758[eType];
        m_pkKeys = pkKeys;
        m_uiNumKeys = uiNumKeys;
        m_eType = eType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pkKeys = 0;
        m_ucKeySize = 0;
        m_eType = NiAnimationKey::NOINTERP;
    }
}

extern const void* vftable_NiFloatData[];

// The unused EDX parameter preserves the original member functions' stack arguments.
// @fnv 0x00a3cc80
// pdb: NiFloatData::GuaranteeKeysAtStartAndEnd | NiFloatData.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiFloatData::~NiFloatData
// pdb params: fStartTime, fEndTime
// pdb locals: pkKeys
void __fastcall DestroyFloatData(NiFloatData* self, void*)
{
    *(const void***)self = vftable_NiFloatData;
    if (self->m_pkKeys)
    {
        DAT_011f38a0[self->m_eType](self->m_pkKeys);
    }
    self->NiObject::FUN_00a5d3d0();
}

void __cdecl NiAnimationKey_GuaranteeKeyAtStartAndEnd(int, int, void*, void*, float, float);
// Calls UpdateSlotStates with the key count, key pointer and two floats, then stores the updated key pointer back.
// @fnv 0x00a3cc40
// pdb: NiKeyBasedInterpolator::`scalar deleting destructor' | NiKeyBasedInterpolator.obj | debug, object-file run extension, low
void __fastcall SetFloatDataRange(NiFloatData* self, void*, float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = self->m_pkKeys;
    NiAnimationKey_GuaranteeKeyAtStartAndEnd(0, self->m_eType, &pkKeys, &self->m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    self->m_pkKeys = static_cast<TimedAnimationKey*>(pkKeys);
}

extern unsigned char DAT_41890871[];
// Stores the keys pointer, key count and type, caching DAT_41890871[type] as a byte; clears all fields when any argument is null or zero.
// @fnv 0x00a3ccb0
// pdb: NiFloatData::~NiFloatData | NiFloatData.obj | retail, object-file run extension, low
// pdb locals: pfnDeleteFunc
void __fastcall SetFloatDataKeys(NiFloatData* self, void*, TimedAnimationKey* keys, unsigned int numKeys, NiAnimationKey::KeyType type)
{
    if (keys && numKeys && type)
    {
        self->m_ucKeySize = DAT_41890871[type];
        self->m_pkKeys = keys;
        self->m_uiNumKeys = numKeys;
        self->m_eType = type;
    }
    else
    {
        self->m_uiNumKeys = 0;
        self->m_pkKeys = 0;
        self->m_eType = NiAnimationKey::NOINTERP;
        self->m_ucKeySize = 0;
    }
}

namespace fnv_00a3cd00 {

void __fastcall _Call_a5d3a0(void* object);

extern const char vftable_NiFloatData[];

// @fnv 0x00a3cd00
// pdb: NiFloatData::CreateObject | NiFloatData.obj | retail, object-file run extension, low
// pdb locals: pkObject
NiFloatData* CreateNiFloatData()
{
    NiFloatData* object = static_cast<NiFloatData*>(NiObject::operator new(0x18));

    if (object)
    {
        _Call_a5d3a0(object);

        object->m_uiNumKeys = 0;
        object->m_pkKeys = 0;
        object->m_eType = NiAnimationKey::NOINTERP;
        object->m_ucKeySize = 0;

        *reinterpret_cast<void**>(object) = const_cast<void*>(static_cast<const void*>(vftable_NiFloatData));
        return object;
    }

    return 0;
}
}  // namespace fnv_00a3cd00

struct GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610* NiFloatData_ms_RTTI; // src: XBOX_RETAIL_PDB 0x011f3748 (old: g_011f3748)

void __stdcall AppendCameraPathEntries(StrArr* pStrings);
char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);
char* __cdecl NiGetViewerString_00a7d510(char const* name, unsigned int value);

// @fnv 0x00a3d050
// pdb: NiFloatData::GetViewerStrings | NiFloatData.obj | retail, vtable slot, high
// pdb params: pStrings
void __fastcall GetFloatDataViewerStrings(NiFloatData* self, void*, StrArr* strings)
{
    AppendCameraPathEntries(strings);

    char* value = _FUN_00a7d330(NiFloatData_ms_RTTI);
    unsigned int index = strings->m_usSize;
    unsigned int capacity = strings->m_usMaxSize;

    if (index >= capacity)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);

    value = NiGetViewerString_00a7d510("m_uiNumKeys", self->m_uiNumKeys);
    index = strings->m_usSize;
    capacity = strings->m_usMaxSize;

    if (index >= capacity)
        strings->SetSize(index + strings->m_usGrowBy);

    strings->SetAt(index, value);
}

struct WriteStream
{
    void* data00;
    unsigned int position04;
    unsigned int unk08;
    unsigned int(__cdecl* write0c)(WriteStream*, const void*, unsigned int, unsigned int*, int);
    __forceinline void Write(const void* data)
    {
        unsigned int size = 4;
        position04 += write0c(this, data, 4, &size, 1);
    }
};
inline WriteStream* NiStream::GetWriter()
{
    return *reinterpret_cast<WriteStream**>((char*)this + 0x250);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>((char*)this + 0x24c);
}
extern void(__cdecl* DAT_011f3a50[])(NiStream*, TimedAnimationKey*, unsigned int);
// @fnv 0x00a3cfd0
// pdb: NiFloatData::SaveBinary | NiFloatData.obj | retail, vtable slot, high
// pdb params: stream
// pdb locals: sf
void __fastcall SaveFloatDataBinary(NiFloatData* self, void*, NiStream* stream)
{
    self->NiObject::SaveBinary(*stream);
    stream->GetWriter()->Write(&self->m_uiNumKeys);
    if (self->m_uiNumKeys > 0)
    {
        stream->GetWriter()->Write(&self->m_eType);
        DAT_011f3a50[self->m_eType](stream, self->m_pkKeys, self->m_uiNumKeys);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* Addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* Addend);

inline void NiRefObject::AcquireReference()
{
    InterlockedIncrement((volatile long*)&m_uiRefCount);
}

inline void NiRefObject::DecRef()
{
    if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        DeleteThis();
}

extern void __cdecl NiAnimationKey_CopySequence(int, int, TimedAnimationKey*, unsigned int, float, float, TimedAnimationKey**,
                                 unsigned int*);

// @fnv 0x00a3ce20
// src: XBOX_RETAIL_PDB 0x00a3ce20
// pdb: NiFloatData::GetSequenceData | NiFloatData.obj | retail, call graph, high
// pdb params: fStartTime, fEndTime, aspFloatData
// pdb locals: spDeepCopy, spNewData, pkNewKeys, uiNewNumKeys
void __fastcall NiFloatData_GetSequenceData(NiFloatData* self, void*, float m_fStartTime, float m_fMaximumDistance, NiFloatData** ppResult)
{
    NiFloatData* pData = 0;
    self->ResolveObjectPointer(*reinterpret_cast<NiPointer<NiObject>*>(&pData));
    NiFloatData* pCur = pData;
    if (pCur != 0)
        pCur->AcquireReference();
    if (self->m_uiNumKeys > 0)
    {
        TimedAnimationKey* pKeys = 0;
        unsigned int uiNumKeys = 0;
        NiAnimationKey_CopySequence(0, (int)self->m_eType, self->m_pkKeys, self->m_uiNumKeys, m_fStartTime, m_fMaximumDistance, &pKeys,
                     &uiNumKeys);
        pCur->ReplaceAnim(pKeys, uiNumKeys, self->m_eType);
    }
    NiFloatData* pOld = *ppResult;
    if (pOld != pCur)
    {
        if (pOld != 0)
            pOld->DecRef();
        *ppResult = pCur;
        if (pCur != 0)
            pCur->AcquireReference();
    }
    if (pCur != 0)
        pCur->DecRef();
    if (pData != 0)
        pData->DecRef();
}

typedef bool(__cdecl* FUN_00a3cd40_KeyCmp)(void*, void*);
extern FUN_00a3cd40_KeyCmp DAT_011f3ae0[];

// Compares this NiFloatData with another by checking key count, request type, key data size, and each key via a type-specific comparator.
// @fnv 0x00a3cd40
// pdb: NiFloatData::IsEqual | NiFloatData.obj | retail, vtable slot, high
// pdb params: pkObject
// pdb locals: equal, pkData, i
bool __fastcall IsFloatDataEqual(NiFloatData* self, void*, NiFloatData* other)
{
    if (!self->NiObject::IsSameAs(other))
    {
        return false;
    }
    if (self->m_uiNumKeys != other->m_uiNumKeys)
    {
        return false;
    }
    if (self->m_eType != other->m_eType)
    {
        return false;
    }
    if (self->m_ucKeySize != other->m_ucKeySize)
    {
        return false;
    }
    FUN_00a3cd40_KeyCmp cmp = DAT_011f3ae0[self->m_eType];
    unsigned int iKeyIndex = 0;
    if (self->m_uiNumKeys > 0)
    {
        do
        {
            void* a = (char*)other->m_pkKeys + (unsigned int)self->m_ucKeySize * iKeyIndex;
            void* n = (char*)self->m_pkKeys + (unsigned int)self->m_ucKeySize * iKeyIndex;
            if (!cmp(n, a))
            {
                return false;
            }
            ++iKeyIndex;
        } while (iKeyIndex < self->m_uiNumKeys);
    }
    return true;
}

typedef TimedAnimationKey*(__cdecl* CreateFn_cf)(NiStream&, unsigned int);
typedef void(__cdecl* FillFn_cf)(TimedAnimationKey*, unsigned int, unsigned char);
extern CreateFn_cf DAT_011f3db0[];
extern FillFn_cf DAT_011f3780[];

struct StreamBinView_cf
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(StreamBinView_cf* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

template <class T> inline void LoadEnum(StreamBinView_cf* istr, T& v)
{
    unsigned int u;
    istr->Load(&u);
    v = (T)u;
}

// Loads animation key data from a NiStream, reading key count, type, and key values, then stores them via SetColorKeys.
// @fnv 0x00a3cf10
// pdb: NiFloatData::LoadBinary | NiFloatData.obj | retail, upstream name already matches, high
// pdb params: stream
// pdb locals: uiNumKeys, pkKeys, cf, derived, eType
void NiFloatData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int numKeys;

    reinterpret_cast<StreamBinView_cf*>(stream.GetBinaryStream())->Load(&numKeys);
    if (numKeys > 0)
    {
        NiAnimationKey::KeyType keyType;
        LoadEnum(reinterpret_cast<StreamBinView_cf*>(stream.GetBinaryStream()), keyType);
        m_ucKeySize = DAT_011f3758[keyType];
        CreateFn_cf pCreateFn = DAT_011f3db0[keyType];
        TimedAnimationKey* keys = pCreateFn(stream, numKeys);
        FillFn_cf pFillFn = DAT_011f3780[keyType];
        pFillFn(keys, numKeys, m_ucKeySize);
        ReplaceAnim(keys, numKeys, keyType);
    }
}
