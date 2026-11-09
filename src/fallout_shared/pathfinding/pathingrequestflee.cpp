// src/fallout_shared/pathfinding/pathingrequestflee.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestflee.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/PathingRequestFlee.h"

class PathingRequestOwner
{
public:
    float GetGoalRadius() const;
};

// Initializes the base request and the flee radius.
// @fnv 0x006e5390
// pdb: PathingRequestFlee::PathingRequestFlee | PathingRequestFlee.obj | retail, call graph, high
PathingRequestFlee::PathingRequestFlee()
{
    fMinFleeDistance = 128.0f;
}

// Destructs the base and optionally frees the request.
// @fnv 0x006e53c0
// pdb: PathingRequestFlee::`scalar deleting destructor' | PathingRequestFlee.obj | retail, vtable slot, high
void* PathingRequestFlee::DestroyAndFree(unsigned int flags)
{
    PathingRequest::DestroyPathingRequest();
    if (flags & 1)
        PathingRequest::operator delete(this, 0xb4);
    return this;
}

// Constructs the base from the owner and takes its goal radius.
// @fnv 0x006e5400
// pdb: PathingRequestFlee::PathingRequestFlee | PathingRequestFlee.obj | retail, object-file run extension, low
PathingRequestFlee::PathingRequestFlee(PathingRequestOwner* owner) : PathingRequest(owner)
{
    fMinFleeDistance = owner->GetGoalRadius();
}

// @fnv 0x006e5470
// pdb: PathingRequestFlee::CopyTo | PathingRequestFlee.obj | retail, vtable slot, high
// pdb params: apDest
// pdb locals: pdest
void PathingRequestFlee::CopyToWithFleeData(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    PathingRequest::CopyTo(pdest);
    ((PathingRequestFlee*)pdest)->fMinFleeDistance = fMinFleeDistance;
}

// Saves the base request and the flee radius.
// @fnv 0x006e54b0
// pdb: PathingRequestFlee::SaveGame | PathingRequestFlee.obj | retail, upstream name already matches, high
// pdb params: apSaveGameBuffer
void PathingRequestFlee::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(&fMinFleeDistance, 4, 0);
}

// Loads the base request and the flee radius.
// @fnv 0x006e54e0
// pdb: PathingRequestFlee::LoadGame | PathingRequestFlee.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void PathingRequestFlee::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)&fMinFleeDistance, 4u);
}
