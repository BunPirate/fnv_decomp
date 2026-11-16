#pragma once

#include "TESPackageData.h"

// pdb: class TESPatrolPackageData, size 0x8, bases: TESPackageData, 2 members
class TESPatrolPackageData : public TESPackageData
{
public:
    struct PatrolParams
    {
        unsigned char a;
        unsigned char b;
    };

    TESPatrolPackageData();
    TESPatrolPackageData(PatrolParams aParams);
    TESPatrolPackageData(unsigned char a, unsigned char b);

    virtual ~TESPatrolPackageData();
    virtual void Copy(TESPatrolPackageData* source) override;
    virtual bool vf02(TESPackageData* other) override;
    virtual void vf03() override;
    virtual void InitItem(TESForm* item) override;
    virtual void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer) override;
    virtual void vf06(BGSLoadFormBuffer* buffer) override;
    virtual void vf07(BGSLoadFormBuffer* buffer) override;

    bool bRepeatable; // src: XBOX_RETAIL_PDB +0x4 (old: m_bPrimaryComparisonFlag)
    bool bStartingLocationAtLinkedRef; // src: XBOX_RETAIL_PDB +0x5 (old: m_bSecondaryComparisonFlag)

    void Unused();
    TESPatrolPackageData* __thiscall TESPatrolPackageData_TESPatrolPackageData(PatrolParams aParams);
    void Copy_0067c4b0(TESPackageData* apCopy);
    bool Compare_0067c500(TESPackageData* apCompare);
    void Save_0067c570();
    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
};
