#pragma once

#include "ActorPackageData.h"
#include "BSSimpleArray.h"

class Actor;
class TESPackage;
class NiPoint3;
class TESPatrolPackageData;

// pdb: class PatrolActorPackageData, size 0x38, bases: ActorPackageData, 10 members
class PatrolActorPackageData : public ActorPackageData
{
public:
    enum PATROL_STATE
    {
        PATROL_STATE_INIT = 0,
        PATROL_STATE_TRAVELING_TO_NEXT_REF = 1,
        PATROL_STATE_AT_REF = 2,
        PATROL_STATE_DEBUG_ACTOR_DELETED = 3,
        PATROL_STATE_DEBUG_DESTRUCTED = 4
    };

    PatrolActorPackageData();
    virtual ~PatrolActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apDeletedObj);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    bool Init(Actor* apActor, TESPackage* apPackage);
    bool SetNextReferenceForPatrol(bool abWaitForOccupiedPoints);
    TESObjectREFR* GetCurrentPatrolReference();
    static TESObjectREFR* __cdecl GetPatrolReference(Actor* apActor, TESPackage* apPackage);
    bool IsPatrolling();
    void SetPatrolPosition(const NiPoint3& aActorPos);
    bool SetCurrentReference(unsigned int aiRefIndex);
    void SelectClosestPatrolPoint(const NiPoint3& aActorPos);
    void SelectClosestPatrolPoint(void* apPoint);
    void PatrolActorPackageData_ClearReservedPatrolRef();

    PATROL_STATE eState; // 0x04
    float fCurrentTimeAtReference; // 0x08 // src: XBOX_RETAIL_PDB +0x8 (old: m_fElapsedWaitTime)
    bool bPatrolDirection; // 0x0C // src: XBOX_RETAIL_PDB +0xc (old: m_bPatrolFlag)
    unsigned char unk0D[3];
    Actor* pActor; // 0x10
    TESPackage* pPackage; // 0x14
    const TESPatrolPackageData* pPackageData; // 0x18 // src: XBOX_RETAIL_PDB +0x18 (old: m_pEscortPackageData)
    BSSimpleArray<TESObjectREFR*, 1024> References; // 0x1C
    bool bCircularArray; // 0x2C // src: XBOX_RETAIL_PDB +0x2c (old: m_bReferenceFlag)
    unsigned char unk2D[3];
    unsigned int iLoopAroundIndex; // 0x30 // src: XBOX_RETAIL_PDB +0x30 (old: m_uiValueAfterReferenceFlag)
    unsigned int iCurrentReference; // 0x34 // src: XBOX_RETAIL_PDB +0x34 (old: m_uiSecondValueAfterReferenceFlag)
};
