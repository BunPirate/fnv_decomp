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

    int m_selectable; // src: XBOX_RETAIL_PDB +0x4 (old: unk04)
    int m_inStream; // src: XBOX_RETAIL_PDB +0x8 (old: unk08)
    int m_outStream; // src: XBOX_RETAIL_PDB +0xc (old: unk0c)
    int m_displayHandler; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    int m_processHandler; // src: XBOX_RETAIL_PDB +0x14 (old: unk14)
};
