#pragma once

#include "TESForm.h"
#include "TESModel.h"
#include "SaveMetadata.h"
#include "RagdollAnimationData.h"
#include "FootIK_DATA.h"
#include "LookIK_DATA.h"
#include "GrabIK_DATA.h"
#include "RagdollFeedbackProfile.h"
#include "BGSBodyPartData.h"

class TESActorBase;

// pdb: class BGSRagdoll, size 0x148, bases: TESForm, TESModel, 9 members
class BGSRagdoll : public TESForm, public TESModel
{
public:
    SaveMetadata SaveStruct; // src: XBOX_RETAIL_PDB +0x30 (old: ActorAnimationData)
    unsigned char layoutPadding3E[2];
    RagdollAnimationData FeedbackData; // src: XBOX_RETAIL_PDB +0x40 (old: m_kRagdollAnimationData)
    FootIK_DATA FootIKData; // src: XBOX_RETAIL_PDB +0x90 (old: m_kFootIKData)
    LookIK_DATA LookIKData; // src: XBOX_RETAIL_PDB +0xd0 (old: m_kLookIKData)
    GrabIK_DATA GrabIKData; // src: XBOX_RETAIL_PDB +0xf4 (old: m_kGrabIKData)
    RagdollFeedbackProfile PoseMatchingData; // src: XBOX_RETAIL_PDB +0x118 (old: m_kRagdollFeedbackProfile)
    int iSkeletonID; // src: XBOX_RETAIL_PDB +0x13c (old: m_iRagdollType)
    BGSBodyPartData* pBodyPartData; // src: XBOX_RETAIL_PDB +0x140 (old: m_pBodyPartDataCur)
    TESActorBase* pPreviewActor; // src: XBOX_RETAIL_PDB +0x144 (old: m_pActorBase)

    BGSRagdoll();
    virtual ~BGSRagdoll();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem(void);

    void ResetFormData();
    bool Load(TESFile* file);
};
