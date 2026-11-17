// fallout_shared/tesloadscreentype.cpp: TESLoadScreenType, LoadScreenTypeData_FUN (7 functions)

#include "tesloadscreentype_decls.h"
#include "../../include/TESLoadScreenType.h"
#include "../../include/Script.h"

// Reads the record header and chunks (EDID, OBND, DATA) from file, applies endian conversion to data, and returns true.
// @fnv 0x005a72f0
// pdb: TESLoadScreenType::Load | TESLoadScreenType.obj | retail, vtable slot, high
// pdb params: apFile
// pdb locals: chunkid, pMessage
bool TESLoadScreenType::LoadForm(TESFile* apFile)
{
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = apFile->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x41544144:
            ReadTypedData(apFile, data, 88);
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    if (apFile->IsEndianConversionRequired())
        ((LoadScreenTypeData*)data)->Endian();
    return true;
}

void* __cdecl __memcpy(void* dst, const void* src, unsigned int size);

// @fnv 0x005a7690
// pdb: TESLoadScreenType::Copy | TESLoadScreenType.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: pmisc
void TESLoadScreenType::CopyFrom(const TESForm* apCopy)
{
    TESLoadScreenType* pmisc = (TESLoadScreenType*)dynamic_cast<TESLoadScreenType*>((TESForm*)apCopy);
    if (!pmisc)
    {
        return;
    }
    __memcpy(data, pmisc->data, 0x58);
    TESForm::CopyFrom(apCopy);
}

bool __cdecl TESForm_QEndianSwapOnSave();
// Saves the form data, converting its byte order before and after writing when required.
// @fnv 0x005a7630
// pdb: TESLoadScreenType::Save | TESLoadScreenType.obj | retail, vtable slot, high
void TESLoadScreenType::SaveForm()
{
    BeginFormRecord();
    if (TESForm_QEndianSwapOnSave())
        ((LoadScreenTypeData*)data)->Endian();
    TESForm___SaveData(data, 0x58);
    if (TESForm_QEndianSwapOnSave())
        ((LoadScreenTypeData*)data)->Endian();
    FinishFormRecord();
}

int __cdecl _memcmp(const void*, const void*, unsigned int);
// Compares the form data and inherited fields, returning true when either differs or the cast fails.
// @fnv 0x005a76f0
// pdb: TESLoadScreenType::Compare | TESLoadScreenType.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool TESLoadScreenType::Compare(TESForm* apCompare)
{
    TESLoadScreenType* pcomp = dynamic_cast<TESLoadScreenType*>(apCompare);
    if (!pcomp)
        return true;
    if (_memcmp(data, ((Script*)pcomp)->GetHeader(), 0x58))
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    return false;
}

// @fnv 0x005a72d0
// pdb: TESLoadScreenType::~TESLoadScreenType | TESLoadScreenType.obj | debug, upstream name already matches, high
TESLoadScreenType::~TESLoadScreenType()
{}

struct EndianTag
{
};
void __cdecl BSEndian_00401080(int* apValue, EndianTag aTag);
struct LoadScreenTypeData_FUN
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    void SwapEndianFields();
};
// Byte-swaps every integer field of the structure by calling FUN_00401080 on each member.
// @fnv 0x005a7400
// pdb: LoadScreenType_Data::Endian | TESLoadScreenType.obj | retail, call graph, high
void LoadScreenTypeData_FUN::SwapEndianFields()
{
    BSEndian_00401080(&unk28, EndianTag());
    BSEndian_00401080(&unk10, EndianTag());
    BSEndian_00401080(&unk04, EndianTag());
    BSEndian_00401080(&unk08, EndianTag());
    BSEndian_00401080(&unk14, EndianTag());
    BSEndian_00401080(&unk0C, EndianTag());
    BSEndian_00401080(&unk1C, EndianTag());
    BSEndian_00401080(&unk20, EndianTag());
    BSEndian_00401080(&unk24, EndianTag());
    BSEndian_00401080(&unk38, EndianTag());
    BSEndian_00401080(&unk2C, EndianTag());
    BSEndian_00401080(&unk30, EndianTag());
    BSEndian_00401080(&unk3C, EndianTag());
    BSEndian_00401080(&unk34, EndianTag());
    BSEndian_00401080(&unk44, EndianTag());
    BSEndian_00401080(&unk48, EndianTag());
    BSEndian_00401080(&unk4C, EndianTag());
    BSEndian_00401080(&unk50, EndianTag());
    BSEndian_00401080(&unk00, EndianTag());
    BSEndian_00401080(&unk18, EndianTag());
    BSEndian_00401080(&unk40, EndianTag());
    BSEndian_00401080(&unk54, EndianTag());
}
