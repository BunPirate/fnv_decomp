#pragma once

#include "QueuedFileEntry.h"
#include "NiAVObject.h"

class BGSDistantObjectBlock;
class TESWorldSpace;

// pdb: class BGSDistantObjectBlockLoadTask, size 0x58, bases: QueuedFileEntry, 10 members
class BGSDistantObjectBlockLoadTask : public QueuedFileEntry
{
public:
    BGSDistantObjectBlockLoadTask(int apBlock, int apWorld, int aiX, int aiY, int aiLevel,
                                bool abPostApocalypse, bool abHighPriority, bool abStingerVersion);
    BGSDistantObjectBlockLoadTask(BGSDistantObjectBlock* parent, TESWorldSpace* world,
                                int x, int y, int level, bool force, bool alternate, bool lod);
    BGSDistantObjectBlockLoadTask(void* apBlock, void* apWorld, int aiX, int aiY, void* aiLevel,
                                int abPostApocalypse, int abHighPriority, int abStingerVersion);

    virtual ~BGSDistantObjectBlockLoadTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);
    virtual void DispatchToManager();
    virtual void HandleChildCompletion(QueuedFile* apChild);
    virtual void OnChildCompletion();
    virtual unsigned char GetFileIndex();

    void BGSDistantObjectBlockLoadTask_GetWaterGeometry(void* destination);
    void QueuedFile_Cancel(void* aePreviousState, void* apTaskOwner);
    void RunOnce(void* apTaskState, void* apTaskOwner);
    void FUN_006f6fe0();
    void* FUN_006f6fb0(unsigned int flags);
    void LoadDistantObjectBlock();
    void UpdateLoadingState();
    void QueueLODModelLoads();

    union
    {
        unsigned int unk30;
        unsigned char m_bDone;
        bool bFadeQueuedCur;
    };
    union { int iX; int m_iX; };
    union { int iY; int m_iY; };
    union { int iLevel; int m_iZ; };
    BGSDistantObjectBlock* pBlock; // src: XBOX_RETAIL_PDB +0x40 (old: m_pParent)
    TESWorldSpace* pWorldSpace; // src: XBOX_RETAIL_PDB +0x44 (old: m_pContainingWorldspace)
    NiPointer<NiAVObject> spMesh; // src: XBOX_RETAIL_PDB +0x48 (old: m_spNode)
    NiPointer<NiAVObject> spNode; // src: XBOX_RETAIL_PDB +0x4c (old: m_spLand)
    unsigned char bCanceled; // src: XBOX_RETAIL_PDB +0x50 (old: m_bLoadComplete)
    union { bool m_bLOD; bool bSkipLoad; };
    unsigned char unk52[2];
    int unk54;
};
