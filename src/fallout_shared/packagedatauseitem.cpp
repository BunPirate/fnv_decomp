// src/fallout_shared/packagedatauseitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatauseitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../include/TESUseItemPackageData.h"

extern "C" void __cdecl TESForm_AddChunk(int);
struct LocationDescriptor
{
    ~LocationDescriptor();
    void Save(int);
    bool PackageLocation_Compare(LocationDescriptor* apCompare);
};
// @fnv 0x0067c9d0
// pdb: TESUseItemPackageData::Save | PackageDataUseItem.obj | retail, vtable slot, high
void TESUseItemPackageData::vf03()
{
    TESForm_AddChunk(0x44495550);
    if (this->pSearchLocation != 0)
        this->pSearchLocation->Save(0x32444c50);
}

// The compiler emits the scalar deleting destructor at 0x0067c7a0.
// @fnv 0x0067c7d0
// pdb: TESUseItemPackageData::~TESUseItemPackageData | PackageDataUseItem.obj | debug, upstream name already matches, high
TESUseItemPackageData::~TESUseItemPackageData()
{
    delete pSearchLocation;
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long vf, void* src, void* tgt, int isRef);
extern int DAT_0119bdec;
extern int DAT_0119bed8;
// Returns true if the cast fails, the target comparison returns true, or only the other target is non-null.
// @fnv 0x0067c960
// pdb: TESUseItemPackageData::Compare | PackageDataUseItem.obj | retail, vtable slot, high
// pdb params: apCompare
// pdb locals: pcomp
bool TESUseItemPackageData::vf02(TESPackageData* apCompare)
{
    TESUseItemPackageData* pUseItemData =
        (TESUseItemPackageData*)FUN_00ec43fb(apCompare, 0, &DAT_0119bdec, &DAT_0119bed8, 0);
    if (!pUseItemData)
        return true;
    if (pSearchLocation)
    {
        if (pSearchLocation->PackageLocation_Compare(pUseItemData->pSearchLocation))
            return true;
    }
    else if (pUseItemData->pSearchLocation)
        return true;
    return false;
}
