// fallout_shared/bgslightingtemplate.cpp: lighting template operations (11 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "bgslightingtemplate.h"
#include "../../include/BGSLightingTemplate.h"
#include "../../include/InteriorData.h"
#include <malloc.h>
#include <string.h>
#include "../../include/TESFile.h"

// @fnv 0x005265c0
// pdb: BGSLightingTemplate::BGSLightingTemplate | BGSLightingTemplate.obj | retail, upstream name already matches, high
BGSLightingTemplate::BGSLightingTemplate()
{
    SetFormType(ENUM_FORM_ID_LGTM_ID);
    ResetFormData();
}

// @fnv 0x00526710
// pdb: BGSLightingTemplate::InitializeData | BGSLightingTemplate.obj | debug, object-file gap fill, medium
void BGSLightingTemplate::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

// Reads the LGTM record header and chunks (EDID, OBND, DATA) into the lighting template, converting endianness if required.
// @fnv 0x005268a0
// pdb: BGSLightingTemplate::Load | BGSLightingTemplate.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: chunkid, pMessage
bool BGSLightingTemplate::Load(TESFile* apFile)
{
    if (static_cast<TESFileFormInt*>(apFile)->GetTESForm() != ENUM_FORM_ID_LGTM_ID)
        return false;
    LoadRecordHeader(apFile);
    int iChunkID;
    while ((iChunkID = apFile->GetChunkID()) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pEditorID = static_cast<char*>(_alloca(apFile->GetChunkSize()));
            apFile->GetChunkData(pEditorID, 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(apFile);
            break;
        case 0x41544144:  // DATA
            ReadTypedData(apFile, &Data, sizeof(Data));
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    if (apFile->IsEndianConversionRequired())
        Data.INTERIOR_DATA_Endian();
    return true;
}

// Initializes the lighting fields, with directional fade and fog power set to 1.0f.
// @fnv 0x00526640
InteriorData::InteriorData()
{
    m_uiAmbientColor = 0;
    m_uiDirectionalColor = 0;
    m_uiFogColor = 0;
    m_fFogNear = 0.0f;
    m_fFogFar = 0.0f;
    m_uiDirectionalRotationXY = 0;
    m_uiDirectionalRotationZ = 0;
    m_fDirectionalFade = 1.0f;
    m_fFogClipDistance = 0.0f;
    m_fFogPower = 1.0f;
    m_uiTrailingValue = 0;
}

// @fnv 0x005266f0
// pdb: BGSLightingTemplate::~BGSLightingTemplate | BGSLightingTemplate.obj | debug, upstream name already matches, high
BGSLightingTemplate::~BGSLightingTemplate()
{}

// Method-only adapter for operations not declared on the shared lighting template.
// All object layout comes from BGSLightingTemplate.
struct LightingTemplateOperations : BGSLightingTemplate
{
    void SaveForm();
    void CopyFrom(TESForm* apCopy);
    void ClearData();
    bool Compare(TESForm* apCompare);
};

extern "C" bool __cdecl TESForm_QEndianSwapOnSave();
// @fnv 0x00526730
// pdb: BGSLightingTemplate::Save | BGSLightingTemplate.obj | retail, vtable slot, high
void LightingTemplateOperations::SaveForm()
{
    BeginFormRecord();
    if (TESForm_QEndianSwapOnSave())
        Data.INTERIOR_DATA_Endian();
    TESForm___SaveData(&Data, sizeof(Data));
    if (TESForm_QEndianSwapOnSave())
        Data.INTERIOR_DATA_Endian();
    FinishFormRecord();
}

struct SwapTag
{
};

void SwapInt(int* p, SwapTag tag);

// Swaps the byte order of the ten serialized 32-bit lighting fields.
// @fnv 0x00526790
// src: XBOX_RETAIL_PDB 0x00526790
// pdb: INTERIOR_DATA::Endian | BGSLightingTemplate.obj | retail, call graph, high
void InteriorData::INTERIOR_DATA_Endian()
{
    SwapInt(reinterpret_cast<int*>(&m_uiAmbientColor), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiDirectionalColor), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiFogColor), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogNear), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogFar), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiDirectionalRotationXY), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_uiDirectionalRotationZ), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fDirectionalFade), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogClipDistance), SwapTag());
    SwapInt(reinterpret_cast<int*>(&m_fFogPower), SwapTag());
}

extern "C" void* __cdecl _memcpy(void* dst, const void* src, unsigned int size);

// Copies InteriorData from a BGSLightingTemplate source and calls the base class copy routine.
// @fnv 0x005269f0
// pdb: BGSLightingTemplate::Copy | BGSLightingTemplate.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: pcopy
void LightingTemplateOperations::CopyFrom(TESForm* apCopy)
{
    BGSLightingTemplate* src = dynamic_cast<BGSLightingTemplate*>(apCopy);
    if (src == 0)
    {
    }
    else
    {
        _memcpy(&Data, &src->Data, sizeof(InteriorData));
        TESForm::CopyFrom(apCopy);
    }
}

// If the form is not yet initialized, clears its data and marks it as initialized.
// @fnv 0x005269c0
// pdb: BGSLightingTemplate::InitItem | BGSLightingTemplate.obj | debug, object-file gap fill, medium
void LightingTemplateOperations::ClearData()
{
    if (IsFormInitialized())
        return;
    TESForm::ClearData();
    SetInitializationState(true);
}

extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);
// Returns true when the cast fails, the InteriorData bytes differ, or TESForm::Compare returns true.
// @fnv 0x00526a50
// pdb: BGSLightingTemplate::Compare | BGSLightingTemplate.obj | retail, vtable slot, high
// pdb params: apCompare
// pdb locals: pcomp
bool LightingTemplateOperations::Compare(TESForm* apCompare)
{
    BGSLightingTemplate* other = dynamic_cast<BGSLightingTemplate*>(apCompare);
    if (!other)
        return true;
    if (_memcmp(&Data, &other->Data, sizeof(InteriorData)))
        return true;
    if (TESForm::Compare(other))
        return true;
    return false;
}
