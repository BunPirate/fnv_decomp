#pragma once

// BGSTerrainManager: distant-LOD manager of a worldspace, no vtable. 0x3c bytes: the one allocation (0x00584b62)
// `new`s 0x3c before calling the constructor 0x006fc490, which constructs NiPointer<NiNode> at +0x08 and +0x0c
// (0x00633c90) and the BSSimpleArray<TESObjectREFR*> at +0x2c (0x005e04c0), stores the world at +0x00 and reads the
// coordinates and levels at +0x10..+0x24 from the LOD settings file. GetHasLOD 0x00454b70 tests +0x04,
// GetMaxLevel 0x009611e0 reads +0x18, GetMinLevel 0x00441110 reads +0x1c, SetNeedsImmediateUpdate 0x00929260 writes +0x28.

#include "BSSimpleArray.h"
#include "NiPointer.h"

class BGSDistantTreeBlock;
class BGSTerrainChunk;
class BGSTerrainNode;
class NiCamera;
class NiNode;
class NiPoint3;
class NiTexture;
class TESObjectREFR;
class TESWorldSpace;

// pdb: class BGSTerrainManager, size 0x3c, 15 members
class BGSTerrainManager
{
public:
    TESWorldSpace* pWorld;                                      // 0x00
    BGSTerrainNode* pRootNode;                           // 0x04
    NiPointer<NiNode> spLODRoot;                                // 0x08
    NiPointer<NiNode> spLODWaterRoot;                           // 0x0c
    short sMinCellX;                                                // 0x10 north-west cell
    short sMinCellY;                                                // 0x12
    short sMaxCellX;                                                // 0x14 south-east cell
    short sMaxCellY;                                                // 0x16
    unsigned int iMaxLevel;                                    // 0x18
    unsigned int iMinLevel;                                    // 0x1c
    unsigned int iRootLevel;                                      // 0x20
    unsigned int iBlockLevel;                                    // 0x24
    bool bNeedsImmediateUpdate;                                 // 0x28
    bool bHasLOD;                                               // 0x29 ctor: 0
    bool bFlag2A;                                               // 0x2a
    bool bFlag2B;                                               // 0x2b
    BSSimpleArray<TESObjectREFR*, 1024> TreesQueuedToHide;     // 0x2c AddTerrainReference / RemoveTerrainReference

    BGSTerrainManager(TESWorldSpace* apWorld);                    // 0x006fc490
    ~BGSTerrainManager();                                       // 0x006fc980

    void AddMultiBoundDebugLines(NiCamera*);
    void AddTerrainReference(TESObjectREFR*);
    static void ClearMultiBoundResults();
    static void DeallocateStaticNodes();
    static void DisableBlockVisibility();
    static void EnableBlockVisibility();
    static void EnableLODWaterProcessing(bool);
    bool FUN_00454b70();
    void Update_006fca90(const NiPoint3&, int);
    void UnloadAll_006fce00();
    void TriggerLODApocalypse();
    static BGSTerrainManager* GetActiveManager();
    unsigned int GetBlockLevel();
    BGSTerrainChunk* GetChunkForPoint(void*);
    static bool GetCurrentWorldHasLOD();
    NiTexture* GetDiffuseTextureForPoint(void*);
    BGSDistantTreeBlock* GetDistantTreeBlockForPoint(void*);
    static bool GetEnabled();
    bool GetHasLOD();
    NiNode* GetLODLandRoot();
    NiNode* GetLODObjectRoot();
    NiNode* GetLODRoot();
    unsigned int GetMaxLevel();
    unsigned int GetMaximumLevelWithGeometry();
    unsigned int GetMinLevel();
    unsigned int GetMinimumLevel();
    bool GetNeedsImmediateUpdate();
    NiTexture* GetNormalTextureForPoint(void*);
    unsigned int GetRootLevel();
    BGSTerrainNode* GetRootTerrainNode();
    static unsigned int GetTreeLevel();
    NiNode* GetTreeNode();
    NiNode* GetWaterLODRoot();
    TESWorldSpace* GetWorld();
    void LoadAll();
    bool QHasLOD();
    void RefreshTerrain();
    void ReleaseTree(TESObjectREFR*);
    void ResetMultiBoundResults();
    static void SetEnabled(bool);
    void SetNeedsImmediateUpdate(bool);
    static void SetTreeNode(NiNode*);
    static void ShowMinimumDetail();
    static void ShowNormalDetail();
    void UnloadAll();
    void Update(const NiPoint3&, int);
    void Update(void*, int);
    void UpdateMorphParameters(void*);
    void UpdateMultiBoundResults(NiCamera*);
    void HideTree(TESObjectREFR*, bool);
};
