#pragma once

// NavMeshInfo: per-navmesh record kept by NavMeshInfoMap, no vtable. 0x5c bytes: both allocation sites
// (0x00698726 and 0x006b603f) `new` 0x5c before calling the constructor 0x006b46a0, which builds the NiPoint3 at +0x10,
// the two BSSimpleArray<NavMeshInfo*> at +0x24/+0x34 (0x0069aee0) and the BSSimpleArray<TESObjectREFR*> at +0x44
// (0x005e04c0), zeroes +0x00, +0x1c, +0x54, +0x58, stores 0xdeaddead at +0x0c and a float at +0x20.

#include "BSSimpleArray.h"
#include "NiPoint3.h"

class NavMesh;
class NavMeshBounds;
class NavMeshPtr;
class TESFile;
class TESForm;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;
template <class T> class NiPointer;

// pdb: class NavMeshInfo, size 0x5c, 12 members
class NavMeshInfo
{
public:
    unsigned int NavMeshID;                                    // 0x00
    unsigned int ParentSpaceID;                                // 0x04
    unsigned int uiFlags;                                          // 0x08
    int iCellKey;                                          // 0x0c ctor: 0xdeaddead
    NiPoint3 ApproxLocation;                                   // 0x10
    TESForm* pParentSpace;                                       // 0x1c
    float fPreferredPercent;                                          // 0x20
    BSSimpleArray<NavMeshInfo*, 1024> AdjacentNavMeshes;    // 0x24
    BSSimpleArray<NavMeshInfo*, 1024> PreferredAdjacentNavMeshes;     // 0x34
    BSSimpleArray<TESObjectREFR*, 1024> ConnectedDoors;         // 0x44
    NavMesh* pNavMesh;                                   // 0x54
    NavMeshBounds* pBounds;                                        // 0x58

    NavMeshInfo();                                                 // 0x006b46a0
    ~NavMeshInfo();                                                // 0x006b4790

    bool AcquireNavMesh(NavMeshPtr&);
    void Delete();                                                 // 0x006b6390: `delete this` (the deleting destructor)
    void CopyTo(NavMeshInfo*);
    bool NavMeshInfo_GetDisabled() const;
    void FUN_0069ad00(NiPointer<NavMesh>&);
    float FUN_007df1f0() const;
    NavMeshBounds* GetBounds();
    TESObjectCELL* GetInteriorCell();
    unsigned int GetNavMeshID();
    TESWorldSpace* GetParentWorldSpace();
    void LoadNavMeshInfo(char*, TESFile*, int);
    void SetFromPortalChunk(char*, TESFile*, int);
    void InitDoorPointers();
    bool ResolveNavMesh(NavMeshPtr&);
    void SetNavMesh(NavMesh*);
    TESObjectCELL* GetCell(); // exe 0x006b7770
    int GetInfoChunkSize();       // exe 0x006b4880
    void WriteInfoChunk(char*);   // exe 0x006b48f0
    int GetIndexChunkSize();      // exe 0x006b4e10
    void WriteIndexChunk(char*);  // exe 0x006b4e80
    bool HasNonZeroAtOffset54() const; // exe 0x0069dfb0
    bool HasNonZeroAtOffset54();  // exe 0x0069dfb0
    void NavMeshInfo_CreateFromNavMesh(NavMesh*); // exe 0x006b5560
    bool ResolveNavMesh(NavMeshPtr&) const;
};
