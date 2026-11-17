#pragma once

#include "QueuedFileEntry.h"

class LoadedFile;

// pdb: class QueuedFileLoad, size 0x38, bases: QueuedFileEntry, 2 members
class QueuedFileLoad : public QueuedFileEntry
{
public:
    virtual ~QueuedFileLoad();
    virtual void Run();
    virtual void Finish();
    virtual void DispatchToManager();
    virtual unsigned char GetFileIndex();

    LoadedFile* GetLoadedFile();
    void FUN_00441d20();
    void* FUN_00441cf0(unsigned int flags);

    char spLoadedFile[4]; // src: XBOX_RETAIL_PDB +0x30 (old: m_pLoadedFile)
    union
    {
        int m_iLoadPriority;
        unsigned char fileIndex;
    };
};
