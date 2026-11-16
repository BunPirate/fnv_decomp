#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESModel.h"
#include "TESTexture.h"

class TESNPC;

// pdb: class TESHair, size 0x4c, bases: TESForm, TESFullName, TESModel, TESTexture, 1 members
class TESHair : public TESForm, public TESFullName, public TESModel, public TESTexture
{
public:
    TESHair();

    bool Load(TESFile* apFile);
    // TESForm vtable slot 8 (vftable 0x1049b9c slot 8 = 0x5fdcb0)
    bool LoadForm(TESFile* apFile);
    bool IsValidForNPC(TESNPC* npc);
    bool IsHairValidForNPC(TESNPC* npc);
    void ResetFormData();
    bool TESHair_GetPlayable();
    bool TESHair_CanBeMale();
    bool IsFlag2Clear();
    bool IsFlag4Clear();

    char cFlags;
    unsigned char layoutPadding49[3];
};
