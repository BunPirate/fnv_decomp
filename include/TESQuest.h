#pragma once

#include "TESForm.h"
#include "TESScriptableForm.h"
#include "TESIcon.h"
#include "TESFullName.h"
#include "QuestData.h"
#include "PerkEntryConditionSet.h"
#include "MagicTarget.h"

class QuestStage;
class BGSQuestObjective;
class RegionObjectEntry;
class ScriptLocals;
class QuestObjectiveList;
class BGSSaveFormBuffer;

template <class T> class PlayerList;

// pdb: class TESQuest, size 0x6c, bases: TESForm, TESScriptableForm, TESIcon, TESFullName, 7 members
class TESQuest : public TESForm, public TESScriptableForm, public TESIcon, public TESFullName
{
public:
    class QuestDataDefaults : public QuestData
    {
    public:
        QuestDataDefaults();
    };

    QuestDataDefaults data;
    BSSimpleList<QuestStage*> m_kStageList;
    BSSimpleList<BGSQuestObjective*> m_listObjectives; // src: XBOX_RETAIL_PDB +0x4c (old: m_kObjectives)
    PerkEntryConditionSet objConditions; // src: XBOX_RETAIL_PDB +0x54 (old: m_kInfoConditions)
    ScriptLocals* m_pScriptLocals;
    unsigned char m_ucEnabled;
    unsigned char layoutPadding61[3];
    BSStringT<char> cFormEditorID; // src: XBOX_RETAIL_PDB +0x64 (old: strEditorID)

    TESQuest();
    virtual ~TESQuest();
    virtual void ClearData();
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void InitItem();
    virtual const char* GetEditorName() const;

    void ResetFormData();
    void ClearStageList();
    void ClearObjectiveList();
    unsigned int GetStageMask();
    void UpdateStageMask();
    bool HasStage(unsigned char index);
    bool SetStageDone(unsigned char aucIndex);
    BGSQuestObjective* GetObjective(unsigned int aiIndex);
    void GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* apListToFill,
                                 BSSimpleList<BGSQuestObjective*>* apPlayerObjectiveList);
    bool ValidateTargetList(BSSimpleList<RegionObjectEntry*>* apListToValidate,
                                 BSSimpleList<BGSQuestObjective*>* apPlayerObjectiveList);
    void GetTargetsAndObjectives(PlayerList<RegionObjectEntry*>* apListToFill,
                                 PlayerList<BGSQuestObjective*>* apPlayerObjectiveList);
    bool ValidateTargetList(PlayerList<RegionObjectEntry*>* apListToValidate,
                                 PlayerList<BGSQuestObjective*>* apPlayerObjectiveList);
    bool Load(TESFile* apFile);
    bool GetEnabled();
    void SetEnabled(bool abEnabled);
    bool GetCompleted();
    bool GetAllowRepeatStages();
    bool GetAllowRepeatedTopics();
    void RunScript();
    void SetStartsEnabled(bool abVal);
    PerkEntryConditionSet* GetConditions();
    ScriptLocals* GetScriptLocalData();
    BSSimpleList<QuestStage*>* GetStageList();
    BSSimpleList<BGSQuestObjective*>* GetObjectiveList();
    QuestStage* GetStage(unsigned char acIndex);
    void AddStageDataAtIndex(QuestStage* stage);
    void AddObjective(BGSQuestObjective* objective);
    void MarkCompleted(bool completed);
    void SetQuestCompleted(bool abFailed);
    bool HasFlag40();
    bool HasFlag20();
    bool HasFlag0x10();
    void TESQuest_SetDisplayedInHUD(bool abVal);
    void WriteToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void SaveIfChanged(BGSSaveFormBuffer* buffer);
    void LoadQuestData(unsigned int aiFlags, unsigned int aiCurrentFlags);
    void SetAllObjectivesComplete(int abComplete);
    void FUN_0060c9c0(bool abEnabled);
    void SetCompleted(bool set);
    void SetFailed(bool abFailed);
    void ProcessEntries_0060d720();
    void Save_0060cd60();
    unsigned short GetSaveSize_0060dba0(unsigned int aiFlags);
    void SaveGame_0060dd50(unsigned int aiFlags);
    void RevertTES_0060e6a0(unsigned int aiFlags);
    void CheckSaveGame(BGSSaveFormBuffer* buffer);
    float QueuedModel_GetOverriddenVisualDistance();
    QuestObjectiveList* FUN_005d43e0();
};
