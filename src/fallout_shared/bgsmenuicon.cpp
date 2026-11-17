// fallout_shared/bgsmenuicon.cpp: BGSMenuIcon (6 functions)

#include "TESFile.h"
#include "../../include/BGSMenuIcon.h"
#include <malloc.h>

struct ChunkLoadState
{
    char* chunkData;
    unsigned int chunkID;
};

// Checks the form type is 5, loads the record header, then reads EDID, OBND and ICON chunks until no chunk remains.
// @fnv 0x00590350
// pdb: BGSMenuIcon::Load | BGSMenuIcon.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: chunkid, formid, pMessage
bool BGSMenuIcon::Load(TESFile* apFile)
{
    unsigned char formType;
    ChunkLoadState chunkState;

    formType = apFile->GetTESForm();
    if (formType != 5)
        return false;

    LoadRecordHeader(apFile);
    while ((chunkState.chunkID = apFile->GetChunkID()) != 0)
    {
        switch (chunkState.chunkID)
        {
        case 0x44494445:
            chunkState.chunkData = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(chunkState.chunkData, 0x200);
            SetEditorID_AtRuntime(chunkState.chunkData);
            break;
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(static_cast<TESTexture*>(this), apFile);
            break;
        }

        if (!apFile->NextChunk())
            break;
    }
    return true;
}

void __fastcall FUN_00483710(void* p);

// Clears this form before destroying its icon and form bases.
// @fnv 0x005902d0
// pdb: BGSMenuIcon::~BGSMenuIcon | BGSMenuIcon.obj | debug, upstream name already matches, high
BGSMenuIcon::~BGSMenuIcon()
{
    FUN_00483710(this);
}

// @fnv 0x00590470
// pdb: BGSMenuIcon::Save | BGSMenuIcon.obj | retail, vtable slot, high
void BGSMenuIcon::SaveForm()
{
    TESForm::BeginFormRecord();
    TESTexture::Save(0x4e4f4349);
    TESForm::FinishFormRecord();
}

// Copies the base form data when the source is a menu icon.
// @fnv 0x005904a0
// pdb: BGSMenuIcon::Copy | BGSMenuIcon.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: pcopy
void BGSMenuIcon::CopyFrom(const TESForm* apCopy)
{
    const BGSMenuIcon* icon = dynamic_cast<const BGSMenuIcon*>(apCopy);
    if (!icon)
        return;
    TESForm::CopyFrom(icon);
}

// Returns true if apCompare is not a BGSMenuIcon or the base comparison returns true.
// @fnv 0x005904e0
// pdb: BGSMenuIcon::Compare | BGSMenuIcon.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool BGSMenuIcon::Compare(TESForm* apCompare)
{
    BGSMenuIcon* pcomp = dynamic_cast<BGSMenuIcon*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    return false;
}
