// fallout/ai/movement/virtualactorpathhandler.cpp: VirtualActorPathHandler (16 functions)

#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/IDebugText.h"
#include "../../../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../../../include/ActorPathHandler.h"
#include "../../../../include/NiPlane.h"
#include "../../../../include/PathingActorData.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/PathingSolution.h"
#include "../../../../include/VirtualActorPathHandler.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/PathingLocation.h"
#include "../../../../include/PathingGraphNode.h"

// GetLocation/IsTransitionNode bind to 0x00717e50/0x006ca0c0, the shared PathingGraphNode accessors.

// Actor.h lacks the player-comparison call at 0x008bc7f0; this adds no actor layout or virtual slots.
struct PlayerComparisonCall : Actor
{
    bool Actor_IsFollowing_008bc7f0(PlayerCharacter*);
};

class UseDoorCalls
{
  public:
    void QueueActorLocationTask();
    void TaskQueueInterface_QueueActorMoveCharController();
};
class FullNameCall
{
  public:
    const char* GetFullName();
};
void* __stdcall FUN_004537b0(Actor*);
void* __stdcall FUN_004537b0(Actor*, NiPoint3&);
extern const double DAT_0102f078;
extern PlayerCharacter* g_thePlayer;
int Warning(const char*, ...);

// Resets two members to 0 and clears a third member by setting it to 0.
// @fnv 0x009eb040
// pdb: VirtualActorPathHandler::ClearMovement | VirtualActorPathHandler.obj | retail, vtable slot, high
void VirtualActorPathHandler::SetInitialPathState()
{
    pCurrentPathingSolution.operator=(static_cast<PathingSolution*>(0));
    spRequest.operator=(static_cast<PathingRequest*>(0));
    m_uiPathPointIndex = 0;
}

// @fnv 0x009eb3e0
// pdb: VirtualActorPathHandler::LoadGame | VirtualActorPathHandler.obj | retail, upstream name already matches, high
// pdb params: apLoadGameBuffer
void VirtualActorPathHandler::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData((void*)&m_uiPathPointIndex, 4u);
    apLoadGameBuffer->ReadTypedData((void*)&fDistanceTraveled, 4u);
    apLoadGameBuffer->ReadTypedData((void*)&fPathLength, 4u);
}

// @fnv 0x009ea770
// pdb: VirtualActorPathHandler::VirtualActorPathHandler | VirtualActorPathHandler.obj | retail, upstream name already matches, high
// pdb params: apActor, apActorMover
VirtualActorPathHandler::VirtualActorPathHandler(Actor* apActor, ActorMover* apActorMover, NiPointer<PathingSolution>& apPath,
                                                 PathingRequest* apRequest)
    : ActorPathHandler(apActor, apActorMover, apPath, apRequest)
{
    fDistanceTraveled = 0.0f;
    fPathLength = 0.0f;
}

// @fnv 0x009ea820
// pdb: VirtualActorPathHandler::Init | VirtualActorPathHandler.obj | retail, upstream name already matches, high
// pdb params: afPercentTraveled, afDeltaT
int VirtualActorPathHandler::Init(float afPercentTraveled, float afDeltaT)
{
    m_uiPathPointIndex = (unsigned int)afPercentTraveled;
    fDistanceTraveled = 0.0f;
    fPathLength = pCurrentPathingSolution.operator PathingSolution*()->ComputeVirtualPathLength();
    if (afPercentTraveled == 0.0)
        return vfn_0c(afDeltaT);
    else
        return 0;
}

class PlayerS
{
  public:
    bool IsSleepingOrResting();
};
// pdb: class Calendar, size 0x1c (here 0x1), 7 members
class Calendar
{
  public:
    float GetGameTimeScale();
};
extern Calendar g_calendar;
extern double _gModifierZero;
extern const double _DAT_01012640;
extern const double DAT_010848d0;
extern float DAT_011e0358;
extern const NiPoint3 NiPoint3_ZERO;
float __cdecl GetDirectionAngle(const NiPoint3&);

// Advances the actor along its path solution by the distance it can travel this frame, updating position, angle and path index, and returns a status code.
// @fnv 0x009ea8a0
// pdb: VirtualActorPathHandler::Update | VirtualActorPathHandler.obj | retail, vtable slot, high
// pdb params: afDeltaT
// pdb locals: currentLoc, deltaToNode, fdistCanTravel, fdelta, fscale, fdistToNode, nextLoc, pprocess, fangle, pactorProcess
int VirtualActorPathHandler::UpdatePathMovement(float afDeltaT)
{
    float fdelta = afDeltaT;
    BaseProcess* pprocess = pActor->GetCurrentProcess();
    if (pprocess && pprocess->GetSitSleepState())
        return 0;
    if (((PlayerS*)g_thePlayer)->IsSleepingOrResting() || ((PlayerComparisonCall*)pActor)->Actor_IsFollowing_008bc7f0(g_thePlayer))
    {
        fdelta = _DAT_01012640 / g_calendar.GetGameTimeScale();
    }
    else if (!pActor->HasCombatState())
    {
        fdelta = DAT_010848d0 / g_calendar.GetGameTimeScale();
        BaseProcess* pactorProcess = pActor->GetCurrentProcess();
        if (pactorProcess)
            fdelta = (DAT_011e0358 - pactorProcess->FUN_007df1f0()) * _DAT_01012640 /
                     g_calendar.GetGameTimeScale();
    }
    if (m_uiPathPointIndex >= ((PathingSolution*)pCurrentPathingSolution)->PathingSolution_GetVirtualNodeCount())
        return 5;
    NiPoint3 currentLoc = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    NiPoint3 deltaToNode = NiPoint3_ZERO;
    NiPoint3 nextLoc;
    float fdistCanTravel = pActor->GetCurrentMovementSpeed() * fdelta;
    float fdistToNode = 0;
    while (fdistCanTravel >= _gModifierZero)
    {
        nextLoc = ((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode(m_uiPathPointIndex))
                      ->GetLocation()
                      .GetLocation<NiPoint3>();
        deltaToNode = nextLoc - currentLoc;
        fdistToNode = reinterpret_cast<NiPoint3&>(deltaToNode).Length();
        if (fdistCanTravel >= fdistToNode)
        {
            fDistanceTraveled += fdistToNode;
            fdistCanTravel -= fdistToNode;
            currentLoc = reinterpret_cast<const NiPoint3&>(nextLoc);
            float fangle = GetDirectionAngle(deltaToNode);
            pActor->SetFurnitureHeading(fangle);
            if (((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode(m_uiPathPointIndex))
                    ->IsTransitionNode())
            {
                switch (UseDoorAtNode(currentLoc))
                {
                case -2:
                case -1:
                    return 3;
                case 1:
                    pActor->TESObjectREFR::Actor_MoveActorAndFollowers(currentLoc, fangle, pActor->GetParentCell(),
                                       pActor->GetParentWorldSpace(), 1, 0);
                    return 0;
                }
            }
            else
            {
                pActor->TESObjectREFR::Actor_MoveActorAndFollowers(currentLoc, fangle, pActor->GetParentCell(),
                                   pActor->GetParentWorldSpace(), 1, 0);
                if (pActor->GetProcessTier() == 0 && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
                    return 0;
                m_uiPathPointIndex++;
            }
            if (m_uiPathPointIndex >= ((PathingSolution*)pCurrentPathingSolution)->PathingSolution_GetVirtualNodeCount())
                return 5;
        }
        else
        {
            break;
        }
    }
    float fscale = fdistToNode != _gModifierZero ? 1.0 - (fdistToNode - fdistCanTravel) / fdistToNode : 0.0;
    reinterpret_cast<NiPoint3&>(deltaToNode) *= fscale;
    reinterpret_cast<NiPoint3&>(currentLoc) += deltaToNode;
    fDistanceTraveled += reinterpret_cast<NiPoint3&>(deltaToNode).Length();
    float fangle = GetDirectionAngle(deltaToNode);
    pActor->SetFurnitureHeading(fangle);
    pActor->TESObjectREFR::Actor_MoveActorAndFollowers(currentLoc, fangle, pActor->GetParentCell(), pActor->GetParentWorldSpace(), 1,
                       0);
    if (pActor->GetProcessTier() == 0 && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
        return 0;
    if (pCurrentPathingSolution &&
        m_uiPathPointIndex + 1 == ((PathingSolution*)pCurrentPathingSolution)->PathingSolution_GetVirtualNodeCount() &&
        ((PathingRequest*)spRequest)->FUN_009b0bd0() + fdistCanTravel >= fdistToNode)
    {
        m_uiPathPointIndex++;
        return 5;
    }
    return 0;
}

extern "C" float __cdecl BSMAX_00404010(float, float);


// @fnv 0x009eb070
// src: XBOX_PDB 0x009eb070
// pdb: VirtualActorPathHandler::GetDistanceRemaining | VirtualActorPathHandler.obj | debug, vtable slot, medium
// pdb locals: flength
float VirtualActorPathHandler::GetDistanceRemaining_009eb070()
{
    float flength = ((float*)this)[7] - ((float*)this)[6];
    flength = BSMAX_00404010(flength, 0.0f);
    return flength;
}


// Saves three 4-byte values at offsets 0x14, 0x18 and 0x1c of this object into the save buffer.
// @fnv 0x009eb390
// pdb: VirtualActorPathHandler::SaveGame | VirtualActorPathHandler.obj | retail, vtable slot, high
// pdb params: apSaveGameBuffer
void VirtualActorPathHandler::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((char*)this + 0x14, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x18, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x1c, 4, 0);
}

void __cdecl _Deallocate(void*);
// Calls FUN_009ea7c0 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009ea740
// pdb: VirtualActorPathHandler::`scalar deleting destructor' | VirtualActorPathHandler.obj | retail, vtable slot, high
void* VirtualActorPathHandler::DestroyIfFlagged(unsigned int flags)
{
    VirtualActorPathHandler::~VirtualActorPathHandler();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x009ea7c0
// pdb: VirtualActorPathHandler::~VirtualActorPathHandler | VirtualActorPathHandler.obj | debug, upstream name already matches, high
VirtualActorPathHandler::~VirtualActorPathHandler()
{
    ((VirtualActorPathHandler*)this)->SetInitialPathState();
}

// Forwards the delta time to the virtual method V003 and returns its result.
// @fnv 0x009ead60
// src: XBOX_PDB 0x009ead60
// pdb: VirtualActorPathHandler::UpdateWhilePlayerWaits | VirtualActorPathHandler.obj | debug, upstream name already matches, high
// pdb params: afDeltaT
int VirtualActorPathHandler::UpdateWhilePlayerWaits(float afDeltaT)
{
    return vfn_0c(afDeltaT);
}

struct Flt
{
    operator unsigned int();
};
extern unsigned int __fastcall PathingSolution_GetVirtualNodeCount(char*);
extern double gModifierZero;
// @fnv 0x009eb0b0
// src: XBOX_PDB 0x009eb0b0
// pdb: VirtualActorPathHandler::GetPercentTraveled | VirtualActorPathHandler.obj | debug, upstream name already matches, high
float VirtualActorPathHandler::GetPercentTraveled()
{
    if (!reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int())
        return 0.0f;
    if (m_uiPathPointIndex >=
            PathingSolution_GetVirtualNodeCount(reinterpret_cast<char*>(
                reinterpret_cast<Flt*>(reinterpret_cast<char*>(this) + 0xc)->operator unsigned int())) ||
        fPathLength <= gModifierZero)
        return 1.0f;
    return fDistanceTraveled / fPathLength;
}

// Returns the actor's position.
// @fnv 0x009eb120
// pdb: VirtualActorPathHandler::ComputeApproximateLocation | VirtualActorPathHandler.obj | retail, vtable slot, high
// pdb params: afDeltaT
NiPoint3 VirtualActorPathHandler::GetPoint(float afDeltaT)
{
    return *static_cast<const TESObjectREFR*>(pActor)->GetPos();
}


// Accessor at 0x009ddb30 is not declared by the shared PathingSolution yet.
PathingGraphNode* __fastcall GetLastVirtualPathNode(PathingSolution* solution);


// Returns the position of the next path node, the virtual node, or the starting position when the solution has no nodes.
// @fnv 0x009eb160
// pdb: VirtualActorPathHandler::GetNextNodeLocation | VirtualActorPathHandler.obj | retail, vtable slot, high
NiPoint3 VirtualActorPathHandler::GetNextPathPoint() const
{
    if (((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))->GetNodeCount() >
        0)
    {
        if (*(unsigned int*)((char*)this + 0x14) + 1 <
            (*(NiPointer<PathingSolution>*)((char*)this + 0xc))->PathingSolution_GetVirtualNodeCount())
        {
            return ((PathingGraphNode*)((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
                ->GetVirtualNode(*(unsigned int*)((char*)this + 0x14) + 1))
                ->GetLocation()
                .GetLocation();
        }
        else
        {
            return GetLastVirtualPathNode((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
                ->GetLocation()
                .GetLocation();
        }
    }
    else
    {
        return *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    }
}


// Prints the actor's starting position and, if a pathing solution exists, the current path node index and count; otherwise prints "No path".
// @fnv 0x009eb2b0
// pdb: VirtualActorPathHandler::PrintCurrentStatus | VirtualActorPathHandler.obj | retail, string-set bridge, high
// pdb params: apDebugText, aLoc, aJust
// pdb locals: loc
void VirtualActorPathHandler::PrintPathDebugInfo(IDebugText* apDebugText, DEBUGTEXT_LOCATION aLoc, DEBUGTEXT_JUSTIFY aJust)
{
    NiPoint3 loc = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    apDebugText->Print(aLoc, aJust, "VirtualPathHandler: Actor's Positon %1.f %1.f %1.f", loc.x, loc.y, loc.z);

    if ((PathingSolution*)*(NiPointer<PathingSolution>*)((char*)this + 0xc))
    {
        apDebugText->Print(aLoc, aJust, "Current path node %u of %u", *(unsigned int*)((char*)this + 0x14),
                           (*(NiPointer<PathingSolution>*)((char*)this + 0xc))->PathingSolution_GetVirtualNodeCount());
    }
    else
    {
        apDebugText->Print(aLoc, aJust, "No path");
    }
}


unsigned int __fastcall PathingSolution_GetVirtualNodeCount(void* p);
void* __fastcall Modelloader_GetReferencedThis(void* p);


// If the container at unk0c is valid and index is in range, copies the NiPoint3 at that index into out and returns true; otherwise returns false.
// @fnv 0x009eb230
// pdb: VirtualActorPathHandler::GetNodeLocation | VirtualActorPathHandler.obj | debug, vtable slot, medium
// pdb params: aiIndex, arLocation
bool VirtualActorPathHandler::GetPointAtIndex(unsigned int index, NiPoint3* out)
{
    if (Modelloader_GetReferencedThis(&pCurrentPathingSolution) != 0)
    {
        if (index < PathingSolution_GetVirtualNodeCount(Modelloader_GetReferencedThis(&pCurrentPathingSolution)))
        {
            *out = ((PathingGraphNode*)((PathingSolution*)Modelloader_GetReferencedThis(&pCurrentPathingSolution))->GetVirtualNode(index))
                       ->GetLocation()
                       .GetLocation();
            return true;
        }
    }
    return false;
}

bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
struct DoorReference : TESObjectREFR
{
    void TESObjectREFR_SetLocationOnReference(const NiPoint3&);
    bool TESObjectREFR_Activate(Actor*, bool, TESBoundObject*, int);
    int GetFormEditorIDLength();
    const char* TESObjectREFR_GetFullName();
    int GetCellLoadState();
};
struct CellNameView : TESForm
{
    FullNameCall fullName;
    int GetFormEditorIDLength();
};
struct PointComparison : NiPoint3
{
    bool FUN_00439090(const NiPoint3&);
};
struct PointMagnitude : NiPoint3
{
    float GetSquaredXYLength();
};
// Advances the door path node, moves the actor through the door, and returns -1, -2, 1 or 0 depending on the next node and actor position checks.
// @fnv 0x009ead90
// src: XBOX_RETAIL_PDB 0x009ead90
// pdb: VirtualActorPathHandler::UseDoorAtNode | VirtualActorPathHandler.obj | retail, string-set bridge, high
// pdb params: aNewLoc
// pdb locals: pdoor, movedLoc, fdiff
int VirtualActorPathHandler::UseDoorAtNode(NiPoint3& aNewLoc)
{
    if (AILinearTaskThreadManager_ShouldQueue3DTask())
    {
        ((UseDoorCalls*)FUN_004537b0(pActor, aNewLoc))->QueueActorLocationTask();
        ((UseDoorCalls*)FUN_004537b0(pActor))->TaskQueueInterface_QueueActorMoveCharController();
    }
    else
    {
        ((DoorReference*)pActor)->TESObjectREFR_SetLocationOnReference(aNewLoc);
    }
    DoorReference* pPathNodeDoor =
        (DoorReference*)((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode_006e78b0(m_uiPathPointIndex))->GetTeleportDoor();
    ++m_uiPathPointIndex;
    if (pPathNodeDoor && !pPathNodeDoor->TESObjectREFR_Activate(pActor, false, 0, 1))
        return -1;
    if ((PathingSolution*)pCurrentPathingSolution &&
        m_uiPathPointIndex < ((PathingSolution*)pCurrentPathingSolution)->PathingSolution_GetVirtualNodeCount())
    {
        NiPoint3 actorPosition = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
        float distance =
            ((PointMagnitude&)(actorPosition - reinterpret_cast<const NiPoint3&>(((PathingGraphNode*)((PathingSolution*)pCurrentPathingSolution)->GetVirtualNode(m_uiPathPointIndex))
                                                   ->GetLocation()
                                                   .GetLocation<NiPoint3>())))
                .GetSquaredXYLength();
        if (distance > DAT_0102f078)
        {
            if (((PointComparison&)aNewLoc).FUN_00439090(actorPosition))
            {
                Warning(
                    "PATHFINDING: Actor %s used teleport door %s in cell %s and was not moved to the expected pathing location, check teleport marker",
                    ((DoorReference*)pActor)->GetFormEditorIDLength() ? pActor->GetName()
                                                             : ((DoorReference*)pActor)->TESObjectREFR_GetFullName(),
                    pPathNodeDoor->GetName(),
                    pPathNodeDoor->GetParentCell() ? (((CellNameView*)pPathNodeDoor->GetParentCell())->GetFormEditorIDLength()
                                                  ? ((CellNameView*)pPathNodeDoor->GetParentCell())->fullName.GetFullName()
                                                  : ((TESForm*)pPathNodeDoor->GetParentCell())->GetName())
                                           : "");
            }
            return -2;
        }
    }
    aNewLoc = *static_cast<const TESObjectREFR*>(pActor)->GetPos();
    if (!((DoorReference*)pActor)->GetCellLoadState() && !((PlayerS*)g_thePlayer)->IsSleepingOrResting())
    {
        ++m_uiPathPointIndex;
        fDistanceTraveled = 0.0f;
        return 1;
    }
    return 0;
}
