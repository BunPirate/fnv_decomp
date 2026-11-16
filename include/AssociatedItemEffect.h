#pragma once

#include "ActiveEffect.h"

class TESForm;

// pdb: class AssociatedItemEffect, size 0x4c, bases: ActiveEffect, 1 members
class AssociatedItemEffect : public ActiveEffect
{
public:
    AssociatedItemEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    virtual ~AssociatedItemEffect();

    virtual ActiveEffect* Copy();
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void InitLoadGame(Actor* apActor);
    virtual void CopyData(ActiveEffect* apDestination);

    void __thiscall FUN_00806c20(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    void __thiscall FUN_00806de0(Actor* apActor);
    void FUN_00806e30(Actor* apActor);
    void __thiscall FUN_00806e70(Actor* apActor);

    TESForm* pAssociatedItem; // src: XBOX_RETAIL_PDB +0x48 (old: m_pAssociatedForm)
};
