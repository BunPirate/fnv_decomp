#pragma once

#include "hkBool.h"

typedef unsigned char hkUint8;

// pdb: class hkProcess, size 0x18, 5 members
class hkProcess
{
public:
    class CommandArgument;

    hkProcess(hkBool selectable);

    virtual ~hkProcess() throw();
    virtual int GetOperationType();
    virtual void CollectProcessCommands(hkUint8*& commands, int& numCommands);
    virtual void ExecuteCommand(hkUint8 command);
    virtual bool isActive();
    virtual void init();
    virtual void step(float frameTimeInMs);

    int m_selectable;
    int m_inStream;
    int m_outStream;
    int m_displayHandler;
    int m_processHandler;
};
