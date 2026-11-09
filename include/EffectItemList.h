#pragma once

#include "BSSimpleList.h"
#include "MagicTarget.h"

class Actor;
class EffectItem;
class TESFile;

// pdb: class EffectItemList, size 0x10, bases: BSSimpleList<EffectItem *>, 1 members
class EffectItemList : public BSSimpleList<EffectItem *>
{
public:
    EffectItemList();
    virtual ~EffectItemList();
    virtual void vf01();
    virtual float GetTotalCost(Actor* apActor);
    virtual void vf03();
    virtual void vf04();

    int m_iEffectCount;

    EffectItem* GetUsageMonitorEffect();
    void AddItem(EffectItem* item);
    EffectItem* GetCostliestEffect(int aeRange, bool abAreaOnly);
    EffectItem* GetCostliestEffect(int m_eRange, int iUnk);
    void Load(TESFile* apFile, const char* apSpellName);
    bool EffectItemList_Compare(EffectItemList* apCompare);
    void EffectItemList_Copy(EffectItemList* apCopy);
    void RemoveAllEffectItems();
    bool HasTargetEffect();
    bool HasNonDetrimentalEffectWithFlag(unsigned int flag);
    bool HasDetrimentalEffect();
    EffectItem* GetEffectItemByIndex(unsigned char index);
    bool IsHostile_00405d80();
    bool CanBePoison();
    bool HasTouchEffect();
    bool HasSelfEffect();
    void RemoveAllEffects();
};
