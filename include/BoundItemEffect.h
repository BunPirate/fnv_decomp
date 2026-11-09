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

    InventoryStackRecord* pDisplacedWeapon;
    InventoryStackRecord* pDisplacedItems[20];
    float fAppearTime;
    bool bItemSummoned;
    bool bSpellModelCached;
    bool bWeaponCached;
    bool bWornCached;
    bool bSetupItem;
};
