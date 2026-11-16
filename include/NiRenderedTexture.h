#pragma once

#include <windows.h>
#include <d3d9.h>
#include "NiTexture.h"
#include "Ni2DBuffer.h"
#include "NiAVObject.h"

class NiRenderer;

// pdb: class NiRenderedTexture, size 0x48, bases: NiTexture, 7 members
class NiRenderedTexture : public NiTexture
{
  public:
    NiRenderedTexture() throw();
    virtual ~NiRenderedTexture();
    virtual int vf41();

    void vfn_0();
    void vfn_4();
    NiRTTI* GetType();
    bool IsExactKindOf(const NiRTTI* type);

    static NiRenderedTexture* Create(const NiFixedString&, unsigned int, unsigned int, NiRenderer*,
                                     NiTexture::TextureFormatPreferences&, Ni2DBuffer::MultiSamplePreference,
                                     NiRenderedTexture*, unsigned int);

    NiPointer<Ni2DBuffer> m_spRenderTargetBuffer;
    unsigned int uiAliasOffset; // src: XBOX_RETAIL_PDB +0x34 (old: m_uiAliasOffset)
    NiRenderedTexture* pAliasTexture; // src: XBOX_RETAIL_PDB +0x38 (old: m_pReuseTexture)
    Ni2DBuffer::MultiSamplePreference eMSAA; // src: XBOX_RETAIL_PDB +0x3c (old: m_eMultiSamplePreference)
    bool bRenderedTexture; // src: XBOX_RETAIL_PDB +0x40 (old: m_bUseMipMaps)
    bool bForceD3DFormat; // src: XBOX_RETAIL_PDB +0x41 (old: m_bUseDepthBuffer)
    _D3DFORMAT m_ePixelFormat;

    static bool ms_bUseMipMaps;
    static bool ms_bUseDepthBuffer;
    static _D3DFORMAT ms_eDepthStencilFormat;
};
