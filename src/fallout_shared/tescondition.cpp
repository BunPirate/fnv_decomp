// fallout_shared/tescondition.cpp: condition operations (14 functions)

#include "../../include/MemoryManager.h"
#include "../../include/PackageList.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/TESConditionItem.h"
#include "../../include/TESFile.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESTopicInfoData.h"

// Runs the condition on subject and target references, discarding the result and passing false.
// @fnv 0x00680c30
// pdb: TESCondition::IsTrue | TESCondition.obj | retail, call graph (shared callers), high
// pdb params: apActionRef, apTargetRef
// pdb locals: bIgnoreMe
bool PerkEntryConditionSet::ContainsTrait(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef)
{
    bool result;
    return IsTrue(apActionRef, apTargetRef, result, false);
}

// Calls InitItem(form) on each TESConditionItem in the list obtained from GetItem(), walking the list until it is empty.
// @fnv 0x00680a20
// pdb: TESCondition::InitItem | TESCondition.obj | retail, call graph (shared callers), high
// pdb params: apOwner
// pdb locals: pList
void PerkEntryConditionSet::InitItem(TESForm* apOwner)
{
    BSSimpleList<TESConditionItem*>* current = (BSSimpleList<TESConditionItem*>*)&listConditions.GetItem();
    while (current && !current->IsEmpty())
    {
        current->GetItem()->InitItem(apOwner);
        current = current->GetNext();
    }
}

// Deletes each TESConditionItem in the list obtained from GetItem and removes the head until the list is empty.
// @fnv 0x00680fe0
// pdb: TESCondition::ClearAllConditionItems | TESCondition.obj | retail, call graph, high
// pdb locals: pList
void PerkEntryConditionSet::InitializeConditionItems()
{
    BSSimpleList<TESConditionItem*>* current = (BSSimpleList<TESConditionItem*>*)&listConditions.GetItem();
    while (current && !current->IsEmpty())
    {
        delete current->GetItem();
        current->RemoveHead();
    }
}

// @fnv 0x00680960
// pdb: TESCondition::Load | TESCondition.obj | retail, call graph (shared callers), high
// pdb params: apFile
// pdb locals: pCondItem
void PerkEntryConditionSet::Load(TESFile* apFile)
{
    if (apFile)
    {
        TESConditionItem* item = 0;
        switch (apFile->GetChunkID())
        {
        case 0x41445443:
            item = new TESConditionItem;
            item->Load(apFile);
            ((PackageList*)this)->AddPackage((TESPackage*)item);
            break;
        }
    }
}

// @fnv 0x00680b70
// pdb: TESCondition::Compare | TESCondition.obj | retail, call graph (shared callers), high
// pdb params: apCompare
// pdb locals: pCompList, pList, pCondItem, pCompCondItem
bool PerkEntryConditionSet::Compare(PerkEntryConditionSet* apCompare)
{
    BSSimpleList<TESConditionItem*>* left = (BSSimpleList<TESConditionItem*>*)&listConditions.GetItem();
    BSSimpleList<TESConditionItem*>* right = (BSSimpleList<TESConditionItem*>*)&apCompare->listConditions.GetItem();
    struct ItemPair
    {
        TESConditionItem* leftItem;
        TESConditionItem* rightItem;
    } items;
    while (right && !right->IsEmpty())
    {
        if (!left || left->IsEmpty())
            return true;
        items.leftItem = left->GetItem();
        items.rightItem = right->GetItem();
        if (items.leftItem->IsDifferentFrom(items.rightItem))
            return true;
        left = left->GetNext();
        right = right->GetNext();
    }
    if (left && !left->IsEmpty())
        return true;
    return false;
}

// @fnv 0x00680c60
// src: XBOX_RETAIL_PDB 0x00680c60
// pdb: TESCondition::IsTrue | TESCondition.obj | retail, call graph (shared callers), high
// pdb params: apActionRef, apTargetRef
// pdb locals: bIgnoreMe
bool PerkEntryConditionSet::IsTrue(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef, bool& abDispositionFailure, bool abEssentialPropertiesOnly)
{
    struct EvaluationState
    {
        char padding00, padding01, padding02;
        bool unknown;
        TESConditionItem* item;
        char padding10, padding11, padding12;
        bool skip;
        TESObjectREFR* replacement;
        char padding20, padding21;
        bool inOr;
        bool all;
        BSSimpleList<TESConditionItem*>* current;
        bool value;
        bool orFalse;
        bool definiteFalse;
        bool orUnknown;
    } state;
    state.current = (BSSimpleList<TESConditionItem*>*)&listConditions.GetItem();
    if (state.current->IsEmpty())
    {
        abDispositionFailure = false;
        return true;
    }
    state.all = true;
    state.value = false;
    state.inOr = false;
    state.orUnknown = false;
    state.orFalse = false;
    abDispositionFailure = false;
    state.definiteFalse = false;
    if (apTargetRef)
    {
        state.replacement = apTargetRef->TESObjectREFR_GetXTarget();
        if (state.replacement)
            apTargetRef = state.replacement;
    }
    while (state.current && !state.current->IsEmpty())
    {
        state.item = state.current->GetItem();
        state.skip = false;
        if (abEssentialPropertiesOnly)
        {
            switch ((int)*(unsigned short*)((TESTopicInfoData*)state.item)->GetLinkToList())
            {
            case 68:
            case 69:
            case 70:
            case 71:
            case 72:
            case 372:
                break;
            default:
                state.skip = true;
            }
        }
        state.unknown = false;
        if (!state.inOr)
        {
            if (!state.item->IsFlagSet())
            {
                state.value = state.skip ? true : state.item->IsTrue(apActionRef, apTargetRef, state.unknown);
                state.all = state.all && state.value;
                if (state.unknown)
                    abDispositionFailure = true;
                else if (!state.value)
                    state.definiteFalse = true;
            }
            else
            {
                state.value = state.item->IsTrue(apActionRef, apTargetRef, state.unknown);
                state.inOr = true;
                state.orFalse = false;
                state.orUnknown = state.unknown;
                if (!state.unknown && !state.value)
                    state.orFalse = true;
            }
        }
        else
        {
            if (!state.value)
            {
                state.value = state.skip ? state.skip : state.item->IsTrue(apActionRef, apTargetRef, state.unknown);
                state.orUnknown = state.orUnknown || state.unknown;
                if (!state.unknown && !state.value)
                    state.orFalse = true;
            }
            if (!state.item->IsFlagSet())
            {
                state.inOr = false;
                state.all = state.all && state.value;
                if (!state.all)
                {
                    if (state.orUnknown && !state.orFalse)
                        abDispositionFailure = true;
                    else
                        state.definiteFalse = true;
                }
            }
        }
        if (!state.all && !state.inOr && !abDispositionFailure)
            break;
        state.current = state.current->GetNext();
    }
    if (state.inOr)
    {
        state.all = state.all && state.value;
        if (!state.all)
        {
            if (state.orUnknown && !state.orFalse)
                abDispositionFailure = true;
            else
                state.definiteFalse = true;
        }
    }
    if (state.all || state.definiteFalse)
        abDispositionFailure = false;
    return state.all;
}

extern int DAT_01046b48;

struct FUN_005e9530_Obj
{
    void* vftable;
    unsigned char b4;
    unsigned char b5;
    __thiscall FUN_005e9530_Obj();
};

// Sets the object's vftable to DAT_01046b48 and clears bytes b4 and b5, then returns the object.
// @fnv 0x005e9530
// src: EXE 0x005e9530
void* __fastcall BGSPerkEntry_BGSPerkEntry(FUN_005e9530_Obj* pThis)
{
    pThis->vftable = &DAT_01046b48;
    pThis->b4 = 0;
    pThis->b5 = 0;
    return pThis;
}

// @fnv 0x006808b0
// pdb: TESCondition::~TESCondition | TESCondition.obj | retail, call graph, high
PerkEntryConditionSet::~PerkEntryConditionSet()
{
    InitializeConditionItems();
}

// Evaluates a comparison condition code (0-5) between two floats and returns true if the comparison holds.
// @fnv 0x00681050
// pdb: TESCondition::ForceTrailingAnd | TESCondition.obj | debug, object-file run extension, low
// pdb locals: plist
bool __cdecl CompareFloatsByCondition(int aiCondition, float afVal1, float afVal2)
{
    switch (aiCondition)
    {
    case 0:
        if (afVal1 != afVal2)
            return false;
        break;
    case 1:
        if (afVal1 == afVal2)
            return false;
        break;
    case 2:
        if (afVal1 <= afVal2)
            return false;
        break;
    case 3:
        if (afVal1 < afVal2)
            return false;
        break;
    case 4:
        if (afVal1 >= afVal2)
            return false;
        break;
    case 5:
        if (afVal1 > afVal2)
            return false;
        break;
    }
    return true;
}

struct TESItem_680910
{
    void TESConditionItem_Save();
};
struct ListNode_680910
{
    TESItem_680910* item;
    ListNode_680910* _ref_006815c0();
    bool _ref_008256d0();
    ListNode_680910* _ref_00726070();
};
// @fnv 0x00680910
// src: XBOX_RETAIL_PDB 0x00680910
// pdb: TESCondition::Save | TESCondition.obj | retail, call graph (shared callers), high
// pdb locals: pList
void PerkEntryConditionSet::Save()
{
    ListNode_680910* pNode = ((ListNode_680910*)this)->_ref_006815c0();
    while (pNode != 0 && !pNode->_ref_008256d0())
    {
        pNode->_ref_006815c0()->item->TESConditionItem_Save();
        pNode = pNode->_ref_00726070();
    }
}

struct FUN_00404760_shell
{
    void EffectItem_SetConditions(PerkEntryConditionSet*);
};
// Passes source to the object at this+0x1c, or an empty value when source is null.
// @fnv 0x00404760
// src: COMMUNITY 0x00404760
// pdb: EffectItem::EffectItem | EffectItem.obj | retail, object-file gap fill, medium
// pdb note: debug build links it to EffectItem::SetConditions
// pdb params: apEffectSetting
void FUN_00404760_shell::EffectItem_SetConditions(PerkEntryConditionSet* source)
{
    if (source)
        ((PerkEntryConditionSet*)((char*)this + 0x1c))->Copy(source, 0);
    else
    {
        PerkEntryConditionSet empty;
        ((PerkEntryConditionSet*)((char*)this + 0x1c))->Copy(&empty, 0);
    }
}

extern "C" void __stdcall FUN_00ec5fce(void* object, int elementSize, int count, void (PerkEntryConditionSet::*callback)());

extern "C" void __cdecl FormHeapFreeAndLog_00401030(void* apMemory);

// @fnv 0x005ea2c0
// pdb: TESCondition::`vector deleting destructor' | BGSPerk.obj | debug, object-file gap fill, medium
void* PerkEntryConditionSet::DeleteConditions(unsigned int flags)
{
    if (flags & 2)
    {
        FUN_00ec5fce(this, 0x8, reinterpret_cast<int*>(this)[-1], &PerkEntryConditionSet::Destroy);

        if (flags & 1)
        {
            FormHeapFreeAndLog_00401030(reinterpret_cast<char*>(this) - 4);
        }

        return reinterpret_cast<char*>(this) - 4;
    }

    Destroy();

    if (flags & 1)
    {
        FormHeapFreeAndLog_00401030(this);
    }

    return this;
}

struct ListOps_680a70
{
    void FUN_00680fe0();
    ListOps_680a70* FUN_006815c0();
    TESForm** FUN_006815c0(PerkEntryConditionSet* other);
    bool FUN_008256d0();
    ListOps_680a70* FUN_00726070();
    void CopyFromRefObj(TESForm* form);
    void FUN_00905820(TESConditionItem** item);
};

// Clears this list, then walks the nodes of a1, appending a new TESConditionItem built from each node's form to the destination list.
// @fnv 0x00680a70
// src: XBOX_RETAIL_PDB 0x00680a70
// pdb: TESCondition::Copy | TESCondition.obj | retail, call graph, high
// pdb params: apCopy, apOwner
// pdb locals: pList, pCopyList, pCondItem
void PerkEntryConditionSet::Copy(PerkEntryConditionSet* apCopy, PerkEntryConditionSet* apOwner)
{
    ((ListOps_680a70*)this)->FUN_00680fe0();
    ListOps_680a70* dst = ((ListOps_680a70*)this)->FUN_006815c0();
    ListOps_680a70* src3 = ((ListOps_680a70*)apCopy)->FUN_006815c0();
    while (src3 != 0 && !src3->FUN_008256d0())
    {
        TESConditionItem* item = new TESConditionItem();
        ((ListOps_680a70*)item)->CopyFromRefObj(*src3->FUN_006815c0(apOwner));
        dst->FUN_00905820(&item);
        if (dst->FUN_00726070() != 0)
        {
            dst = dst->FUN_00726070();
        }
        src3 = src3->FUN_00726070();
    }
}

// Walks the node list from _ref_006815c0, skipping nodes where _ref_008256d0 is true, and returns the TESConditionItem at the given index or 0.
// @fnv 0x00680f70
// pdb: TESCondition::GetConditionItem | TESCondition.obj | debug, call graph, medium
// pdb params: aiIndex
// pdb locals: iCount, pList
TESConditionItem* PerkEntryConditionSet::GetItemByIndex(int index)
{
    int iCurrent = 0;
    ListNode_680910* pNode = ((ListNode_680910*)this)->_ref_006815c0();
    while (pNode != 0 && !pNode->_ref_008256d0())
    {
        if (iCurrent == index)
        {
            return *(TESConditionItem**)pNode->_ref_006815c0();
        }
        iCurrent = iCurrent + 1;
        pNode = pNode->_ref_00726070();
    }
    return 0;
}
