#pragma once

class Script;
class ScriptLocals;
class ScriptRunner;
class TESObjectREFR;

// pdb: class ScriptRunManager, size 0x8, 2 members
class ScriptRunManager // src: XBOX_RETAIL_PDB 0x005e24d0 (first retail link of 2 high-tier links to its methods; old: ScriptExecutor)
{
public:
    ScriptRunner* m_pScriptRunner; // src: XBOX_RETAIL_PDB +0x0 (old: m_pReusableScriptRunner)
    ScriptRunner* pCurrentRunner; // src: XBOX_RETAIL_PDB +0x4 (old: m_pActiveScriptRunner)

    ScriptRunManager();
    ~ScriptRunManager();
    static ScriptRunManager* Instance();
    bool ScriptRunManager_InitActionList(Script* script, TESObjectREFR* ref, ScriptLocals* locals); // returns bool (body in tesscriptrunmanager.cpp)
    bool Run(Script* apScript, TESObjectREFR* apOwnerObject, ScriptLocals* apOwnerVars, TESObjectREFR* apOwnerContainer,
             bool abIsPartialScript, bool abScriptEffectStart, bool abScriptEffectFinish, float afSecondsElapsed);
};
