#pragma once

class Effect;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class CombatController;

// pdb: class CombatPlan, size 0x18, 6 members
class CombatPlan
{
public:
    int pPlanSteps;
    int iLength;
    int iCurrentAction;
    int pGoal;
    int iCombatLocation;
    int pCombatController;

    CombatPlan(CombatController* controller);
    ~CombatPlan();

    bool __thiscall CombatController_CombatPlanContainsAction(int aiAction);
    Effect* __thiscall FUN_004fd3e0();
    void __thiscall SetFieldE0(float f);
    void SaveToBuffer(BGSSaveFormBuffer*);
    void ReadFromStream(BGSLoadFormBuffer* buffer);
    bool CombatPlan_IsFinished();
    void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    bool AdvanceActions(CombatController* controller);
    void Revert(BGSLoadFormBuffer* buffer);
};
