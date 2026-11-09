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
    void* pCoverLocation;
    float CurrentCoverPosition[3];
    float CurrentFirePosition[3];
    unsigned char LookAtPosition[0x0C];
    Timer WaitBehindCoverTimer;
    Timer WaitingOutOfCoverTimer;
    Timer FiringOutOfCoverTimer;
    Timer ReevaluateCoverTimer;
    Timer HoldingGroundTimer;
    Timer TargetBlockedTimer;
};
