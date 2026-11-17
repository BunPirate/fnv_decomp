#pragma once

#include "BSExtraData.h"

class Script;
class ScriptLocals;

// pdb: class ExtraScript, size 0x14, bases: BSExtraData, 2 members
class ExtraScript : public BSExtraData
{
public:
    ExtraScript();
    ExtraScript(Script* aScript);
    virtual ~ExtraScript();
    virtual bool Compare(BSExtraData* pkOther);

    bool BaseCompare(BSExtraData* pkOther);
    bool CompareScriptExtra(BSExtraData* pkOther);
    void FUN_00432040();

    Script* pScript;
    ScriptLocals* m_pLocals;
};
