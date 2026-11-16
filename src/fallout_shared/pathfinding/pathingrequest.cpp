// fallout_shared/pathfinding/pathingrequest.cpp: PathingRequest, PathingAvoidNodeArray, PathingRequestDebugView (24 functions)

#include "../../../include/PathingLocation.h"
// The unit type header also includes an older local PathingLocation header.
#define FNV_PATHINGLOCATION_H
#include "pathingrequest_types_PathingRequest.h"
#include "pathingrequest_types_TESPackage.h"
#include "TESObjectREFR.h"
#include "pathingrequest_decls.h"
#include "../../../include/BGSSaveGameBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"

// @fnv 0x006e38d0
// pdb: PathingRequest::InitLoadGame | PathingRequest.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
// pdb locals: pactor, ppack
void PathingRequest::InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (reinterpret_cast<BGSLoadFormBufferView*>(apLoadGameBuffer)->GetVersion() < 14)
    {
        bWaitIfPlayerWaits = false;
        Actor* actor = reinterpret_cast<BGSLoadFormBufferView*>(apLoadGameBuffer)->GetActor();
        if (actor)
        {
            TESPackage* package = reinterpret_cast<MobileObject*>(actor)->GetCurrentPackage();
            if (package &&
                reinterpret_cast<Calendar*>(package)->GetDaysPassed() ==
                    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ESCORT_ACTOR &&
                package->GetTargetForActor(actor, false) == reinterpret_cast<TESObjectREFR*>(g_thePlayer))
                bWaitIfPlayerWaits = true;
        }
    }
}

// Loads a PathingRequest from a BGSLoadFormBuffer, reading origin/destination, flags, and version-gated fields, then a count-driven array of avoid nodes.
// @fnv 0x006e34f0
// pdb: PathingRequest::LoadGame | PathingRequest.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
// pdb locals: isaveGameCount, i, avoidNode
void PathingRequest::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Origin.LoadGame(apLoadGameBuffer);
    Destination.LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fActorRadius), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fActorHeight), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fGoalZDelta), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fTargetRadius), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fCenterRadius), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fSmoothingRandomness), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fGoalAngle), 4u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bFaceTargetAtGoal), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bCantOpenDoors), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bDrawDebugGeometry), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bAllowIncompletePath), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bSoftGoalRadius), 1u);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bCanSwim), 1u);
    if (apLoadGameBuffer->GetVersion() >= 13)
    {
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bWaitIfPlayerWaits), 1u);
    }
    if (apLoadGameBuffer->GetVersion() >= 15)
    {
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fInitialPathHeading), 4u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bFirstTangentUsesHeading), 1u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bGoDirectIfPathingFails), 1u);
    }
    if (apLoadGameBuffer->GetVersion() >= 18)
    {
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&Center), 12u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bTryToUseCurvedPath), 1u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bIgnoreSmoothingIfFails), 1u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bIgnoreLocks), 1u);
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&iRetryCount), 4u);
    }
    if (apLoadGameBuffer->GetVersion() >= 20)
    {
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bCanFly), 1u);
    }
    if (apLoadGameBuffer->GetVersion() >= 21)
    {
        apLoadGameBuffer->ReadTypedData(static_cast<void*>(&bFailIfGoalOccupied), 1u);
    }
    unsigned int count = apLoadGameBuffer->ReadElementCount();
    if (count)
    {
        reinterpret_cast<PathingAvoidPointerView*>(&spAvoidNodeArray)->Assign(reinterpret_cast<PathingAvoidNodeArray*>(new PathingAvoidNodeArrayStorage));
        reinterpret_cast<PathingAvoidPointerView*>(&spAvoidNodeArray)->Get()->BSSimpleArray_PathingAvoidNode_1024_SetSize(count, true);
        for (unsigned int i = 0; i < count; ++i)
        {
            PathingAvoidNode* node =
                reinterpret_cast<PathingAvoidPointerView*>(&spAvoidNodeArray)->Get()->BSSimpleArray_PathingAvoidNode_1024_GetAt(i);
            node->LoadPathingAvoidNode(apLoadGameBuffer);
        }
    }
}

// Creates and returns a new pathing request object matching the given type, warning and returning null for unknown types.
// @fnv 0x006e2f80
// src: XBOX_DEBUG_PDB 0x006e2f80
// pdb: PathingRequest::CreatePathingRequest | PathingRequest.obj | debug, unique string literal, high
// pdb params: aeType
PathingRequest* PathingRequest::CreatePathingRequest(PATHING_REQUEST_TYPE aeType)
{
    switch (aeType)
    {
    case 0:
        return new PathingRequest;
    case 1:
        return new FUN_006e4080;
    case 2:
        return new PathingRequestClosePoint;
    case 3:
        return new PathingRequestFlee;
    case 4:
        return new PathingRequestHide;
    case 5:
        return new PathingRequestLOS;
    case 7:
        return new PathingRequestOptimalLocation;
    case 8:
        return new FUN_006e4a50;
    default:
        Warning("PATHFINDING: Unknown pathing request type %i", aeType);
        return 0;
    }
}

// Copies origin, destination, radii, smoothing and flag fields from this PathingRequest into the given request.
// @fnv 0x006e2750
// pdb: PathingRequest::CopyTo | PathingRequest.obj | retail, upstream name already matches, high
// pdb params: apDest
// pdb locals: center
void PathingRequest::CopyTo(PathingRequest* apDest)
{
    apDest->SetOrigin(GetOrigin());
    apDest->SetDestination(NiAVObject_GetRotate_006a9540());
    apDest->SetActorRadius(GetActorRadius());
    apDest->FUN_006d3ae0(GetFloatAtOffset68());
    apDest->SetActorLockData(GetActorLockData());
    apDest->SetCenterRadius(GetCenterRadius());
    NiPoint3 center = GetTargetPoint();
    apDest->PathingRequest_SetCenterRadius(center, GetTargetRadius());
    apDest->SetSmoothingRandomness(GetSmoothingRandomness());
    apDest->SetAvoidNodeArray(GetString());
    apDest->SetSmoothingRandomness(GetSmoothingRandomness());
    apDest->SetGoalZDelta(GetGoalZDelta());
    apDest->bCantOpenDoors = bCantOpenDoors;
    apDest->fGoalAngle = fGoalAngle;
    apDest->fInitialPathHeading = fInitialPathHeading;
    apDest->bFaceTargetAtGoal = bFaceTargetAtGoal;
    apDest->bAllowIncompletePath = bAllowIncompletePath;
    apDest->bSoftGoalRadius = bSoftGoalRadius;
    apDest->bCanSwim = bCanSwim;
    apDest->bCanFly = bCanFly;
    apDest->bWaitIfPlayerWaits = bWaitIfPlayerWaits;
    apDest->bFirstTangentUsesHeading = bFirstTangentUsesHeading;
    apDest->bGoDirectIfPathingFails = bGoDirectIfPathingFails;
    apDest->bTryToUseCurvedPath = bTryToUseCurvedPath;
    apDest->bIgnoreSmoothingIfFails = bIgnoreSmoothingIfFails;
    apDest->bIgnoreLocks = bIgnoreLocks;
    apDest->iRetryCount = iRetryCount;
    apDest->bFailIfGoalOccupied = bFailIfGoalOccupied;
}

// @fnv 0x006e2420
// pdb: PathingRequest::PathingRequest | PathingRequest.obj | retail, call graph, high
PathingRequest::PathingRequest() : spAvoidNodeArray(0)
{
    fActorRadius = runtimeFloatSettingDefault65;
    fActorHeight = 1.0f;
    fGoalZDelta = 180.0f;
    fTargetRadius = TESPackage::GetPackageDefaultFloat();
    fCenterRadius = 0.0f;
    static_cast<NiPoint3&>(Center) = pathingrequestZero;
    fGoalAngle = 0.0f;
    fInitialPathHeading = 0.0f;
    bCantOpenDoors = false;
    bFaceTargetAtGoal = false;
    bDrawDebugGeometry = false;
    bAllowIncompletePath = true;
    bSoftGoalRadius = true;
    bCanSwim = true;
    bCanFly = false;
    bWaitIfPlayerWaits = false;
    bFirstTangentUsesHeading = false;
    bGoDirectIfPathingFails = false;
    bTryToUseCurvedPath = false;
    bIgnoreSmoothingIfFails = false;
    bIgnoreLocks = false;
    iRetryCount = 3;
    bFailIfGoalOccupied = false;
    fSmoothingRandomness = 0.0f;
}

// Calls Destruct on this, frees the object with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e3880
// pdb: PathingAvoidNodeArray::`scalar deleting destructor' | PathingRequest.obj | debug, vtable slot, medium
PathingAvoidNodeArrayStorage* PathingAvoidNodeArrayStorage::Destroy(unsigned int flags)
{
    reinterpret_cast<PathingAvoidNodeArrayDestructionView*>(this)->Destruct();
    if (flags & 1)
        PathingAvoidNodeArrayStorage::operator delete(this, 24);
    return this;
}
// @fnv 0x006e3850
// pdb: PathingAvoidNodeArray::PathingAvoidNodeArray | PathingRequest.obj | debug, call graph, medium
PathingAvoidNodeArrayStorage::PathingAvoidNodeArrayStorage()
{
    FUN_006e3960();
    *reinterpret_cast<void**>(data) = &DAT_0106d1e4;
    *reinterpret_cast<void**>(data + 16) = &DAT_0106d1d8;
}
// @fnv 0x006e38b0
// pdb: PathingAvoidNodeArray::~PathingAvoidNodeArray | PathingRequest.obj | debug, call graph, medium
PathingAvoidNodeArrayStorage::~PathingAvoidNodeArrayStorage()
{
    FUN_006e39d0();
}

void __cdecl Deallocate(void*);

struct FUN_006db090_shell
{
    void FreeBuffer(void* apBuffer);
};

// @fnv 0x006db090
// pdb: BSPackedAdditionalGeometryData::NiBSPackedAGDDataBlock::FreeBuffer | BSPackedAdditionalGeometryData.obj | retail, upstream name already matches, high; a name-only link, and the class here differs from the PDB class, so its parameter names are not applied
// pdb params (unverified, name-only link): pvBuffer
// pdb locals (unverified, name-only link): patt, att
void FUN_006db090_shell::FreeBuffer(void* apBuffer)
{
    Deallocate(apBuffer);
}

void __fastcall FUN_006e2620(void*);
void __cdecl FUN_00aa1460(void*, unsigned int);

struct FUN_006e25e0_impl
{
    void* FUN_006e25e0(unsigned int flags);
};

// Calls FUN_006e2620 on this, then if bit 0 of flags is set calls FUN_00aa1460 with size 0xb0, and returns this.
// @fnv 0x006e25e0
// pdb: PathingRequest::`scalar deleting destructor' | PathingRequest.obj | debug, vtable slot, medium
void* FUN_006e25e0_impl::FUN_006e25e0(unsigned int flags)
{
    FUN_006e2620(this);
    if (flags & 1)
        FUN_00aa1460(this, 0xb0);
    return this;
}

struct FUN_006e2980_shell : public PathingRequest
{
    void PathingRequest_SetCenterRadius(NiPoint3*, float);
};

// Stores arCenter at offset 0x7c and afOriginRadius at offset 0x78 of this object.
// @fnv 0x006e2980
// src: XBOX_PDB 0x006e2980
void FUN_006e2980_shell::PathingRequest_SetCenterRadius(NiPoint3* apCenter, float afOriginRadius)
{
    *(NiPoint3*)((char*)this + 0x7c) = *apCenter;
    *(float*)((char*)this + 0x78) = afOriginRadius;
}

struct FUN_006e2b50_shell : public PathingRequest
{
    void SetCantOpenDoors(bool);
};

// @fnv 0x006e2b50
void FUN_006e2b50_shell::SetCantOpenDoors(bool abCantOpenDoors)
{
    *((bool*)((char*)this + 0x98)) = abCantOpenDoors;
}

struct FUN_006e2b70_shell : public PathingRequest
{
    void SetCanSwim(bool);
};

// @fnv 0x006e2b70
void FUN_006e2b70_shell::SetCanSwim(bool abCanSwim)
{
    *((bool*)((char*)this + 0x9d)) = abCanSwim;
}

struct FUN_006e2bb0_shell : public PathingRequest
{
    void SetInitialPathHeading(float);
};

// Stores afInitialPathHeading at offset 0x90 and sets the bool at offset 0xa0 to true.
// @fnv 0x006e2bb0
void FUN_006e2bb0_shell::SetInitialPathHeading(float afInitialPathHeading)
{
    *(float*)((char*)this + 0x90) = afInitialPathHeading;
    *(bool*)((char*)this + 0xa0) = true;
}

struct FUN_006e3a80
{
    virtual void va();
    char pad[12];
    FUN_006e3a80();
    ~FUN_006e3a80();
};
struct FUN_006e3960 : public FUN_006e3a80, public NiRefObject
{
    FUN_006e3960();
    ~FUN_006e3960();
};
// @fnv 0x006e3960
// pdb: BSSimpleArray<PathingAvoidNode,1024>::_MoveItems | PathingRequest.obj | retail, object-file run extension, low
// pdb note: debug build links it to BSSimpleArrayRefCounted<PathingAvoidNode,1024>::BSSimpleArrayRefCounted<PathingAvoidNode,1024>
// pdb params: apDestAddr, apSrcAddr, aiCount
// pdb locals: i
FUN_006e3960::FUN_006e3960()
{}

struct FUN_006e3ab0
{
    virtual void va();
    char pad[12];
    ~FUN_006e3ab0();
};
struct FUN_00496910
{
    virtual void vb();
    ~FUN_00496910();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006e39d0 : public FUN_006e3ab0, public FUN_00496910
{
    ~FUN_006e39d0();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006e39d0
// pdb: BSSimpleArrayRefCounted<PathingAvoidNode,1024>::~BSSimpleArrayRefCounted<PathingAvoidNode,1024> | PathingRequest.obj | debug, call graph, medium
FUN_006e39d0::~FUN_006e39d0()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct EBase
{
    unsigned char ebasePad[8];
    virtual void vfn0();
    ~EBase();
};
struct PathingRequestMember94
{
    unsigned char data[4];
    ~PathingRequestMember94();
};
class FUN_006e2620 : public EBase
{
  public:
    PathingLocation m0c;
    PathingLocation m34;
    unsigned char pad5c[0x38];
    PathingRequestMember94 m94;
    ~FUN_006e2620();
};
// @fnv 0x006e2620
// pdb: PathingRequest::~PathingRequest | PathingRequest.obj | retail, call graph, high
FUN_006e2620::~FUN_006e2620()
{}

struct BSSimpleArray_PathingAvoidNode_1024
{
    PathingAvoidNode* AllocateBuffer(unsigned int aiSizeInItem);
};

// Allocates a buffer of aiSizeInItem elements of 0x24 bytes each and returns the pointer.
// @fnv 0x006e3c10
// pdb: BSSimpleArray<PathingAvoidNode,1024>::_Allocate | PathingRequest.obj | debug, vtable slot, medium
// pdb params: aiSizeInItem
// pdb locals: pnewBuffer
PathingAvoidNode* BSSimpleArray_PathingAvoidNode_1024::AllocateBuffer(unsigned int aiSizeInItem)
{
    PathingAvoidNode* pBuffer = static_cast<PathingAvoidNode*>(operator new(aiSizeInItem * 0x24));
    return pBuffer;
}

extern "C" void* __cdecl Reallocate(void*, unsigned int);

struct FUN_006e3c40_shell
{
    void* __thiscall Reallocate_Thunk_006e3c40(void* apBuffer, unsigned int aiNewSizeInItem);
};

// @fnv 0x006e3c40
// src: GUESS 0x006e3c40 (confidence: medium)
// pdb: BSSimpleArray<PathingAvoidNode,1024>::_Reallocate | PathingRequest.obj | debug, vtable slot, medium
// pdb params: apBuffer, aiNewSizeInItem
void* __thiscall FUN_006e3c40_shell::Reallocate_Thunk_006e3c40(void* apBuffer, unsigned int aiNewSizeInItem)
{
    return Reallocate(apBuffer, aiNewSizeInItem * 0x24);
}

struct FUN_006dad70_shell : public PathingRequest
{
    void DestroyPathingRequest();
};

// @fnv 0x006dad70
// pdb: PathingRequestCover::~PathingRequestCover | Pathfind.obj | debug, call graph, medium
void __thiscall FUN_006dad70_shell::DestroyPathingRequest()
{
    PathingRequest::~PathingRequest();
}

struct FUN_006e2b90
{
    void SetFlag(unsigned char value);
};

// @fnv 0x006e2b90
void FUN_006e2b90::SetFlag(unsigned char value)
{
    ((unsigned char*)this)[0x9e] = value;
}



// Exe 0x006e3230: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct PathingrequestOffset08View
{
    unsigned int GetFlags();
};

struct FUN_006dc890_Class
{
    void PathingAvoidNode_SaveGame(BGSSaveFormBuffer*);
};

struct FUN_006e3230_shell
{
    void PathingRequest_SaveGame(BGSSaveFormBuffer*);
};

// Serializes this object's fields and two embedded pathing locations into the save buffer, then saves each avoid node referenced at offset 0x94.
// @fnv 0x006e3230
// src: XBOX_PDB 0x006e3230
// pdb: PathingRequest::SaveGame | PathingRequest.obj | retail, upstream name already matches, high
// pdb params: apSaveGameBuffer
// pdb locals: isaveGameCount, i, avoidNode
void FUN_006e3230_shell::PathingRequest_SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int i;
    unsigned int isaveGameCount;
    PathingAvoidNode* avoidNode;

    reinterpret_cast<PathingLocation*>(reinterpret_cast<char*>(this) + 0x0c)->SaveGame(apSaveGameBuffer);
    reinterpret_cast<PathingLocation*>(reinterpret_cast<char*>(this) + 0x34)->SaveGame(apSaveGameBuffer);

    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x68), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x6c), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x70), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x74), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x78), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x88), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x8c), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x99), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x98), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9a), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9b), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9c), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9d), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9f), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x90), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa0), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa1), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x7c), 12, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa2), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa3), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa4), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xa8), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x9e), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0xac), 1, 0);

    i = reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)->Get()
            ? reinterpret_cast<PathingrequestOffset08View*>(
                  reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)->Get())
                  ->GetFlags()
            : 0;

    apSaveGameBuffer->SaveVariableSizedValue(i);

    for (isaveGameCount = 0; isaveGameCount < i; ++isaveGameCount)
    {
        avoidNode = reinterpret_cast<PathingAvoidPointerView*>(reinterpret_cast<char*>(this) + 0x94)
                        ->Get()
                        ->BSSimpleArray_PathingAvoidNode_1024_GetAt(isaveGameCount);
        reinterpret_cast<FUN_006dc890_Class*>(avoidNode)->PathingAvoidNode_SaveGame(apSaveGameBuffer);
    }
}

struct Base_006e26a0
{
    virtual void v00();
    int unk04;
    int unk08;

    Base_006e26a0();
    ~Base_006e26a0();
};


struct Member20_006e26a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    Member20_006e26a0();
};

struct Member18_006e26a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    Member18_006e26a0();
};

struct Member4_006e26a0
{
    int unk00;

    Member4_006e26a0(int aValue);
    ~Member4_006e26a0();
};

struct Owner_006e26a0
{
    void Attach(struct FUN_006e26a0* apDest);
};

struct FUN_006e26a0 : Base_006e26a0
{
    PathingLocation m_0C;
    PathingLocation m_34;
    Member20_006e26a0 m_5C;
    Member18_006e26a0 m_7C;
    Member4_006e26a0 m_94;

    FUN_006e26a0(Owner_006e26a0* aRequest);
    virtual void v00();
};

// Constructs the object with m_94 set to 0 and attaches it to the given owner.
// @fnv 0x006e26a0
// pdb: PathingRequest::PathingRequest | PathingRequest.obj | retail, call graph (shared callers), high
FUN_006e26a0::FUN_006e26a0(Owner_006e26a0* aRequest) : m_94(0)
{
    aRequest->Attach(this);
}

struct PathingDebugOutput
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void __cdecl Print(unsigned int, unsigned int, const char*, ...);
};
struct PathingRequestDebugView : PathingRequest
{
    void PrintDebugInfo(PathingDebugOutput* apDebugText);
};
// Formats the request's origin, destination and pathing parameters into text and prints each line through the debug output.
// @fnv 0x006e2be0
// pdb: PathingRequest::PrintDebugText | PathingRequest.obj | retail, string-set bridge, high
// pdb params: apDebugText
// pdb locals: buffer
void PathingRequestDebugView::PrintDebugInfo(PathingDebugOutput* apDebugText)
{
    char text[256];
    Origin.PrintDebugText(text, 256);
    apDebugText->Print(0, 1, "Origin: %s", text);
    Destination.PrintDebugText(text, 256);
    apDebugText->Print(0, 1, "Destination: %s", text);
    apDebugText->Print(0, 1, "Actor Radius: %f", fActorRadius);
    apDebugText->Print(0, 1, "Goal Z Delta: %f", fGoalZDelta);
    apDebugText->Print(0, 1, "Target Radius: %f", fTargetRadius);
    apDebugText->Print(0, 1, "Allow Incomplete Path: %s", bAllowIncompletePath ? "true" : "false");
    if (fCenterRadius != 0.0)
        apDebugText->Print(0, 1, "Center Radius: (%.2f,%.2f,%.2f) %f", Center.x, Center.y, Center.z, fCenterRadius);
    apDebugText->Print(0, 1, "Face Target at Goal: %s", bFaceTargetAtGoal ? "true" : "false");
    if (bFaceTargetAtGoal)
        apDebugText->Print(0, 1, "Goal Angle: %f", fGoalAngle);
    if (bFirstTangentUsesHeading)
        apDebugText->Print(0, 1, "Initial Path Heading: %f", fInitialPathHeading);
    apDebugText->Print(0, 1, "Allow Direct Path If Pathing Fails: %s", bGoDirectIfPathingFails ? "true" : "false");
    apDebugText->Print(0, 1, "Using Curved path: %s", bTryToUseCurvedPath ? "true" : "false");
    apDebugText->Print(0, 1, "Ignoring Locks: %s", bIgnoreLocks ? "true" : "false");
    apDebugText->Print(0, 1, "Pathsmoothing retry count: %i", iRetryCount);
}
