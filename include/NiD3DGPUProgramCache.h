#pragma once

#include "NiGPUProgramCache.h"

// pdb: class NiD3DGPUProgramCache, size 0x48 (here 0x3c), bases: NiGPUProgramCache, 3 members
class NiD3DGPUProgramCache : public NiGPUProgramCache
{
public:
    virtual ~NiD3DGPUProgramCache();
    virtual void vf38();

    static const char* GetVertexShaderProfile();
    static const char* GetPixelShaderProfile(bool usePixelLevel);
};
