#pragma once

#include "TESTexture.h"

// pdb: class TESIcon, size 0xc, bases: TESTexture, 0 members
class TESIcon : public TESTexture
{
public:
    TESIcon();
    ~TESIcon();

    virtual char* GetTextureResourcePath();
};
