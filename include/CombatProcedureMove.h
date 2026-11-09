#pragma once

#include "CombatProcedure.h"
#include "GO.h"
#include "NiPoint3.h"
#include "TimeoutTimer.h"

class DebugDisplay;
class MoveInput;
class MoveRef;
class MoveRequest;
class MoveVec;
class Output052;
class OutputValue;

// pdb: class CombatProcedureMove, size 0x7c, bases: CombatProcedure, 15 members
class CombatProcedureMove : public CombatProcedure
{
public:
    struct Location
    {
        unsigned int x;
        unsigned int y;
        unsigned int z;
        unsigned int w;

        Location();
        MoveVec* Point();
        float Distance(const Location&);
        MoveVec Position();
        void Set(const MoveVec&, int);
        void BGSWorldLocation_SaveGame(void* buffer);
        void BGSWorldLocation_LoadGame(void* buffer);
    };

    CombatProcedureMove(MoveInput* apCombatLocation, float afTargetRadius, unsigned int aiLocation);
    virtual ~CombatProcedureMove();

    virtual void Unk04();
    virtual void Unk0c();
    virtual void Unk10(int);
    virtual void d05();
    virtual void d11();
    virtual void d12();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    void FUN_009d6ba0();
    void* DestroyIfFlagged(unsigned int flags);
    void Update_009d6ca0();
    void UpdateCombatMovement();
    void ClearTargetRef(TESObjectREFR* apRef);
    void PrintDebugInfo(DebugDisplay* apDebugText, int aeLocation, int aeJustify);
    void StartedPlanning();
    void FinishedPlanning();
    void SaveGame_009d8880(BGSSaveFormBuffer* apSaveGameBuffer);
    void LoadGame_009d89a0(BGSLoadFormBuffer* apLoadGameBuffer);
    void InitLoadGame_009d8ad0(unsigned int apLoadGameBuffer);
    float GetHidingTime();
    void UpdateOutput(OutputValue* output);
    bool CreatePath(Output052* arspAvoidNodeArray);

    MoveRef* Actor();
    MoveRef* Target();
    bool Begin();
    void Fail(const char*);
    void Clear();
    float Duration();
    void Look(const MoveVec&, unsigned char);
    void SetState(int);
    void Reset();
    void Avoid(MoveRequest*);

    unsigned int eState;
    Location startTransform;
    Location CurrentDestination;
    float fTargetRadius;
    unsigned int pTargetRef;
    unsigned int iLocation;
    TimeoutTimer HidingTimer;
    NiPoint3 LookAtPosition;
    bool bReservedSecondaryLocation;
    unsigned char unk55[3];
    GO spQueuedPathingRequest;
    bool bHasQueuedPathingRequest;
    unsigned char unk5D[3];
    int iCurrentNode;
    TimeoutTimer CoveredMoveSearchTimer;
    TimeoutTimer CheckCoverTimer;
    TimeoutTimer CheckDestinationTimer;
};
