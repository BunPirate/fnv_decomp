// src/fallout_shared/packagedatadialogue_rtti2_variant.cpp - dialogue package RTTI comparison.

#include "../../include/TESDialoguePackageData.h"

struct DialogueTargetComparison
{
    bool PackageLocation_Compare(DialogueTargetComparison*);
};

// The shared class supplies the entire layout; this adapter declares only the
// comparison method that is not yet declared by the shared header.
struct DialoguePackageComparison : TESDialoguePackageData
{
    bool TESDialoguePackageData_Compare(void*);
};

// @fnv 0x0067b470
// src: XBOX_PDB 0x0067b470
// pdb: TESDialoguePackageData::Compare | PackageDataDialogue.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool DialoguePackageComparison::TESDialoguePackageData_Compare(void* apCompare)
{
    DialoguePackageComparison* other = reinterpret_cast<DialoguePackageComparison*>(
        dynamic_cast< ::TESDialoguePackageData*>(static_cast< ::TESPackageData*>(apCompare)));

    if (other == 0)
        return true;

    if (fFov != other->fFov)
        return true;

    if (fDistanceStartTalking != other->fDistanceStartTalking)
        return true;

    if (bNOHeadtracking != other->bNOHeadtracking)
        return true;

    if (ptopic != other->ptopic)
        return true;

    if (pTargetLocation != 0)
    {
        if (reinterpret_cast<DialogueTargetComparison*>(pTargetLocation)->PackageLocation_Compare(
                reinterpret_cast<DialogueTargetComparison*>(other->pTargetLocation)))
            return true;
    }
    else if (other->pTargetLocation != 0)
    {
        return true;
    }

    if (bDoNotControlTarget != other->bDoNotControlTarget)
        return true;

    if (bSayTo != other->bSayTo)
        return true;

    if (eTriggerType != other->eTriggerType)
        return true;

    return false;
}
