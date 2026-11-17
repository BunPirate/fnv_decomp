#pragma once

#include "BGSPerkEntry.h"

class SpellItem;

// pdb: class BGSAbilityPerkEntry, size 0xc, bases: BGSPerkEntry, 1 members
class BGSAbilityPerkEntry : public BGSPerkEntry
{
public:
    SpellItem* pAbility; // src: XBOX_RETAIL_PDB +0x8 (old: m_pSpell)

    BGSAbilityPerkEntry();
    BGSAbilityPerkEntry* Initialize();

    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* apFile);
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);
};
