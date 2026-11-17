#pragma once

#include "CombatProcedure.h"
#include "NiPoint3.h"
#include "TimeoutTimer.h"

class Actor;

// pdb: class CombatProcedureAttackRanged, size 0x48, bases: CombatProcedure, 7 members
class CombatProcedureAttackRanged : public CombatProcedure
{
public:
    CombatProcedureAttackRanged();
    virtual ~CombatProcedureAttackRanged();
    virtual void Unk04();
    virtual void Unk0c();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    void Disarmed_009d1dc0(Actor* apOpponent);
    void CombatProcedure_SetFailed(const char* str);

    unsigned int eState; // src: XBOX_RETAIL_PDB +0x10 (old: m_10)
    NiPoint3 TargetedPoint; // src: XBOX_RETAIL_PDB +0x14 (old: m_14)
    TimeoutTimer ExplosiveProjectileBlockedTimer; // src: XBOX_RETAIL_PDB +0x20 (old: m_20)
    TimeoutTimer FiringTimer; // src: XBOX_RETAIL_PDB +0x28 (old: m_28)
    TimeoutTimer CooldownTimer; // src: XBOX_RETAIL_PDB +0x30 (old: m_30)
    TimeoutTimer FireDelayTimer; // src: XBOX_RETAIL_PDB +0x38 (old: m_38)
    TimeoutTimer SuppressiveFireTimer; // src: XBOX_RETAIL_PDB +0x40 (old: m_40)
};
