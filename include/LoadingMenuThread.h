#pragma once

#include "BSThread.h"
#include "CountingSemaphore.h"

// pdb: class LoadingMenuThread, size 0x50 (here 0x4c), bases: BSThread, 5 members
class LoadingMenuThread : public BSThread
{
public:
    CountingSemaphore m_kFirstSemaphore;
    CountingSemaphore m_kSecondSemaphore;
    volatile bool m_bFirstThreadFlag;
    volatile bool m_bSecondThreadFlag;
    volatile bool m_bThirdThreadFlag;

    LoadingMenuThread();
    virtual unsigned int ThreadProc();
};
