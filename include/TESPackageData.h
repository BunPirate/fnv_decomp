#pragma once

class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class TESForm;
class TESPatrolPackageData;

// pdb: class TESPackageData, size 0x4, 0 members
class TESPackageData
{
public:
    TESPackageData();
    virtual ~TESPackageData();
    virtual void Copy(TESPatrolPackageData* source);
    virtual bool vf02(TESPackageData* other);
    virtual void vf03();
    virtual void InitItem(TESForm* item);
    virtual void SaveToBuffer(BGSSaveFormBuffer* buffer);
    virtual void vf06(BGSLoadFormBuffer* buffer);
    virtual void vf07(BGSLoadFormBuffer* buffer);

    void Save(int);
};
