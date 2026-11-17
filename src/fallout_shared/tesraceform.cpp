// fallout_shared/tesraceform.cpp: TESRaceForm, TESNPC, ActorValue, TESActorBase (5 functions)

#include "../../include/ActorBaseAttributes.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/FileEntryList.h"
#include "../../include/PackageList.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESContainer.h"
#include "../../include/TESModel.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObject.h"
#include "../../include/TESRace.h"
#include "../../include/TESRaceForm.h"
#include "../../include/TESSpellList.h"

TESForm* __cdecl GetFormByID(unsigned int formID);
int __cdecl Warning(const char* format, ...);

namespace ActorValue {
bool IsSkill(Index actorValue);
unsigned char ToArrayIndex(int section, Index actorValue);
}

// Resolves the stored race form ID against the owner's file, looks up the TESRace, and warns if the race cannot be found.
// @fnv 0x0048b920
// pdb: TESRaceForm::InitItem | TESRaceForm.obj | retail, string-set bridge, high
// pdb params: apOwner
// pdb locals: itempint
void TESRaceForm::InitItem(TESForm* apOwner)
{
    if (m_pRace)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pRace);
        TESForm::RemapFormIDForFile(formID, apOwner->GetFile(-1));
        m_pRace = dynamic_cast<TESRace*>(GetFormByID(formID));
        if (!m_pRace)
        {
            if (apOwner)
            {
                if (reinterpret_cast<BGSCameraPath*>(apOwner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find race (%08X) on owner object \"%s\".", formID, apOwner->GetName());
                else
                    Warning("MASTERFILE: Unable to find race (%08X) on owner object (%08X).", formID,
                            apOwner->GetFormID());
            }
            else
            {
                Warning("MASTERFILE: Unable to find race (%08X) on unknown owner.", formID);
            }
        }
    }
}

// Returns a skill value from kData arrays (plus offset unless IsAutoCalculated), otherwise delegates to ActorValueOwner::GetActorValue.
// @fnv 0x00607850
// pdb: TESNPC::GetActorValue | TESNPC.obj | retail, upstream name already matches, high
// pdb params: aiWhich
// pdb locals: iresult, i
int TESNPC::GetActorValue(ActorValue::Index aiWhich)
{
    int value = 0;
    if (ActorValue::IsSkill(aiWhich))
    {
        int skillIndex = static_cast<signed char>(ActorValue::ToArrayIndex(2, aiWhich));
        value = kData.ucSkillValues[skillIndex];
        if (!static_cast<const TESNPC*>(this)->IsAutoCalculated())
            value += kData.ucSkillOffsets[skillIndex];
    }
    else
    {
        value = ActorValueOwner::GetActorValue(aiWhich);
    }
    return value;
}

// Casts component to TESRaceForm and, if successful, sets this form's race to the component's race.
// @fnv 0x0048b870
// pdb: TESRaceForm::CopyComponent | TESRaceForm.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pcopy
void TESRaceForm::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESRaceForm* raceForm = dynamic_cast<TESRaceForm*>(apCopyFC);
    if (!raceForm)
        return;
    SetFormRace(raceForm->GetFormRace());
}

// Returns the actor value for the given ActorValue::Index converted to float.
// @fnv 0x005f7480
// pdb: TESActorBase::GetActorFloatValue | TESCreature.obj | retail, vtable slot, high
// pdb params: aiWhich
float TESActorBase::GetCurrentActorValue(ActorValue::Index aiWhich)
{
    return static_cast<float>(GetActorValue(aiWhich));
}

// Returns true if apCompareFC is not a TESRaceForm or its race differs from this form's race; otherwise false.
// @fnv 0x0048b8c0
// pdb: TESRaceForm::CompareComponent | TESRaceForm.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pcompare
bool TESRaceForm::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    TESRaceForm* pcompare = dynamic_cast<TESRaceForm*>(apCompareFC);
    if (!pcompare)
        return true;
    if (this->GetFormRace() != pcompare->GetFormRace())
        return true;
    return false;
}
