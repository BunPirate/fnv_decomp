// fallout_shared/teslevcharacter.cpp: TESLevCreature, TESLevItem, TESLevCharacter, Entry (8 functions)

#include "teslevcharacter_unit.h"
#include "../../include/BGSLoadFormBuffer.h"

// @fnv 0x0050ad40
// pdb: TESLevCreature::InitItem | TESLevCreature.obj | retail, upstream name already matches, high
void TESLevCreature::InitItem()
{
    if (GetInitialized())
        return;
    TESLeveledList::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    SetInitializationState(true);
}

// Loads the leveled item's base form data and its leveled list data from the given load buffer.
// @fnv 0x0050b390
// pdb: TESLevItem::LoadGame | TESLevItem.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void TESLevItem::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    TESLeveledList::LoadGame(apLoadGameBuffer);
}

// @fnv 0x0050a930
// pdb: TESLevCharacter::Load | TESLevCharacter.obj | retail, vtable slot, high
// pdb params: apFile
// pdb locals: formid, pMessage, fileLevObj, pextra, cdata, itempint, isize, pdata
bool TESLevCharacter::LoadForm(TESFile* apFile)
{
    unsigned char ucFormType = apFile->GetTESForm();
    if (ucFormType != 45)
        return false;
    LoadRecordHeader(apFile);
    do
    {
        switch ((int)apFile->GetChunkID())
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
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
                struct Entry
                {
                    unsigned short level;
                    unsigned short pad;
                    TESForm* form;
                    unsigned short count;
                    unsigned short pad2;
                } levelEntry;
                memset(&levelEntry, 0, 12);
                apFile->GetChunkData(&levelEntry, 12);
                if (apFile->IsEndianConversionRequired())
                    ((LeveledObject*)&levelEntry)->LEVELED_OBJECT_FILE_Endian();
                DAT_011c8e64 = AddLeveledObject(levelEntry.level, levelEntry.count, levelEntry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8e64)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(apFile);
                    DAT_011c8e64->extra = extra;
                    DAT_011c8e64 = 0;
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
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x53444f4d: {
            void* textureData;
            unsigned int chunkSize = apFile->GetChunkSize();
            textureData = _alloca(chunkSize);
            apFile->GetChunkData(textureData, chunkSize);
            UnpackTextureSwapChunkData(textureData, chunkSize, ((TESFileFormVersion*)apFile)->GetFormVersion());
            break;
        }
        }
    } while (apFile->NextChunk());
    SetInitializationState(false);
    return true;
}

namespace fnv_0050b3c0 {
struct FUN_0050b3c0_shell : public TESLevItem
{
    void TESLevCharacter_Revert(BGSLoadFormBuffer*);
};

struct TESLeveledList_Revert_Access
{
    void Revert(BGSLoadFormBuffer*);
};

// Reverts the TESForm base and then the leveled list at offset 0x30 using the load game buffer.
// @fnv 0x0050b3c0
// src: COMMUNITY 0x0050b3c0
// pdb: TESLevItem::Revert | TESLevItem.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
void FUN_0050b3c0_shell::TESLevCharacter_Revert(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert(reinterpret_cast<unsigned int>(apLoadGameBuffer));
    reinterpret_cast<TESLeveledList_Revert_Access*>(reinterpret_cast<char*>(this) + 0x30)->Revert(apLoadGameBuffer);
}
}  // namespace fnv_0050b3c0

struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v[6];
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    virtual void vf2();
    int w;
};
struct FUN_0050a770 : public TESBoundAnimObject, public FUN_00487650, public B2_4fe
{
    FUN_0050a770();
    ~FUN_0050a770();
};
// @fnv 0x0050a770
// pdb: TESLevCharacter::TESLevCharacter | TESLevCharacter.obj | retail, call graph, high
FUN_0050a770::FUN_0050a770()
{
    SetFormType((ENUM_FORM_ID)0x2d);
    ClearData();
    SetInitializationState(true);
}

void __cdecl _Deallocate(void*);
struct FUN_0050a820_shell
{
    void FUN_0050a850();
    void* FUN_0050a820(unsigned int);
};
// Calls FUN_0050a850, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0050a820
// pdb: TESLevCharacter::`scalar deleting destructor' | TESLevCharacter.obj | retail, vtable slot, high
void* FUN_0050a820_shell::FUN_0050a820(unsigned int flags)
{
    FUN_0050a850();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
    void TESLevCharacter_Copy(TESForm*);
};
// Casts apCopy to TESLevCharacter and, if the cast succeeds, calls FUN_004851b0 with apCopy.
// @fnv 0x0050acb0
// src: XBOX_PDB 0x0050acb0
// pdb: TESLevCharacter::Copy | TESLevCharacter.obj | retail, upstream name already matches, high
// pdb params: apCopy
// pdb locals: pllcopy
void FUN_005e78f0_t::TESLevCharacter_Copy(TESForm* apCopy)
{
    TESLevCharacter* pllcopy = dynamic_cast<TESLevCharacter*>(apCopy);
    if (!pllcopy)
        return;
    TESForm_CopyAllComponents(apCopy);
}

namespace LevCharacterComparison {
class Entry : public TESLevCharacter
{
  public:
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESLevCharacter_Compare(TESForm*);
};

// Returns true if the cast fails or FUN_00485270 returns true for the compared object.
// @fnv 0x0050acf0
// src: XBOX_PDB 0x0050acf0
// pdb: TESLevCharacter::Compare | TESLevCharacter.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool Entry::TESLevCharacter_Compare(TESForm* apCompare)
{
    TESLevCharacter* compared = dynamic_cast<TESLevCharacter*>(apCompare);
    if (!compared)
        return true;
    if (TESForm_CompareAllComponents(compared))
        return true;
    return false;
}
}
