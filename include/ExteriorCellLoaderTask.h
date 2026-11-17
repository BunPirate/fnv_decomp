#pragma once

#include "IOTask.h"

// pdb: class ExteriorCellLoaderTask, size 0x20 (here 0x18), bases: IOTask, 2 members
class ExteriorCellLoaderTask : public IOTask
{
public:
    virtual ~ExteriorCellLoaderTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE aePreviousState, void* apTaskOwner);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);

    void Finish_00527ce0();
};
