#pragma once
#include "SANDBOX_PROCEDURE.h"
#include "SANDBOX_ACTIVITY.h"

#include "ActorPackageData.h"
#include "BSSimpleArray.h"

class Actor;
class SandboxProcedureData;
class TESObjectREFR;

// pdb: class SandBoxActorPackageData, size 0x64, bases: ActorPackageData, 23 members
class SandBoxActorPackageData : public ActorPackageData
{
public:
    enum SANDBOX_STATE
    {
        SANDBOX_STATE_INIT = 0,
        SANDBOX_STATE_GETTING_UP = 1,
        SANDBOX_STATE_MOVING = 2,
        SANDBOX_STATE_DOINGSTUFF = 3,
        NUM_SANDBOX_STATES = 4
    };



    SandBoxActorPackageData();
    virtual ~SandBoxActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* pDeletedObj);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    bool IsLocationCheckDue();
    bool IsActivityTime();
    bool HasProcessTarget(Actor* apActor);
    bool HasActivityEnded(bool* apbEndedToday);
    bool IsActivityProcedure();
    float GetHourDifference(float afLastTime, float afNow);
    bool IsActorWithinLocationRadius(Actor* apActor, bool abFlag);

    SANDBOX_STATE eState;
    SANDBOX_PROCEDURE eProcedure;
    float fProcedureDuration;
    TESObjectREFR* pLocation;
    float fLastTimeChanged;
    float fTotalTime;
    unsigned int iNextTimeToChangeLocations;
    BSSimpleArray<SandboxProcedureData, 1024> PotentialTargets;
    unsigned int iNextTimeToScanWorld;
    bool bShouldPickNewProcedure;
    bool bFood;
    bool bChair;
    bool bBed;
    int iIdleMarkers;
    TESObjectREFR* pCurrentTargetObject;
    unsigned char cCurrentTargetMarker;
    unsigned char layoutPadding41[3];
    TESObjectREFR* pPrevTargetObject;
    unsigned int iPrevTargetChangedTimeStamp;
    unsigned int iActivityStartDay;
    float fActivityStartHour;
    float fActivityDuration;
    SANDBOX_ACTIVITY eActivity;
    unsigned char cProcedureWeight[NUM_SANDBOX_PROCEDURES];
    unsigned char layoutPadding62[2];
};
