// fallout_shared/tesenchantableform.cpp: TESEnchantableForm (7 functions)

#include "../../include/TESEnchantableForm.h"
#include "../../include/EnchantmentItem.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/TESForm.h"

TESForm* GetFormByID(unsigned int formID);
int Warning(const char* format, ...);

// @fnv 0x004830a0
// pdb: TESEnchantableForm::TESEnchantableForm | TESEnchantableForm.obj | debug, upstream name already matches, high
TESEnchantableForm::TESEnchantableForm()
{
    InitializeComponent();
}

// Resolves the form's enchantment by form ID, warns when it is missing or has an invalid effect trigger, and clears it on failure.
// @fnv 0x00483210
// pdb: TESEnchantableForm::InitItem | TESEnchantableForm.obj | retail, string-set bridge, high
// pdb params: apOwner
// pdb locals: tempint
void TESEnchantableForm::InitItem(TESForm* apOwner)
{
    if (pFormEnchanting)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(pFormEnchanting);
        if (apOwner)
            TESForm::RemapFormIDForFile(formID, apOwner->GetFile(-1));

        pFormEnchanting = dynamic_cast<EnchantmentItem*>(GetFormByID(formID));
        if (!pFormEnchanting)
        {
            if (apOwner)
            {
                if (reinterpret_cast<BGSCameraPath*>(apOwner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find enchanting (%08X) on owner object \"%s\".", formID,
                            apOwner->GetName());
                else
                    Warning("MASTERFILE: Unable to find enchanting (%08X) on owner object (%08X).", formID,
                            apOwner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find enchanting (%08X) on unknown owner.", formID);
        }

        if (pFormEnchanting && apOwner && !pFormEnchanting->FUN_004094f0(apOwner))
        {
            Warning(
                "MASTERFILE: Enchanting (%08X) '%s' has invalid effect trigger type or effect for object (%08X) '%s'.",
                pFormEnchanting->GetFormID(), pFormEnchanting->GetName(), apOwner->GetFormID(), apOwner->GetName());
            pFormEnchanting = 0;
        }
    }
}

// @fnv 0x00483170
void TESEnchantableForm::SetFormEnchantmentAmount(unsigned short amount)
{
    iAmountofEnchantment = amount;
}

void __cdecl TESForm_AddChunk_00485910(unsigned int a, unsigned int b);
void __cdecl TESForm_AddChunk_00485950(unsigned int aeChunkID, unsigned int aiData);

// @fnv 0x0047bd70
// pdb: TESEnchantableForm::Save | TESEnchantableForm.obj | retail, upstream name already matches, high
// pdb locals: tempint
void TESEnchantableForm::Save()
{
    unsigned int tempint;
    if (pFormEnchanting != 0)
    {
        tempint = pFormEnchanting->GetFormID();
        TESForm_AddChunk_00485910(0x4d544945, tempint);
    }
    if (iAmountofEnchantment != 0)
    {
        TESForm_AddChunk_00485950(0x544d4145, iAmountofEnchantment);
    }
}

// Clears the enchantment form's fields, setting the casting type to 4 and zeroing the other two members.
// @fnv 0x004830d0
void TESEnchantableForm::InitializeComponent()
{
    pFormEnchanting = 0;
    iAmountofEnchantment = 0;
    eCastingType = MagicSystem__CastingType_CASTING_COUNT;
}


// Returns true when the cast fails or the enchantment or enchantment amount differs.
// @fnv 0x00483190
// pdb: TESEnchantableForm::CompareComponent | TESEnchantableForm.obj | retail, vtable slot, high
// pdb params: apCompareFC
// pdb locals: pCompare
bool TESEnchantableForm::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    TESEnchantableForm* other = dynamic_cast<TESEnchantableForm*>(apCompareFC);
    if (!other)
        return true;
    if (GetEnchantment() != other->GetEnchantment())
        return true;
    if (GetFormEnchantmentAmount() != other->GetFormEnchantmentAmount())
        return true;
    return false;
}

// Casts apComponent to TESEnchantableForm and copies its enchantment, enchantment amount and casting type onto this form.
// @fnv 0x00483100
// pdb: TESEnchantableForm::CopyComponent | TESEnchantableForm.obj | retail, vtable slot, high
// pdb params: apCopyFC
// pdb locals: pCopy
void TESEnchantableForm::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESEnchantableForm* pForm = dynamic_cast<TESEnchantableForm*>(apCopyFC);
    if (!pForm)
        return;
    SetFormEnchanting(pForm->GetEnchantment());
    SetFormEnchantmentAmount(pForm->GetFormEnchantmentAmount());
    SetCastingType(pForm->GetCastingType());
}
