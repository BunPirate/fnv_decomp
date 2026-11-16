#pragma once

// pdb: class CombatFormulas, size 0x1, 0 members
class CombatFormulas // src: XBOX_RETAIL_PDB 0x00644a70 (first of 34 linked methods; old: CombatDamageCalculator)
{
  public:
    static float CalculateWeaponDamage(ActorValueOwner*, TESObjectWEAP*, float, bool, InventoryStackRecord*, bool, bool, int,
                                       float, float, bool, bool, TESAmmo*);
    static float CalculateWeaponDamageForActor(TESObjectREFR*, TESObjectWEAP*, bool, InventoryStackRecord*);
    static float GetWeaponConditionDamageMultiplier(int);
    static float GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
    static float GetDamageMultiplier(float, float);
    static float CalculateArmorDamageThreshold(unsigned short asArmorRating, float afcondition);
};
