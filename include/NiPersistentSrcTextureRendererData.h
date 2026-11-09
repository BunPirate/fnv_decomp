#pragma once

#include "NiTexture.h"
#include "NiObject.h"
#include "NiPixelFormat.h"
#include "NiPalette.h"

class ViewerArray;

class NiTexture::RendererData : public NiObject
{
public:
    virtual ~RendererData();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();

    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    NiPixelFormat m_kPixelFormat;
    unsigned char DegradePriorityRange[8];
};

// pdb: class NiPersistentSrcTextureRendererData, size 0x94, bases: NiTexture::RendererData, 13 members
class NiPersistentSrcTextureRendererData : public NiTexture::RendererData
{
public:
    virtual ~NiPersistentSrcTextureRendererData();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void AllocateMipMap(unsigned int levels, unsigned int faces, unsigned int bytes);
    virtual void FreePixelData();

    void LinkPalette(NiStream& stream);
    void AppendToStrings(ViewerArray* pkStrings);
    bool RegisterStreamables_00a98170(NiStream& stream);
    bool IsEqual_00a982f0(NiObject* object);
    void FUN_00a984b0(NiStream& stream);
    unsigned int GetWidth(unsigned int level = 0) const;
    unsigned int GetHeight(unsigned int level = 0) const;
    const unsigned int& GetMipmapLevels() const;
    const unsigned int& GetFaces() const;
    unsigned int GetTotalSizeInBytes() const;
    unsigned int GetFaceSizeInBytes() const;

    static NiRTTI ms_kRTTI;

    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiPadOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiFaces;
    int m_eTargetPlatform;
    unsigned char* m_pucPristinePixels;
    unsigned int m_uiPristineMaxOffsetInBytes;
    unsigned int m_uiPristinePadOffsetInBytes;
    NiPalette* m_spPalette;
};
