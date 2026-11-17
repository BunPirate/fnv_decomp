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

    NiPoint3 SideVec; // src: XBOX_RETAIL_PDB +0x88 (old: m_kSideVec)
    unsigned int MoveMode; // src: XBOX_RETAIL_PDB +0x94 (old: ByteAndFlagState)
    unsigned int LastTurnDir; // src: XBOX_RETAIL_PDB +0x98 (old: m_uiMode)
    float fMinTurnTime; // src: XBOX_RETAIL_PDB +0x9c (old: m_fValue)
};
