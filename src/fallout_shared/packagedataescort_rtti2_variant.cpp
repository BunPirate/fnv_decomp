// src/fallout_shared/packagedataescort_rtti2_variant.cpp - escort package RTTI comparison.
// Original source: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp.
#include "../../include/TESEscortPackageData.h"
#include "../../include/TESPackageData.h"

struct EscortLocationComparison
{
    bool __thiscall PackageLocation_Compare(LocationDescriptor* apCompare);
};

// The shared class does not yet declare this comparison method.
struct EscortComparison : TESEscortPackageData
{
    bool __thiscall TESEscortPackageData_Compare(TESPackageData* apCompare);
};

// @fnv 0x0067be40
// src: XBOX_PDB 0x0067be40
// pdb: TESEscortPackageData::Compare | PackageDataEscort.obj | retail, upstream name already matches, high
// pdb params: apCompare
// pdb locals: pcomp
bool EscortComparison::TESEscortPackageData_Compare(TESPackageData* apCompare)
{
    TESEscortPackageData* other = dynamic_cast<TESEscortPackageData*>(apCompare);
    if (!other)
        return true;
    if (pSearchLocation)
    {
        if (reinterpret_cast<EscortLocationComparison*>(pSearchLocation)->PackageLocation_Compare(other->pSearchLocation))
            return true;
    }
    else if (other->pSearchLocation)
    {
        return true;
    }
    if (iFollowPackRadius != other->iFollowPackRadius)
        return true;
    return false;
}
