// fallout_shared/bgsmessageicon.cpp: BGSMessageIcon, TESModelTextureSwap (11 functions)

#include "layout_support.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESModelTextureSwap.h"

// @fnv 0x0047a220
// pdb: BGSMessageIcon::ClearDataComponent | BGSMessageIcon.obj | debug, call graph, medium
void BGSMessageIcon::ClearComponent()
{
    Icon.Free();
}

// @fnv 0x0048a3d0
// pdb: TESModelTextureSwap::TESModelTextureSwap | TESModelTextureSwap.obj | retail, upstream name already matches, high
TESModelTextureSwap::TESModelTextureSwap()
{
    InitializeComponent();
}

// @fnv 0x0047a130
// pdb: BGSMessageIcon::BGSMessageIcon | BGSMessageIcon.obj | retail, upstream name already matches, high
BGSMessageIcon::BGSMessageIcon()
{
    InitializeComponent();
}

// @fnv 0x0047a290
// pdb: BGSMessageIcon::LoadMessageIcon | BGSMessageIcon.obj | debug, upstream name already matches, high
// pdb params: apIcon, apFile
void BGSMessageIcon::LoadMessageIcon(BGSMessageIcon* apIcon, TESFile* apFile)
{
    TESTexture::ReadTextureData(apIcon->GetIcon(), apFile);
}

// @fnv 0x0047a380
// pdb: BGSMessageIcon::SetMessageIconTextureName | BGSMessageIcon.obj | debug, upstream name already matches, high
// pdb params: apTexture
void BGSMessageIcon::SetMessageIconTextureName(char* apTexture)
{
    reinterpret_cast<TESFullName*>(&Icon)->SetFullName(static_cast<const char*>(apTexture));
}

// @fnv 0x0047a1a0
// pdb: BGSMessageIcon::~BGSMessageIcon | BGSMessageIcon.obj | retail, upstream name already matches, high
BGSMessageIcon::~BGSMessageIcon()
{
    ClearComponent();
}

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
// @fnv 0x0047a240
// pdb: BGSMessageIcon::Save | BGSMessageIcon.obj | debug, upstream name already matches, high
// pdb params: aeTextureID
void BGSMessageIcon::Save(int aeTextureID)
{
    if (reinterpret_cast<TESFullName*>(&Icon)->GetModelLength())
        TESForm_AddChunkArray(aeTextureID, (void*)reinterpret_cast<TESFullName*>(&Icon)->GetFullName(),
                     reinterpret_cast<TESFullName*>(&Icon)->GetModelLength() + 1);
}

// @fnv 0x0047a2b0
// pdb: BGSMessageIcon::CopyComponent | BGSMessageIcon.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pCopy
void BGSMessageIcon::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    BGSMessageIcon* msgIcon = dynamic_cast<BGSMessageIcon*>(apCopyFC);
    if (!msgIcon)
        return;
    SetMessageIconTextureName(msgIcon->GetMessageIconTextureName());
}

int _stricmp(const char*, const char*);
// @fnv 0x0047a320
// pdb: BGSMessageIcon::CompareComponent | BGSMessageIcon.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pCompare
bool BGSMessageIcon::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    BGSMessageIcon* icon = dynamic_cast<BGSMessageIcon*>(apCompareFC);
    if (!icon)
        return true;
    if (_stricmp(GetMessageIconTextureName(), icon->GetMessageIconTextureName()))
        return true;
    return false;
}

// @fnv 0x0047a300
// pdb: BGSMessageIcon::GetMessageIconTextureName | BGSMessageIcon.obj | debug, upstream name already matches, high
char* BGSMessageIcon::GetMessageIconTextureName()
{
    return reinterpret_cast<TESFullName*>(&Icon)->GetFullName();
}

// @fnv 0x0047a200
// pdb: BGSMessageIcon::InitializeDataComponent | BGSMessageIcon.obj | debug, call graph, high
void BGSMessageIcon::InitializeComponent()
{
    Icon.Init();
}
