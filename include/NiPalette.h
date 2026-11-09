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

    unsigned int m_bAlpha;
    unsigned int m_uiEntries;
    unsigned int m_uiRevID;
    unsigned int m_pkPalette;
    unsigned int m_pkRendererData;
    unsigned int m_pkPrev;
    unsigned int m_pkNext;
};
