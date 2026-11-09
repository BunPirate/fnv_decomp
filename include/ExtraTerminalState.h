#pragma once

#include "BSExtraData.h"

// pdb: class ExtraTerminalState, size 0x10, bases: BSExtraData, 2 members
class ExtraTerminalState : public BSExtraData
{
public:
    ExtraTerminalState();
    bool __thiscall IsLockedState();

    unsigned char cState;
    char cLockOverride;
    unsigned char unk0E[2];
};
