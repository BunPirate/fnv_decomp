#pragma once

#include "ActorPackageData.h"

class Actor;

// pdb: class GuardActorPackageData, size 0x14, bases: ActorPackageData, 4 members
class GuardActorPackageData : public ActorPackageData
{
public:
    enum GUARD_STATE
    {
        GUARD_STATE_INIT = 0,
        GUARD_STATE_IDLE = 1,
        GUARD_STATE_WAIT_TO_ATTACK = 2
    };

    GuardActorPackageData();
    virtual ~GuardActorPackageData();

    void* DestroyIfFlagged(unsigned int flags);

    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    GUARD_STATE eState;
    Actor* pGuardWarnedActor;
    int iWarningCount;
    float fGuardTimer;
};
