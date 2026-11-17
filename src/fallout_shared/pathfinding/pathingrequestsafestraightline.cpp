
// src/fallout_shared/pathfinding/pathingrequestsafestraightline.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestsafestraightline.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/PathingRequestSafeStraightLine.h"


extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x006e5fd0
// pdb: PathingRequestSafeStraightLine::`scalar deleting destructor' | PathingRequestSafeStraightLine.obj | retail, vtable slot, high
void* PathingRequestSafeStraightLine::FUN_006e5fd0(unsigned int flags)
{
    this->PathingRequestSafeStraightLine::~PathingRequestSafeStraightLine();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xbc);
    return this;
}

// @fnv 0x006e60c0
// src: XBOX_PDB 0x006e60c0
void __thiscall PathingRequestSafeStraightLine::SetTarget_006e60c0(int a1)
{
    pTarget = pTarget;
}

// @fnv 0x006e60e0
// pdb: PathingRequestSafeStraightLine::SaveGame | PathingRequestSafeStraightLine.obj | retail, vtable slot, high
// pdb params: apSaveGameBuffer
void __thiscall PathingRequestSafeStraightLine::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequestOptimalLocation_SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData((void*)pTarget, 0);
}

// Calls the base load routine on buffer, then loads the field at offset 0xb8 from the buffer.
// @fnv 0x006e6110
// src: XBOX_PDB 0x006e6110
// pdb: PathingRequestSafeStraightLine::LoadGame | PathingRequestSafeStraightLine.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
void PathingRequestSafeStraightLine::LoadGame_006e6110(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequestClosePoint::PathingRequestOptimalLocation_LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadFormIdentifier((void*)&pTarget);
}

// @fnv 0x006e6080
// src: XBOX_PDB 0x006e6080
// pdb: PathingRequestSafeStraightLine::CopyTo | PathingRequestSafeStraightLine.obj | debug, vtable slot, medium
// pdb params: apDest
// pdb locals: pdest
void __thiscall PathingRequestSafeStraightLine::CopyTo_006e6080(PathingRequest* apDest)
{
    PathingRequestSafeStraightLine* pdest = (PathingRequestSafeStraightLine*)apDest;
    PathingRequest::CopyTo(pdest);
    pdest->SetTarget_006e60c0(pTarget);
}

// The shared PathingRequestClosePoint lacks the copy constructor at 0x006e3fb0,
// and PathingRequestSafeStraightLine lacks the target getter at 0x004036b0.
// Retain the constructor helpers until those declarations are available.
struct S_004036b0
{
    int TES_QPlaceableWaterCount();
};
struct FUN_006e3fb0_base
{
    FUN_006e3fb0_base(int);
    virtual ~FUN_006e3fb0_base();
};
struct FUN_006e6010 : FUN_006e3fb0_base
{
    char _pad[0xB4];
    int pTarget;
    FUN_006e6010(int aRequest);
    ~FUN_006e6010();
};
// Constructs the base with ai and stores the result of FUN_004036b0 called on ai into pTarget.
// @fnv 0x006e6010
// pdb: PathingRequestSafeStraightLine::PathingRequestSafeStraightLine | PathingRequestSafeStraightLine.obj | debug, call graph, high
// pdb params: aRequest
FUN_006e6010::FUN_006e6010(int aRequest) : FUN_006e3fb0_base(aRequest)
{
    pTarget = ((S_004036b0*)(void*)aRequest)->TES_QPlaceableWaterCount();
}

// @fnv 0x006e6140
// pdb: PathingRequestSafeStraightLine::InitLoadGame | PathingRequestSafeStraightLine.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
void __thiscall PathingRequestSafeStraightLine::ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer)
{
    pTarget = pTarget
                  ? (int)dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID((unsigned int)pTarget))
                  : 0;
}
