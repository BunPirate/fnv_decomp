
// src/fallout_shared/havok/bgsacousticspacelistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/bgsacousticspacelistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/PlayerCharacter.h"
#include "../../../include/BGSAcousticSpaceListener.h"
#include "../../../include/RootContactPoint.h"

void __cdecl _Deallocate(void* ptr);

// Calls FUN_0061f5d0, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0061f5a0
// pdb: BGSAcousticSpaceListener::`scalar deleting destructor' | BGSAcousticSpaceListener.obj | retail, vtable slot, high
void* __thiscall BGSAcousticSpaceListener::Destroy(unsigned int flags)
{
    FUN_0061f5d0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Flt
{
    operator unsigned int() const;
};

// @fnv 0x0061f6c0
// src: XBOX_PDB 0x0061f6c0
// pdb: PlayerCharacter::QCameraRigidBody | BGSAcousticSpaceListener.obj | debug, upstream name already matches, high
unsigned int PlayerCharacter::QCameraRigidBody()
{
    return *reinterpret_cast<const Flt*>(reinterpret_cast<const char*>(this) + 0xDEC);
}

struct BGSAcousticSpace;
struct SoundPlaybackManager
{
    static void __cdecl ClearAcousticSpace(BGSAcousticSpace*);
};
// @fnv 0x0061f8e0
// src: COMMUNITY 0x0061f8e0
// pdb: BGSAcousticSpaceListener::DequeueAllRemovals | BGSAcousticSpaceListener.obj | retail, upstream name already matches, high
// pdb params: abDoRemoval
// pdb locals: iter, icount, pref
void BGSAcousticSpaceListener::DequeueAllRemovals(bool abDoRemoval)
{
    void* pos2 = RemovalQueueMap.GetFirstPos();
    while (pos2)
    {
        TESObjectREFR* key;
        int value2;
        RemovalQueueMap.GetNext(pos2, key, value2);
        SoundPlaybackManager::ClearAcousticSpace(key->GetAcousticSpace());
    }
    RemovalQueueMap.RemoveAll();
}

extern PlayerCharacter* _g_thePlayer;
struct W_0043b4f0
{
    unsigned int GetSourceFilesFromObject();
};
TESObjectREFR* __cdecl TESHavokUtilities_FindCollidableRef(void*);
// @fnv 0x0061f7b0
// pdb: BGSAcousticSpaceListener::contactPointRemovedCallback | BGSAcousticSpaceListener.obj | retail, vtable slot, high
// pdb params: CPoint
// pdb locals: pAcousticSpaceLeft, apTestRef
bool BGSAcousticSpaceListener::CheckAcousticSpaceListener(RootContactPoint* CPoint)
{
    TESObjectREFR* apTestRef = 0;
    if (_g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        if (CPoint->m_pRootCollidableB ==
            reinterpret_cast<void*>(reinterpret_cast<W_0043b4f0*>(_g_thePlayer->QCameraRigidBody())
                ->GetSourceFilesFromObject()))
            apTestRef = TESHavokUtilities_FindCollidableRef((void*)CPoint->m_pRootCollidableA);
    }
    else
    {
        TESObjectREFR* pAcousticSpaceLeft = TESHavokUtilities_FindCollidableRef((void*)CPoint->m_pRootCollidableB);
        if (pAcousticSpaceLeft == reinterpret_cast<TESObjectREFR*>(_g_thePlayer))
            apTestRef = TESHavokUtilities_FindCollidableRef((void*)CPoint->m_pRootCollidableA);
    }
    if (apTestRef)
    {
        if (bBufferRemovalOperations)
            SetCopyMapEntry(apTestRef);
        else
            SoundPlaybackManager::ClearAcousticSpace(apTestRef->GetAcousticSpace());
    }
    return false;
}

// @fnv 0x0061f940
// pdb: BGSAcousticSpaceListener::Update | BGSAcousticSpaceListener.obj | retail, vtable slot, high
// pdb params: afTime
// pdb locals: iter, bloop, icount, pref
void BGSAcousticSpaceListener::UpdateAcousticSpaceRefCounts(float afTime)
{
    void* iter = RemovalQueueMap.GetFirstPos();
    while (iter)
    {
        int icount;
        TESObjectREFR* key;
        RemovalQueueMap.GetNext(iter, key, icount);
        RemovalQueueMap.SetAt(key, --icount);
    }
    bool bloop = true;
    while (bloop)
    {
        bloop = false;
        void* iter2 = RemovalQueueMap.GetFirstPos();
        while (iter2)
        {
            int icount;
            TESObjectREFR* key;
            RemovalQueueMap.GetNext(iter2, key, icount);
            if (icount == 0)
            {
                RemovalQueueMap.RemoveAt(key);
                SoundPlaybackManager::ClearAcousticSpace(key->GetAcousticSpace());
                bloop = true;
                break;
            }
        }
    }
}

struct TgtOps
{
    void* GetSourceFiles();
};
// @fnv 0x0061f630
// pdb: BGSAcousticSpaceListener::entityRemovedCallback | BGSAcousticSpaceListener.obj | retail, vtable slot, high
// pdb params: apEntity
// pdb locals: apTestRef
void BGSAcousticSpaceListener::CheckPlayerReference(TESObjectREFR* apEntity)
{
    if (!_g_thePlayer)
        return;
    if (_g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        if (((TgtOps*)apEntity)->GetSourceFiles() ==
            (void*)((W_0043b4f0*)(_g_thePlayer->QCameraRigidBody()))->GetSourceFilesFromObject())
            SoundPlaybackManager::ClearAcousticSpace(0);
    }
    else
    {
        TESObjectREFR* apTestRef = TESHavokUtilities_FindCollidableRef(((TgtOps*)apEntity)->GetSourceFiles());
        if (apTestRef == (TESObjectREFR*)_g_thePlayer)
            SoundPlaybackManager::ClearAcousticSpace(0);
    }
}

struct FUN_0082eae0_shell
{
    static void __cdecl SetAcousticSpace(BGSAcousticSpace*);
};

struct FNV_GetObjectReference_shell
{
    BGSAcousticSpace* __thiscall _FNV_GetObjectReference();
};

// @fnv 0x0061f6e0
// pdb: BGSAcousticSpaceListener::contactPointAddedCallback | BGSAcousticSpaceListener.obj | retail, vtable slot, high
// pdb params: CPoint
// pdb locals: pAcousticSpaceEntered, apTestRef
bool __thiscall BGSAcousticSpaceListener::CheckAcousticSpaceEntered(RootContactPoint* CPoint)
{
    TESObjectREFR* pAcousticSpaceRef = 0;

    if (_g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        if (CPoint->m_pRootCollidableB == reinterpret_cast<void*>(reinterpret_cast<W_0043b4f0*>(_g_thePlayer->QCameraRigidBody())->GetSourceFilesFromObject()))
        {
            pAcousticSpaceRef = TESHavokUtilities_FindCollidableRef((void*)CPoint->m_pRootCollidableA);
        }
    }
    else
    {
        TESObjectREFR* apTestRef = TESHavokUtilities_FindCollidableRef((void*)CPoint->m_pRootCollidableB);
        if (apTestRef == reinterpret_cast<TESObjectREFR*>(_g_thePlayer))
        {
            pAcousticSpaceRef = TESHavokUtilities_FindCollidableRef((void*)CPoint->m_pRootCollidableA);
        }
    }

    if (pAcousticSpaceRef)
    {
        if (!bBufferRemovalOperations || !BGSAcousticSpaceListener_DequeueRemoval(pAcousticSpaceRef, false))
        {
            FUN_0082eae0_shell::SetAcousticSpace(
                reinterpret_cast<FNV_GetObjectReference_shell*>(pAcousticSpaceRef)->_FNV_GetObjectReference());
        }
        return true;
    }

    return false;
}

// Destructor of the class; the body is empty, so the compiler-generated member destructors run.
// @fnv 0x0061f5d0
// pdb: BGSAcousticSpaceListener::~BGSAcousticSpaceListener | BGSAcousticSpaceListener.obj | retail, upstream name already matches, high
BGSAcousticSpaceListener::~BGSAcousticSpaceListener()
{}

struct S_00620260_A
{
    virtual void vfn_00();
};
struct S_00620260_B
{
    void FUN_006ecd40(S_00620260_B* other);
};
struct S_00620260_T : S_00620260_A, S_00620260_B
{
    S_00620260_T* FindDerivedByKey(int b);
};
struct S_00620260_C
{
    virtual void vfn_00();
    virtual S_00620260_T* vfn_04(int a, int b);
    S_00620260_T* cur;
    S_00620260_T* BGSZoneTargetListener_AddZone(int apZone, int apCol);
};
// @fnv 0x00620260
// src: COMMUNITY 0x00620260
// pdb: BGSZoneTargetListener::AddZone | BGSZoneTargetListener.obj | retail, upstream name already matches, high
// pdb params: apZone, apCol
// pdb locals: pt
S_00620260_T* S_00620260_C::BGSZoneTargetListener_AddZone(int apZone, int apCol)
{
    S_00620260_T* r = cur ? cur->FindDerivedByKey(apCol) : 0;
    if (!r)
    {
        r = vfn_04(apZone, apCol);
        r->FUN_006ecd40(cur);
        cur = r;
    }
    return r;
}
