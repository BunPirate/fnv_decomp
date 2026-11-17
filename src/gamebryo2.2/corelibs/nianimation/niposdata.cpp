// gamebryo2.2/corelibs/nianimation/niposdata.cpp: NiPosData (10 functions)

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPosData.h"
#include "../../../../include/NiStream.h"
#include <windows.h>

extern unsigned char DAT_011f375e[];
extern void (*DAT_011f38b8[])(PositionKeyInterpolator*);
// The shared stream declaration does not yet name its transfer storage.
inline unsigned int NiBinaryStream::Read(void* data, unsigned int bytes)
{
    unsigned int size = 4;
    unsigned int transferred = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))
        (this, data, bytes, &size, 1);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += transferred;
    return transferred;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* data, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))
        (this, data, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

inline unsigned int NiBinaryStream::Write(const void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    return BinaryWrite(data, bytes, &size, 1);
}
// The shared stream stores its input/output pointers in the opaque layout.
inline NiBinaryStream& NiStream::Istr()
{
    return **reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x250);
}

inline unsigned int NiStream::ReadUnsignedInteger()
{
    unsigned int raw;
    Istr().Read(&raw, 4);
    return raw;
}
extern PositionKeyInterpolator* (*DAT_011f3dc8[])(NiStream&, unsigned int);
extern void (*DAT_011f3798[])(PositionKeyInterpolator*, unsigned int, unsigned char);
inline unsigned char GetPosKeySize(NiAnimationKey::KeyType type)
{
    return DAT_011f375e[type];
}
typedef PositionKeyInterpolator* (*CreatePosKeys)(NiStream&, unsigned int);
typedef void (*FillPosKeys)(PositionKeyInterpolator*, unsigned int, unsigned char);
inline CreatePosKeys GetCreatePosKeys(NiAnimationKey::KeyType type)
{
    return DAT_011f3dc8[type];
}
inline FillPosKeys GetFillPosKeys(NiAnimationKey::KeyType type)
{
    return DAT_011f3798[type];
}

struct FUN_0096ad30_param;

// Methods not yet declared by NiPosData; all storage comes from the shared class.
class NiPosDataOperations : public NiPosData
{
  public:
    void UpdateKeyRange(float, float);
    void DestroyPosData();
    void SetKeys(void*, unsigned int, int);
    bool Equals(const NiPosDataOperations*);
    void SaveToStream(NiStream&);
    void nullsub_3(NiStream&);
    void AppendCameraPathEntries(FUN_0096ad30_param*);
    void AddViewerEntries(FUN_0096ad30_param*);
    void FUN_00a5d510(NiPosDataOperations**);
    void NiPosData_GetSequenceData(float, float, NiPosDataOperations**);

    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

// @fnv 0x00a490e0
// src: XBOX_RETAIL_PDB 0x00a490e0
// pdb: NiPosData::ReplaceAnim | NiPosData.obj | retail, object-file gap fill, high
// pdb params: pkKeys, uiNumKeys, eType
// pdb locals: pfnDeleteFunc
void NiPosData::ReplaceAnim(PositionKeyInterpolator* pkKeys, unsigned int uiNumKeys, NiAnimationKey::KeyType eType)
{
    if (m_pkKeys)
        DAT_011f38b8[m_eType](m_pkKeys);
    if (pkKeys && uiNumKeys)
    {
        m_ucKeySize = GetPosKeySize(eType);
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

// @fnv 0x00a49240
// pdb: NiPosData::LoadBinary | NiPosData.obj | retail, upstream name already matches, high
// pdb params: stream
// pdb locals: uiNumKeys, pkPosKeys, ePosType, cf, derived
void NiPosData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int count;
    stream.Istr().Read(&count, 4);
    if (count > 0)
    {
        NiAnimationKey::KeyType type = (NiAnimationKey::KeyType)stream.ReadUnsignedInteger();
        m_ucKeySize = GetPosKeySize(type);
        PositionKeyInterpolator* keys = GetCreatePosKeys(type)(stream, count);
        GetFillPosKeys(type)(keys, count, m_ucKeySize);
        ReplaceAnim(keys, count, type);
    }
}

extern int DAT_0109717c;
struct BaseUnk
{
    void _Call_a5d3a0();
    void* vtable;
    int _04;
};
// @fnv 0x00a49020
// src: EXE 0x00a49020
// pdb: NiPosData::CreateObject | NiPosData.obj | retail, upstream name already matches, high
// pdb locals: pkObject
NiPosData* NiPosData_CreateObject()
{
    NiPosData* p = (NiPosData*)BSFadeNode::operator new(sizeof(NiPosData));
    if (p)
    {
        reinterpret_cast<BaseUnk*>(p)->_Call_a5d3a0();
        p->m_uiNumKeys = 0;
        p->m_pkKeys = 0;
        p->m_eType = NiAnimationKey::NOINTERP;
        p->m_ucKeySize = 0;
        *(void**)p = (void*)&DAT_0109717c;
        return p;
    }
    return 0;
}

void __cdecl NiAnimationKey_GuaranteeKeyAtStartAndEnd(int, int, void*, void*, float, float);
// Calls UpdateSlotStates with the key count and key pointer, then stores the updated key pointer back.
// @fnv 0x00a48f70
// pdb: NiQuaternionInterpolator::`scalar deleting destructor' | NiQuaternionInterpolator.obj | debug, object-file run extension, low
void NiPosDataOperations::UpdateKeyRange(float afArg1, float afArg2)
{
    void* pkKeys = m_pkKeys;
    NiAnimationKey_GuaranteeKeyAtStartAndEnd(1, m_eType, &pkKeys, &m_uiNumKeys, afArg1, afArg2);
    m_pkKeys = (PositionKeyInterpolator*)pkKeys;
}

// Restores the vtable, calls the stored callback on the pointer at _0C if set, then destroys the NiRefObject base.
// @fnv 0x00a48fb0
// pdb: NiQuaternionInterpolator::~NiQuaternionInterpolator | NiQuaternionInterpolator.obj | debug, object-file run extension, low
void NiPosDataOperations::DestroyPosData()
{
    PositionKeyInterpolator* p = m_pkKeys;
    *(int*)this = (int)&DAT_0109717c;
    if (p)
        DAT_011f38b8[m_eType](p);
    this->NiRefObject::~NiRefObject();
}

// Stores the key array, key count and type, setting a byte from DAT_011f375e indexed by type; clears all fields when keys or numKeys is null/zero.
// @fnv 0x00a48fe0
// pdb: NiPosData::~NiPosData | NiPosData.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiQuaternionInterpolator::SetQuaternionData
// pdb locals: pfnDeleteFunc
void NiPosDataOperations::SetKeys(void* keys, unsigned int numKeys, int type)
{
    if (keys && numKeys)
    {
        m_ucKeySize = DAT_011f375e[type];
        m_pkKeys = (PositionKeyInterpolator*)keys;
        m_uiNumKeys = numKeys;
        m_eType = (NiAnimationKey::KeyType)type;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pkKeys = 0;
        m_ucKeySize = 0;
        m_eType = NiAnimationKey::NOINTERP;
    }
}

typedef bool(__cdecl* KeyEqual)(const void*, const void*);
extern KeyEqual DAT_011f3af8[];

// @fnv 0x00a49060
// pdb: NiPosData::IsEqual | NiPosData.obj | retail, object-file gap fill, high
// pdb params: pkObject
// pdb locals: equal, pkData, uiI
bool NiPosDataOperations::Equals(const NiPosDataOperations* pkObject)
{
    if (!IsSameAs(const_cast<NiPosDataOperations*>(pkObject)))
        return false;

    if (m_uiNumKeys != pkObject->m_uiNumKeys || m_eType != pkObject->m_eType ||
        m_ucKeySize != pkObject->m_ucKeySize)
        return false;

    KeyEqual pfnEqualKeys = DAT_011f3af8[m_eType];
    for (unsigned int i = 0; i < m_uiNumKeys; ++i)
    {
        unsigned int offset = i * m_ucKeySize;
        const unsigned char* otherKey = (const unsigned char*)pkObject->m_pkKeys + offset;
        const unsigned char* currentKey = (const unsigned char*)m_pkKeys + offset;
        if (!pfnEqualKeys(currentKey, otherKey))
            return false;
    }
    return true;
}

typedef void (*SavePosKeys)(NiStream& kStream, void* pvData, unsigned int ItemUpdateArray);
extern SavePosKeys g_apfnSavePosKeys[];


// SaveBinary
// @fnv 0x00a49300
// pdb: NiPosData::SaveBinary | NiPosData.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiPoint3Interpolator::NiPoint3Interpolator
// pdb params: stream
// pdb locals: sf
void NiPosDataOperations::SaveToStream(NiStream& kStream)
{
    nullsub_3(kStream);
    kStream.GetBinaryStream()->Write((const void*)&m_uiNumKeys, 4);
    if (m_uiNumKeys > 0)
    {
        kStream.GetBinaryStream()->Write((const void*)&m_eType, 4);
        g_apfnSavePosKeys[m_eType](kStream, m_pkKeys, m_uiNumKeys);
    }
}

extern char str_01097164[];
extern int DAT_011f3f68;
extern int __cdecl NiViewerStrings_NiGetViewerString_Title(int);
extern int __cdecl NiGetViewerString_00a7d510(char*, int);

struct FUN_0096ad30_param
{
    void* vtable;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, unsigned int*);
};


// @fnv 0x00a49380
// pdb: NiPosData::GetViewerStrings | NiPosData.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiPoint3Interpolator::NiPoint3Interpolator
// pdb params: pStrings
void NiPosDataOperations::AddViewerEntries(FUN_0096ad30_param* param)
{
    unsigned int value;
    unsigned int index;

    AppendCameraPathEntries(param);
    value = NiViewerStrings_NiGetViewerString_Title(DAT_011f3f68);
    index = param->unk0A;
    if (index >= (unsigned int)param->unk08)
    {
        param->FUN_0096ad30((unsigned int)param->unk0E + index);
    }
    param->FUN_0096ae90(index, &value);
    value = NiGetViewerString_00a7d510(str_01097164, m_uiNumKeys);
    index = param->unk0A;
    if (index >= (unsigned int)param->unk08)
    {
        param->FUN_0096ad30((unsigned int)param->unk0E + index);
    }
    param->FUN_0096ae90(index, &value);
}


void NiAnimationKey_CopySequence(int, int, int, int, float, float, unsigned int*, unsigned int*);


// @fnv 0x00a49140
// src: XBOX_RETAIL_PDB 0x00a49140
// pdb: NiPosData::GetSequenceData | NiPosData.obj | retail, object-file gap fill, high
// pdb params: fStartTime, fEndTime, aspPosData
// pdb locals: spDeepCopy, spNewData, pkNewKeys, uiNewNumKeys
void NiPosDataOperations::NiPosData_GetSequenceData(float fStartTime, float fEndTime, NiPosDataOperations** aspPosData)
{
    NiPosDataOperations* tmp;
    unsigned int uiOut2;
    unsigned int uiOut1;
    tmp = 0;
    FUN_00a5d510(&tmp);
    NiPosDataOperations* p = tmp;
    if (p != 0)
    {
        p->IncRefCount();
    }
    if (m_uiNumKeys > 0)
    {
        uiOut1 = 0;
        uiOut2 = 0;
        NiAnimationKey_CopySequence(1, m_eType, (int)m_pkKeys, (int)m_uiNumKeys, fStartTime, fEndTime, &uiOut1, &uiOut2);
        p->ReplaceAnim((PositionKeyInterpolator*)uiOut1, uiOut2, m_eType);
    }
    NiPosDataOperations* old = *aspPosData;
    if (old != p)
    {
        if (old != 0)
        {
            old->DecRefCount();
        }
        *aspPosData = p;
        if (p != 0)
        {
            p->IncRefCount();
        }
    }
    if (p != 0)
    {
        p->DecRefCount();
    }
    if (tmp != 0)
    {
        tmp->DecRefCount();
    }
}
