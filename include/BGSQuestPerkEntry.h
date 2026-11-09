#pragma once

#include "BGSPerkEntry.h"

class TESQuest;

// pdb: class BGSQuestPerkEntry, size 0x10, bases: BGSPerkEntry, 1 members
class BGSQuestPerkEntry : public BGSPerkEntry
{
public:
    BGSQuestPerkEntry();  // 0x005e9800: BGSPerkEntry(), vftable 0x01046b84, Data zeroed

    struct
    {
        TESQuest* pQuest;
        unsigned char stage;
        unsigned char padding[3];
    } Data;

    virtual void InitItem(TESForm* apOwner);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* apCompare);
    virtual void Save();
    virtual bool Load(TESFile* apFile);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
};
