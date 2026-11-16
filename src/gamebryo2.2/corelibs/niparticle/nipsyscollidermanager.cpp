// src/gamebryo2.2/corelibs/niparticle/nipsyscollidermanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsyscollidermanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiObject.h"
#include "../../../../include/NiPSysCollider.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiPSysPositionModifier.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiPSysColliderManager.h"
#include "../../../../include/NiPSysData.h"

extern "C" void* NiPSysColliderManager_ms_RTTI; // src: XBOX_RETAIL_PDB 0x01202780 (old: g_01202780)
extern int DAT_010c008c;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
void __cdecl _delete(void*, unsigned int);
char* __cdecl _FUN_00a7d330(void*);

struct Owner
{
    char _p[0xd4];
    float m_fPoint3Value;
};
// One 0x1c-byte NiPSysData::m_pkParticleInfo element (Point3ParameterData is only forward-declared).
struct Item
{
    float f[7];
};

// The shared manager lacks the collider member and the Update, MakeClone and
// IsEqual declarations needed by this unit, so retain its definition here.

// NiPSysModifier.h does not declare the StrArr viewer-string overload.
// This declaration provides that call without duplicating the modifier layout.
struct ModifierViewerStrings : NiPSysModifier
{
    void GetViewerStrings(StrArr*);
};

// @fnv 0x00c2d540
// src: COMMUNITY 0x00c2d540
void* __cdecl NiPSysColliderManager_GetRTTI()
{
    return &NiPSysColliderManager_ms_RTTI;
}

// @fnv 0x00c2d5b0
// src: EXE 0x00c2d5b0
// pdb: NiPSysColliderManager::CreateObject | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb locals: pkObject
NiPSysColliderManager* __cdecl NiPSysColliderManager_CreateObject()
{
    NiPSysColliderManager* p = static_cast<NiPSysColliderManager*>(NiPSysPositionModifier::operator new(0x1c));
    if (p)
    {
        reinterpret_cast<NiPSysPositionModifier*>(p)->NiPSysPositionModifier::NiPSysPositionModifier();
        *(int**)p = &DAT_010c008c;
        p->m_spColliders = 0;
        return p;
    }
    return 0;
}

// @fnv 0x00c2d3b0
void NiPSysColliderManager::CloneCollider(NiPSysColliderManager* pkDest, CloningProcess& kCloning)
{
    NiPSysModifier::CopyMembers(pkDest, kCloning);
    NiPSysCollider* pkSrc = m_spColliders;
    if (pkSrc)
    {
        NiPSysCollider* pkClone = static_cast<NiPSysCollider*>(pkSrc->MakeClone(kCloning));
        NiPSysCollider* pkOld = pkDest->m_spColliders;
        if (pkOld != pkClone)
        {
            if (pkOld && InterlockedDecrement(reinterpret_cast<long volatile*>(&pkOld->m_uiRefCount)) == 0)
                pkOld->DeleteThis();
            pkDest->m_spColliders = pkClone;
            if (pkClone)
                InterlockedIncrement(reinterpret_cast<long volatile*>(&pkClone->m_uiRefCount));
        }
    }
}

// @fnv 0x00c2d410
// pdb: NiPSysColliderManager::ProcessClone | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: kCloning
void NiPSysColliderManager::ProcessClone(CloningProcess& kCloning)
{
    NiPSysModifier::ProcessClone(kCloning);
    NiPSysCollider* pkColliders = m_spColliders;
    if (pkColliders)
        pkColliders->ProcessClone(kCloning);
}

// @fnv 0x00c2d440
// pdb: NiPSysColliderManager::LinkObject | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiPSysColliderManager::LinkObject(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
    NiObject* pNewObject = kStream.GetLoadedObject();
    NiObject* pOldObject = m_spColliders;
    if (pOldObject != pNewObject)
    {
        if (pOldObject)
        {
            if (InterlockedDecrement(reinterpret_cast<long volatile*>(&pOldObject->m_uiRefCount)) == 0)
                pOldObject->DeleteThis();
        }
        m_spColliders = static_cast<NiPSysCollider*>(pNewObject);
        if (pNewObject)
            InterlockedIncrement(reinterpret_cast<long volatile*>(&pNewObject->m_uiRefCount));
    }
}

// @fnv 0x00c2d4a0
// pdb: NiPSysColliderManager::RegisterStreamables | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: kStream
bool NiPSysColliderManager::RegisterStreamables(NiStream& kStream)
{
    if (!NiPSysModifier::RegisterStreamables(kStream))
        return false;
    NiPSysCollider* pkColliders = m_spColliders;
    if (pkColliders)
        pkColliders->RegisterStreamables(kStream);
    return true;
}

// @fnv 0x00c2d4d0
// pdb: NiPSysColliderManager::SaveBinary | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: kStream
void NiPSysColliderManager::SaveBinary(NiStream& kStream)
{
    NiPSysModifier::FUN_00c31950(kStream);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spColliders));
}

// @fnv 0x00c2d5e0
// pdb: NiPSysColliderManager::`scalar deleting destructor' | NiPSysColliderManager.obj | retail, object-file gap fill, high
void* NiPSysColliderManager::ReleaseCollider(unsigned int flag)
{
    NiPSysCollider* p = m_spColliders;
    if (p != 0)
    {
        if (InterlockedDecrement(reinterpret_cast<long volatile*>(&p->m_uiRefCount)) == 0)
            p->DeleteThis();
    }
    reinterpret_cast<NiPSysPositionModifier*>(this)->NiPSysPositionModifier::~NiPSysPositionModifier();
    if (flag & 1)
        _delete(this, 0x1c);
    return this;
}

// @fnv 0x00c2d630
// pdb: NiPSysColliderManager::GetViewerStrings | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: pkStrings
void NiPSysColliderManager::GetViewerStrings(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(strings);
    static_cast<ModifierViewerStrings*>(static_cast<NiPSysModifier*>(this))->GetViewerStrings(pkStrings);
    char* pcString = _FUN_00a7d330(NiPSysColliderManager_ms_RTTI);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiSize, pcString);
    m_spColliders->GetViewerStrings(reinterpret_cast<NiViewerStringsArray*>(pkStrings));
}

// @fnv 0x00c2d300
// pdb: NiPSysColliderManager::Update | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: fTime, pkData
// pdb locals: us, fTimeStepStart, fCollisionTime, pkFirstCollider
// vftable 0x010c008c slot 35: the virtual Update(float, NiPSysData*).
void NiPSysColliderManager::Update(float fTime, NiPSysData* pkData)
{
    NiPSysCollider* pCtl = m_spColliders;
    if (pCtl && pkData->m_usActive > 0)
        pCtl->vf37();
    for (unsigned short usIndex = 0; usIndex < pkData->m_usActive; usIndex++)
    {
        float a = reinterpret_cast<Owner*>(m_pkTarget)->m_fPoint3Value;
        float fResult = fTime;
        pCtl = m_spColliders;
        NiPSysCollider* p = 0;
        if (pCtl)
            p = pCtl->vf35(a, fResult, pkData, usIndex);
        if (p)
        {
            // The shared vf36 takes an unsigned int, but this call passes the
            // original unsigned-short index without zero-extending its register.
            typedef void (__thiscall* ApplyParticle)(NiPSysCollider*, float, NiPSysData*, unsigned short);
            reinterpret_cast<ApplyParticle>((*reinterpret_cast<void***>(p))[36])(
                p, fTime, pkData, usIndex);
        }
        else
            fResult = a;
        reinterpret_cast<Item*>(pkData->m_pkParticleInfo)[usIndex].f[5] = fResult;
    }
}

// @fnv 0x00c2d550
// pdb: NiPSysColliderManager::CreateClone | NiPSysColliderManager.obj | retail, object-file run extension, low
// pdb params: kCloning
// pdb locals: pkObject
NiObject* NiPSysColliderManager::MakeClone(CloningProcess& cp)
{
    NiPSysColliderManager* pkNew = (NiPSysColliderManager*)NiPSysPositionModifier::operator new(0x1c);
    if (pkNew != 0)
    {
        reinterpret_cast<NiPSysPositionModifier*>(pkNew)->NiPSysPositionModifier::NiPSysPositionModifier();
        *(int**)pkNew = &DAT_010c008c;
    }
    else
    {
        pkNew = 0;
    }
    (pkNew != 0 ? (pkNew->m_spColliders = 0, this) : this)->CloneCollider(pkNew, cp);
    return pkNew;
}

// @fnv 0x00c2d4f0
// pdb: NiPSysColliderManager::IsEqual | NiPSysColliderManager.obj | retail, upstream name already matches, high
// pdb params: pkObject
// pdb locals: pkDest
bool NiPSysColliderManager::IsEqual(NiObject* pkObject) const
{
    if (!NiPSysModifier::IsEqual(pkObject))
        return false;

    NiPSysColliderManager* pOtherManager = (NiPSysColliderManager*)pkObject;
    if ((m_spColliders && !pOtherManager->m_spColliders) ||
        (!m_spColliders && pOtherManager->m_spColliders))
    {
        return false;
    }

    NiPSysCollider* pCollider = m_spColliders;
    if (pCollider && pOtherManager->m_spColliders)
    {
        if (!static_cast<const NiPSysCollider*>(pCollider)->IsEqual(pOtherManager->m_spColliders))
            return false;
    }

    return true;
}
