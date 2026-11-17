#pragma once

class Effect;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class CombatController;

// pdb: class CombatPlan, size 0x18, 6 members
class CombatPlan
{
public:
    int pPlanSteps; // src: XBOX_RETAIL_PDB +0x0 (old: unk00)
    int iLength; // src: XBOX_RETAIL_PDB +0x4 (old: unk04)
    int iCurrentAction; // src: XBOX_RETAIL_PDB +0x8 (old: unk08)
    int pGoal; // src: XBOX_RETAIL_PDB +0xc (old: unk0C)
    int iCombatLocation; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    int pCombatController; // src: XBOX_RETAIL_PDB +0x14 (old: unk14)

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
