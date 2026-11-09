#pragma once

#include "ExpressionEvaluator.h"
#include "ScriptFunctionInfo.h"

class TESObjectREFR;
class TESObject;
class ScriptLocals;
class TESTopicInfo;
class TESGlobal;
class Script;

#include "SCRIPT_ERROR.h"

// pdb: class ScriptRunner, size 0xa4, 15 members
class ScriptRunner
{
public:
    TESObjectREFR* m_currentContainer;
    TESObject* m_currentObject;
    ScriptLocals* m_currentVars;
    TESTopicInfo* m_currentInfo;
    TESGlobal* m_global;
    Script* m_scriptRunning;
    SCRIPT_ERROR m_error;
    EXPRESSION_ERROR m_expError;
    int m_ifNested;
    int m_ifFlags[10];
    int m_whileNested;
    int m_whileFlags[10];
    int m_whileOffset[10];
    bool m_bScriptErrorFound;
    bool m_bStopObjectScriptExecution;

    ScriptRunner();
    bool GetNextLine(Script* apScript, SCRIPT_OUTPUT& aeNextExp, unsigned int& auiDataOffset, int& aiLineSize,
                     TESObjectREFR** appRefObject, bool abSkip);
    void SetErrorMessage(Script* script, char* message, ...);
    bool EvaluateLine(Script* apScript, const SCRIPT_OUTPUT aeExp, TESObjectREFR* apFunctionOwner, int& aiLineSize,
                    const unsigned int auiDataOffset, unsigned int& aiSkipLines, const unsigned int auiCurrentLine,
                    bool abEndian, bool abActionInit);
    void SetError(Script* script, SCRIPT_ERROR error);
    bool SetScriptLocalsFromExtraData(Script* script, TESObjectREFR* reference, ScriptLocals* locals);
    bool RunScript(Script* apScript, TESObjectREFR* apOwnerObject, ScriptLocals* apOwnerVars);
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target,
             bool arg5, bool arg6, bool arg7, float arg8);
};
