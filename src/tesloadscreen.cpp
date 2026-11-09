// tesloadscreen.cpp: TESLoadScreen (13 functions)

#include "../include/BSStringT.h"
#include "tesloadscreen.h"
#include "tesloadscreen_decls.h"
#include "../include/TESLoadScreen.h"
#include "../include/BaseFormComponent.h"
#include "../include/NiPoint3.h"
#include "../include/TESDataHandler.h"
#include "../include/TESDescription.h"
#include "../include/TESFile.h"
#include "../include/TESForm.h"
#include "../include/TESObjectCELL.h"
#include "../include/TESObjectREFR.h"
#include "../include/TESTexture.h"
#include "../include/TESWorldSpace.h"

extern TESDataHandler* g_dataHandler;

extern "C" const char kTESLoadScreenWarning[];
const char kTESLoadScreenWarning[] = "MASTERFILE: File %s contains old data for loadscreen %s (%08X).";

// Reads the load screen record header and chunks (EDID, OBND, ICON, DESC, LNAM, FNAM, WMI1), storing editor ID, text, form list entries and load screen type.
// @fnv 0x005a68d0
// pdb: TESLoadScreen::Load | TESLoadScreen.obj | retail, string-set bridge, high
// pdb params: apFile
// pdb locals: chunkid, pMessage, ptemptext, pdata, itempint
bool TESLoadScreen::Load(TESFile* apFile)
{
    LoadRecordHeader(apFile);
    SetInitializationState(false);

    int chunkID;
    while ((chunkID = apFile->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(static_cast<TESTexture*>(this), apFile);
            break;
        case 0x43534544: {
            char* text = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(text, 0);
            cDescText.Set(text, 0);
            break;
        }
        case 0x4d414e4c: {
            WorldCellRecord* loadForm = new WorldCellRecord;
            apFile->GetChunkData(loadForm, 12);
            if (apFile->IsEndianConversionRequired())
                reinterpret_cast<ContainerItemExtraFileData*>(loadForm)->Endian();
            reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(&LoadFormList)
                ->AddHead(reinterpret_cast<TESObjectREFR*&>(loadForm));
            break;
        }
        case 0x4d414e46:
            Warning(kTESLoadScreenWarning, apFile->GetFilename(), GetName(), GetFormID());
            break;
        case 0x31494d57: {
            unsigned int loadScreenType = 0;
            apFile->GetChunkData(&loadScreenType);
            if (loadScreenType)
                pLoadScreenType = reinterpret_cast<TESLoadScreenType*>(loadScreenType);
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x005a66e0
// pdb: TESLoadScreen::TESLoadScreen | TESLoadScreen.obj | retail, upstream name already matches, high
TESLoadScreen::TESLoadScreen()
{
    SetFormType(ENUM_FORM_ID_LSCR_ID);
    SetInitializationState(true);
    pLoadScreenType = 0;
}

// @fnv 0x005a6880
// pdb: TESLoadScreen::ClearData | TESLoadScreen.obj | retail, upstream name already matches, high
void TESLoadScreen::ClearData()
{
    ClearLoadFormList();
    pLoadScreenType = 0;
    TESForm::ClearData();
}

// Deletes every element of the loading screen list and then clears the list.
// @fnv 0x005a6e50
// src: XBOX_RETAIL_PDB 0x005a6e50
// pdb: TESLoadScreen::ClearLoadFormList | TESLoadScreen.obj | retail, call graph (shared callers), high
// pdb locals: plist, pdata
void TESLoadScreen::ClearLoadFormList()
{
    BSSimpleList<WorldCellRecord*>* item = &LoadFormList;
    while (item && !item->IsEmpty())
    {
        WorldCellRecord* data = item->GetItem();
        delete data;
        item = item->GetNext();
    }
    LoadFormList.RemoveAll();
}

// @fnv 0x005a6b70
// pdb: TESLoadScreen::InitItem | TESLoadScreen.obj | retail, upstream name already matches, high
// pdb locals: plist, plastlist, pdata, itempint
void TESLoadScreen::InitItem()
{
    if (IsFormInitialized())
        return;
    BSSimpleList<WorldCellRecord*>* item = &LoadFormList;
    BSSimpleList<WorldCellRecord*>* previous = 0;
    while (item && !item->IsEmpty())
    {
        WorldCellRecord* data = item->GetItem();
        if (data->auiFormId)
            TESForm::RemapFormIDForFile(data->auiFormId, GetFile(-1));
        if (data->uiWorldID)
            TESForm::RemapFormIDForFile(data->uiWorldID, GetFile(-1));
        previous = item;
        item = item->GetNext();
    }
    if (pLoadScreenType)
    {
        unsigned int formID = 0;
        formID = reinterpret_cast<unsigned int>(pLoadScreenType);
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        pLoadScreenType = g_dataHandler->GetLoadScreenType(formID);
    }
    SetInitializationState(true);
}

// Builds a location key from the form's cell, worldspace or reference and checks whether it matches an entry in the load screen location list.
// @fnv 0x005a6ec0
// pdb: TESLoadScreen::CanDisplayForForm | TESLoadScreen.obj | debug, object-file gap fill, medium
// pdb params: apLoadingForm
// pdb locals: searchdata, bsearch, bretval, pcell, pworld, pref, plist, pdata
bool TESLoadScreen::MatchesFormLocation(TESForm* form)
{
    bool validLocation = false;
    WorldCellRecord location = {0, 0, 0};
    bool display = false;
    switch (static_cast<const TESForm*>(form)->GetFormType())
    {
    case ENUM_FORM_ID_CELL_ID: {
        TESObjectCELL* cell = static_cast<TESObjectCELL*>(form);
        if (cell->IsCellInterior())
        {
            location.auiFormId = cell->GetFormID();
            location.uiWorldID = 0;
            location.uiCellKey = 0;
            display = true;
        }
        else
        {
            TESWorldSpace* world = cell->GetParentWorldSpace();
            if (world)
            {
                location.auiFormId = 0;
                location.uiWorldID = world->GetFormID();
                location.uiCellKey = TESWorldSpace::BuildCellKey(cell->GetCellGridX(), cell->GetCellGridY());
                display = true;
            }
        }
        break;
    }
    case ENUM_FORM_ID_WRLD_ID: {
        TESWorldSpace* world = static_cast<TESWorldSpace*>(form);
        location.auiFormId = world->GetFormID();
        location.uiWorldID = 0;
        location.uiCellKey = 0;
        display = true;
        break;
    }
    case ENUM_FORM_ID_REFR_ID:
    case ENUM_FORM_ID_ACHR_ID:
    case ENUM_FORM_ID_ACRE_ID:
    case ENUM_FORM_ID_PMIS_ID:
    case ENUM_FORM_ID_PGRE_ID:
    case ENUM_FORM_ID_PBEA_ID:
    case ENUM_FORM_ID_PFLA_ID:
    case ENUM_FORM_ID_PCBE_ID: {
        TESObjectREFR* ref = static_cast<TESObjectREFR*>(form);
        TESObjectCELL* cell = static_cast<const TESObjectREFR*>(ref)->GetParentCell();
        if (cell && cell->IsCellInterior())
        {
            location.auiFormId = cell->GetFormID();
            location.uiWorldID = 0;
            location.uiCellKey = 0;
            display = true;
        }
        else
        {
            TESWorldSpace* world = ref->GetParentWorldSpace();
            if (world)
            {
                location.auiFormId = 0;
                location.uiWorldID = world->GetFormID();
                location.uiCellKey = TESWorldSpace::GetKeyForWorldCoord(*static_cast<const TESObjectREFR*>(ref)->GetPos());
                display = true;
            }
        }
        break;
    }
    }
    if (display)
    {
        BSSimpleList<WorldCellRecord*>* item = &LoadFormList;
        while (item && !item->IsEmpty())
        {
            WorldCellRecord* data = item->GetItem();
            if (location.auiFormId)
            {
                if (data->auiFormId == location.auiFormId)
                {
                    validLocation = true;
                    break;
                }
            }
            else if (location.uiWorldID)
            {
                if (data->uiWorldID == location.uiWorldID && data->uiCellKey == location.uiCellKey)
                {
                    validLocation = true;
                    break;
                }
            }
            item = item->GetNext();
        }
    }
    return validLocation;
}

bool __fastcall _ref_008256d0(void*);

// @fnv 0x005a7110
// pdb: TESLoadScreen::IsDefaultLoadScreen | TESLoadScreen.obj | debug, upstream name already matches, high
bool TESLoadScreen::IsDefaultLoadScreen()
{
    return _ref_008256d0(&LoadFormList);
}

// @fnv 0x005a7130
int TESLoadScreen::GetLoadScreenTypeDataType()
{
    int eRetVal = 0;
    if (pLoadScreenType)
    {
        eRetVal = *(int*)((char*)pLoadScreenType + 0x18);
    }
    return eRetVal;
}

// @fnv 0x005a68b0
// pdb: TESLoadScreen::Save | TESLoadScreen.obj | retail, vtable slot, high
void TESLoadScreen::InitializeComponent()
{
    TESForm::BeginFormRecord();
    TESForm::FinishFormRecord();
}

// @fnv 0x005a67e0
// pdb: TESLoadScreen::~TESLoadScreen | TESLoadScreen.obj | retail, upstream name already matches, high
TESLoadScreen::~TESLoadScreen()
{
    ClearData();
}

// Copies the load-screen type, form data and list items from another TESLoadScreen into this one.
// @fnv 0x005a6c70
// pdb: TESLoadScreen::Copy | TESLoadScreen.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: plist, pcopylist, pcopy
void TESLoadScreen::CopyLoadScreenData(TESForm* apCopy)
{
    BSSimpleList<WorldCellRecord*>* pkDstNode = 0;
    TESLoadScreen* pkSource = dynamic_cast<TESLoadScreen*>(apCopy);
    if (!pkSource)
        return;

    ClearLoadFormList();

    BSSimpleList<WorldCellRecord*>* pkSrcIter = &pkSource->LoadFormList;
    pkDstNode = &LoadFormList;
    while (pkSrcIter && !pkSrcIter->IsEmpty())
    {
        pkDstNode->AddTail(static_cast<WorldCellRecord* const&>(pkSrcIter->GetItem()));
        if (pkDstNode->GetNext())
            pkDstNode = pkDstNode->GetNext();
        pkSrcIter = pkSrcIter->GetNext();
    }

    SetLoadScreenType(pkSource->GetLoadScreenType());
    CopyFormData(pkSource);
}

extern char DAT_01186260, DAT_01183028;
void* FUN_00ec43fb(void*, int, void*, void*, int);
class ListX
{
  public:
    int FUN_005ae380();
    bool FUN_008256d0();
    void* FUN_006815c0();
    ListX* FUN_00726070();
    bool BSSimpleList_TESLevSpell_IsInList(void*);
    void* head;
    void* next;
};
// @fnv 0x005a6d30
// pdb: TESLoadScreen::Compare | TESLoadScreen.obj | retail, vtable slot, high
// pdb params: apCompare
// pdb locals: pcomp, pcomplist
bool TESLoadScreen::CompareLoadScreenData(void* apCompare)
{
    TESLoadScreen* pOtherForm = (TESLoadScreen*)FUN_00ec43fb(apCompare, 0, &DAT_01183028, &DAT_01186260, 0);
    if (!pOtherForm)
        return true;
    ListX* it = reinterpret_cast<ListX*>(&pOtherForm->LoadFormList);
    if (reinterpret_cast<ListX*>(&LoadFormList)->FUN_005ae380() != it->FUN_005ae380())
        return true;
    while (it && !it->FUN_008256d0())
    {
        if (!reinterpret_cast<ListX*>(&LoadFormList)->BSSimpleList_TESLevSpell_IsInList(it->FUN_006815c0()))
            return true;
        it = it->FUN_00726070();
    }
    if (CompareFormData(pOtherForm))
        return true;
    if (GetLoadScreenType() != pOtherForm->GetLoadScreenType())
        return true;
    return false;
}
