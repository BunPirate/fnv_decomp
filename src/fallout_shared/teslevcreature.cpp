// fallout_shared/teslevcreature.cpp: Entry, TESLevCreature (7 functions)

#include "../../include/TESLevCreature.h"
#include "teslevcreature_decls.h"
// @fnv 0x0050af60
// pdb: TESLevCreature::Load | TESLevCreature.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: formid, pMessage, fileLevObj, pextra, cdata, itempint, isize, pdata
bool TESLevCreature::Load(TESFile* apFile)
{
    unsigned char type = apFile->GetTESForm();
    if (type != 44)
        return false;
    LoadRecordHeader(apFile);
    do
    {
        switch ((int)apFile->GetChunkID())
        {
        case 0x44494445: {
            char* uiGlobalId = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(uiGlobalId, 512);
            SetEditorID_AtRuntime(uiGlobalId);
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
                LeveledObject leveledEntry;
                memset(&leveledEntry, 0, 12);
                apFile->GetChunkData(&leveledEntry, 12);
                if (apFile->IsEndianConversionRequired())
                    leveledEntry.LEVELED_OBJECT_FILE_Endian();
                DAT_011c8eec =
                    (LeveledEntry*)TESLeveledList_AddLeveledObject(leveledEntry.level, leveledEntry.count, leveledEntry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8eec)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(apFile);
                    DAT_011c8eec->extra = extra;
                    DAT_011c8eec = 0;
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
            unsigned int uiGlobalId = 0;
            apFile->GetChunkData(&uiGlobalId);
            pChanceGlobal = (TESGlobal*)uiGlobalId;
            break;
        }
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x53444f4d: {
            struct
            {
                unsigned int size;
                void* data;
            } chunk;
            chunk.size = apFile->GetChunkSize();
            chunk.data = _alloca(chunk.size);
            apFile->GetChunkData(chunk.data, chunk.size);
            UnpackTextureSwapChunkData(chunk.data, chunk.size, apFile->GetFormVersion());
            break;
        }
        }
    } while (apFile->NextChunk());
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050adf0
// pdb: TESLevCreature::TESLevCreature | TESLevCreature.obj | retail, upstream name already matches, high
TESLevCreature::TESLevCreature()
{
    SetFormType((ENUM_FORM_ID)0x2c);
    TESForm::ClearData();
    SetInitializationState(true);
}

// @fnv 0x0050aed0
// pdb: TESLevCreature::~TESLevCreature | TESLevCreature.obj | retail, upstream name already matches, high
TESLevCreature::~TESLevCreature()
{}

struct LevCreatureDeletion : public TESLevCreature
{
    void* Destroy(unsigned int flags);
};

// @fnv 0x0050aea0
// pdb: TESLevCreature::`scalar deleting destructor' | TESLevCreature.obj | retail, vtable slot, high
void* LevCreatureDeletion::Destroy(unsigned int flags)
{
    TESLevCreature::~TESLevCreature();
    if (flags & 1)
        operator delete(this);
    return this;
}

// The three-chunk serialization overload is not declared by the shared header.
struct ModelTextureSwapSerialization : public TESModelTextureSwap
{
    void WriteChunks(unsigned int, unsigned int, unsigned int);
};

struct LevCreatureSerialization : public TESLevCreature
{
    void SaveForm();
};

// @fnv 0x0050a8e0
// pdb: TESLevCreature::Save | TESLevCreature.obj | retail, vtable slot, high
void LevCreatureSerialization::SaveForm()
{
    TESForm::BeginFormRecord();
    TESForm::ClearData();
    TESLeveledList::Save();
    ((ModelTextureSwapSerialization*)((char*)this + 0x4c))->WriteChunks(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESForm::FinishFormRecord();
}

namespace LevCreatureCopyImplementation {

struct Entry : public TESLevCreature
{
    void TESLevCreature_Copy(TESForm*);
};

// Casts source to TESLevCreature and, if valid, calls FUN_004851b0 to copy data from it.
// @fnv 0x0050b2e0
// src: XBOX_PDB 0x0050b2e0
// pdb: TESLevCreature::Copy | TESLevCreature.obj | retail, upstream name already matches, high
// pdb params: apCopy
// pdb locals: pllcopy
void Entry::TESLevCreature_Copy(TESForm* apCopy)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(apCopy);
    if (!creature)
        return;
    TESForm::CopyFrom(apCopy);
}

}

namespace LevCreatureComparisonImplementation {

struct Entry : public TESLevCreature
{
    bool TESLevCreature_Compare(TESForm*);
};

// Returns true if the other form is not a TESLevCreature or if FUN_00485270(creature) is true, otherwise false.
// @fnv 0x0050b320
// src: XBOX_PDB 0x0050b320
// pdb: TESLevCreature::Compare | TESLevCreature.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool Entry::TESLevCreature_Compare(TESForm* apCompare)
{
    TESLevCreature* creature;
    creature = dynamic_cast<TESLevCreature*>(apCompare);
    if (!creature)
        return true;
    if (TESForm::Compare(creature))
        return true;
    return false;
}

}
