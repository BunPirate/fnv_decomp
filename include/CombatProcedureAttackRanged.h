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

    unsigned int eState;
    NiPoint3 TargetedPoint;
    TimeoutTimer ExplosiveProjectileBlockedTimer;
    TimeoutTimer FiringTimer;
    TimeoutTimer CooldownTimer;
    TimeoutTimer FireDelayTimer;
    TimeoutTimer SuppressiveFireTimer;
};
