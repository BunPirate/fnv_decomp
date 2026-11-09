#pragma once

#include "TESForm.h"
#include "NiTPointerMap.h"
#include "BSSimpleArray.h"
#include "MapEntryCount.h"

class NavMeshInfo;
class NavMesh;
class NavigationRequest;
class TeleportableReference;
class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;

typedef BSSimpleArray<NavMeshInfo*, 1024> NavMeshInfoArray;

// pdb: class NavMeshInfoMap, size 0x40, bases: TESForm, 4 members
class NavMeshInfoMap : public TESForm
{
public:
    virtual ~NavMeshInfoMap();
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual bool Sort(TESForm* form);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual void InitItem(void);
    virtual void SetQuestItem(bool set);

    bool bUpdateAll;
    unsigned char pad19[3];
    NiTPointerMap<unsigned int, NavMeshInfo*> InfoMap;
    NiTPointerMap<unsigned int, NiTPointerMap<unsigned int, NavMeshInfoArray*>*>
        m_kNavMeshInfoArraysByWorldspace;
    bool bInit;
    unsigned char pad3D[3];

    NavMeshInfoMap();
    bool Load(TESFile* file);
    NavMeshInfo* FUN_00693d70(unsigned int formID);
    bool CheckAllNavmeshBoundingBoxes();
    void AddInfoToCellKeyMap(NavMeshInfo* apNavMeshInfo);
    void ClearNavMeshInfoMaps();
    void CheckMap();
    bool LoadNavMeshInfoMap(TESFile* file);
    void SaveNavMeshInfoMap();
    void StartSave();
    void EndSave();
    void SetAlteredAndRevertNavMeshes(bool value);
    bool FUN_00460340();
    bool ProcessBeforeSave();
    bool SavesBefore_006b6910(TESForm* form);
    void RegisterNavMeshInfo(TeleportableReference* info);
    void RemoveNavMeshInfo(unsigned int auiNavMeshID);
    void RemoveNavMeshInfo(NavMesh* auiNavMeshID);
    void DeleteNavMeshInfo(int auiNavMeshID);
    int FindNavMeshInfoForCell(TESObjectCELL* apCell);
    void* FindNavMeshInfoForCellKey(TESWorldSpace* worldSpace, int cellKey);
    int FindNavMeshInfoForCellKey(void* worldSpace, int cellKey);
    unsigned int LookupScriptMessageValue(const char* message);
    int LookupScriptMessageValue(TESObjectCELL* cell);
    void GetAllNavMeshInfo(BSSimpleArray<void*, 1024>* apReturnArray);
    void RemoveInfoFromCellKeyMap(NavMeshInfo* apNavMeshInfo);
    void RemoveInfoFromCellKeyMap(unsigned int apNavMeshInfo);
    void RemoveInfoFromCellKeyMap(NavigationRequest* apNavMeshInfo);
};
