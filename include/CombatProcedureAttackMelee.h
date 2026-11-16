#pragma once

#include "CombatProcedure.h"
#include "CombatTargetTimestamp.h"
#ifndef COMBATPROCEDUREATTACKMELEE_TIMER_H
#include "TimeoutTimer.h"
#endif

class Actor;
class CombatVec3;
class MeleeDebugOutput;
class NiPoint3;

// pdb: class CombatProcedureAttackMelee, size 0x88, bases: CombatProcedure, 16 members
class CombatProcedureAttackMelee : public CombatProcedure
{
public:
    struct CombatMeleeData
    {
        CombatMeleeData();
        int unk00;
    };

    CombatProcedureAttackMelee();
    virtual ~CombatProcedureAttackMelee();
    virtual void Unk04();
    virtual void Unk08(CombatController*);
    virtual void Unk0c();
    virtual void d05();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void vf16();

    int ChooseMeleeAttack(bool abMidAttack, float afDistance, float afReach,
                          bool abTargetAttacking, bool abTargetPostAttack,
                          bool abTargetRecoiling, bool* abDoPowerAttack,
                          bool* abSwitchAttack);
    int FUN_009ccb20(bool abMidAttack, float afDistance, float afReach,
                     bool abTargetAttacking, bool abTargetPostAttack,
                     bool abTargetRecoiling, bool* abDoPowerAttack,
                     bool* abSwitchAttack);

    void RunCombatProcedure();
    void UpdateCombatState();
    void CombatProcedureAttackMelee_MeleeDecision();
    void CombatProcedureAttackMelee_StartAttack(int attack, int arg2);
    void CombatProcedureAttackMelee_HandleAttack();
    void CombatProcedureAttackMelee_HandleBlock();
    void CombatProcedureAttackMelee_CheckStopBlocking();
    void CombatProcedureAttackMelee_HandleHold();
    void CombatProcedureAttackMelee_StartEngage();
    void CombatProcedureAttackMelee_HandleEngage();
    void FUN_009cd5e0();
    void UpdateDodge();
    void EvaluateReaction();
    void UpdateState();
    void CombatProcedureAttackMelee_HandleIdle();
    void CombatProcedureAttackMelee_StartClose();
    void UpdateCombatMovement();
    void UpdateMeleeCombat();
    void CombatProcedureAttackMelee_StartAdvance();
    float CombatProcedureAttackMelee_GetCurrentAttackReach();
    void CombatProcedureAttackMelee_MoveToFaceTargetLocation(CombatVec3* position);
    int CombatProcedureAttackMelee_SelectPowerAttack(float distance, float reach, bool targetAttacking,
                     bool targetMidAttack, int arg5);
    bool IsWithinThreshold(float value, float limit, int unused);
    char IsWithinThreshold(float value, float limit, float unused);
    unsigned char CombatProcedureAttackMelee_OutsideAttackRange(float distance, float reach, int unused);
    void TryAttackTarget(float arg1, float arg2);
    bool IsActionAvailable(unsigned action);
    bool IsActionAvailable(int action);
    void SetMode(int mode);
    void CombatProcedureAttackMelee_SetCombatState(int arg);
    void PrintDebugInfo(MeleeDebugOutput* output, int x, int y);
    char CombatProcedureAttackMelee_CheckDodge(unsigned short mask);
    bool CombatProcedureAttackMelee_CheckDodge(int mask);
    void CombatProcedureAttackMelee_CheckResetMovementRestrictions();
    void CombatProcedureAttackMelee_StopMoving();
    float GetModifierValue();
    bool IsTargetOutOfRange();
    float CombatProcedureAttackMelee_GetMovingTargetVelocity();
    void StopIfSpeakerOutOfRange();

    Actor* CombatProcedure_GetAttacker();
    Actor* GetTarget_00996e00();
    void SetMoveMode_00996e20(int);
    void ClearLookAtTarget_00996ea0();
    void SetLookAtPoint(NiPoint3*, int);
    void CombatProcedure_SetFailed(const char*);
    int FUN_00825c00();
    int TESMain_GetThread();
    int GetSection();
    int GetAudioBackendData();

    int eManeuverState; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    int eCombatState; // src: XBOX_RETAIL_PDB +0x14 (old: unk14)
    int eLastCombatState; // src: XBOX_RETAIL_PDB +0x18 (old: unk18)
    int eCurrentAttack; // src: XBOX_RETAIL_PDB +0x1c (old: unk1C)
    TimeoutTimer MeleeTimer; // src: XBOX_RETAIL_PDB +0x20 (old: pt20)
    TimeoutTimer ManeuverTimer; // src: XBOX_RETAIL_PDB +0x28 (old: pt28)
    TimeoutTimer DodgeTimer; // src: XBOX_RETAIL_PDB +0x30 (old: pt30)
    TimeoutTimer AdvanceTimer; // src: XBOX_RETAIL_PDB +0x38 (old: pt38)
    TimeoutTimer CloseTimer; // src: XBOX_RETAIL_PDB +0x40 (old: pt40)
    TimeoutTimer TargetUnreachableTimer; // src: XBOX_RETAIL_PDB +0x48 (old: pt48)
    bool bRangedAllyWantsToShoot; // src: XBOX_RETAIL_PDB +0x50 (old: unk50)
    unsigned char unk51[3];
    int iAdvanceMoveMode; // src: XBOX_RETAIL_PDB +0x54 (old: unk54)
    float fCurrentAttackReach; // src: XBOX_RETAIL_PDB +0x58 (old: unk58)
    float fFacingTargetDistance; // src: XBOX_RETAIL_PDB +0x5c (old: unk5C)
    CombatTargetTimestamp fAttackPickFailedTimestamp; // src: XBOX_RETAIL_PDB +0x60 (old: val60)
    CombatMeleeData MovementRestrictions; // src: XBOX_RETAIL_PDB +0x64 (old: data64)
    unsigned char unk68[0x20];
};
