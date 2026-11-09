#pragma once

#include "NiRenderedTexture.h"

// pdb: class NiRenderedCubeMap, size 0x64, bases: NiRenderedTexture, 2 members
class NiRenderedCubeMap : public NiRenderedTexture
{
  public:
    NiRenderedCubeMap() throw();
    virtual ~NiRenderedCubeMap();

    void __thiscall ReleaseReference_00ee82b0();

    static NiRenderedCubeMap* Create_00ee8330(unsigned int uiFaceSize, NiRenderer* pkRenderer,
                                         NiTexture::TextureFormatPreferences& kPrefs);

    int m_eFace;
    void* m_ppCubeMapFaces[6];
};
