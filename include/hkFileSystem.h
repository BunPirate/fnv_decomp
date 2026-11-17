#pragma once

#include "hkReferencedObject.h"
#include "hkSingleton.h"

class hkStreamWriter;

// pdb: class hkFileSystem, size 0x8, bases: hkReferencedObject, hkSingleton<hkFileSystem>, 0 members
class hkFileSystem : public hkReferencedObject, public hkSingleton<hkFileSystem>
{
public:
    virtual ~hkFileSystem();
    virtual const hkClass* getClassType() const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual void v0c();
    virtual hkStreamWriter* OpenWriter(const char* pcName) throw();
    virtual int return_1_0(const char*, void*);
};
