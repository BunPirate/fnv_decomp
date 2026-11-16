#pragma once

#include "NiObject.h"
#include <stddef.h>

// pdb: class NiPalette, size 0x24, bases: NiObject, 7 members
class NiPalette : public NiObject
{
public:
    struct PaletteColorEntry
    {
        unsigned char r, g, b, a;
    };

    NiPalette(const NiPalette& src) throw();
    NiPalette(bool, unsigned int, const PaletteColorEntry*) throw();
    virtual ~NiPalette();
    virtual void DeleteThis();


    unsigned int GetEntries(PaletteColorEntry*& entries) const throw();
    PaletteColorEntry* GetEntries(unsigned int& count) const throw();
    void IncRefCount();
    void DecRefCount();
    void* DestroyPalette(unsigned int);

    unsigned int m_bAlpha; // src: XBOX_RETAIL_PDB +0x8 (old: unk08)
    unsigned int m_uiEntries; // src: XBOX_RETAIL_PDB +0xc (old: unk0C)
    unsigned int m_uiRevID; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    unsigned int m_pkPalette; // src: XBOX_RETAIL_PDB +0x14 (old: unk14)
    unsigned int m_pkRendererData; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)
    unsigned int m_pkPrev; // src: XBOX_RETAIL_PDB +0x1c (old: unk1C)
    unsigned int m_pkNext; // src: XBOX_RETAIL_PDB +0x20 (old: unk20)
};
