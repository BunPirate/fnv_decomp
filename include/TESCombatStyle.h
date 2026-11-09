#pragma once

#include "TESForm.h"
#include "UnsignedIntArray16.h"
#include "StatsChunkData.h"
#include "UInt32ChunkData.h"

// pdb: class TESCombatStyle, size 0x108, bases: TESForm, 3 members
class TESCombatStyle : public TESForm
{
public:
    UnsignedIntArray16 m_kUnsignedIntArray16;
    StatsChunkData Data;
    UInt32ChunkData AdvancedData;

    TESCombatStyle();
    void ResetFormData();
    bool Load(TESFile*);
    float GetRandomValue();
    float UpdateCombatStyle();
    void UpdateCombatStyle() const;
};
