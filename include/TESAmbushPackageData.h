#pragma once

#include "TESPackageData.h"

class AF50Location;

// pdb: class TESAmbushPackageData, size 0x8, bases: TESPackageData, 1 members
class TESAmbushPackageData : public TESPackageData
{
public:
    virtual ~TESAmbushPackageData();

    bool vf02(TESPackageData* pkOtherData);

    void* Destroy(unsigned int flags);
    void SaveWithTag();
    void SetLocationFromPackage(int apCopy);
    bool Compare_0067af50(TESPackageData* apCompare);

    AF50Location* pAmbushLocation;
};
