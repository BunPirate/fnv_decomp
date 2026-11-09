// fallout_shared/bgsrepairitemlist.cpp: BGSRepairItemList (6 functions)

#include "../../include/BaseFormComponent.h"
#include "../../include/TESFile.h"

#include "../../include/BGSCameraPath.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSRepairItemList.h"
#include "../../include/TESForm.h"

int Warning(const char*, ...);

// The shared class has no accessor declaration for this out-of-line getter yet.
BGSListForm* __fastcall GetRepairItemList(BGSRepairItemList* component);

// Resolves pListForm's form ID to a BGSListForm and warns if the lookup fails, naming the owner when available.
// @fnv 0x0047b8e0
// pdb: BGSRepairItemList::InitItem | BGSRepairItemList.obj | retail, string-set bridge, high
// pdb params: apOwner
// pdb locals: itempint, pownerFile
void BGSRepairItemList::InitItem(TESForm* apOwner)
{
    unsigned int formID = (unsigned int)pListForm;
    if (formID)
    {
        TESFile* file = apOwner ? apOwner->GetFile(-1) : 0;
        TESForm::RemapFormIDForFile(formID, file);
        pListForm = dynamic_cast<BGSListForm*>(TESForm::GetFormByID(formID));
        if (!pListForm)
        {
            if (apOwner)
            {
                if (((BGSCameraPath*)apOwner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find repair item list (%08X) for owner object \"%s\".", formID,
                            apOwner->GetName());
                else
                    Warning("MASTERFILE: Unable to find repair item list (%08X) for owner object (%08X).", formID,
                            apOwner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find repair item list (%08X) for unknown owner.", formID);
        }
    }
}

// @fnv 0x0047b850
// pdb: BGSRepairItemList::BGSRepairItemList | BGSRepairItemList.obj | debug, upstream name already matches, high
BGSRepairItemList::BGSRepairItemList()
{
    BGSRepairItemList::InitializeComponent();
}

// @fnv 0x0047b880
// pdb: BGSRepairItemList::~BGSRepairItemList | BGSRepairItemList.obj | debug, upstream name already matches, high
BGSRepairItemList::~BGSRepairItemList()
{
    BGSRepairItemList::Free();
}

void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
// @fnv 0x0047b8a0
// src: XBOX_DEBUG_PDB 0x0047b8a0
// pdb: BGSRepairItemList::Save | BGSRepairItemList.obj | debug, call graph, high
// pdb locals: tempint
void __fastcall BGSRepairItemList_Save(BGSRepairItemList* component)
{
    unsigned int formID;
    if (component->pListForm != 0)
    {
        formID = component->pListForm->GetFormID();
        TESForm_AddChunk_00485910(0x4C504552, formID);
    }
}

// Copies the repair list when the source component is a BGSRepairItemList.
// @fnv 0x0047b9d0
// pdb: BGSRepairItemList::CopyComponent | BGSRepairItemList.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pcopy
void BGSRepairItemList::CopyFromBase(BaseFormComponent* apCopyFC)
{
    BGSRepairItemList* pcopy = dynamic_cast<BGSRepairItemList*>(apCopyFC);
    if (!pcopy)
        return;
    SetRepairItemList(GetRepairItemList(pcopy));
}

// Returns true if the component has a different repair list or component type.
// @fnv 0x0047ba20
// pdb: BGSRepairItemList::CompareComponent | BGSRepairItemList.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pcomp
bool BGSRepairItemList::CompareWithBase(BaseFormComponent* apCompareFC)
{
    BGSRepairItemList* other = dynamic_cast<BGSRepairItemList*>(apCompareFC);
    if (!other)
        return true;
    if (GetRepairItemList(other) != GetRepairItemList(this))
        return true;
    return false;
}
