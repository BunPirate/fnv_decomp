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
    float fProcedureDuration; // src: XBOX_RETAIL_PDB +0xc (old: m_fProcedureTime)
    TESObjectREFR* pLocation;
    float fLastTimeChanged; // src: XBOX_RETAIL_PDB +0x14 (old: m_fLastProcedureCheckHour)
    float fTotalTime; // src: XBOX_RETAIL_PDB +0x18 (old: m_fNextProcedureCheckHour)
    unsigned int iNextTimeToChangeLocations; // src: XBOX_RETAIL_PDB +0x1c (old: m_uiLastProcedureCheckDay)
    BSSimpleArray<SandboxProcedureData, 1024> PotentialTargets; // src: XBOX_RETAIL_PDB +0x20 (old: m_kProcedureList)
    unsigned int iNextTimeToScanWorld; // src: XBOX_RETAIL_PDB +0x30 (old: m_uiProcedureIndex)
    bool bShouldPickNewProcedure; // src: XBOX_RETAIL_PDB +0x34 (old: m_bNeedsSandboxUpdate)
    bool bFood; // src: XBOX_RETAIL_PDB +0x35 (old: m_bHasFoodMarker)
    bool bChair; // src: XBOX_RETAIL_PDB +0x36 (old: m_bHasChairMarker)
    bool bBed; // src: XBOX_RETAIL_PDB +0x37 (old: m_bHasBedMarker)
    int iIdleMarkers; // src: XBOX_RETAIL_PDB +0x38 (old: m_iSerializedValue)
    TESObjectREFR* pCurrentTargetObject; // src: XBOX_RETAIL_PDB +0x3c (old: m_pCurrentTarget)
    unsigned char cCurrentTargetMarker; // src: XBOX_RETAIL_PDB +0x40 (old: m_ucProcedureIndex)
    unsigned char layoutPadding41[3];
    TESObjectREFR* pPrevTargetObject; // src: XBOX_RETAIL_PDB +0x44 (old: m_pCurrentFurniture)
    unsigned int iPrevTargetChangedTimeStamp; // src: XBOX_RETAIL_PDB +0x48 (old: m_uiActivityStartDay)
    unsigned int iActivityStartDay; // src: XBOX_RETAIL_PDB +0x4c (old: m_uiActivityEndDay)
    float fActivityStartHour; // src: XBOX_RETAIL_PDB +0x50 (old: m_fActivityStartHour)
    float fActivityDuration; // src: XBOX_RETAIL_PDB +0x54 (old: m_fActivityEndHour)
    SANDBOX_ACTIVITY eActivity; // src: XBOX_RETAIL_PDB +0x58 (old: m_eSandboxActivity)
    unsigned char cProcedureWeight[NUM_SANDBOX_PROCEDURES]; // src: XBOX_RETAIL_PDB +0x5c (old: m_ucProcedureFlags)
    unsigned char layoutPadding62[2];
};
