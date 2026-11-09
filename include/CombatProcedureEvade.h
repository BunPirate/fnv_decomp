#pragma once

#include "CombatProcedure.h"

// pdb: class CombatProcedureEvade, size 0x18, bases: CombatProcedure, 2 members
class CombatProcedureEvade : public CombatProcedure
{
public:
    unsigned char eState[0x08];

    CombatProcedureEvade(int);

    void LoadGame(BGSLoadFormBuffer* apBuffer) override;
};
