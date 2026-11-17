// fallout_shared/region system/tesregion.cpp: TESRegion (12 functions)

#include <windows.h>
#include "layout_support.h"

#include "../../../include/NiPoint2.h"
#include "../../../include/TESFile.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESRegionDataManager.h"
#include "../../../include/SL.h"
#include "../../../include/NiPoint3.h"
// 0x004f15a0 stores its argument byte at +4 (the form type here); the same folded code is BSSoundHandle::SetAssumeSuccess.
struct FormTypeSetter_4f15a0
{
    void SetFormType(int);
};
#include "../../../include/TESRegionDataWeather.h"
#include "../../../include/TESWorldSpace.h"

#include "tesregion_TESRegion.h"
#include "tesregion_TESRegionDataList.h"
#include "tesregion_TESRegionPointList.h"
#include "tesregion_load.h"

// The shared base declares Initialize nonvirtual; this call site uses the original vtable slot.
class RegionDataInitialization
{
public:
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Initialize(TESRegion* region);
};

// Clears the region's data list and deletes every point list held in the point list queue.
// @fnv 0x004f0ef0
// pdb: TESRegion::ClearData | TESRegion.obj | retail, upstream name already matches, high
// pdb locals: pcurrentPointList
void TESRegion::ClearData()
{
    if (m_pRegionDataList)
        m_pRegionDataList->Clear();
    if (pRegionPointList)
    {
        RegionPointList* pointList = pRegionPointList->GetItem();
        while (pointList)
        {
            pRegionPointList->RemoveHead();
            delete pointList;
            pointList = pRegionPointList->GetItem();
        }
    }
}

// @fnv 0x004f0f80
// pdb: TESRegion::InitItem | TESRegion.obj | retail, upstream name already matches, high
// pdb locals: itempint, pList, pworld
void TESRegion::InitItem()
{
    TESWorldSpace* world;
    BSSimpleList<TESRegionData*>* data;
    if (GetInitialized())
        return;
    {
        unsigned int worldID = (unsigned int)GetParentWorldSpace();
        RemapFormIDForFile(worldID, GetFile(-1));
        world = dynamic_cast<TESWorldSpace*>(GetFormByID(worldID));
    }
    if (world)
        SetWorldSpace(world);
    SetInitializationState(true);
    data = GetRegionDataList();
    while (data && data->GetItem())
    {
        reinterpret_cast<RegionDataInitialization*>(data->GetItem())->Initialize(this);
        data = data->GetNext();
    }
}

// Loads a TESRegion from a TESFile: reads the EDID/OBND/WNAM/RPLI/RPLD chunks and region-type subrecords, then prunes invalid point lists.
// @fnv 0x004f0b10
// pdb: TESRegion::Load | TESRegion.obj | retail, upstream name already matches, high
// pdb params: apFile
// pdb locals: echunkID, plastPtList, formid, pMessage, itempint, itemp, pcurrent, pdelete
bool TESRegion::Load(TESFile* apFile)
{
    struct ReferenceItemCountEntry
    {
        RegionPointList* invalid;
        BSSimpleList<RegionPointList*>* lists;
        unsigned int distance;
        unsigned int worldID;
        char* editorID;
        int chunk;
        RegionPointList* pointList;
        char padding0, padding1, padding2;
        unsigned char type;
    } loadState;
    loadState.type = apFile->GetTESForm();
    loadState.pointList = 0;
    if (loadState.type != 55)
        return false;
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    while (loadState.chunk = apFile->GetChunkID())
    {
        switch (loadState.chunk)
        {
        case 0x44494445: {
            loadState.editorID = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(loadState.editorID, 512);
            SetEditorID_AtRuntime(loadState.editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4d414e57: {
            loadState.worldID = 0;
            apFile->GetChunkData(&loadState.worldID);
            SetWorldSpace((TESWorldSpace*)loadState.worldID);
            break;
        }
        case 0x494c5052: {
            loadState.distance = 0;
            apFile->GetChunkData(&loadState.distance);
            loadState.pointList = new RegionPointList(true);
            loadState.pointList->SetDistanceInsideAtMax(loadState.distance);
            GetRegionPointLists()->AddTail(loadState.pointList);
            break;
        }
        case 0x444c5052:
            if (loadState.pointList)
                loadState.pointList->TESRegionPointList_LoadPoints(apFile);
            break;
        case 0x424f4452:
        case 0x42534452:
        case 0x44494452:
        case 0x44534452:
        case 0x444d4452:
        case 0x49534452:
        case 0x504d4452:
        case 0x4e4c4452:
        case 0x4a4f4452:
        case 0x4e4f4349:
        case 0x544f4452:
        case 0x53474452:
        case 0x54414452:
        case 0x54574452:
            ((TESRegionLoadHandler*)g_dataHandler)->GetRegionDataManager()->ApplyEntry(apFile, this);
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    loadState.lists = GetRegionPointLists();
    while (loadState.lists && loadState.lists->GetItem())
    {
        if (!loadState.lists->GetItem()->TESRegionPointList_Validate(true))
        {
            loadState.invalid = loadState.lists->GetItem();
            ((TESRegionLoadList*)GetRegionPointLists())->Remove(loadState.invalid);
            delete loadState.invalid;
            loadState.lists = GetRegionPointLists();
        }
        else
            loadState.lists = loadState.lists->GetNext();
    }
    return true;
}

struct FUN_00740940_shell : public TESDataHandler
{
    TESRegionDataManager* GetRegionDataManager();
};

// @fnv 0x00740940
TESRegionDataManager* FUN_00740940_shell::GetRegionDataManager()
{
    return *(TESRegionDataManager**)((char*)this + 0x624);
}

void __fastcall TESWeatherList_GetRandomWeather(char*);

// @fnv 0x004f10b0
// src: COMMUNITY 0x004f10b0
// pdb: TESRegionDataWeather::GetRandomWeather | TESRegion.obj | debug, object-file run extension, low
void __fastcall TESWeatherList_GetRandomWeather_(char* param_1)
{
    TESWeatherList_GetRandomWeather(param_1 + 8);
}

struct RDL_004f3330
{
    void* a;
    void* b;
    void* c;
    RDL_004f3330(bool);
};

// Initialises the object: zeroes the point, allocates two members, sets form type 0x37, clears two pointers and sets a float to -1.
// @fnv 0x004f0770
// pdb: TESRegion::TESRegion | TESRegion.obj | retail, upstream name already matches, high
TESRegion::TESRegion()
{
    ((NiPoint3*)&m_kDiffuseColor)->Set(0.0f, 0.0f, 0.0f);
    m_pRegionDataList = (RegionDataList*)new RDL_004f3330(true);
    pRegionPointList = (BSSimpleList<RegionPointList*>*)new SL;
    ((FormTypeSetter_4f15a0*)this)->SetFormType(0x37);
    m_pContainingWorldspace = 0;
    m_pRegionWeather = 0;
    fWeatherChance = -1.0f;
}

// @fnv 0x004f08c0
// pdb: TESRegion::~TESRegion | TESRegion.obj | retail, upstream name already matches, high
// pdb locals: pcurrentPointList
TESRegion::~TESRegion()
{
    if (m_pRegionDataList != 0)
    {
        delete m_pRegionDataList;
    }
    if (pRegionPointList != 0)
    {
        RegionPointList* pointList = pRegionPointList->GetItem();
        while (pointList != 0)
        {
            pRegionPointList->RemoveHead();
            delete pointList;
            pointList = pRegionPointList->GetItem();
        }
        delete pRegionPointList;
    }
}

struct PointProxy
{
    PointProxy* CloneRegionPointList(int);
};
struct ListProxy
{
    PointProxy*& FUN_006815c0();
    ListProxy* FUN_00726070();
    void FUN_005ae3d0(PointProxy* const&);
};
struct DataProxy
{
    void TESRegionDataList_Copy(DataProxy*);
};
// Copies this region into destination (allocating one if null), copying its data and each list node's point proxy.
// @fnv 0x004f10d0
// pdb: TESRegion::Copy | TESRegion.obj | retail, vtable slot, high
// pdb params: apCopyInto
// pdb locals: pcopy, pcurrent
TESRegion* TESRegion::Clone(TESRegion* apCopyInto)
{
    TESRegion* result = apCopyInto ? apCopyInto : new TESRegion;
    ListProxy* pNode = FUN_00441110();
    WarnCopyUnsupported(result);
    NiAVObject_GetParent()->TESRegionDataList_Copy(result->NiAVObject_GetParent());
    while (pNode && pNode->FUN_006815c0())
    {
        result->FUN_00441110()->FUN_005ae3d0(pNode->FUN_006815c0()->CloneRegionPointList(0));
        pNode = pNode->FUN_00726070();
    }
    return result;
}

struct S_004f1300_Item
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    float TESTopic_GetPriority_GetUnk28();
};

struct S_004f1300_Base0
{
    virtual void vfn00();
};

struct S_004f1300_Holder : S_004f1300_Base0, BSSimpleList<S_004f1300_Item*>
{
};

struct S_004f1300_Mgr
{
    S_004f1300_Holder* TESDataHandler_GetRegionList();
};

struct S_004f1300_Save
{
    unsigned short* FUN_00825c00();
    void TESSaveLoadGame_SaveGameDataOLD(void* apData, unsigned int aiSize);
    void TESSaveLoadGame_SaveNumericID(void* apFormID, unsigned int aiSize);
};

extern S_004f1300_Save* DAT_011de45c;
extern S_004f1300_Mgr* DAT_011c3f2c;

// @fnv 0x004f1300
// src: XBOX_DEBUG_PDB 0x004f1300
// pdb: TESRegion::SaveGame | TESRegion.obj | debug, call graph, high
// pdb locals: icount, plist, pcount, iregionID, pregion, flastWeatherUpdate
void __cdecl TESRegion_SaveGame()
{
    unsigned short m_usPassCountLocal = 0;
    unsigned short* pusCount4 = DAT_011de45c->FUN_00825c00();
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&m_usPassCountLocal, 2);

    BSSimpleList<S_004f1300_Item*>* pNodeX = DAT_011c3f2c->TESDataHandler_GetRegionList();
    while (pNodeX && !pNodeX->IsEmpty())
    {
        S_004f1300_Item* pItem = pNodeX->GetItem();
        int iID2 = 0;
        float fSecondFunctionValue = 0.0f;
        if (pItem)
        {
            iID2 = pItem->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            fSecondFunctionValue = pItem->TESTopic_GetPriority_GetUnk28();
        }
        DAT_011de45c->TESSaveLoadGame_SaveNumericID(&iID2, 4);
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&fSecondFunctionValue, 4);
        m_usPassCountLocal++;
        pNodeX = pNodeX->GetNext();
    }
    *pusCount4 = m_usPassCountLocal;
}

class B4F1050DataList
{
  public:
    TESRegionData* GetDataByType(int aFind);
};

void* __fastcall B4F1050GetWeatherTypes(TESRegionDataWeather* pkWeather);

// Clears m_pRegionWeather, then if m_pRegionDataList exists, gets the type-3 region data and stores its weather types.
// @fnv 0x004f1050
// pdb: TESRegion::UpdateWeather | TESRegion.obj | retail, upstream name already matches, high
// pdb locals: pRDW
void TESRegion::UpdateWeather()
{
    m_pRegionWeather = 0;
    if (m_pRegionDataList)
    {
        TESRegionDataWeather* pkWeather = dynamic_cast<TESRegionDataWeather*>(((B4F1050DataList*)m_pRegionDataList)->GetDataByType(3));
        if (pkWeather)
            m_pRegionWeather = (TESWeather*)B4F1050GetWeatherTypes(pkWeather);
    }
}

void __cdecl TESForm_AddChunk_00485910(unsigned int uiType, unsigned int uiID_ldrt);
struct RefQ
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct ElemQ
{
    void TESRegionPointList_Save();
};
struct VElemQ
{
    virtual void v0();
    virtual void Save();
};
struct LstAQ
{
    bool FUN_008256d0();
    ElemQ** FUN_006815c0();
    LstAQ* FUN_00726070();
};
struct LstBQ
{
    bool FUN_008256d0();
    VElemQ** FUN_006815c0();
    LstBQ* FUN_00726070();
};
// Calls FUN_004855a0, passes a reference-derived ID to FUN_00485910, traverses two lists calling FUN_004f77c0 and Save on their elements, then calls FUN_00485680.
// @fnv 0x004f0a40
// pdb: TESRegion::Save | TESRegion.obj | retail, vtable slot, high
// pdb locals: pPList, pDataList, pworld, itempint
void TESRegion::SaveForm()
{
    BeginFormRecord();
    RefQ* pRef_gmplt = (RefQ*)GetParentWorldSpace();
    if (pRef_gmplt)
    {
        unsigned int uiID_ldrt = pRef_gmplt->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e57, uiID_ldrt);
    }
    LstAQ* pIterA_kkeo = (LstAQ*)FUN_00441110();
    while (pIterA_kkeo && !pIterA_kkeo->FUN_008256d0())
    {
        (*pIterA_kkeo->FUN_006815c0())->TESRegionPointList_Save();
        pIterA_kkeo = pIterA_kkeo->FUN_00726070();
    }
    LstBQ* pIterB_jeqla = (LstBQ*)NiAVObject_GetParent();
    while (pIterB_jeqla && !pIterB_jeqla->FUN_008256d0())
    {
        (*pIterB_jeqla->FUN_006815c0())->Save();
        pIterB_jeqla = pIterB_jeqla->FUN_00726070();
    }
    FinishFormRecord();
}
