#pragma once

#include <windows.h>

class NiRenderTargetGroup;
class NiRenderedTexture;

// pdb: class BSRenderedTexture, size 0x40, bases: NiObject, 6 members
class BSRenderedTexture
{
  public:
    unsigned char base[8];
    NiRenderTargetGroup* spGroup[6];
    char spPreRestoreGroup[4];
    char spRestoreGroup[4];
    char spPostRestoreGroup[4];
    int iAliasedType;
    NiRenderedTexture* spTexture[4];

    NiRenderTargetGroup* GetGroup();
    static void __cdecl EndAllAndResetRendererState();
    static void EndAll();
    void* BSRenderedTexture_GetTexture();
    void __thiscall TESMain_DrawWorld_StopRenderTarget(int, int);
    void IncRefCount();
};
