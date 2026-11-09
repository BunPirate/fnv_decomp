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

    int eState;
    float fMinOptimalRange;
    float fMaxOptimalRange;
    float fAbsoluteMaxRange;
    TimeoutTimer HoldingTimer;
    TimeoutTimer LeftRightDodgeLOSTimer;
    bool bLeftRightDodgeHadLOS;
    bool bLeftRightDodgeCheckLOS;
    bool bLeftRightDodgeLostLOS;
    signed char cCheckedOptimalPath;
    NiPoint3 LeftRightDodgeStartLocation;
    Location Destination;
    Location TargetOptimalWorldLoc;
    CombatTargetTimestamp fOptimalLocationPathingFailedTimeStamp;
};
