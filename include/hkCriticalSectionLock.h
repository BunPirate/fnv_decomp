#pragma once

#include "hkCriticalSection.h"

// pdb: class hkCriticalSectionLock, size 0x4, 1 members
class hkCriticalSectionLock
{
public:
    hkCriticalSection* m_section;

    hkCriticalSectionLock(hkCriticalSection* pkSection);
    hkCriticalSectionLock(void* section);
    ~hkCriticalSectionLock();
};
