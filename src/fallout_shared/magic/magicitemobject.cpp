// fallout_shared/magic/magicitemobject.cpp: MagicItemObject (5 functions)

#include "magicitemobject_decls.h"
// @fnv 0x0040c9d0
// pdb: MagicItemObject::InitItem | MagicItemObject.obj | retail, upstream name already matches, high
void MagicItemObject::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    MagicItemInitItem(this);
    SetInitializationState(true);
}

#include <malloc.h>
// Reads a magic item record's chunks (editor ID, bounds, full name, effects), warns when the effect list is empty, and returns true.
// @fnv 0x0040c650
// pdb: MagicItemObject::Load | MagicItemObject.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: echunkid, pMessage
bool MagicItemObject::Load(TESFile* apFile)
{
    int chunk;
    LoadRecordHeader(apFile);
    while (chunk = apFile->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(editor, 512);
            SetEditorID_AtRuntime(editor);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, apFile);
            break;
        case 0x44494645:
        case 0x41445443:
            EffectItemList::Load(apFile, GetFullName());
            break;
        }
        LoadMagicItemChunk(apFile, chunk);
        if (chunk == GetChunkID())
        {
            memset(GetData(), 0, GetDataSize());
            apFile->GetChunkData(GetData(), GetDataSize());
            if (apFile->GetChunkData())
                vfn_180();
        }
        if (!apFile->NextChunk())
            break;
    }
    if (!reinterpret_cast<EffectListEntries*>(reinterpret_cast<char*>(this) + kEffectEntriesOffset)->ItemsInList())
        Warning("GAME EFFECTS: Effect Item (%08X) %s has no effects defined.", GetFormID(), GetFullName());
    return true;
}

// @fnv 0x0040c5f0
// pdb: MagicItemObject::Save | MagicItemObject.obj | debug, object-file run extension, low
void MagicItemObject::ClearData()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    ClearMagicItemData();
    SaveMagicItemData();
    FUN_004056d0(reinterpret_cast<char*>(this) + kEffectListOffset);
    TESForm::FinishFormRecord();
}

// The shared classes do not declare these comparison and copy entry points yet.
// These extensions add declarations only; all object layout comes from include/.
class EffectListOperations : public EffectItemList
{
public:
    bool EffectItemList_Compare(EffectItemList* apCompare);
    void EffectItemList_Copy(EffectItemList* apCopy);
};

class MagicItemObjectOperations : public MagicItemObject
{
public:
    bool CompareObject(TESForm* apCompare);
    void CopyObject(TESForm* apCopy);
};

// @fnv 0x0040c870
// pdb: MagicItemObject::Compare | MagicItemObject.obj | retail, object-file run extension, high
// pdb params: apCompare
// pdb locals: pmagicItem
bool MagicItemObjectOperations::CompareObject(TESForm* apCompare)
{
    MagicItemObject* converted = dynamic_cast<MagicItemObject*>(apCompare);
    if (!converted)
        return true;
    if (TESForm::Compare(apCompare))
        return true;
    if (IsMagicItemEqual(static_cast<MagicItem*>(converted)))
        return true;
    if (reinterpret_cast<EffectListOperations*>(reinterpret_cast<char*>(this) + kEffectListOffset)->EffectItemList_Compare(converted ? reinterpret_cast<EffectItemList*>(reinterpret_cast<char*>(converted) + kEffectListOffset) : 0))
        return true;
    return false;
}

extern int DAT_01183028;
extern int DAT_011830e8;

MagicItemObject* __cdecl FUN_00ec43fb(TESForm* arg, int a, int* b, int* c, int d);

// @fnv 0x0040c930
// pdb: MagicItemObject::Copy | MagicItemObject.obj | retail, object-file run extension, high
// pdb params: apCopy
// pdb locals: pmagicItem
void MagicItemObjectOperations::CopyObject(TESForm* apCopy)
{
    MagicItemObject* result = FUN_00ec43fb(apCopy, 0, &DAT_01183028, &DAT_011830e8, 0);
    if (!result)
        return;

    TESForm::CopyFrom(apCopy);

    CopyMagicItemData(result ? reinterpret_cast<MagicItem*>(reinterpret_cast<char*>(result) + kMagicItemOffset) : 0);

    reinterpret_cast<EffectListOperations*>(reinterpret_cast<char*>(this) + kEffectListOffset)->EffectItemList_Copy(result ? reinterpret_cast<EffectItemList*>(reinterpret_cast<char*>(result) + kEffectListOffset) : 0);
}
