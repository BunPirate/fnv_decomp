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

    unsigned char fTetherMinMove[0x08];
    NiPoint3 MoveDelta;
    NiPoint3 BlockedTargetPoint;
    NiPoint3 TetherTargetPoint;
    NiPoint3 LastLocation;
    NiPoint3 LastTetherPoint;
    BSSimpleList<TESTopicInfo*> ActorAvoidList;
    unsigned int MoveMode;
    unsigned int iCurrentNodeIndex;
    float fRotateGoal;
    float fPathLength;
    float fCurrentSplineT;
    float fActorAvoidanceTimer;
    float fAvoidanceDetectionValue;
    int iUnblockDirection;
    float fAlternateFacingAngle;
    float fBlockedStartAngle;
    float fBlockTime;
    float fTimeInAnim;
    float fRunWalkTime;
    float fMinRotateTime;
    float fWaitTime;
    float fLastFrameMinMoveDelta;
    NiPoint3 LastFrameMinMoveDelta;
    float fGoalRadiusSqr;
    float fFallTime;
    float fDistanceTraveled;
    float fIgnoreLookAtPointTimer;
    float fLastRotationApplied;
    bool bIgnoreInitialRotation;
    bool bIgnoreInitialRotationKeepActorHeading;
    unsigned char padC2[0x02];
    float fIgnoreInitialRotationTetherParam;
    int eState;
    int eBlendRunning;
    int eAvoidState;
    int eDoorState;
    void* pCurrentDoor;
    bool bRotateMode;
    bool bRotateCCW;
    bool bMovementBlocked;
    bool bEndUpdatePath;
    bool bWaitingForUpdate;
    bool bIgnoreLookAtPoint;
    bool bDeltaComputedThisFrame;
    unsigned char padE3[1];

    virtual bool GetPathingDelta(NiPoint3* outDelta);
    bool TurnToAngle(float afTargetAngle, bool abForceTurn);
    bool StartTurningToAngle(float angle, bool keepActorHeading, bool ignoreInitialRotation);
    void SetInitialPathState();
    void TransitionFrom(ActorPathHandler* apOldHander);
    static void UpdateSceneNode(NiNode*);
    void HandleReferenceUpdate(TESObjectREFR*, bool, bool);
};
