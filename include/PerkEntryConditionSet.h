#pragma once

#include "BSSimpleList.h"

class BGSPerkEntry;
class TESConditionItem;
class TESFile;
class TESForm;
class TESObjectREFR;

class PerkEntryConditionSet
{
public:
    // a list of conditions: the constructor 0x006808b0 constructs it (EH-framed list constructor call)
    BSSimpleList<TESConditionItem*> listConditions;

    PerkEntryConditionSet();
    ~PerkEntryConditionSet();

    bool ContainsTrait(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef);
    bool IsTrue(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef, bool& abDispositionFailure, bool abEssentialPropertiesOnly);
    void InitItem(TESForm* apOwner);
    bool Compare(PerkEntryConditionSet* apCompare);
    void InitializeConditionItems();
    void Load(TESFile* apFile);
    BGSPerkEntry*& GetItem();
    void Save();
    void Copy(PerkEntryConditionSet* apCopy, PerkEntryConditionSet* apOwner);
    TESConditionItem* GetItemByIndex(int index);
    void Destroy();
    void* DeleteConditions(unsigned int flags);
};
