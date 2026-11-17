#pragma once

#include "CombatProcedure.h"
#include "IDebugText.h"

class Projectile;

// pdb: class CombatProcedureBeInCover, size 0x6c, bases: CombatProcedure, 11 members
class CombatProcedureBeInCover : public CombatProcedure
{
public:
    enum COVER_STATE  // values: Xbox PDB CombatProcedureBeInCover::COVER_STATE
    {
        COVER_STATE_INITIALIZING = 0,
        COVER_STATE_WAITING_BEHIND_COVER = 1,
        COVER_STATE_MOVING_OUT = 2,
        COVER_STATE_WAITING_OUT_OF_COVER = 3,
        COVER_STATE_FIRING_OUT_OF_COVER = 4,
        COVER_STATE_MOVING_IN = 5,
        COVER_STATE_MOVING_IN_AND_ROTATE = 6,
        COVER_STATE_HOLDING_GROUND = 7
    };

    struct Timer
    {
        float m_fStartTime;
        float m_fTimeout;

        bool CombatTimer_IsSet();
        float GetValue();
        float GetElapsedTime();
    };

    CombatProcedureBeInCover(void* apCombatCoverLocation);

    virtual ~CombatProcedureBeInCover();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    void DebugText(IDebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY);
    void UpdateCoverState();
    void StopAttackerAndEngageTarget();
    void UpdateCombatProcedure(Projectile* apProjectile);

    COVER_STATE eState;
    void* pCoverLocation; // src: XBOX_RETAIL_PDB +0x14 (old: m_pCurrentCoverPoint)
    float CurrentCoverPosition[3]; // src: XBOX_RETAIL_PDB +0x18 (old: m_afFirstVector)
    float CurrentFirePosition[3]; // src: XBOX_RETAIL_PDB +0x24 (old: m_afSecondVector)
    unsigned char LookAtPosition[0x0C]; // src: XBOX_RETAIL_PDB +0x30 (old: _pad1)
    Timer WaitBehindCoverTimer; // src: XBOX_RETAIL_PDB +0x3c (old: m_waitTimer)
    Timer WaitingOutOfCoverTimer; // src: XBOX_RETAIL_PDB +0x44 (old: m_waitingOutTimer)
    Timer FiringOutOfCoverTimer; // src: XBOX_RETAIL_PDB +0x4c (old: m_firingTimer)
    Timer ReevaluateCoverTimer; // src: XBOX_RETAIL_PDB +0x54 (old: m_reevaluateTimer)
    Timer HoldingGroundTimer; // src: XBOX_RETAIL_PDB +0x5c (old: m_holdingGroundTimer)
    Timer TargetBlockedTimer; // src: XBOX_RETAIL_PDB +0x64 (old: m_targetBlockedTimer)
};
