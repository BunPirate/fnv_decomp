#pragma once

class Script;
class ScriptLocals;
class ScriptRunner;
class TESObjectREFR;

// pdb: class ScriptRunManager, size 0x8, 2 members
class ScriptRunManager
{
public:
    ScriptRunner* m_pScriptRunner;
    ScriptRunner* pCurrentRunner;

    ScriptRunManager();
    ~ScriptRunManager();
    static ScriptRunManager* Instance();
    bool InitActionList(Script* script, TESObjectREFR* ref, ScriptLocals* locals); // returns bool (body in tesscriptrunmanager.cpp)
    bool Run(Script* apScript, TESObjectREFR* apOwnerObject, ScriptLocals* apOwnerVars, TESObjectREFR* apOwnerContainer,
             bool abIsPartialScript, bool abScriptEffectStart, bool abScriptEffectFinish, float afSecondsElapsed);
};
