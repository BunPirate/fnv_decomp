#include "../../../../include/CombatProcedureSwitchWeapon.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/CombatController.h"
#include "../../../../include/TESForm.h"
#include "../../../../include/TESObjectWEAP.h"

// src/fallout/ai/combat/combatprocedureswitchweapon.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureswitchweapon.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Actor/state helpers use their original one-register calling convention.
Actor* __fastcall GetCombatProcedureActor(CombatProcedure*);
void __fastcall SetCombatProcedureState(CombatProcedure*);

// @fnv 0x009da7a0
// pdb: CombatProcedureSwitchWeapon::~CombatProcedureSwitchWeapon | CombatProcedureSwitchWeapon.obj | debug, upstream name already matches, high
CombatProcedureSwitchWeapon::~CombatProcedureSwitchWeapon()
{
}

// Saves the base combat procedure, then writes pWeapon and the 1-byte field at offset 0x14 to the save buffer.
// @fnv 0x009da970
// pdb: CombatProcedureUseCombatItem::SaveGame | CombatProcedureUseCombatItem.obj | retail, vtable slot, high
// pdb params: apSaveGameBuffer
void CombatProcedureSwitchWeapon::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    CombatProcedure::SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData(pWeapon, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0x14, 1, 0);
}

void __cdecl Deallocate(void*);
// Calls the destructor, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x009da770
// pdb: CombatProcedureSwitchWeapon::`scalar deleting destructor' | CombatProcedureSwitchWeapon.obj | debug, vtable slot, medium
void* CombatProcedureSwitchWeapon::DestroyIfFlagged(unsigned int flags)
{
    this->~CombatProcedureSwitchWeapon();
    if (flags & 1)
        Deallocate(this);
    return this;
}

TESForm* __cdecl _ref_004839c0(unsigned int);
// Loads the base combat procedure state, resolves the weapon form from the buffer, and reads one byte into the field at offset 0x14.
// @fnv 0x009da9b0
// pdb: CombatProcedureSwitchWeapon::LoadGame | CombatProcedureSwitchWeapon.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void CombatProcedureSwitchWeapon::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    CombatProcedure::LoadGame(apLoadGameBuffer);
    pWeapon = dynamic_cast<TESObjectWEAP*>(_ref_004839c0(((BGSLoadGameBuffer*)apLoadGameBuffer)->ReadFormIdentifier()));
    apLoadGameBuffer->ReadTypedData((char*)this + 0x14, 1u);
}

// Calls the base constructor, installs the vtable, stores apWeapon in pWeapon and clears the byte flag.
// @fnv 0x009da720
// pdb: CombatProcedureSwitchWeapon::CombatProcedureSwitchWeapon | CombatProcedureSwitchWeapon.obj | debug, upstream name already matches, high
// pdb params: apWeapon
CombatProcedureSwitchWeapon::CombatProcedureSwitchWeapon(TESObjectWEAP* apWeapon)
{
    pWeapon = apWeapon;
    bEquipQueued = 0;
}

struct ExtraDataList;
struct InvEntry
{
    TESForm* FUN_0044ddc0();
    ExtraDataList* FUN_00726070();
};
bool __fastcall TESObjectWEAP_IsThrownWeapon(TESForm*);
bool __fastcall TESObjectWEAP_IsMeleeWeapon(TESForm*);
// @fnv 0x009da7c0
// pdb: CombatProcedureSwitchWeapon::Update | CombatProcedureSwitchWeapon.obj | retail, vtable slot, high
// pdb locals: pcurrentWeaponItem, pcurrentWeapon, pattacker, icount
void CombatProcedureSwitchWeapon::UpdateWeaponDraw()
{
    if (pCombatController->IsFleeing_00981990())
    {
        SetCombatProcedureState(this);
        return;
    }
    Actor* actor = GetCombatProcedureActor(this);
    if (actor->GetAnimAction_008a7570() != -1)
        return;
    InvEntry* entry = reinterpret_cast<InvEntry*>(reinterpret_cast<BaseProcess*>(actor->FUN_008d8520())->GetActiveWeapon());
    TESForm* weap = entry ? entry->FUN_0044ddc0() : 0;
    if (!bEquipQueued && weap != pWeapon)
    {
        if (reinterpret_cast<BaseProcess*>(actor->FUN_008d8520())->IsAdditionalActorFlagSet())
        {
            actor->Actor_SetWantWeaponDrawn(false);
            return;
        }
        if (pWeapon)
        {
            int count = 1;
            if (TESObjectWEAP_IsThrownWeapon(pWeapon))
                count = actor->FUN_00575610(pWeapon);
            actor->Actor_QueueEquipObject(pWeapon, count, 0, true, false, true);
        }
        else
        {
            actor->QueueUnEquipObject(weap, entry->FUN_00726070(), false, false, false, true);
        }
        bEquipQueued = true;
    }
    else if (weap == pWeapon)
    {
        if (!reinterpret_cast<BaseProcess*>(actor->FUN_008d8520())->IsAdditionalActorFlagSet())
            actor->Actor_SetWantWeaponDrawn(true);
        if (!weap || TESObjectWEAP_IsMeleeWeapon(weap))
            pCombatController->DeterminePowerAttackDeltas();
        SetCombatProcedureState(this);
    }
}
