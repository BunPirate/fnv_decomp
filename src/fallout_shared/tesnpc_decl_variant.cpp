// the shared NiTArray first: NiNode.h then takes it (its own copy is only for units without one)
#include "../../include/NiTArray.h"

// src/fallout_shared/tesnpc_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x006047c0: the skeleton of src/fallout_shared/tesnpc.cpp
// with declarations corrected to what the original code does (TESNPC += void FUN_006047c0(TESObjectREFR* pRef, bool b1, bool b2, bool b3, bool b4);). Move the function to its real unit once
// that unit declares it this way.

// Shared headers use the Windows types.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "../../include/BaseProcess.h"
#include "../../include/Actor.h"
#include "../../include/ActorBaseAttributes.h"
#include "../../include/ActorSkillData.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSHeadPart.h"
#include "../../include/BGSListForm.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/BSFaceGenAnimationData.h"
#include "../../include/BSFaceGenNiNode.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/CombatController.h"
#include "../../include/ExtraDataList.h"
#include "../../include/ExtraDismemberedLimbs.h"
#include "../../include/MagicCaster.h"
#include "../../include/MobileObject.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiNode.h"
#include "../../include/NiUpdateData.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESClass.h"
#include "../../include/TESCombatStyle.h"
#include "../../include/TESContainer.h"
#include "../../include/TESEyes.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHair.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESPackage.h"
#include "../../include/TESRace.h"
#include "../../include/TESRaceForm.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSpellList.h"
#include "../../include/TESTopic.h"
#include "../../include/BSSimpleList.h"
#include "../../include/InventoryChanges.h"
#include "../../include/InventoryStackRecord.h"

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x006047c0
// src: XBOX_PDB 0x006047c0
// pdb: TESNPC::InitDefaultWorn | TESNPC.obj | retail, upstream name already matches, high
// pdb params: apRef, abArmor, abWeapon, abOnlyifClothes, abAllowChanges
// pdb locals: pinv, brestoreAllowChanges, pitemChange, pextra, pactor, pupperModel, n, bwear, pobj, pmodel, pweapon, fval, bdelete, pact
void TESNPC::InitDefaultWorn(TESObjectREFR* apRef, bool a3, bool a4, bool a5, bool a6)
{
    InventoryChanges* j;
    InventoryStackRecord* item;
    bool bAllowed;
    bAllowed = true;
    if (a6 == 0)
    {
        bAllowed = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
    }
    if (apRef->IsActor())
    {
        apRef->FUN_00571b50();
    }
    j = InventoryChanges::GetOrAddInventoryChanges(apRef);
    j->RemoveWornItems(true, apRef);
    Actor* pBiped;
    pBiped = (Actor*)apRef;
    if (pBiped->GetProcess())
    {
        pBiped->GetProcess()->SetCurrentAmmunition(NULL);
        pBiped->GetProcess()->SetCurrentShield(NULL);
        pBiped->GetProcess()->SetCurrentTorch(NULL);
        pBiped->GetProcess()->SetCurrentArmor(NULL, NULL, false);
    }
    TESBipedModelForm* res = NULL;
    ExtraDataList* pExtra = NULL;
    for (int i = 0; i < 20; i++)
    {
        item = j->FindBestArmor(this, i, true);
        if (item)
        {
            bool val = true;
            TESBoundObject* p;
            p = item->FUN_0044ddc0();
            if ((!res || !res->HasBipedModel(i, false, NULL)) && !apRef->TESObjectREFR_WearingObject(p))
            {
                if (item->Modelloader_GetReferencedThis())
                {
                    pExtra = item->Modelloader_GetReferencedThis()->GetItem();
                }
                else
                {
                    pExtra = NULL;
                }
                if (i == 2)
                {
                    res = dynamic_cast<TESBipedModelForm*>(p);
                }
                else
                {
                    TESBipedModelForm* pInv;
                    pInv = TESBipedModelForm::GetFormAsBipedModel(p);
                    if (pInv->HasBipedModel(2, false, NULL))
                    {
                        val = false;
                    }
                }
                if (val)
                {
                    apRef->EquipItem(p, 1, pExtra, false);
                }
            }
            delete item;
            item = NULL;
        }
    }
    if (a4 && !apRef->HasHealth(false))
    {
        float cnt;
        cnt = 0.0f;
        InventoryStackRecord* pWeaponExtra;
        pWeaponExtra = j->GetBestWeapon(this, &cnt, 6, true);
        if (pWeaponExtra)
        {
            bool pItem = true;
            if (!apRef->TESObjectREFR_WearingObject(pWeaponExtra->FUN_0044ddc0()))
            {
                ExtraDataList* fWeight;
                fWeight = NULL;
                if (pWeaponExtra->Modelloader_GetReferencedThis())
                {
                    fWeight = pWeaponExtra->Modelloader_GetReferencedThis()->GetItem();
                    pItem = false;
                }
                else
                {
                    fWeight = NULL;
                }
                TESObjectREFR* bEquipWeapon;
                bEquipWeapon = apRef;
                bEquipWeapon->EquipObject(pWeaponExtra->FUN_0044ddc0(), pWeaponExtra->FUN_00726070(), fWeight, true,
                                          false, true);
                if (pItem)
                {
                    delete pWeaponExtra;
                }
            }
            else if (((Actor*)apRef)->GetProcess())
            {
                if (pWeaponExtra->FUN_0044ddc0() != ((Actor*)apRef)->GetActiveWeapon())
                {
                    ((Actor*)apRef)->GetProcess()->SetCurrentArmor(pWeaponExtra, apRef->GetNiNode(), false);
                }
            }
        }
    }
    if (a6 == 0)
    {
        g_BGSSaveLoadGame->SetThreadAllowChanges(bAllowed);
    }
    if (pBiped->GetProcess())
    {
        pBiped->Actor_CastPermanentMagic(true);
    }
}
