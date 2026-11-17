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
    NiPointer<NiAVObject> spLocationNode; // src: XBOX_RETAIL_PDB +0x60 (old: m_pLocationNode)
    NiPointer<NiAVObject> spTargetNode; // src: XBOX_RETAIL_PDB +0x64 (old: m_pTargetNode)
    TESObjectREFR* pTargetRef; // src: XBOX_RETAIL_PDB +0x68 (old: m_pReference)
    NiPointer<NiNode> spCameraNode; // src: XBOX_RETAIL_PDB +0x6c (old: m_spPositionNode)
    NiPointer<NiAVObject> spImagespaceTarget; // src: XBOX_RETAIL_PDB +0x70 (old: m_pSceneObject)
    char cCameraHasRotation; // src: XBOX_RETAIL_PDB +0x74 (old: m_bUpdateNodePosition)
    bool bCameraTooClose; // src: XBOX_RETAIL_PDB +0x75 (old: m_bFlag74)
    bool bCameraIsKillCam; // src: XBOX_RETAIL_PDB +0x76 (old: m_bFlag75)
    unsigned char layoutPadding77[1];
};
