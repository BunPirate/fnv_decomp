#pragma once

#include "TESPackageData.h"

class LocationDescriptor;

// pdb: class TESEscortPackageData, size 0xc, bases: TESPackageData, 2 members
class TESEscortPackageData : public TESPackageData
{
public:
    TESEscortPackageData();
    virtual ~TESEscortPackageData();

    LocationDescriptor* pSearchLocation;
    int iFollowPackRadius;

    TESEscortPackageData* __thiscall ConstructFromForm(TESForm** pForm);
    void TESFollowPackageData_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void LoadPackageData(BGSLoadFormBuffer* apCopy);

    void FUN_0067ad20();
    TESEscortPackageData* TESEscortPackageData_0067bbf0();
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
    void Save_0067bec0();
    void SaveGame_0067bf40(BGSSaveFormBuffer* apSaveGameBuffer);
};
