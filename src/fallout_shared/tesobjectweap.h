#ifndef FNV_TESOBJECTWEAP_HEADER_UNIT_H
#define FNV_TESOBJECTWEAP_HEADER_UNIT_H

#include "tesobjectweap_types.h"

// @fnv 0x00521690
void TESObjectWEAP::SetMeleeBlockSound(TESSound* sound)
{
    pMeleeBlockSound = sound;
}

// @fnv 0x004be380
// pdb: TESEnchantableForm::GetFormEnchantmentAmount | InventoryChanges.obj | debug, object-file run extension, low
// pdb params: apForm
// pdb locals: pEF
float TESObjectWEAP::GetWeightForForm(bool modded)
{
    if (modded)
    {
        return TESWeightForm::GetWeightForForm() -
               GetModdedWeaponValue(WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_WEIGHT, 0);
    }
    else
    {
        return TESWeightForm::GetWeightForForm();
    }
}
#endif
