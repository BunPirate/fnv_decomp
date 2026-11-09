#pragma once

#include "TESBoundAnimObject.h"
#include "TESLeveledList.h"
#include "TESModelTextureSwap.h"

class TESActorBase;

// pdb: class TESLevCharacter, size 0x70, bases: TESBoundAnimObject, TESLeveledList, TESModelTextureSwap, 1 members
class TESLevCharacter : public TESBoundAnimObject, public TESLeveledList, public TESModelTextureSwap
{
public:
    TESLevCharacter();

    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x102864c slot 8 = 0x50a930)
    bool LoadForm(TESFile* apFile);

    TESActorBase* pTemplate;
};
