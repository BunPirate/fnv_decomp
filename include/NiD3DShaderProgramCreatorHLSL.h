#pragma once

#include "NiD3DShaderProgramCreator.h"

class ID3DXConstantTable;

// pdb: class NiD3DShaderProgramCreatorHLSL, size 0x8, bases: NiD3DShaderProgramCreator, 1 members
class NiD3DShaderProgramCreatorHLSL : public NiD3DShaderProgramCreator
{
public:
    virtual ~NiD3DShaderProgramCreatorHLSL();
    virtual void vf09();
    virtual void vf10();

    void* Destroy(unsigned int flags);
    void SetCompileFlags(unsigned int uiFlags);
    bool LoadShaderCodeFromBuffer(const void* pvBuffer, unsigned int uiBufferSize,
                                 const char* pcEntryPoint, const char* pcShaderTarget,
                                 void*& pvCode, unsigned int& uiCodeSize,
                                 ID3DXConstantTable*& pkConstantTable, bool bRecoverable);

    unsigned int m_uiShaderCreationFlags; // src: XBOX_RETAIL_PDB +0x4 (old: m_uiCompileFlags)
};
