#pragma once

#include "CombatProcedure.h"
#include "TimeoutTimer.h"

class Actor;
class Output;

// pdb: class CombatProcedureSearch, size 0x40, bases: CombatProcedure, 6 members
class CombatProcedureSearch : public CombatProcedure
{
public:
    struct Location
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0c;

        void Init();
        void* FUN_006815c0();
        void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        double BGSWorldLocation_GetDistanceSquared(const Location*);
        void BGSWorldLocation_SaveGame(BGSSaveFormBuffer*);
        void BGSWorldLocation_LoadGame(BGSLoadFormBuffer*);
    };

    CombatProcedureSearch();
    virtual ~CombatProcedureSearch();
    virtual void Unk04() override;
    virtual void Unk0c() override;
    virtual void d05() override;
    virtual void OnInventoryItemChanged(TESObjectREFR* apRef, TESBoundObject* apObject,
                                        int aiCount, bool abActivatedScriptOnly) override;
    virtual int GetType() override;
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer) override;
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) override;
    virtual void vf16() override;

    void* Destroy(unsigned int flags);
    void UpdateSearchState();
    void UpdateEngageTarget();
    void PrintDebugInfo(Output* apDebugText, int aeLocation, int aeJustify);
    void ClearRefIfMatches(TESObjectREFR* apRef, TESBoundObject* apObject,
                          int aiCount, bool abActivatedScriptOnly);
    void RevertAndResolveRef(BGSLoadFormBuffer* apLoadGameBuffer);
    Actor* CombatProcedure_GetAttacker();
    void* GetTarget_00996e00();
    void CombatProcedure_SetFailed(const char*);
    void SetMoveMode_00996e20(int);
    void ClearMoveMode();

    unsigned int eState; // src: XBOX_RETAIL_PDB +0x10 (old: state)
    TimeoutTimer CheckDestinationTimer; // src: XBOX_RETAIL_PDB +0x14 (old: timer14)
    TimeoutTimer LookingTimer; // src: XBOX_RETAIL_PDB +0x1c (old: timer1c)
    TimeoutTimer CheckSearchDoorTimer; // src: XBOX_RETAIL_PDB +0x24 (old: timer24)
    Location InvestigateLocation; // src: XBOX_RETAIL_PDB +0x2c (old: location)
    TESObjectREFR* pSearchDoor; // src: XBOX_RETAIL_PDB +0x3c (old: m_pReference)
};
