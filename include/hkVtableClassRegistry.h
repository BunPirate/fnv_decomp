#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkClass;

// pdb: class hkVtableClassRegistry, size 0x14 (here 0x8), bases: hkReferencedObject, hkSingleton<hkVtableClassRegistry>, 1 members
class hkVtableClassRegistry : public hkReferencedObject, public hkSingleton<hkVtableClassRegistry>
{
public:
    virtual void RegisterVtable(const void*, const hkClass*);
    virtual const hkClass* GetClassFromVirtualInstance(const void*) const;
    virtual void vf05();

    unsigned long LookupClassByVtable(const unsigned long* p);
};
