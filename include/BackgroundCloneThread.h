#pragma once

#include "BSTaskThread.h"

class Q449;

// pdb: class BackgroundCloneThread, size 0x3c, bases: BSTaskThread, 3 members
class BackgroundCloneThread : public BSTaskThread
{
public:
    BackgroundCloneThread(unsigned int aiMaxThreads);
    virtual ~BackgroundCloneThread();
    virtual void RunBackgroundClone();

    void* __thiscall FUN_00442290(unsigned int flags);

    bool bExit;
    int iRunningCount;
    Q449* pCloneReferencesQueue;
};
