#pragma once

#include "CombatProcedure.h"

class TESForm;
class TESObjectWEAP;

// pdb: class CombatProcedureSwitchWeapon, size 0x18, bases: CombatProcedure, 2 members
class CombatProcedureSwitchWeapon : public CombatProcedure
{
public:
    CombatProcedureSwitchWeapon(TESObjectWEAP*);
    virtual ~CombatProcedureSwitchWeapon();
    virtual void Unk04();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);

    void* DestroyIfFlagged(unsigned int flags);
    void UpdateWeaponDraw();

    TESForm* pWeapon;
    bool bEquipQueued;
};
