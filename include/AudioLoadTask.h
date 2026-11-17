#pragma once

#include "QueuedFileEntry.h"

#pragma pack(push, 4)
// pdb: class AudioLoadTask, size 0x38 (here 0x34), bases: QueuedFileEntry, 1 members
class AudioLoadTask : public QueuedFileEntry
{
public:
    virtual ~AudioLoadTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE aePreviousState, void* apTaskOwner);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual unsigned char GetFileIndex();

    void __thiscall DestroyFields_00ae7020();
    void __thiscall Finish_00ae7360();
    void* __thiscall FUN_00ae7b10(unsigned int flags);

    void* SoundAssetTmp;
};
#pragma pack(pop)
