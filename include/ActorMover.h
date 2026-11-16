#pragma once

#pragma push_macro("ActorPathHandler")
#undef ActorPathHandler
#include "ActorPathHandler.h"
#include "NiAVObject.h"
#include "NiPoint3.h"
#include "PathingLocation.h"

class Actor;
class ActorPathingMessageQueue;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class NiNode;
class PathingRequest;
class TESForm;
class TESPackage;
class TESObjectREFR;
class TESWorldSpace;
struct DcVec;
struct Fx_Arg;
struct PkgTriple;

// pdb: class ActorMover, size 0x88, 27 members
class ActorMover
{
public:
    ~ActorMover();

    virtual void* DestroyIfFlagged(unsigned int flags);
    virtual void SetMoveModeFlags(unsigned int);
    virtual void ClearFlags(unsigned int mask);
    virtual void SetAnimationFlags(unsigned short flags);
    virtual void ResetMovementData();
    virtual void Update_009dc120(float);
    virtual void vf06();
    virtual void vf07();
    virtual unsigned int vf08();
    virtual bool GetPathingDelta(NiPoint3&);
    virtual void SaveGame_009df100(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame_009df3d0(BGSLoadFormBuffer* apLoadGameBuffer);
    virtual void InitLoadGame_009df8c0(BGSLoadFormBuffer* buffer);
    virtual void FinishLoadGame_009dfa00(BGSLoadFormBuffer* buffer);
    virtual void ResetPathingState(BGSLoadFormBuffer* apBuffer);

    NiPoint3 LookAtPoint;                 // 0x04 // src: XBOX_RETAIL_PDB +0x4 (old: m_kLookAtTargetPosition)
    NiPoint3 CachedMoveDelta;                        // 0x10 // src: XBOX_RETAIL_PDB +0x10 (old: m_kPathingDelta)
    NiPointer<PathingRequest> spCurrentRequest;              // 0x1c // src: XBOX_RETAIL_PDB +0x1c (old: request)
    NiPointer<NiNode> spCurrentPath;                  // 0x20 // src: XBOX_RETAIL_PDB +0x20 (old: m_pActorNode)
    union
    {
        ActorPathHandler* m_pPathHandler;           // 0x24
        unsigned int preferredMoveMode;
    };
    Actor* pActor;                                  // 0x28
    unsigned int DetectionDoorID; // src: XBOX_RETAIL_PDB +0x2c (old: unk2C)
    NiPointer<ActorPathingMessageQueue> spMessageQueue;     // 0x30 // src: XBOX_RETAIL_PDB +0x30 (old: m_queue)
    unsigned int uiPreferredMoveMode; // src: XBOX_RETAIL_PDB +0x34 (old: unk34)
    unsigned int uiForcedMoveMode;                 // 0x38 // src: XBOX_RETAIL_PDB +0x38 (old: m_uiMovementFlags)
    unsigned int iCachedLastValidMoveMode;                  // 0x3c // src: XBOX_RETAIL_PDB +0x3c (old: m_uiMovementMode)
    unsigned short iPreviousNode;                    // 0x40 // src: XBOX_RETAIL_PDB +0x40 (old: currentNode)
    unsigned short iNextNode;                       // 0x42 // src: XBOX_RETAIL_PDB +0x42 (old: lastNode)
    PathingLocation FailedPathDestination;              // 0x44 // src: XBOX_RETAIL_PDB +0x44 (old: m_pathingLocation)
    int eState;                                    // 0x6c
    bool bPathingFailed;                            // 0x70
    bool bForceMoveMode;                        // 0x71 // src: XBOX_RETAIL_PDB +0x71 (old: m_bHasMovementData)
    bool bStopMovementNextUpdate;                       // 0x72 // src: XBOX_RETAIL_PDB +0x72 (old: m_bMovementComplete)
    bool bFaceTargetPoint;                        // 0x73 // src: XBOX_RETAIL_PDB +0x73 (old: m_bHasLookAtTarget)
    bool bWaitingForPath;                         // 0x74 // src: XBOX_RETAIL_PDB +0x74 (old: m_bMovementActive)
    bool bActorChangedProcessLevel;                      // 0x75 // src: XBOX_RETAIL_PDB +0x75 (old: m_bMovementStateFlag)
    bool bInDialog;                         // 0x76 // src: XBOX_RETAIL_PDB +0x76 (old: m_bMovementPaused)
    bool bHaveValidDeltaThisFrame;                        // 0x77 // src: XBOX_RETAIL_PDB +0x77 (old: m_bHasPathingDelta)
    bool bStopCurrentMoveAnim; // src: XBOX_RETAIL_PDB +0x78 (old: unk78)
    unsigned char unk79[3];
    unsigned int iLastFailureTimeStamp;                          // 0x7c // src: XBOX_RETAIL_PDB +0x7c (old: lastTime)
    unsigned int iFirstFailureTimeStamp;                         // 0x80 // src: XBOX_RETAIL_PDB +0x80 (old: startTime)
    int iContinuedFailureCount;                                   // 0x84 // src: XBOX_RETAIL_PDB +0x84 (old: retries)

    void ClearMovementPath();
    void RefreshMovementState();
    void StopMoving();
    bool HasLookAtTarget();
    bool IsMovementActive();
    unsigned int GetPreferredMoveModeType();
    void RunProcedure();
    void UpdateMovement(float);
    void HandlePathingResult(ActorPathHandler::PATH_HANDLER_RESULT);
    void UpdateMovementStatus(bool);
    bool HasActiveMovement();
    void ForceStopMoving();
    void Revert(BGSLoadFormBuffer* apBuffer);
    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    bool GetLookAtTargetPosition(NiPoint3& point);
    unsigned int GetCurrentMoveModeType();
    void UpdatePackageData(TESPackage*);
    void ForceMoveMode(int aiMoveMode);
    unsigned int GetActorStateFlags();
    void UpdateTeleportPathState();
    void UpdateFlagFromTarget();
    DcVec* GetVec(DcVec* out, float f);
    PkgTriple* FUN_009de0a0(PkgTriple* out);
    bool ApplyNodeLookup(Fx_Arg* arg);
    bool SetGoal_009dba50(int, int, int, float, int);
    bool SetGoalAndAngle(int, int, int, float, float, int);
    void SetGoalAndAngle(NiPoint3*, TESObjectREFR*, TESWorldSpace*, float, float, int);
    bool SetGoal_009dbb10(TESObjectREFR*, float, int);
    void SetGoalAndAngle_(TESObjectREFR*, float, int);
    int GetCurrentNodeIndex();
    bool IsWaitingForAvoidance();
    bool IsMovementBlocked();
    float GetCurrentPercent();
    float GetDistanceTraveled();
    float GetDistanceRemaining();
    bool ComputePathPassesThroughPlayersArea();
    void PathingSolution_GetLastVirtualNode();
    void FUN_009dd0a0();
    void FUN_009dd150();

    void ClearDataForNewPathingRequest(bool abClearWaitingFlag);
    void ClearDataForNewPathingRequest(int);
    bool HasPathingSolution();
    void SetMoveTarget(NiPoint3 target);
    bool GetPathCoordinate(NiPoint3* apRetLocation);
    int UpdatePathHandler();
    void ResetPathing();
    void SetPathFailed(bool abValue);
    void HandlePathResult(int result);
    void UpdatePathMovement();
    void UpdatePathingState(float);
    void SetEnabled(bool abValue);
    void SetEnabled(int);
    void UpdateTargeting();
    void SetFormID(TESForm* form);
    PathingLocation* GetPathingLocation();

    bool BackGroundBuildPath(const PathingRequest* request);
    bool SetGoal(const PathingRequest* request);
    void ActorMover_ClearCurrentData();
    bool PathingSolution_IsValid();
    void FUN_009dc590(float);
    int EndOfCurrentPathCheck();
    bool IsPathingComplete();
    void* RequestRotateActor(NiPoint3 aTargetPoint, bool abForceTurn);
    bool RequestRotateActor_009dce80(float afTargetAngle, bool abForceTurn);
    unsigned int GetPreferredMoveModeType_009dd130();
    void FinishMoving(bool clearHandler);
    void FinishMoving(int);
    void SetCurrentFrameMoveModeAndDelta();
    bool GetNodeLocation(int, int);
    bool IsPathValid();
    bool MoveActorToLocation(const NiPoint3& location);
    void FUN_00483710();

protected:
    void SetMovementMode(bool);

private:
    void DebugOnStopMoving();
};

#pragma pop_macro("ActorPathHandler")
