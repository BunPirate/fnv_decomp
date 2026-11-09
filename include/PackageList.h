#pragma once

#include "MagicTarget.h"

class Actor;
class TESForm;
class TESPackage;

// pdb: class PackageList, size 0x8, 1 members
class PackageList
{
public:
    BSSimpleList<TESPackage*> listPackages;

    ~PackageList();
    void FUN_0067e3a0();
    int FUN_00726070();
    BSSimpleList<TESPackage*>* GetListOfPackages();
    BSSimpleList<TESPackage*>* GetListOfPackages() const;
    void Copy(const PackageList* apPackList);
    void FreePackageList();
    TESPackage* FindCurrentPackage(Actor* apActor);
    void CollectEligiblePackages(Actor* actor, BSSimpleList<TESPackage*>* packages, float first, float second);
    void InitItem(TESForm* apOwner);
    void AddPackage(TESPackage* apPack);
    bool DiffersFrom(PackageList* other);
};
