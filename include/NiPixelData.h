#pragma once

#include "NiObject.h"
#include "NiPixelFormat.h"
#include "NiPalettePointer.h"
#include "NiPalette.h"
#include <stddef.h>

// pdb: class NiPixelData, size 0x74, bases: NiObject, 11 members
class NiPixelData : public NiObject
{
public:
    NiPixelData(unsigned int uiWidth, unsigned int uiHeight, const NiPixelFormat& kFormat,
                unsigned int uiMipmapLevels = 1, unsigned int uiFaces = 1);
    NiPixelData(unsigned int uiWidth, unsigned int uiHeight, const NiPixelFormat* kFormat,
                unsigned int uiMipmapLevels, unsigned int uiFaces);
    virtual ~NiPixelData();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& kStream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    static unsigned int CalculateMipmapLevels(unsigned int width, unsigned int height);
    void NiPixelData_AllocateData(unsigned int uiLevels, unsigned int uiFaces, unsigned int uiBytes);
    NiPalette* GetPalette() const throw();
    void SetPalette(NiPalette* palette);
    void SetOwnsPixelData(bool value) { bNoConvert = value; }
    unsigned int GetWidth(unsigned int level = 0) const throw()
    {
        return m_puiWidth[level];
    }
    unsigned int GetHeight(unsigned int level = 0) const throw()
    {
        return m_puiHeight[level];
    }
    const unsigned char* GetPixels(unsigned int level, unsigned int face) const throw()
    {
        return m_pucPixels + m_puiOffsetInBytes[level] + face * m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    unsigned char* GetPixels(unsigned int level, unsigned int face)
    {
        return m_pucPixels + m_puiOffsetInBytes[level] + face * m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    unsigned char* GetPixels();
    unsigned int GetSizeInBytes(unsigned int level) const throw()
    {
        return m_puiOffsetInBytes[level + 1] - m_puiOffsetInBytes[level];
    }
    unsigned char* Pixels()
    {
        return m_pucPixels + m_puiOffsetInBytes[0];
    }
    void AddString();
    void NiPixelData_SetPalette(NiPalette* palette);
    NiPixelData* NiPixelData_00a7c030(const NiPixelData& source);
    unsigned char* NiPixelData_GetPixels(unsigned int level, unsigned int face);
    unsigned char* NiPixelData_GetPixels(int level, int face);
    void* NiPixelData_GetPixels(int level, int face, unsigned int size);
    void FUN_004f31b0();

    NiPixelFormat m_kPixelFormat;
    NiPalettePointer m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
    unsigned int m_uiFaces;
    bool bNoConvert; // src: XBOX_RETAIL_PDB +0x70 (old: m_bOwnsPixelData)
    unsigned char m_ucUnknownByte[3];
};
