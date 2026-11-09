// fallout_shared/teslevitem.cpp: TESLevItem, LevItemCopyEntry, LevItemComparison (10 functions)

#include "teslevitem_decls.h"
#include "../../include/TESLevItem.h"
// @fnv 0x0050b8d0
// pdb: TESLevItem::GetMaxLevelDifference | TESLevItem.obj | debug, upstream name already matches, high
int TESLevItem::GetMaxLevelDifference()
{
    return g_011c8f00.Int()->i;
}

// @fnv 0x0050b560
// pdb: TESLevItem::Load | TESLevItem.obj | retail, vtable slot, high
// pdb params: apFile
// pdb locals: formid, pMessage, fileLevObj, pextra, cdata, itempint
bool TESLevItem::LoadForm(TESFile* apFile)
{
    unsigned char ucFormType = apFile->GetTESForm();
    if (ucFormType != 0x34)
        return false;
    LoadRecordHeader(apFile);
    do
    {
        switch ((int)apFile->GetChunkID())
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorId, 512);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)apFile->GetChunkID())
            {
            case 0x4f4c564c: {
                LeveledObject entry;
                memset(&entry, 0, 12);
                apFile->GetChunkData(&entry, 12);
                if (apFile->IsEndianConversionRequired())
                    entry.LEVELED_OBJECT_FILE_Endian();
                DAT_011c8f1c = TESLeveledList_AddLeveledObject(entry.level, entry.count, entry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8f1c)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(apFile);
                    *(ContainerItemExtra**)((char*)DAT_011c8f1c + 8) = extra;
                    DAT_011c8f1c = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            apFile->GetChunkData(&chance, 0);
            ExtraWeaponModFlags_SetWeaponModFlags(chance);
            break;
        }
        case 0x464c564c:
            apFile->GetChunkData(&cLLFlags, 0);
            break;
        case 0x474c564c: {
            unsigned int global = 0;
            apFile->GetChunkData(&global);
            pChanceGlobal = (TESGlobal*)global;
            break;
        }
        }
    } while (apFile->NextChunk());
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050b890
// pdb: TESLevSpell::InitItem | TESLevSpell.obj | retail, vtable slot, high
void TESLevItem::InitItem()
{
    if (GetInitialized())
        return;
    TESLeveledList::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x0050b400
// pdb: TESLevItem::TESLevItem | TESLevItem.obj | retail, upstream name already matches, high
TESLevItem::TESLevItem()
{
    SetFormType((ENUM_FORM_ID)0x34);
    ClearData();
}

// @fnv 0x0050b4c0
// pdb: TESLevItem::~TESLevItem | TESLevItem.obj | debug, upstream name already matches, high
TESLevItem::~TESLevItem()
{}

// Saving entry points not yet declared on the shared TESLevItem.
struct LevItemSerialization : public TESLevItem
{
    void Save();
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    void SaveIfChanged(BGSSaveFormBuffer* buffer);
};

// @fnv 0x0050b530
// pdb: TESLevSpell::Save | TESLevSpell.obj | retail, vtable slot, high
void LevItemSerialization::Save()
{
    TESForm::BeginFormRecord();
    TESForm::ClearData();
    TESLeveledList::Save();
    TESForm::FinishFormRecord();
}

// @fnv 0x0050adb0
// pdb: TESLevItem::SaveGame | TESLevItem.obj | retail, vtable slot, high
// pdb params: apSaveGameBuffer
void LevItemSerialization::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    SaveIfChanged(apSaveGameBuffer);
    TESLeveledList::SaveGame(apSaveGameBuffer);
}

struct LevItemCopyEntry : public ::TESLevItem
{
    void TESLevItem_Copy(::TESForm* apCopy);
};

// Casts the source TESForm to a TESLevItem and, if valid, calls FUN_004851b0 to copy the source into this entry.
// @fnv 0x0050b800
// src: XBOX_PDB 0x0050b800
// pdb: TESLevItem::Copy | TESLevItem.obj | retail, upstream name already matches, high
// pdb params: apCopy
// pdb locals: pllcopy
void LevItemCopyEntry::TESLevItem_Copy(::TESForm* apCopy)
{
    ::TESLevItem* sourceItem;
    sourceItem = dynamic_cast< ::TESLevItem*>(apCopy);
    if (!sourceItem)
        return;
    TESForm::CopyFrom(apCopy);
}

struct LevItemComparison : public ::TESLevItem
{
    bool TESLevItem_Compare(::TESForm*);
};

// @fnv 0x0050b840
// src: XBOX_PDB 0x0050b840
// pdb: TESLevItem::Compare | TESLevItem.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool LevItemComparison::TESLevItem_Compare(::TESForm* apCompare)
{
    ::TESLevItem* pLevItem = dynamic_cast< ::TESLevItem*>(apCompare);
    if (!pLevItem)
        return true;
    if (TESForm::Compare(pLevItem))
        return true;
    return false;
}
