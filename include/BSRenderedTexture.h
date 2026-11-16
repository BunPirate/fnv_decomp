#pragma once

#include <windows.h>

class NiRenderTargetGroup;
class NiRenderedTexture;

// pdb: class BSRenderedTexture, size 0x40, bases: NiObject, 6 members
class BSRenderedTexture
{
  public:
    unsigned char base[8];
    NiRenderTargetGroup* spGroup[6]; // src: XBOX_RETAIL_PDB +0x8 (old: m_apRenderTargetGroups)
    char spPreRestoreGroup[4]; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
    char spRestoreGroup[4]; // src: XBOX_RETAIL_PDB +0x24 (old: m_acDataAtOffset36)
    char spPostRestoreGroup[4]; // src: XBOX_RETAIL_PDB +0x28 (old: m_acDataAtOffset40)
    int iAliasedType; // src: XBOX_RETAIL_PDB +0x2c (old: m_iDataAtOffset44)
    NiRenderedTexture* spTexture[4];

    NiRenderTargetGroup* GetGroup();
    static void __cdecl EndAllAndResetRendererState();
    static void EndAll();
    void* BSRenderedTexture_GetTexture();
    void __thiscall TESMain_DrawWorld_StopRenderTarget(int, int);
    void IncRefCount();
};
