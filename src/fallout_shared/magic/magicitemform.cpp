// fallout_shared/magic/magicitemform.cpp: MagicItemForm (5 functions)

#include "magicitemform_decls.h"
#include "../../../include/EffectItemList.h"
#include "../../../include/MagicItem.h"
#include "../../../include/MagicItemForm.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x0040c230
// pdb: MagicItemForm::Load | MagicItemForm.obj | debug, object-file run extension, low
// pdb params: apFile
// pdb locals: echunkid, pMessage
bool MagicItemForm::LoadForm(TESFile* file)
{
    LoadRecordHeader(file);

    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* chunkData = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(chunkData, 0x200);
            SetEditorID_AtRuntime(chunkData);
            break;
        }

        case 0x444e424f:
            readOBNDSubRecord(file);
            break;

        case 0x4c4c5546: {
            TESFullName::LoadFullNameChunk(this ? (TESFullName*)((char*)this + 0x18) : 0, file);
            break;
        }

        case 0x44494645:
        case 0x41445443:
            ((EffectItemList*)((char*)this + 0x24))->Load(file, ((TESFullName*)((char*)this + 0x18))->GetFullName());
            break;

        default:
            break;
        }

        ((MagicItem*)((char*)this + 0x18))->LoadMagicItemChunk(file, chunkID);

        if (chunkID == ((MagicItem*)((char*)this + 0x18))->GetChunkID())
        {
            memset(((MagicItem*)((char*)this + 0x18))->GetData(), 0, ((MagicItem*)((char*)this + 0x18))->GetDataSize());

            file->GetChunkData(((MagicItem*)((char*)this + 0x18))->GetData(),
                               ((MagicItem*)((char*)this + 0x18))->GetDataSize());

            if (file->IsEndianConversionRequired())
                Endian();
        }

        if (!file->NextChunk())
            break;
    }

    if (((BSSimpleList<EffectSetting*>*)((char*)this + 0x28))->ItemsInList() == 0)
    {
        Warning(DAT_0101361c, GetFormID(), ((TESFullName*)((char*)this + 0x18))->GetFullName());
    }

    return true;
}

// @fnv 0x0040c5b0
// pdb: MagicItemForm::InitItem | MagicItemForm.obj | retail, upstream name already matches, high
void MagicItemForm::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    ((MagicItem*)((char*)this + 0x18))->MagicItemInitItem(this);
    SetInitializationState(true);
}

void __fastcall FUN_004056d0(void*);

// @fnv 0x0040c1d0
// pdb: SettingT<GameSettingCollection>::~SettingT<GameSettingCollection> | EffectItem.obj | retail, object-file run extension, low
// pdb note: debug build links it to MagicItemForm::Save
void MagicItemForm::SaveForm()
{
    TESForm::BeginFormRecord();
    ((TESFullName*)((char*)this + 0x18))->Save_00487010();
    ((MagicItem*)((char*)this + 0x18))->ClearMagicItemData();
    ((MagicItem*)((char*)this + 0x18))->SaveMagicItemData();
    FUN_004056d0((void*)((char*)this + 0x24));
    TESForm::FinishFormRecord();
}

// @fnv 0x0040c450
// pdb: MagicItemForm::Compare | MagicItemForm.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pmagicItem
bool MagicItemForm::Compare(TESForm* apCompare)
{
    MagicItemForm* pmagicItem = dynamic_cast<MagicItemForm*>(apCompare);

    if (!pmagicItem)
        return true;

    if (TESForm::Compare(apCompare))
        return true;

    if (reinterpret_cast<MagicItem*>(reinterpret_cast<char*>(this) + 0x18)
            ->IsMagicItemEqual(pmagicItem ? reinterpret_cast<MagicItem*>(reinterpret_cast<char*>(pmagicItem) + 0x18)
                                        : 0))
        return true;

    if (reinterpret_cast<EffectItemList*>(reinterpret_cast<char*>(this) + 0x24)
            ->EffectItemList_Compare(pmagicItem ? reinterpret_cast<EffectItemList*>(reinterpret_cast<char*>(pmagicItem) + 0x24)
                                  : 0))
        return true;

    return false;
}

extern const char DAT_01183028[];
extern const char DAT_0118395c[];

MagicItemForm* __cdecl FUN_00ec43fb(const TESForm* form, int a2, const char* a3, const char* a4, int a5);

// @fnv 0x0040c510
// pdb: MagicItemForm::Copy | MagicItemForm.obj | retail, object-file gap fill, high
// pdb params: apCopy
// pdb locals: pmagicItem
void MagicItemForm::CopyFrom(const TESForm* apCopy)
{
    MagicItemForm* rec = FUN_00ec43fb(apCopy, 0, DAT_01183028, DAT_0118395c, 0);
    if (rec == 0)
    {
        return;
    }
    TESForm::CopyFrom(apCopy);
    ((MagicItem*)((char*)this + 0x18))->CopyMagicItemData(rec ? (MagicItem*)((char*)rec + 0x18) : 0);
    ((EffectItemList*)((char*)this + 0x24))->EffectItemList_Copy(rec ? (EffectItemList*)((char*)rec + 0x24) : 0);
}
