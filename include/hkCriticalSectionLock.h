#pragma once

#include "hkCriticalSection.h"

// pdb: class hkCriticalSectionLock, size 0x4, 1 members
class hkCriticalSectionLock
{
public:
    hkCriticalSection* m_section; // src: XBOX_RETAIL_PDB +0x0 (old: m_kCriticalSection)

    hkCriticalSectionLock(hkCriticalSection* pkSection);
    hkCriticalSectionLock(void* section);
    ~hkCriticalSectionLock();
};
