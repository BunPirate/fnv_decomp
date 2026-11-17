// fallout/ai/combat/combataction.cpp: CombatAction (12 functions)

#include "combataction_decls.h"
#include "../../../../include/CombatAction.h"
#include "../../../../include/CombatState.h"
#include "../../../../include/CombatActionAcquireLineOfSight.h"
#include "../../../../include/CombatActionActivateCombatItem.h"
#include "../../../../include/CombatActionApproachTarget.h"
#include "../../../../include/CombatActionAttackGrenade.h"
#include "../../../../include/CombatActionAttackGrenadeFlushTarget.h"
#include "../../../../include/CombatActionAttackGrenadeFromCover.h"
#include "../../../../include/CombatActionAttackHandToHand.h"
#include "../../../../include/CombatActionAttackMelee.h"
#include "../../../../include/CombatActionAttackRanged.h"
#include "../../../../include/CombatActionAttackRangedExplosive.h"
#include "../../../../include/CombatActionAttackRangedExplosiveFromCover.h"
#include "../../../../include/CombatActionAttackRangedFromCover.h"
#include "../../../../include/CombatActionAvoidThreat.h"
#include "../../../../include/CombatActionDodge.h"
#include "../../../../include/CombatActionDrawWeapon.h"
#include "../../../../include/CombatActionFlee.h"
#include "../../../../include/CombatActionHide.h"
#include "../../../../include/CombatActionIgnoreBlockedTarget.h"
#include "../../../../include/CombatActionInvestigate.h"
#include "../../../../include/CombatActionMove.h"
#include "../../../../include/CombatActionMoveAndAttackGrenade.h"
#include "../../../../include/CombatActionMoveAndAttackRanged.h"
#include "../../../../include/CombatActionMoveAndAttackRangedExplosive.h"
#include "../../../../include/CombatActionMoveAndSwitchToMelee.h"
#include "../../../../include/CombatActionSearch.h"
#include "../../../../include/CombatActionSwitchWeapon.h"
#include "../../../../include/CombatActionUseCombatItem.h"
#include "../../../../include/CombatWorldStateArray.h"
#include "../../../../include/CombatWorldStateListNode.h"
#include "../../../../include/BSThread.h"

// Creates and returns a new CombatAction subclass instance matching the given COMBAT_ACTION type, warning and returning 0 for unknown types.
// @fnv 0x00979f90
// src: XBOX_DEBUG_PDB 0x00979f90
// pdb: CombatAction::CreateCombatAction | CombatAction.obj | debug, unique string literal, high
// pdb params: aeCombatAction
CombatAction* CombatAction::CreateCombatAction(COMBAT_ACTION aeCombatAction)
{
    switch (aeCombatAction)
    {
    case COMBAT_ACTION_ATTACK_RANGED:
        return new CombatActionAttackRanged(aeCombatAction);
    case COMBAT_ACTION_ATTACK_RANGED_FROM_COVER:
        return new CombatActionAttackRangedFromCover(aeCombatAction);
    case COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE:
        return new CombatActionAttackRangedExplosive(aeCombatAction);
    case COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE_FROM_COVER:
        return new CombatActionAttackRangedExplosiveFromCover(aeCombatAction);
    case COMBAT_ACTION_ATTACK_MELEE:
        return new CombatActionAttackMelee(aeCombatAction);
    case COMBAT_ACTION_ATTACK_HAND_TO_HAND:
        return new CombatActionAttackHandToHand(aeCombatAction);
    case COMBAT_ACTION_ATTACK_GRENADE:
        return new CombatActionAttackGrenade(aeCombatAction);
    case COMBAT_ACTION_ATTACK_GRENADE_FLUSH_TARGET:
        return new CombatActionAttackGrenadeFlushTarget(aeCombatAction);
    case COMBAT_ACTION_ATTACK_GRENADE_FROM_COVER:
        return new CombatActionAttackGrenadeFromCover(aeCombatAction);
    case COMBAT_ACTION_MOVE:
        return new CombatActionMove(aeCombatAction);
    case COMBAT_ACTION_MOVE_AND_SWITCH_TO_MELEE:
        return new CombatActionMoveAndSwitchToMelee(aeCombatAction);
    case COMBAT_ACTION_MOVE_AND_ATTACK_RANGED:
        return new CombatActionMoveAndAttackRanged(aeCombatAction);
    case COMBAT_ACTION_MOVE_AND_ATTACK_RANGED_EXPLOSIVE:
        return new CombatActionMoveAndAttackRangedExplosive(aeCombatAction);
    case COMBAT_ACTION_MOVE_AND_ATTACK_GRENADE:
        return new CombatActionMoveAndAttackGrenade(aeCombatAction);
    case COMBAT_ACTION_DRAW_WEAPON:
        return new CombatActionDrawWeapon(aeCombatAction);
    case COMBAT_ACTION_SWITCH_WEAPON:
        return new CombatActionSwitchWeapon(aeCombatAction);
    case COMBAT_ACTION_AVOID_THREAT:
        return new CombatActionAvoidThreat(aeCombatAction);
    case COMBAT_ACTION_SEARCH:
        return new CombatActionSearch(aeCombatAction);
    case COMBAT_ACTION_INVESTIGATE:
        return new CombatActionInvestigate(aeCombatAction);
    case COMBAT_ACTION_DODGE:
        return new CombatActionDodge(aeCombatAction);
    case COMBAT_ACTION_IGNORE_BLOCKED_TARGET:
        return new CombatActionIgnoreBlockedTarget(aeCombatAction);
    case COMBAT_ACTION_FLEE:
        return new CombatActionFlee(aeCombatAction);
    case COMBAT_ACTION_ACTIVATE_COMBAT_ITEM:
        return new CombatActionActivateCombatItem(aeCombatAction);
    case COMBAT_ACTION_USE_COMBAT_ITEM:
        return new CombatActionUseCombatItem(aeCombatAction);
    case COMBAT_ACTION_ACQUIRE_LINE_OF_SIGHT:
        return new CombatActionAcquireLineOfSight(aeCombatAction);
    case COMBAT_ACTION_HIDE:
        return new CombatActionHide(aeCombatAction);
    case COMBAT_ACTION_APPROACH_TARGET:
        return new CombatActionApproachTarget(aeCombatAction);
    default:
        Warning("COMBAT: Could not create combat action of type %i", aeCombatAction);
        return 0;
    }
}

struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};
extern CombatActionEntry DAT_011a4280[];

// @fnv 0x00979e20
// pdb: CombatAction::GetName | CombatAction.obj | debug, call graph, medium
char* CombatAction::GetCombatActionName()
{
    return DAT_011a4280[reinterpret_cast<BSThread*>(this)->GetThreadID()].pName;
}

// @fnv 0x00979e40
// src: XBOX_PDB 0x00979e40
// pdb: CombatAction::GetCost | CombatAction.obj | debug, vtable slot, medium
// pdb params: apCombatController, aiActionValue
float CombatAction::GetCost_00979e40(CombatController* apCombatController, int aiActionValue)
{
    return DAT_011a4280[reinterpret_cast<BSThread*>(this)->GetThreadID()].m_fPathingCostCur;
}

// pdb: class TaskQueueInterface, size 0x10 (here 0x1), 4 members
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

// @fnv 0x00979e60
// src: XBOX_PDB 0x00979e60
// pdb: CombatAction::GetDebugText | CombatAction.obj | debug, upstream name already matches, high
// pdb params: apDebugText, aiMaxLength, aiActionValue
void CombatAction::GetDebugText(char* apDebugText, unsigned int aiMaxLength, int aiActionValue)
{
    TaskQueueInterface::CopyStringToBuffer(apDebugText, aiMaxLength, GetCombatActionName());
}

struct CombatController;
struct UnsignedIdHandle
{
    int _ref_00726070();
    operator unsigned int() const;
};
struct TgtOps
{
    void* GetPosition();
};
struct FUN_005e3fc0_shell
{
    unsigned int Get();
};
struct FUN_00979f70_shell
{
    void CombatPlannerData_SetLinkLocation(unsigned int);
};

// @fnv 0x00979e90
// src: XBOX_PDB 0x00979e90
// pdb: CombatAction::CanExecute | CombatAction.obj | retail, upstream name already matches, high
// pdb params: apCombatController, apWorldStateArray, aiActionValue
// pdb locals: plist, icombatLocation, pworldState, ivalue
bool CombatAction::CanExecute(CombatController* apCombatController, CombatWorldStateArray* apWorldStateArray,
                                 int aiActionValue)
{
    UnsignedIdHandle* pWorldState4;
    int iValue3;
    int _iCombatLocation;
    CombatWorldStateListNode* pList;

    pList = reinterpret_cast<CombatWorldStateListNode*>(reinterpret_cast<TgtOps*>(this)->GetPosition());
    while (pList)
    {
        pWorldState4 = pList->operator->()->item;
        if (pWorldState4)
        {
            iValue3 = pWorldState4->_ref_00726070() == -1 ? aiActionValue : pWorldState4->_ref_00726070();
            if (!apWorldStateArray->CombatWorldStateArray_IsTrue(*pWorldState4, iValue3))
                return false;
        }
        pList = pList->GetNext();
    }
    _iCombatLocation = -1;
    if (HasRequirement(1, &_iCombatLocation))
        reinterpret_cast<FUN_00979f70_shell*>(reinterpret_cast<FUN_005e3fc0_shell*>(apCombatController)->Get())
            ->CombatPlannerData_SetLinkLocation(_iCombatLocation);
    return true;
}

// The shared node has no declaration for FindStateByType at 0x009aa410.
struct CombatActionStateListAccess : CombatWorldStateListNode
{
    void FindStateByType(int, int);
};

// Calls FindStateByType on the object at offset 0xc of this, passing a and b through.
// @fnv 0x00979f50
// src: COMMUNITY 0x00979f50
// pdb: CombatAction::GetPreconditionWorldStateActionValue | CombatAction.obj | debug, object-file run extension, low
// pdb params: aeState, ariActionValue
void CombatAction::HasRequirement(int aiArg1, int aiArg2)
{
    reinterpret_cast<CombatActionStateListAccess*>(&Preconditions)->FindStateByType(aiArg1, aiArg2);
}

namespace fnv_00979f70 {
struct QuantityData
{
    void SetQuantity(unsigned int);
};

struct FUN_00979f70_shell
{
    void CombatPlannerData_SetLinkLocation(unsigned int aiLocation);
};

// @fnv 0x00979f70
// src: XBOX_PDB 0x00979f70
// pdb: CombatPlannerData::SetLinkLocation | CombatAction.obj | debug, upstream name already matches, high
// pdb params: aiLocation
void FUN_00979f70_shell::CombatPlannerData_SetLinkLocation(unsigned int aiLocation)
{
    (*reinterpret_cast<QuantityData**>(reinterpret_cast<char*>(this) + 4))->SetQuantity(aiLocation);
}
}  // namespace fnv_00979f70

namespace fnv_0097abd0 {
int __cdecl BSstricmp(const char*, const char*);

struct CombatActionEntry
{
    char* pName;
    float m_fPathingCostCur;
    int iFlags;
};
extern CombatActionEntry DAT_011a4280[];

// @fnv 0x0097abd0
// src: COMMUNITY 0x0097abd0
// pdb: CombatAction::SetCombatActionCost | CombatAction.obj | retail, upstream name already matches, high
// pdb params: apCombatActionName, afCost
// pdb locals: i
bool CombatAction_SetCombatActionCost(char* apCombatActionName, float afCost)
{
    for (unsigned int i = 0; i < 0x1b; i++)
    {
        if (!BSstricmp(DAT_011a4280[i].pName, apCombatActionName))
        {
            DAT_011a4280[i].m_fPathingCostCur = afCost;
            return true;
        }
    }
    return false;
}
}  // namespace fnv_0097abd0

struct CombatController;
struct IMH
{
    CombatState* CombatController_GetCombatState();
};
extern double _gModifierZero;
extern float DAT_0108ca80;

// Gets the combat state's attack DPS for a weapon type and returns the default value if zero, otherwise the max attack DPS minus it.
// @fnv 0x0097ac30
// pdb: CombatAction::GetAttackCost | CombatAction.obj | debug, call graph, medium
// pdb params: apCombatController, aeWeaponType
// pdb locals: fattackDPS, pcombatState, fmaxAttackDPS
float GetWeaponDPSDeficit(CombatController* apCombatController, int aeWeaponType)
{
    float fattackDPS;
    CombatState* pcombatState;
    float fmaxAttackDPS;

    pcombatState = reinterpret_cast<IMH*>(apCombatController)->CombatController_GetCombatState();
    fattackDPS = pcombatState->GetCombatWeaponDPS(aeWeaponType);
    if (fattackDPS == _gModifierZero)
        return DAT_0108ca80;
    fmaxAttackDPS = pcombatState->GetMaxCombatWeaponDPS();
    return fmaxAttackDPS - fattackDPS;
}

// @fnv 0x0097ac90
float CombatState::GetCombatWeaponDPS(int aiIndex)
{
    return reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x3c)[aiIndex];
}

struct CombatController;
struct CoordinateTriple
{
    double BGSWorldLocation_GetDistanceSquared(CoordinateTriple*);
};
float __cdecl BSMIN(float, float);
float __cdecl BSMAX_00404010(float, float);
extern float DAT_0108cb00;
extern double DAT_0108cb08;

// @fnv 0x0097acb0
// src: COMMUNITY 0x0097acb0
// pdb: CombatAction::GetMovementCost | CombatAction.obj | retail, upstream name already matches, high
// pdb params: apCombatController, arStartWorldLoc, arEndWorldLoc
// pdb locals: fmovementCost
float CombatAction_GetMovementCost(CombatController* apCombatController, CoordinateTriple* arStartWorldLoc,
                   CoordinateTriple* arEndWorldLoc)
{
    float fmovementCost;

    fmovementCost = arStartWorldLoc->BGSWorldLocation_GetDistanceSquared(arEndWorldLoc) / DAT_0108cb08;
    fmovementCost = BSMIN(fmovementCost, DAT_0108cb00);
    fmovementCost = BSMAX_00404010(fmovementCost, 0.01f);
    return fmovementCost;
}

extern int DAT_0108cab8;

// CombatWorldStateListNode currently has no nontrivial constructor or destructor.
// Keep this constructor's local representation until the shared node supports
// the four initialization calls and their exception cleanup at 0x00979bd0.
struct CondS
{
    int data[2];
    CondS();
    ~CondS();
};

struct FUN_00979bd0
{
    virtual void vfunc();
    CondS cond0;
    CondS cond1;
    CondS cond2;
    CondS cond3;
    int aeType;
    int iFlags;

    FUN_00979bd0(int aeType);
};

// Stores the type argument in aeType and copies iFlags from the global type table entry at that index.
// @fnv 0x00979bd0
// pdb: CombatAction::CombatAction | CombatAction.obj | debug, call graph, medium
// pdb params: aeType
FUN_00979bd0::FUN_00979bd0(int a)
{
    aeType = a;
    iFlags = DAT_011a4280[aeType].iFlags;
}
