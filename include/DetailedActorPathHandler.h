#pragma once

#include "ActorPathHandler.h"
#include "NiPoint3.h"
#include "MagicTarget.h"

class TESTopicInfo;
class TESObjectREFR;
class NiNode;

// pdb: class DetailedActorPathHandler, size 0xe4, bases: ActorPathHandler, 45 members
class DetailedActorPathHandler : public ActorPathHandler
{
public:
    DetailedActorPathHandler(int a1, int a2);
    DetailedActorPathHandler(void* apActor, void* apMover, NiPointer<PathingSolution>* apPathPtr, void* apRequest);
    ~DetailedActorPathHandler();

    unsigned char fTetherMinMove[0x08]; // src: XBOX_RETAIL_PDB +0x14 (old: pad14)
    NiPoint3 MoveDelta; // src: XBOX_RETAIL_PDB +0x1c (old: m_kPathVector1)
    NiPoint3 BlockedTargetPoint; // src: XBOX_RETAIL_PDB +0x28 (old: m_kPathVector2)
    NiPoint3 TetherTargetPoint; // src: XBOX_RETAIL_PDB +0x34 (old: m_kPathVector3)
    NiPoint3 LastLocation; // src: XBOX_RETAIL_PDB +0x40 (old: m_kActorPosition)
    NiPoint3 LastTetherPoint; // src: XBOX_RETAIL_PDB +0x4c (old: m_kPathVector4)
    BSSimpleList<TESTopicInfo*> ActorAvoidList; // src: XBOX_RETAIL_PDB +0x58 (old: ActorAvoidEntryList)
    unsigned int MoveMode; // src: XBOX_RETAIL_PDB +0x60 (old: ByteAndFlagState)
    unsigned int iCurrentNodeIndex; // src: XBOX_RETAIL_PDB +0x64 (old: m_uiPathPointIndex)
    float fRotateGoal; // src: XBOX_RETAIL_PDB +0x68 (old: m_fPathValue1)
    float fPathLength; // src: XBOX_RETAIL_PDB +0x6c (old: m_fPathValue2)
    float fCurrentSplineT; // src: XBOX_RETAIL_PDB +0x70 (old: m_fSplineParameter)
    float fActorAvoidanceTimer; // src: XBOX_RETAIL_PDB +0x74 (old: m_fPathValue4)
    float fAvoidanceDetectionValue; // src: XBOX_RETAIL_PDB +0x78 (old: m_fPathValue5)
    int iUnblockDirection; // src: XBOX_RETAIL_PDB +0x7c (old: m_iPathValue1)
    float fAlternateFacingAngle; // src: XBOX_RETAIL_PDB +0x80 (old: m_fPathValue6)
    float fBlockedStartAngle; // src: XBOX_RETAIL_PDB +0x84 (old: m_fPathValue7)
    float fBlockTime; // src: XBOX_RETAIL_PDB +0x88 (old: m_fPathValue8)
    float fTimeInAnim; // src: XBOX_RETAIL_PDB +0x8c (old: m_fPathValue9)
    float fRunWalkTime; // src: XBOX_RETAIL_PDB +0x90 (old: m_fPathValue10)
    float fMinRotateTime; // src: XBOX_RETAIL_PDB +0x94 (old: m_fPathValue11)
    float fWaitTime; // src: XBOX_RETAIL_PDB +0x98 (old: m_fPathValue12)
    float fLastFrameMinMoveDelta; // src: XBOX_RETAIL_PDB +0x9c (old: m_fPathValue13)
    NiPoint3 LastFrameMinMoveDelta; // src: XBOX_RETAIL_PDB +0xa0 (old: m_kPathVector5)
    float fGoalRadiusSqr; // src: XBOX_RETAIL_PDB +0xac (old: m_fPathValue14)
    float fFallTime; // src: XBOX_RETAIL_PDB +0xb0 (old: m_fPathValue15)
    float fDistanceTraveled; // src: XBOX_RETAIL_PDB +0xb4 (old: m_fPathValue16)
    float fIgnoreLookAtPointTimer; // src: XBOX_RETAIL_PDB +0xb8 (old: m_fPathValue17)
    float fLastRotationApplied; // src: XBOX_RETAIL_PDB +0xbc (old: m_fPathValue18)
    bool bIgnoreInitialRotation; // src: XBOX_RETAIL_PDB +0xc0 (old: m_bHasPathingSolution)
    bool bIgnoreInitialRotationKeepActorHeading; // src: XBOX_RETAIL_PDB +0xc1 (old: m_bPathingRequestPending)
    unsigned char padC2[0x02];
    float fIgnoreInitialRotationTetherParam; // src: XBOX_RETAIL_PDB +0xc4 (old: m_fElapsedTime)
    int eState;
    int eBlendRunning; // src: XBOX_RETAIL_PDB +0xcc (old: m_iPathParameter1)
    int eAvoidState; // src: XBOX_RETAIL_PDB +0xd0 (old: m_iPathParameter2)
    int eDoorState; // src: XBOX_RETAIL_PDB +0xd4 (old: m_iPathValue2)
    void* pCurrentDoor; // src: XBOX_RETAIL_PDB +0xd8 (old: m_pPathTargetReference)
    bool bRotateMode; // src: XBOX_RETAIL_PDB +0xdc (old: m_bPathFlag1)
    bool bRotateCCW; // src: XBOX_RETAIL_PDB +0xdd (old: m_bPathFlag2)
    bool bMovementBlocked; // src: XBOX_RETAIL_PDB +0xde (old: m_bPathFlag3)
    bool bEndUpdatePath; // src: XBOX_RETAIL_PDB +0xdf (old: m_bPathFlag4)
    bool bWaitingForUpdate; // src: XBOX_RETAIL_PDB +0xe0 (old: m_bPathFlag5)
    bool bIgnoreLookAtPoint; // src: XBOX_RETAIL_PDB +0xe1 (old: m_bPathFlag6)
    bool bDeltaComputedThisFrame; // src: XBOX_RETAIL_PDB +0xe2 (old: m_bPathFlag7)
    unsigned char padE3[1];

    virtual bool GetPathingDelta(NiPoint3* outDelta);
    bool TurnToAngle(float afTargetAngle, bool abForceTurn);
    bool StartTurningToAngle(float angle, bool keepActorHeading, bool ignoreInitialRotation);
    void SetInitialPathState();
    void TransitionFrom(ActorPathHandler* apOldHander);
    static void UpdateSceneNode(NiNode*);
    void HandleReferenceUpdate(TESObjectREFR*, bool, bool);
};
