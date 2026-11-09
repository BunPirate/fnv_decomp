#pragma once

#include "NiObject.h"

// pdb: class NiStringPalette, size 0x14 (here 0xc), bases: NiObject, 3 members
class NiStringPalette : public NiObject
{
public:
    char* m_pString;
};
