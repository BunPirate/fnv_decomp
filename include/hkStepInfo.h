#pragma once
#include <stddef.h>
#include "hkPadSpu.h"   // Havok 7.1 hkPadSpu<T> (hkBaseTypes.h:692; PC: a bare T m_storage)

// Havok 7.1 Common/Base/Types/Physics/hkStepInfo.h: four hkPadSpu members, the first HK_ALIGN16, sizeof == 16.
// Havok names: m_startTime, m_endTime, m_deltaTime, m_invDeltaTime (the units use the names below).
// HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR: operator new/delete are declared here; a unit that allocates one defines
// them out of class (__forceinline, thread-memory heap), as the units did.
// pdb: class hkStepInfo, size 0x10, 4 members
class hkStepInfo
{
  public:
    void* __cdecl operator new(size_t nbytes);
    void __cdecl operator delete(void* p);

    hkStepInfo() {}
    void set(float startTime, float endTime)
    {
        m_startTime = startTime;
        m_endTime = endTime;
        m_deltaTime = endTime - startTime;
        m_invDeltaTime = m_deltaTime == 0.0f ? 0.0f : 1.0f / m_deltaTime;
    }
    hkStepInfo(float startTime, float endTime) { set(startTime, endTime); }

  public:
    __declspec(align(16)) hkPadSpu<float> m_startTime;   // hkPadSpu<hkTime> m_startTime
    hkPadSpu<float> m_endTime;                            // hkPadSpu<hkTime> m_endTime
    hkPadSpu<float> m_deltaTime;                           // hkPadSpu<hkReal> m_deltaTime
    hkPadSpu<float> m_invDeltaTime;                   // hkPadSpu<hkReal> m_invDeltaTime
};
