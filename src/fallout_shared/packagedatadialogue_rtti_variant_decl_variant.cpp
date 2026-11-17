#include "../../include/TESDialoguePackageData.h"

struct TargetLocation
{
    unsigned char type;
    unsigned char unk01, unk02, unk03;
    unsigned int data;
    float radius;
    TargetLocation();
    ~TargetLocation();
    void FUN_0067f4d0(TargetLocation*, int);
};
// The shared class does not declare this copy overload. Keep its implementation
// in a fieldless derived helper so all data layout comes from the shared class.
struct DialoguePackageDataCopy : TESDialoguePackageData
{
    void Copy(TESPackageData*);
};
// @fnv 0x0067b310
// pdb: TESDialoguePackageData::Copy | PackageDataDialogue.obj | retail, vtable slot, high
// pdb params: apCopy
// pdb locals: pcopy
void DialoguePackageDataCopy::Copy(TESPackageData* apCopy)
{
    TESDialoguePackageData* source = dynamic_cast<TESDialoguePackageData*>(apCopy);
    if (source)
    {
        fFov = source->fFov;
        fDistanceStartTalking = source->fDistanceStartTalking;
        bNOHeadtracking = source->bNOHeadtracking;
        if (pTargetLocation)
        {
            delete pTargetLocation;
            pTargetLocation = 0;
        }
        if (source->pTargetLocation)
        {
            pTargetLocation = new TargetLocation;
            pTargetLocation->FUN_0067f4d0(source->pTargetLocation, 0);
        }
        ptopic = source->ptopic;
        bDoNotControlTarget = source->bDoNotControlTarget;
        bSayTo = source->bSayTo;
        eTriggerType = source->eTriggerType;
    }
}
