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
    SaveMetadata SaveStruct;
    unsigned char layoutPadding3E[2];
    RagdollAnimationData FeedbackData;
    FootIK_DATA FootIKData;
    LookIK_DATA LookIKData;
    GrabIK_DATA GrabIKData;
    RagdollFeedbackProfile PoseMatchingData;
    int iSkeletonID;
    BGSBodyPartData* pBodyPartData;
    TESActorBase* pPreviewActor;

    BGSRagdoll();
    virtual ~BGSRagdoll();
    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem(void);

    void ResetFormData();
    bool Load(TESFile* file);
};
