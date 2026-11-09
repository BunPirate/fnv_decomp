#pragma once

#include "BSLinearTaskThread.h"
#include "hkMemoryRouter.h"

// pdb: class AILinearTaskThread, size 0x7c (here 0x78), bases: BSLinearTaskThread, 3 members
class AILinearTaskThread : public BSLinearTaskThread
{
public:
    AILinearTaskThread(void(__cdecl* apfnTaskFunc)());
    virtual ~AILinearTaskThread();

    void StartTaskThread();
    void ExecuteTask();

    void(__cdecl* m_pTaskFunction)();
    hkMemoryRouter ThreadMemory;
    void* m_pTaskMemory;
};
