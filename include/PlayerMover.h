#pragma once

#include "ActorMover.h"
#include "NiPoint3.h"

class BGSLoadFormBuffer;

// pdb: class PlayerMover, size 0xa0, bases: ActorMover, 4 members
class PlayerMover : public ActorMover
{
public:
    ~PlayerMover();

    void SetMoveModePreference(unsigned int auiPreferredMoveMode);
    void ClearMoveModePreference(unsigned int auiPreferredMoveMode);
    void* FUN_009e9e00(unsigned int auFlags);
    void ResetVtableAndDestroyActorMover();
    void SaveGame_009ea5a0(BGSSaveFormBuffer* apSaveGameBuffer);

    void Revert(BGSLoadFormBuffer* apLoadGameBuffer);
    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void SetMovementValue(float fdeltaT);
    void Update(float fdeltaT);
    void SetMoverMode(unsigned int auMode);
    void UpdatePlayerStatus(unsigned int auMode, bool abSet);
    void SetSideVec(const NiPoint3& arSideVec);
    void ClearMode(unsigned int auMode);
    unsigned int GetActorStateFlags();

    NiPoint3 SideVec;
    unsigned int MoveMode;
    unsigned int LastTurnDir;
    float fMinTurnTime;
};
