// bscore/console/bsthread_console.cpp: BSThread (8 functions)

#include "bsthread_console_pc.h"

// @fnv 0x00aa6550
void BSThread::SetSchedulingPriority(unsigned int argument0)
{}

#include "bsthread_console_pc.h"

// @fnv 0x00ad87c0
// pdb: BSThread::ThreadProc | BSThread_Xenon.obj | debug, upstream name already matches, high
unsigned int BSThread::ThreadProc()
{
    return 0;
}

#include "bsthread_console_pc.h"

// @fnv 0x00aa6540
// pdb: BSThread::SetName | BSThread_Xenon.obj | debug, upstream name already matches, high
// pdb params: apName
void BSThread::SetName(const char* apName)
{}

// Creates the thread once, records its handle and id, sets its priority, and resumes it under the critical section.
// @fnv 0x00aa6430
// pdb: BSThread::Initialize | BSThread_Xenon.obj | retail, upstream name already matches, high
// pdb params: aeStackSize, apName, bSuspend
// pdb locals: result
void BSThread::Initialize(StackSize aeStackSize, const char* apName, bool bSuspend)
{
    if (m_pThreadHandle)
        return;

    m_pCurrentThreadHandle = GetCurrentThread();
    m_uiCurrentThreadId = GetCurrentThreadId();
    m_pThreadHandle = CreateThread(0, aeStackSize, RunThreadProc, this, bSuspend ? 4 : 0, &m_uiCreatedThreadId);
    fnv_EnterCriticalSection(&CriticalSection);
    SetThreadPriority(-1);
    m_bThreadStarted = true;
    unsigned long previousSuspendCount = ResumeThread(m_pThreadHandle);
    fnv_LeaveCriticalSection(&CriticalSection);
}

// @fnv 0x00aa6360
// pdb: BSThread::BSThread | BSThread_Xenon.obj | retail, upstream name already matches, high
BSThread::BSThread()
{
    BSThreadCriticalSectionPC* criticalSection = &CriticalSection;
    DAT_00fdf054(criticalSection);
    m_pThreadHandle = 0;
    m_pCurrentThreadHandle = 0;
    m_uiCreatedThreadId = 0;
    m_uiCurrentThreadId = 0;
    m_bThreadStarted = false;
}

// If the stored thread handle is non-null, applies the given priority to it via SetThreadPriority.
// @fnv 0x00aa6560
// pdb: BSThread::SetThreadPriority | BSThread_Xenon.obj | debug, upstream name already matches, high
// pdb params: aiPriority
void BSThread::SetThreadPriority(int aiPriority)
{
    if (m_pThreadHandle)
        ::SetThreadPriority(m_pThreadHandle, aiPriority);
}

// @fnv 0x00aa64d0
unsigned long __stdcall RunThreadProc(void* thread)
{
    return static_cast<BSThreadEntryPC*>(thread)->ThreadProc();
}

struct CRITSEC
{
    int a[6];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITSEC*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITSEC*);
struct FUN_00aa64f0_t
{
    int vt;
    CRITSEC cs;
    void* handle;
    int pad[3];
    char running;
    void StopAndCloseHandle();
};
// If handle is set, clears running, closes handle under the critical section, and resets handle to 0.
// @fnv 0x00aa64f0
// pdb: BSThread::Close | BSThread_Xenon.obj | retail, call graph, high
void FUN_00aa64f0_t::StopAndCloseHandle()
{
    if (handle)
    {
        running = 0;
        EnterCriticalSection(&cs);
        CloseHandle(handle);
        handle = 0;
        LeaveCriticalSection(&cs);
    }
}
