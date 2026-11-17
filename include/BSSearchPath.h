#pragma once

#include "NiSearchPath.h"

// pdb: class BSSearchPath, size 0x210, bases: NiSearchPath, 0 members
class BSSearchPath : public NiSearchPath
{
public:
    virtual ~BSSearchPath();
    virtual bool ResolveSearchPath(char* pcPath, unsigned int uiStringLen);
    virtual bool Access_00b013e0(char* apFile);

    static void* operator new(unsigned int uiSize);

    void SetVptr00();
    void* FUN_00b01480(unsigned int flags);
};
