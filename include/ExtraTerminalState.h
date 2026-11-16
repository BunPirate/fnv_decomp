#pragma once

#include "BSExtraData.h"

// pdb: class ExtraTerminalState, size 0x10, bases: BSExtraData, 2 members
class ExtraTerminalState : public BSExtraData
{
public:
    ExtraTerminalState();
    bool __thiscall IsLockedState();

    unsigned char cState; // src: XBOX_RETAIL_PDB +0xc (old: padC)
    char cLockOverride; // src: XBOX_RETAIL_PDB +0xd (old: m_cTerminalState)
    unsigned char unk0E[2];
};
