#pragma once

#include "PathingRequest.h"
#include "PathingLocation.h"

// pdb: class PathingRequestHide, size 0xdc, bases: PathingRequest, 2 members
class PathingRequestHide : public PathingRequest
{
public:
    PathingRequestHide();  // 0x006e5510 (PathingRequest::CreateRequestForType, type 4: 0xdc bytes)
    PathingRequestHide(Actor* aRequest);
    virtual ~PathingRequestHide();
    virtual void CopyTo(PathingRequest* apDest);
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    void* Destroy(unsigned int flags);
    // Explicit cleanup entry without an implicit destructor vtable write.
    void DestroyMembers();
    void FUN_006e55e0();
    void CopyTo_006e56f0(PathingRequest* apDest);

    PathingLocation ThreatLocation;
    float fMinHideDistance;
};
