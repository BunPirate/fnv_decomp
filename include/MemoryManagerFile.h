#pragma once

#include "IMemoryManagerFile.h"

// pdb: class MemoryManagerFile, size 0x2c (here 0x4), bases: IMemoryManagerFile, 1 members
class MemoryManagerFile : public IMemoryManagerFile
{
public:
    int __thiscall Read(void* apData, unsigned int aSize);
    virtual int __thiscall Write(const void* apData, unsigned int aSize);
    virtual void __thiscall vf04(int aiPos);
};
