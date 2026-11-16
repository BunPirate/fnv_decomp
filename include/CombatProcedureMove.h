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

    unsigned int eState; // src: XBOX_RETAIL_PDB +0x10 (old: unk10)
    Location startTransform;
    Location CurrentDestination; // src: XBOX_RETAIL_PDB +0x24 (old: currentTransform)
    float fTargetRadius; // src: XBOX_RETAIL_PDB +0x34 (old: rate)
    unsigned int pTargetRef; // src: XBOX_RETAIL_PDB +0x38 (old: target38)
    unsigned int iLocation; // src: XBOX_RETAIL_PDB +0x3c (old: mode)
    TimeoutTimer HidingTimer; // src: XBOX_RETAIL_PDB +0x40 (old: pos40)
    NiPoint3 LookAtPosition; // src: XBOX_RETAIL_PDB +0x48 (old: pos48)
    bool bReservedSecondaryLocation; // src: XBOX_RETAIL_PDB +0x54 (old: active54)
    unsigned char unk55[3];
    GO spQueuedPathingRequest; // src: XBOX_RETAIL_PDB +0x58 (old: state58)
    bool bHasQueuedPathingRequest; // src: XBOX_RETAIL_PDB +0x5c (old: active5C)
    unsigned char unk5D[3];
    int iCurrentNode; // src: XBOX_RETAIL_PDB +0x60 (old: unk60)
    TimeoutTimer CoveredMoveSearchTimer; // src: XBOX_RETAIL_PDB +0x64 (old: state64)
    TimeoutTimer CheckCoverTimer; // src: XBOX_RETAIL_PDB +0x6c (old: state6C)
    TimeoutTimer CheckDestinationTimer; // src: XBOX_RETAIL_PDB +0x74 (old: state74)
};
