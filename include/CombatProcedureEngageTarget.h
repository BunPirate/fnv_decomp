#pragma once

#include "CombatProcedure.h"
#include "CombatTargetTimestamp.h"
#include "NiPoint3.h"
#include "TimeoutTimer.h"

class Actor;
class CombatOwner;
class Output;
class Ref;

// pdb: class CombatProcedureEngageTarget, size 0x64, bases: CombatProcedure, 14 members
class CombatProcedureEngageTarget : public CombatProcedure
{
public:
    struct Location
    {
        NiPoint3 pos;
        void* cell;

        NiPoint3* GetPos();
        void* GetContainingCell();
        float GetDistSq(Location* other);
        void GetCoords(int* a, int* b);
        void SetPos(NiPoint3* p);
        void InitializeForCell(void* c);
    };

    CombatProcedureEngageTarget();
    virtual ~CombatProcedureEngageTarget();
    virtual void Unk04();
    virtual void Unk0c();
    virtual void d05();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    void ResetCombatState();
    Actor* GetActor();
    Actor* GetTarget();
    Actor* CombatProcedure_GetAttacker();
    Actor* GetTarget_00996e00();
    void SetMoveMode_00996e20(int mode);
    void ClearMoveMode();
    bool CheckAndApply(bool mode);
    Ref* GetRef();
    void PrintDebugInfo(Output* out, int a, int b);
    void SetAvoid(NiPoint3* pos, bool b);
    void UpdatePlayerStatus(int mode);
    void StopMove();
    void Fail(const char* msg);
    bool TryAttack(bool b);
    bool IsAimingWeapon();
    void ResetState();
    void UpdateEngagement();

    int eState; // src: XBOX_RETAIL_PDB +0x10 (old: m_iFadeIndex)
    float fMinOptimalRange; // src: XBOX_RETAIL_PDB +0x14 (old: m_fMinRange)
    float fMaxOptimalRange; // src: XBOX_RETAIL_PDB +0x18 (old: m_fMaxRange)
    float fAbsoluteMaxRange; // src: XBOX_RETAIL_PDB +0x1c (old: m_fFarRange)
    TimeoutTimer HoldingTimer; // src: XBOX_RETAIL_PDB +0x20 (old: m_timer20)
    TimeoutTimer LeftRightDodgeLOSTimer; // src: XBOX_RETAIL_PDB +0x28 (old: m_timer28)
    bool bLeftRightDodgeHadLOS; // src: XBOX_RETAIL_PDB +0x30 (old: m_bDodgeWait)
    bool bLeftRightDodgeCheckLOS; // src: XBOX_RETAIL_PDB +0x31 (old: m_bCovered)
    bool bLeftRightDodgeLostLOS; // src: XBOX_RETAIL_PDB +0x32 (old: m_bDodging)
    signed char cCheckedOptimalPath; // src: XBOX_RETAIL_PDB +0x33 (old: m_cFallback)
    NiPoint3 LeftRightDodgeStartLocation; // src: XBOX_RETAIL_PDB +0x34 (old: m_dodgePos)
    Location Destination; // src: XBOX_RETAIL_PDB +0x40 (old: m_dest)
    Location TargetOptimalWorldLoc; // src: XBOX_RETAIL_PDB +0x50 (old: m_lastTarget)
    CombatTargetTimestamp fOptimalLocationPathingFailedTimeStamp; // src: XBOX_RETAIL_PDB +0x60 (old: m_stamp60)
};
