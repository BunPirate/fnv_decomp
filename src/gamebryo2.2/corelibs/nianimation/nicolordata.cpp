// gamebryo2.2/corelibs/nianimation/nicolordata.cpp: NiColorData (9 functions)
#include "nicolordata_decls.h"
#include "../../../../include/NiColorData.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"

// Preserve the original out-of-line, nonthrowing setter call in the range-copy entry below.
// @fnv 0x00a3d210
// src: XBOX_RETAIL_PDB 0x00a3d210
// pdb: NiColorData::ReplaceAnim | NiColorData.obj | retail, call graph (shared callers), high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
__declspec(noinline) __declspec(nothrow) void NiColorData::ReplaceAnim(
    ColorAnimationKey* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType)
{
    if (m_pkKeys)
        DAT_011f38e8[m_eType](m_pkKeys);
    if (pkKeys && uiNumKeys)
    {
        m_ucKeySize = DAT_011f376a[eType];
        m_pkKeys = pkKeys;
        m_uiNumKeys = uiNumKeys;
        m_eType = eType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pkKeys = 0;
        m_eType = NiAnimationKey::NOINTERP;
        m_ucKeySize = 0;
    }
}

extern const void* vftable_NiColorData;

// The shared destructor would add base-unwind cleanup around the key-table call; keep this explicit destruction entry.
struct ColorDataDestruction : public NiColorData
{
    void DestroyColorData();
};

// @fnv 0x00a3d120
// pdb: NiColorData::~NiColorData | NiColorData.obj | debug, call graph, medium
// pdb locals: pfnDeleteFunc
void ColorDataDestruction::DestroyColorData()
{
    *(const void**)this = &vftable_NiColorData;
    if (m_pkKeys)
    {
        DAT_011f38e8[m_eType](m_pkKeys);
    }
    this->NiObject::~NiObject();
}

void __cdecl NiAnimationKey_GuaranteeKeyAtStartAndEnd(int, int, void*, unsigned int*, float, float);
// NiColorData.h lacks GuaranteeKeysAtStartAndEnd; the shared class supplies all of this adapter's storage.
struct ColorDataKeyRange : public NiColorData
{
    void GuaranteeKeysAtStartAndEnd(float m_fStartTime, float m_fMaximumDistance);
};
// @fnv 0x00a3d0e0
void ColorDataKeyRange::GuaranteeKeysAtStartAndEnd(float afValue1, float afValue2)
{
    void* pkKeys = m_pkKeys;
    NiAnimationKey_GuaranteeKeyAtStartAndEnd(3, m_eType, &pkKeys, &m_uiNumKeys, afValue1, afValue2);
    m_pkKeys = (ColorAnimationKey*)pkKeys;
}

namespace fnv_00a3d150 {
extern int vftable_NiColorData;

// Allocates a 0x18-byte object, runs its constructor, installs the NiColorData vtable and zeroes three int fields at offsets 8, 0xc and 0x10.
// @fnv 0x00a3d150
// pdb: NiColorData::CreateObject | NiColorData.obj | retail, object-file run extension, low
// pdb locals: pkObject
void* CreateNiColorData()
{
    NiColorData* p = (NiColorData*)NiMemObject::operator new(sizeof(NiColorData));
    if (p)
    {
        new (p) NiObject;
        *(void**)p = (void*)&vftable_NiColorData;
        p->m_uiNumKeys = 0;
        p->m_pkKeys = 0;
        p->m_eType = NiAnimationKey::NOINTERP;
        return p;
    }
    return 0;
}
}  // namespace fnv_00a3d150

extern bool(__cdecl* DAT_011f3b28[])(ColorAnimationKey*, ColorAnimationKey*);

// NiColorData.h lacks the key-comparison override; this adapter adds no storage.
struct ColorDataEquality : public NiColorData
{
    bool CompareKeys(NiColorData* pkObject);
};

// @fnv 0x00a3d190
// pdb: NiColorData::IsEqual | NiColorData.obj | retail, vtable slot, high
// pdb params: pkObject
// pdb locals: equal, pkData, uiI
bool ColorDataEquality::CompareKeys(NiColorData* pkObject)
{
    if (!IsSameAs(pkObject))
        return false;
    if (m_uiNumKeys != pkObject->m_uiNumKeys)
        return false;
    if (m_eType != pkObject->m_eType)
        return false;
    if (m_ucKeySize != pkObject->m_ucKeySize)
        return false;
    bool(__cdecl * pfnKeyCompare)(ColorAnimationKey*, ColorAnimationKey*) = DAT_011f3b28[m_eType];
    for (unsigned int i = 0; i < m_uiNumKeys; ++i)
    {
        ColorAnimationKey* kOther = (ColorAnimationKey*)((char*)pkObject->m_pkKeys + m_ucKeySize * i);
        ColorAnimationKey* kThis = (ColorAnimationKey*)((char*)m_pkKeys + m_ucKeySize * i);
        if (!pfnKeyCompare(kThis, kOther))
            return false;
    }
    return true;
}

inline unsigned int NiBinaryStream::BinaryRead(void* pvBuffer, unsigned int uiTotalBytes,
                                             unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    m_uiAbsoluteCurrentPos += uiBytesRead;
    return uiBytesRead;
}

template <class T> inline void ReadColorDataElements(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int uiSize = sizeof(T);
    stream.BinaryRead(value, count * uiSize, &uiSize, 1);
}

template <class T> inline void LoadColorDataScalar(NiStream& kStream, T& value)
{
    ReadColorDataElements(*kStream.m_pkIstr, &value);
}

template <class T> inline void LoadColorDataEnum(NiStream& kStream, T& eValue)
{
    unsigned int uiValue;
    LoadColorDataScalar(kStream, uiValue);
    eValue = (T)uiValue;
}

typedef ColorAnimationKey*(__cdecl* ColorKeyCreateFunction)(NiStream& kStream, unsigned int uiNumKeys);
extern ColorKeyCreateFunction g_apfnColorKeyCreateA3D[];

// NiColorData.h has no LoadBinary override yet; this adapter adds only its method, using the shared layout.
class ColorDataBinaryLoader : public NiColorData
{
  public:
    void LoadColorKeys(NiStream& stream);
};

// Loads the base object, reads the key count, and if nonzero reads the key type and creates and stores the color keys via the matching create function.
// @fnv 0x00a3d370
// pdb: NiColorData::LoadBinary | NiColorData.obj | retail, vtable slot, high
// pdb params: stream
// pdb locals: uiNumKeys, eColorType, pkColorKeys, cf
void ColorDataBinaryLoader::LoadColorKeys(NiStream& stream)
{
    NiObject::LoadBinary(stream);

    unsigned int uiNumKeys;
    LoadColorDataScalar(stream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        NiAnimationKey::KeyType eType;
        LoadColorDataEnum(stream, eType);
        ColorKeyCreateFunction cf = g_apfnColorKeyCreateA3D[eType];
        ColorAnimationKey* pkKeys = cf(stream, uiNumKeys);
        ReplaceAnim(pkKeys, uiNumKeys, eType);
    }
}

extern void(__cdecl* DAT_011f3a98[])(NiStream*, ColorAnimationKey*, unsigned);

inline void WriteColorDataScalar(NiBinaryStream* stream, const void* src, unsigned bytes)
{
    unsigned comp = bytes;
    stream->m_uiAbsoluteCurrentPos += stream->m_pfnWrite(stream, src, bytes, &comp, 1);
}

template <class T> inline void SaveColorDataScalar(NiStream* stream, const T& value)
{
    WriteColorDataScalar(stream->m_pkOstr, &value, sizeof(T));
}

// NiColorData.h lacks its SaveBinary override; this adapter uses the shared storage and base implementation.
struct ColorDataBinarySaver : NiColorData
{
    void SaveColorKeys(NiStream* stream);
};

// Writes the key count and, when nonzero, the key type and key array through the matching save function.
// @fnv 0x00a3d410
// pdb: NiColorData::SaveBinary | NiColorData.obj | retail, vtable slot, high
// pdb params: stream
// pdb locals: sf
void ColorDataBinarySaver::SaveColorKeys(NiStream* stream)
{
    NiObject::SaveBinary(*stream);
    unsigned& n = m_uiNumKeys;
    SaveColorDataScalar(stream, n);
    if (n > 0)
    {
        SaveColorDataScalar(stream, m_eType);
        DAT_011f3a98[m_eType](stream, m_pkKeys, n);
    }
}

extern void* NiColorData_ms_RTTI;

void* __cdecl NiViewerStrings_NiGetViewerString_Title(void* p);
void* __cdecl NiGetViewerString_00a7d510(const char* s, unsigned int count);

struct FUN_00a3d490_arr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_usCap;           // +0x8
    unsigned short m_usElementCount;  // +0xa
    unsigned short unk0c;             // +0xc
    unsigned short m_usGrow;          // +0xe
    void FUN_0096ad30(unsigned int newCap);
    void FUN_0096ae90(unsigned int index, void** item);
};

// NiColorData.h lacks its viewer-string override; the key count comes from the shared layout.
class ColorDataViewerStrings : public NiColorData
{
  public:
    void CollectViewerStrings(FUN_00a3d490_arr* pStrings);
};

// @fnv 0x00a3d490
// pdb: NiColorData::GetViewerStrings | NiColorData.obj | retail, vtable slot, high
// pdb params: pStrings
void ColorDataViewerStrings::CollectViewerStrings(FUN_00a3d490_arr* pStrings)
{
    NiObject::AddViewerStrings((NiViewerStringsArray*)pStrings);
    void* item = NiViewerStrings_NiGetViewerString_Title(NiColorData_ms_RTTI);
    unsigned int index = pStrings->m_usElementCount;
    if (index >= pStrings->m_usCap)
    {
        pStrings->FUN_0096ad30(index + pStrings->m_usGrow);
    }
    pStrings->FUN_0096ae90(index, &item);

    item = NiGetViewerString_00a7d510("m_uiNumKeys", m_uiNumKeys);
    index = pStrings->m_usElementCount;
    if (index >= pStrings->m_usCap)
    {
        pStrings->FUN_0096ad30(index + pStrings->m_usGrow);
    }
    pStrings->FUN_0096ae90(index, &item);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

__declspec(nothrow) inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}

__declspec(nothrow) inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

template <class T> __declspec(nothrow) inline NiPointer<T>::NiPointer() : m_pObject(0)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> __declspec(nothrow) inline NiPointer<T>::NiPointer(const NiPointer& ptr) : m_pObject(ptr.m_pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}

template <class T> __declspec(nothrow) inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

template <class T> __declspec(nothrow) inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer& ptr)
{
    if (m_pObject != ptr.m_pObject)
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
        m_pObject = ptr.m_pObject;
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> __declspec(nothrow) inline T* NiPointer<T>::operator->() const
{
    return m_pObject;
}

void __cdecl BuildColorKeyRange(NiAnimationKey::KeyContent eContent, NiAnimationKey::KeyType eType,
                                ColorAnimationKey* pkOrigKeys, unsigned int uiOrigNumKeys, float fStartTime, float fEndTime,
                                ColorAnimationKey** pkNewKeys, unsigned int* uiNewNumKeys) throw();

// NiColorData.h lacks the range-copy method; the adapter inherits all object storage from NiColorData.
class ColorDataRangeCopy : public NiColorData
{
  public:
    void CreateData(NiPointer<NiColorData>& aspObject) throw();
    void NiColorData_GetSequenceData(float fStartTime, float fEndTime, NiPointer<NiColorData>& aspColorData);
};

// Creates color data, fills its keys for the requested range, and assigns it to spResult.
// @fnv 0x00a3d270
// src: XBOX_RETAIL_PDB 0x00a3d270
// pdb: NiColorData::GetSequenceData | NiColorData.obj | retail, object-file gap fill, high
// pdb params: fStartTime, fEndTime, aspColorData
// pdb locals: spDeepCopy, spNewData, pkNewKeys, uiNewNumKeys
void ColorDataRangeCopy::NiColorData_GetSequenceData(float fStartTime, float fEndTime, NiPointer<NiColorData>& aspColorData)
{
    NiPointer<NiColorData> spCreated;
    CreateData(spCreated);
    NiPointer<NiColorData> spScreenData = spCreated;
    if (m_uiNumKeys > 0)
    {
        ColorAnimationKey* keys = 0;
        unsigned int count = 0;
        BuildColorKeyRange(NiAnimationKey::COLORKEY, m_eType, m_pkKeys, m_uiNumKeys,
                           fStartTime, fEndTime, &keys, &count);
        spScreenData->ReplaceAnim(keys, count, m_eType);
    }
    aspColorData = spScreenData;
}
