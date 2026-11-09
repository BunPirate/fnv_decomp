#pragma once

#include "NiShader.h"

// pdb: class NiFragmentShaderInstanceDescriptor, size 0x18 (here 0x8), bases: NiShader::NiShaderInstanceDescriptor, 1 members
class NiFragmentShaderInstanceDescriptor : public NiShader::NiShaderInstanceDescriptor
{
public:
    virtual void* vf00();
    virtual void* __thiscall vf16(unsigned int flags);

    void* __thiscall FUN_00e8d540(unsigned int flags);

    void* m_pDescriptorData;
};
