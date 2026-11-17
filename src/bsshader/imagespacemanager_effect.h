#ifndef IMAGESPACEMANAGER_EFFECT_H
#define IMAGESPACEMANAGER_EFFECT_H
// Declaration-only virtual prefix: JIP LN NVSE internal/netimmerse.h,
// ImageSpaceEffect (PC 1.4.0.525). No object is instantiated here.
// Retained locally: include/ has no ImageSpaceEffect definition yet.
class NiDX9Renderer;
// pdb: class ImageSpaceEffect, size 0x58 (here 0x4), 7 members
class ImageSpaceEffect
{
  public:
    virtual void Destroy(bool doFree);
    virtual void RenderShader(NiGeometry*, NiDX9Renderer*, ImageSpaceEffectParam*, bool);
    virtual void Setup(ImageSpaceManager*, ImageSpaceEffectParam*);
    virtual void Shutdown();
    virtual void BorrowTextures(ImageSpaceEffectParam*);
    virtual void ReturnTextures();
    virtual bool IsActive();
    virtual bool UpdateParams(ImageSpaceEffectParam*);
};
#endif
