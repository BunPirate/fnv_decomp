#pragma once

class Script;
class ScriptDefinition;
class FormFlagRecord;
class ScriptLocalVariable;
class TESForm;
class TESBoundObject;
class ScriptHeaderData;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
template <class T> class BSSimpleList;

// pdb: class ScriptLocals, size 0x14, 5 members
class ScriptLocals
{
public:
    Script* m_pMasterScript; // src: XBOX_RETAIL_PDB +0x0 (old: m_pOwnerScript)
    char m_cFlags; // src: XBOX_RETAIL_PDB +0x4 (old: m_cActionFlags)
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSSimpleList<FormFlagRecord*>* m_pActionList; // src: XBOX_RETAIL_PDB +0x8 (old: m_pLocalVariableList)
    BSSimpleList<ScriptLocalVariable*>* m_pLocalList; // src: XBOX_RETAIL_PDB +0xc (old: m_pVariableList)
    ScriptDefinition* m_pScriptEffectData; // src: XBOX_RETAIL_PDB +0x10 (old: m_pExtendedLocals)

    ScriptLocals();
    ~ScriptLocals();
    void Destroy();
#ifdef __vecDelDtor
    void* __vecDelDtor(unsigned int);
#endif
    void ClearActionFlags();
    bool GetLocalData(TESForm*, unsigned int);
    TESBoundObject* GetLocalData();
    void ClearActionFlagsForForm(TESForm*);
    bool CheckActionFlag(TESForm*, unsigned int);
    FormFlagRecord* GetActionEntry(TESForm*, bool);
    TESBoundObject* bhkWorld_GetahkpWorld();
    void Save(ScriptHeaderData*);
    void ClearActionList();
    void InitializeActionList();
    void CopyActionListFrom(ScriptLocals*);
    void* GetActionList();
    void ResetFormData(Script*);
    void SetVariable(unsigned int, double);
    double GetVariable(unsigned int, Script*);
    BSSimpleList<ScriptLocalVariable*>* GetLocalList();
    bool IsReferenceVariable(unsigned int);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void Revert(BGSLoadFormBuffer*);
    void Revert();
    static void ProcessPendingTasks();
    FormFlagRecord* ScriptLocals_GetActionObject(ScriptLocals* locals, bool create);
    bool SetActionFlag(TESForm* apActionForm, unsigned int aiFlag);
    void FUN_005a85c0();
};
