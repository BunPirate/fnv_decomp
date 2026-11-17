#pragma once

#include "TESTexture.h"

// pdb: class TESTexture1024, size 0xc, bases: TESTexture, 0 members
class TESTexture1024 : public TESTexture
{
public:
    TESTexture1024();
    ~TESTexture1024();

    unsigned int GetModelLength() const;
    const char* GetTextureResourceName();
    void SetTexture(const char* apFullName);
};
