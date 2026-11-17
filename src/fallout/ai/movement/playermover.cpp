extern "C" void* const DAT_0109297c[];


// Fallout: New Vegas - original source reconstruction.
// Source unit: fallout/ai/movement/playermover.cpp
//
// PlayerMover extends the ActorMover base with player-specific movement
// state: a side-step vector, the current move mode, the pending turn
// direction bits and the minimum turn timer.
//
#include "../../../../include/bhkCharacterController.h"
#include "../../../../include/Actor.h"
#include "../../../../include/LowProcess.h"
#include "../../../../include/MapEntryCount.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESActorBaseData.h"
#include "../../../../include/TESAnimGroup.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/TESObjectCELL.h"
#include "../../../../include/TESObjectLAND.h"
#include "../../../../include/TESTopicInfo.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/ActorMover.h"
#include "../../../../include/PlayerMover.h"
#include "playermover_decls.h"

// @fnv 0x009ea6a0
// pdb: PlayerMover::Revert | PlayerMover.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void PlayerMover::Revert(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ActorMover::Revert(apLoadGameBuffer);
    SideVec = NiPoint3::ZERO;
    MoveMode = 0;
    fMinTurnTime = -1.0f;
    LastTurnDir = 0;
}

// @fnv 0x009ea610
// pdb: PlayerMover::LoadGame | PlayerMover.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void PlayerMover::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ActorMover::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadDataBlock(&SideVec, sizeof(SideVec));
    apLoadGameBuffer->ReadDataBlock(&MoveMode, sizeof(MoveMode));
    apLoadGameBuffer->ReadDataBlock(&LastTurnDir, sizeof(LastTurnDir));
    apLoadGameBuffer->ReadDataBlock(&fMinTurnTime, sizeof(fMinTurnTime));
}

// @fnv 0x009ea680
// pdb: PlayerMover::InitLoadGame | PlayerMover.obj | debug, upstream name already matches, high
// pdb params: apLoadGameBuffer
void PlayerMover::InitLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ActorMover::InitLoadGame(apLoadGameBuffer);
}

// @fnv 0x009ea2f0
// pdb: PlayerMover::UpdateTurnTimer | PlayerMover.obj | retail, object-file run extension, high
// pdb params: fdeltaT
void PlayerMover::SetMovementValue(float fdeltaT)
{
    if (fMinTurnTime > 0.0)
    {
        fMinTurnTime -= fdeltaT;
        if (!pActor->GetSitSleepState())
            MoveMode |= LastTurnDir;
    }
}

// @fnv 0x009e9e50
// pdb: PlayerMover::Update | PlayerMover.obj | retail, upstream name already matches, high
// pdb params: fdeltaT
// pdb locals: movedelta, panim, panim1st, pController, pListener, fMotionMagnitude, fAnimMagnitude, fCosTheta, fSinTheta, fdeltax, fangle, pos, pcell, refpos, fheight
void PlayerMover::Update(float fdeltaT)
{
    NiPoint3 delta = NiPoint3::ZERO;
    Animation* animation = g_thePlayer->GetAnimation(false);
    if (!g_thePlayer->PlayerCharacter_Is3rdPerson())
    {
        Animation* firstPerson = g_thePlayer->GetAnimation(true);
        if (!animation || firstPerson->Animation_GetGroup(1) == animation->Animation_GetGroup(1))
            animation = firstPerson;
    }
    if (!g_thePlayer->Actor_GetKnockedDownMovementDelta(delta))
    {
        if (animation)
        {
            if (g_thePlayer->FUN_0050d4a0())
                animation->GetMovementDelta(&delta, g_thePlayer, true, false);
            else
                animation->GetMovementDelta(&delta, g_thePlayer, false, true);
        }
        struct ControllerState
        {
            bhkCharacterController* controller;
            bhkCharacterController::ControllerState* state;
        } character;
        character.controller = g_thePlayer->GetPhysicsCharacterController();
        character.state = character.controller ? &character.controller->state : 0;
        if (character.state && character.state->bhkCharacterListener_StuckToSomeone())
            delta = NiPoint3::ZERO;
        if ((MoveMode & 0xF) && !g_thePlayer->GetIsDying() && !g_thePlayer->FUN_0050d4a0())
        {
            switch (g_thePlayer->GetAnimAction())
            {
            default:
                break;
            }
            struct MovementLengths
            {
                float sideLength;
                float deltaLength;
            } lengths;
            lengths.sideLength = static_cast<const NiPoint3&>(SideVec).Length();
            lengths.deltaLength = static_cast<const NiPoint3&>(delta).Length();
            if (lengths.sideLength > 0.0 && lengths.deltaLength > 0.0 && !(MoveMode & 0x40))
            {
                float sideX = SideVec.x / lengths.sideLength;
                float sideY = SideVec.y / lengths.sideLength;
                delta.x = sideX * lengths.deltaLength;
                delta.y = sideY * lengths.deltaLength;
            }
        }
        if ((MoveMode & 3) && (MoveMode & 0xC) && !g_thePlayer->GetIsDying())
        {
            switch (g_thePlayer->GetLogDate()->GetAnimAction())
            {
            default:
                if (delta.y != 0.0)
                {
                    float displacement = SideVec.x * fdeltaT * g_thePlayer->GetScale();
                    float angle = displacement / delta.y * 0.7853981852531433;
                    if (MoveMode & 4)
                        delta.x += -std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    else if (MoveMode & 8)
                        delta.x += std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    delta.y = cos(angle) * delta.y;
                }
            case 13:
            case 14:
                break;
            }
        }
    }
    if (g_thePlayer->FUN_0050d4a0())
    {
        NiPoint3 position =
            *reinterpret_cast<NiPoint3*>(reinterpret_cast<TESTopicInfo*>(g_thePlayer)->GetAddTopicList()) + delta;
        g_thePlayer->SetPos(&position);
    }
    else
    {
        g_thePlayer->Move(fdeltaT, &delta, g_thePlayer->GetActorStateFlags());
        struct GroundHeight
        {
            float height;
            TESObjectCELL* cell;
        } ground;
        ground.cell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(g_thePlayer)->LowProcess::GetTarget());
        if (ground.cell && !ground.cell->IsCellInterior())
        {
            ground.height = 0.0f;
            NiPoint3 position = *static_cast<const MobileObject*>(g_thePlayer)->GetPos();
            if (ground.cell->GetLandscape()->GetLandHeightAtPosition(position, ground.height))
            {
                if (ground.height - position.z > 32.0)
                {
                    position.z = ground.height + 32.0;
                    g_thePlayer->SetPos(&position);
                }
            }
        }
    }
}

// @fnv 0x009ea3e0
// pdb: PlayerMover::ForceMoveMode | PlayerMover.obj | debug, vtable slot, medium
// pdb params: aiMoveMode
// pdb locals: bsneakChanged, eaimGroup, sanimGroup, panim, pseq
void PlayerMover::SetMoverMode(unsigned int auMode)
{
    bool changed = (MoveMode & 0x400) != (auMode & 0x400);
    if (auMode & 0x30)
    {
        fMinTurnTime = DAT_011cdf28.Float()->f;
        LastTurnDir = auMode & 0x30;
    }
    MoveMode = auMode;
    if (changed && TESAnimGroup::IsAimAnimation(g_thePlayer->GetAnimation(false)->Animation_GetGroup(4)))
    {
        struct AimAnimationState
        {
            ANIM_GROUP_ENUM group;
            unsigned short groupID;
            Animation* animation;
            NiControllerSequence* sequence;
        } aimState;
        aimState.group = g_thePlayer->IsAlert() ? (ANIM_GROUP_ENUM)20 : (ANIM_GROUP_ENUM)17;
        aimState.animation = g_thePlayer->GetAnimation(false);
        aimState.sequence = aimState.animation->GetControllerSequence(4);
        aimState.groupID = g_thePlayer->GetAnimGroup(aimState.group, 0, false, aimState.animation);
        if (!aimState.sequence ||
            aimState.groupID != aimState.sequence->GetAnimGroup()->GetAnimGroupType_0047d3b0())
            aimState.animation->BlendOut(4, false);
        aimState.animation = g_thePlayer->GetAnimation(true);
        aimState.sequence = aimState.animation->GetControllerSequence(4);
        aimState.groupID = g_thePlayer->GetAnimGroup(aimState.group, 0, false, aimState.animation);
        if (!aimState.sequence ||
            aimState.groupID != aimState.sequence->GetAnimGroup()->GetAnimGroupType_0047d3b0())
            aimState.animation->BlendOut(4, false);
    }
}

// @fnv 0x009ea360
void PlayerMover::UpdatePlayerStatus(unsigned int auMode, bool abSet)
{
    if (abSet)
        MoveMode |= auMode;
    else
        MoveMode &= ~auMode;
}

// Stores the given side vector into the player mover's side vector member.
// @fnv 0x009ea570
void PlayerMover::SetSideVec(const NiPoint3& arSideVec)
{
    SideVec = arSideVec;
}

// @fnv 0x009ea3b0
void PlayerMover::ClearMode(unsigned int auMode)
{
    MoveMode &= ~auMode;
}

// @fnv 0x009e9de0
// src: XBOX_PDB 0x009e9de0
// pdb: PlayerMover::ClearMoveModePreference | PlayerMover.obj | debug, upstream name already matches, high
// pdb params: auiPreferredMoveMode
void PlayerMover::ClearMoveModePreference(unsigned int auiPreferredMoveMode)
{
    ClearMode(auiPreferredMoveMode);
}

// @fnv 0x009e9dc0
// src: XBOX_PDB 0x009e9dc0
// pdb: PlayerMover::SetMoveModePreference | PlayerMover.obj | debug, upstream name already matches, high
// pdb params: auiPreferredMoveMode
void PlayerMover::SetMoveModePreference(unsigned int auiPreferredMoveMode)
{
    UpdatePlayerStatus(auiPreferredMoveMode, true);
}

// @fnv 0x009e9e30
// src: GUESS 0x009e9e30 (confidence: medium)
// pdb: PlayerMover::~PlayerMover | PlayerMover.obj | debug, object-file gap fill, medium
void PlayerMover::ResetVtableAndDestroyActorMover()
{
    *reinterpret_cast<int*>(this) = (int)DAT_0109297c;
    ActorMover::~ActorMover();
}

void __cdecl _Deallocate(void*);
// Calls FUN_009e9e30, then deallocates this object if auFlags has bit 0 set, and returns this.
// @fnv 0x009e9e00
// pdb: PlayerMover::`scalar deleting destructor' | PlayerMover.obj | debug, vtable slot, medium
void* PlayerMover::FUN_009e9e00(unsigned int auFlags)
{
    ResetVtableAndDestroyActorMover();
    if (auFlags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x009ea5a0
// src: XBOX_PDB 0x009ea5a0
// pdb: PlayerMover::SaveGame | PlayerMover.obj | retail, object-file run extension, high
// pdb params: apSaveGameBuffer
void PlayerMover::SaveGame_009ea5a0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    ActorMover::SaveGame_009df100(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(&SideVec, 0xC, 0);
    apSaveGameBuffer->SaveData(&MoveMode, 4, 0);
    apSaveGameBuffer->SaveData(&LastTurnDir, 4, 0);
    apSaveGameBuffer->SaveData(&fMinTurnTime, 4, 0);
}
