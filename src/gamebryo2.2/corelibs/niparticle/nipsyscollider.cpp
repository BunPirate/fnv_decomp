#include "../../../../include/NiTStringPointerMap.h"
// gamebryo2.2/corelibs/niparticle/nipsyscollider.cpp: NiPSysCollider (12 functions)

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiPointer.h"
#include "../../../../include/NiPSysColliderManager.h"
#include "../../../../include/NiPSysData.h"
#include "../../../../include/NiPSysSpawnModifier.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiPSysCollider.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTStringPointerMap.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

// The shared stream declaration keeps its callbacks and byte counter opaque.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                              unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
        this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}

inline unsigned int NiBinaryStream::BinaryWrite(const void* buffer, unsigned int bytes,
                                               unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(
        this, buffer, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}

class ShaderBufferRecord;
#pragma pack(push, 4)
class CloningProcess
{
  public:
    NiTPointerMap<NiObject*, NiObject*>* m_pCloneMap;
    NiTPointerMap<NiObject*, bool>* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    inline bool GetClone(NiObject* original, NiObject*& clone)
    {
        // The PC linker folds this pointer-map lookup with the canonical
        // string-pointer-map lookup; preserve its bound external symbol.
        return reinterpret_cast<NiTStringPointerMap<ShaderBufferRecord*>*>(m_pCloneMap)
            ->GetAt(reinterpret_cast<const char*>(original), reinterpret_cast<ShaderBufferRecord*&>(clone));
    }
};
#pragma pack(pop)

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream.BinaryRead(value, sizeof(T) * count, &size, 1);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    // The approved NiStream keeps its backing storage opaque.
    NiBinaryStream* input = *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(&stream) + 0x24C);
    NiBinaryStreamLoad(*input, &value, 1);
}

// @fnv 0x00C32840
// pdb: NiPSysCollider::LoadBinary | NiPSysCollider.obj | retail, upstream name already matches, high
// pdb params: kStream
// pdb locals: bDieOnCollide, bSpawnOnCollide
void NiPSysCollider::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_fBounce);
    char spawn;
    char die;
    ReadBinaryValue(kStream, spawn);
    m_bSpawnOnCollide = (spawn != 0);
    ReadBinaryValue(kStream, die);
    m_bDieOnCollide = (die != 0);
    kStream.ResetStreamState();
    kStream.ResetStreamState();
    kStream.ResetStreamState();
}

// @fnv 0x00C32580
// pdb: NiPSysCollider::ProcessClone | NiPSysCollider.obj | retail, upstream name already matches, high
// pdb params: kCloning
// pdb locals: bCloned, pkClone, pkDest
void NiPSysCollider::ProcessClone(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    NiObject* clone = 0;
    kCloning.GetClone(this, clone);
    NiPSysCollider* collider = static_cast<NiPSysCollider*>(clone);
    if (m_pkSpawnModifier)
    {
        if (kCloning.GetClone(reinterpret_cast<NiObject*>(m_pkSpawnModifier), clone))
            collider->m_pkSpawnModifier = reinterpret_cast<NiPSysSpawnModifier*>(clone);
        else
            collider->m_pkSpawnModifier = m_pkSpawnModifier;
    }
    if (m_pkManager)
    {
        if (kCloning.GetClone(reinterpret_cast<NiObject*>(m_pkManager), clone))
            collider->m_pkManager = reinterpret_cast<NiPSysColliderManager*>(clone);
        else
            collider->m_pkManager = m_pkManager;
    }
    NiPSysCollider* next = m_spNext.m_pObject;
    if (next)
        next->ProcessClone(kCloning);
}

// @fnv 0x00C32610
// pdb: NiPSysCollider::LinkObject | NiPSysCollider.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiPSysCollider::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    m_pkSpawnModifier = reinterpret_cast<NiPSysSpawnModifier*>(kStream.GetLoadedObject());
    m_pkManager = reinterpret_cast<NiPSysColliderManager*>(kStream.GetLoadedObject());
    NiPSysCollider* next = static_cast<NiPSysCollider*>(kStream.GetLoadedObject());
    NiPSysCollider* old = m_spNext.m_pObject;
    if (old != next)
    {
        if (old && InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount)) == 0)
            old->DeleteThis();
        m_spNext.m_pObject = next;
        if (next)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&next->m_uiRefCount));
    }
}

extern const char* const g_012026a0_arg1;
// @fnv 0x00c327e0
const NiRTTI* __fastcall GetColliderRTTI(const NiPSysCollider*, void*)
{
    return reinterpret_cast<const NiRTTI*>(&g_012026a0_arg1);
}

void __stdcall AppendCameraPathEntries(StrArr* pStrings);
char* __cdecl _FUN_00a7d330(char const* value);
char* __cdecl _FUN_00a7d370(char const* pcPrefix, bool bValue);
char* __cdecl NiGetViewerString_00a7d550(char const* value, float number);
char* __cdecl NiGetViewerString_00a7d5a0(char const* pcPrefix, void* pvValue);
char* __cdecl NiGetViewerString_00a7d5e0(char const* pcPrefix, char const* pcValue);

extern const char g_011d1f8c_arg1[];

// @fnv 0x00c329c0
// pdb: NiPSysCollider::GetViewerStrings | NiPSysCollider.obj | retail, string-set bridge, high
// pdb params: pkStrings
// pdb locals: pcSpawnModifier
void NiPSysCollider::GetViewerStrings(NiViewerStringsArray* pkStrings)
{
    StrArr* arr = reinterpret_cast<StrArr*>(pkStrings);
    char* value;
    unsigned int index;
    unsigned int capacity;
    NiPSysCollider* target;

    AppendCameraPathEntries(arr);

    value = _FUN_00a7d330(g_012026a0_arg1);
    index = arr->m_usSize;
    capacity = arr->m_usMaxSize;
    if (index >= capacity)
        arr->SetSize(arr->m_usGrowBy + index);
    arr->SetAt(index, value);

    value = NiGetViewerString_00a7d550("Bounce", m_fBounce);
    index = arr->m_usSize;
    capacity = arr->m_usMaxSize;
    if (index >= capacity)
        arr->SetSize(arr->m_usGrowBy + index);
    arr->SetAt(index, value);

    value = _FUN_00a7d370("Spawn on Collide", m_bSpawnOnCollide);
    index = arr->m_usSize;
    capacity = arr->m_usMaxSize;
    if (index >= capacity)
        arr->SetSize(arr->m_usGrowBy + index);
    arr->SetAt(index, value);

    value = _FUN_00a7d370("Die on Collide", m_bDieOnCollide);
    index = arr->m_usSize;
    capacity = arr->m_usMaxSize;
    if (index >= capacity)
        arr->SetSize(arr->m_usGrowBy + index);
    arr->SetAt(index, value);

    {
        const char* name = m_pkSpawnModifier ? m_pkSpawnModifier->m_kName.m_kHandle : g_011d1f8c_arg1;
        value = NiGetViewerString_00a7d5e0("Spawn Modifier", name);
    }
    index = arr->m_usSize;
    capacity = arr->m_usMaxSize;
    if (index >= capacity)
        arr->SetSize(arr->m_usGrowBy + index);
    arr->SetAt(index, value);

    value = NiGetViewerString_00a7d5a0("Manager", m_pkManager);
    index = arr->m_usSize;
    capacity = arr->m_usMaxSize;
    if (index >= capacity)
        arr->SetSize(arr->m_usGrowBy + index);
    arr->SetAt(index, value);

    target = m_spNext.m_pObject;
    if (target)
        target->GetViewerStrings(reinterpret_cast<NiViewerStringsArray*>(arr));
}

// Forward the collision query to the next collider, if any.
// @fnv 0x00c32450
// pdb: NiPSysCollider::Resolve | NiPSysCollider.obj | retail, object-file run extension, low
// pdb note: debug build links it to NiPSysFieldModifier::`scalar deleting destructor'
// pdb params: fInitialTime, fCollisionTime, pkData, usCurParticle
// pdb locals: pkResult
NiPSysCollider* NiPSysCollider::vf35(float time, float& collisionTime, NiPSysData* data, unsigned short index)
{
    NiPSysCollider* target = m_spNext.m_pObject;

    if (target)
    {
        NiPSysCollider* result = target->vf35(time, collisionTime, data, index);

        if (result)
            return result;
    }

    return 0;
}

// Writes a vertex position for the particle at uiIndex, runs the spawn modifier when both pointers are set, and calls the data update if a flag is set.
// @fnv 0x00c32490
// pdb: NiPSysCollider::Update | NiPSysCollider.obj | retail, object-file run extension, low
// pdb params: fTime, pkData, usCurParticle
void NiPSysCollider::vf36(float fTime, NiPSysData* pkData, unsigned int uiIndex)
{
    pkData->m_pkVertex[(unsigned short)uiIndex] = m_kCollisionPoint;

    if (m_bSpawnOnCollide && m_pkSpawnModifier)
    {
        m_pkSpawnModifier->SpawnChildParticles(fTime, m_fCollisionTime, uiIndex, reinterpret_cast<NiPSysData*>(m_pkManager->m_pkTarget));
    }

    if (m_bDieOnCollide)
    {
        pkData->vf41((unsigned short)uiIndex);
    }
}

// The shared collider lacks a RegisterStreamables override declaration. This
// entry uses its real layout; the unused register preserves the member-call ABI.
// @fnv 0x00c32680
// pdb: NiPSysCollider::RegisterStreamables | NiPSysCollider.obj | retail, object-file gap fill, low
// pdb params: kStream
bool __fastcall RegisterColliderStreamables(NiPSysCollider* collider, void*, NiStream& stream)
{
    if (!collider->NiObject::RegisterStreamables(stream))
    {
        return false;
    }
    NiPSysCollider* pNext = collider->m_spNext.m_pObject;
    if (pNext)
    {
        pNext->RegisterStreamables(stream);
    }
    return true;
}

// NiPSysCollider's IsEqual override is not declared in the shared header.
// @fnv 0x00c326b0
// pdb: NiPSysCollider::IsEqual | NiPSysCollider.obj | retail, object-file gap fill, low
// pdb params: pkObject
// pdb locals: pkDest
bool __fastcall IsColliderEqual(const NiPSysCollider* collider, void*, NiObject* pkObject)
{
    if (!collider->NiObject::IsEqual(pkObject))
        return false;

    NiPSysCollider* pkOther = static_cast<NiPSysCollider*>(pkObject);

    if (collider->m_fBounce != pkOther->m_fBounce)
        return false;

    if (collider->m_bSpawnOnCollide != pkOther->m_bSpawnOnCollide || collider->m_bDieOnCollide != pkOther->m_bDieOnCollide)
        return false;

    if ((collider->m_pkSpawnModifier && !pkOther->m_pkSpawnModifier) || (!collider->m_pkSpawnModifier && pkOther->m_pkSpawnModifier))
        return false;

    if (collider->m_pkSpawnModifier && pkOther->m_pkSpawnModifier && !collider->m_pkSpawnModifier->IsEqual(pkOther->m_pkSpawnModifier))
        return false;

    if ((collider->m_pkManager && !pkOther->m_pkManager) || (!collider->m_pkManager && pkOther->m_pkManager))
        return false;

    if ((collider->m_spNext.m_pObject && !pkOther->m_spNext.m_pObject) || (!collider->m_spNext.m_pObject && pkOther->m_spNext.m_pObject))
        return false;

    NiPSysCollider* pkThird = collider->m_spNext.m_pObject;
    if (pkThird && pkOther->m_spNext.m_pObject && !pkThird->IsEqual(pkOther->m_spNext.m_pObject))
        return false;

    return true;
}

// Deleting-destructor entry using the shared collider layout.
// @fnv 0x00c327f0
// pdb: NiPSysCollider::`scalar deleting destructor' | NiPSysCollider.obj | retail, object-file run extension, low
NiPSysCollider* __fastcall DeleteCollider(NiPSysCollider* collider, void*, unsigned char flags)
{
    NiPSysCollider* next = *reinterpret_cast<NiPSysCollider* volatile*>(&collider->m_spNext.m_pObject);
    if (next)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&next->m_uiRefCount)) == 0)
            next->DeleteThis();
    }
    collider->NiObject::~NiObject();
    if (flags & 1)
        NiMemObject::operator delete(collider, sizeof(NiPSysCollider));
    return collider;
}

template <class T>
inline void NiBinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void SaveBinaryValue(NiStream& kStream, const T& value)
{
    NiBinaryStreamSave(*kStream.m_pkOstr, &value);
}

// NiPSysCollider's SaveBinary override is not declared in the shared header.
// Save the bounce factor, collision flags and three object links.
// @fnv 0x00c32900
// pdb: NiPSysCollider::SaveBinary | NiPSysCollider.obj | retail, object-file gap fill, high
// pdb params: kStream
void __fastcall SaveColliderBinary(NiPSysCollider* collider, void*, NiStream& kStream)
{
    collider->NiObject::SaveBinary(kStream);
    SaveBinaryValue(kStream, collider->m_fBounce);
    SaveBinaryValue(kStream, (unsigned char)collider->m_bSpawnOnCollide);
    SaveBinaryValue(kStream, (unsigned char)collider->m_bDieOnCollide);
    kStream.SaveLinkID(collider->m_pkSpawnModifier);
    kStream.SaveLinkID(collider->m_pkManager);
    kStream.SaveLinkID(collider->m_spNext.m_pObject);
}

// The shared headers do not declare NiPSysCollider's parameterized constructor.
// Retain only that constructor's layout until its declaration is available.
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0)
{}

class ColliderConstruction : public NiObject
{
  public:
    float m_fBounceFactor;
    bool m_bSpawnOnCollision;
    bool m_bDieOnCollision;
    NiPSysSpawnModifier* m_pSpawnModifier;
    NiPoint3 m_kCollisionPosition;
    float m_fSpawnRate;
    NiPSysColliderManager* m_pColliderManager;
    NiPointer<NiPSysCollider> m_spNextController;

    ColliderConstruction(float bounce, bool spawn, bool die, NiPSysSpawnModifier* spawnMod);
};

// @fnv 0x00c32780
// pdb: NiPSysCollider::NiPSysCollider | NiPSysCollider.obj | retail, call graph (shared callers), low
// pdb params: fBounce, bSpawnOnCollide, bDieOnCollide, pkSpawnModifier
ColliderConstruction::ColliderConstruction(float bounce, bool spawn, bool die, NiPSysSpawnModifier* spawnMod)
    : m_fBounceFactor(bounce), m_bSpawnOnCollision(spawn), m_bDieOnCollision(die), m_pSpawnModifier(spawnMod),
      m_kCollisionPosition(NiPoint3::ZERO), m_fSpawnRate(0.0f), m_pColliderManager(0)
{}
