#pragma once

#include "AssociatedItemEffect.h"
#include "InventoryStackRecord.h"

// pdb: class BoundItemEffect, size 0xac, bases: AssociatedItemEffect, 8 members
class BoundItemEffect : public AssociatedItemEffect
{
public:
    BoundItemEffect(MagicCaster* apCaster, MagicItem* apSpell, EffectItem* apEffect);
    virtual ~BoundItemEffect();

    virtual ActiveEffect* Copy();
    virtual void Update(float afSecondsElapsed);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void LoadGame(Actor* apActor);
    virtual void InitLoadGame(Actor* apActor);
    virtual bool IsEffectValid(MagicTarget* apTarget);
    virtual void Start();
    virtual void Finish();

    bool __thiscall IsTargetCharacter(MagicTarget* apTarget);
    void DoSummon();

    InventoryStackRecord* pDisplacedWeapon; // src: XBOX_RETAIL_PDB +0x4c (old: m_pkWeaponEntry)
    InventoryStackRecord* pDisplacedItems[20]; // src: XBOX_RETAIL_PDB +0x50 (old: m_apArmorEntries)
    float fAppearTime; // src: XBOX_RETAIL_PDB +0xa0 (old: unka0)
    bool bItemSummoned; // src: XBOX_RETAIL_PDB +0xa4 (old: m_bModifierActive)
    bool bSpellModelCached; // src: XBOX_RETAIL_PDB +0xa5 (old: m_bShowShader)
    bool bWeaponCached; // src: XBOX_RETAIL_PDB +0xa6 (old: m_bLoadWeaponModel)
    bool bWornCached; // src: XBOX_RETAIL_PDB +0xa7 (old: m_bLoadArmorModel)
    bool bSetupItem; // src: XBOX_RETAIL_PDB +0xa8 (old: pending)
};
