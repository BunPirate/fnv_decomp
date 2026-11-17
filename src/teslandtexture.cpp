// teslandtexture.cpp: TESLandTexture, BGSTextureSet, LTCopy (11 functions)

#include "teslandtexture_decls.h"
#include "../include/TESLandTexture.h"

// @fnv 0x00540c50
// pdb: TESLandTexture::TESLandTexture | TESLandTexture.obj | retail, upstream name already matches, high
TESLandTexture::TESLandTexture()
{
    SetFormType(ENUM_FORM_ID_LTEX_ID);
    SetInitializationState(true);
    ResetFormData();
}

// @fnv 0x00540d80
void TESLandTexture::ResetFormData()
{
    pTextureSet = 0;
    HavokData.m_ucParameter1 = 2;
    HavokData.m_ucParameter2 = 30;
    HavokData.m_ucParameter3 = 30;
    cSpecularExponent = 30;
}

// @fnv 0x005412a0
// pdb: TESLandTexture::Load | TESLandTexture.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: formid, pMessage, itempint, tempint
bool TESLandTexture::Load(TESFile* apFile)
{
    unsigned char formType = apFile->GetTESForm();
    if (formType != ENUM_FORM_ID_LTEX_ID)
        return false;
    LoadRecordHeader(apFile);
    do
    {
        switch (static_cast<int>(apFile->GetChunkID()))
        {
        case 'DIDE': {
            char* editorID = static_cast<char*>(_alloca(apFile->GetChunkSize()));
            apFile->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(apFile);
            break;
        case 'MANT': {
            unsigned int textureID = 0;
            apFile->GetChunkData(&textureID);
            pTextureSet = reinterpret_cast<BGSTextureSet*>(textureID);
            break;
        }
        case 'MANH':
            apFile->GetChunkData(&HavokData, 3);
            break;
        case 'MANS':
            apFile->GetChunkData(&cSpecularExponent, 1);
            break;
        case 'MANG': {
            unsigned int grassID = 0;
            apFile->GetChunkData(&grassID);
            if (grassID)
                GetGrassList()->AddTail(reinterpret_cast<TESGrass*>(grassID));
            break;
        }
        }
    } while (apFile->NextChunk());
    SetInitializationState(false);
    return true;
}

// Resolves the grass list and texture set form IDs, warns about missing entries, and marks the item initialized.
// @fnv 0x00540fe0
// pdb: TESLandTexture::InitItem | TESLandTexture.obj | retail, string-set bridge, high
// pdb locals: plist, plastlist, tempint, pgrass
void TESLandTexture::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    BSSimpleList<TESGrass*>* current = GetGrassList();
    BSSimpleList<TESGrass*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        struct GrassResolution
        {
            unsigned int formID;
            TESGrass* grass;
        } grassEntry;
        grassEntry.formID = reinterpret_cast<unsigned int>(current->GetItem());
        RemapFormIDForFile(grassEntry.formID, GetFile(-1));
        grassEntry.grass = dynamic_cast<TESGrass*>(GetFormByID(grassEntry.formID));
        if (!grassEntry.grass)
        {
            Warning("MASTERFILE: Could not find Grass (%08X) for LandTexture '%s' (%08X).", grassEntry.formID,
                    GetName(), GetFormID());
            if (previous)
            {
                previous->Remove(reinterpret_cast<TESGrass*>(grassEntry.formID));
                current = previous->GetNext();
            }
            else
            {
                current->RemoveHead();
            }
        }
        else
        {
            current->SetItem(grassEntry.grass);
            previous = current;
            current = current->GetNext();
        }
    }
    if (pTextureSet)
    {
        unsigned int textureID = reinterpret_cast<unsigned int>(pTextureSet);
        RemapFormIDForFile(textureID, GetFile(-1));
        pTextureSet = dynamic_cast<BGSTextureSet*>(GetFormByID(textureID));
        if (!pTextureSet)
            Warning("MASTERFILE: Could not find Texture Set (%08X) for LandTexture '%s' (%08X).", textureID, GetName(),
                    GetFormID());
        if (pTextureSet)
        {
            if (!pTextureSet->GetTexture(BSShaderProperty::TEXTYPE_DIFFUSE))
                Warning("MASTERFILE: TextureSet '%s' (%08X) missing diffuse texture (required for landscape textures).",
                        pTextureSet->GetName(), pTextureSet->GetFormID());
            if (!pTextureSet->GetTexture(BSShaderProperty::TEXTYPE_NORMAL))
                Warning("MASTERFILE: TextureSet '%s' (%08X) missing normal texture (required for landscape textures).",
                        pTextureSet->GetName(), pTextureSet->GetFormID());
            pTextureSet->SetHasSpecular(false);
        }
    }
    SetInitializationState(true);
}

// Sets or clears bit 0 of iFlags according to hasSpecular.
// @fnv 0x00541250
void BGSTextureSet::SetHasSpecular(bool hasSpecular)
{
    if (hasSpecular)
        iFlags &= ~1;
    else
        iFlags |= 1;
}

void _Deallocate(void*);
// @fnv 0x00540ce0
// pdb: TESLandTexture::`scalar deleting destructor' | TESLandTexture.obj | retail, vtable slot, high
void* TESLandTexture::Delete(unsigned int flags)
{
    this->~TESLandTexture();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00540dc0
// pdb: TESLandTexture::ClearData | TESLandTexture.obj | debug, upstream name already matches, high
void TESLandTexture::ClearData()
{
    GetGrassList()->RemoveAll();
}

// @fnv 0x00540d10
// pdb: TESLandTexture::~TESLandTexture | TESLandTexture.obj | debug, upstream name already matches, high
TESLandTexture::~TESLandTexture()
{
    TESLandTexture::ClearData();
}

void MemCopy(void* dst, const void* src, unsigned int n);
// Copies land texture data from pForm into this object, clearing and rebuilding the grass list from the source's grass entries.
// @fnv 0x00540de0
// pdb: TESLandTexture::Copy | TESLandTexture.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: plist, pcopy, pgrass
void TESLandTexture::CopyFrom(const TESForm* apCopy)
{
    TESLandTexture* src = dynamic_cast<TESLandTexture*>(const_cast<TESForm*>(apCopy));
    if (!src)
        return;
    BSSimpleList<TESGrass*>* node = 0;
    GetGrassList()->RemoveAll();
    TESForm::CopyFrom(src);
    MemCopy(&HavokData, &src->HavokData, 3);
    cSpecularExponent = src->cSpecularExponent;
    pTextureSet = src->GetTextureSet();
    node = src->GetGrassList();
    while (node && !node->IsEmpty())
    {
        TESGrass* g = node->GetItem();
        TextureGrassList.AddTail(g);
        node = node->GetNext();
    }
}

void __fastcall Cb_004855a0(void* self);
void __fastcall Cb_00483710(void* self);
unsigned int __fastcall Cb_0084e3a0(void* self);
void __cdecl Cb_00485910(unsigned int tag, unsigned int value);
bool __cdecl Cb_00401500();
void __cdecl Cb_00485990(unsigned int tag, void* data, unsigned int size);
void __cdecl Cb_004858f0(unsigned int aeChunkID, unsigned int aiData);
void __fastcall Cb_00485680(void* self);

// @fnv 0x00541440
// pdb: TESLandTexture::Save | TESLandTexture.obj | retail, vtable slot, high
// pdb locals: plist, itempint, tempint, pgrass
void TESLandTexture::SaveForm()
{
    unsigned int formId;
    BSSimpleList<TESGrass*>* node3;
    {
        TESGrass* grass;
        unsigned int grassId;

        Cb_004855a0(this);
        Cb_00483710(this);
        if (pTextureSet != 0)
        {
            formId = Cb_0084e3a0(pTextureSet);
            Cb_00485910(0x4d414e54, formId);
        }
        if (Cb_00401500())
        {
            Cb_00483710(&HavokData);
        }
        Cb_00485990(0x4d414e48, &HavokData, 3);
        if (Cb_00401500())
        {
            Cb_00483710(&HavokData);
        }
        Cb_004858f0(0x4d414e53, cSpecularExponent);
        node3 = GetGrassList();
        while (node3 != 0 && !node3->IsEmpty())
        {
            grass = node3->GetItem();
            grassId = Cb_0084e3a0(grass);
            Cb_00485910(0x4d414e47, grassId);
            node3 = node3->GetNext();
        }
    }
    Cb_00485680(this);
}

#include <string.h>
// Returns true if form is not a TESLandTexture or differs in base compare, parameters, tiling, texture set or grass list.
// @fnv 0x00540ec0
// pdb: TESLandTexture::Compare | TESLandTexture.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp, plist, pcomplist
bool TESLandTexture::Compare(TESForm* apCompare)
{
    TESLandTexture* other = dynamic_cast<TESLandTexture*>(apCompare);
    if (!other)
        return true;
    if (TESForm::Compare(other))
        return true;
    if (memcmp(&HavokData, &other->HavokData, 3))
        return true;
    if (cSpecularExponent != other->cSpecularExponent)
        return true;
    if (pTextureSet != other->GetTextureSet())
        return true;
    BSSimpleList<TESGrass*>* pGrassList = GetGrassList();
    BSSimpleList<TESGrass*>* pOtherGrassList = other->GetGrassList();
    while (pGrassList && pOtherGrassList)
    {
        if (pGrassList->GetItem() != pOtherGrassList->GetItem())
            return true;
        pOtherGrassList = pOtherGrassList->GetNext();
        pGrassList = pGrassList->GetNext();
    }
    if ((!pGrassList && pOtherGrassList) || (!pOtherGrassList && pGrassList))
        return true;
    return false;
}
