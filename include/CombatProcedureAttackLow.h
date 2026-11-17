#pragma once

#include "CombatProcedure.h"
#include "IDebugText.h"

class TESObjectWEAP;

// pdb: class CombatProcedureAttackLow, size 0x20, bases: CombatProcedure, 4 members
class CombatProcedureAttackLow : public CombatProcedure
{
public:
    virtual ~CombatProcedureAttackLow();
    virtual void Unk04() override;
    virtual void d05() override;
    virtual int GetType() override;
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer) override;
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) override;

    void SetVtableAndProcessState_009cbb50();
    void* DestroyIfFlagged(unsigned int flags);
    void CombatProcedureAttackLow_Update();
    void DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation,
                                DEBUGTEXT_JUSTIFY aeJustify);
    void SaveGame_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer);
    void CombatProcedureAttackLow_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    int eState; // src: XBOX_RETAIL_PDB +0x10 (old: m_10)
    int fWeaponDPS; // src: XBOX_RETAIL_PDB +0x14 (old: m_14)
    int fWeaponCondition; // src: XBOX_RETAIL_PDB +0x18 (old: m_18)
    TESObjectWEAP* pWeapon;
};
