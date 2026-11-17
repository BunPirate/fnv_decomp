#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkInspectProcess;
class hkProcess;

// pdb: class hkProcessFactory, size 0x1c (here 0x8), bases: hkReferencedObject, hkSingleton<hkProcessFactory>, 3 members
class hkProcessFactory : public hkReferencedObject, public hkSingleton<hkProcessFactory>
{
public:
    hkInspectProcess* __thiscall RegisterProcess(const char*, void (__cdecl*)(hkProcess*));
    void* RegisterProcess(const char*, void*);
};
