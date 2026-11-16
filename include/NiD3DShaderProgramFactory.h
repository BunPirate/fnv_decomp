#pragma once

#include "NiRefObject.h"
#include "NiTPointerList.h"

class NiD3DShaderProgramCreator;
struct ShaderBufferRecord;
template <class TVAL> class NiTStringPointerMap;

// pdb: class NiD3DShaderProgramFactory, size 0x1c, bases: NiRefObject, 3 members
class NiD3DShaderProgramFactory : public NiRefObject
{
public:
    NiTPointerList<char*> m_kProgramDirectories; // src: XBOX_RETAIL_PDB +0x8 (old: m_kDirectoryList)
    NiTStringPointerMap<ShaderBufferRecord*>* m_pkVertexShaderMap; // src: XBOX_RETAIL_PDB +0x14 (old: m_pVertexShaderMap)
    union
    {
        NiTStringPointerMap<ShaderBufferRecord*>* m_pPixelShaderMap;
        NiTStringPointerMap<ShaderBufferRecord*>* m_pShaderBufferMap;
    };

    char* GetFirstName(void**);
    const char* GetNextName(void*&);
    void NiD3DShaderProgramFactory_AddProgramDirectory(const char* pacDirectory);
    void NiD3DShaderProgramFactory_RemoveProgramDirectory(const char*);
    void RemoveDirectoryEntry(const char* pcDirectory);
    ShaderBufferRecord* __thiscall FindVertexShader(const char* pcShaderName);
    ShaderBufferRecord* __thiscall FindPixelShader(const char* pcShaderName);

    static bool __cdecl RegisterCreator(const char*, NiD3DShaderProgramCreator*);
    static void CreateFactoryInstance();
};
