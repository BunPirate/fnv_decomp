#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "ByteFlags.h"

// pdb: class TESRecipeCategory, size 0x28, bases: TESForm, TESFullName, 1 members
class TESRecipeCategory : public TESForm, public TESFullName
{
public:
    ByteFlags data;
    unsigned char layoutPadding25[3];

    virtual bool LoadForm(TESFile* file);
    bool Load(TESFile* apFile);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short asSize);
};
