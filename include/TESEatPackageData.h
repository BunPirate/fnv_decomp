#pragma once

#include "TESPackageData.h"

class LocationDescriptor;
class BGSLoadFormBuffer;

// pdb: class TESEatPackageData, size 0x8, bases: TESPackageData, 1 members
class TESEatPackageData : public TESPackageData
{
public:
    virtual ~TESEatPackageData();
    virtual void vf03();

    void vf07(BGSLoadFormBuffer* apLoadGameBuffer);

    void __thiscall Load(BGSLoadFormBuffer* apLoadGameBuffer);
    void __thiscall Copy_0067ba40(int apCopy);
    unsigned char __thiscall Compare_0067bb40(int apCompare);
    void __thiscall Save_0067bbb0();
    void ProcessState_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer);
    void PackageLocation_LoadGame_0067fbe0(BGSLoadFormBuffer* apLoadGameBuffer);

    LocationDescriptor* pSearchLocation;
};
