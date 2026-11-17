// fallout_shared/bgsdefaultobjectmanager.cpp: BGSDefaultObjectManager, NavMesh (11 functions)

#include "layout_support.h"
#include "../../include/ActorValueInfo.h"
#include "../../include/BGSDefaultObjectManager.h"
#include "../../include/NavMesh.h"
#include "../../include/NavMeshGrid.h"
#include "../../include/TESChildCell.h"

#include "bgsdefaultobjectmanager.h"
#include <string.h>

// Zeroes the default object array with memset.
// @fnv 0x0058d840
// pdb: BGSDefaultObjectManager::InitializeData | BGSDefaultObjectManager.obj | debug, call graph, high
void BGSDefaultObjectManager::ResetFormData()
{
    memset(m_apDefaultObjects, 0, sizeof(m_apDefaultObjects));
}

// @fnv 0x0058db10
// pdb: BGSDefaultObjectManager::GetDefaultObject | BGSDefaultObjectManager.obj | retail, call graph (shared callers), high
// pdb params: aeObject
TESForm* BGSDefaultObjectManager::GetDefaultObjectByIndex(DEFAULT_OBJECT aeObject)
{
    if (!Instance()->IsFormInitialized())
        return 0;
    return Instance()->m_apDefaultObjects[aeObject];
}

// Returns the singleton BGSDefaultObjectManager, allocating it with new if it has not been created yet.
// @fnv 0x0058d680
// pdb: BGSDefaultObjectManager::Instance | BGSDefaultObjectManager.obj | retail, upstream name already matches, high
BGSDefaultObjectManager* BGSDefaultObjectManager::Instance()
{
    if (!ms_pSystemUtility)
        ms_pSystemUtility = new BGSDefaultObjectManager;
    return ms_pSystemUtility;
}

#include "bgsdefaultobjectmanager_endian.h"

// Reads a TESFile record of form type 100, loads the DATA chunk into the default object array and byte-swaps it when endian conversion is required.
// @fnv 0x0058d920
// pdb: BGSDefaultObjectManager::Load | BGSDefaultObjectManager.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: chunkid, formid, i
bool BGSDefaultObjectManager::Load(TESFile* apFile)
{
    unsigned char form = apFile->GetTESForm();
    if (form != 100)
        return false;
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    while (unsigned int chunk = apFile->GetChunkID())
    {
        switch (chunk)
        {
        case 0x41544144:
            apFile->GetChunkData(m_apDefaultObjects, sizeof(m_apDefaultObjects));
            if (apFile->IsEndianConversionRequired())
            {
                for (int i = 0; i < DEFAULT_OBJECT_DO_COUNT; ++i)
                    BSEndian((unsigned int*)&m_apDefaultObjects[i], EndianSizeTag<4>());
            }
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    SetInitializationState(false);
    return true;
}

#include "bgsdefaultobjectmanager_decls.h"
// If not yet initialized, resolves each of the 34 default object IDs to a form, clears mismatched types, warns on failures, then marks the manager initialized.
// @fnv 0x0058da10
// pdb: BGSDefaultObjectManager::InitItem | BGSDefaultObjectManager.obj | retail, string-set bridge, high
// pdb locals: i, itempint
void BGSDefaultObjectManager::InitItem()
{
    if (GetInitialized())
        return;
    for (int i = 0; i < 34; ++i)
    {
        unsigned int uiFormId = (unsigned int)m_apDefaultObjects[i];
        if (uiFormId)
        {
            TESForm::RemapFormIDForFile(uiFormId, GetFile(-1));
            m_apDefaultObjects[i] = TESForm::GetFormByID(uiFormId);
            if (m_apDefaultObjects[i] && m_apDefaultObjects[i]->GetFormType() != DAT_0118c360[i].type)
                m_apDefaultObjects[i] = 0;
            if (!m_apDefaultObjects[i])
                Warning("Unable to find valid '%s' default object for ID (%08X).", DAT_0118c360[i].name, uiFormId);
        }
    }
    SetInitializationState(true);
}

// @fnv 0x0068eb80
// pdb: NavMesh::NavMesh | NavMesh.obj | retail, upstream name already matches, high
NavMesh::NavMesh() : POVs(37)
{
    SetFormType(ENUM_FORM_ID_NAVM_ID);
    pParentCell = 0;
    pNavMeshInfo = 0;
    pTriangleToObstacleMap = new NiTMap<unsigned short, NiPointer<ObstacleData> >(37);
}

// Deletes the BGSDefaultObjectManager singleton instance and clears its pointer if it is set.
// @fnv 0x0058d710
// pdb: BGSDefaultObjectManager::ReleaseInstance | BGSDefaultObjectManager.obj | debug, object-file gap fill, medium
void DestroyDefaultObjectManager()
{
    if (BGSDefaultObjectManager::ms_pSystemUtility)
    {
        delete BGSDefaultObjectManager::ms_pSystemUtility;
        BGSDefaultObjectManager::ms_pSystemUtility = 0;
    }
}

// @fnv 0x0058d760
// pdb: BGSDefaultObjectManager::BGSDefaultObjectManager | BGSDefaultObjectManager.obj | retail, upstream name already matches, high
BGSDefaultObjectManager::BGSDefaultObjectManager() : TESForm()
{
    SetFormType((ENUM_FORM_ID)100);
    SetRefID(0x31, 1);
    ((ActorValueInfo*)this)->SetScriptName("DefaultObjectManager");
    ResetFormData();
}

// @fnv 0x0058d820
// pdb: BGSDefaultObjectManager::~BGSDefaultObjectManager | BGSDefaultObjectManager.obj | debug, upstream name already matches, high
BGSDefaultObjectManager::~BGSDefaultObjectManager()
{
}

void __cdecl TESForm_AddChunkArray_00485710(unsigned int, unsigned int*, unsigned int);
// @fnv 0x0058d870
// pdb: BGSDefaultObjectManager::Save | BGSDefaultObjectManager.obj | retail, upstream name already matches, high
// pdb locals: pidarray, i
void BGSDefaultObjectManager::Save()
{
    unsigned int pidarray4[34];
    int i;
    BeginFormRecord();
    for (i = 0; i < 34; ++i)
    {
        if (m_apDefaultObjects[i])
            pidarray4[i] = m_apDefaultObjects[i]->GetFormID();
        else
            pidarray4[i] = 0;
    }
    TESForm_AddChunkArray_00485710(0x41544144, pidarray4, 34);
    FinishFormRecord();
}
