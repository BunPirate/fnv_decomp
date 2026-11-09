
// fallout_shared/distant terrain system/bgsterrainmanager.cpp
#include "../../../include/BGSTerrainManager.h"
#include "../../../include/BGSDistantTreeBlock.h"
#include "bgsterrainmanager_decls.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TES.h"
#include "../../../include/NiNode.h"
// NiNodeHolder_bgsterrainmanager: local type (was include/NiNodeHolder.h, which had no evidence of one real class); its methods are 0x00559450 NiPointer<PathingSolution>::operator->, 0x0066b0d0 NiPointer<PathingSolution>::operator=
#include "../../../include/NiRefObject.h"

class NiNode;
class CleanupObject;

class NiNodeHolder_bgsterrainmanager
{
public:
    NiRefObject* value;

    NiNodeHolder_bgsterrainmanager(NiRefObject* p);
    ~NiNodeHolder_bgsterrainmanager();
    operator NiNode*() const;
    void FUN_0066b0d0(CleanupObject* object);
    CleanupObject* Modelloader_GetReferencedThis();
};
#include "../../../include/TESObjectREFR.h"
#include "../../../include/BGSTerrainNode.h"

// 0x00485b60 is not declared by the shared headers; this preserves its ECX-only call ABI.
unsigned int __fastcall GetTerrainReferenceID(TESObjectREFR* reference);

// Returns null if path is missing or not found, otherwise opens the file and returns the result of ReadAnimationFromStream on it.
// @fnv 0x004d52f0
// pdb: LipSynchAnim::LoadFromFile | LipSynchAnim.obj | debug, object-file run extension, low
// pdb params: apFilename
// pdb locals: pfile
BGSTerrainManager* LoadBGSTerrainManager(const char* path)
{
    BSFile* file = 0;
    if (!path || !FileFinder::Exist(path, 0, 0, 0xFFFFFFFF))
    {
        return 0;
    }
    file = FileFinder::GetFile(path, NiFile::READ_ONLY, 0x4000, 0x10);
    return ReadAnimationFromStream(file);
}

void __cdecl BGSTerrainChunk_ResetCullResults();
void __cdecl BGSDistantObjectBlock_ResetCullResults();

// @fnv 0x006fd130
// pdb: BGSTerrainManager::ResetMultiBoundResults | BGSTerrainManager.obj | retail, upstream name already matches, high
void BGSTerrainManager::ResetMultiBoundResults()
{
    if (pRootNode)
    {
        BGSTerrainChunk_ResetCullResults();
        BGSDistantObjectBlock_ResetCullResults();
    }
}

void __cdecl SetSoundListFlag(bool);

// @fnv 0x006fd1f0
// src: XBOX_PDB 0x006fd1f0
// pdb: BGSTerrainManager::EnableLODWaterProcessing | BGSTerrainManager.obj | debug, upstream name already matches, high
// pdb params: abEnable
void __cdecl BGSTerrainManager_EnableLODWaterProcessing(bool abEnable)
{
    SetSoundListFlag(abEnable);
}

extern int DAT_011d8598;

// @fnv 0x006fcda0
// src: COMMUNITY 0x006fcda0
int __cdecl BGSDistantTreeBlock_GetBlockCount()
{
    return DAT_011d8598;
}

struct FUN_006fd980_shell
{
    void BGSTerrainNode_UnloadDataRecurse(int);
};

// If the root node is non-null, calls FUN_006fd980(7) on it.
// @fnv 0x006fce00
// src: XBOX_PDB 0x006fce00
// pdb: BGSDistantObjectBlock::QBlocksAreLoaded | BGSTerrainManager.obj | debug, object-file run extension, low
void __thiscall BGSTerrainManager::UnloadAll_006fce00()
{
    if (pRootNode != 0)
        ((FUN_006fd980_shell*)pRootNode)->BGSTerrainNode_UnloadDataRecurse(7);
}

// pdb: class BGSTerrainChunk, size 0x30 (here 0x1), 14 members
struct BGSTerrainChunk
{
    int __thiscall BGSTerrainChunk_GetTexture(int);
};

// @fnv 0x006fce30
// pdb: BGSTerrainManager::GetDiffuseTextureForPoint | BGSTerrainManager.obj | retail, upstream name already matches, high
// pdb params: aPoint
// pdb locals: ptex, pchunk
NiTexture* BGSTerrainManager::GetDiffuseTextureForPoint(void* aPoint)
{
    NiTexture* result = 0;
    BGSTerrainChunk* obj = GetChunkForPoint(aPoint);
    if (obj)
    {
        result = (NiTexture*)obj->BGSTerrainChunk_GetTexture(0);
    }
    return result;
}

struct GlobalObject_00869f00
{
    void Remove(unsigned int, bool);
};

// Scans the array at offset 0x2c for entries equal to apTreeRef and removes each match, decrementing the count.
// @fnv 0x006fcf30
// src: XBOX_RETAIL_PDB 0x006fcf30
// pdb: BGSTerrainManager::ReleaseTree | BGSTerrainManager.obj | retail, call graph (shared callers), high
// pdb params: apTreeRef
// pdb locals: icount, i
void BGSTerrainManager::ReleaseTree(TESObjectREFR* apTreeRef)
{
    unsigned int icount = ((BSSimpleArray<unsigned int>*)(&TreesQueuedToHide))->GetSize();
    unsigned int i = 0;
    while (i < icount)
    {
        if (*((BSSimpleArray<TESObjectREFR*>*)(&TreesQueuedToHide))->GetAtPointer((int)i) == apTreeRef)
        {
            ((GlobalObject_00869f00*)(&TreesQueuedToHide))->Remove(i, true);
            icount--;
        }
        else
        {
            i++;
        }
    }
}


// @fnv 0x006fd060
// src: COMMUNITY 0x006fd060
// pdb: BGSTerrainManager::TriggerApocalypse | BGSTerrainManager.obj | debug, object-file run extension, low
void __thiscall BGSTerrainManager::TriggerLODApocalypse()
{
    pRootNode->ProcessBlock();
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern unsigned char DAT_0119f188;
extern GlobalObject_0045cf30 g_011d86ac;
struct FUN_006fea70_obj
{
    void SetValue(int);
};
// @fnv 0x006fcdb0
// pdb: BGSTerrainManager::UpdateMorphParameters | BGSTerrainManager.obj | debug, upstream name already matches, high
// pdb params: aViewPosition
void BGSTerrainManager::UpdateMorphParameters(void* aViewPosition)
{
    if (DAT_0119f188 && *g_011d86ac.Bool() && pRootNode)
        ((FUN_006fea70_obj*)pRootNode)->SetValue((int)aViewPosition);
}

// @fnv 0x006fce70
// pdb: BGSTerrainManager::GetNormalTextureForPoint | BGSTerrainManager.obj | retail, upstream name already matches, high
// pdb params: aPoint
// pdb locals: ptex, pchunk
NiTexture* BGSTerrainManager::GetNormalTextureForPoint(void* aPoint)
{
    NiTexture* result = 0;
    BGSTerrainChunk* chunk = GetChunkForPoint(aPoint);
    if (chunk)
        result = (NiTexture*)chunk->BGSTerrainChunk_GetTexture(1);
    return result;
}

struct Unk006fec90
{
    int __thiscall BGSTerrainNode_GetChunkForPoint(int);
};
// @fnv 0x006fceb0
// pdb: BGSTerrainManager::GetChunkForPoint | BGSTerrainManager.obj | debug, upstream name already matches, high
// pdb params: aPoint
// pdb locals: pchunk
BGSTerrainChunk* BGSTerrainManager::GetChunkForPoint(void* aPoint)
{
    int unused = 0;
    if (pRootNode)
        return (BGSTerrainChunk*)((Unk006fec90*)pRootNode)->BGSTerrainNode_GetChunkForPoint((int)aPoint);
    return 0;
}

struct FUN_006fed30_Callee
{
    int __thiscall BGSTerrainNode_GetTreeBlockForPoint(int);
};
// @fnv 0x006fcef0
// pdb: BGSTerrainManager::GetTreeBlockForPoint | BGSTerrainManager.obj | debug, call graph, medium
// pdb params: aPoint
// pdb locals: pchunk
BGSDistantTreeBlock* BGSTerrainManager::GetDistantTreeBlockForPoint(void* a)
{
    int unused = 0;
    if (pRootNode)
        return (BGSDistantTreeBlock*)((FUN_006fed30_Callee*)pRootNode)->BGSTerrainNode_GetTreeBlockForPoint((int)a);
    return 0;
}

// @fnv 0x006fd010
// pdb: BGSTerrainManager::ShowTree | BGSTerrainManager.obj | debug, object-file run extension, low
// pdb params: apTreeRef
// pdb locals: ptrees, id
void BGSTerrainManager::AddTerrainReference(TESObjectREFR* a1)
{
    unsigned int tmp = GetTerrainReferenceID(a1);
    {
        BGSDistantTreeBlock* p = GetDistantTreeBlockForPoint((void*)((const TESObjectREFR*)a1)->GetPos());
        if (p)
            p->ClearInstanceFlag(tmp);
    }
}

struct S_00587f40_Lock
{
    void BSCriticalSection_Enter(int apName);
    void FUN_004538c0();
};
extern S_00587f40_Lock DAT_011ca60c;

struct S_00587f40_List
{
    int unk00;
    int unk04;
    void RemoveAll();
    ~S_00587f40_List();
};

struct S_00587f40_Map
{
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, S_00587f40_List*& val);
    void RemoveAll();
};

struct S_00587f40
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    S_00587f40_Map m_map;
    int unk54;
    int unk58;
    int unk5C;
    S_00587f40_List m_kNode;
    void TESWorldSpace_ClearPersistentRefData();
};

// @fnv 0x00587f40
// src: XBOX_RETAIL_PDB 0x00587f40
// pdb: TESWorldSpace::ClearPersistentRefData | TESWorldSpace.obj | retail, call graph, high
// pdb locals: iter, preflist, iignore
void S_00587f40::TESWorldSpace_ClearPersistentRefData()
{
    DAT_011ca60c.BSCriticalSection_Enter(0);
    m_kNode.RemoveAll();
    void* pos = m_map.GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        S_00587f40_List* list = 0;
        m_map.GetNext(pos, key, list);
        if (list)
        {
            list->RemoveAll();
            delete list;
        }
    }
    m_map.RemoveAll();
    DAT_011ca60c.FUN_004538c0();
}

// @fnv 0x006fcfa0
// src: XBOX_RETAIL_PDB 0x006fcfa0
// pdb: BGSTerrainManager::HideTree | BGSTerrainManager.obj | retail, call graph (shared callers), high
// pdb params: apTreeRef, abQueue
// pdb locals: ptrees, id
void BGSTerrainManager::HideTree(TESObjectREFR* apTreeRef, bool abQueue)
{
    unsigned int formId = GetTerrainReferenceID(apTreeRef);
    BGSDistantTreeBlock* block = GetDistantTreeBlockForPoint((void*)((const TESObjectREFR*)apTreeRef)->GetPos());
    if (block)
    {
        block->MarkTreeInstance(formId, true);
    }
    else if (abQueue)
    {
        TreesQueuedToHide.Add((TESObjectREFR* const&)apTreeRef);
    }
}

// pdb: structure tagRECT, size 0x10, 4 members
struct tagRECT
{
    long left, top, right, bottom;
};
void __cdecl SetRectCenterAndHalfExtents(tagRECT*);

extern TES* g_TES;

extern NiNodeHolder_bgsterrainmanager DAT_011d86bc;
extern GlobalObject_0045cf30 DAT_011d869c;
extern GlobalObject_0045cf30 DAT_011d8680;


struct LodNode
{
    void UpdateTerrainNode(const NiPoint3&, bool);
    void UpdateBlock(const NiPoint3&, bool);
    void BGSTerrainNode_UpdateTrees(const NiPoint3&);
};

struct RefArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TESObjectREFR*& FUN_00877a30(unsigned int);
    unsigned int FUN_0044ddc0();
    void FUN_008454f0(bool);
    void FUN_006f2290(unsigned int, bool);
    void BSSimpleArray_TESAmmo_1024_SetAt(unsigned int, TESObjectREFR* const&);
};

struct LocalRefArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LocalRefArray();
    ~LocalRefArray();
    unsigned int FUN_0044ddc0();
    void FUN_007cb2e0(TESObjectREFR* const&);
    TESObjectREFR*& BSSimpleArray_NiAVObject_1024_GetAt(unsigned int);
};

extern BGSTerrainManager* DAT_011d8670;

// @fnv 0x006fca90
// src: XBOX_PDB 0x006fca90
// pdb: BGSTerrainManager::Update | BGSTerrainManager.obj | debug, call graph, high
// pdb params: aViewPosition, aWhatToUpdate
// pdb locals: viewPos, kloadedrect, poldManager, bupdateLandAndBlocks, bupdateWaterVisibility, bupdateTrees, bupdateBlockVisibility, tempTreeList, uisize, i, ptrees, id
void BGSTerrainManager::Update_006fca90(const NiPoint3& aViewPosition, int aWhatToUpdate)
{
    if (DAT_0119f188 && *g_011d86ac.Bool())
    {
        NiPoint3 pos = aViewPosition;
        aWhatToUpdate |= 1;
        tagRECT rect;
        g_TES->FUN_00451020(&rect, 0.0f);
        SetRectCenterAndHalfExtents(&rect);
        if (DAT_011d8670 && DAT_011d8670 != this)
        {
            BGSTerrainManager* pOld = DAT_011d8670;
            DAT_011d8670 = this;
            pOld->UnloadAll_006fce00();
            if (DAT_011d86bc)
            {
                ((NiNode*)DAT_011d86bc)->DetachAllChildren_00572160();
            }
        }
        DAT_011d8670 = this;
        if (pRootNode)
        {
            bool b1 = (aWhatToUpdate & 1) != 0;
            bool b2 = (aWhatToUpdate & 2) != 0;
            bool b4 = (aWhatToUpdate & 4) != 0;
            bool m_bShaderFeatureActive = (aWhatToUpdate & 8) != 0;
            if (b1)
            {
                ((LodNode*)pRootNode)->UpdateTerrainNode(pos, b4);
                g_TES->TES_InitDistantTextureBlending();
                if (*DAT_011d869c.Bool())
                {
                    ((LodNode*)pRootNode)->UpdateBlock(pos, b2);
                }
            }
            if (m_bShaderFeatureActive && *DAT_011d8680.Bool())
            {
                unsigned int count;
                ((LodNode*)pRootNode)->BGSTerrainNode_UpdateTrees(pos);
                if (BGSDistantTreeBlock_GetBlockCount() > 0u && ((RefArray*)&TreesQueuedToHide)->FUN_0044ddc0() > 0)
                {
                    LocalRefArray kept;
                    count = ((RefArray*)&TreesQueuedToHide)->FUN_0044ddc0();
                    for (unsigned int i = 0; i < count; i++)
                    {
                        unsigned int val = GetTerrainReferenceID(((RefArray*)&TreesQueuedToHide)->FUN_00877a30(i));
                        BGSDistantTreeBlock* pBlock = GetDistantTreeBlockForPoint((void*)((const TESObjectREFR*)((RefArray*)&TreesQueuedToHide)->FUN_00877a30(i))->GetPos());
                        if (pBlock)
                        {
                            pBlock->MarkTreeInstance(val, true);
                        }
                        else
                        {
                            kept.FUN_007cb2e0(((RefArray*)&TreesQueuedToHide)->FUN_00877a30(i));
                        }
                    }
                    ((RefArray*)&TreesQueuedToHide)->FUN_008454f0(true);
                    if (kept.FUN_0044ddc0() > 0)
                    {
                        unsigned int keptCount = kept.FUN_0044ddc0();
                        ((RefArray*)&TreesQueuedToHide)->FUN_006f2290(keptCount, true);
                        for (unsigned int j = 0; j < keptCount; j++)
                        {
                            ((RefArray*)&TreesQueuedToHide)->BSSimpleArray_TESAmmo_1024_SetAt(j, kept.BSSimpleArray_NiAVObject_1024_GetAt(j));
                        }
                    }
                }
            }
        }
    }
    bNeedsImmediateUpdate = 0;
}

class TerrainRefProxy
{
  public:
    unsigned int GetRawId();
};

class TerrainTempBuffer
{
  public:
    TerrainTempBuffer(int aInit);
    ~TerrainTempBuffer();
    void Push(TerrainRefProxy* apRef);
    void Assign(unsigned int kFrustum);

    unsigned int m_00, m_04, m_08, m_0C, m_10, m_14, m_18, m_1C, m_20;
    unsigned int m_24, m_28, m_2C, m_30, m_34, m_38, m_3C, m_40, m_44;
    unsigned int m_48, m_4C, m_50, m_54, m_58, m_5C, m_60, m_64, m_68;
    unsigned int m_6C, m_70, m_74, m_78, m_7C, m_80, m_84, m_88;
};

void __cdecl UpdateSceneEntryRadii(TerrainRefProxy* apRef, TerrainTempBuffer* apBuf);
void __cdecl BGSDistantObjectBlock_ResetCullResults();

// @fnv 0x006fd080
// pdb: ShadowSceneNode::UpdateMultiboundVisibility | ShadowSceneNode.obj | debug, call graph, medium
// pdb params: apMultibound, akViewPoint, akCuller
// pdb locals: pbsculler, kresult, bshapewithinfrustum, kiter, poccluder
void BGSTerrainManager::UpdateMultiBoundResults(NiCamera* apCamera)
{
    TerrainTempBuffer tempBuffer(0);
    tempBuffer.Push((TerrainRefProxy*)apCamera);
    tempBuffer.Assign(((TerrainRefProxy*)apCamera)->GetRawId());
    if (pRootNode != 0)
    {
        UpdateSceneEntryRadii((TerrainRefProxy*)apCamera, &tempBuffer);
        BGSDistantObjectBlock_ResetCullResults();
    }
}
