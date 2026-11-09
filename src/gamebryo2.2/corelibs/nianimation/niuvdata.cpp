
// src/gamebryo2.2/corelibs/nianimation/niuvdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niuvdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiUVData.h"
#include "../../../../include/StrArr.h"

extern const void* g_011f3f10;

// @fnv 0x00a45010
// src: COMMUNITY 0x00a45010
const void* __cdecl NiUVData_GetRTTI()
{
    return &g_011f3f10;
}

void __cdecl _delete(void*, unsigned int);
// Calls Destructor, then frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a45200
void* NiUVData::FUN_00a45200(unsigned int flags)
{
    Destructor();
    if (flags & 1)
        _delete(this, 0x4C);
    return this;
}

extern void(__cdecl* DAT_011f38a0[])(void*);
extern unsigned char DAT_011f3758[];
// @fnv 0x00a45280
// src: XBOX_PDB 0x00a45280
// pdb: NiUVData::ReplaceVOffsetAnim | NiUVData.obj | retail, upstream name already matches, high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void NiUVData::ReplaceVOffsetAnim(void* pkKeys, unsigned int uiNumKeys, int eType)
{
    void* oldKeys = m_pkVOffsetKeys;
    if (oldKeys)
        DAT_011f38a0[m_eVOffsetType](oldKeys);
    if (pkKeys && uiNumKeys)
    {
        m_uiNumVOffsetKeys = uiNumKeys;
        m_pkVOffsetKeys = reinterpret_cast<unsigned char*>(pkKeys);
        m_eVOffsetType = eType;
        m_ucVOffsetSize = DAT_011f3758[eType];
    }
    else
    {
        m_uiNumVOffsetKeys = 0;
        m_pkVOffsetKeys = 0;
        m_eVOffsetType = 0;
        m_ucVOffsetSize = 0;
    }
}


// Releases the previous key data, then stores the new keys, count and type (or clears them when keys or count is null/zero).
// @fnv 0x00a45340
// src: XBOX_PDB 0x00a45340
// pdb: NiUVData::ReplaceVTilingAnim | NiUVData.obj | retail, upstream name already matches, high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void NiUVData::ReplaceVTilingAnim(void* pkKeys, unsigned int uiNumKeys, unsigned int eType)
{
    if (m_pkVTilingKeys)
        DAT_011f38a0[m_eVTilingType](m_pkVTilingKeys);
    if (pkKeys && uiNumKeys)
    {
        m_uiNumVTilingKeys = uiNumKeys;
        m_pkVTilingKeys = reinterpret_cast<unsigned char*>(pkKeys);
        m_eVTilingType = eType;
        m_ucVTilingSize = DAT_011f3758[eType];
    }
    else
    {
        m_uiNumVTilingKeys = 0;
        m_pkVTilingKeys = 0;
        m_eVTilingType = 0;
        m_ucVTilingSize = 0;
    }
}


// Releases the current key array, then stores the new keys, count and type (or clears them when keys or numKeys is null/zero).
// @fnv 0x00a45220
// src: XBOX_PDB 0x00a45220
// pdb: NiUVData::ReplaceUOffsetAnim | NiUVData.obj | retail, upstream name already matches, high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void NiUVData::ReplaceUOffsetAnim(TimedAnimationKey* pkKeys, unsigned int uiNumKeys, unsigned int eType)
{
    if (m_pkUOffsetKeys)
        DAT_011f38a0[m_eUOffsetType](m_pkUOffsetKeys);
    if (pkKeys && uiNumKeys)
    {
        m_uiNumUOffsetKeys = uiNumKeys;
        m_pkUOffsetKeys = reinterpret_cast<unsigned char*>(pkKeys);
        m_eUOffsetType = eType;
        m_ucUOffsetSize = DAT_011f3758[eType];
    }
    else
    {
        m_uiNumUOffsetKeys = 0;
        m_pkUOffsetKeys = 0;
        m_eUOffsetType = 0;
        m_ucUOffsetSize = 0;
    }
}

// Releases the previous key array, then stores the new keys, count and type (or clears them when keys or count is null/zero).
// @fnv 0x00a452e0
// src: XBOX_PDB 0x00a452e0
// pdb: NiUVData::ReplaceUTilingAnim | NiUVData.obj | retail, upstream name already matches, high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void NiUVData::ReplaceUTilingAnim(void* pkKeys, unsigned int uiNumKeys, unsigned int eType)
{
    if (m_pkUTilingKeys)
        DAT_011f38a0[m_eUTilingType](m_pkUTilingKeys);
    if (pkKeys && uiNumKeys)
    {
        m_uiNumUTilingKeys = uiNumKeys;
        m_pkUTilingKeys = reinterpret_cast<unsigned char*>(pkKeys);
        m_eUTilingType = eType;
        m_ucUTilingSize = DAT_011f3758[eType];
    }
    else
    {
        m_uiNumUTilingKeys = 0;
        m_pkUTilingKeys = 0;
        m_eUTilingType = 0;
        m_ucUTilingSize = 0;
    }
}

extern int DAT_01097f84;


// Sets the vtable, releases the four pointer members via DAT_011f38a0 if non-null, then calls the NiRefObject destructor.
// @fnv 0x00a45020
void NiUVData::Destructor()
{
    *(void**)this = (void*)&DAT_01097f84;
    void* p;
    p = m_pkUOffsetKeys;
    if (p)
        DAT_011f38a0[m_eUOffsetType](p);
    p = m_pkVOffsetKeys;
    if (p)
        DAT_011f38a0[m_eVOffsetType](p);
    p = m_pkUTilingKeys;
    if (p)
        DAT_011f38a0[m_eUTilingType](p);
    p = m_pkVTilingKeys;
    if (p)
        DAT_011f38a0[m_eVTilingType](p);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}


void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl _FUN_00a7d330(char*);
char* __cdecl NiGetViewerString_00a7d510(char const*, unsigned int);


// @fnv 0x00a457d0
// pdb: NiUVData::GetViewerStrings | NiUVData.obj | retail, string-set bridge, high
// pdb params: pStrings
void NiUVData::AppendKeyNames(StrArr* pStrings)
{
    char* pString;
    unsigned int nIndex;

    AppendCameraPathEntries(pStrings);

    pString = _FUN_00a7d330(const_cast<char*>(static_cast<const char*>(g_011f3f10)));
    nIndex = pStrings->m_usSize;
    if (nIndex >= pStrings->m_usMaxSize)
        pStrings->SetSize(pStrings->m_usGrowBy + nIndex);
    pStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumUOffsetKeys", m_uiNumUOffsetKeys);
    nIndex = pStrings->m_usSize;
    if (nIndex >= pStrings->m_usMaxSize)
        pStrings->SetSize(pStrings->m_usGrowBy + nIndex);
    pStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumUTilingKeys", m_uiNumUTilingKeys);
    nIndex = pStrings->m_usSize;
    if (nIndex >= pStrings->m_usMaxSize)
        pStrings->SetSize(pStrings->m_usGrowBy + nIndex);
    pStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumVOffsetKeys", m_uiNumVOffsetKeys);
    nIndex = pStrings->m_usSize;
    if (nIndex >= pStrings->m_usMaxSize)
        pStrings->SetSize(pStrings->m_usGrowBy + nIndex);
    pStrings->SetAt(nIndex, pString);

    pString = NiGetViewerString_00a7d510("m_uiNumVTilingKeys", m_uiNumVTilingKeys);
    nIndex = pStrings->m_usSize;
    if (nIndex >= pStrings->m_usMaxSize)
        pStrings->SetSize(pStrings->m_usGrowBy + nIndex);
    pStrings->SetAt(nIndex, pString);
}

extern bool(__cdecl* DAT_011f3ae0[])(void*, void*);


inline unsigned char* NiUVData::GetKeyPointerByIndex(unsigned char* pk, unsigned int i, unsigned char uc)
{
    return pk + i * uc;
}

// @fnv 0x00a45090
// src: XBOX_PDB 0x00a45090
bool NiUVData::IsEqual_00a45090(NiUVData* pkOther)
{
    if (!NiObject::IsEqual(pkOther))
        return false;

    if (m_uiNumUOffsetKeys != pkOther->m_uiNumUOffsetKeys || m_eUOffsetType != pkOther->m_eUOffsetType ||
        m_uiNumVOffsetKeys != pkOther->m_uiNumVOffsetKeys || m_eVOffsetType != pkOther->m_eVOffsetType ||
        m_uiNumUTilingKeys != pkOther->m_uiNumUTilingKeys || m_eUTilingType != pkOther->m_eUTilingType ||
        m_uiNumVTilingKeys != pkOther->m_uiNumVTilingKeys || m_eVTilingType != pkOther->m_eVTilingType ||
        m_ucUOffsetSize != pkOther->m_ucUOffsetSize || m_ucVOffsetSize != pkOther->m_ucVOffsetSize || m_ucUTilingSize != pkOther->m_ucUTilingSize ||
        m_ucVTilingSize != pkOther->m_ucVTilingSize)
        return false;

    unsigned int i;
    bool(__cdecl * pfnKeyEqual)(void*, void*);

    pfnKeyEqual = DAT_011f3ae0[m_eUOffsetType];
    for (i = 0; i < m_uiNumUOffsetKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pkUOffsetKeys, i, m_ucUOffsetSize),
                         GetKeyPointerByIndex(pkOther->m_pkUOffsetKeys, i, m_ucUOffsetSize)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_eVOffsetType];
    for (i = 0; i < m_uiNumVOffsetKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pkVOffsetKeys, i, m_ucVOffsetSize),
                         GetKeyPointerByIndex(pkOther->m_pkVOffsetKeys, i, m_ucVOffsetSize)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_eUTilingType];
    for (i = 0; i < m_uiNumUTilingKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pkUTilingKeys, i, m_ucUTilingSize),
                         GetKeyPointerByIndex(pkOther->m_pkUTilingKeys, i, m_ucUTilingSize)))
            return false;
    }

    pfnKeyEqual = DAT_011f3ae0[m_eVTilingType];
    for (i = 0; i < m_uiNumVTilingKeys; i++)
    {
        if (!pfnKeyEqual(GetKeyPointerByIndex(m_pkVTilingKeys, i, m_ucVTilingSize),
                         GetKeyPointerByIndex(pkOther->m_pkVTilingKeys, i, m_ucVTilingSize)))
            return false;
    }

    return true;
}


// Keep these transfer operations inline, as in the original stream views.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = m_pfnRead(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesRead;
    return bytesRead;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                                unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesWritten = m_pfnWrite(this, buffer, bytes, componentSizes, componentCount);
    m_uiAbsoluteCurrentPos += bytesWritten;
    return bytesWritten;
}


template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    return pkIstr->BinaryRead(pValue, uiNumEls * sizeof(T), &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& kStream, T& val)
{
    NiBinaryStreamLoad(kStream.m_pkIstr, &val, 1);
}

template <class T> inline void ReadStreamValue(NiStream& kStream, T& eValue)
{
    unsigned int uiValue;
    ReadBinaryValue(kStream, uiValue);
    eValue = (T)uiValue;
}

typedef NiUVKey*(__cdecl* NiUVKeyCreateFunction)(NiStream& kStream, unsigned int uiNumKeys);
typedef void(__cdecl* NiUVKeyFillFunction)(NiUVKey* pkKeys, unsigned int uiNumKeys, unsigned char ucSize);
extern unsigned char g_aucFloatKeySizes[];
extern NiUVKeyCreateFunction g_apfnFloatKeyCreate[];
extern NiUVKeyFillFunction g_apfnFloatKeyFill[];


// Loads the base object, then reads U/V offset and U/V tiling key blocks from the stream and replaces each key set.
// @fnv 0x00a453a0
// pdb: NiUVData::LoadBinary | NiUVData.obj | retail, upstream name already matches, high
// pdb params: kStream
// pdb locals: uiNumKeys, pfnDerived, eUOffsetType, pfnCreate, pkUOffsetKeys, pkVOffsetKeys, eVOffsetType, pkUTilingKeys, eUTilingType, pkVTilingKeys, eVTilingType
void NiUVData::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);

    unsigned int uiNumKeys;
    NiUVKeyType eType;

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucUOffsetSize = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucUOffsetSize);
        ReplaceUOffsetKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucVOffsetSize = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucVOffsetSize);
        ReplaceVOffsetKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucUTilingSize = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucUTilingSize);
        ReplaceUTilingKeys(pkKeys, uiNumKeys, eType);
    }

    ReadBinaryValue(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        ReadStreamValue(kStream, eType);
        m_ucVTilingSize = g_aucFloatKeySizes[eType];
        NiUVKeyCreateFunction pfnCreate = g_apfnFloatKeyCreate[eType];
        NiUVKey* pkKeys = pfnCreate(kStream, uiNumKeys);
        NiUVKeyFillFunction pfnFill = g_apfnFloatKeyFill[eType];
        pfnFill(pkKeys, uiNumKeys, m_ucVTilingSize);
        ReplaceVTilingKeys(pkKeys, uiNumKeys, eType);
    }
}

// NiUVData::SaveBinary writes the four UV key groups through the per-type float-key saver table.



template <class T> inline unsigned int WriteBinaryValue(NiBinaryStream& kBinstream, T& value)
{
    unsigned int uiSize = sizeof(T);
    return kBinstream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
template <class T> inline unsigned int WriteBinaryValue(NiStream& kStream, T& value)
{
    return WriteBinaryValue(*kStream.m_pkOstr, value);
}

extern void(__cdecl* DAT_011f3a50[])(NiStream& kStream, void* pkKeys, unsigned int uiNumKeys);


// Saves the base object, then writes each UV key count and any key array via the key-type saver table.
// @fnv 0x00a45610
// pdb: NiUVData::SaveBinary | NiUVData.obj | retail, upstream name already matches, high
// pdb params: kStream
// pdb locals: pfnSave
void NiUVData::SaveBinary(NiStream& kStream)
{
    NiObject::SaveBinary(kStream);
    WriteBinaryValue(kStream, m_uiNumUOffsetKeys);
    if (m_uiNumUOffsetKeys > 0)
    {
        WriteBinaryValue(kStream, m_eUOffsetType);
        DAT_011f3a50[m_eUOffsetType](kStream, m_pkUOffsetKeys, m_uiNumUOffsetKeys);
    }
    WriteBinaryValue(kStream, m_uiNumVOffsetKeys);
    if (m_uiNumVOffsetKeys > 0)
    {
        WriteBinaryValue(kStream, m_eVOffsetType);
        DAT_011f3a50[m_eVOffsetType](kStream, m_pkVOffsetKeys, m_uiNumVOffsetKeys);
    }
    WriteBinaryValue(kStream, m_uiNumUTilingKeys);
    if (m_uiNumUTilingKeys > 0)
    {
        WriteBinaryValue(kStream, m_eUTilingType);
        DAT_011f3a50[m_eUTilingType](kStream, m_pkUTilingKeys, m_uiNumUTilingKeys);
    }
    WriteBinaryValue(kStream, m_uiNumVTilingKeys);
    if (m_uiNumVTilingKeys > 0)
    {
        WriteBinaryValue(kStream, m_eVTilingType);
        DAT_011f3a50[m_eVTilingType](kStream, m_pkVTilingKeys, m_uiNumVTilingKeys);
    }
}
