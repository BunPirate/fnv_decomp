#pragma once

#include "NiObject.h"
#include "NiMemObject.h"
#include "NiAVObject.h"

class Ni2DBuffer;
class NiDepthStencilBuffer;
class NiPixelFormat;

// pdb: class NiRenderTargetGroup, size 0x30, bases: NiObject, 8 members
class NiRenderTargetGroup : public NiObject
{
  public:
    class RendererData;
    NiRenderTargetGroup();
    virtual ~NiRenderTargetGroup();
    NiRenderTargetGroup& operator=(const NiRenderTargetGroup&);
    void* __thiscall FUN_00ee87e0(unsigned int flags);

    virtual unsigned int Unk_23(unsigned int);
    virtual void* vf36(unsigned int);
    virtual int GetDepthStencilWidth() const;
    virtual int GetDepthStencilHeight() const;
    virtual void* vf39(unsigned int);
    virtual const NiPixelFormat* __thiscall GetPixelFormat() const;
    virtual void vf41();
    virtual void vf42(void* a, int b);
    virtual bool __thiscall SetDepthStencilBuffer(NiDepthStencilBuffer* pkDepthBuffer);
    virtual NiMemObject* __thiscall GetBuffer_00ee84f0(unsigned int uiIndex) const;
    virtual void vf45();
    virtual void vf46();
    virtual void __thiscall SetResolveDepthBufferMode(bool abResolve);
    virtual void vf48();
    virtual void SetRendererData_00ee8460(RendererData* pkRendererData);
    virtual void* GetBufferRendererData(unsigned int uiIndex) const;
    virtual void vf51();

    NiMemObject** GetBuffers()
    {
        return reinterpret_cast<NiMemObject**>(&uiDepthBase);
    }

    NiMemObject* const* GetBuffers() const
    {
        return reinterpret_cast<NiMemObject* const*>(&uiDepthBase);
    }

    NiDepthStencilBuffer*& GetDepthStencilBuffer()
    {
        return reinterpret_cast<NiDepthStencilBuffer*&>(m_aspBuffers[3].m_pObject);
    }

    NiDepthStencilBuffer* const& GetDepthStencilBuffer() const
    {
        return reinterpret_cast<NiDepthStencilBuffer* const&>(m_aspBuffers[3].m_pObject);
    }

    bool bForceNoMSAASurface;
    bool bAddDSRestoreSurface;
    unsigned char layoutPaddingA[2];
    unsigned int uiDepthBase;
    bool bResolveDepth;
    unsigned char layoutPadding11[1];
    unsigned short RenderBufferSet;
    NiPointer<Ni2DBuffer> m_aspBuffers[4];
    unsigned int m_uiNumBuffers;
    NiPointer<NiDepthStencilBuffer> m_spDepthStencilBuffer;
    RendererData* m_pkRendererData;
};

#include "NiRenderTargetGroup_RendererData.h"
