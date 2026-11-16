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
    TESObjectREFR* m_currentContainer; // src: XBOX_RETAIL_PDB +0x0 (old: m_pReference)
    TESObject* m_currentObject; // src: XBOX_RETAIL_PDB +0x4 (old: m_pScriptObject)
    ScriptLocals* m_currentVars; // src: XBOX_RETAIL_PDB +0x8 (old: m_pScriptLocals)
    TESTopicInfo* m_currentInfo; // src: XBOX_RETAIL_PDB +0xc (old: m_pTopicInfo)
    TESGlobal* m_global; // src: XBOX_RETAIL_PDB +0x10 (old: m_pGlobal)
    Script* m_scriptRunning; // src: XBOX_RETAIL_PDB +0x14 (old: m_pScript)
    SCRIPT_ERROR m_error; // src: XBOX_RETAIL_PDB +0x18 (old: m_eScriptError)
    EXPRESSION_ERROR m_expError; // src: XBOX_RETAIL_PDB +0x1c (old: m_eExpressionError)
    int m_ifNested; // src: XBOX_RETAIL_PDB +0x20 (old: m_iIfStackDepth)
    int m_ifFlags[10]; // src: XBOX_RETAIL_PDB +0x24 (old: m_aiIfStack)
    int m_whileNested; // src: XBOX_RETAIL_PDB +0x4c (old: m_iBlockStackDepth)
    int m_whileFlags[10]; // src: XBOX_RETAIL_PDB +0x50 (old: m_aiBlockOffsets)
    int m_whileOffset[10]; // src: XBOX_RETAIL_PDB +0x78 (old: m_aiBlockSizes)
    bool m_bScriptErrorFound; // src: XBOX_RETAIL_PDB +0xa0 (old: m_bScriptCompileFailed)
    bool m_bStopObjectScriptExecution; // src: XBOX_RETAIL_PDB +0xa1 (old: m_bExecutionFlagSet)

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
