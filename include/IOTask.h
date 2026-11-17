#pragma once

#include "BSTask.h"

enum IO_TASK_PRIORITY;
class RefObj;

// pdb: class IOTask, size 0x18, bases: BSTask<__int64>, 0 members
class IOTask : public BSTask<__int64>
{
public:
    IOTask(IO_TASK_PRIORITY aePriority);
    IOTask(int aePriority);
    virtual ~IOTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);

    void ChangePriority(int priority);
    void SetIOTaskPriority(IO_TASK_PRIORITY aePriority);
    unsigned char GetPriority();
    void SetKey(char, unsigned int, unsigned char, unsigned short);
    unsigned int InitScriptRunLockTask();
    void NotifyParents();
    void AddToPostProcessQueue();
    RefObj* GetCur();
    void SetState(long state);
    void AcquireReference();
    void QueuedFileEntry_GenerateKey();
    bool BSTask_int64_GetTaskFinished();
    bool BSTask_int64_GetTaskCanceled();
    bool QueuedFile_GetAllChildrenFinished();
    bool QueuedModel_GetFinishedQueuing();
    IO_TASK_PRIORITY IOTask_GetIOTaskPriority();
    unsigned short IOTask_GetNextCounter();
    void BSTask_int64_DecRefCount();
    void QueuedFile_Cancel(int aePreviousState, RefObj* apTaskOwner);
    void QueuedFile_AddAdditionalParent(RefObj* apAdditionalParent);

    static unsigned char GetPriorityFromKey(__int64& key);
};
