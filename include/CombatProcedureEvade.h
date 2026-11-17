#pragma once

#include "CombatProcedure.h"

// pdb: class CombatProcedureEvade, size 0x18, bases: CombatProcedure, 2 members
class CombatProcedureEvade : public CombatProcedure
{
public:
    unsigned char eState[0x08]; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)

    CombatProcedureEvade(int);

    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer) override;
};
