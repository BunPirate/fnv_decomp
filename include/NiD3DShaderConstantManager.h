#pragma once
#include "NiRefObject.h"

// pdb: class NiD3DShaderConstantManager, size 0x88 (here 0x8), bases: NiRefObject, 32 members
class NiD3DShaderConstantManager : public NiRefObject
{
public:
    virtual ~NiD3DShaderConstantManager();
    virtual void vf02();

    void* __thiscall Destroy(unsigned int flags);
};
