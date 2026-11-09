#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "TESImageSpaceModifiableForm.h"
#include "BGSCameraShot__CAMERA_SHOT_DATA.h"
#include "NiAVObject.h"
#include "NiPoint3.h"

class TESObjectREFR;
class NiNode;

// pdb: class BGSCameraShot, size 0x78, bases: TESForm, TESModel, TESImageSpaceModifiableForm, 9 members
class BGSCameraShot : public TESForm, public TESModel, public TESImageSpaceModifiableForm
{
public:
    BGSCameraShot();
    virtual ~BGSCameraShot();
    virtual void ClearData();
    virtual bool LoadForm2(TESFile* file);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* apFile);
    void ResetCameraShot();
    void ResetFormData();
    void InitCamera(void* apTargetRef, int aeZoom);
    void Update(float time);
    NiPoint3 GetTargetPos();
    bool IsNotFlag4Set();
    bool IsInitialized();
    float TESCombatStyle_GetTargetingFOV();

    BGSCameraShot__CAMERA_SHOT_DATA Data;
    NiPointer<NiAVObject> spLocationNode;
    NiPointer<NiAVObject> spTargetNode;
    TESObjectREFR* pTargetRef;
    NiPointer<NiNode> spCameraNode;
    NiPointer<NiAVObject> spImagespaceTarget;
    char cCameraHasRotation;
    bool bCameraTooClose;
    bool bCameraIsKillCam;
    unsigned char layoutPadding77[1];
};
