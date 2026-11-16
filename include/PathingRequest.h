#pragma once

#include "NiRefObject.h"
#include "NiAVObject.h"
#include "PathingLocation.h"
#include "PathingActorData.h"
#include "NiPoint3.h"

class Actor;
class Arg1Class;
class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class EvadeActor;
class MoveActor454;
class PathingAvoidNodeArray;
class PathingDebugOutput;
class PathingRequestOwner;
class NiMatrix3;
template <class T, unsigned int N> class BSSimpleArray;
enum PATHING_REQUEST_TYPE;

// pdb: class PathingRequest, size 0xb0, bases: NiRefObject, 29 members
class PathingRequest : public NiRefObject
{
public:
    PathingRequest();
    PathingRequest(PathingRequest*);
    PathingRequest(PathingRequestOwner*);
    virtual ~PathingRequest();
    virtual void DeleteThis();
    virtual void CopyTo(PathingRequest*);
    virtual void vfn_c();
    virtual PATHING_REQUEST_TYPE GetType();
    virtual void PrintDebugInfo(PathingDebugOutput*);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void InitLoadGame(BGSLoadFormBuffer*);

    static PathingRequest* CreatePathingRequest(PATHING_REQUEST_TYPE);

    void SetUseSoft(bool);
    void SetTargetAngle(float);
    void PathingRequest_SetOrigin(Actor*);
    void PathingRequest_SetOrigin(EvadeActor*);
    void PathingRequest_SetOrigin(MoveActor454*);
    void SetInitialPathHeading(float);
    void SetCantOpenDoors(bool);
    void SetCanSwim(bool);
    void SetOrigin(PathingLocation*);
    void SetDestination(PathingLocation*);
    void SetByteAtOffset9B(bool);
    void SetByteAtOffset9B(int);
    void SetByteAtA1(int);
    void SetSmoothingRandomness(float);
    void SetCurvedPath(int);
    void SetCenterRadius(float);
    void SetActorRadius(float);
    void SetAvoidNodeArray(BSSimpleArray<void*, 1024>*);
    void SetGoalZDelta(float);
    void DestroyPathingRequest();
    void IncRefCount();
    void DecRefCount();

    PathingLocation& GetOffsetC();
    PathingLocation* GetOrigin();
    PathingLocation* GetStartLoc();
    float GetSmoothingRandomness();
    float GetFloatAtOffset68();
    float GetFloatAtOffset68() const;
    float GetFieldB4Float();
    float GetFloatAtOffsetB0();
    float GetFloatAtOffsetB0() const;
    float GetCenterRadius();
    float GetMinRadius();
    float GetMaxRadius();
    float GetTargetRadius();
    float GetActorRadius();
    float GetGoalZDelta();
    bool IsRandomBelowRadiusThreshold();
    bool GetByteAtOffset9E() const;
    bool GetByteAtOffsetA1();
    bool GetByteAtOffset9B();
    int DialoguePackage_GetCurrentDialogItem();  // 0x008cdd90 (folded getter): the int at +0xa8, PathBuilder's pass limit
    bool FUN_006cd1d0(); // 0x006cd1d0: the byte at +0xa3
    const NiMatrix3& GetRotate();
    PathingAvoidNodeArray* GetString() const;
    BSSimpleArray<void*, 1024>* GetString();
    PathingAvoidNodeArray* GetAvoidNodes() const;

    void PathingRequestClosePoint_SetMinDistance(float);
    bool TESCombatStyle_GetPowerAttackF();
    float BGSProjectile_GetMuzzleFlashDuration();
    int PathingRequestCoveredMove_GetCoverLocation();
    float FUN_006a78f0() const;
    NiPoint3 GetTargetPoint();
    NiPoint3 GetTargetPoint() const;
    bool GetCanSwim() const;
    bool GetTryToUseCurvedPath() const;
    bool GetIgnoreLocks_006a79a0() const;
    PathingLocation* NiAVObject_GetRotate_006a9540();
    PathingActorData* GetActorLockData();
    const PathingActorData* GetActorLockData() const;
    void FUN_006d1bc0(PathingLocation*);
    void PathingRequestCoveredMove_SetCombatCoverSearchInfo(int);
    void PathingRequestCoveredMove_SetCombatCoverLocation(Arg1Class*);
    void PathingRequestCoveredMove_ClearCombatCoverData();
    void FUN_006d3ae0(float);
    void FUN_006d61e0(int);
    void FUN_006d61e0(void*);
    void PathingRequest_SetCenterRadius(NiPoint3&, float);
    void PathingRequest_SetCenterRadius(NiPoint3*, float);
    void SetActorLockData(PathingActorData*);
    void FUN_006e2b20(void*);
    void PathingRequest_SaveGame(BGSSaveFormBuffer*);
    void PathingRequestCoveredMove_SetAttackerSneakHeight(float);
    void FUN_006e4bf0();
    void PathingRequestCoveredMove_SetAttackerHeight(float);
    void SetMaxDistance_006e5ee0(float);
    void FUN_00705b10(int);
    bool FUN_0073cb80() const;
    void PathingRequest_SetNoDestination();
    float FUN_009b0bd0() const;
    void FUN_009db930(unsigned int);

    Actor* pActor;
    PathingLocation Origin;
    PathingLocation Destination;
    union
    {
        struct
        {
            PathingActorData PathingActorState;
        };
    };
    float fActorRadius; // src: XBOX_RETAIL_PDB +0x68 (old: m_fFirstValueAfterActorData)
    float fActorHeight; // src: XBOX_RETAIL_PDB +0x6c (old: m_fSecondValueAfterActorData)
    float fGoalZDelta; // src: XBOX_RETAIL_PDB +0x70 (old: PathingActorSpatialData)
    float fTargetRadius; // src: XBOX_RETAIL_PDB +0x74 (old: fWeaponSpread)
    float fCenterRadius; // src: XBOX_RETAIL_PDB +0x78 (old: m_fCenterRadius)
    NiPoint3 Center;
    float fSmoothingRandomness; // src: XBOX_RETAIL_PDB +0x88 (old: m_fFloatAfterCenter)
    float fGoalAngle; // src: XBOX_RETAIL_PDB +0x8c (old: m_fPathingRadius)
    float fInitialPathHeading; // src: XBOX_RETAIL_PDB +0x90 (old: m_fAvoidanceRadius)
    NiPointer<PathingAvoidNodeArray> spAvoidNodeArray; // src: XBOX_RETAIL_PDB +0x94 (old: m_pPathingAvoidNodeArray)
    bool bCantOpenDoors;
    bool bFaceTargetAtGoal;
    bool bDrawDebugGeometry; // src: XBOX_RETAIL_PDB +0x9a (old: PathingOptions)
    bool bAllowIncompletePath;
    bool bSoftGoalRadius; // src: XBOX_RETAIL_PDB +0x9c (old: m_bAllowDoorTraversal)
    bool bCanSwim;
    bool bCanFly;
    bool bWaitIfPlayerWaits; // src: XBOX_RETAIL_PDB +0x9f (old: m_bCanWalk)
    bool bFirstTangentUsesHeading; // src: XBOX_RETAIL_PDB +0xa0 (old: m_bCanJump)
    bool bGoDirectIfPathingFails; // src: XBOX_RETAIL_PDB +0xa1 (old: m_bCanClimb)
    bool bTryToUseCurvedPath; // src: XBOX_RETAIL_PDB +0xa2 (old: m_bCanUseDoors)
    bool bIgnoreSmoothingIfFails; // src: XBOX_RETAIL_PDB +0xa3 (old: m_bCanRun)
    bool bIgnoreLocks;
    struct
    {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
    } layoutPaddingA5;
    int iRetryCount; // src: XBOX_RETAIL_PDB +0xa8 (old: m_iRequestType)
    bool bFailIfGoalOccupied; // src: XBOX_RETAIL_PDB +0xac (old: m_bCanOpenDoors)
    struct
    {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
    } layoutPaddingAD;
};
