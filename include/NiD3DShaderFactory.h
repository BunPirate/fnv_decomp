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

    void* m_pkRenderer;
    void* m_pkShaderMap;
    void* m_kLibraryIter;
    void* m_pkLibraryMap;
    unsigned char unk34[0x4C];
    unsigned char m_kShaderMapLock[0x80];
};
