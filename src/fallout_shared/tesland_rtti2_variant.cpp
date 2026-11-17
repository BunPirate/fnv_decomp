
// src/fallout_shared/tesland_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py (flags of tesland_od_variant.cpp) for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesland.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesland_decls.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectLAND.h"
#pragma optimize("", off)
int TruncateFloatToInt(float value);

struct LandDuplicateCalls
{
    ::TESForm* TESForm_CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap);
};
struct LandDuplicateEntry : LandDuplicateCalls
{
    ::TESForm* TESObjectLAND_CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap);
};
// @fnv 0x00534880
// src: XBOX_PDB 0x00534880
// pdb: TESObjectLAND::CreateDuplicateForm | TESLand.obj | retail, upstream name already matches, high
// pdb params: abCreateEditorID, apCopyMap
// pdb locals: pdupland
::TESForm* LandDuplicateEntry::TESObjectLAND_CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap)
{
    ::TESObjectLAND* duplicate;
    duplicate = dynamic_cast< ::TESObjectLAND*>(TESForm_CreateDuplicateForm(false, apCopyMap));
    return duplicate;
}

extern void* DAT_01187020;

TESForm* TESForm_GetFormByNumericID(unsigned int auiFormId);

struct LandSaveGroup5391
{
    void* typeTag;
    unsigned int unk04;
    unsigned int formID;
    unsigned int groupType;
};

struct FUN_005391d0_class
{
    TESObjectCELL* __thiscall BGSSaveFormBuffer_GetForm();
    bool __thiscall TESObjectLAND_SavesBefore_005391d0(LandSaveGroup5391* apGroupFORM);
};

// @fnv 0x005391d0
// src: XBOX_PDB 0x005391d0
// pdb: TESObjectLAND::SavesBefore | TESLand.obj | retail, vtable slot, high
// pdb params: apForm
// pdb locals: bretval, pformcell, pcellchild, pref
bool FUN_005391d0_class::TESObjectLAND_SavesBefore_005391d0(LandSaveGroup5391* apGroupFORM)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->typeTag == DAT_01187020)
    {
        switch (apGroupFORM->groupType)
        {
        case 8:
        case 9: {
            void* found = dynamic_cast< ::TESObjectCELL*>(TESForm_GetFormByNumericID(apGroupFORM->formID));
            if (found && BGSSaveFormBuffer_GetForm() == found)
                bretval = false;
            break;
        }
        default: {
            TESObjectCELL* pCell = BGSSaveFormBuffer_GetForm();
            bretval = pCell->Unk_0E(apGroupFORM);
            break;
        }
        }
    }
    return bretval;
}
