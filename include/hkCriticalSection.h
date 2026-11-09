#pragma once

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void* cs);

// pdb: class hkCriticalSection, size 0x1c (here 0x18), 1 members
class hkCriticalSection
{
public:
    int m_kCriticalSection[6];

    void enter()
    {
        EnterCriticalSection(&m_kCriticalSection);
    }

    void leave()
    {
        LeaveCriticalSection(&m_kCriticalSection);
    }
};
