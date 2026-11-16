#pragma once

#include "ActorPackageData.h"
#include "MagicTarget.h"

class Actor;
class TESPackage;
class TESEscortPackageData;

// pdb: class EscortActorPackageData, size 0x18, bases: ActorPackageData, 4 members
class EscortActorPackageData : public ActorPackageData
{
public:
    EscortActorPackageData();
    virtual ~EscortActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    void FUN_0067d920();
    void RegisterActor(Actor* apActor);
    void RemoveActorFromList(Actor* actor);
    int GetNumEscortedActorsOfType(Actor* apEscorter, void* apType);

    Actor* pActor;
    TESPackage* pPackage;
    const TESEscortPackageData* pPackageData; // src: XBOX_RETAIL_PDB +0xc (old: m_pEscortPackageData)
    BSSimpleList<Actor*> EscortedActors; // src: XBOX_RETAIL_PDB +0x10 (old: m_kActorList)
};
