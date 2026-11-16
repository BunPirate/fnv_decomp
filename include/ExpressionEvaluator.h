#pragma once

#include "ExpressionValue.h"

class TESObjectREFR;
class Script;
class ScriptLocals;

#include "EXPRESSION_ERROR.h"

#include "ExpressionOperator.h"

#pragma pack(push, 4)
#include "Stack.h"

// pdb: class CExpression, size 0x710 (here 0x70c), 5 members
class CExpression // src: XBOX_RETAIL_PDB 0x00483710 (first of 3 high-tier links to its methods; old: ExpressionEvaluator)
{
public:
    EXPRESSION_ERROR m_eExpressionError;
    char m_sExpression[512];
    char m_sExpressionBuffer[512];
    Stack<ExpressionOperator, 64> m_kOperatorStack;
    Stack<ExpressionValue, 32> m_kOperandStack;

    CExpression();
    ~CExpression();
    double Eval(const char* sptr, TESObjectREFR* apFunctionOwner, TESObjectREFR* apContainer,
                Script* script, ScriptLocals* scriptLocals, int postfixSize, bool abEndian);
    EXPRESSION_ERROR ExpressionError();
    void SetError(EXPRESSION_ERROR error);
    int ParseToken(char** expression, char* token, ExpressionOperator* operation,
                   bool unary, const char** next);
};
#pragma pack(pop)
