#include "../../include/TESEnchantableForm.h"
#include "../../include/TESForm.h"

// @fnv 0x004be330
// pdb: TESEnchantableForm::GetFormEnchanting | InventoryChanges.obj | debug, call graph, high
// pdb params: apForm
// pdb locals: pEF
EnchantmentItem* TESEnchantableForm::FindFormEnchantment(TESForm* apForm)
{
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(apForm);
    return enchantable ? enchantable->GetEnchantment() : 0;
}
