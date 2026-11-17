#pragma once

// RTTI: no bases, vftable 0x010c1844 (slot 0 destructor 0x00c3f130, slot 1 pure); constructor 0x00c42dd0,
// destructor 0x00c42f00. Size 0x30 (BackgroundCloneThread's own members start there).
// pdb: class BSTaskThread, size 0x30, 5 members
class BSTaskThread
{
public:
    // Semaphore built inline by the constructor (count, CreateSemaphore handle, maximum).
    struct Semaphore
    {
        long iCount;
        void* hSemaphore;
        long iMaxCount;
    };

    BSTaskThread(unsigned int aiProcessor, const char* apThreadName);
    virtual ~BSTaskThread();

    void* hThreadHandle; // src: XBOX_RETAIL_PDB +0x4 (old: hThread)
    unsigned int iThreadID; // src: XBOX_RETAIL_PDB +0x8 (old: uiThreadID)
    Semaphore kStartSemaphore;
    Semaphore PauseSemaphore; // src: XBOX_RETAIL_PDB +0x18 (old: kDoneSemaphore)
    int HavokThreadMemory; // src: XBOX_RETAIL_PDB +0x24 (old: unk24)
    int unk28;
    unsigned int uiOwnerThreadID;
};
