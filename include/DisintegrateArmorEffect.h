#pragma once

#include "ActiveEffect.h"

class InventoryItem;

// pdb: class DisintegrateArmorEffect, size 0x4c, bases: ActiveEffect, 1 members
class DisintegrateArmorEffect : public ActiveEffect
{
public:
    DisintegrateArmorEffect(MagicCaster*, MagicItem*, EffectItem*);
    virtual ~DisintegrateArmorEffect();
    virtual ActiveEffect* Copy() override;
    virtual unsigned short GetSaveSize(Actor*) override;
    virtual void SaveGame(Actor*) override;
    virtual void LoadGame(Actor*) override;
    virtual void Start() override;

    void* Destroy(unsigned int flags);
    InventoryItem* GetItem();
    float GetFloatAtOffset1C(int);
    float GetFloatAtOffset1C();

    InventoryItem* pArmor; // src: XBOX_RETAIL_PDB +0x48 (old: m_pItem)
};
