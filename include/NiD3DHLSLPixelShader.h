#pragma once

#include "NiD3DPixelShader.h"

class ID3DXConstantTable;

// pdb: class NiD3DHLSLPixelShader, size 0x3c, bases: NiD3DPixelShader, 3 members
class NiD3DHLSLPixelShader : public NiD3DPixelShader
{
public:
    NiD3DHLSLPixelShader(NiD3DRenderer* pkRenderer) throw();
    NiD3DHLSLPixelShader(void* pkRenderer) throw();

    virtual ~NiD3DHLSLPixelShader();
    virtual void* GetRTTI();
    virtual unsigned int GetNumberOfVariables();
    virtual char* GetVariableName(unsigned int);
    virtual bool SetShaderConstant(NiShaderConstantMapEntry*, void*, unsigned int);
    virtual bool SetShaderConstantArray(NiShaderConstantMapEntry*, void*, unsigned int,
                                        unsigned int, unsigned short*);
    virtual void UnloadShader();
    virtual void BuildVertexShader();

    virtual void vf35();
    virtual void SetEntryPoint(const char* pcEntryPoint);
    virtual unsigned int vf37();
    virtual void SetPixelShaderTarget(const char* pcShaderTarget);
    virtual ID3DXConstantTable* vf39();
    virtual void SetShaderInterface(ID3DXConstantTable* pkTable);

    void __thiscall UpdateState_00e96c90();
    void* __thiscall FUN_00e95cd0(unsigned int flags);
    unsigned int GetVariableCount();
    void SetEntryPoint_00e95cf0(const char* pcEntryPoint);
    unsigned int __thiscall NiD3DVertexShader_GetShaderHandle();
    void __thiscall SetShaderTarget(const char* pcShaderTarget);
    void __thiscall AssignTable(ID3DXConstantTable* pkTable);
    void* __thiscall DestroyPixelShader(unsigned int flags);
    ID3DXConstantTable* GetShaderConstantTable();


    const char* m_pcEntryPoint; // src: XBOX_RETAIL_PDB +0x30 (old: m_pcShaderEntryPoint)
    const char* m_pcShaderTarget; // src: XBOX_RETAIL_PDB +0x34 (old: m_pcShaderProfile)
    ID3DXConstantTable* m_pkConstantTable; // src: XBOX_RETAIL_PDB +0x38 (old: m_pShaderConstantTable)
};
