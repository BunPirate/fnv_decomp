#pragma once

#include "BSThreadCriticalSectionPC.h"

// pdb: class BSThread, size 0x34 (here 0x30), 6 members
class BSThread
{
public:
    enum StackSize  // values: Xbox PDB BSThread::StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };

    BSThread();
    virtual ~BSThread();
    virtual unsigned int ThreadProc();

    void Initialize(StackSize aeStackSize, const char* apName, bool bSuspend);
    void Initialize(int aeStackSize, const char* apName, bool bSuspend);
    void SetThreadPriority(int aiPriority);
    void SetSchedulingPriority(unsigned int priority);
    void SetSchedulingPriority(int priority);
    void SetName(const char* apName);
    void SetPriority(int priority);
    void Wakeup();
    void Run();
    unsigned int GetThreadID();
    bool TESAnimGroup_GetDecal();
    void FUN_00aa6430(int aeStackSize, const char* apName, bool bSuspend);
    void FUN_00aa6540(const char* apName);
    void FUN_00aa6550(unsigned int priority);
    void FUN_00aa6550(int priority);
    void FUN_00aa6560(int aiPriority);

    BSThreadCriticalSectionPC CriticalSection;
    void* m_pThreadHandle;
    void* m_pCurrentThreadHandle;
    unsigned int m_uiCreatedThreadId;
    unsigned int m_uiCurrentThreadId;
    bool m_bThreadStarted;
    unsigned char unk2D[3];
};
