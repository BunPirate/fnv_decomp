#pragma once

#include "TESPackageData.h"

class FollowPackageField;

// pdb: class TESFollowPackageData, size 0xc, bases: TESPackageData, 2 members
class TESFollowPackageData : public TESPackageData
{
public:
    TESFollowPackageData(float afValue);
    virtual ~TESFollowPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    FollowPackageField* pStartLocation; // src: XBOX_RETAIL_PDB +0x4 (old: m_04)
    float fTriggerRadius; // src: XBOX_RETAIL_PDB +0x8 (old: m_08)

    TESFollowPackageData* Construct(float afValue);
    void* DestroyIfFlagged(unsigned int flags);
    void SaveFloatRecord();
    void FUN_0067c080();
    void Copy_0067c110(TESPackageData* apCopy);
    bool Compare_0067c220(TESPackageData* apCompare);
};
