#pragma once

#include "CombatTargetTimestamp.h"
#include "NiPoint3.h"
#include "NiPointer.h"
#include "NiTMap.h"
#include "NiTPrimitiveArray.h"
#include "TimeoutTimer.h"

class Actor;
class ActorCombatGroup;
class BGSExplosion;
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class CombatController;
class CombatCoverMap;
class CombatTargetMap;
class CombatThreatMap;
class IDebugText;
class NiNode;
class TESObjectREFR;
class TESPackage;

// pdb: class CombatManager, size 0x3c, 10 members
class CombatManager
{
public:
    NiTPrimitiveArray<ActorCombatGroup*> CombatGroups; // src: XBOX_RETAIL_PDB +0x0 (old: m_kCombatGroups)
    NiTMap<Actor*, unsigned __int64>* pLocalActorTargetingMap; // src: XBOX_RETAIL_PDB +0x10 (old: m_pActorCombatGroupMap)
    CombatThreatMap* pThreatMap; // src: XBOX_RETAIL_PDB +0x14 (old: m_pThreatMap)
    CombatCoverMap* pCoverMap; // src: XBOX_RETAIL_PDB +0x18 (old: m_pCoverMap)
    CombatTargetMap* pTargetMap; // src: XBOX_RETAIL_PDB +0x1c (old: m_pTargetMap)
    CombatTargetTimestamp fCombatMusicStartedTimeStamp; // src: XBOX_RETAIL_PDB +0x20 (old: m_kFourByteManagerData)
    TimeoutTimer CombatMusicStopTimer; // src: XBOX_RETAIL_PDB +0x24 (old: m_kFirstEightByteManagerData)
    TimeoutTimer CombatMusicUpdateTimer; // src: XBOX_RETAIL_PDB +0x2c (old: m_kSecondEightByteManagerData)
    unsigned int iNextGroupID; // src: XBOX_RETAIL_PDB +0x34 (old: m_uiDebugFlags)
    NiPointer<NiNode> spDebugGeometry; // src: XBOX_RETAIL_PDB +0x38 (old: m_spDebugRootNode)

    void ResetFormData();
    void ClearData(bool);
    static void Create();
    static void Destroy();
    void Update(bool abTimeStopped);
    void UpdateCombatGroups(bool arg);
    void UpdateCombatants();
    void ResetTargetMap();
    CombatController* AddCombatant(Actor*, Actor*, unsigned int, bool);
    CombatController* AddCombatantToGroup(Actor*, ActorCombatGroup*);
    CombatController* AddPretendCombatant(Actor*, TESPackage*);
    unsigned int GetCombatantCount(Actor* target, unsigned int* recentCount);
    bool CheckShouldFlee(Actor*, Actor*);
    void AssignCombatTarget(Actor*, Actor*);
    bool GetWanttoHelpGroup(Actor*, Actor*);
    bool CanActorJoinCombat(Actor*, Actor*);
    void AddCombatGroupTarget(ActorCombatGroup*, Actor*);
    void NotifyCombatGroupRemovedTarget(ActorCombatGroup*, Actor*);
    void AddCombatGroupMember(ActorCombatGroup*, Actor*);
    void NotifyCombatGroupRemovedMember(ActorCombatGroup*, Actor*);
    bool CanActorBeAffectedByExplosion(Actor*, BGSExplosion*, void*, float);
    void SetActivatePickReference(TESObjectREFR*);
    void DrawDebugText(IDebugText*);
    void DisplayCombatGroupDebugText(IDebugText*, TESObjectREFR*);
    void DisplaySpectatorDebugText(IDebugText*, TESObjectREFR*);
    bool IsCombatActive();
    void AddLocalActor(Actor*);
    void RemoveLocalActor(Actor*);
    void TargetLocalActor(Actor*, ActorCombatGroup*);
    void UntargetLocalActor(Actor*, ActorCombatGroup*);
    unsigned int FindCombatGroupForActor(NiPoint3, float, float, Actor*, unsigned int*, unsigned int*,
                                         unsigned int*, unsigned int*);
    CombatThreatMap* GetThreatMap();
    CombatCoverMap* GetCoverMap();
    CombatTargetMap* GetTargetMap();
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer* buffer);
    void InitLoadGame(BGSLoadGameBuffer*);
    void FinishLoadGame(BGSLoadGameBuffer* apLoadGameBuffer);
    void Revert(BGSLoadGameBuffer*);
    unsigned int GetCombatGroupCount();
    ActorCombatGroup* GetCombatGroupByIndex(unsigned int);
    ActorCombatGroup* GetCombatGroup(unsigned int);
    ActorCombatGroup* GetPlayerCombatGroup();
    ActorCombatGroup* SplitPlayerCombatGroup(Actor*);
#if !defined(_MSC_VER) || defined(__vecDelDtor)
    void* __vecDelDtor(unsigned int);
#else
    // MSVC supplies __vecDelDtor(unsigned int) from the destructor.
#endif
    ~CombatManager();
    void SwapAndDispatch(void*, void*);
    void FUN_008d0600(void*, void*);
    void CombatManager_UpdateCombatants();
    ActorCombatGroup* FindByKey(unsigned int aiGroupID);
    void FUN_00993800(BGSLoadGameBuffer*);
    void InitLoadGame_00993600(void* apLoadGameBuffer);
};
