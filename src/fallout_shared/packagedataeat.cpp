
// src/fallout_shared/packagedataeat.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataeat.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/TESEatPackageData.h"

void __cdecl _FUN_004856d0(int);
struct LocationDescriptor
{
    LocationDescriptor();
    char pad[12];
    void __thiscall PackageLocation_Save(int);
    void PackageLocation_InitLoadGame(BGSLoadFormBuffer*);
    void PackageLocation_LoadGame(BGSLoadFormBuffer*);
    void* FUN_00670b30(int aFlags);
    unsigned char __thiscall PackageLocation_Compare(int apCompare);
};

// @fnv 0x0067bbb0
// src: XBOX_PDB 0x0067bbb0
// pdb: TESEatPackageData::Save | PackageDataEat.obj | retail, vtable slot, high
void __thiscall TESEatPackageData::Save_0067bbb0()
{
    _FUN_004856d0(0x44454b50);
    if (this->pSearchLocation != 0)
    {
        pSearchLocation->PackageLocation_Save(0x32444c50);
    }
}

// @fnv 0x0067bfa0
// src: GUESS 0x0067bfa0 (confidence: low)
void TESEatPackageData::ProcessState_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (pSearchLocation != 0)
    {
        pSearchLocation->PackageLocation_InitLoadGame(apLoadGameBuffer);
    }
}

// @fnv 0x0067b050
// pdb: TESUseItemPackageData::LoadGame | PackageDataUseItem.obj | retail, vtable slot, high
// pdb params: apLoadGameBuffer
// pdb locals: bhasLocation
void __thiscall TESEatPackageData::Load(BGSLoadFormBuffer* apLoadGameBuffer)
{
    bool bhasLocation = false;
    apLoadGameBuffer->ReadTypedData((void*)&bhasLocation, 1u);
    if (bhasLocation)
    {
        pSearchLocation = new LocationDescriptor;
        pSearchLocation->PackageLocation_LoadGame(apLoadGameBuffer);
    }
}

// @fnv 0x0067b9b0
// pdb: TESEatPackageData::~TESEatPackageData | PackageDataEat.obj | debug, upstream name already matches, high
TESEatPackageData::~TESEatPackageData()
{
    LocationDescriptor* a = pSearchLocation;
    LocationDescriptor* p = a;
    (p != 0) ? p->FUN_00670b30(1) : 0;
}

extern "C" int __cdecl FUN_00ec43fb(int a1, int a2, int* a3, int* a4, int a5);

extern int DAT_0119bdec;
extern int DAT_0119be3c;

struct FUN_0067bb40_Result
{
    int unk00;
    int unk04;
};

// @fnv 0x0067bb40
// src: XBOX_PDB 0x0067bb40
// pdb: TESEatPackageData::Compare | PackageDataEat.obj | retail, vtable slot, high
// pdb params: apCompare
// pdb locals: pcomp
unsigned char __thiscall TESEatPackageData::Compare_0067bb40(int apCompare)
{
    FUN_0067bb40_Result* result = (FUN_0067bb40_Result*)FUN_00ec43fb(apCompare, 0, &DAT_0119bdec, &DAT_0119be3c, 0);

    if (result == 0)
    {
        return 1;
    }

    if (pSearchLocation != 0)
    {
        if (pSearchLocation->PackageLocation_Compare(result->unk04) != 0)
        {
            return 1;
        }
    }
    else if (result->unk04 != 0)
    {
        return 1;
    }

    return 0;
}
