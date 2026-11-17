#pragma once

#include "BGSEntryPointFunctionData.h"

// pdb: class BGSEntryPointFunctionDataTwoValue, size 0xc, bases: BGSEntryPointFunctionData, 2 members
class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionDataTwoValue();

    float fValue1; // src: XBOX_RETAIL_PDB +0x4 (old: EntryPointTwoValueFunctionData)
    float fValue2; // src: XBOX_RETAIL_PDB +0x8 (old: fSecondFunctionValue)

    float ReadValueA();
    float ReadValueB();

    BGSEntryPointFunctionDataTwoValue* Duplicate_005e67f0();
    bool Compare_005e6890(BGSEntryPointFunctionData* apCompare);
    void Save_005e6900();
    bool Load_005e6970(TESFile* apFile);
    void FUN_005e6490();
    void* FUN_005e64e0(unsigned int flags);
};
