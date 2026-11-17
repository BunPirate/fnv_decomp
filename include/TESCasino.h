#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESModelTextureSwap.h"
#include "TESTexture.h"
#include "EndianConvertibleData.h"

// pdb: class TESCasino, size 0x220, bases: TESForm, TESFullName, 3 members
class TESCasino : public TESForm, public TESFullName
{
public:
    TESCasino();

    bool Load(TESFile* apFile);
    // TESForm vtable slot 8 (vftable 0x1026574 slot 8 = 0x5048d0)
    bool LoadForm(TESFile* file);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);

    TESModelTextureSwap modelArrayList[10]; // src: XBOX_RETAIL_PDB +0x24 (old: m_kModelTextureSwaps)
    TESTexture textureArrayList[11]; // src: XBOX_RETAIL_PDB +0x164 (old: m_kIconTextures)
    EndianConvertibleData data;
};
