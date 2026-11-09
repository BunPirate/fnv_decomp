// src/fallout_shared/pathfinding/pathingrequesthide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequesthide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/PathingRequestHide.h"

extern "C" void __cdecl _delete(void*, unsigned int);

// Runs the destructor and, when flags has bit 0 set, frees the object with _delete; returns this.
// @fnv 0x006e55a0
// pdb: PathingRequestHide::`scalar deleting destructor' | PathingRequestHide.obj | retail, vtable slot, high
void* PathingRequestHide::Destroy(unsigned int flags)
{
    this->PathingRequestHide::~PathingRequestHide();
    if (flags & 1)
        _delete(this, 0xdc);
    return this;
}

class HideActorView
{
public:
    PathingLocation* hkpAabbPhantom_getAabb();
    float FUN_00885bd0();
};

struct HidePathView
{
    void FUN_006d2c00();
};

// @fnv 0x006e5640
// pdb: PathingRequestHide::PathingRequestHide | PathingRequestHide.obj | debug, call graph, high
// pdb params: aRequest
PathingRequestHide::PathingRequestHide(Actor* aRequest)
    : PathingRequest(reinterpret_cast<PathingRequestOwner*>(aRequest))
{
    ThreatLocation = *reinterpret_cast<HideActorView*>(aRequest)->hkpAabbPhantom_getAabb();
    fMinHideDistance = reinterpret_cast<HideActorView*>(aRequest)->FUN_00885bd0();
    reinterpret_cast<HidePathView*>(&Destination)->FUN_006d2c00();
}

// The original cleanup entry omits a vtable write. Apply novtable after
// the constructor so its normal vtable initialization is retained.
class __declspec(novtable) PathingRequestHide;

// Destroys the embedded location and the base request.
// @fnv 0x006e55e0
// pdb: PathingRequestHide::~PathingRequestHide | PathingRequestHide.obj | debug, upstream name already matches, high
PathingRequestHide::~PathingRequestHide()
{}

// Saves the base request, hide location, and hide distance.
// @fnv 0x006e5740
// pdb: PathingRequestHide::SaveGame | PathingRequestHide.obj | retail, upstream name already matches, high
// pdb params: apSaveGameBuffer
void PathingRequestHide::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::PathingRequest_SaveGame(apSaveGameBuffer);
    ThreatLocation.SaveGame(reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer));
    apSaveGameBuffer->SaveData(&fMinHideDistance, 4, 0);
}

// Loads the base request, hide location, and hide distance.
// @fnv 0x006e5790
// pdb: PathingRequestHide::LoadGame | PathingRequestHide.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void PathingRequestHide::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    ThreatLocation.LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(static_cast<void*>(&fMinHideDistance), 4u);
}

// Copies the base request, hide location, and hide distance.
// @fnv 0x006e56f0
// src: XBOX_PDB 0x006e56f0
// pdb: PathingRequestHide::CopyTo | PathingRequestHide.obj | retail, vtable slot, high
// pdb params: apDest
// pdb locals: pdest
void PathingRequestHide::CopyTo_006e56f0(PathingRequest* apDest)
{
    PathingRequestHide* pdest = static_cast<PathingRequestHide*>(apDest);
    PathingRequest::CopyTo(pdest);
    pdest->ThreatLocation = ThreatLocation;
    pdest->fMinHideDistance = fMinHideDistance;
}

