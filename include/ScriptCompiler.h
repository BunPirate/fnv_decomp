#pragma once

class CStringArgument;
class Script;
class ScriptLineBuffer;
class TESObjectREFR;
enum COMPILER_NAME;

// pdb: class ScriptCompiler, size 0x1, 0 members
class ScriptCompiler
{
public:
    ScriptCompiler();

    bool CompilePartialScript(Script* script, TESObjectREFR* ownerObject, COMPILER_NAME index, bool flag);
    bool Compile_005aeb90(Script*, CStringArgument*);
    unsigned int GetNextExpression(CStringArgument*);
    bool VerifyBlocks(CStringArgument*);
    bool ScriptCompiler_CompileLine(Script*, CStringArgument*, ScriptLineBuffer*);
};
