#pragma once

#include "TESPackageData.h"

class LocationDescriptor;

// pdb: class TESUseItemPackageData, size 0x8, bases: TESPackageData, 1 members
class TESUseItemPackageData : public TESPackageData
{
public:
    virtual ~TESUseItemPackageData();
    virtual bool vf02(TESPackageData* other) override;
    virtual void vf03();

    void vf01(TESPackageData* apCopy);
    void FUN_0067c9d0();

    LocationDescriptor* pSearchLocation; // src: XBOX_RETAIL_PDB +0x4 (old: m_pPackageTarget)
};
