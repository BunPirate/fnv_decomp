#pragma once

#include "NiD3DShaderInterface.h"
#include "NiAVObject.h"

class D3DRenderStateGroup;
class NiD3DPass;
class NiD3DShaderConstantMap;

// pdb: class NiD3DShader, size 0x3c, bases: NiD3DShaderInterface, 7 members
class NiD3DShader : public NiD3DShaderInterface
{
public:
    NiD3DShader();
    virtual ~NiD3DShader();
    virtual bool Initialize();
    virtual void ResetPasses();

    NiD3DShader& operator=(const NiD3DShader&);
    void* DestroyIfFlagged(unsigned int);
    void __thiscall FUN_00e806c0();
    void __thiscall UpdateFields_00e7c540();
    static unsigned int IsRendererActive();
    static void __cdecl _SDMInit();

    union
    {
        struct
        {
            bool m_bUsesNiRenderState;
            bool m_bUsesNiLightState;
            unsigned char _pad26[2];
        };
        NiD3DPass** m_ppPasses;
    };
    NiPointer<NiD3DShaderDeclaration> m_spShaderDecl;
    D3DRenderStateGroup* m_pkRenderStateGroup;
    NiPointer<NiD3DShaderConstantMap> m_spPixelConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spVertexConstantMap;
    unsigned int m_uiCurrentPass;
};
