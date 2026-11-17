#pragma once

#include <windows.h>
#include "hkReferencedObject.h"
#include "hkSingleton.h"

// pdb: class hkReferencedObjectLock, size 0x34 (here 0x30), bases: hkReferencedObject, hkSingleton<hkReferencedObjectLock>, 4 members
class hkReferencedObjectLock : public hkReferencedObject, public hkSingleton<hkReferencedObjectLock>
{
public:
    hkReferencedObjectLock() throw();
    void ReleaseReference() throw();

    int m_multiThreaded;
    int m_lLockCount;
    int unk10;
    int unk14;
    CRITICAL_SECTION m_kCriticalSection;
};
