#pragma once

#include "BSThread.h"
#include "BSSemaphore_adf080.h"

// pdb: class BSAudioManagerThread, size 0x50 (here 0x4c), bases: BSThread, 3 members
class BSAudioManagerThread : public BSThread
{
public:
    BSAudioManagerThread();
    virtual ~BSAudioManagerThread();
    virtual unsigned int ThreadProc();

    void __thiscall ForwardCall_00aa6590(int, int);
    void ExitThread_00ae7ac0();
    void Suspended();

    BSSemaphore_adf080 doneSemaphore30;
    unsigned int unk38;
    BSSemaphore_adf080 workSemaphore3c;
    unsigned int unk44;
    bool waiting48;
};
