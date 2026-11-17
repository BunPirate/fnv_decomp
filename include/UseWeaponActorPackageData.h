#pragma once

#include "ActorPackageData.h"

class TESObjectREFR;

// pdb: class UseWeaponActorPackageData, size 0x8, bases: ActorPackageData, 1 members
class UseWeaponActorPackageData : public ActorPackageData
{
public:
    UseWeaponActorPackageData();
    virtual ~UseWeaponActorPackageData();
    void SetReferenceTarget(TESObjectREFR* reference) override;
    void LoadGame(BGSLoadFormBuffer* apBuffer) override;
    void InitLoadGame(BGSLoadFormBuffer* apBuffer) override;

    TESObjectREFR* m_pUseTarget;
};
