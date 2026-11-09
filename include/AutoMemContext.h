#pragma once

enum MEM_CONTEXT;

// pdb: class AutoMemContext, size 0x4, 1 members
class AutoMemContext
{
  public:
    MEM_CONTEXT iOldMemContext;

    AutoMemContext();
    AutoMemContext(int context);
    AutoMemContext(MEM_CONTEXT memContext, bool overridable, const char* file, int aiLine);
    AutoMemContext(MEM_CONTEXT memContext, bool overridable, const char* file, unsigned int aiLine);
    AutoMemContext(int memContext, bool overridable, const char* file, int aiLine);
    ~AutoMemContext();

    void Enter(int context, bool track, char* file, int line);
    void Leave();
    // The compiler generates __vecDelDtor(unsigned int) from the destructor.
};
