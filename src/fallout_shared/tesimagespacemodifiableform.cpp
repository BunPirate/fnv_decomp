// fallout_shared/tesimagespacemodifiableform.cpp: TESImageSpaceModifiableForm (5 functions)

#include "../../include/BaseFormComponent.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/TESForm.h"
#include "../../include/TESImageSpaceModifiableForm.h"
#include "../../include/TESImageSpaceModifier.h"

int Warning(const char*, ...);

// Resolves the stored form ID to a TESImageSpaceModifier via the owner's file and warns if it cannot be found.
// @fnv 0x00487490
// pdb: TESImageSpaceModifiableForm::InitItem | TESImageSpaceModifiableForm.obj | retail, upstream name already matches, high
// pdb params: apOwner
// pdb locals: uitemp
void TESImageSpaceModifiableForm::InitItem(TESForm* apOwner)
{
    if (pFormImageSpaceModifying)
    {
        unsigned int formID = (unsigned int)pFormImageSpaceModifying;
        if (apOwner)
            TESForm::RemapFormIDForFile(formID, apOwner->GetFile(-1));
        pFormImageSpaceModifying = dynamic_cast<TESImageSpaceModifier*>(TESForm::GetFormByID(formID));
        if (!pFormImageSpaceModifying)
        {
            if (apOwner)
            {
                if (((BGSCameraPath*)apOwner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on owner object \"%s\".", formID,
                            apOwner->GetName());
                else
                    Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on owner object (%08X).", formID,
                            apOwner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find imagespacemodifier (%08X) on unknown owner.", formID);
        }
    }
}

// Initialises the base component and clears the image space modifier.
// @fnv 0x00487420
// pdb: TESImageSpaceModifiableForm::TESImageSpaceModifiableForm | TESImageSpaceModifiableForm.obj | debug, upstream name already matches, high
TESImageSpaceModifiableForm::TESImageSpaceModifiableForm()
{
    ClearComponent();
}

extern "C" void TESForm_AddChunk_00485910(unsigned int, unsigned int);

// @fnv 0x00487450
// pdb: TESImageSpaceModifiableForm::Save | TESImageSpaceModifiableForm.obj | debug, upstream name already matches, high
// pdb locals: uitemp
void TESImageSpaceModifiableForm::Save()
{
    if (pFormImageSpaceModifying)
    {
        unsigned int id = pFormImageSpaceModifying->GetFormID();
        TESForm_AddChunk_00485910(0x4D414E4D, id);
    }
}

// @fnv 0x00487570
// pdb: TESImageSpaceModifiableForm::CopyComponent | TESImageSpaceModifiableForm.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pcopy
void TESImageSpaceModifiableForm::CopyFromBase(BaseFormComponent* apCopyFC)
{
    TESImageSpaceModifiableForm* pHelper = dynamic_cast<TESImageSpaceModifiableForm*>(apCopyFC);
    if (pHelper == 0)
    {
    }
    else
    {
        this->SetFormImageSpaceModifying(pHelper->GetFormImageSpaceModifying());
    }
}

// Returns true if the cast fails or the two modifier getters return different values.
// @fnv 0x004875c0
// pdb: TESImageSpaceModifiableForm::CompareComponent | TESImageSpaceModifiableForm.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pcompare
bool TESImageSpaceModifiableForm::CompareWithBase(BaseFormComponent* apCompareFC)
{
    TESImageSpaceModifiableForm* pCompareImageSpaceForm = dynamic_cast<TESImageSpaceModifiableForm*>(apCompareFC);
    if (!pCompareImageSpaceForm)
        return true;
    if (this->GetFormImageSpaceModifying() != pCompareImageSpaceForm->GetFormImageSpaceModifying())
        return true;
    return false;
}
