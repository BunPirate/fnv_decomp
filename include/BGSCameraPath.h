#pragma once

#include "TESForm.h"
#include "PerkEntryConditionSet.h"
#include "CameraShotData.h"
#include "MagicTarget.h"

class BGSCameraShot;
class NiFormArray;
class CameraPathMap;
class CameraResponse;
class CameraFlag;

// pdb: class BGSCameraPath, size 0x38, bases: TESForm, 6 members
class BGSCameraPath : public TESForm
{
public:
    PerkEntryConditionSet Conditions;
    BSSimpleList<BGSCameraShot*> ShotList; // src: XBOX_RETAIL_PDB +0x20 (old: m_kCameraShotList)
    CameraShotData data;
    unsigned char layoutPadding29[3];
    NiFormArray* pChildPaths; // src: XBOX_RETAIL_PDB +0x2c (old: m_pPathArray)
    BGSCameraPath* pParentPath; // src: XBOX_RETAIL_PDB +0x30 (old: m_pFirstCameraPath)
    BGSCameraPath* pPrevPath; // src: XBOX_RETAIL_PDB +0x34 (old: m_pSecondCameraPath)

    BGSCameraPath();
    virtual ~BGSCameraPath();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* apFile);
    bool InitParents();
    NiFormArray* CreateChildArray();
    void ResetFormData();
    void AssignParentPath(BGSCameraPath* parent);
    BGSCameraPath* GetPrevPath();
    BGSCameraPath* GetCameraPathAt(unsigned int);
    void FixNextPaths(NiFormArray* apArray);
    int HasNameForWarning();
    BSSimpleList<BGSCameraShot*>* GetShotList();
    PerkEntryConditionSet* GetConditions();
    const char* GetEditorID();

    void CopyCommonData(TESForm* src);
    void CopyFromForm(TESForm* apCopy);
    void Save_0058ac10();
    bool Compare_0058a750(TESForm* apCompare);
    TESForm* CreateDuplicateForm(bool abCreateEditorID, CameraPathMap* apCopyMap);
    TESForm* CreateBaseClone(bool abCreateEditorID, CameraPathMap* apCopyMap);

    bool IsFlag2Set();
    bool IsFlag80Set();
    bool GetZoomDefault();
    bool GetZoomDisable();
    bool FUN_00440d80();
    CameraResponse* FUN_00500940(unsigned int context, unsigned int flags);
    CameraFlag* FUN_00891170();
    BGSCameraPath* GetCameraPathToPlay(unsigned int apActionRef, unsigned int apTargetRef);

    BGSCameraPath* GetParentPath();
    void RemoveChild(BGSCameraPath* apChild);
    BGSCameraPath* GetPrevPathStub();
    void SetPrevPathStub(BGSCameraPath* prev);
    unsigned int GetChildCount();
    BGSCameraPath* GetChildAt(unsigned int aiIndex);
    void SetParentStub(BGSCameraPath* parent);
    void SetParentPath(BGSCameraPath* apParent);
    void SetPrevPathForm(BGSCameraPath* apPrev);
};
