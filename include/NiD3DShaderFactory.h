#pragma once

#include "NiShaderFactory.h"

class GraphicsRenderer;

// pdb: class NiD3DShaderFactory, size 0x100, bases: NiShaderFactory, 5 members
class NiD3DShaderFactory : public NiShaderFactory
{
public:
    virtual void vfn_70(GraphicsRenderer*);
    virtual void vf29();
    virtual void vf30();

    static NiD3DShaderFactory* GetShaderFactory();
    void ShutdownPoint3();
    static void __cdecl _SDMInit();
    void UpdateShaderMaterialCache(void*);
    void NiDX9MaterialManager_UpdateToDevice(void*);
    void FUN_00aa0390();
    NiShaderFactory* Create();

    void* m_pkRenderer; // src: XBOX_RETAIL_PDB +0x24 (old: m_pOwnerShader)
    void* m_pkShaderMap; // src: XBOX_RETAIL_PDB +0x28 (old: m_pShaderMapStorage)
    void* m_kLibraryIter; // src: XBOX_RETAIL_PDB +0x2c (old: m_pShaderLibraryIterator)
    void* m_pkLibraryMap; // src: XBOX_RETAIL_PDB +0x30 (old: m_pShaderLibraryStorage)
    unsigned char unk34[0x4C];
    unsigned char m_kShaderMapLock[0x80]; // src: XBOX_RETAIL_PDB +0x80 (old: m_kShaderMap)
};
